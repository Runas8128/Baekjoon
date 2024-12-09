@echo off

gcc -o main.exe Template/%1.c
main.exe
del main.exe
