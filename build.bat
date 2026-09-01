@echo off
cl /EHsc *.cpp NPC\*.cpp NPC\Animals\*.cpp /Fe:dungeon_adventure.exe
if errorlevel 1 (
    echo failed.
    exit /b 1
)
echo done
exit /b 0