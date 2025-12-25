### CMake SFML Starter template:
https://github.com/SFML/cmake-sfml-project?tab=readme-ov-file

# Goals:
- Use of C++/SFML AND ImGUI 
- Reads from a config.txt file that has drawing paramteres ofr shapes
	- Each shape will have a *name, position, speed, color, font size, font colour and unique properties. For example a Rectangle will have width and height, while a circle will hvae Radius*
	- The position refers to its SFML default upper left corner position
- Draw the shapes from the txt file, make them move and make them bounce off window borders
- Each shape's name should always be centered in the middle of the shape itself
	- The *font size* and *font colour* specified in the shape config has to be followed

*** GUI
- List of all the shapes and select any one of them to edit their properties (Dropdown recommended)
- Toggle whether or not the shape will be drawn
- Change the scale of the shape (0 to 4)
- Change the x and y velocity of the shape (-8 to 8)
- Change the color of the shape
- Change the name of the shape

*** Config
Window W H
- Width            W        int
- Height           H        int

Font F S R G B
- Font File        F        std::string
- Font Size        S        int
- RGB color        (R,G,B)  int, int, int

Rectangle N X Y SX SY RGB W H
- Shape Name       N        std::string
- Initial Position (X,Y)    float, float
- Initial Speed    (SX, SY) float, float
- RGB Color        (R,G,B)  int, int, int
- Size             (W,H)    float, float

Circle N X Y SX SY RGB R
- Shape Name       N        std::string
- Initial Position (X,Y)    float, float
- Initial Speed    (SX, SY) float, float
- RGB Color        (R,G,B)  int, int, int
- Radius           R        float