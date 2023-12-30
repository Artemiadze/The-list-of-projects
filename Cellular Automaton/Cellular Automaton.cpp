﻿#define _CRT_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>

#define x 85
#define y 40


char cell[y][x];


void init() {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cell[i][j] = ' ';
        }
    }
    for (int j = 0; j < x; j++) {
        cell[0][j] = '#';
        cell[39][j] = '#';
    }
    for (int i = 0; i < y; i++) {
        cell[i][0] = '#';
        cell[i][84] = '#';
    }
    //генерация живых клеток
    for (int y0 = 1; y0 < y - 1; y0++) 
    {
        for (int x0 = 1; x0 < x - 1; x0++) 
        {
            int num = rand() % 2;
            if (num == 1) cell[y0][x0] = '*';
        }
    }
}


void setcur(int x1, int y1) {
    COORD coord;
    coord.X = x1;
    coord.Y = y1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void life() {
    int number = 0;
    setcur(0, 0);
    for (int i = 1; i < y-1; i++) {
        for (int j = 1; j < x-1; j++) {
            if (cell[i][j] == '*') {
                for (int i1 = i - 1; i1 < i + 2; i1++) {
                    for (int j1 = j - 1; j1 < j + 2; j1++) {
                        if (cell[i1][j1] == '*')  number++;
                    }
                }
                if ((number != 2) && (number != 3)) {
                    cell[i][j] = ' ';
                }
                number = 0;
            }
            else {
                for (int i1 = i - 1; i1 < i + 2; i1++) {
                    for (int j1 = j - 1; j1 < j + 2; j1++) {
                        if (cell[i1][j1] == '*')  number++;
                    }
                }
                if (number == 3) {
                    cell[i][j] = '*';
                }
                number = 0;
            }
        }
    }
}



void print() {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%c", cell[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    do {
        init();
        life();
        print();
        Sleep(15);

    } while ((GetKeyState(VK_ESCAPE) >= 0));
    return 0;
}


