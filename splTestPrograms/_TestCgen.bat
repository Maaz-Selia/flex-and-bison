@echo off

title Test cgen.exe with sample spl programs


cgen < a.spl > a.c
echo cgen -Complete-
gcc -o a.exe a.c
echo a.exe -Created-
a
echo a -Complete-
pause

cgen < b.spl > b.c
echo cgen -Complete-
gcc -o b.exe b.c
echo b.exe -Created-
b
echo b -Complete-
pause

cgen < c.spl > c.c
echo cgen -Complete-
gcc -o c.exe c.c
echo c.exe -Created-
c
echo c -Complete-
pause

cgen < d.spl > d.c
echo cgen -Complete-
gcc -o d.exe d.c
echo d.exe -Created-
d
echo d -Complete-
pause

cgen < e.spl > e.c
echo cgen -Complete-
gcc -o e.exe e.c
echo e.exe -Created-
e
echo e -Complete-
pause