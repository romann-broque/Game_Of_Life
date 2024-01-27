## Game of Life

Welcome to the Game of Life, a fascinating cellular automaton simulation implemented in C++ using the SFML (Simple and Fast Multimedia Library). This project brings to life the rules of Conway's Game of Life, where cells evolve based on a set of simple rules.

### 🗺️ Project Overview

The Game of Life is a classic cellular automaton simulation where each cell in a grid evolves over time based on its neighboring cells. The simulation follows specific rules, creating visually captivating patterns that emerge from seemingly simple interactions.

### 🌟 Key Features

- **Cellular Automaton Simulation**: Implements Conway's Game of Life rules for cellular automaton simulation.

- **SFML Graphics**: Utilizes the SFML library for graphics rendering, providing an interactive and visually appealing experience.

- **Grid Representation**: Represents the cellular grid where each cell evolves according to predefined rules.

- **User Interaction**: Allows user interaction to start, stop, and reset the simulation.

- **Pattern Visualization**: Visualizes interesting patterns and structures that emerge during the simulation.

### 🚀 How to Run

To run the Game of Life project, follow these steps:

1. **Install SFML**: Ensure the SFML library is installed on your system. Refer to the [SFML installation guide](https://www.sfml-dev.org/) for your platform.

    #### Linux

    ```shell
    sudo apt-get install libsfml-dev
    ```

    #### MacOS

    ```shell
    brew install sfml
    ```

2. **Build and Run**:

   ```shell
   make
   ./Simulation
   ```

![](file/GameOfLife.gif)

### 🕹️ Controls

- **Spacebar**: Start/Stop the simulation.
- **H/J**: Slow down/Accelerate the simulation.
- **R**: Reset the simulation.
- **Left Click**: Toggle life/death of cell.

### 🛠️ Options

It is possible to specify certain option values:

- **Background color**
- **Border color**
- **Border thickness**
- **Cell color**
- **Cell size**
- **Cell lifetime**
- **Cycle**
- **Darkening**
- **Food Color**
- **Food Presence**
- **Grid dimensions**
- **Probability of food**
- **Probability of life**
- **Window dimensions**

For more information:

```shell
./Simulation -h
# or
./Simulation --help
```

### 🎨 Additional Information

- **SFML Documentation**: Refer to the [SFML documentation](https://www.sfml-dev.org/documentation/) for detailed information on using SFML in your C++ projects.

- **Conway's Game of Life**: Explore the rules and patterns of Conway's Game of Life on the [Wikipedia page](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

Enjoy exploring the mesmerizing world of cellular automaton with the Game of Life! Experiment with different initial configurations, observe the emergence of patterns, and delve into the captivating dynamics of this simulation. 🧬🔬
