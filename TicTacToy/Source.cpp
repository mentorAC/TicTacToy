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
void Input() {

}
void Logic() {

}
int main() {

    return 0;
}