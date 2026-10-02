#define NOMINMAX
#include <Windows.h>
#include <shellapi.h>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include "CombatConfig.h"

namespace fs=std::filesystem;
static fs::path root;
static HWND main_window,status_box,state_label,start_button,stop_button,team_list;
static HWND options[7]{},key_fields[5]{};
static HFONT normal_font,title_font,heading_font;
static HBRUSH background_brush,sidebar_brush;
static PROCESS_INFORMATION child{};
static bool running=false,closing=false;

static HWND control(HWND parent,const wchar_t* type,const wchar_t* text,DWORD style,
    int x,int y,int width,int height,int id=0,HFONT font=nullptr) {
    HWND item=CreateWindowExW(wcscmp(type,L"EDIT")==0?WS_EX_CLIENTEDGE:0,type,text,
        WS_CHILD|WS_VISIBLE|style,x,y,width,height,parent,reinterpret_cast<HMENU>(INT_PTR(id)),nullptr,nullptr);
    SendMessageW(item,WM_SETFONT,reinterpret_cast<WPARAM>(font?font:normal_font),TRUE);return item;
}
static bool checked(int i){return SendMessageW(options[i],BM_GETCHECK,0,0)==BST_CHECKED;}
static void set_checked(int i,bool value){SendMessageW(options[i],BM_SETCHECK,value?BST_CHECKED:BST_UNCHECKED,0);}
static bool save_config() {
    auto path=root/L"config.ini";
    const wchar_t* section[]={L"Combat",L"Combat",L"Combat",L"Combat",L"Characters",L"Characters",L"Combat"};
    const wchar_t* names[]={L"AutoTarget",L"UseLiberation",L"CheckLevitator",L"SwitchHealer",L"ChisaDPS",L"IunoC6",L"OpenWorld"};
    bool ok=true;
    for(int i=0;i<7;++i)ok=WritePrivateProfileStringW(section[i],names[i],checked(i)?L"1":L"0",path.c_str()) && ok;
    auto team=std::to_wstring(SendMessageW(team_list,CB_GETCURSEL,0,0));
    ok=WritePrivateProfileStringW(L"Combat",L"Team",team.c_str(),path.c_str()) && ok;
    const wchar_t* keys[]={L"Resonance",L"Echo",L"Liberation",L"Tool",L"Execution"};
    for(int i=0;i<5;++i) {
        wchar_t value[32]{};GetWindowTextW(key_fields[i],value,32);
        ok=WritePrivateProfileStringW(L"Keys",keys[i],value,path.c_str()) && ok;
    }
    return ok;
}
static void enable_options(bool value) {
    EnableWindow(team_list,value);
    for(auto option:options)EnableWindow(option,value);
    for(auto field:key_fields)EnableWindow(field,value);
}
static void request_stop() {
    running=false;std::ofstream(root/"stop.flag").put('1');
    EnableWindow(start_button,child.hProcess?FALSE:TRUE);EnableWindow(stop_button,FALSE);
    SetWindowTextW(state_label,child.hProcess?L"正在停止，等待釋放按鍵…":L"已停止");
    if(!child.hProcess)enable_options(true);
}
static void launch_battle() {
    if(child.hProcess)return;
    DeleteFileW((root/"stop.flag").c_str());
    const int team=int(SendMessageW(team_list,CB_GETCURSEL,0,0));
    const wchar_t* mode=team==1?L"--combat-one-team1":team==2?L"--combat-one-team2":team==3?L"--combat-one-team3":L"--combat-one";
    std::wstring cmd=L"\""+(root/"MaaOKWWNative.exe").wstring()+L"\" "+mode;
    std::vector<wchar_t> command(cmd.begin(),cmd.end());command.push_back(0);
    STARTUPINFOW startup{};startup.cb=sizeof(startup);
    if(!CreateProcessW(nullptr,command.data(),nullptr,nullptr,FALSE,CREATE_NO_WINDOW,nullptr,root.c_str(),&startup,&child)) {
        request_stop();MessageBoxW(main_window,L"無法啟動戰鬥程序。請確認同資料夾內有 MaaOKWWNative.exe。",L"啟動失敗",MB_OK|MB_ICONERROR);return;
    }
    SetWindowTextW(state_label,L"監控中：等待遊戲戰鬥畫面");
}
static void start_monitoring() {
    if(running || child.hProcess)return;
    if(!save_config()){MessageBoxW(main_window,L"無法保存 config.ini。",L"設定",MB_OK|MB_ICONERROR);return;}
    running=true;
    EnableWindow(start_button,FALSE);EnableWindow(stop_button,TRUE);enable_options(false);
    launch_battle();
}
static std::wstring recent_log() {
    std::ifstream in(root/"native_run.log",std::ios::binary);if(!in)return L"按「開始」後，戰鬥紀錄會顯示在這裡。";
    in.seekg(0,std::ios::end);auto size=in.tellg();
    if(size>14000)in.seekg(size-std::streamoff(14000));else in.seekg(0);
    std::string bytes((std::istreambuf_iterator<char>(in)),std::istreambuf_iterator<char>());
    if(size>14000){auto first=bytes.find('\n');if(first!=std::string::npos)bytes.erase(0,first+1);}
    int length=MultiByteToWideChar(CP_UTF8,0,bytes.data(),int(bytes.size()),nullptr,0);
    if(length<=0)return L"等待紀錄…";
    std::wstring wide(size_t(length),L'\0');MultiByteToWideChar(CP_UTF8,0,bytes.data(),int(bytes.size()),wide.data(),length);
    return wide;
}
static void update_status() {
    const auto log=recent_log();SetWindowTextW(status_box,log.c_str());
    SendMessageW(status_box,EM_SETSEL,WPARAM(-1),LPARAM(-1));SendMessageW(status_box,EM_SCROLLCARET,0,0);
    if(child.hProcess && WaitForSingleObject(child.hProcess,0)==WAIT_OBJECT_0) {
        DWORD exit_code=1;GetExitCodeProcess(child.hProcess,&exit_code);
        CloseHandle(child.hThread);CloseHandle(child.hProcess);child={};
        if(running) {
            running=false;EnableWindow(start_button,TRUE);EnableWindow(stop_button,FALSE);enable_options(true);
            SetWindowTextW(state_label,exit_code==0?L"已停止":L"核心已停止，請查看戰鬥紀錄");
        }else{SetWindowTextW(state_label,L"已停止");EnableWindow(start_button,TRUE);enable_options(true);}
    }
    if(closing && !child.hProcess){DestroyWindow(main_window);return;}
}
static LRESULT CALLBACK window_proc(HWND hwnd,UINT message,WPARAM wparam,LPARAM lparam) {
    switch(message) {
    case WM_CREATE: {
        main_window=hwnd;auto cfg=CombatConfig::load(root);
        control(hwnd,L"STATIC",L"OK-WW",0,24,24,130,34,0,title_font);
        control(hwnd,L"STATIC",L"MaaFramework",0,24,61,140,24);
        control(hwnd,L"BUTTON",L"觸發任務",BS_PUSHBUTTON,16,114,154,42,10);
        control(hwnd,L"BUTTON",L"戰鬥紀錄",BS_PUSHBUTTON,16,166,154,42,11);
        control(hwnd,L"BUTTON",L"開啟角色原始碼",BS_PUSHBUTTON,16,218,154,42,12);
        control(hwnd,L"STATIC",L"F10  開始／暫停\nF11  停止",0,24,566,146,54);
        control(hwnd,L"STATIC",L"自動戰鬥",0,216,24,440,36,0,title_font);
        state_label=control(hwnd,L"STATIC",L"已停止",0,216,67,650,25);
        control(hwnd,L"STATIC",L"隊伍策略",0,216,111,108,28);
        team_list=control(hwnd,L"COMBOBOX",L"",CBS_DROPDOWNLIST|WS_VSCROLL,330,107,535,220,20);
        const wchar_t* teams[]={L"自動辨識目前隊伍（51 名角色，含心）",L"Aemeath／Linnai／Mornye",L"Hiyuki／Lucilla／Chisa",L"Qingxiao／Denia／ShoreKeeper"};
        for(auto item:teams)SendMessageW(team_list,CB_ADDSTRING,0,reinterpret_cast<LPARAM>(item));
        SendMessageW(team_list,CB_SETCURSEL,cfg.team>=0 && cfg.team<=3?cfg.team:0,0);
        control(hwnd,L"STATIC",L"戰鬥設定",0,216,155,450,28,0,heading_font);
        const wchar_t* labels[]={L"自動鎖定敵人",L"使用共鳴解放",L"檢查漂浮狀態",L"戰鬥前後切換治療角色",L"千咲 DPS 模式",L"尤諾六命模式",L"大世界戰鬥模式"};
        for(int i=0;i<7;++i)options[i]=control(hwnd,L"BUTTON",labels[i],BS_AUTOCHECKBOX,216+(i%2)*330,190+(i/2)*33,310,27,30+i);
        const bool values[]={cfg.auto_target,cfg.use_liberation,cfg.check_levitator,cfg.switch_healer,cfg.chisa_dps,cfg.iuno_c6,cfg.open_world};
        for(int i=0;i<7;++i)set_checked(i,values[i]);
        const wchar_t* key_names[]={L"共鳴技能",L"聲骸",L"共鳴解放",L"工具",L"處決"};
        const int key_values[]={cfg.resonance,cfg.echo,cfg.liberation,cfg.tool,cfg.execution};
        for(int i=0;i<5;++i) {
            const int x=216+i*130;control(hwnd,L"STATIC",key_names[i],0,x,332,94,23);
            wchar_t text[2]{wchar_t(key_values[i]),0};key_fields[i]=control(hwnd,L"EDIT",text,ES_CENTER|ES_UPPERCASE,x,357,94,28,50+i);
            SendMessageW(key_fields[i],EM_SETLIMITTEXT,8,0);
        }
        start_button=control(hwnd,L"BUTTON",L"開始  F10",BS_DEFPUSHBUTTON,216,405,235,42,1);
        stop_button=control(hwnd,L"BUTTON",L"停止  F11",BS_PUSHBUTTON,465,405,160,42,2);
        control(hwnd,L"BUTTON",L"保存設定",BS_PUSHBUTTON,639,405,105,42,3);
        control(hwnd,L"BUTTON",L"開啟紀錄",BS_PUSHBUTTON,758,405,106,42,4);
        EnableWindow(stop_button,FALSE);
        control(hwnd,L"STATIC",L"戰鬥紀錄",0,216,463,450,27,0,heading_font);
        status_box=control(hwnd,L"EDIT",L"",WS_VSCROLL|ES_MULTILINE|ES_AUTOVSCROLL|ES_READONLY,216,499,648,178);
        RegisterHotKey(hwnd,1,MOD_NOREPEAT,VK_F10);RegisterHotKey(hwnd,2,MOD_NOREPEAT,VK_F11);
        SetTimer(hwnd,1,100,nullptr);update_status();return 0;
    }
    case WM_COMMAND:
        switch(LOWORD(wparam)) {
        case 1:start_monitoring();break;
        case 2:request_stop();break;
        case 3:if(!running)SetWindowTextW(state_label,save_config()?L"設定已保存":L"設定保存失敗");break;
        case 4:case 11:ShellExecuteW(hwnd,L"open",(root/L"native_run.log").c_str(),nullptr,root.c_str(),SW_SHOWNORMAL);break;
        case 12:ShellExecuteW(hwnd,L"open",(root/L"src"/L"char").c_str(),nullptr,nullptr,SW_SHOWNORMAL);break;
        }return 0;
    case WM_HOTKEY:if(wparam==1){if(running)request_stop();else start_monitoring();}else if(wparam==2)request_stop();return 0;
    case WM_TIMER:update_status();return 0;
    case WM_CTLCOLORSTATIC: {
        HDC dc=reinterpret_cast<HDC>(wparam);SetBkMode(dc,TRANSPARENT);SetTextColor(dc,RGB(33,38,47));
        RECT rect{};GetWindowRect(reinterpret_cast<HWND>(lparam),&rect);MapWindowPoints(nullptr,hwnd,reinterpret_cast<POINT*>(&rect),2);
        return reinterpret_cast<LRESULT>(rect.left<185?sidebar_brush:background_brush);
    }
    case WM_PAINT: {
        PAINTSTRUCT paint{};HDC dc=BeginPaint(hwnd,&paint);RECT rect{};GetClientRect(hwnd,&rect);
        FillRect(dc,&rect,background_brush);rect.right=185;FillRect(dc,&rect,sidebar_brush);EndPaint(hwnd,&paint);return 0;
    }
    case WM_CLOSE:closing=true;request_stop();if(!child.hProcess)DestroyWindow(hwnd);return 0;
    case WM_DESTROY:KillTimer(hwnd,1);UnregisterHotKey(hwnd,1);UnregisterHotKey(hwnd,2);PostQuitMessage(0);return 0;
    }
    return DefWindowProcW(hwnd,message,wparam,lparam);
}
int WINAPI wWinMain(HINSTANCE instance,HINSTANCE,PWSTR,int show) {
    SetProcessDPIAware();wchar_t module[MAX_PATH]{};GetModuleFileNameW(nullptr,module,MAX_PATH);root=fs::path(module).parent_path();
    HANDLE mutex=CreateMutexW(nullptr,TRUE,L"Local\\MaaOKWWNativeGUI");
    if(!mutex || GetLastError()==ERROR_ALREADY_EXISTS){MessageBoxW(nullptr,L"戰鬥視窗已開啟。",L"OK-WW · MaaFramework",MB_OK);if(mutex)CloseHandle(mutex);return 0;}
    normal_font=CreateFontW(-17,0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY,DEFAULT_PITCH,L"Microsoft JhengHei UI");
    title_font=CreateFontW(-26,0,0,0,FW_SEMIBOLD,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY,DEFAULT_PITCH,L"Microsoft JhengHei UI");
    heading_font=CreateFontW(-19,0,0,0,FW_SEMIBOLD,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY,DEFAULT_PITCH,L"Microsoft JhengHei UI");
    background_brush=CreateSolidBrush(RGB(250,250,252));sidebar_brush=CreateSolidBrush(RGB(240,242,247));
    WNDCLASSW wc{};wc.lpfnWndProc=window_proc;wc.hInstance=instance;wc.lpszClassName=L"MaaOKWWNativeWindow";wc.hCursor=LoadCursorW(nullptr,IDC_ARROW);wc.hbrBackground=background_brush;RegisterClassW(&wc);
    HWND window=CreateWindowW(wc.lpszClassName,L"OK-WW · MaaFramework 戰鬥",WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,
        CW_USEDEFAULT,CW_USEDEFAULT,915,733,nullptr,nullptr,instance,nullptr);ShowWindow(window,show);UpdateWindow(window);
    MSG msg{};while(GetMessageW(&msg,nullptr,0,0)){TranslateMessage(&msg);DispatchMessageW(&msg);}
    DeleteObject(normal_font);DeleteObject(title_font);DeleteObject(heading_font);DeleteObject(background_brush);DeleteObject(sidebar_brush);
    ReleaseMutex(mutex);CloseHandle(mutex);return int(msg.wParam);
}
