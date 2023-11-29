# Cub3D 🧊

# Project Overview

Cub3D is a homage to the 90's first-person shooter games, particularly inspired by the iconic "Wolfenstein 3D." This project is not just about gaming nostalgia but also an exploration into the world of ray-casting technology. Experience a dynamic view within a maze, where you navigate to find your way out, mimicking the classic FPS gameplay.

# 🚀 Get Started

- Clone the repository.
- Navigate to the project directory.
- Run the program using the command: ```./cub3D <map_file.cub>```

# 💡 Key Learnings: Raycasting Explained
Ray-casting is a technique that transform a limited form of data (a very simplified map or floor plan) into a 3D projection by tracing rays from the view point into the viewing volume

- Principle: For each column of the screen, a ray is cast from the player's view. The direction of each ray depends on the player's position and the column's x-coordinate.
- Wall Detection: The ray moves forward until it hits a wall. The distance to this hit determines how high the wall appears on the screen.
- Side Determination: The texture of the wall varies based on the side the ray hits, creating a realistic 3D environment.
- Efficiency: The algorithm efficiently calculates the distance to walls and renders only what's visible to the player, optimizing performance.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/e/e7/Simple_raycasting_with_fisheye_correction.gif" alt="raycasting"/>
</p>
  
# 📚 Resources
- [Pikuma's course: Raycasting Engine Programming](https://pikuma.com/courses/raycasting-engine-tutorial-algorithm-javascript)
- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
