rem the script is in the root folder, that's our base
set basePath=%~dp0
set project=SafeCString
rem The Compress-Archive command can't deal very well with selective addition of files in subfolders, so we build up the folder with everything we need in temp.
if exist "%temp%\%project%" rmdir "%temp%\%project%" /s /q
mkdir "%temp%\%project%\src"
copy "%basePath%src\*.h" "%temp%\%project%\src" 2>nul
copy "%basePath%src\*.cpp" "%temp%\%project%\src" 2>nul
mkdir "%temp%\%project%\examples"
xcopy /e "%basePath%examples" "%temp%\%project%\examples"
copy "%basePath%keywords.txt" "%temp%\%project%"
copy "%basePath%library.properties" "%temp%\%project%"
copy "%basePath%LICENSE" "%temp%\%project%"
copy "%basePath%README.md" "%temp%\%project%"
rem Create target folder if needed
if not exist "%basePath%publish" mkdir "%basePath%publish"
rem Create the ZIP file from the temp structure
powershell.exe -Command Compress-Archive -Path '%temp%\SafeCString' -DestinationPath '%basePath%publish\%project%.zip' -Force
rem Clean up the temporary folder
rmdir "%temp%\%project%" /s /q