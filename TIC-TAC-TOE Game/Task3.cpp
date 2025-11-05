#include <iostream>
using namespace std;

// Function prototypes
void displayBoard(char board[3][3]);
bool makeMove(char board[3][3], int row, int col, char player);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);
void resetBoard(char board[3][3]);

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameOver = false;
    char playAgain;

    do {
        resetBoard(board);
        gameOver = false;
        currentPlayer = 'X';

        cout << "===== TIC-TAC-TOE GAME =====\n";
        displayBoard(board);

        while (!gameOver) {
            int row, col;

            cout << "\nPlayer " << currentPlayer << ", enter your move (row and column: 1-3): ";
            cin >> row >> col;

            // Validate input range
            if (row < 1 || row > 3 || col < 1 || col > 3) {
                cout << "Invalid input! Please enter numbers between 1 and 3.\n";
                continue;
            }

            // Try to make a move
            if (!makeMove(board, row - 1, col - 1, currentPlayer)) {
                cout << "That cell is already taken! Try again.\n";
                continue;
            }

            displayBoard(board);

            // Check for win
            if (checkWin(board, currentPlayer)) {
                cout << "🎉 Player " << currentPlayer << " wins! 🎉\n";
                gameOver = true;
            }
            // Check for draw
            else if (checkDraw(board)) {
                cout << "It's a draw! 😐\n";
                gameOver = true;
            }
            // Switch players
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe! 👋\n";
    return 0;
}

// Function to display the game board
void displayBoard(char board[3][3]) {
    cout << "\nCurrent Board:\n";
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to make a move
bool makeMove(char board[3][3], int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

// Function to check for a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

// Function to reset the board
void resetBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}
