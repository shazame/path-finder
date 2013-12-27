path-finder
===========

This is just a small personal project to get familiar with maze generation and
some path finding algorithm.

Currently only the maze generation part has been finished.
*ncurses* is used to display the maze. In the futures other GUI might be
provided.

Want to try it?
---------------

Just clone this repository, go to the project root and compile it:

`git clone https://github.com/shazame/path-finder.git`

`cd path-finder`

`make`

Then run the project's main program:

`./bin/PathFinder`

Functionalities
---------------

Currently the program capabilities are limited. When it is launched a maze is
generated randomly and is displayed. `'q'` can pressed to exit. Any other key
will trigger the generation of a new random maze.

Launch the tests
----------------

Some tests are provided using Google Test.
They can simply be compiled and run with:

`make runtest`

Every test should run properly.

Dependencies
------------

The library *ncurses* is needed for the user interface.

If you want to run the tests you need *wget* and *unzip* to get Google
Test automatically when compiling them.
