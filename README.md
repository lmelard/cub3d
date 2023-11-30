# Cub3D 🐺

# Project Overview

Cub3D is a tribute to the iconic 90's first-person shooter game "Wolfenstein 3D." This project is not just about gaming nostalgia but also an exploration into the world of ray-casting technology. 
# 🧱 Building and Running the Game

## Requirements:

- GCC Compiler
- miniLibX Library
- A Linux/Unix environment

## Makefile Commands:

- `make`: Compiles the program.
- `make clean`: Removes object files.
- `make fclean`: Cleans all compiled files.
- `make re`: Re-compiles the program.

## Get Started
- Clone the repository.
- Navigate to the project directory.
- Compile with `make`
- Run the program using the command: ```./cub3D <map_file.cub>```

# 💡 Key Learnings: Raycasting Explained
Ray-casting is a technique that transform a limited form of data (a very simplified map or floor plan) into a 3D projection by tracing rays. The rays are traced from the player point of view into the viewing volume

- Principle: For each column of the screen, a ray is cast from the player's view. The direction of each ray depends on the player's position and the column's x-coordinate.
- Wall Detection: The ray moves forward until it hits a wall. The distance to this hit determines how high the wall appears on the screen.
- Side Determination: The texture of the wall varies based on the side the ray hits, creating a realistic 3D environment.
- Efficiency: The algorithm efficiently calculates the distance to walls and renders only what's visible to the player, optimizing performance.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/e/e7/Simple_raycasting_with_fisheye_correction.gif" alt="raycasting"/>
</p>

# 🛠 Technical Specifications
- Tech stack: C
- Graphics: miniLibX library
- Features:
    - Ray-casting for 3D rendering.
    - Fluid window management.
    - Customizable textures and colors for game elements.
    - Interactive controls for in-game navigation.
  
# 📚 Resources
- [Pikuma's course: Raycasting Engine Programming](https://pikuma.com/courses/raycasting-engine-tutorial-algorithm-javascript)
- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)

# 👥 Contribution and Development
This project is a collaborative effort :

<p align="center">
<a href="http://github.com/lmelard" alt="lmelard github profile"><img src="https://github.com/lmelard.png" width="60px style="border-radius:50%"/></a>
<a href="http://github.com/tiny-chris" alt="tiny-chris github profile"><img src="https://github.com/tiny-chris.png" width="60px style="border-radius:50%"/></a>
</p>
