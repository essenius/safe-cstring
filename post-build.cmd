rem the script is in the root folder, that's our base
set basePath=%~dp0
set project=SafeCString
rem The Compress-Archive command can't deal very well with selective addition of files in subfolders, so we build up the folder with everything we need in temp.
if exist "%temp%\%project%" rmdir "%temp%\%project%" /s /q
mkdir "%temp%\%project%\src"
copy "%basePath%src\*.h" "%temp%\%project%\src" 2>nul
rem Create target folder if needed
if not exist "%basePath%publish" mkdir "%basePath%publish"
rem Create the ZIP file with only the content we need
powershell.exe -Command Compress-Archive -Path '%temp%\SafeCString\src', '%basePath%examples','%basePath%keywords.txt','%basePath%library.properties','%basePath%LICENSE', '%basePath%README.md' -DestinationPath '%basePath%publish\%project%.zip' -Force
rem Clean up the temporary folder
rmdir "%temp%\%project%" /s /q