# CompetingGPUs

This project simulates a classic Tic-Tac-Toe game where two simulated GPUs (“players”) compete using distinct identities and strategies. Each player acts as a separate GPU device and chooses moves according to a predefined strategy (currently random). The competition is logged step-by-step for peer review and future extension.

## Video Demonstration

Watch the full workflow demonstration here:  
[CompetingGPUs: Tic-Tac-Toe GPU Competition Demonstration](https://www.tumblr.com/khronotop/797305531979218944/this-video-demonstrates-the-competinggpus-project?source=share)

## Requirements

- Windows 10/11
- CUDA Toolkit 13.0+
- C++17 support (for `<filesystem>`)
- NVIDIA GeForce RTX 4070 or compatible GPU

## Project Structure

- `src/` – Source code: main, game logic, GPU player logic
- `bin/` – Executable output
- `results/` – Game output logs
- `scripts/` – Optional batch/run scripts
- `Makefile` – Build/run/clean
- `INSTALL` – Installation instructions
- `CodeBook.md` – Design, algorithm and kernel descriptions

## Building

From the project root, build with:
```
make build
```
Or run a complete clean build:
```
make
```
Executable output will be in `bin/CompetingGPUs.exe`.

## Running

From the root directory, run:
```
make run
```
Or manually:
```
bin\CompetingGPUs.exe
```
The game log will be saved to `results/game_results.txt`.

## Game Details

- **Game:** Tic-Tac-Toe, 3x3 grid, turn-based.
- **Players:**
  - Player 1: GPU[0], symbol X, strategy: Random
  - Player 2: GPU[1], symbol O, strategy: Random
- **Simulation:** Each player chooses a move in turn. Moves, player identity, symbols, and board states are logged. The game ends on win or tie.

## Extending

- To add or change strategies, edit `GPUPlayer::chooseMove()`.
- To use real CUDA kernels, replace/extend logic in player classes.
- Output log format is suitable for replay or sharing in presentation/demo.

## Author

This project was developed for the Competing GPUs Project in the course [CUDA at Scale for the Enterprise](https://www.coursera.org/learn/cuda-at-scale-for-the-enterprise/home/module/1), part of the [GPU Programming Specialization](https://www.coursera.org/specializations/gpu-programming) specialization from Johns Hopkins University on Coursera.
