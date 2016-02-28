# Sokoban
A basic sokoban game made with termcaps. Posibility to create your own map (necessarily a rectangle one).

First download the source :
	$> git clone https://github.com/arthur111213/Sokoban.git

then compile the mrpgramm with CMake :
	$> make

Finaly, run the game with the following command :
	$> ./my_sokoban map.txt

You can make your own map with as much boxes as you want.
Just keep in mind that the game wont work correctly if you don't put the exact same number of boxes and destinations blocks.

For the maps :
	The map have to be a rectangle.
	'#' are walls blocks.
	'P' is the player. (just one in the map or the game wont start).
	'X' are boxes blocks.
	'O' are the boxes destinations blocks (position where you have to put the boxes).
	' ' are empty blocks.

You can control the player movements by pressing the arrow keys.
You can reset the game by pressing space bar key.
