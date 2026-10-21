@echo off
setlocal
for %%I in ("%~dp0..\..") do set "ROOT=%%~fI"
set "VCVARS=%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
call "%VCVARS%" >nul || exit /b 1
if not exist "%ROOT%\.cache" mkdir "%ROOT%\.cache"
cl /nologo /utf-8 /O2 /EHsc /std:c++17 /I"%ROOT%\sdk\include" /Fe:"%ROOT%\.cache\logfix-check.exe" "%ROOT%\src\tests\log_and_idle_test.cpp" user32.lib || exit /b 1
"%ROOT%\.cache\logfix-check.exe" "%ROOT%" "%ROOT%\.cache\logfix-fixture"
