# Not Tetris, but space optimization algorithm

### HOW IT WORKS?

First, the program reads each tetromino from its given file, and during the reading, process checking is it a valid piece or not.
If it's not, then the program outputting `error`.
After the valid piece gets its shape and with all the data transforming each piece to alphabetical characters and recursive backtracking way solving the task;
to get the smallest square from it. (Place the pieces that between them are not at all/or just a small gap in the shortest amount of time.)
(You can find comments as well with small explanations in the codes.)

The [reader.c](https://github.com/mobahug/fillit_42/blob/main/srcs/fillit/sources/reader.c) file:

    • Checking for '#' connections and counting them (must be 6 or 8)

    • Checking is it a valid character ('.' and/or '#')

    • Checking is end of line '\n'

    • Checking the lines length

The [encode.c](https://github.com/mobahug/fillit_42/blob/main/srcs/fillit/sources/encode.c) file:

    • Bitwise mode shifting the bits to their shape

    • Measuring each individual tetrominoes width and height

    • Adding these data to the final function what we call in reader functions

The [solve.c](https://github.com/mobahug/fillit_42/blob/main/srcs/fillit/sources/solve.c) file:

    • Using recursive backtracking to check all possibilities for each tetromino and get place them on the map

    • For optimization purposes important that the solving part don't do unnecessary computing except what it's made for

The [printer.c](https://github.com/mobahug/fillit_42/blob/main/srcs/fillit/sources/printer.c) file:

    • Adding to the board with shifting bitwise operators the tetrominoes

    • Allocating for the board memory and printing them out


### Valid tetriminos:

<img width="141" alt="Screen Shot 2022-01-17 at 10 10 07 AM" src="https://user-images.githubusercontent.com/83179142/149731628-443d7714-a11b-4d92-8ce3-31abbcde5add.png">

Maximum valid grids: 26

According to the English alphabet.


To execute in default the program, just enter:

    make

After compiling type:

    ./fillit <valid_file.fillit>

You can also use the `time` argument to check how fast solving the algorithm the task:

    time ./fillit <valid_file.fillit>

<img width="772" alt="Screen Shot 2022-01-17 at 8 55 13 AM" src="https://user-images.githubusercontent.com/83179142/149721771-b9c0ea7c-7648-452b-bd14-58db48327007.png">

If you want to get the result in a colourful version just enter:

    make color

To remove it:

    make fclean_color

The purpose of this was, to see better each tetromino, and to be accepted by the 42 school project checker AI, had to modify the [Makefile](https://github.com/mobahug/fillit_42/blob/main/srcs/fillit/Makefile) and split into two-part, so by default the result will be black and white, but available the colourful version as well.

<img width="847" alt="Screen Shot 2022-01-17 at 8 58 07 AM" src="https://user-images.githubusercontent.com/83179142/149722069-b00eb82b-247b-4abe-aa11-22858f1859a9.png">
