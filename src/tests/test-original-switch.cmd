@echo off
setlocal
set "ROOT=%~dp0..\..\"
set "VCVARS=%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
call "%VCVARS%" >nul || exit /b 1
cl /nologo /EHsc /std:c++17 /W4 /Fe:"%ROOT%src\tests\original_switch_test.exe" "%ROOT%src\tests\original_switch_test.cpp" || exit /b 1
"%ROOT%src\tests\original_switch_test.exe"
