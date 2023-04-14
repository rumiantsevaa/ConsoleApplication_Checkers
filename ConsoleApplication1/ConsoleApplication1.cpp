#include <iostream>

using namespace std;

const int BOARD_SIZE = 8;

void display_board(char board[][BOARD_SIZE]) {
    
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i + 1 << " | ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "  +---+---+---+---+---+---+---+---+" << endl;
    }
    cout << "    A   B   C   D   E   F   G   H  " << endl;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
        {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '},
        {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
        {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '}
    };

    display_board(board);

    return 0;
}