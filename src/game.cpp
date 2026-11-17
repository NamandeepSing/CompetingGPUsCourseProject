// game.cpp
#include "game.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>

// Constructor: initializes the board
Game::Game() : board(3, std::vector<char>(3, ' ')), game_log("Competition initialized.\n") {}

// Helper: write the current board state to game_log
void Game::printBoardToLog() {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            game_log += (board[r][c] == ' ' ? "." : std::string(1, board[r][c]));
            if (c < 2) game_log += " | ";
        }
        game_log += "\n";
        if (r < 2) game_log += "--+---+--\n";
    }
    game_log += "\n";
}

// Returns true if symbol wins
bool Game::isWin(char symbol) const {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return true;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return true;
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true;
    return false;
}

// Returns true if all cells are filled and no winner
bool Game::isTie() const {
    for (auto& row : board) {
        for (char cell : row) if (cell == ' ') return false;
    }
    return true;
}

// Main competition loop with logging
void Game::runCompetition(GPUPlayer& player1, GPUPlayer& player2) {
    game_log += player1.getLabel() + " vs " + player2.getLabel() + "\n";
    printBoardToLog();
    bool gameOver = false;
    int turn = 0;
    GPUPlayer* players[2] = {&player1, &player2};

    while (!gameOver) {
        GPUPlayer* currPlayer = players[turn % 2];
        auto move = currPlayer->chooseMove(board);
        if (move.first == -1) break; // No valid move

        board[move.first][move.second] = currPlayer->getSymbol();

        std::ostringstream ss;
        ss << "Turn " << (turn + 1) << ": " << currPlayer->getLabel()
           << " places " << currPlayer->getSymbol()
           << " at (" << move.first << ", " << move.second << ")\n";
        game_log += ss.str();
        printBoardToLog();

        if (isWin(currPlayer->getSymbol())) {
            game_log += currPlayer->getLabel() + " WINS!\n";
            gameOver = true;
        } else if (isTie()) {
            game_log += "TIE GAME.\n";
            gameOver = true;
        }
        turn++;
    }
    game_log += "Competition ended.\n";
}

// Saves the full log to output file (creates dir if needed)
void Game::saveResults(const std::string& filepath) const {
    std::filesystem::create_directories(filepath.substr(0, filepath.find_last_of("/\\")));
    std::ofstream outfile(filepath);
    if (outfile.is_open()) {
        outfile << game_log;
        outfile.close();
        std::cout << "Results saved to " << filepath << std::endl;
    } else {
        std::cerr << "Error opening result file!" << std::endl;
    }
}
