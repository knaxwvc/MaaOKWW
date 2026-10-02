@echo off
setlocal
set "ROOT=%~dp0"
set "VCVARS=%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
if not exist "%VCVARS%" (
  for /f "usebackq delims=" %%I in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VCVARS=%%I\VC\Auxiliary\Build\vcvars64.bat"
)
if not exist "%VCVARS%" (
  echo Visual Studio C++ tools were not found. Install Desktop development with C++.
  exit /b 1
)
call "%VCVARS%" >nul || exit /b 1
cl /nologo /utf-8 /O2 /EHsc /std:c++17 /W4 /I"%ROOT%sdk\include" /Fe:"%ROOT%MaaOKWWNative.exe" "%ROOT%src\main.cpp" user32.lib || exit /b 1
if /I "%~1"=="native" goto :complete
cl /nologo /utf-8 /O2 /EHsc /std:c++17 /W4 /DUNICODE /D_UNICODE /Fe:"%ROOT%MaaOKWWGui.exe" "%ROOT%src\gui.cpp" user32.lib gdi32.lib shell32.lib /link /SUBSYSTEM:WINDOWS /MANIFEST:EMBED /MANIFESTUAC:NO /MANIFESTINPUT:"%ROOT%src\require-admin.manifest" || exit /b 1
:complete
echo Build complete.
