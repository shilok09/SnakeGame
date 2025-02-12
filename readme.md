# Snake Game

## Description
This project is a simple implementation of the classic Snake game using C++ and OpenGL. The game features a snake that moves around the screen, consumes food to grow in length, and avoids obstacles. The game ends when the snake collides with itself or a hurdle.

## Features
- Responsive game mechanics
- Food generation and consumption
- Hurdles for added difficulty
- Score tracking system
- Smooth movement and direction control
- Border wrapping for continuous movement

## Technologies Used
- C++
- OpenGL (GLUT)

## Installation
To run the project locally, follow these steps:

### Prerequisites
Ensure you have the following installed:
- C++ compiler (G++)
- OpenGL and GLUT libraries

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/shilok09/SnakeGame.git
   cd snake-game
   ```
2. Compile the code using G++:
   ```bash
   g++ -o snake_game snakegame.cpp -lGL -lGLU -lglut
   ```
3. Run the executable:
   ```bash
   ./snake_game
   ```

## Gameplay Instructions
- Use arrow keys to control the snake:
  - **Up Arrow**: Move Up
  - **Down Arrow**: Move Down
  - **Left Arrow**: Move Left
  - **Right Arrow**: Move Right
- The game ends when the snake collides with itself or a hurdle.
- Eating food increases the snake's length and score.

## Project Structure
```
snake-game/
├── snakegame.cpp   # Main game implementation
├── util.h          # Utility functions and definitions
├── README.md       # Project documentation
├── assets/         # Folder for any game assets (if needed)
```

## Credits
- Developed by: Shilok Kumar
- Roll No: 23I-2502
- Libraries Used: OpenGL, GLUT

## License
This project is licensed under the MIT License.

## Contributing
Contributions are welcome! If you'd like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourFeatureName`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature/YourFeatureName`).
5. Open a pull request.

## Issues
If you encounter any issues or have suggestions for improvements, please open an issue on the GitHub repository.

