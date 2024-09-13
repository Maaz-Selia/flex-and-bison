@echo off

cgen < a.spl > a.c
gcc -o a.exe a.c

pause