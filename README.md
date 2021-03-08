# 3D Shapes
 This project basically involves constructing 3D shapes in OpenGL by using the OpenGL pipeline. \
 Following figures are made:
  * Decagonal Prism
  * Hexagonal Di-pyramid
  * Un-decagonal Pyramid
 
## Installation

Make sure you have the following installed on your system.
* glew
* cmake

Run the following commands to open a new window.
```(shell)
$ mkdir build && cd build
$ cmake ..
$ make 
$ ./3DShapes
```

## Controls

* The following keys are used to move camera
    *  <kbd>A</kbd> : Move Camera left
    *  <kbd>D</kbd> : Move Camera right
    *  <kbd>W</kbd> : Move Camera Up
    *  <kbd>S</kbd> : Move Camera Down
    *  <kbd>E</kbd> : Move Camera Inside the plane   
    *  <kbd>Z</kbd> : Move Camera Outside the plane
    
* The following keys are used to move object
    *  <kbd>J</kbd> : Move Object left
    *  <kbd>K</kbd> : Move Object right
    *  <kbd>I</kbd> : Move Object Up
    *  <kbd>M</kbd> : Move Object Down
    *  <kbd>O</kbd> : Move Object Inside the plane   
    *  <kbd>N</kbd> : Move Object Outside the plane
    
 
* The following keys are used to teleport the camera to fixed world-space coordinates
    *  <kbd>F</kbd> : Positions to (0, 0, 10)
    *  <kbd>G</kbd> : Positions to (5, -5, 5)
    *  <kbd>H</kbd> : Positions to (10, 0, 0)
    
* Miscellaneous
    *  <kbd>R</kbd> : Object start rotating about its z-axis (Toggling Key)
    *  <kbd>T</kbd> : Camera starts spinning around the object (Toggling Key)
    *  <kbd>Q</kbd> : Closes the window 
    *  <kbd>ESC</kbd> : Closes the window
