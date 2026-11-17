// gpu_player.cpp
#include "gpu_player.h"
#include <random>
#include <sstream>

GPUPlayer::GPUPlayer(int gpu_id, const std::string& name, char symbol, const std::string& strategy)
    : id(gpu_id), name(name), symbol(symbol), strategy(strategy) {}

// Helper function: returns a label for logs
std::string GPUPlayer::getLabel() const {
    std::ostringstream oss;
    oss << name << " (GPU[" << id << "], " << strategy << ")";
    return oss.str();
}

char GPUPlayer::getSymbol() const {
    return symbol;
}

// For now, strategy is only "Random"—chooses the first empty cell found.
std::pair<int, int> GPUPlayer::chooseMove(const std::vector<std::vector<char>>& board) const {
    // Random move
    std::vector<std::pair<int, int>> emptyCells;
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (board[r][c] == ' ') emptyCells.push_back({r, c});
        }
    }
    if (emptyCells.empty()) return {-1, -1}; // No valid move

    // True random pick (C++11)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, static_cast<int>(emptyCells.size()) - 1);
    int idx = dist(gen);
    return emptyCells[idx];
}
