# COMP345 - Advanced Program Design with C++

## Project Overview

This project is a simple computer game based on the popular board game "Risk." It is developed as part of the COMP345 course at Concordia University, focusing on advanced C++ programming concepts. The program follows the rules of the "Warzone" version of Risk, which can be found [here](https://www.warzone.com/). The goal of the game is to conquer all territories on the map by placing and moving armies strategically.

## Game Features

### Map
The game map is represented as a connected graph where:
- **Nodes**: Represent territories owned by players.
- **Edges**: Indicate adjacency between territories.
- **Continents**: Divided subgraphs within the map that provide bonuses if fully owned by a player.

### Gameplay
The game consists of 5 phases:
1. **Startup Phase**: Players are assigned territories randomly.
2. **Reinforcement Phase**: Players receive armies based on territories and continents owned.
3. **Orders Issuing Phase**: Players issue orders to deploy, advance, or use special cards.
4. **Orders Execution Phase**: Issued orders are executed in a round-robin manner.
5. **End Phase**: The player who conquers all territories wins, and game statistics are displayed.

### Orders
Players can issue the following orders:
- **Deploy**: Add armies to a territory.
- **Advance**: Move armies between territories or attack adjacent territories.
- **Bomb**: Destroy half the armies on a target territory.
- **Blockade**: Triple armies on a territory and make it neutral.
- **Airlift**: Move armies to any territory.
- **Negotiate**: Prevent attacks between two players until the end of the turn.

## Setup & Installation

1. **Clone the Repository**
   ```bash
   git clone https://github.com/MMingQwQ/COMP345-A1.git
   cd COMP345-A1
