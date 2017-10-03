# fdf
"fil de fer" aka "iron wire"

### About
This is the first project from Graphics branch of School's 42 curriculum. The aim of this project is to create a program that would translate a 2D map into 3D model. We were provided with 2D maps that can be found in /maps directory
The code is written in accordance with the Norm.

### Requirements
This project is based on a macos version of a graphical library - minilibx. If you use other os than mac, delete minilibx_macos folder and clone a folder with the proper os from here: https://github.com/dannywillems/minilibx (do not forget to change Makefile).

### Building the program
1. Clone the source code
2. From the root directory run `make`

### Supported commands
* ← - Move map right.
* → - Move map left.
* ↑ - Move map up.
* ↓ - Move map down.
* + - Zoom in.
* - - Zoom out
* q - Decrease height.
* w - Increase height.
* x - Decrease scale of height.
* z - Increase scale of height.
* u, i - Rotate around 0z.
* j, k - Rotate around 0y.
* n, m - Rotate around 0x.
* ESC - exit program.

### TODO
* Rotate around center, not {0,0,0}
* Make Bresenham's algorithm work with gradient
* Add description of commands used for 3d image manipulation
