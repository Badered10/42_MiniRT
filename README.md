# MiniRT

## Project Overview
MiniRT is a simple yet powerful ray tracer built using C and MiniLibX. It was developed as part of a school project to demonstrate ray tracing fundamentals, including object rendering, lighting effects, and camera manipulation.

## Purpose
This project was created as part of the 42 Network curriculum to explore computer graphics, mathematics, and rendering algorithms.

---

## Features
- Realistic shadow rendering
- Flexible camera controls
- Support for multiple shapes and light controls
- Bonus features including bump mapping, anti-aliasing, and checkerboard patterns

---

## Mandatory Part
### Supported Shapes
- Sphere
- Plane
- Cylinder

### Lighting Model
- Phong lighting model for realistic shading

### Camera Controls
- Translation: Move forward, backward, left, and right
- Rotation: Rotate the camera on the X, Y, and Z axes

### Shapes and Lights Controls
- **Shapes:** Can be translated, rotated, and scaled
- **Lights:** Can be translated and rotated

### Parsing
- `.rt` file format for scene descriptions

---

## Bonus Part
### Supported Shapes
- Sphere
- Plane
- Cylinder
- Cone

### Lighting Model
- Add specular reflection

### Camera Controls
- All mandatory camera controls
- Additional control: Move all lights using side mouse keys

### Parsing
- `.rt` format with additional `ck` keyword for defining checkerboard patterns on planes

### Extra Features
- Bump mapping texture support
- Anti-aliasing for improved visual quality
- Patterns: Checkerboard patterns (for planes)

### Performance Optimizations
- Multi-threading for enhanced performance and faster rendering

---

## Technical Details
- Language: C
- Library: MiniLibX

---

## Build Instructions
1. Clone the repository
2. Run `make` to compile the project
3. Use `./minirt <scene_file.rt>` to launch the program

---

## Usage Instructions
### Camera Controls
- **"W, A, S, D"**: Move the camera (translation)
- **"U, O"**: Rotate camera on the Z axis
- **"I, K"**: Rotate camera on the Y axis
- **"J, L"**: Rotate camera on the X axis

### Shapes and Lights Controls
- **Arrow keys**: Move selected shape or light (translation)
- Rotation keys ("U, O", "I, K", "J, L") apply to shapes and lights as well

---

## Visuals
(Sample rendered images showcasing the ray tracer's capabilities)

---

## Acknowledgments
Special thanks to my teammate **Abderrahim Chikhi** for their contributions and dedication throughout this project.

---

## Personal Touch
Creating this project was a rewarding experience that challenged my understanding of mathematics, graphics, and code optimization. Exploring ray tracing concepts while improving performance and visuals has been an enriching journey.


