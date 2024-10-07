# Game Of Life

> The Game of Life, also known as Conway's Game of Life or simply Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.
>  
> --Wikipedia

## Installation

To build and run the Game of Life, follow these steps:

1. **Clone the repository:**
    ```sh
    git clone --recursive https://github.com/sourav-behera/gameOfLife.gl.git
    cd game-of-life
    ```
2. **Build GLFW**
   ```sh
    mkdir vendor/glfw/build
    cd vendor/glfw/build
    cmake ..
    make
    cd -

   ```
3. **Build the project:**
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

4. **Run the executable:**
    ```sh
    ./gameOfLife
    ```
    Press **Space** to start the simulation
![gol_v1](https://github.com/user-attachments/assets/60ae4f34-b05c-46bf-82fb-06819e394657)
