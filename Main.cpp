#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <vector>

#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

vector<int> undoX, undoY;
vector<int> Xundo, Yundo;

void MainMenu(int& n, int& turn, int chess[201][201], int check[201][201], int point[201][201]);
void chooseMode(int& n, int& turn, int chess[201][201], int check[201][201], int point[201][201]);

void gotoxy(int x, int y) {
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x , y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

void textcolor(int x) {
	HANDLE Color;
	Color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Color , x);
}

void SplashScreen() {
     cout << "                                                               ||||||||||||\n";
     cout << "                                                            ||||||||||||||||||\n";
     cout << "                                                        |||||                ||||||\n";
     cout << "                    ||||||||||||                    ||||                          ||||\n";
     cout << "                  |||||||||||||||||               |||                                |||\n";
     cout << "                ||||            ||||            |||                                    |||\n";
     cout << "               |||                |||          ||                                        ||\n";
     cout << "              |||  ||||      ||||  |||       ||                                            ||\n";
     cout << "             |||    |||||  |||||    |||     ||                                              ||\n";
     cout << "             |||      ||||||||      |||    ||                                                ||\n";
     cout << "             |||        |||||       |||   ||                                                  |\n";
     cout << "             |||      ||||||||      |||   |             |||                     |||            |\n";
     cout << "             |||    |||||  |||||    |||  ||            |||||                   |||||           ||\n";
     cout << "              |||  ||||      ||||  |||   |             |||||                   |||||            |\n";
     cout << "               |||  |          |  |||    |             |||||                   |||||            |\n";
     cout << "                ||||            ||||    ||              |||                     |||             |\n";
     cout << "                  |||||||||||||||||     ||                                                      |\n";
     cout << "                    ||||||||||||        ||     ||||||                                 ||||||    |\n";
     cout << "                                         |                                                      |\n";
     cout << "                                         |                     |    ||    |                     |\n";
     cout << "                                         ||                     ||||  ||||                     ||\n";
     cout << "                                          |                                                    |\n";
     cout << "                                          ||                                                  ||\n";
     cout << "                  ||||        ||           ||                                                ||\n";
     cout << "                 ||||||      ||||           ||                                              ||\n";
     cout << "                ||          ||  ||          ||||                                          ||  |\n";
     cout << "                ||    |    ||||||||         |  ||                                       |||   |\n";
     cout << "                 ||||||    ||    ||         |    |||                        ||||     ||||     ||\n";
     cout << "                  ||||     ||    ||        ||      ||||||||||             |||   ||||||        ||\n";
     cout << "                                           |          ||     |           |       ||            |\n";
     cout << "                                           |         |       ||         ||        ||           |\n";
     cout << "                 ||||        ||||          |         |       ||         ||    ||  ||           |\n";
     cout << "                |||||||     ||||||        ||        |   |    |           ||||||    ||          ||\n";
     cout << "                ||   ||    ||    ||       |         |    ||||                |      |          |\n";
     cout << "                ||||||     ||    ||       |        ||     |                  ||     ||         |\n";
     cout << "                ||   ||     ||||||        |        |      |                   ||   | ||       |\n";
     cout << "                ||   ||      ||||          |       ||    ||                    |||||  ||| ||||\n";
     cout << "                                            ||      ||||||                          \n\n";
     cout << "                                       WELCOME TO GOMUKO GAME\n";
     cout << "                                       - DKMNHAT - 18125103 -\n";
}

void LoadingBar() {
    char a = 177, b = 219;
    printf("\n\n\n\t\t\t\t\tLoading....\n\t\t\t\t\t");
    textcolor(9);
    fto(i, 1, 25) {
        cout << a;
        Sleep(100);
    }
    printf("\r");
    printf("\t\t\t\t\t");
    fto(i, 1, 25) {
        cout << b;
        Sleep(100);
    }
    textcolor(15);
    system("cls");
}

void setup(int& turn, int chess[201][201], int check[201][201], int point[201][201]) {
    turn = 1;
    fto(i, 1, 50) fto(j, 1, 50) {
        chess[i][j] = 0;
        check[i][j] = 0;
        point[i][j] = 0;
    }

    undoX.clear();
    undoY.clear();
}

void DrawBoard(int n, int chess[201][201]) {
    printf("-");
    fto(i, 1, n) printf("----");
    cout << endl;

    fto(i, 1, n) {
        printf("|");
        fto(j, 1, n) {
            if (chess[i][j] == 0) printf(" . |");
            if (chess[i][j] == 1) {
                textcolor(9); printf(" X ");
                textcolor(15); printf("|");
            }
            if (chess[i][j] == -1) {
                textcolor(12); printf(" O ");
                textcolor(15); printf("|");
            }
        } cout << endl << "-";

        fto(j, 1, n) printf("----");
        cout << endl;
    }
}

void Draw1st5Board(int n, int chess[201][201]) {
    printf("-");
    fto(i, 1, n) printf("----");
    cout << endl;

    fto(i, 1, n) {
        printf("|");
        fto(j, 1, n) {
            if (chess[i][j] == 0) printf(" . |");
            if (chess[i][j] == 1) {
                textcolor(9); printf(" O ");
                textcolor(15); printf("|");
            }
            if (chess[i][j] == -1) {
                textcolor(12); printf(" O ");
                textcolor(15); printf("|");
            }
        } cout << endl << "-";

        fto(j, 1, n) printf("----");
        cout << endl;
    }
}

void Draw3PBoard(int n, int chess[201][201]) {
    printf("-");
    fto(i, 1, n) printf("----");
    cout << endl;

    fto(i, 1, n) {
        printf("|");
        fto(j, 1, n) {
            if (chess[i][j] == 0) {
                textcolor(14); printf(" Y ");
                textcolor(15); printf("|");
            }
            if (chess[i][j] == 1) {
                textcolor(9); printf(" X ");
                textcolor(15); printf("|");
            }
            if (chess[i][j] == 2) {
                textcolor(12); printf(" O ");
                textcolor(15); printf("|");
            }
            if (chess[i][j] == -1) printf(" . |");
        } cout << endl << "-";

        fto(j, 1, n) printf("----");
        cout << endl;
    }
}

void Undo(int chess[201][201], int x) {
    int ezis = undoX.size() - 1;
    int xx = undoX[ezis];
    int yy = undoY[ezis];
    undoX.erase(undoX.end() - 1);
    undoY.erase(undoY.end() - 1);

    chess[yy][xx] = x;
    gotoxy((xx - 1)*4 + 2, yy*2);
    cout << ".";
}

void UndoPVC(int chess[201][201], int check[201][201], int point[201][201]) {
    int ezis = Xundo.size() - 1;
    fto(i, 0, (int)Xundo.size() - 1) {
        check[Yundo[i]][Xundo[i]] = 0;
        point[Yundo[i]][Xundo[i]] = 0;
    }

    Xundo.clear();
    Yundo.clear();
}

///TICTACTOE______________________________________________________________
void savegame3T(int n, int turn, int board[201][201], int toado_x, int toado_y) {
    FILE *FileSave;
    FileSave = fopen("gamemode1.txt", "w");
    fprintf(FileSave, "%d %d\n", n, turn);
    fprintf(FileSave, "%d %d\n", toado_x, toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            fprintf(FileSave, "%d ", board[i][j]);
        }
        printf("\n");
    }
    fclose(FileSave);
}

void Loadgame3T(int &n, int &turn, int loadboard[201][201], int &toado_x, int &toado_y) {

    FILE *FileLoad;
    FileLoad = fopen("gamemode1.txt", "r");
    fscanf(FileLoad, "%d%d", &n, &turn);
    fscanf(FileLoad, "%d%d", &toado_x, &toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            int x;
            fscanf(FileLoad, "%d", &x);
            loadboard[i][j] = x;
        }
    }
    fclose(FileLoad);
}

int checkT2T(int y, int x, int chess[201][201]) {
    bool pots[10];
    int tnuoc[10];

    for (int i = 1; i <= 8; ++i) {
        pots[i] = false;
        tnuoc[i] = 1;
    }
    int i = 1;
    while (i < 3) {
        ///1///DOC
        if (chess[y][x] == chess[y+i][x] && !pots[1]) ++tnuoc[1];
        else if (chess[y][x] != chess[y+i][x]) pots[1] = true;
        if (chess[y][x] == chess[y-i][x] && !pots[2]) ++tnuoc[1];
        else if (chess[y][x] != chess[y-i][x]) pots[2] = true;
        ///2///NGANG
        if (chess[y][x] == chess[y][x+i] && !pots[3]) ++tnuoc[2];
        else if (chess[y][x] != chess[y][x+i]) pots[3] = true;
        if (chess[y][x] == chess[y][x-i] && !pots[4]) ++tnuoc[2];
        else if (chess[y][x] != chess[y][x-i]) pots[4] = true;
        ///3///CHEOCHINH
        if (chess[y][x] == chess[y+i][x+i] && !pots[5]) ++tnuoc[3];
        else if (chess[y][x] != chess[y+i][x+i]) pots[5] = true;
        if (chess[y][x] == chess[y-i][x-i] && !pots[6]) ++tnuoc[3];
        else if (chess[y][x] != chess[y-i][x-i]) pots[6] = true;
        ///4///CHEOPHU
        if (chess[y][x] == chess[y+i][x-i] && !pots[7]) ++tnuoc[4];
        else if (chess[y][x] != chess[y+i][x-i]) pots[7] = true;
        if (chess[y][x] == chess[y-i][x+i] && !pots[8]) ++tnuoc[4];
        else if (chess[y][x] != chess[y-i][x+i]) pots[8] = true;

        ++i;
    }
    fto(i, 1, 4) if (tnuoc[i] == 3) return chess[y][x];
    return 0;
}

void Draw3T(int y, int x, int turn, int board[201][201], int n, int check[201][201], int point[201][201]) {
    if (checkT2T(y, x, board) == 1) {
        system("cls");
        gotoxy(0, 0);

        while (true) {
            textcolor(9);

            cout << "                                                                    00\n";
            cout << "   1111111       11111      11111111111             111      01     001    110001         11111       0000\n";
            cout << "     00011     0001 1000 10011001    00         0011001    100      00   0011 10001    0001 000     101\n";
            cout << "     00      000      0110   100               00  001    1000     10  100      1001  00    0001    01\n";
            cout << "    100     000       000    001   1          00  100    00000    101 100        000  01   00100   00\n";
            cout << "    001    000         00   10011100          001 000   00 101   10   001        000  00   01 001  01\n";
            cout << "   100     001         100  000   11              000  00  001  00   000         000      10  100 10\n";
            cout << "   001    000               00                    000 00   00  00    000        100       00   00001\n";
            cout << "  100     000              001      101           10001    00001      000      100       10     000\n";
            cout << "11000     1001      01   10000000111001           100      000        10001  1001   1   101     100\n";
            cout << "1111111    1001   100   1111111110111              0       01            100011    1000001       01\n";
            cout << "             1000001                                                                  \n";

            textcolor(15);
            DrawBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame3T(n, turn, board, x, y);
            }
        }
    }
    if (checkT2T(y, x, board) == -1) {
        system("cls");
        gotoxy(0, 0);
        while (true) {
            textcolor(12);

            cout << "                                                                                     000\n";
            cout << "     11111111100   1100001    11110001      1111001010001          111001     00      00   10000001       111100       00001\n";
            cout << "   001 000    00    000     000111  1000  1001 000    10         001 000     001     10   001   10001   001  1001     00\n";
            cout << " 101   00     1     001   100  100   100 10    00               00  000    1000     101 100       000  00    0000    00\n";
            cout << " 01   000   0      100    01   001  1001 01   100   01         101  00    10100    101  00        1001 00    0 001  10\n";
            cout << "101   0001100      001   10    0011001  100   00011001          00  00   00  00   101  000        1001 101  00 100  00\n";
            cout << " 00  100   11      00     00  000100     00  100    1               00  00  100  00    001        000       01  001 0\n";
            cout << "     001          000      01 00  00         001                    00 00   100 00     000        00       00    0000\n";
            cout << "    100           00         000  100       100       00            0001    10001      0001     100        01    1001\n";
            cout << "  1000011      0000011     100001  000    11000000001001            001     000         1000011001   10   00      00\n";
            cout << "                                    001   101     111               0       00             1111      100001        0\n";
            cout << "                                     10011001\n";
            cout << "                                       1111\n";

            textcolor(15);
            DrawBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame3T(n, turn, board, x, y);
            }
        }
    }

    if (checkT2T(y, x, board) == 0) {
        bool ok = false;
        fto(i, 1, 3) fto(j, 1, 3) if (board[i][j] == 0) ok = true;
        if (ok == true) return;
        else {
            while (true) {
                system("cls");
                textcolor(10);

                cout << "                                                     111       000\n";
                cout << "       1000011                0000011               1000       10000               11\n";
                cout << "        0000000001          1000000000001         0000000      00000       001    000\n";
                cout << "           1000000001       0001 1000000001       000000001    00000      00001   000\n";
                cout << "           000100000001     001       000001     0000000000    00000      0000    001\n";
                cout << "          0000   1000001    00000      10000    10000 10000    00000     00000   100\n";
                cout << "         10001     10000    10000      0000     0000   0000   100000     00001   000\n";
                cout << "         0000       10001   10001   100001     0000    1000    00000    10000   0001\n";
                cout << "         0000        0001   0000 100001        0001    1000     0000    00000   000\n";
                cout << "         0001        000    00000001          0001     00001    0000   100000  0001\n";
                cout << "        1000        0001  1000000           1000000000000001    0000   000000  000\n";
                cout << "        1000       0001   10000000         00000000001 1000     1000  0000000 000\n";
                cout << "        0001      0001      00000000       000001      1000      0001100 10000000\n";
                cout << "        000      000   00   000 0000001     000        1001      0000001 1000000\n";
                cout << "        000    0000000000  1001   0000001  1000        100       100000   00000\n";
                cout << "        00  100000111      000      1000001000         000        0000    1011\n";
                cout << "         10000001          100        11000001         000        111\n";
                cout << "         10111                            000\n";

                textcolor(15);
                DrawBoard(n, board);

                printf("\nPress X to save game\n");
                printf("Press ESC to back to menu\n");
                int a = getch();
                if (a == 27) {
                    system("cls");
                    MainMenu(n, turn, board, check, point);
                }
                if (char(a) == 'X' || char(a) == 'x') {
                    printf("Save game successfully\n");
                    Sleep(1000);
                    savegame3T(n, turn, board, x, y);
                }
            }
        }
    }
}

void T2TPvP(int n, int chess[201][201], int turn, int toado_x, int toado_y, int check[201][201], int point[201][201]) {
    int S = 0, cntUndo = 0;
    int x = toado_x;
    int y = toado_y;
    while (true) {
        if (turn == 1) {
            gotoxy(0, 2*n + 2);
            cout << "            ";
            gotoxy(0, 2*n + 2);
            textcolor(9);
            cout << "BLUE TURN.";
            textcolor(15);
        }

        if (turn == -1) {
            gotoxy(0, 2*n + 2);
            cout << "            ";
            gotoxy(0, 2*n + 2);
            textcolor(12);
            cout << "RED TURN.";
            textcolor(15);
        }

        if (S == 0) {
            gotoxy(0, 2 * 3 + 3);
            cout << "Press X to save game.\n";
            cout << "Press U to undo.\n";
            cout << "Press ESC to back to menu.\n";
            S = 1;
        }

        gotoxy(x, y);

        int a = getch();
        switch (a) {
        case 72: //UP
            y -= 2;
            gotoxy(x, y);
            break;
        case 75: //LEFT
            x -= 4;
            gotoxy(x, y);
            break;
        case 77: //RIGHT
            x += 4;
            gotoxy(x, y);
            break;
        case 80: //DOWN
            y += 2;
            gotoxy(x, y);
            break;
        case 119: // W
            y -= 2;
            gotoxy(x, y);
            break;
        case 97: // A
            x -= 4;
            gotoxy(x, y);
            break;
        case 100: // D
            x += 4;
            gotoxy(x, y);
            break;
        case 115: // S
            y += 2;
            gotoxy(x, y);
            break;
        case 27: // ESC BACK TO MENU
            system("cls");
            MainMenu(n, turn, chess, check, point);
            break;
        }

        int X = (x - 2)/4 + 1;
        int Y = y/2;

        if (char(a) == 'X' || char(a) == 'x') {
            savegame3T(n, turn, chess, x, y);
            gotoxy(22, 2 * 3 + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(22, 2 * 3 + 3);
            cout << "Save game successfully";
            fto(i, 1, 3) {
                Sleep(200);
                cout << ".";
            } Sleep(200);
            gotoxy(22, 2 * 3 + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(x, y);
        }

        if (char(a) == 'U' || char(a) == 'u') {
            if (!undoX.empty()) {
                gotoxy(17, 2 * 3 + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(17, 2 * 3 + 4);
                cout << "U"; Sleep(50);
                cout << "N"; Sleep(50);
                cout << "D"; Sleep(50);
                cout << "O"; Sleep(50);
                cout << "E"; Sleep(50);
                cout << "D"; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(50);

                gotoxy(17, 2 * 3 + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(x, y);

                Undo(chess, 0);
                turn = -turn;
            }
        }

        if (a == 13 && chess[Y][X] == 0 && Y <= 3 && X <= 3 && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            cout << char((167 + turn*9)/2);
            turn = -turn;
            textcolor(15);
            Draw3T(Y, X, turn, chess, n, check, point);
        }

        if (a == 32 && chess[Y][X] == 0 && Y <= 3 && X <= 3 && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            cout << char((167 + turn*9)/2);
            turn = -turn;
            textcolor(15);
            Draw3T(Y, X, turn, chess, n, check, point);
        }
    }
}
///FIVE2WIN_______________________________________________________________
void savegame52W(int n, int turn, int board[201][201], int toado_x, int toado_y) {
    FILE *FileSave;
    FileSave = fopen("gamemode2.txt", "w");
    fprintf(FileSave, "%d %d\n", n, turn);
    fprintf(FileSave, "%d %d\n", toado_x, toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            fprintf(FileSave, "%d ", board[i][j]);
        }
        printf("\n");
    }
    fclose(FileSave);
}

void Loadgame52W(int &n, int &turn, int loadboard[201][201], int &toado_x, int &toado_y) {

    FILE *FileLoad;
    FileLoad = fopen("gamemode2.txt", "r");
    fscanf(FileLoad, "%d%d", &n, &turn);
    fscanf(FileLoad, "%d%d", &toado_x, &toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            int x;
            fscanf(FileLoad, "%d", &x);
            loadboard[i][j] = x;
        }
    }
    fclose(FileLoad);
}

int checkFive2Win(int y, int x, int chess[201][201]) {
    bool pots[10];
    int tnuoc[10];

    for (int i = 1; i <= 8; ++i) {
        pots[i] = false;
        tnuoc[i] = 1;
    }
    int i = 1;
    while (i < 5) {
        ///1///DOC
        if (chess[y][x] == chess[y+i][x] && !pots[1]) ++tnuoc[1];
        else if (chess[y][x] != chess[y+i][x]) pots[1] = true;
        if (chess[y][x] == chess[y-i][x] && !pots[2]) ++tnuoc[1];
        else if (chess[y][x] != chess[y-i][x]) pots[2] = true;
        ///2///NGANG
        if (chess[y][x] == chess[y][x+i] && !pots[3]) ++tnuoc[2];
        else if (chess[y][x] != chess[y][x+i]) pots[3] = true;
        if (chess[y][x] == chess[y][x-i] && !pots[4]) ++tnuoc[2];
        else if (chess[y][x] != chess[y][x-i]) pots[4] = true;
        ///3///CHEOCHINH
        if (chess[y][x] == chess[y+i][x+i] && !pots[5]) ++tnuoc[3];
        else if (chess[y][x] != chess[y+i][x+i]) pots[5] = true;
        if (chess[y][x] == chess[y-i][x-i] && !pots[6]) ++tnuoc[3];
        else if (chess[y][x] != chess[y-i][x-i]) pots[6] = true;
        ///4///CHEOPHU
        if (chess[y][x] == chess[y+i][x-i] && !pots[7]) ++tnuoc[4];
        else if (chess[y][x] != chess[y+i][x-i]) pots[7] = true;
        if (chess[y][x] == chess[y-i][x+i] && !pots[8]) ++tnuoc[4];
        else if (chess[y][x] != chess[y-i][x+i]) pots[8] = true;

        ++i;
    }
    fto(i, 1, 4) if (tnuoc[i] == 5) return chess[y][x];
    return 0;
}

void DrawFive2Win(int y, int x, int turn, int board[201][201], int n, int check[201][201], int point[201][201]) {
    if (checkFive2Win(y, x, board) == 1) {
        system("cls");
        gotoxy(0, 0);

        while (true) {
            textcolor(9);

            cout << "                                                                    00\n";
            cout << "   1111111       11111      11111111111             111      01     001    110001         11111       0000\n";
            cout << "     00011     0001 1000 10011001    00         0011001    100      00   0011 10001    0001 000     101\n";
            cout << "     00      000      0110   100               00  001    1000     10  100      1001  00    0001    01\n";
            cout << "    100     000       000    001   1          00  100    00000    101 100        000  01   00100   00\n";
            cout << "    001    000         00   10011100          001 000   00 101   10   001        000  00   01 001  01\n";
            cout << "   100     001         100  000   11              000  00  001  00   000         000      10  100 10\n";
            cout << "   001    000               00                    000 00   00  00    000        100       00   00001\n";
            cout << "  100     000              001      101           10001    00001      000      100       10     000\n";
            cout << "11000     1001      01   10000000111001           100      000        10001  1001   1   101     100\n";
            cout << "1111111    1001   100   1111111110111              0       01            100011    1000001       01\n";
            cout << "             1000001                                                                  \n";

            textcolor(15);
            DrawBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame52W(n, turn, board, x, y);
            }
        }
    }
    if (checkFive2Win(y, x, board) == -1) {
        system("cls");
        gotoxy(0, 0);
        while (true) {
            textcolor(12);

            cout << "                                                                                     000\n";
            cout << "     11111111100   1100001    11110001      1111001010001          111001     00      00   10000001       111100       00001\n";
            cout << "   001 000    00    000     000111  1000  1001 000    10         001 000     001     10   001   10001   001  1001     00\n";
            cout << " 101   00     1     001   100  100   100 10    00               00  000    1000     101 100       000  00    0000    00\n";
            cout << " 01   000   0      100    01   001  1001 01   100   01         101  00    10100    101  00        1001 00    0 001  10\n";
            cout << "101   0001100      001   10    0011001  100   00011001          00  00   00  00   101  000        1001 101  00 100  00\n";
            cout << " 00  100   11      00     00  000100     00  100    1               00  00  100  00    001        000       01  001 0\n";
            cout << "     001          000      01 00  00         001                    00 00   100 00     000        00       00    0000\n";
            cout << "    100           00         000  100       100       00            0001    10001      0001     100        01    1001\n";
            cout << "  1000011      0000011     100001  000    11000000001001            001     000         1000011001   10   00      00\n";
            cout << "                                    001   101     111               0       00             1111      100001        0\n";
            cout << "                                     10011001\n";
            cout << "                                       1111\n";

            textcolor(15);
            DrawBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame52W(n, turn, board, x, y);
            }
        }
    }

    if (checkFive2Win(y, x, board) == 0) {
        bool ok = false;
        fto(i, 1, n) fto(j, 1, n) if (board[i][j] == 0) ok = true;
        if (ok == true) return;
        else {
            while (true) {
                system("cls");
                textcolor(10);

                cout << "                                                     111       000\n";
                cout << "       1000011                0000011               1000       10000               11\n";
                cout << "        0000000001          1000000000001         0000000      00000       001    000\n";
                cout << "           1000000001       0001 1000000001       000000001    00000      00001   000\n";
                cout << "           000100000001     001       000001     0000000000    00000      0000    001\n";
                cout << "          0000   1000001    00000      10000    10000 10000    00000     00000   100\n";
                cout << "         10001     10000    10000      0000     0000   0000   100000     00001   000\n";
                cout << "         0000       10001   10001   100001     0000    1000    00000    10000   0001\n";
                cout << "         0000        0001   0000 100001        0001    1000     0000    00000   000\n";
                cout << "         0001        000    00000001          0001     00001    0000   100000  0001\n";
                cout << "        1000        0001  1000000           1000000000000001    0000   000000  000\n";
                cout << "        1000       0001   10000000         00000000001 1000     1000  0000000 000\n";
                cout << "        0001      0001      00000000       000001      1000      0001100 10000000\n";
                cout << "        000      000   00   000 0000001     000        1001      0000001 1000000\n";
                cout << "        000    0000000000  1001   0000001  1000        100       100000   00000\n";
                cout << "        00  100000111      000      1000001000         000        0000    1011\n";
                cout << "         10000001          100        11000001         000        111\n";
                cout << "         10111                            000\n";

                textcolor(15);
                DrawBoard(n, board);

                printf("\nPress X to save game\n");
                printf("Press ESC to back to menu\n");
                int a = getch();
                if (a == 27) {
                    system("cls");
                    MainMenu(n, turn, board, check, point);
                }
                if (char(a) == 'X' || char(a) == 'x') {
                    printf("Save game successfully\n");
                    Sleep(1000);
                    savegame52W(n, turn, board, x, y);
                }
            }
        }
    }
}

void Five2WinPvP(int n, int chess[201][201], int turn, int toado_x, int toado_y, int check[201][201], int point[201][201]) {
    int S = 0, cntUndo = 0;
    int x = toado_x;
    int y = toado_y;
    while (true) {
        if (turn == 1) {
            gotoxy(0, 2*n + 2);
            cout << "            ";
            gotoxy(0, 2*n + 2);
            textcolor(9);
            cout << "BLUE TURN.";
            textcolor(15);
        }

        if (turn == -1) {
            gotoxy(0, 2*n + 2);
            cout << "            ";
            gotoxy(0, 2*n + 2);
            textcolor(12);
            cout << "RED TURN.";
            textcolor(15);
        }

        if (S == 0) {
            gotoxy(0, 2 * n + 3);
            cout << "Press X to save game.\n";
            cout << "Press U to undo.\n";
            cout << "Press ESC to back to menu.\n";
            S = 1;
        }

        gotoxy(x, y);

        int a = getch();
        switch (a) {
        case 72: //UP
            y -= 2;
            gotoxy(x, y);
            break;
        case 75: //LEFT
            x -= 4;
            gotoxy(x, y);
            break;
        case 77: //RIGHT
            x += 4;
            gotoxy(x, y);
            break;
        case 80: //DOWN
            y += 2;
            gotoxy(x, y);
            break;
        case 119: // W
            y -= 2;
            gotoxy(x, y);
            break;
        case 97: // A
            x -= 4;
            gotoxy(x, y);
            break;
        case 100: // D
            x += 4;
            gotoxy(x, y);
            break;
        case 115: // S
            y += 2;
            gotoxy(x, y);
            break;
        case 27: // ESC BACK TO MENU
            system("cls");
            MainMenu(n, turn, chess, check, point);
            break;
        }

        int X = (x - 2)/4 + 1;
        int Y = y/2;

        if (char(a) == 'X' || char(a) == 'x') {
            savegame52W(n, turn, chess, x, y);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(22, 2 * n + 3);
            cout << "Save game successfully";
            fto(i, 1, 3) {
                Sleep(200);
                cout << ".";
            } Sleep(200);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(x, y);
        }

        if (char(a) == 'U' || char(a) == 'u') {
            if (!undoX.empty()) {
                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(17, 2 * n + 4);
                cout << "U"; Sleep(50);
                cout << "N"; Sleep(50);
                cout << "D"; Sleep(50);
                cout << "O"; Sleep(50);
                cout << "E"; Sleep(50);
                cout << "D"; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(50);

                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(x, y);

                Undo(chess, 0);
                turn = -turn;
            }
        }

        if (a == 13 && chess[Y][X] == 0 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            cout << char((167 + turn*9)/2);
            turn = -turn;
            textcolor(15);
            DrawFive2Win(Y, X, turn, chess, n, check, point);
        }

        if (a == 32 && chess[Y][X] == 0 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            cout << char((167 + turn*9)/2);
            turn = -turn;
            textcolor(15);
            DrawFive2Win(Y, X, turn, chess, n, check, point);
        }
    }
}
///PVC
void loang(int y, int x, int check[201][201], int chess[201][201]) {
    fto(i, -1, 1) {
        if (chess[y+i][x] == 0) {
            check[y+i][x] = 1;
            Xundo.pb(x);
            Yundo.pb(y+i);
        }
        if (chess[y][x+i] == 0) {
            check[y][x+i] = 1;
            Xundo.pb(x+i);
            Yundo.pb(y);
        }
        if (chess[y+i][x+i] == 0) {
            check[y+i][x+i] = 1;
            Xundo.pb(x+i);
            Yundo.pb(y+i);
        }
        if (chess[y+i][x-i] == 0) {
            check[y+i][x-i] = 1;
            Xundo.pb(x-i);
            Yundo.pb(y+i);
        }
    }
}

void evaluation(int y, int x, int chess[201][201], int point[201][201]) {
    bool pots1[10], pots2[10];
    int cntATK[10], cntDEF[10];
    int ATK[] = {1, 10, 100, 10000, 1000000};
    int DEF[] = {0, 1, 10, 1000, 100000};

    fto(i, 1, 10) {
        pots1[i] = false;
        pots2[i] = false;
        cntATK[i] = 1;
        cntDEF[i] = 1;
    }

    for (int i = 1; i < 5; ++i) {
        ///1///DOC
        if (chess[y+i][x] == -1 && !pots1[1]) ++cntATK[1];
        else if (chess[y+i][x] != -1) pots1[1] = true;
        if (chess[y-i][x] == -1 && !pots1[1]) ++cntATK[1];
        else if (chess[y-i][x] != -1) pots1[2] = true;
        ///2///NGANG
        if (chess[y][x+i] == -1 && !pots1[3]) ++cntATK[2];
        else if (chess[y][x+i] != -1) pots1[3] = true;
        if (chess[y][x-i] == -1 && !pots1[4]) ++cntATK[2];
        else if (chess[y][x-i] != -1) pots1[4] = true;
        ///3///CHEOCHINH
        if (chess[y+i][x+i] == -1 && !pots1[5]) ++cntATK[3];
        else if (chess[y+i][x+i] != -1) pots1[5] = true;
        if (chess[y-i][x-i] == -1 && !pots1[6]) ++cntATK[3];
        else if (chess[y-i][x-i] != -1) pots1[6] = true;
        ///4///CHEOPHU
        if (chess[y-i][x+i] == -1 && !pots1[7]) ++cntATK[4];
        else if (chess[y-i][x+i] != -1) pots1[7] = true;
        if (chess[y+i][x-i] == -1 && !pots1[8]) ++cntATK[4];
        else if (chess[y+i][x-i] != -1) pots1[8] = true;


        ///1///DOC
        if (chess[y+i][x] == 1 && !pots2[1]) ++cntDEF[1];
        else if (chess[y+i][x] != 1) pots2[1] = true;
        if (chess[y-i][x] == 1 && !pots2[1]) ++cntDEF[1];
        else if (chess[y-i][x] != 1) pots2[2] = true;
        ///2///NGANG
        if (chess[y][x+i] == 1 && !pots2[3]) ++cntDEF[2];
        else if (chess[y][x+i] != 1) pots2[3] = true;
        if (chess[y][x-i] == 1 && !pots2[4]) ++cntDEF[2];
        else if (chess[y][x-i] != 1) pots2[4] = true;
        ///3///CHEOCHINH
        if (chess[y+i][x+i] == 1 && !pots2[5]) ++cntDEF[3];
        else if (chess[y+i][x+i] != 1) pots2[5] = true;
        if (chess[y-i][x-i] == 1 && !pots2[6]) ++cntDEF[3];
        else if (chess[y-i][x-i] != 1) pots2[6] = true;
        ///4///CHEOPHU
        if (chess[y-i][x+i] == 1 && !pots2[7]) ++cntDEF[4];
        else if (chess[y-i][x+i] != 1) pots2[7] = true;
        if (chess[y+i][x-i] == 1 && !pots2[8]) ++cntDEF[4];
        else if (chess[y+i][x-i] != 1) pots2[8] = true;
    }

    int pointATK = 0, pointDEF = 0;
    fto(i, 1, 4) {
        pointATK += ATK[cntATK[i]];
        pointDEF += DEF[cntDEF[i]];
    }

    point[y][x] = max(pointATK, pointDEF);
}

void tick(int &ii, int &jj, int n, int check[201][201], int chess[201][201], int point[201][201]) {
    fto(i, 1, n) {
        fto(j, 1, n) {
            if (check[i][j] == 1) evaluation(i, j, chess, point);
        }
    }
    int ans = 0;
    fto(i, 1, n) {
        fto(j, 1, n) {
            if (point[i][j] > ans && check[i][j] == 1) {
                ans = point[i][j];
                ii = i;
                jj = j;
            }
        }
    }
}

void Five2WinPvC(int n, int turn, int toado_x, int toado_y, int chess[201][201], int check[201][201], int point[201][201]) {
    int S = 0, cntUndo = 0;
    int x = toado_x;
    int y = toado_y;
    while (true) {
        if (S == 0) {
            gotoxy(0, 2 * n + 2);
            cout << "Press X to save game.\n";
            cout << "Press U to undo.\n";
            cout << "Press ESC to back to menu.\n";
            S = 1;
        }

        gotoxy(x, y);

        int a = getch();
        switch (a) {
        case 72: //UP
            y -= 2;
            gotoxy(x, y);
            break;
        case 75: //LEFT
            x -= 4;
            gotoxy(x, y);
            break;
        case 77: //RIGHT
            x += 4;
            gotoxy(x, y);
            break;
        case 80: //DOWN
            y += 2;
            gotoxy(x, y);
            break;
        case 119: // W
            y -= 2;
            gotoxy(x, y);
            break;
        case 97: // A
            x -= 4;
            gotoxy(x, y);
            break;
        case 100: // D
            x += 4;
            gotoxy(x, y);
            break;
        case 115: // S
            y += 2;
            gotoxy(x, y);
            break;
        case 27: // ESC BACK TO MENU
            system("cls");
            MainMenu(n, turn, chess, check, point);
            break;
        }

        int X = (x - 2)/4 + 1;
        int Y = y/2;

        if (char(a) == 'X' || char(a) == 'x') {
            //savegame(n, turn, chess, x, y);
            gotoxy(22, 2 * n + 2);
            fto(i, 1, 50) cout << " ";
            gotoxy(22, 2 * n + 2);
            cout << "Save game successfully";
            fto(i, 1, 3) {
                Sleep(200);
                cout << ".";
            } Sleep(200);
            gotoxy(22, 2 * n + 2);
            fto(i, 1, 50) cout << " ";
            gotoxy(x, y);
        }

        if (char(a) == 'U' || char(a) == 'u') {
            if (!undoX.empty()) {
                gotoxy(17, 2 * n + 3);
                fto(i, 1, 50) cout << " ";
                gotoxy(17, 2 * n + 3);
                cout << "U"; Sleep(50);
                cout << "N"; Sleep(50);
                cout << "D"; Sleep(50);
                cout << "O"; Sleep(50);
                cout << "E"; Sleep(50);
                cout << "D"; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(50);

                gotoxy(17, 2 * n + 3);
                fto(i, 1, 50) cout << " ";
                gotoxy(x, y);

                UndoPVC(chess, check, point);
                Undo(chess, 0);
                Undo(chess, 0);
            }
        }

        Xundo.clear();
        Yundo.clear();

        if (a == 13 && chess[Y][X] == 0 && Y <= n && X <= n && Y > 0 && X > 0) {
            ///PLA TURN
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn; check[Y][X] = -1;
            textcolor((21 - turn*3)/2);
            cout << char((167 + turn*9)/2);
            turn = -turn;
            textcolor(15);
            DrawFive2Win(Y, X, turn, chess, n, check, point);
            loang(Y, X, check, chess);
            tick(Y, X, n, check, chess, point);
            ///COM TURN
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn; check[Y][X] = -1;
            gotoxy((X - 1)*4 + 2, 2*Y);
            textcolor((21 - turn*3)/2);
            cout << char((167 + turn*9)/2);
            turn = -turn;
            textcolor(15);
            DrawFive2Win(Y, X, turn, chess, n, check, point);
            loang(Y, X, check, chess);
        }
        if (a == 32 && chess[Y][X] == 0 && Y <= n && X <= n && Y > 0 && X > 0) {
            ///PLA TURN
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn; check[Y][X] = 0;
            textcolor((21 - turn*3)/2);
            cout << char((167 + turn*9)/2);
            turn = -turn;
            textcolor(15);
            DrawFive2Win(Y, X, turn, chess, n, check, point);
            loang(Y, X, check, chess);
            tick(Y, X, n, check, chess, point);
            ///COM TURN
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn; check[Y][X] = 0;
            gotoxy((X - 1)*4 + 2, 2*Y);
            textcolor((21 - turn*3)/2);
            cout << char((167 + turn*9)/2);
            turn = -turn;
            textcolor(15);
            DrawFive2Win(Y, X, turn, chess, n, check, point);
            loang(Y, X, check, chess);
        }
    }
}
///2BLOCKEDHEAD_______________________________________________________________
void savegame2BH(int n, int turn, int board[201][201], int toado_x, int toado_y) {
    FILE *FileSave;
    FileSave = fopen("gamemode3.txt", "w");
    fprintf(FileSave, "%d %d\n", n, turn);
    fprintf(FileSave, "%d %d\n", toado_x, toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            fprintf(FileSave, "%d ", board[i][j]);
        }
        printf("\n");
    }
    fclose(FileSave);
}

void Loadgame2BH(int &n, int &turn, int loadboard[201][201], int &toado_x, int &toado_y) {

    FILE *FileLoad;
    FileLoad = fopen("gamemode3.txt", "r");
    fscanf(FileLoad, "%d%d", &n, &turn);
    fscanf(FileLoad, "%d%d", &toado_x, &toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            int x;
            fscanf(FileLoad, "%d", &x);
            loadboard[i][j] = x;
        }
    }
    fclose(FileLoad);
}

int checkFive(int y, int x, int chess[201][201]) {
    bool pots[10], kcolb[10];
    int tnuoc[10];

    for (int i = 1; i <= 8; ++i) {
        pots[i] = false;
        kcolb[i] = false;
        tnuoc[i] = 1;
    }
    int i = 1;
    while (i < 5) {
        ///1///DOC
        if (chess[y][x] == chess[y+i][x] && !pots[1]) ++tnuoc[1];
        else if (chess[y][x] != chess[y+i][x]) {
                if ((chess[y+i][x] + chess[y][x]) == 0) kcolb[1] = true;
                pots[1] = true;
        }
        if (chess[y][x] == chess[y-i][x] && !pots[2]) ++tnuoc[1];
        else if (chess[y][x] != chess[y-i][x]) {
                if ((chess[y-i][x] + chess[y][x]) == 0) kcolb[2] = true;
                pots[2] = true;
        }
        ///2///NGANG
        if (chess[y][x] == chess[y][x+i] && !pots[3]) ++tnuoc[2];
        else if (chess[y][x] != chess[y][x+i]) {
                if ((chess[y][x+i] + chess[y][x]) == 0) kcolb[3] = true;
                pots[3] = true;
        }
        if (chess[y][x] == chess[y][x-i] && !pots[4]) ++tnuoc[2];
        else if (chess[y][x] != chess[y][x-i]) {
                if ((chess[y][x-i] + chess[y][x]) == 0) kcolb[4] = true;
                pots[4] = true;
        }
        ///3///CHEOCHINH
        if (chess[y][x] == chess[y+i][x+i] && !pots[5]) ++tnuoc[3];
        else if (chess[y][x] != chess[y+i][x+i]) {
                if ((chess[y+i][x+i] + chess[y][x]) == 0) kcolb[5] = true;
                pots[5] = true;
        }
        if (chess[y][x] == chess[y-i][x-i] && !pots[6]) ++tnuoc[3];
        else if (chess[y][x] != chess[y-i][x-i]) {
                if ((chess[y-i][x-i] + chess[y][x]) == 0) kcolb[6] = true;
                pots[6] = true;
        }
        ///4///CHEOPHU
        if (chess[y][x] == chess[y+i][x-i] && !pots[7]) ++tnuoc[4];
        else if (chess[y][x] != chess[y+i][x-i]) {
                if ((chess[y+i][x-i] + chess[y][x]) == 0) kcolb[7] = true;
                pots[7] = true;
        }
        if (chess[y][x] == chess[y-i][x+i] && !pots[8]) ++tnuoc[4];
        else if (chess[y][x] != chess[y-i][x+i]) {
                if ((chess[y-i][x+i] + chess[y][x]) == 0) kcolb[8] = true;
                pots[8] = true;
        }

        ++i;
    }
    fto(i, 1, 4) if (tnuoc[i] >= 5 && !kcolb[2*i-1] && !kcolb[2*i]) return chess[y][x];
    return 0;
}

void DrawFive(int y, int x, int turn, int board[201][201], int n, int check[201][201], int point[201][201]) {
    if (checkFive(y, x, board) == 1) {
        system("cls");
        gotoxy(0, 0);

        while (true) {
            textcolor(9);

            cout << "                                                                    00\n";
            cout << "   1111111       11111      11111111111             111      01     001    110001         11111       0000\n";
            cout << "     00011     0001 1000 10011001    00         0011001    100      00   0011 10001    0001 000     101\n";
            cout << "     00      000      0110   100               00  001    1000     10  100      1001  00    0001    01\n";
            cout << "    100     000       000    001   1          00  100    00000    101 100        000  01   00100   00\n";
            cout << "    001    000         00   10011100          001 000   00 101   10   001        000  00   01 001  01\n";
            cout << "   100     001         100  000   11              000  00  001  00   000         000      10  100 10\n";
            cout << "   001    000               00                    000 00   00  00    000        100       00   00001\n";
            cout << "  100     000              001      101           10001    00001      000      100       10     000\n";
            cout << "11000     1001      01   10000000111001           100      000        10001  1001   1   101     100\n";
            cout << "1111111    1001   100   1111111110111              0       01            100011    1000001       01\n";
            cout << "             1000001                                                                  \n";

            textcolor(15);
            DrawBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame2BH(n, turn, board, x, y);
            }
        }
    }
    if (checkFive(y, x, board) == -1) {
        system("cls");
        gotoxy(0, 0);
        while (true) {
            textcolor(12);

            cout << "                                                                                     000\n";
            cout << "     11111111100   1100001    11110001      1111001010001          111001     00      00   10000001       111100       00001\n";
            cout << "   001 000    00    000     000111  1000  1001 000    10         001 000     001     10   001   10001   001  1001     00\n";
            cout << " 101   00     1     001   100  100   100 10    00               00  000    1000     101 100       000  00    0000    00\n";
            cout << " 01   000   0      100    01   001  1001 01   100   01         101  00    10100    101  00        1001 00    0 001  10\n";
            cout << "101   0001100      001   10    0011001  100   00011001          00  00   00  00   101  000        1001 101  00 100  00\n";
            cout << " 00  100   11      00     00  000100     00  100    1               00  00  100  00    001        000       01  001 0\n";
            cout << "     001          000      01 00  00         001                    00 00   100 00     000        00       00    0000\n";
            cout << "    100           00         000  100       100       00            0001    10001      0001     100        01    1001\n";
            cout << "  1000011      0000011     100001  000    11000000001001            001     000         1000011001   10   00      00\n";
            cout << "                                    001   101     111               0       00             1111      100001        0\n";
            cout << "                                     10011001\n";
            cout << "                                       1111\n";

            textcolor(15);
            DrawBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame2BH(n, turn, board, x, y);
            }
        }
    }

    if (checkFive(y, x, board) == 0) {
        bool ok = false;
        fto(i, 1, n) fto(j, 1, n) if (board[i][j] == 0) ok = true;
        if (ok == true) return;
        else {
            while (true) {
                system("cls");
                textcolor(10);

                cout << "                                                     111       000\n";
                cout << "       1000011                0000011               1000       10000               11\n";
                cout << "        0000000001          1000000000001         0000000      00000       001    000\n";
                cout << "           1000000001       0001 1000000001       000000001    00000      00001   000\n";
                cout << "           000100000001     001       000001     0000000000    00000      0000    001\n";
                cout << "          0000   1000001    00000      10000    10000 10000    00000     00000   100\n";
                cout << "         10001     10000    10000      0000     0000   0000   100000     00001   000\n";
                cout << "         0000       10001   10001   100001     0000    1000    00000    10000   0001\n";
                cout << "         0000        0001   0000 100001        0001    1000     0000    00000   000\n";
                cout << "         0001        000    00000001          0001     00001    0000   100000  0001\n";
                cout << "        1000        0001  1000000           1000000000000001    0000   000000  000\n";
                cout << "        1000       0001   10000000         00000000001 1000     1000  0000000 000\n";
                cout << "        0001      0001      00000000       000001      1000      0001100 10000000\n";
                cout << "        000      000   00   000 0000001     000        1001      0000001 1000000\n";
                cout << "        000    0000000000  1001   0000001  1000        100       100000   00000\n";
                cout << "        00  100000111      000      1000001000         000        0000    1011\n";
                cout << "         10000001          100        11000001         000        111\n";
                cout << "         10111                            000\n";

                textcolor(15);
                DrawBoard(n, board);

                printf("\nPress X to save game\n");
                printf("Press ESC to back to menu\n");
                int a = getch();
                if (a == 27) {
                    system("cls");
                    MainMenu(n, turn, board, check, point);
                }
                if (char(a) == 'X' || char(a) == 'x') {
                    printf("Save game successfully\n");
                    Sleep(1000);
                    savegame2BH(n, turn, board, x, y);
                }
            }
        }
    }
}

void FivePvP(int n, int chess[201][201], int turn, int toado_x, int toado_y, int check[201][201], int point[201][201]) {
    int S = 0, cntUndo = 0;
    int x = toado_x;
    int y = toado_y;
    while (true) {
        if (turn == 1) {
            gotoxy(0, 2*n + 2);
            cout << "            ";
            gotoxy(0, 2*n + 2);
            textcolor(9);
            cout << "BLUE TURN.";
            textcolor(15);
        }
        if (turn == -1) {
            gotoxy(0, 2*n + 2);
            cout << "            ";
            gotoxy(0, 2*n + 2);
            textcolor(12);
            cout << "RED TURN.";
            textcolor(15);
        }
        if (S == 0) {
            gotoxy(0, 2 * n + 3);
            cout << "Press X to save game.\n";
            cout << "Press U to undo.\n";
            cout << "Press ESC to back to menu.\n";
            S = 1;
        }

        gotoxy(x, y);

        int a = getch();
        switch (a) {
        case 72: //UP
            y -= 2;
            gotoxy(x, y);
            break;
        case 75: //LEFT
            x -= 4;
            gotoxy(x, y);
            break;
        case 77: //RIGHT
            x += 4;
            gotoxy(x, y);
            break;
        case 80: //DOWN
            y += 2;
            gotoxy(x, y);
            break;
        case 119: // W
            y -= 2;
            gotoxy(x, y);
            break;
        case 97: // A
            x -= 4;
            gotoxy(x, y);
            break;
        case 100: // D
            x += 4;
            gotoxy(x, y);
            break;
        case 115: // S
            y += 2;
            gotoxy(x, y);
            break;
        case 27: // ESC BACK TO MENU
            system("cls");
            MainMenu(n, turn, chess, check, point);
            break;
        }

        int X = (x - 2)/4 + 1;
        int Y = y/2;

        if (char(a) == 'X' || char(a) == 'x') {
            savegame2BH(n, turn, chess, x, y);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(22, 2 * n + 3);
            cout << "Save game successfully";
            fto(i, 1, 3) {
                Sleep(200);
                cout << ".";
            } Sleep(200);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(x, y);
        }

        if (char(a) == 'U' || char(a) == 'u') {
            if (!undoX.empty()) {
                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(17, 2 * n + 4);
                cout << "U"; Sleep(50);
                cout << "N"; Sleep(50);
                cout << "D"; Sleep(50);
                cout << "O"; Sleep(50);
                cout << "E"; Sleep(50);
                cout << "D"; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(50);

                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(x, y);

                Undo(chess, 0);
                turn = -turn;
            }
        }

        if (a == 13 && chess[Y][X] == 0 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            cout << char((167 + turn*9)/2);
            turn = -turn;
            textcolor(15);
            DrawFive(Y, X, turn, chess, n, check, point);
        }

        if (a == 32 && chess[Y][X] == 0 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            cout << char((167 + turn*9)/2);
            turn = -turn;
            textcolor(15);
            DrawFive(Y, X, turn, chess, n, check, point);
        }
    }
}
///1ST5OW_______________________________________________________________
void savegame1st5(int n, int turn, int board[201][201], int toado_x, int toado_y) {
    FILE *FileSave;
    FileSave = fopen("gamemode4.txt", "w");
    fprintf(FileSave, "%d %d\n", n, turn);
    fprintf(FileSave, "%d %d\n", toado_x, toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            fprintf(FileSave, "%d ", board[i][j]);
        }
        printf("\n");
    }
    fclose(FileSave);
}

void Loadgame1st5(int &n, int &turn, int loadboard[201][201], int &toado_x, int &toado_y) {

    FILE *FileLoad;
    FileLoad = fopen("gamemode4.txt", "r");
    fscanf(FileLoad, "%d%d", &n, &turn);
    fscanf(FileLoad, "%d%d", &toado_x, &toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            int x;
            fscanf(FileLoad, "%d", &x);
            loadboard[i][j] = x;
        }
    }
    fclose(FileLoad);
}

int checkF5thO(int y, int x, int chess[201][201], int turn) {
    bool pots[10];
    int tnuoc[10];

    for (int i = 1; i <= 8; ++i) {
        pots[i] = false;
        tnuoc[i] = 1;
    }
    int i = 1;
    while (i < 5) {
        ///1///DOC
        if (chess[y+i][x] != 0 && !pots[1]) ++tnuoc[1];
        else pots[1] = true;
        if (chess[y-i][x] != 0 && !pots[2]) ++tnuoc[1];
        else pots[2] = true;
        ///2///NGANG
        if (chess[y][x+i] != 0 && !pots[3]) ++tnuoc[2];
        else pots[3] = true;
        if (chess[y][x-i] != 0 && !pots[4]) ++tnuoc[2];
        else pots[4] = true;
        ///3///CHEOCHINH
        if (chess[y+i][x+i] != 0 && !pots[5]) ++tnuoc[3];
        else pots[5] = true;
        if (chess[y-i][x-i] != 0 && !pots[6]) ++tnuoc[3];
        else pots[6] = true;
        ///4///CHEOPHU
        if (chess[y+i][x-i] != 0 && !pots[7]) ++tnuoc[4];
        else pots[7] = true;
        if (chess[y-i][x+i] != 0 && !pots[8]) ++tnuoc[4];
        else pots[8] = true;

        ++i;
    }
    fto(i, 1, 4) if (tnuoc[i] == 5) return turn;
    return 0;
}

void Draw1st5(int y, int x, int turn, int board[201][201], int n, int check[201][201], int point[201][201]) {
    if (checkF5thO(y, x, board, turn) == 1) {
        system("cls");
        gotoxy(0, 0);

        while (true) {
            textcolor(9);

            cout << "                                                                    00\n";
            cout << "   1111111       11111      11111111111             111      01     001    110001         11111       0000\n";
            cout << "     00011     0001 1000 10011001    00         0011001    100      00   0011 10001    0001 000     101\n";
            cout << "     00      000      0110   100               00  001    1000     10  100      1001  00    0001    01\n";
            cout << "    100     000       000    001   1          00  100    00000    101 100        000  01   00100   00\n";
            cout << "    001    000         00   10011100          001 000   00 101   10   001        000  00   01 001  01\n";
            cout << "   100     001         100  000   11              000  00  001  00   000         000      10  100 10\n";
            cout << "   001    000               00                    000 00   00  00    000        100       00   00001\n";
            cout << "  100     000              001      101           10001    00001      000      100       10     000\n";
            cout << "11000     1001      01   10000000111001           100      000        10001  1001   1   101     100\n";
            cout << "1111111    1001   100   1111111110111              0       01            100011    1000001       01\n";
            cout << "             1000001                                                                  \n";

            textcolor(15);
            Draw1st5Board(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame1st5(n, turn, board, x, y);
            }
        }
    }
    if (checkF5thO(y, x, board, turn) == -1) {
        system("cls");
        gotoxy(0, 0);
        while (true) {
            textcolor(12);

            cout << "                                                                                     000\n";
            cout << "     11111111100   1100001    11110001      1111001010001          111001     00      00   10000001       111100       00001\n";
            cout << "   001 000    00    000     000111  1000  1001 000    10         001 000     001     10   001   10001   001  1001     00\n";
            cout << " 101   00     1     001   100  100   100 10    00               00  000    1000     101 100       000  00    0000    00\n";
            cout << " 01   000   0      100    01   001  1001 01   100   01         101  00    10100    101  00        1001 00    0 001  10\n";
            cout << "101   0001100      001   10    0011001  100   00011001          00  00   00  00   101  000        1001 101  00 100  00\n";
            cout << " 00  100   11      00     00  000100     00  100    1               00  00  100  00    001        000       01  001 0\n";
            cout << "     001          000      01 00  00         001                    00 00   100 00     000        00       00    0000\n";
            cout << "    100           00         000  100       100       00            0001    10001      0001     100        01    1001\n";
            cout << "  1000011      0000011     100001  000    11000000001001            001     000         1000011001   10   00      00\n";
            cout << "                                    001   101     111               0       00             1111      100001        0\n";
            cout << "                                     10011001\n";
            cout << "                                       1111\n";

            textcolor(15);
            Draw1st5Board(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame1st5(n, turn, board, x, y);
            }
        }
    }

    if (checkF5thO(y, x, board, turn) == 0) {
        bool ok = false;
        fto(i, 1, n) fto(j, 1, n) if (board[i][j] == 0) ok = true;
        if (ok == true) return;
        else {
            while (true) {
                system("cls");
                textcolor(10);

                cout << "                                                     111       000\n";
                cout << "       1000011                0000011               1000       10000               11\n";
                cout << "        0000000001          1000000000001         0000000      00000       001    000\n";
                cout << "           1000000001       0001 1000000001       000000001    00000      00001   000\n";
                cout << "           000100000001     001       000001     0000000000    00000      0000    001\n";
                cout << "          0000   1000001    00000      10000    10000 10000    00000     00000   100\n";
                cout << "         10001     10000    10000      0000     0000   0000   100000     00001   000\n";
                cout << "         0000       10001   10001   100001     0000    1000    00000    10000   0001\n";
                cout << "         0000        0001   0000 100001        0001    1000     0000    00000   000\n";
                cout << "         0001        000    00000001          0001     00001    0000   100000  0001\n";
                cout << "        1000        0001  1000000           1000000000000001    0000   000000  000\n";
                cout << "        1000       0001   10000000         00000000001 1000     1000  0000000 000\n";
                cout << "        0001      0001      00000000       000001      1000      0001100 10000000\n";
                cout << "        000      000   00   000 0000001     000        1001      0000001 1000000\n";
                cout << "        000    0000000000  1001   0000001  1000        100       100000   00000\n";
                cout << "        00  100000111      000      1000001000         000        0000    1011\n";
                cout << "         10000001          100        11000001         000        111\n";
                cout << "         10111                            000\n";

                textcolor(15);
                Draw1st5Board(n, board);

                printf("\nPress X to save game\n");
                printf("Press ESC to back to menu\n");
                int a = getch();
                if (a == 27) {
                    system("cls");
                    MainMenu(n, turn, board, check, point);
                }
                if (char(a) == 'X' || char(a) == 'x') {
                    printf("Save game successfully\n");
                    Sleep(1000);
                    savegame1st5(n, turn, board, x, y);
                }
            }
        }
    }
}

void Fst5thOPvP(int n, int chess[201][201], int turn, int toado_x, int toado_y, int check[201][201], int point[201][201]) {
    int S = 0, cntUndo = 0;
    int x = toado_x;
    int y = toado_y;
    while (true) {
        if (turn == 1) {
            gotoxy(0, 2*n + 2);
            cout << "            ";
            gotoxy(0, 2*n + 2);
            textcolor(9);
            cout << "BLUE TURN.";
            textcolor(15);
        }
        if (turn == -1) {
            gotoxy(0, 2*n + 2);
            cout << "            ";
            gotoxy(0, 2*n + 2);
            textcolor(12);
            cout << "RED TURN.";
            textcolor(15);
        }

        if (S == 0) {
            gotoxy(0, 2 * n + 3);
            cout << "Press X to save game.\n";
            cout << "Press U to undo.\n";
            cout << "Press ESC to back to menu.\n";
            S = 1;
        }

        gotoxy(x, y);

        int a = getch();
        switch (a) {
        case 72: //UP
            y -= 2;
            gotoxy(x, y);
            break;
        case 75: //LEFT
            x -= 4;
            gotoxy(x, y);
            break;
        case 77: //RIGHT
            x += 4;
            gotoxy(x, y);
            break;
        case 80: //DOWN
            y += 2;
            gotoxy(x, y);
            break;
        case 119: // W
            y -= 2;
            gotoxy(x, y);
            break;
        case 97: // A
            x -= 4;
            gotoxy(x, y);
            break;
        case 100: // D
            x += 4;
            gotoxy(x, y);
            break;
        case 115: // S
            y += 2;
            gotoxy(x, y);
            break;
        case 27: // ESC BACK TO MENU
            system("cls");
            MainMenu(n, turn, chess, check, point);
            break;
        }

        int X = (x - 2)/4 + 1;
        int Y = y/2;

        if (char(a) == 'X' || char(a) == 'x') {
            savegame1st5(n, turn, chess, x, y);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(22, 2 * n + 3);
            cout << "Save game successfully";
            fto(i, 1, 3) {
                Sleep(200);
                cout << ".";
            } Sleep(200);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(x, y);
        }

        if (char(a) == 'U' || char(a) == 'u') {
            if (!undoX.empty()) {
                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(17, 2 * n + 4);
                cout << "U"; Sleep(50);
                cout << "N"; Sleep(50);
                cout << "D"; Sleep(50);
                cout << "O"; Sleep(50);
                cout << "E"; Sleep(50);
                cout << "D"; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(50);

                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(x, y);

                Undo(chess, 0);
                turn = -turn;
            }
        }

        if (a == 13 && chess[Y][X] == 0 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            cout << char((167 - 1*9)/2);
            textcolor(15);
            Draw1st5(Y, X, turn, chess, n, check, point);
            turn = -turn;
        }

        if (a == 32 && chess[Y][X] == 0 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            cout << char((167 - 1*9)/2);
            textcolor(15);
            Draw1st5(Y, X, turn, chess, n, check, point);
            turn = -turn;
        }
    }
}
///1ST5OL_______________________________________________________________
void savegame1st5L(int n, int turn, int board[201][201], int toado_x, int toado_y) {
    FILE *FileSave;
    FileSave = fopen("gamemode5.txt", "w");
    fprintf(FileSave, "%d %d\n", n, turn);
    fprintf(FileSave, "%d %d\n", toado_x, toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            fprintf(FileSave, "%d ", board[i][j]);
        }
        printf("\n");
    }
    fclose(FileSave);
}

void Loadgame1st5L(int &n, int &turn, int loadboard[201][201], int &toado_x, int &toado_y) {

    FILE *FileLoad;
    FileLoad = fopen("gamemode5.txt", "r");
    fscanf(FileLoad, "%d%d", &n, &turn);
    fscanf(FileLoad, "%d%d", &toado_x, &toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            int x;
            fscanf(FileLoad, "%d", &x);
            loadboard[i][j] = x;
        }
    }
    fclose(FileLoad);
}

int check_F5thO(int y, int x, int chess[201][201], int turn) {
    bool pots[10];
    int tnuoc[10];

    for (int i = 1; i <= 8; ++i) {
        pots[i] = false;
        tnuoc[i] = 1;
    }
    int i = 1;
    while (i < 5) {
        ///1///DOC
        if (chess[y+i][x] != 0 && !pots[1]) ++tnuoc[1];
        else pots[1] = true;
        if (chess[y-i][x] != 0 && !pots[2]) ++tnuoc[1];
        else pots[2] = true;
        ///2///NGANG
        if (chess[y][x+i] != 0 && !pots[3]) ++tnuoc[2];
        else pots[3] = true;
        if (chess[y][x-i] != 0 && !pots[4]) ++tnuoc[2];
        else pots[4] = true;
        ///3///CHEOCHINH
        if (chess[y+i][x+i] != 0 && !pots[5]) ++tnuoc[3];
        else pots[5] = true;
        if (chess[y-i][x-i] != 0 && !pots[6]) ++tnuoc[3];
        else pots[6] = true;
        ///4///CHEOPHU
        if (chess[y+i][x-i] != 0 && !pots[7]) ++tnuoc[4];
        else pots[7] = true;
        if (chess[y-i][x+i] != 0 && !pots[8]) ++tnuoc[4];
        else pots[8] = true;

        ++i;
    }
    fto(i, 1, 4) if (tnuoc[i] == 5) return chess[y][x];
    return 0;
}

void Draw_1st5(int y, int x, int turn, int board[201][201], int n, int check[201][201], int point[201][201]) {
    if (check_F5thO(y, x, board, turn) == -1) {
        system("cls");
        gotoxy(0, 0);

        while (true) {
            textcolor(9);

            cout << "                                                                    00\n";
            cout << "   1111111       11111      11111111111             111      01     001    110001         11111       0000\n";
            cout << "     00011     0001 1000 10011001    00         0011001    100      00   0011 10001    0001 000     101\n";
            cout << "     00      000      0110   100               00  001    1000     10  100      1001  00    0001    01\n";
            cout << "    100     000       000    001   1          00  100    00000    101 100        000  01   00100   00\n";
            cout << "    001    000         00   10011100          001 000   00 101   10   001        000  00   01 001  01\n";
            cout << "   100     001         100  000   11              000  00  001  00   000         000      10  100 10\n";
            cout << "   001    000               00                    000 00   00  00    000        100       00   00001\n";
            cout << "  100     000              001      101           10001    00001      000      100       10     000\n";
            cout << "11000     1001      01   10000000111001           100      000        10001  1001   1   101     100\n";
            cout << "1111111    1001   100   1111111110111              0       01            100011    1000001       01\n";
            cout << "             1000001                                                                  \n";

            textcolor(15);
            Draw1st5Board(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame1st5L(n, turn, board, x, y);
            }
        }
    }
    if (check_F5thO(y, x, board, turn) == 1) {
        system("cls");
        gotoxy(0, 0);
        while (true) {
            textcolor(12);

            cout << "                                                                                     000\n";
            cout << "     11111111100   1100001    11110001      1111001010001          111001     00      00   10000001       111100       00001\n";
            cout << "   001 000    00    000     000111  1000  1001 000    10         001 000     001     10   001   10001   001  1001     00\n";
            cout << " 101   00     1     001   100  100   100 10    00               00  000    1000     101 100       000  00    0000    00\n";
            cout << " 01   000   0      100    01   001  1001 01   100   01         101  00    10100    101  00        1001 00    0 001  10\n";
            cout << "101   0001100      001   10    0011001  100   00011001          00  00   00  00   101  000        1001 101  00 100  00\n";
            cout << " 00  100   11      00     00  000100     00  100    1               00  00  100  00    001        000       01  001 0\n";
            cout << "     001          000      01 00  00         001                    00 00   100 00     000        00       00    0000\n";
            cout << "    100           00         000  100       100       00            0001    10001      0001     100        01    1001\n";
            cout << "  1000011      0000011     100001  000    11000000001001            001     000         1000011001   10   00      00\n";
            cout << "                                    001   101     111               0       00             1111      100001        0\n";
            cout << "                                     10011001\n";
            cout << "                                       1111\n";

            textcolor(15);
            Draw1st5Board(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame1st5L(n, turn, board, x, y);
            }
        }
    }

    if (check_F5thO(y, x, board, turn) == 0) {
        bool ok = false;
        fto(i, 1, n) fto(j, 1, n) if (board[i][j] == 0) ok = true;
        if (ok == true) return;
        else {
            while (true) {
                system("cls");
                textcolor(10);

                cout << "                                                     111       000\n";
                cout << "       1000011                0000011               1000       10000               11\n";
                cout << "        0000000001          1000000000001         0000000      00000       001    000\n";
                cout << "           1000000001       0001 1000000001       000000001    00000      00001   000\n";
                cout << "           000100000001     001       000001     0000000000    00000      0000    001\n";
                cout << "          0000   1000001    00000      10000    10000 10000    00000     00000   100\n";
                cout << "         10001     10000    10000      0000     0000   0000   100000     00001   000\n";
                cout << "         0000       10001   10001   100001     0000    1000    00000    10000   0001\n";
                cout << "         0000        0001   0000 100001        0001    1000     0000    00000   000\n";
                cout << "         0001        000    00000001          0001     00001    0000   100000  0001\n";
                cout << "        1000        0001  1000000           1000000000000001    0000   000000  000\n";
                cout << "        1000       0001   10000000         00000000001 1000     1000  0000000 000\n";
                cout << "        0001      0001      00000000       000001      1000      0001100 10000000\n";
                cout << "        000      000   00   000 0000001     000        1001      0000001 1000000\n";
                cout << "        000    0000000000  1001   0000001  1000        100       100000   00000\n";
                cout << "        00  100000111      000      1000001000         000        0000    1011\n";
                cout << "         10000001          100        11000001         000        111\n";
                cout << "         10111                            000\n";

                textcolor(15);
                Draw1st5Board(n, board);

                printf("\nPress X to save game\n");
                printf("Press ESC to back to menu\n");
                int a = getch();
                if (a == 27) {
                    system("cls");
                    MainMenu(n, turn, board, check, point);
                }
                if (char(a) == 'X' || char(a) == 'x') {
                    printf("Save game successfully\n");
                    Sleep(1000);
                    savegame1st5L(n, turn, board, x, y);
                }
            }
        }
    }
}

void Fst5thOLPvP(int n, int chess[201][201], int turn, int toado_x, int toado_y, int check[201][201], int point[201][201]) {
    int S = 0, cntUndo = 0;
    int x = toado_x;
    int y = toado_y;
    while (true) {
        if (turn == 1) {
            gotoxy(0, 2*n + 2);
            cout << "            ";
            gotoxy(0, 2*n + 2);
            textcolor(9);
            cout << "BLUE TURN.";
            textcolor(15);
        }

        if (turn == -1) {
            gotoxy(0, 2*n + 2);
            cout << "            ";
            gotoxy(0, 2*n + 2);
            textcolor(12);
            cout << "RED TURN.";
            textcolor(15);
        }

        if (S == 0) {
            gotoxy(0, 2 * n + 3);
            cout << "Press X to save game.\n";
            cout << "Press U to undo.\n";
            cout << "Press ESC to back to menu.\n";
            S = 1;
        }

        gotoxy(x, y);

        int a = getch();
        switch (a) {
        case 72: //UP
            y -= 2;
            gotoxy(x, y);
            break;
        case 75: //LEFT
            x -= 4;
            gotoxy(x, y);
            break;
        case 77: //RIGHT
            x += 4;
            gotoxy(x, y);
            break;
        case 80: //DOWN
            y += 2;
            gotoxy(x, y);
            break;
        case 119: // W
            y -= 2;
            gotoxy(x, y);
            break;
        case 97: // A
            x -= 4;
            gotoxy(x, y);
            break;
        case 100: // D
            x += 4;
            gotoxy(x, y);
            break;
        case 115: // S
            y += 2;
            gotoxy(x, y);
            break;
        case 27: // ESC BACK TO MENU
            system("cls");
            MainMenu(n, turn, chess, check, point);
            break;
        }

        int X = (x - 2)/4 + 1;
        int Y = y/2;

        if (char(a) == 'X' || char(a) == 'x') {
            savegame1st5L(n, turn, chess, x, y);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(22, 2 * n + 3);
            cout << "Save game successfully";
            fto(i, 1, 3) {
                Sleep(200);
                cout << ".";
            } Sleep(200);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(x, y);
        }

        if (char(a) == 'U' || char(a) == 'u') {
            if (!undoX.empty()) {
                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(17, 2 * n + 4);
                cout << "U"; Sleep(50);
                cout << "N"; Sleep(50);
                cout << "D"; Sleep(50);
                cout << "O"; Sleep(50);
                cout << "E"; Sleep(50);
                cout << "D"; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(50);

                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(x, y);

                Undo(chess, 0);
                turn = -turn;
            }
        }

        if (a == 13 && chess[Y][X] == 0 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            cout << char((167 - 1*9)/2);
            textcolor(15);
            Draw_1st5(Y, X, turn, chess, n, check, point);
            turn = -turn;
        }

        if (a == 32 && chess[Y][X] == 0 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            cout << char((167 - 1*9)/2);
            textcolor(15);
            Draw_1st5(Y, X, turn, chess, n, check, point);
            turn = -turn;
        }
    }
}
///(N/2)W NXN_______________________________________________________________
void savegame2N(int n, int turn, int board[201][201], int toado_x, int toado_y) {
    FILE *FileSave;
    FileSave = fopen("gamemode6.txt", "w");
    fprintf(FileSave, "%d %d\n", n, turn);
    fprintf(FileSave, "%d %d\n", toado_x, toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            fprintf(FileSave, "%d ", board[i][j]);
        }
        printf("\n");
    }
    fclose(FileSave);
}

void Loadgame2N(int &n, int &turn, int loadboard[201][201], int &toado_x, int &toado_y) {

    FILE *FileLoad;
    FileLoad = fopen("gamemode6.txt", "r");
    fscanf(FileLoad, "%d%d", &n, &turn);
    fscanf(FileLoad, "%d%d", &toado_x, &toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            int x;
            fscanf(FileLoad, "%d", &x);
            loadboard[i][j] = x;
        }
    }
    fclose(FileLoad);
}

int checkN_1W(int n, int y, int x, int chess[201][201], int turn) {
    bool pots[10];
    int tnuoc[10];

    for (int i = 1; i <= 8; ++i) {
        pots[i] = false;
        tnuoc[i] = 1;
    }
    int i = 1;
    while (i < n/2) {
        ///1///DOC
        if (chess[y+i][x] == chess[y][x] && !pots[1]) ++tnuoc[1];
        else if (chess[y+i][x] != chess[y][x]) pots[1] = true;
        if (chess[y-i][x] == chess[y][x] && !pots[1]) ++tnuoc[1];
        else if (chess[y-i][x] != chess[y][x]) pots[2] = true;
        ///2///NGANG
        if (chess[y][x+i] == chess[y][x] && !pots[3]) ++tnuoc[2];
        else if (chess[y][x+i] != chess[y][x]) pots[3] = true;
        if (chess[y][x-i] == chess[y][x] && !pots[4]) ++tnuoc[2];
        else if (chess[y][x-i] != chess[y][x]) pots[4] = true;
        ///3///CHEOCHINH
        if (chess[y+i][x+i] == chess[y][x] && !pots[5]) ++tnuoc[3];
        else if (chess[y+i][x+i] != chess[y][x]) pots[5] = true;
        if (chess[y-i][x-i] == chess[y][x] && !pots[6]) ++tnuoc[3];
        else if (chess[y-i][x-i] != chess[y][x]) pots[6] = true;
        ///4///CHEOPHU
        if (chess[y-i][x+i] == chess[y][x] && !pots[7]) ++tnuoc[4];
        else if (chess[y-i][x+i] != chess[y][x]) pots[7] = true;
        if (chess[y+i][x-i] == chess[y][x] && !pots[8]) ++tnuoc[4];
        else if (chess[y+i][x-i] != chess[y][x]) pots[8] = true;

        ++i;
    }
    fto(i, 1, 4) if (tnuoc[i] == n/2) return chess[y][x];
    return 0;
}

void DrawN_1(int n, int y, int x, int turn, int board[201][201], int check[201][201], int point[201][201]) {
    if (checkN_1W(n, y, x, board, turn) == 1) {
        system("cls");
        gotoxy(0, 0);

        while (true) {
            textcolor(9);

            cout << "                                                                    00\n";
            cout << "   1111111       11111      11111111111             111      01     001    110001         11111       0000\n";
            cout << "     00011     0001 1000 10011001    00         0011001    100      00   0011 10001    0001 000     101\n";
            cout << "     00      000      0110   100               00  001    1000     10  100      1001  00    0001    01\n";
            cout << "    100     000       000    001   1          00  100    00000    101 100        000  01   00100   00\n";
            cout << "    001    000         00   10011100          001 000   00 101   10   001        000  00   01 001  01\n";
            cout << "   100     001         100  000   11              000  00  001  00   000         000      10  100 10\n";
            cout << "   001    000               00                    000 00   00  00    000        100       00   00001\n";
            cout << "  100     000              001      101           10001    00001      000      100       10     000\n";
            cout << "11000     1001      01   10000000111001           100      000        10001  1001   1   101     100\n";
            cout << "1111111    1001   100   1111111110111              0       01            100011    1000001       01\n";
            cout << "             1000001                                                                  \n";

            textcolor(15);
            DrawBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame2N(n, turn, board, x, y);
            }
        }
    }
    if (checkN_1W(n, y, x, board, turn) == -1) {
        system("cls");
        gotoxy(0, 0);
        while (true) {
            textcolor(12);

            cout << "                                                                                     000\n";
            cout << "     11111111100   1100001    11110001      1111001010001          111001     00      00   10000001       111100       00001\n";
            cout << "   001 000    00    000     000111  1000  1001 000    10         001 000     001     10   001   10001   001  1001     00\n";
            cout << " 101   00     1     001   100  100   100 10    00               00  000    1000     101 100       000  00    0000    00\n";
            cout << " 01   000   0      100    01   001  1001 01   100   01         101  00    10100    101  00        1001 00    0 001  10\n";
            cout << "101   0001100      001   10    0011001  100   00011001          00  00   00  00   101  000        1001 101  00 100  00\n";
            cout << " 00  100   11      00     00  000100     00  100    1               00  00  100  00    001        000       01  001 0\n";
            cout << "     001          000      01 00  00         001                    00 00   100 00     000        00       00    0000\n";
            cout << "    100           00         000  100       100       00            0001    10001      0001     100        01    1001\n";
            cout << "  1000011      0000011     100001  000    11000000001001            001     000         1000011001   10   00      00\n";
            cout << "                                    001   101     111               0       00             1111      100001        0\n";
            cout << "                                     10011001\n";
            cout << "                                       1111\n";

            textcolor(15);
            DrawBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame2N(n, turn, board, x, y);
            }
        }
    }

    if (checkN_1W(n, y, x, board, turn) == 0) {
        bool ok = false;
        fto(i, 1, n) fto(j, 1, n) if (board[i][j] == 0) ok = true;
        if (ok == true) return;
        else {
            while (true) {
                system("cls");
                textcolor(10);

                cout << "                                                     111       000\n";
                cout << "       1000011                0000011               1000       10000               11\n";
                cout << "        0000000001          1000000000001         0000000      00000       001    000\n";
                cout << "           1000000001       0001 1000000001       000000001    00000      00001   000\n";
                cout << "           000100000001     001       000001     0000000000    00000      0000    001\n";
                cout << "          0000   1000001    00000      10000    10000 10000    00000     00000   100\n";
                cout << "         10001     10000    10000      0000     0000   0000   100000     00001   000\n";
                cout << "         0000       10001   10001   100001     0000    1000    00000    10000   0001\n";
                cout << "         0000        0001   0000 100001        0001    1000     0000    00000   000\n";
                cout << "         0001        000    00000001          0001     00001    0000   100000  0001\n";
                cout << "        1000        0001  1000000           1000000000000001    0000   000000  000\n";
                cout << "        1000       0001   10000000         00000000001 1000     1000  0000000 000\n";
                cout << "        0001      0001      00000000       000001      1000      0001100 10000000\n";
                cout << "        000      000   00   000 0000001     000        1001      0000001 1000000\n";
                cout << "        000    0000000000  1001   0000001  1000        100       100000   00000\n";
                cout << "        00  100000111      000      1000001000         000        0000    1011\n";
                cout << "         10000001          100        11000001         000        111\n";
                cout << "         10111                            000\n";

                textcolor(15);
                DrawBoard(n, board);

                printf("\nPress X to save game\n");
                printf("Press ESC to back to menu\n");
                int a = getch();
                if (a == 27) {
                    system("cls");
                    MainMenu(n, turn, board, check, point);
                }
                if (char(a) == 'X' || char(a) == 'x') {
                    printf("Save game successfully\n");
                    Sleep(1000);
                    savegame2N(n, turn, board, x, y);
                }
            }
        }
    }
}

void N_1PvP(int n, int chess[201][201], int turn, int toado_x, int toado_y, int check[201][201], int point[201][201]) {
    int S = 0;
    int x = toado_x;
    int y = toado_y;
    while (true) {
        if (turn == 1) {
            gotoxy(0, 2*n + 2);
            cout << "            ";
            gotoxy(0, 2*n + 2);
            textcolor(9);
            cout << "BLUE TURN.";
            textcolor(15);
        }

        if (turn == -1) {
            gotoxy(0, 2*n + 2);
            cout << "            ";
            gotoxy(0, 2*n + 2);
            textcolor(12);
            cout << "RED TURN.";
            textcolor(15);
        }

        if (S == 0) {
            gotoxy(0, 2 * n + 3);
            cout << "Press X to save game.\n";
            cout << "Press U to undo.\n";
            cout << "Press ESC to back to menu.\n";
            S = 1;
        }

        gotoxy(x, y);

        int a = getch();
        switch (a) {
        case 72: //UP
            y -= 2;
            gotoxy(x, y);
            break;
        case 75: //LEFT
            x -= 4;
            gotoxy(x, y);
            break;
        case 77: //RIGHT
            x += 4;
            gotoxy(x, y);
            break;
        case 80: //DOWN
            y += 2;
            gotoxy(x, y);
            break;
        case 119: // W
            y -= 2;
            gotoxy(x, y);
            break;
        case 97: // A
            x -= 4;
            gotoxy(x, y);
            break;
        case 100: // D
            x += 4;
            gotoxy(x, y);
            break;
        case 115: // S
            y += 2;
            gotoxy(x, y);
            break;
        case 27: // ESC BACK TO MENU
            system("cls");
            MainMenu(n, turn, chess, check, point);
            break;
        }

        int X = (x - 2)/4 + 1;
        int Y = y/2;

        if (char(a) == 'X' || char(a) == 'x') {
            savegame2N(n, turn, chess, x, y);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(22, 2 * n + 3);
            cout << "Save game successfully";
            fto(i, 1, 3) {
                Sleep(200);
                cout << ".";
            } Sleep(200);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(x, y);
        }

        if (char(a) == 'U' || char(a) == 'u') {
            if (!undoX.empty()) {
                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(17, 2 * n + 4);
                cout << "U"; Sleep(50);
                cout << "N"; Sleep(50);
                cout << "D"; Sleep(50);
                cout << "O"; Sleep(50);
                cout << "E"; Sleep(50);
                cout << "D"; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(50);

                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(x, y);

                Undo(chess, 0);
                turn = -turn;
            }
        }

        if (a == 13 && chess[Y][X] == 0 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            cout << char((167 - turn*9)/2);
            textcolor(15);
            turn = -turn;
            DrawN_1(n, Y, X, turn, chess, check, point);
        }

        if (a == 32 && chess[Y][X] == 0 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            cout << char((167 - turn*9)/2);
            textcolor(15);
            turn = -turn;
            DrawN_1(n, Y, X, turn, chess, check, point);
        }
    }
}
///PvPvP__________________________________________________________________
void savegame3P(int n, int turn, int board[201][201], int toado_x, int toado_y) {
    FILE *FileSave;
    FileSave = fopen("gamemode7.txt", "w");
    fprintf(FileSave, "%d %d\n", n, turn);
    fprintf(FileSave, "%d %d\n", toado_x, toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            fprintf(FileSave, "%d ", board[i][j]);
        }
        printf("\n");
    }
    fclose(FileSave);
}

void Loadgame3P(int &n, int &turn, int loadboard[201][201], int &toado_x, int &toado_y) {

    FILE *FileLoad;
    FileLoad = fopen("gamemode7.txt", "r");
    fscanf(FileLoad, "%d%d", &n, &turn);
    fscanf(FileLoad, "%d%d", &toado_x, &toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            int x;
            fscanf(FileLoad, "%d", &x);
            loadboard[i][j] = x;
        }
    }
    fclose(FileLoad);
}

int checkFive2Win3P(int y, int x, int chess[201][201]) {
    bool pots[10];
    int tnuoc[10];

    for (int i = 1; i <= 8; ++i) {
        pots[i] = false;
        tnuoc[i] = 1;
    }
    int i = 1;
    while (i < 5) {
        ///1///DOC
        if (chess[y][x] == chess[y+i][x] && !pots[1]) ++tnuoc[1];
        else if (chess[y][x] != chess[y+i][x]) pots[1] = true;
        if (chess[y][x] == chess[y-i][x] && !pots[2]) ++tnuoc[1];
        else if (chess[y][x] != chess[y-i][x]) pots[2] = true;
        ///2///NGANG
        if (chess[y][x] == chess[y][x+i] && !pots[3]) ++tnuoc[2];
        else if (chess[y][x] != chess[y][x+i]) pots[3] = true;
        if (chess[y][x] == chess[y][x-i] && !pots[4]) ++tnuoc[2];
        else if (chess[y][x] != chess[y][x-i]) pots[4] = true;
        ///3///CHEOCHINH
        if (chess[y][x] == chess[y+i][x+i] && !pots[5]) ++tnuoc[3];
        else if (chess[y][x] != chess[y+i][x+i]) pots[5] = true;
        if (chess[y][x] == chess[y-i][x-i] && !pots[6]) ++tnuoc[3];
        else if (chess[y][x] != chess[y-i][x-i]) pots[6] = true;
        ///4///CHEOPHU
        if (chess[y][x] == chess[y+i][x-i] && !pots[7]) ++tnuoc[4];
        else if (chess[y][x] != chess[y+i][x-i]) pots[7] = true;
        if (chess[y][x] == chess[y-i][x+i] && !pots[8]) ++tnuoc[4];
        else if (chess[y][x] != chess[y-i][x+i]) pots[8] = true;

        ++i;
    }
    fto(i, 1, 4) if (tnuoc[i] == 5) return chess[y][x];
    return -1;
}

void DrawPvPvP(int y, int x, int turn, int board[201][201], int n, int check[201][201], int point[201][201]) {
    if (checkFive2Win3P(y, x, board) == 1) {
        system("cls");
        gotoxy(0, 0);

        while (true) {
            textcolor(9);

            cout << "  0\n";
            cout << " 000              000\n";
            cout << " 000              000\n";
            cout << " 000              000\n";
            cout << " 000              000\n";
            cout << "  00      0000    000     00     000        000000             000        000    0        0        000\n";
            cout << "  00    0000000   00     000     000      000   000           00000      0000   000     0000       000    0000\n";
            cout << "  00   000   00   00     00     0000     000  0000               000     000     00    000 0000    000   00 000\n";
            cout << "  00 000    000   00    000    00000    00000000                 000    0000     00   000    000    00  00  000\n";
            cout << "  00000    000    00    00    000 00    00         0              00   00 000    00   00      000   00  00  000\n";
            cout << "  0000    000     00    00   000  00   000        00              000 000  00   00   000       00   00000   000\n";
            cout << "  000   0000      00    00  000   00   000       00                00 00   000  00   000      000   0000    000\n";
            cout << "  000 0000        000   00 000    00    000   0000                 0000     00000    000    0000    0000    000\n";
            cout << "   00000          000   0000      000    00000000                  0000     0000      00000000       00     000\n";
            cout << "                                                                    00                                      00\n";

            textcolor(15);
            Draw3PBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame3P(n, turn, board, x, y);
            }
        }
    }
    if (checkFive2Win3P(y, x, board) == 0) {
        system("cls");
        gotoxy(0, 0);
        while (true) {
            textcolor(14);

            cout << "                              000    00\n";
            cout << "                              000   000\n";
            cout << "                              00    000\n";
            cout << "                              00    000\n";
            cout << "          0        000000     00    000                000         00                  00         000                      00\n";
            cout << "00       000     0000  000    00    000     0000      00000       000   000           0000       0000   000     000        000    0000\n";
            cout << "000      000    000  0000     00    000    0000000      000      000     00             000     0000    000    0000000     000   00 00\n";
            cout << "000      000   00000000       00    000   000   0000     000    0000     00              000    0000    000   000   0000   000  00  00\n";
            cout << " 00     000    0000       0   00    000   000     000     00   000000    00              000   00 00    00   000      000  000 00   00\n";
            cout << " 000   0000   000        00   00    00   000       000    000 000  00   00                00  000 000   00   000       00   00 00   00\n";
            cout << "  000000000   000       00   000    00   000      000     000 00   00   00                000 00   00  000   00       000   0000    00\n";
            cout << "   0000 000   0000    000    000    000  000     000       00000   000 00                 00000    000 00    000    0000    000     00\n";
            cout << "        000    000000000      000   000   000000000        0000     0000                   0000     0000      00000000      000    000\n";
            cout << "        00         0                         00            000                             000                  000                 00\n";
            cout << "        00\n";
            cout << "        000\n";
            cout << "        000\n";

            textcolor(15);
            Draw3PBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame3P(n, turn, board, x, y);
            }
        }
    }

    if (checkFive2Win3P(y, x, board) == 2) {
        system("cls");
        gotoxy(0, 0);
        while (true) {
            system("cls");
            textcolor(12);

            cout << "                                     00\n";
            cout << "                                     00\n";
            cout << "                                     00\n";
            cout << "                                     00\n";
            cout << "                                     00\n";
            cout << "00    00000      000000          000000            000         00    0                  00\n";
            cout << "00  0000000    0000  000       000 0000           00000       000   000     0000       000    0000\n";
            cout << "00 000        000  0000       000   000              000     000     00    000 0000     00   00 000\n";
            cout << "0000         00000000        00    0000              000    00000    00   000    000    00  000 000\n";
            cout << "0000         000        0   00     0000               000  000 00    00   000     000   00  00  000\n";
            cout << "000         000        00  000    00 00               000 000  00   00    00       000  00000   000\n";
            cout << "00          000       00   00    00  00                00 00   000  00   000      000   0000    000\n";
            cout << "000          000    000    00  000   000               00000    00000    000    0000    0000    000\n";
            cout << "000           00000000     000000    000               0000     0000      00000000       00     000\n";
            cout << " 0                                                      00                                      000\n";

            textcolor(15);
            Draw3PBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame3P(n, turn, board, x, y);
            }
        }
    }


    if (checkFive2Win3P(y, x, board) == -1) {
        bool ok = false;
        fto(i, 1, n) fto(j, 1, n) if (board[i][j] == -1) ok = true;
        if (ok == true) return;
        else {
            while (true) {
                system("cls");
                textcolor(10);

                cout << "                                                     000       000\n";
                cout << "       0000000                0000000               0000       00000               00\n";
                cout << "        0000000000          0000000000000         0000000      00000       000    000\n";
                cout << "           0000000000       0000 0000000000       000000000    00000      00000   000\n";
                cout << "           000000000000     000       000000     0000000000    00000      0000    000\n";
                cout << "          0000   0000000    00000      00000    00000 00000    00000     00000   000\n";
                cout << "         00000     00000    00000      0000     0000   0000   000000     00000   000\n";
                cout << "         0000       00000   00000   000000     0000    0000    00000    00000   0000\n";
                cout << "         0000        0000   0000 000000        0000    0000     0000    00000   000\n";
                cout << "         0000        000    00000000          0000     00000    0000   000000  0000\n";
                cout << "        0000        0000  0000000           0000000000000000    0000   000000  000\n";
                cout << "        0000       0000   00000000         00000000000 0000     0000  0000000 000\n";
                cout << "        0000      0000      00000000       000000      0000      0000000 00000000\n";
                cout << "        000      000   00   000 0000000     000        0000      0000000 0000000\n";
                cout << "        000    0000000000  0000   0000000  0000        000       000000   00000\n";
                cout << "        00  000000000      000      0000000000         000        0000    0000\n";
                cout << "         00000000          000        00000000         000        000\n";
                cout << "         00000                            000\n";

                textcolor(15);
                Draw3PBoard(n, board);

                printf("\nPress X to save game\n");
                printf("Press ESC to back to menu\n");
                int a = getch();
                if (a == 27) {
                    system("cls");
                    MainMenu(n, turn, board, check, point);
                }
                if (char(a) == 'X' || char(a) == 'x') {
                    printf("Save game successfully\n");
                    Sleep(1000);
                    savegame3P(n, turn, board, x, y);
                }
            }
        }
    }
}

void Five2WinPvPvP(int n, int chess[201][201], int turn, int toado_x, int toado_y, int check[201][201], int point[201][201]) {
    int S = 0, cntUndo = 0;
    int x = toado_x;
    int y = toado_y;
    while (true) {
        if ((turn+3)%3 == 1) {
            gotoxy(0, 2*n + 2);
            cout << "                 ";
            gotoxy(0, 2*n + 2);
            textcolor(9);
            cout << "BLUE TURN.";
            textcolor(15);
        }
        if ((turn+3)%3 == 2) {
            gotoxy(0, 2*n + 2);
            cout << "                 ";
            gotoxy(0, 2*n + 2);
            textcolor(12);
            cout << "RED TURN.";
            textcolor(15);
        }
        if ((turn+3)%3 == 0) {
            gotoxy(0, 2*n + 2);
            cout << "                 ";
            gotoxy(0, 2*n + 2);
            textcolor(14);
            cout << "YELLOW TURN.";
            textcolor(15);
        }

        if (S == 0) {
            gotoxy(0, 2 * n + 3);
            cout << "Press X to save game.\n";
            cout << "Press U to undo.\n";
            cout << "Press ESC to back to menu.\n";
            S = 1;
        }

        gotoxy(x, y);

        int a = getch();
        switch (a) {
        case 72: //UP
            y -= 2;
            gotoxy(x, y);
            break;
        case 75: //LEFT
            x -= 4;
            gotoxy(x, y);
            break;
        case 77: //RIGHT
            x += 4;
            gotoxy(x, y);
            break;
        case 80: //DOWN
            y += 2;
            gotoxy(x, y);
            break;
        case 119: // W
            y -= 2;
            gotoxy(x, y);
            break;
        case 97: // A
            x -= 4;
            gotoxy(x, y);
            break;
        case 100: // D
            x += 4;
            gotoxy(x, y);
            break;
        case 115: // S
            y += 2;
            gotoxy(x, y);
            break;
        case 27: // ESC BACK TO MENU
            system("cls");
            MainMenu(n, turn, chess, check, point);
            break;
        }

        int X = (x - 2)/4 + 1;
        int Y = y/2;

        if (char(a) == 'X' || char(a) == 'x') {
            savegame3P(n, turn, chess, x, y);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(22, 2 * n + 3);
            cout << "Save game successfully";
            fto(i, 1, 3) {
                Sleep(200);
                cout << ".";
            } Sleep(200);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(x, y);
        }

        if (char(a) == 'U' || char(a) == 'u') {
            if (!undoX.empty()) {
                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(17, 2 * n + 4);
                cout << "U"; Sleep(50);
                cout << "N"; Sleep(50);
                cout << "D"; Sleep(50);
                cout << "O"; Sleep(50);
                cout << "E"; Sleep(50);
                cout << "D"; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(50);

                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(x, y);

                Undo(chess, -1);
                turn = (turn + 5) % 3;
            }
        }

        if (a == 13 && chess[Y][X] == -1 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            turn = (turn + 3) % 3;
            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            if (turn == 1) {
                textcolor(9);
                cout << "X";
                textcolor(12);
            }
            if (turn == 2) {
                textcolor(12);
                cout << "O";
                textcolor(14);
            }
            if (turn == 0) {
                textcolor(14);
                cout << "Y";
                textcolor(9);
            }
            ++turn;
            textcolor(15);
            DrawPvPvP(Y, X, turn, chess, n, check, point);
        }

        if (a == 32 && chess[Y][X] == -1 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            turn = (turn + 3) % 3;
            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            if (turn == 1) {
                textcolor(9);
                cout << "X";
                textcolor(12);
            }
            if (turn == 2) {
                textcolor(12);
                cout << "O";
                textcolor(14);
            }
            if (turn == 0) {
                textcolor(14);
                cout << "Y";
                textcolor(9);
            }
            ++turn;
            textcolor(15);
            DrawPvPvP(Y, X, turn, chess, n, check, point);
        }
    }
}
///PvPvP_2BH______________________________________________________________
void savegame3P2BH(int n, int turn, int board[201][201], int toado_x, int toado_y) {
    FILE *FileSave;
    FileSave = fopen("gamemode8.txt", "w");
    fprintf(FileSave, "%d %d\n", n, turn);
    fprintf(FileSave, "%d %d\n", toado_x, toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            fprintf(FileSave, "%d ", board[i][j]);
        }
        printf("\n");
    }
    fclose(FileSave);
}

void Loadgame3P2BH(int &n, int &turn, int loadboard[201][201], int &toado_x, int &toado_y) {

    FILE *FileLoad;
    FileLoad = fopen("gamemode8.txt", "r");
    fscanf(FileLoad, "%d%d", &n, &turn);
    fscanf(FileLoad, "%d%d", &toado_x, &toado_y);
    fto(i, 1, n) {
        fto(j, 1, n) {
            int x;
            fscanf(FileLoad, "%d", &x);
            loadboard[i][j] = x;
        }
    }
    fclose(FileLoad);
}

int checkFive2Win3P2BH(int y, int x, int chess[201][201]) {
    bool pots[10], kcolb[10];
    int tnuoc[10];

    for (int i = 1; i <= 8; ++i) {
        pots[i] = false;
        kcolb[i] = false;
        tnuoc[i] = 1;
    }
    int i = 1;
    while (i < 5) {
        ///1///DOC
        if (chess[y][x] == chess[y+i][x] && !pots[1]) ++tnuoc[1];
        else if (chess[y][x] != chess[y+i][x]) {
                if (chess[y+i][x] != -1) kcolb[1] = true;
                pots[1] = true;
        }
        if (chess[y][x] == chess[y-i][x] && !pots[2]) ++tnuoc[1];
        else if (chess[y][x] != chess[y-i][x]) {
                if (chess[y-i][x] != -1) kcolb[2] = true;
                pots[2] = true;
        }
        ///2///NGANG
        if (chess[y][x] == chess[y][x+i] && !pots[3]) ++tnuoc[2];
        else if (chess[y][x] != chess[y][x+i]) {
                if (chess[y][x+i] != -1) kcolb[3] = true;
                pots[3] = true;
        }
        if (chess[y][x] == chess[y][x-i] && !pots[4]) ++tnuoc[2];
        else if (chess[y][x] != chess[y][x-i]) {
                if (chess[y][x-i] != -1) kcolb[4] = true;
                pots[4] = true;
        }
        ///3///CHEOCHINH
        if (chess[y][x] == chess[y+i][x+i] && !pots[5]) ++tnuoc[3];
        else if (chess[y][x] != chess[y+i][x+i]) {
                if (chess[y+i][x+i] != -1) kcolb[5] = true;
                pots[5] = true;
        }
        if (chess[y][x] == chess[y-i][x-i] && !pots[6]) ++tnuoc[3];
        else if (chess[y][x] != chess[y-i][x-i]) {
                if (chess[y-i][x-i] != -1) kcolb[6] = true;
                pots[6] = true;
        }
        ///4///CHEOPHU
        if (chess[y][x] == chess[y+i][x-i] && !pots[7]) ++tnuoc[4];
        else if (chess[y][x] != chess[y+i][x-i]) {
                if (chess[y+i][x-i] != -1) kcolb[7] = true;
                pots[7] = true;
        }
        if (chess[y][x] == chess[y-i][x+i] && !pots[8]) ++tnuoc[4];
        else if (chess[y][x] != chess[y-i][x+i]) {
                if (chess[y-i][x+i] != -1) kcolb[8] = true;
                pots[8] = true;
        }

        ++i;
    }
    fto(i, 1, 4) if (tnuoc[i] == 5 && !kcolb[2*i-1] && !kcolb[2*i]) return chess[y][x];
    return -1;
}

void DrawPvPvP2BH(int y, int x, int turn, int board[201][201], int n, int check[201][201], int point[201][201]) {
    if (checkFive2Win3P2BH(y, x, board) == 1) {
        system("cls");
        gotoxy(0, 0);

        while (true) {
            textcolor(9);

            cout << "  0\n";
            cout << " 000              000\n";
            cout << " 000              000\n";
            cout << " 000              000\n";
            cout << " 000              000\n";
            cout << "  00      0000    000     00     000        000000             000        000    0        0        000\n";
            cout << "  00    0000000   00     000     000      000   000           00000      0000   000     0000       000    0000\n";
            cout << "  00   000   00   00     00     0000     000  0000               000     000     00    000 0000    000   00 000\n";
            cout << "  00 000    000   00    000    00000    00000000                 000    0000     00   000    000    00  00  000\n";
            cout << "  00000    000    00    00    000 00    00         0              00   00 000    00   00      000   00  00  000\n";
            cout << "  0000    000     00    00   000  00   000        00              000 000  00   00   000       00   00000   000\n";
            cout << "  000   0000      00    00  000   00   000       00                00 00   000  00   000      000   0000    000\n";
            cout << "  000 0000        000   00 000    00    000   0000                 0000     00000    000    0000    0000    000\n";
            cout << "   00000          000   0000      000    00000000                  0000     0000      00000000       00     000\n";
            cout << "                                                                    00                                      00\n";

            textcolor(15);
            Draw3PBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame3P2BH(n, turn, board, x, y);
            }
        }
    }
    if (checkFive2Win3P2BH(y, x, board) == 0) {
        system("cls");
        gotoxy(0, 0);
        while (true) {
            textcolor(14);

            cout << "                              000    00\n";
            cout << "                              000   000\n";
            cout << "                              00    000\n";
            cout << "                              00    000\n";
            cout << "          0        000000     00    000                000         00                  00         000                      00\n";
            cout << "00       000     0000  000    00    000     0000      00000       000   000           0000       0000   000     000        000    0000\n";
            cout << "000      000    000  0000     00    000    0000000      000      000     00             000     0000    000    0000000     000   00 00\n";
            cout << "000      000   00000000       00    000   000   0000     000    0000     00              000    0000    000   000   0000   000  00  00\n";
            cout << " 00     000    0000       0   00    000   000     000     00   000000    00              000   00 00    00   000      000  000 00   00\n";
            cout << " 000   0000   000        00   00    00   000       000    000 000  00   00                00  000 000   00   000       00   00 00   00\n";
            cout << "  000000000   000       00   000    00   000      000     000 00   00   00                000 00   00  000   00       000   0000    00\n";
            cout << "   0000 000   0000    000    000    000  000     000       00000   000 00                 00000    000 00    000    0000    000     00\n";
            cout << "        000    000000000      000   000   000000000        0000     0000                   0000     0000      00000000      000    000\n";
            cout << "        00         0                         00            000                             000                  000                 00\n";
            cout << "        00\n";
            cout << "        000\n";
            cout << "        000\n";

            textcolor(15);
            Draw3PBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame3P2BH(n, turn, board, x, y);
            }
        }
    }

    if (checkFive2Win3P2BH(y, x, board) == 2) {
        system("cls");
        gotoxy(0, 0);
        while (true) {
            system("cls");
            textcolor(12);

            cout << "                                     00\n";
            cout << "                                     00\n";
            cout << "                                     00\n";
            cout << "                                     00\n";
            cout << "                                     00\n";
            cout << "00    00000      000000          000000            000         00    0                  00\n";
            cout << "00  0000000    0000  000       000 0000           00000       000   000     0000       000    0000\n";
            cout << "00 000        000  0000       000   000              000     000     00    000 0000     00   00 000\n";
            cout << "0000         00000000        00    0000              000    00000    00   000    000    00  000 000\n";
            cout << "0000         000        0   00     0000               000  000 00    00   000     000   00  00  000\n";
            cout << "000         000        00  000    00 00               000 000  00   00    00       000  00000   000\n";
            cout << "00          000       00   00    00  00                00 00   000  00   000      000   0000    000\n";
            cout << "000          000    000    00  000   000               00000    00000    000    0000    0000    000\n";
            cout << "000           00000000     000000    000               0000     0000      00000000       00     000\n";
            cout << " 0                                                      00                                      000\n";

            textcolor(15);
            Draw3PBoard(n, board);

            printf("\nPress X to save game\n");
            printf("Press ESC to back to menu\n");
            int a = getch();
            if (a == 27) {
                system("cls");
                MainMenu(n, turn, board, check, point);
            }
            if (char(a) == 'X' || char(a) == 'x') {
                printf("Save game successfully\n");
                Sleep(1000);
                savegame3P2BH(n, turn, board, x, y);
            }
        }
    }


    if (checkFive2Win3P2BH(y, x, board) == -1) {
        bool ok = false;
        fto(i, 1, n) fto(j, 1, n) if (board[i][j] == -1) ok = true;
        if (ok == true) return;
        else {
            while (true) {
                system("cls");
                textcolor(10);

                cout << "                                                     000       000\n";
                cout << "       0000000                0000000               0000       00000               00\n";
                cout << "        0000000000          0000000000000         0000000      00000       000    000\n";
                cout << "           0000000000       0000 0000000000       000000000    00000      00000   000\n";
                cout << "           000000000000     000       000000     0000000000    00000      0000    000\n";
                cout << "          0000   0000000    00000      00000    00000 00000    00000     00000   000\n";
                cout << "         00000     00000    00000      0000     0000   0000   000000     00000   000\n";
                cout << "         0000       00000   00000   000000     0000    0000    00000    00000   0000\n";
                cout << "         0000        0000   0000 000000        0000    0000     0000    00000   000\n";
                cout << "         0000        000    00000000          0000     00000    0000   000000  0000\n";
                cout << "        0000        0000  0000000           0000000000000000    0000   000000  000\n";
                cout << "        0000       0000   00000000         00000000000 0000     0000  0000000 000\n";
                cout << "        0000      0000      00000000       000000      0000      0000000 00000000\n";
                cout << "        000      000   00   000 0000000     000        0000      0000000 0000000\n";
                cout << "        000    0000000000  0000   0000000  0000        000       000000   00000\n";
                cout << "        00  000000000      000      0000000000         000        0000    0000\n";
                cout << "         00000000          000        00000000         000        000\n";
                cout << "         00000                            000\n";

                textcolor(15);
                Draw3PBoard(n, board);

                printf("\nPress X to save game\n");
                printf("Press ESC to back to menu\n");
                int a = getch();
                if (a == 27) {
                    system("cls");
                    MainMenu(n, turn, board, check, point);
                }
                if (char(a) == 'X' || char(a) == 'x') {
                    printf("Save game successfully\n");
                    Sleep(1000);
                    savegame3P2BH(n, turn, board, x, y);
                }
            }
        }
    }
}

void Five2WinPvPvP2BH(int n, int chess[201][201], int turn, int toado_x, int toado_y, int check[201][201], int point[201][201]) {
    int S = 0, cntUndo = 0;
    int x = toado_x;
    int y = toado_y;
    while (true) {
        if ((turn+3)%3 == 1) {
            gotoxy(0, 2*n + 2);
            cout << "                 ";
            gotoxy(0, 2*n + 2);
            textcolor(9);
            cout << "BLUE TURN.";
            textcolor(15);
        }
        if ((turn+3)%3 == 2) {
            gotoxy(0, 2*n + 2);
            cout << "                 ";
            gotoxy(0, 2*n + 2);
            textcolor(12);
            cout << "RED TURN.";
            textcolor(15);
        }
        if ((turn+3)%3 == 0) {
            gotoxy(0, 2*n + 2);
            cout << "                 ";
            gotoxy(0, 2*n + 2);
            textcolor(14);
            cout << "YELLOW TURN.";
            textcolor(15);
        }

        if (S == 0) {
            gotoxy(0, 2 * n + 3);
            cout << "Press X to save game.\n";
            cout << "Press U to undo.\n";
            cout << "Press ESC to back to menu.\n";
            S = 1;
        }

        gotoxy(x, y);

        int a = getch();
        switch (a) {
        case 72: //UP
            y -= 2;
            gotoxy(x, y);
            break;
        case 75: //LEFT
            x -= 4;
            gotoxy(x, y);
            break;
        case 77: //RIGHT
            x += 4;
            gotoxy(x, y);
            break;
        case 80: //DOWN
            y += 2;
            gotoxy(x, y);
            break;
        case 119: // W
            y -= 2;
            gotoxy(x, y);
            break;
        case 97: // A
            x -= 4;
            gotoxy(x, y);
            break;
        case 100: // D
            x += 4;
            gotoxy(x, y);
            break;
        case 115: // S
            y += 2;
            gotoxy(x, y);
            break;
        case 27: // ESC BACK TO MENU
            system("cls");
            MainMenu(n, turn, chess, check, point);
            break;
        }

        int X = (x - 2)/4 + 1;
        int Y = y/2;

        if (char(a) == 'X' || char(a) == 'x') {
            savegame3P2BH(n, turn, chess, x, y);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(22, 2 * n + 3);
            cout << "Save game successfully";
            fto(i, 1, 3) {
                Sleep(200);
                cout << ".";
            } Sleep(200);
            gotoxy(22, 2 * n + 3);
            fto(i, 1, 50) cout << " ";
            gotoxy(x, y);
        }

        if (char(a) == 'U' || char(a) == 'u') {
            if (!undoX.empty()) {
                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(17, 2 * n + 4);
                cout << "U"; Sleep(50);
                cout << "N"; Sleep(50);
                cout << "D"; Sleep(50);
                cout << "O"; Sleep(50);
                cout << "E"; Sleep(50);
                cout << "D"; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(100);
                cout << "."; Sleep(50);

                gotoxy(17, 2 * n + 4);
                fto(i, 1, 50) cout << " ";
                gotoxy(x, y);

                Undo(chess, -1);
                turn = (turn + 5) % 3;
            }
        }

        if (a == 13 && chess[Y][X] == -1 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            turn = (turn + 3) % 3;
            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            if (turn == 1) {
                textcolor(9);
                cout << "X";
                textcolor(12);
            }
            if (turn == 2) {
                textcolor(12);
                cout << "O";
                textcolor(14);
            }
            if (turn == 0) {
                textcolor(14);
                cout << "Y";
                textcolor(9);
            }
            ++turn;
            textcolor(15);
            DrawPvPvP2BH(Y, X, turn, chess, n, check, point);
        }

        if (a == 32 && chess[Y][X] == -1 && Y <= n && X <= n && Y > 0 && X > 0) {
            undoX.pb(X);
            undoY.pb(Y);

            turn = (turn + 3) % 3;
            chess[Y][X] = turn;
            textcolor((21 - turn*3)/2);
            if (turn == 1) {
                textcolor(9);
                cout << "X";
                textcolor(12);
            }
            if (turn == 2) {
                textcolor(12);
                cout << "O";
                textcolor(14);
            }
            if (turn == 0) {
                textcolor(14);
                cout << "Y";
                textcolor(9);
            }
            ++turn;
            textcolor(15);
            DrawPvPvP2BH(Y, X, turn, chess, n, check, point);
        }
    }
}
///_________________________________________________________________________

void LoadGamePvP(int& n, int& turn, int& loadX, int& loadY, int chess[201][201], int check[201][201], int point[201][201]) {
    int choice;
    while (true) {
        cout << "*******************************\n";
        cout << " 1 - TIC TAC TOE.\n";
        cout << " 2 - Five to Win.\n";
        cout << " 3 - Five to Win and Block Two Head.\n";
        cout << " 4 - The first fifth O WIN.\n";
        cout << " 5 - The first fifth O LOSE.\n";
        cout << " 6 - Half of N to Win with N x N.\n";
        cout << " 7 - Player vs Player vs Player.\n";
        cout << " 8 - Player vs Player vs Player, but Block Two Head.\n";
        cout << " Enter your choice and press return: ";

        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
		    cout << "WELCOME BACK\n";
		    Loadgame3T(n, turn, chess, loadX, loadY);
		    DrawBoard(n, chess);
            T2TPvP(n, chess, turn, loadX, loadY, check, point);
            break;
        case 2:
            system("cls");
		    cout << "WELCOME BACK\n";
		    Loadgame52W(n, turn, chess, loadX, loadY);
		    DrawBoard(n, chess);
            Five2WinPvP(n, chess, turn, loadX, loadY, check, point);
            break;
        case 3:
            system("cls");
		    cout << "WELCOME BACK\n";
		    Loadgame2BH(n, turn, chess, loadX, loadY);
		    DrawBoard(n, chess);
            FivePvP(n, chess, turn, loadX, loadY, check, point);
            break;
        case 4:
            system("cls");
		    cout << "WELCOME BACK\n";
		    Loadgame1st5(n, turn, chess, loadX, loadY);
		    Draw1st5Board(n, chess);
            Fst5thOPvP(n, chess, turn, loadX, loadY, check, point);
            break;
        case 5:
            system("cls");
		    cout << "WELCOME BACK\n";
		    Loadgame1st5L(n, turn, chess, loadX, loadY);
		    Draw1st5Board(n, chess);
            Fst5thOLPvP(n, chess, turn, loadX, loadY, check, point);
            break;
        case 6:
            system("cls");
		    cout << "WELCOME BACK\n";
		    Loadgame2N(n, turn, chess, loadX, loadY);
		    DrawBoard(n, chess);
            N_1PvP(n, chess, turn, loadX, loadY, check, point);
            break;
        case 7:
            system("cls");
		    cout << "WELCOME BACK\n";
		    Loadgame3P(n, turn, chess, loadX, loadY);
		    Draw3PBoard(n, chess);
            Five2WinPvPvP(n, chess, turn, loadX, loadY, check, point);
            break;
        case 8:
            system("cls");
		    cout << "WELCOME BACK\n";
		    Loadgame3P2BH(n, turn, chess, loadX, loadY);
		    Draw3PBoard(n, chess);
            Five2WinPvPvP(n, chess, turn, loadX, loadY, check, point);
            break;
        }
    }
}

void chooseMode(int& n, int& turn, int chess[201][201], int check[201][201], int point[201][201]) {
    int choice;
    bool gameOn = true;
    while (gameOn != false) {
        cout << "*******************************\n";
        cout << " 1 - TIC TAC TOE.\n";
        cout << " 2 - Five to Win.\n";
        cout << " 3 - Five to Win and Block Two Head.\n";
        cout << " 4 - The first fifth O WIN.\n";
        cout << " 5 - The first fifth O LOSE.\n";
        cout << " 6 - Half of N to Win with N x N.\n";
        cout << " 7 - Player vs Player vs Player.\n";
        cout << " 8 - Player vs Player vs Player, but Block Two Head.\n";
        cout << " Enter your choice and press return: ";

        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            cout << "TIC TAC TOE ";
            cout << "G"; Sleep(50);
            cout << "A"; Sleep(50);
            cout << "M"; Sleep(50);
            cout << "E "; Sleep(50);
            cout << "S"; Sleep(50);
            cout << "T"; Sleep(50);
            cout << "A"; Sleep(50);
            cout << "R"; Sleep(50);
            cout << "T"; Sleep(50);
            cout << "E"; Sleep(50);
            cout << "D\n"; Sleep(50);
            n = 3;
            setup(turn, chess, check, point);
            DrawBoard(n, chess);
            T2TPvP(n, chess, 1, 2, 2, check, point);
            break;
        case 2:
            system("cls");
			cout << "Enter N: ";
            cin >> n;
            setup(turn, chess, check, point);
            DrawBoard(n, chess);
			Five2WinPvP(n, chess, 1, 2, 2, check, point);
            break;
        case 3:
            system("cls");
            cout << "Enter N: ";
            cin >> n;
            setup(turn, chess, check, point);
            DrawBoard(n, chess);
            FivePvP(n, chess, 1, 2, 2, check, point);
            break;
        case 4:
            system("cls");
            cout << "Enter N: ";
            cin >> n;
            setup(turn, chess, check, point);
            DrawBoard(n, chess);
            Fst5thOPvP(n, chess, 1, 2, 2, check, point);
            break;
        case 5:
            system("cls");
            cout << "Enter N: ";
            cin >> n;
            setup(turn, chess, check, point);
            DrawBoard(n, chess);
            Fst5thOLPvP(n, chess, 1, 2, 2, check, point);
            break;
        case 6:
            system("cls");
			cout << "Enter N: ";
            cin >> n;
            setup(turn, chess, check, point);
            DrawBoard(n, chess);
			N_1PvP(n, chess, 1, 2, 2, check, point);
            break;
        case 7:
            system("cls");
			cout << "Enter N: ";
            cin >> n;
            //setup(n, chess, check, point);
            fto(i, 1, n) fto(j, 1, n) chess[i][j] = -1;
            fto(i, 1, n) chess[0][i] = chess[i][0] = -1;
            fto(i, 1, n) chess[i][n+1] = chess[n+1][i] = -1;
            Draw3PBoard(n, chess);
			Five2WinPvPvP(n, chess, 1, (n/2 - 1)*4 + 2, 6, check, point);
            break;
        case 8:
            system("cls");
			cout << "Enter N: ";
            cin >> n;
            //setup(n, chess, check, point);
            fto(i, 1, n) fto(j, 1, n) chess[i][j] = -1;
            fto(i, 1, n) chess[0][i] = chess[i][0] = -1;
            fto(i, 1, n) chess[i][n+1] = chess[n+1][i] = -1;
            Draw3PBoard(n, chess);
			Five2WinPvPvP2BH(n, chess, 1, (n/2 - 1)*4 + 2, 6, check, point);
            break;
        }
    }
}

void MainMenu(int& n, int& turn, int chess[201][201], int check[201][201], int point[201][201]) {

    int choice, x, y;
	bool gameOn = true;
	while (gameOn != false) {
		cout << "*******************************\n";
		cout << " 1 - PvP mode.\n";
		cout << " 2 - PvC mode.\n";
		cout << " 3 - Option.\n";
		cout << " 4 - Load the game PvP.\n";
		cout << " 5 - Quit.\n";
		cout << " Enter your choice and press return: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
		    system("cls");
            chooseMode(n, turn, chess, check, point);
			break;
		case 2:
            system("cls");
            cout << "Enter N: ";
            cin >> n;
            setup(turn, chess, check, point);
            DrawBoard(n, chess);
            Five2WinPvC(n, 1, 2, 2, chess, check, point);
			break;
		case 3:
			break;
		case 4:
            LoadGamePvP(n, turn, x, y, chess, check, point);
			break;
		case 5:
			cout << "Thank you for playing!\n";
			exit(0);
			break;
		default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again: ";
			cin >> choice;
			break;
		}
	}
}

int main() {

    int N, Turn, loadX, loadY, Chess[201][201], Check[201][201], Point[201][201];

    SplashScreen();
    LoadingBar();
    MainMenu(N, Turn, Chess, Check, Point);

    return 0;
}

