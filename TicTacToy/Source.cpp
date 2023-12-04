#include <iostream>
#include<Windows.h>

#define COLOR_BLACK 0
#define COLOR_RED 4
#define MOVING << 4
#define WHITE_COLOR 7
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER '\r'
#define CROSS 'x'
#define CIRCLE 'o'
#define GREEN_COLOR 2

using namespace std;

void clearField(int size, char field[][3]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            field[i][j] = ' ';
        }
    }
}

void Draw(int size, char field[][3], int y, int x, bool isCross) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "+---+---+---+\n";
    for (int i = 0; i < size; i++) {
        cout << "| ";
        for (int j = 0; j < size; j++) {
            if (i == y && j == x) {
                if (isCross) {
                    SetConsoleTextAttribute(h, (COLOR_RED MOVING) | (WHITE_COLOR));
                }
                else {
                    SetConsoleTextAttribute(h, (GREEN_COLOR MOVING) | (WHITE_COLOR));
                }
            }
            cout << field[i][j];
            SetConsoleTextAttribute(h, (COLOR_BLACK MOVING) | (WHITE_COLOR));
            cout << " | ";
        }
        cout << "\n+---+---+---+\n";
    }
}

bool WhoIsWinner(int size, char field[][3], char ch) {
    int countX = 0, countO = 0;
    int combI[8][3]{
        {0,0,0},
        {1,1,1},
        {2,2,2},
        {0,1,2},
        {0,1,2},
        {0,1,2},
        {0,1,2},
        {0,1,2}
    };
    int combJ[8][3]{
        {0,1,2},
        {0,1,2},
        {0,1,2},
        {0,0,0},
        {1,1,1},
        {2,2,2},
        {0,1,2},
        {2,1,0}

    };

    for (int i = 0; i < 8; i++)
    {
        int count = 0;
        for (int j = 0; j < 3; j++)
        {
            int i_ = combI[i][j];
            int j_ = combJ[i][j];
            if (field[i_][j_] == ch) {
                count++;
            }
        }
        if (count == 3) {
            return true;
        }
    }
    return false;
}
void Input(int& y, int& x, bool& isCross, char field[][3]) {

    char ch = _getwch();
    cout << "\r";

    if (ch == UP && y != 0) {
        y--;
    }
    else if (ch == DOWN && y != 2) {
        y++;
    }
    else if (ch == RIGHT && x != 2) {
        x++;
    }
    else if (ch == LEFT && x != 0) {
        x--;
    }

    else if (ch == ENTER && field[y][x] == ' ') {
        field[y][x] = (isCross ? CROSS : CIRCLE);
        isCross = !isCross;
    }
}

void SetUp(char field[][3], int size) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(h, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(h, &cursorInfo);

    clearField(size, field);
}
bool IsAllBusy(int size, char field[][3]) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (field[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
int main() {
    const int size = 3;
    char field[size][size];

    SetUp(field, size);

    int x = 1, y = 1;
    bool isCross = true;
    while (true) {
        Draw(size, field, y, x, isCross);

        int countX = 0, countO = 0;
        int e = 0;
        if (WhoIsWinner(size, field, CROSS)) {
            cout << "X is winner!";
        }
        else if (WhoIsWinner(size, field, CIRCLE)) {
            cout << "O is winner!";
        }
        else if (IsAllBusy(size, field)) {
            cout << "DRAW!!!";
        }
        Input(y, x, isCross, field);

        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleCursorPosition(h, COORD{0, 0});

    }

    return 0;
}