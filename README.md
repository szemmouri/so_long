<div align="center">
  <h1>42 So_Long</h1> 
  
  ## Final Score: 125/125
</div>

## Introduction

Welcome to the 42 So_Long project! This project is part of the curriculum at 42 and focuses on creating a 2D game using the MinilibX, a simple graphic library provided by 42. So_Long is a game where the player navigates through a map, collects items, and avoids obstacles to reach the goal.

## Game

![Game Screenshot 1](https://github.com/szemmouri/so_long/blob/main/images/Screen%20Shot%202025-02-09%20at%202.38.17%20PM.png)
![Game Screenshot 2](https://github.com/szemmouri/so_long/blob/main/images/Screen%20Shot%202025-02-09%20at%202.38.56%20PM%201.png)
![Game Screenshot 3](https://github.com/szemmouri/so_long/blob/main/images/Screen%20Shot%202025-02-09%20at%202.42.00%20PM.png)


## Objective

The objective of the So_Long project is to develop a fully functional game that incorporates various game elements, such as map rendering, player movement, collision detection, item collection, and win/lose conditions. By completing this project, you will enhance your understanding of game development concepts and gain practical experience in using the MinilibX library.

## Features

### Map Rendering
So_Long allows you to load and render game maps stored in a specific format, typically a file with a .ber extension. The map consists of different tiles representing walls, paths, collectible items, the player's starting position, and the exit. The MinilibX library provides functions to render graphical elements on the screen, enabling you to display the map with the appropriate textures and colors.

### Player Movement
The player can move in four directions: up, down, left, and right, within the bounds of the map. By handling keyboard inputs, you can update the player's position on the screen accordingly. The MinilibX library provides functions to capture key events and perform actions based on the pressed keys.

### Collision Detection
To ensure the player doesn't move through walls or outside the boundaries of the map, collision detection is implemented. The game checks if the player's desired movement will result in a collision with a wall or if the player has reached the exit. If a collision is detected, the player's movement is restricted.

### Item Collection
Throughout the map, there may be collectible items that the player can interact with. When the player reaches a tile containing an item, it is collected, and the player's score is incremented. This feature adds an additional layer of gameplay and encourages exploration.

### Win/Lose Conditions
The win condition is achieved when the player successfully reaches the exit tile. In contrast, the lose condition can be triggered by specific events, such as colliding with enemies or running out of lives. Implementing win and lose conditions adds a sense of challenge and completion to the game.

### Bonus Part Features
In the bonus part of the game :
- In my game only one enemy is allowed on the map
- If the player touches the enemy, it triggers an immediate game over
- The enemy can move in all dirictions

## Installation

To install and run the So_Long project, follow these steps:

1. Clone the project repository:
```bash
git clone https://github.com/szemmouri/so_long.git
```

2. Navigate to the project directory:
```bash
cd so_long
```

3. Compile the project using the provided Makefile:
```bash
make
```

4. Run the game executable Mandatory part:
```bash
./so_long maps/mandatory/valid/valid1.ber
```

5. Run the game executable Bonus part:
```bash
./so_long maps/bonus/big.ber
```

Make sure you have the MinilibX library installed on your system. If it's not already installed, you can find the library and installation instructions in the project repository.

## Testing

To test the game and validate its functionality, follow these steps:

1. Launch the game using the installation steps mentioned above
2. Navigate through the map using the arrow keys or/and WASD keys
3. Ensure the player can move freely within the map and is restricted by walls and boundaries
4. Collect items on the map and verify that the score is updated accordingly
5. Reach the exit tile and confirm that the game ends with a win condition
6. Test the enemy interaction in the bonus part:
  - Make the player lose when they touch an enemy patrol.
  - Add some sprite animation.
  - Display the movement count directly on screen instead of writing it in the shell.
7. Test various edge cases, such as reaching invalid tiles or unexpected input, to ensure the game handles them gracefully

During testing, monitor the game's performance, responsiveness, and adherence to the specified game rules. Make adjustments and improvements as necessary to enhance the gameplay experience.
