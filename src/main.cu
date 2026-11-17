// main.cu
#include <iostream>
#include "game.h"
#include "gpu_player.h"

int main() {
    std::cout << "GPU Tic-Tac-Toe Competition Started!" << std::endl;

    // Player 1: GPU[0], strategy: Random, plays as 'X'
    GPUPlayer player1(0, "Player 1", 'X', "Random");
    // Player 2: GPU[1], strategy: Random, plays as 'O'
    GPUPlayer player2(1, "Player 2", 'O', "Random");

    // Run the competition
    Game game;
    game.runCompetition(player1, player2);
    game.saveResults("results/game_results.txt");

    std::cout << "Competition completed. Results are in results/game_results.txt" << std::endl;
    return 0;
}
