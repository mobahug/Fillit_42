# fillit_42

#HOW IT WORKS?

First the program reads each tetriminos from its given file, and during the reading checking is it a valid piece or no.
The `reader.c` file:

• `checking for '#' connections and counting them (must be 6 or 8)`

• `checking is it a valid character ('.' and/or '#')`

• `checking is end of line '\n'`

• `checking the lines length`

# Valid tetriminos:

<img width="141" alt="Screen Shot 2022-01-17 at 10 10 07 AM" src="https://user-images.githubusercontent.com/83179142/149731628-443d7714-a11b-4d92-8ce3-31abbcde5add.png">

To execute the default fillit just enter 'make':

• `make`

After compiling type

`./fillit <valid_file.fillit>`

You can also use `time` argument to check how fast solving the algoritm the task:

`time ./fillit <valid_file.fillit>`

<img width="772" alt="Screen Shot 2022-01-17 at 8 55 13 AM" src="https://user-images.githubusercontent.com/83179142/149721771-b9c0ea7c-7648-452b-bd14-58db48327007.png">

• `make color`
• `make fclean_color`

<img width="847" alt="Screen Shot 2022-01-17 at 8 58 07 AM" src="https://user-images.githubusercontent.com/83179142/149722069-b00eb82b-247b-4abe-aa11-22858f1859a9.png">
