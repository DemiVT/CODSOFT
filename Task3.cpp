/*  
                TASK 3

            TIC-TAC-TOE GAME

A simple console-based Tic-Tac-Toe game that
allows two players to play against each other.
Game Board: Create a 3x3 grid as the game board.
Players: Assign
"X"
and "O" to two players.

Display Board: Show the current state of the board.
Player Input: Prompt the current player to enter their move.
Update Board: Update the game board with the player's move.

Check for Win: Check if the current player has won.
Check for Draw: Determine if the game is a draw.
Switch Players: Alternate turns between "X" and "O" players.

Display Result: Show the result of the game (win, draw, or ongoing).
Play Again: Ask if the players want to play another game.
*/





#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define text colors
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";
const string BLUE = "\033[94m";
const string GREEN = "\033[92m";
const string RED = "\033[91m";
const string YELLOW = "\033[93m";
const string CYAN = "\033[96m";

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    cout << CYAN
         << "\n╔════════════════════════════════════════╗\n"
         << "║ " << BOLD << "    Welcome to Tic-Tac-Toe! ✨" << RESET << "   ║\n"
         << "║                                      ║\n"
         << "║ " << BOLD << "    Get ready for some fun!" << RESET << "         ║\n"
         << "╚════════════════════════════════════════╝\n" << RESET;

    cout << "   1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ' ';
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

// Function to check for a win condition
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

// Function to check for a draw condition
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char player = 'X';
    int row, col;

    // Welcome message
    cout << CYAN
         << "╔════════════════════════════════════════════════════╗\n"
         << "║ " << BOLD << "  Welcome to Tic-Tac-Toe! ✨" << RESET << "             ║\n"
         << "║                                                    ║\n"
         << "║ " << BOLD << "  Player X and Player O take turns to win!" << RESET << " ║\n"
         << "╚════════════════════════════════════════════════════╝\n\n" << RESET;

    while (true) {
        displayBoard(board);
        cout << "Player " << player << ", enter your move (row and column 1-3): ";
        cin >> row >> col;
        row--; col--;  // Convert to 0-based index

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << RED << "Invalid move. Try again.\n" << RESET;
            continue;
        }

        board[row][col] = player;

        if (checkWin(board, player)) {
            displayBoard(board);
            cout << GREEN << "🎉 Player " << player << " wins! 🎉\n" << RESET;
            break;
        }
        if (checkDraw(board)) {
            displayBoard(board);
            cout << YELLOW << "It's a draw! 🌟\n" << RESET;
            break;
        }

        player = (player == 'X') ? 'O' : 'X';  // Switch player
    }

    cout << CYAN
         << "\n╔════════════════════════════════════════════════════╗\n"
         << "║ " << BOLD << "  Thanks for playing! 🎉" << RESET << "                 ║\n"
         << "║ " << BOLD << "  Created with ❤️ by Viraj Tupe" << RESET << "          ║\n"
         << "╚════════════════════════════════════════════════════╝\n" << RESET;

    return 0;
}
