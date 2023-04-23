#include <iostream>
using namespace std;

const int BOARD_SIZE = 8;
const int EMPTY = 0;
const int RED = 1;
const int BLACK = 2;

// Function to initialize the game board
void initBoard(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = EMPTY;
            }
            else if (i < 3) {
                board[i][j] = BLACK;
            }
            else if (i > 4) {
                board[i][j] = RED;
            }
            else {
                board[i][j] = EMPTY;
            }
        }
    }
}
//Update the game boardand display it after each move.
// Function to display the game board
void displayBoard(int board[][BOARD_SIZE]) {
    cout << "  ";
    for (int j = 0; j < BOARD_SIZE; j++) {
        cout << j << " ";
    }
    cout << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                cout << "- ";
            }
            else if (board[i][j] == BLACK) {
                cout << "B ";
            }
            else if (board[i][j] == RED) {
                cout << "R ";
            }
        }
        cout << endl;
    }
}
//Implement code to allow players to input their moves and check if the move is valid.
// Function to check if a move is legal
bool isLegalMove(int board[][BOARD_SIZE], int x1, int y1, int x2, int y2, int player) {
    // Check that the starting position is valid
    if (board[x1][y1] != player) {
        return false;
    }
    // Check that the ending position is empty
    if (board[x2][y2] != EMPTY) {
        return false;
    }
    // Check that the move is diagonal
    if (abs(x2 - x1) != abs(y2 - y1)) {
        return false;
    }
    // Check that the move is within the bounds of the board
    if (x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
        return false;
    }
    // Check that the move is only one or two spaces
    if (abs(x2 - x1) > 2) {
        return false;
    }
    // Check that the move is forward for regular pieces
    if (board[x1][y1] == RED && x2 >= x1) {
        return false;
    }
    if (board[x1][y1] == BLACK && x2 <= x1) {
        return false;
    }
    // Check for a capture
    if (abs(x2 - x1) == 2) {
        int x3 = (x1 + x2) / 2;
        int y3 = (y1 + y2) / 2;
        if (board[x3][y3] == EMPTY || board[x3][y3] == player) {
            return false;
        }
    }
    return true;
}
//Check if a player has won by capturing all of their opponent's pieces or if the game has ended in a draw.
// Function to execute a move and capture
void executeMove(int board[][BOARD_SIZE], int x1, int y1, int x2, int y2, int player) {
    board[x2][y2] = player;
    board[x1][y1] = EMPTY;
    if (abs(x2 - x1) == 2) {
        int x3 = (x1 + x2) / 2;
        int y3 = (y1 + y2) / 2;
        board[x3][y3] = EMPTY;
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer = RED;
    initBoard(board);
    displayBoard(board);

    while (true) {
        // Prompt the current player for their move
        int x1, y1, x2, y2;
        cout << "Player " << currentPlayer << ", enter your move: ";
        cin >> x1 >> y1 >> x2 >> y2;

        // Verify that the move is legal
        if (!isLegalMove(board, x1, y1, x2, y2, currentPlayer)) {
            cout << "Illegal move, try again." << endl;
            continue;
        }

        // Execute the move and capture
        executeMove(board, x1, y1, x2, y2, currentPlayer);

        // Display the updated game board
        displayBoard(board);

        // Check if the game is over
        bool redHasMoves = false;
        bool blackHasMoves = false;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == RED) {
                    if (isLegalMove(board, i, j, i + 1, j + 1, RED) ||
                        isLegalMove(board, i, j, i + 1, j - 1, RED) ||
                        isLegalMove(board, i, j, i - 1, j + 1, RED) ||
                        isLegalMove(board, i, j, i - 1, j - 1, RED)) {
                        redHasMoves = true;
                    }
                }
                if (board[i][j] == BLACK) {
                    if (isLegalMove(board, i, j, i + 1, j - 1, BLACK) ||
                        isLegalMove(board, i, j, i + 1, j + 1, BLACK) ||
                        isLegalMove(board, i, j, i - 1, j - 1, BLACK) ||
                        isLegalMove(board, i, j, i - 1, j + 1, BLACK)) {
                        blackHasMoves = true;
                    }
                }
            }
        }
        if (!redHasMoves) {
            cout << "Black wins!" << endl;
            break;
        }
        if (!blackHasMoves)
        {
            cout << "Red wins!" << endl;
            break;
        }
        //Implement a turn - based system where players take turns making moves.
        // Switch to the other player
        currentPlayer = (currentPlayer == RED) ? BLACK : RED;
    }
   //Determine the valid moves for each player's pieces based on the rules of checkers. This includes mandatory jumps and multi-jump sequences. (saber with a sword - рубка шашкой, a king - дамка) 
    return 0;
}
    









    
