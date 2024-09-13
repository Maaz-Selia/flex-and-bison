@echo off

title Create cgen.exe

flex spl.l
echo Lexer -Complete-

bison spl.y
echo Parser -Complete-

gcc -o cgen.exe spl.c spl.tab.c -lfl
echo cgen.exe -Complete-

pause