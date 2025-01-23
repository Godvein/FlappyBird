# Flappy Bird - C++ SFML

A clone of the classic **Flappy Bird** game, developed using **C++** and **SFML**. This project demonstrates fundamental game development concepts, including physics simulation, input handling, collision detection, and basic game loop mechanics.

---
## Demo Video

Watch a short demo of my project in action:

https://github.com/user-attachments/assets/e0ae47ae-0bca-401c-8db2-748f91d623f7



## **About the Project**
Flappy Bird is a simple yet challenging game where the player controls a bird that flaps its wings to navigate through a series of obstacles (pipes). The objective is to pass through as many pipes as possible without colliding with them or the ground.

## How to Download and Play
You can find the .zip file on the release section for windows and linux. The game was primarily made for linux so it might have some bugs in windows.

## Setup Instructions for SFML Docker Container

## General Steps (for both Windows and Linux)
1. **Install Docker** (if not already installed):
   - **Windows**: Install Docker Desktop from [Docker's official website](https://www.docker.com/products/docker-desktop).
   - **Linux**: Follow the [Docker installation guide for Linux](https://docs.docker.com/engine/install/).

2. **Ensure Docker is Running**:
   - After installing Docker, ensure that Docker is running on your system.
   - **Windows**: Open Docker Desktop.
   - **Linux**: Check Docker status with the following command:
     ```bash
     sudo systemctl status docker
     ```

4. **Build the Docker Image**:
   Navigate to the directory containing the `Dockerfile`, then build the Docker image with the following command:
   ```bash
   docker build -t sfml-game .

5. **Run the Docker Container**:
   For windows:
  ```bash
  docker run --rm -it -e DISPLAY=host.docker.internal:0 -v /tmp/.X11-unix:/tmp/.X11-unix sfml-game 
```
  For linux:
  ```bash
  docker run --rm -it -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix sfml-game
```
  Troubleshooting:
  Display Issues:

If you're facing issues with the display, ensure that X11 is properly set up and that the display is properly forwarded.
        On Linux, check if your X server is running and if you're able to run GUI applications locally.
        On Windows, ensure that VcXsrv or another X server is running and correctly configured.

Permissions:

   On Linux, if you face permission issues with the X11 socket, you may need to allow access to the X server by running:
   ```bash
  xhost +local:docker
```



### **Project Structure**
```plaintext
FlappyBird/
├── assets/        # Game assets (sprites, textures, etc.)
├── src/           # C++ source files
├── build/         # Compiled executable and related files
└── README.md      # Project description
