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
void Input() {

}
void Logic() {

}
int main() {

    return 0;
}