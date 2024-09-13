@echo off

title Create parser.exe

bison spl.y
echo Parser -Complete-

gcc -o parser.exe spl.tab.c spl.c -DDEBUG -lfl
echo parser.exe -Complete-

pause