@echo off

REM Compile the code
g++ main.cpp Person.cpp Secretary.cpp -o build

REM Check if the compilation was successful
if %ERRORLEVEL% neq 0 (
    echo Compilation failed.
    exit /b %ERRORLEVEL%
)

REM Run the build if compilation was successful
echo Running build...
build

REM Exit the script
exit /b