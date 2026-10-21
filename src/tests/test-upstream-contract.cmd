@echo off
setlocal
set "ROOT=%~dp0..\..\"
set "VCVARS=%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
call "%VCVARS%" >nul || exit /b 1
cl /nologo /utf-8 /O2 /EHsc /std:c++17 /W4 /I"%ROOT%sdk\include" /Fe:"%ROOT%src\tests\upstream_contract_test.exe" "%ROOT%src\tests\upstream_contract_test.cpp" user32.lib || exit /b 1
"%ROOT%src\tests\upstream_contract_test.exe"
