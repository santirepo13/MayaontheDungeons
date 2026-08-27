@echo off
    g++ -std=c++17 main.cpp Direction.cpp Player.cpp Room.cpp Game.cpp -o dungeon_adventure.exe
        if errorlevel 1 (
            echo failed.
            exit /b 1
        )
    echo done
    exit /b 0
