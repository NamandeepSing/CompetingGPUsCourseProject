// gpu_player.h
#pragma once

#include <string>
#include <vector>

// GPUPlayer represents a simulated GPU competitor with a given strategy.
class GPUPlayer {
public:
    GPUPlayer(int gpu_id, const std::string& name, char symbol, const std::string& strategy);

    // Chooses the next move based on the player's strategy.
    // Returns a pair (row, col).
    std::pair<int, int> chooseMove(const std::vector<std::vector<char>>& board) const;

    // Returns player's formatted info  
    std::string getLabel() const;

    char getSymbol() const;

private:
    int id;                 // Fake/real GPU device id
    std::string name;       // Player name, e.g., "Player 1"
    char symbol;            // 'X' or 'O'
    std::string strategy;   // "Random" or "Greedy" (for future expansion)
};
