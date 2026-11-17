# Makefile for CompetingGPUs (Windows, CUDA 13.0, RTX 4070)

CXX = nvcc
SRC = src/main.cu src/game.cpp src/gpu_player.cpp
EXE = CompetingGPUs.exe
BIN_DIR = bin
RESULTS_DIR = results

# CUDA and Windows SDK paths (edit if necessary)
CUDA_PATH = "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.0"
WIN_KITS_INC = "C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0"
WIN_KITS_LIB = "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0"

CXXFLAGS = -std=c++17 -arch=sm_89 \
-I$(WIN_KITS_INC)/um \
-I$(WIN_KITS_INC)/shared \
-I$(WIN_KITS_INC)/ucrt \
-I$(WIN_KITS_INC)/winrt \
-I$(WIN_KITS_INC)/cppwinrt \
-I$(CUDA_PATH)/include

LDFLAGS = -L$(CUDA_PATH)/lib/x64 -lcudart -lcuda \
-L$(WIN_KITS_LIB)/um/x64 \
-L$(WIN_KITS_LIB)/ucrt/x64

# Default: clean and build
all: clean build

# Build the executable from all source files
build: $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(BIN_DIR)/$(EXE) $(LDFLAGS)

# Run the executable
run:
	$(BIN_DIR)/$(EXE)

# Clean build artifacts and output files
clean:
	@if exist $(BIN_DIR)\$(EXE) del $(BIN_DIR)\$(EXE)
	@if exist $(RESULTS_DIR)\game_results.txt del $(RESULTS_DIR)\game_results.txt
