# Use the official Ubuntu image
FROM ubuntu:latest

# Set environment variables to avoid interactive prompts during installation
ENV DEBIAN_FRONTEND=noninteractive

# Update and install dependencies (including SFML and build tools)
RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y \
    build-essential \
    cmake \
    g++ \
    libsfml-dev \
    xorg \
    libglu1-mesa \
    libsdl2-dev \
    libsndfile1 \
    libudev-dev \
    git

# Copy the entire project into the Docker container
COPY /src /app/src
COPY /assets /app/assets

# Set the working directory to /app (in the container)

WORKDIR /app/src
# Build the project (assuming you are using g++ to compile the project)
# We need to compile all the .cpp files (you may need to adjust this if you use CMake)
RUN g++ -o /app/game *.cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++17

# Set the command to run your compiled program
CMD ["/app/game"]

