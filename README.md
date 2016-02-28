# Sokoban
A basic sokoban game made with termcaps. Posibility to create your own map (necessarily a rectangle one).

First download the source :
    $> git clone https://github.com/arthur111213/Sokoban.git

then compile the mrpgramm with CMake :
    $> make

Finaly, runn the game with the following command :
    $> ./my_sokoban map.txt

You can make your own map with as much boxes as you want.
Just keep in mind that the game wont work corectly if you don't put the exact same number of box and destination.

For the maps :
    '#' are walls blocs.
    'P' is the player. (just one in the map or the game wont start.
    'X' are boxes.
    'O' are destinations for boxes.

You can control the player movements by pressing the arrows keys.
You can reset the game by pressing the spaceBar key.
