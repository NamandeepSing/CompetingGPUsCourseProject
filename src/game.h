// game.h
#pragma once

#include "gpu_player.h"
#include <string>
#include <vector>

class Game {
public:
    Game();
    void runCompetition(GPUPlayer& player1, GPUPlayer& player2);
    void saveResults(const std::string& filepath) const;

private:
    std::vector<std::vector<char>> board; // 3x3 Tic-Tac-Toe board
    std::string game_log;                 // Full game log

    void printBoardToLog();
    bool isWin(char symbol) const;
    bool isTie() const;
};
