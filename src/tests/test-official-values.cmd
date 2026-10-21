@echo off
setlocal
for %%I in ("%~dp0..\..") do set "ROOT=%%~fI"
call "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" >nul || exit /b 1
cl /nologo /utf-8 /O2 /EHsc /std:c++17 /I"%ROOT%\sdk\include" /Fe:"%ROOT%\.cache\official-values.exe" "%ROOT%\src\tests\official_value_test.cpp" user32.lib || exit /b 1
"%ROOT%\.cache\official-values.exe"
