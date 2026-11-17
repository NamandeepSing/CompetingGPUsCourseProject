# CodeBook for CompetingGPUs

## Overview

This document describes the project structure, high-level algorithms, and kernel expansion points for the Tic-Tac-Toe GPU competition simulation.

## File descriptions

- **main.cu:** Application entry. Creates players and launches the Tic-Tac-Toe competition.
- **game.h/.cpp:** Implements game flow, board logic, move validation, and logging of results.
- **gpu_player.h/.cpp:** Simulates GPU competitors with assigned strategy, identity and symbol. Strategy code is isolated for easy extension.

## Algorithm summary

- Turn-based Tic-Tac-Toe: two players alternate, each placing a symbol ('X' or 'O').
- Each move is chosen based on the player's strategy (default: random).
- After every move, the current board is logged for full traceability.
- The game recognizes win/tie states, and logs the outcome.
- All events (player identity, move coordinates, board snapshots, and results) are stored in `game_log` and saved to a text file.

## GPU kernels

- The current implementation uses simple C++ logic for demonstration.
- To use real CUDA computations, implement custom kernels in `GPUPlayer::chooseMove()` (e.g., for strategy optimization, parallel move search, or board evaluation).
- Each GPUPlayer instance may be mapped to a real GPU device if more than one is present.

## Modifying for custom strategies

- Extend `GPUPlayer::chooseMove()` for different strategies (e.g., greedy, minimax, reinforcement learning).
- Use simulated, random, or complex strategies for each player.
- Support for real multi-GPU is possible by launching kernels and setting the device via CUDA APIs.

## Output files

- All move-by-move logs and board states are written to `results/game_results.txt`.
- Output can be used for replay, presentation, or peer review.