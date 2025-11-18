#include <bits/stdc++.h>
using namespace std;

const int ROWS = 6;
const int COLS = 7;

const int HUMAN = 1;
const int AI = 2;

// Display board
void printBoard(vector<vector<int>>& board) {
    cout << "\n";
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            char ch = board[r][c] == 0 ? '.' :
                      (board[r][c] == HUMAN ? 'H' : 'A');
            cout << ch << " ";
        }
        cout << "\n";
    }
    cout << "0 1 2 3 4 5 6\n\n";
}

// Check if column is valid
bool canPlay(vector<vector<int>>& board, int col) {
    return col >= 0 && col < COLS && board[0][col] == 0;
}

// Drop piece in column
void makeMove(vector<vector<int>>& board, int col, int player) {
    for(int r = ROWS - 1; r >= 0; r--) {
        if(board[r][col] == 0) {
            board[r][col] = player;
            return;
        }
    }
}

// Undo move
void undoMove(vector<vector<int>>& board, int col) {
    for(int r = 0; r < ROWS; r++) {
        if(board[r][col] != 0) {
            board[r][col] = 0;
            return;
        }
    }
}

// Check win
bool checkWin(vector<vector<int>>& b, int p) {
    // Horizontal
    for(int r = 0; r < ROWS; r++)
        for(int c = 0; c < COLS-3; c++)
            if(b[r][c]==p && b[r][c+1]==p && b[r][c+2]==p && b[r][c+3]==p)
                return true;

    // Vertical
    for(int c = 0; c < COLS; c++)
        for(int r = 0; r < ROWS-3; r++)
            if(b[r][c]==p && b[r+1][c]==p && b[r+2][c]==p && b[r+3][c]==p)
                return true;

    // Diagonal down-right
    for(int r = 0; r < ROWS-3; r++)
        for(int c = 0; c < COLS-3; c++)
            if(b[r][c]==p && b[r+1][c]==p && b[r+2][c]==p && b[r+3][c]==p)
                return true;

    // Diagonal up-right
    for(int r = 3; r < ROWS; r++)
        for(int c = 0; c < COLS-3; c++)
            if(b[r][c]==p && b[r-1][c]==p && b[r-2][c]==p && b[r-3][c]==p)
                return true;

    return false;
}

// Evaluate board (simple heuristic)
int evaluate(vector<vector<int>>& b) {
    if(checkWin(b, AI)) return 100000;
    if(checkWin(b, HUMAN)) return -100000;
    return 0;
}

// Minimax + Alpha-Beta
int minimax(vector<vector<int>>& board, int depth, int alpha, int beta, bool maximizingPlayer) {
    int score = evaluate(board);
    if(abs(score) == 100000 || depth == 0) return score;

    if(maximizingPlayer) {
        int best = -1e9;
        for(int col = 0; col < COLS; col++) {
            if(!canPlay(board, col)) continue;
            makeMove(board, col, AI);
            best = max(best, minimax(board, depth-1, alpha, beta, false));
            undoMove(board, col);
            alpha = max(alpha, best);
            if(beta <= alpha) break;
        }
        return best;
    } else {
        int best = 1e9;
        for(int col = 0; col < COLS; col++) {
            if(!canPlay(board, col)) continue;
            makeMove(board, col, HUMAN);
            best = min(best, minimax(board, depth-1, alpha, beta, true));
            undoMove(board, col);
            beta = min(beta, best);
            if(beta <= alpha) break;
        }
        return best;
    }
}

// AI chooses best move
int findBestMove(vector<vector<int>>& board, int depth) {
    int bestScore = -1e9;
    int bestCol = 3; // center default

    for(int col = 0; col < COLS; col++) {
        if(!canPlay(board, col)) continue;
        makeMove(board, col, AI);
        int score = minimax(board, depth, -1e9, 1e9, false);
        undoMove(board, col);

        if(score > bestScore) {
            bestScore = score;
            bestCol = col;
        }
    }
    return bestCol;
}

int main() {
    vector<vector<int>> board(ROWS, vector<int>(COLS, 0));

    cout << "Choose AI Difficulty:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "4. God Mode (Very Strong)\n";
    cout << "Enter option: ";

    int difficulty;
    cin >> difficulty;

    int depth = 4;
    if(difficulty == 1) depth = 2;
    else if(difficulty == 2) depth = 4;
    else if(difficulty == 3) depth = 6;
    else if(difficulty == 4) depth = 8;

    printBoard(board);

    while(true) {
        // Human move
        int col;
        cout << "Your move (0-6): ";
        cin >> col;

        if(!canPlay(board, col)) {
            cout << "Invalid move.\n";
            continue;
        }

        makeMove(board, col, HUMAN);
        printBoard(board);

        if(checkWin(board, HUMAN)) {
            cout << "You win!\n";
            break;
        }

        // AI move
        int aiCol = findBestMove(board, depth);
        makeMove(board, aiCol, AI);
        cout << "AI played at column: " << aiCol << "\n";
        printBoard(board);

        if(checkWin(board, AI)) {
            cout << "AI wins!\n";
            break;
        }
    }

    return 0;
}
