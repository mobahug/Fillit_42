# Not Tetris, but space optimalization algoritm!

# HOW IT WORKS?

First the program reads each tetriminos from its given file, and during the reading process checking is it a valid piece or no.
If it's not, then the program outputing `error`.
After the valid piece get its shape and with all the datas transforming each piece to alphabetical characters and recursive backtracking way solving the task;
to get the smallests square from it. (Place the pieces that between them are no at all/or just small gap in the shortest amount of time.)
(You can find comments as well with small explanation in the codes.)

The `reader.c` file:

• `Checking for '#' connections and counting them (must be 6 or 8)`

• `Checking is it a valid character ('.' and/or '#')`

• `Checking is end of line '\n'`

• `Checking the lines length`

The `encode.c` file:

• `Bitwise mode shifting the bits to the its shape`

• `Measuring each individual tetriminoes width and height`

• `Adding these datas to the final function what we call in reader functions`

The `solve.c` file:

• `Using recursive backtracking to check all posibilties for each tetriminoes and get place them to the map`

• `For optimalization purposes important that the solving part don't do unnecesary computing except what for it's made`

The `printer.c` file:

• `Adding to the board with shifting bitwise operators the tetriminoes`

• `Allocating for the board memory and printing them out`


# Valid tetriminos:

<img width="141" alt="Screen Shot 2022-01-17 at 10 10 07 AM" src="https://user-images.githubusercontent.com/83179142/149731628-443d7714-a11b-4d92-8ce3-31abbcde5add.png">

To execute the default fillit just enter 'make':

• `make`

After compiling type:

`./fillit <valid_file.fillit>`

You can also use `time` argument to check how fast solving the algoritm the task:

`time ./fillit <valid_file.fillit>`

<img width="772" alt="Screen Shot 2022-01-17 at 8 55 13 AM" src="https://user-images.githubusercontent.com/83179142/149721771-b9c0ea7c-7648-452b-bd14-58db48327007.png">

If you want to get the result in colourful version just enter:

• `make color`
• `make fclean_color`

The purpose of this was, to see better each tetriminoes, and to be accepted by the 42 school project checker AI, had to modifiy the [Makefile](https://github.com/mobahug/fillit_42/blob/main/srcs/fillit/Makefile)

<img width="847" alt="Screen Shot 2022-01-17 at 8 58 07 AM" src="https://user-images.githubusercontent.com/83179142/149722069-b00eb82b-247b-4abe-aa11-22858f1859a9.png">
