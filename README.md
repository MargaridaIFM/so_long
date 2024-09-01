# so_long
<div align = "center">

<img src = "https://www.vangproperties.com/media/3830/42lisboa.jpg?preset=imageWithTextInsideText" alt = "42 lisbon img">

</div>

## About
The aim of this project is to create a 2D game using the MiniLibX library. The player need to collect some itens and avoid enemies to unlock the exit.

## Mandatory
- [x] Goal: Collect every collectable and escape choosing the shortest route.
- [x] Controls:Use W, A, S, and D keys to move the main character up, down, left, and right.
- [x] Movement Restrictions: Can't move into walls.
- [x] Movement Display: The number of movements must be displayed in the shell.
 - [x]Window Management: Display the image in a window and ensure it remains smooth (handling window changes, minimizing, etc.).
- [x] Exit Handling: Pressing ESC must close the window and quit the program cleanly.
 - [x] Cross Button Handling: Clicking the window's close button must also close and quit the program cleanly.
### MAP COMPONENTS
- [x]  The map should include 3 components to be constructed: walls, collectables and free space.
- [x] Should be composed of only these 5 characters: 0 for Empty space, 1 for Walls, C for Collectible, E for exit, P for player starting position.
- [x] The map must contain 1 exit, at least 1 collectable, and 1 starting position to be valid.
 - [x] Map must be rectangular.
- [x] Map must be closed/surrounded by walls
- [x] Map must have valid path from starting point to collectables and exit.
- [x]  If an error/misconfiguration is encountered, it should return Error\n

 - [x] Components: The map should include 3 components to be constructed: walls, collectibles, and free space.
 - [x] Character Set: The map should be composed of only these 5 characters:
    - [x] 0 for Empty space,
    - [x] 1 for Walls,
    - [x] C for Collectible,
    - [x] E for Exit,
    - [x] P for Player starting position.
 - [x] Validity: The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
 - [x] Shape: The map must be rectangular.
 - [x] Boundary: The map must be closed/surrounded by walls.
 - [x] Path Validity: The map must have a valid path from the starting point to collectibles and the exit.
 - [x] Error Handling: If an error or misconfiguration is encountered, it should return "Error\n".

## Bonus 
- [x] Make the player lose when they touch an enemy patrol.
- [x] Add some sprite animation.
- [x] Display the movement count directly on screen instead of writing it in the shell

## Step by step
- [x] Understand the MinilibX
	- [x] mlx_init()
	- [x] mlx_new_window()
	- [x] mlx_clear_window()
	- [x] mlx_destroy_window()
	- [x] mlx_new_image()
	- [x] mlx_destroy_image()
	- [x] mlx_xpm_file_to_image()
	- [x] mlx_put_image_to_window()
	- [x] mlx_string_put;
	- [x] mlx_hook()
	- [x] mlx_mouse_hook()
	- [x] mlx_key_hook()
	- [x] mlx_loop_hook()
    - [x] mlx_loop()
    - [x] others
- [x]PARSING
    - [x] see step by step on check_map.c
- [x] DISPLAY
    - [x] see step by step on display.c
    - [x] Create a window using MiniLibX
	- [x] Sprites 
	- [x] Render map
	- [x] hooks
[x] loop_hook
[x]BONUS
    - [x] Add sprite for the enemy
	- [x] Make the player lose when they touch an enemy patrol.
    - [x] Add some sprite animation.
            - [x] mlx_loop_hook()
                - [x] Add sprites for the animations
                - [x] Animantion function
- [x] Movement Display
    - [x] Use mlx_string_put on the beguin
    - [x] Update mlx_string_put when moves increase