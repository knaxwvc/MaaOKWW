# v0.3.0 架構

執行主體為 C++17／MaaFramework v5.14.0；角色流程依 OK-WW 固定提交 `0b37b5b79e771297536ff1155db1c23131297558` 轉寫。

|路徑|用途|
|---|---|
|`src/gui.cpp`|Win32 GUI、設定、F10／F11、紀錄顯示及核心程序管理|
|`src/main.cpp`|Maa 初始化、遊戲視窗連線、監看及戰鬥入口|
|`src/official/generated/`|52 名角色、BaseChar 與共用換人方法的完整 C++ 流程|
|`src/official/OfficialCharacter.*`|角色方法註冊、屬性及跨角色查找|
|`src/official/OfficialTask.*`|官方 API 與 Maa 截圖、模板、OCR、背景輸入之間的接口|
|`src/official/OfficialValue.h`|動態值、參數綁定、Tuple 真值、回呼與作用域|
|`src/official/OfficialArray.h`|角色影像計算所用的陣列、遮罩及 FFT|
|`src/char/`|角色型別與工廠；現行手法本體位於 generated 目錄|
|`src/task/BaseCombatTask.h`|戰鬥監看、隊伍、技能確認及 Maa 輸入實作|
|`src/combat/`|ROI、OCR、模板、血條、技能狀態及冷卻辨識|
|`resource/`|Maa Pipeline、286 份原始模板與本地 OCR 模型|
|`source_reference/upstream/master-0b37b5b/`|固定上游原文，原始行尾及雜湊保留|
|`scripts/official_transpile.py`|開發時的 Python AST → C++ 轉換工具|
|`src/tests/official_roles_test.cpp`|現行原生角色、隊伍與影像離線對照入口|
|`evidence/official-*-20261021.*`|本版公開離線對照資料|

角色方法依官方原名註冊；產生檔含來源檔名、行號與來源提交。執行時的條件、迴圈及回呼皆為編譯後 C++，不載入 Python 解譯器。完整來源與方法數見 `SOURCES.json`。

一／二／三人隊伍共用官方輪轉選擇器；單人返回目前角色，沒有 1／2／3 換人輸入。技能辨識來自畫面，輸入使用 Maa 的 Win32 背景接口。保留三連點規則、按鍵總時間與長按時間。

截圖及辨識依 Maa 後端設定運作；GPU 辨識不代表讀取遊戲內部技能資料。本版離線對照結果不代表實戰成效。
