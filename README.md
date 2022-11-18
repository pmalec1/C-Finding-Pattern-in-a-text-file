
# Piotr Malec 318544
## Oswiadczam ze praca zostala wykonana przeze mnie samodzielnie. 

# TASK
>TASK 
>2- finding pattern in the text file
# Project status 
> COMPLETE :)

## About project 
> This repository contains:
> * The program that finds a pattern in a text
> * Necessary libraries
> * images that show how it works
> * exemplary text file

## User's guide
> If you want to use this project you have to download this repository.
>  * Next step is compile program files with f.ex gcc or clang
>  *Examplary commands from terminal comand line:

>>gcc your_program_name.c -o executive_file -Wall -Wextra 

>>./executive_file   path_to_existing_file.txt   phrase_to_find

> And now you can see program execution results

## Variables used in the program
char searched_phrase[255];      -- the search phrase is stored in this variable

char path_to_file[255];         -- Path pointing to your file is stored in this variable

char current_line[255];         -- Current line from text file is stored here

unsigned short aray_of_pattern_positions_in_line[255]; -- At index [0] is  amount of patterns found in the line, 

next indexes stored position of patters(frist letter)

unsigned int  total_number_of_matches = 0;    --Number of matches from each lines of text file

unsigned short  matches_in_line = 0;          --Number of patterns in current line

char control_flag_EOF ='0';                   --this flag stored value of EOF.

unsigned int line_number = 1;                  -- number of current line 

## Functions used in the program
>Basics Functions from  <stdio.h> <stdlib.h  <string.h>

> Functions from my_new_lib.c
>> void read_line (char temp_line[255]);                                                        --load chars from line in text file to the variable

>> void copy_arguments_to_chars(char **argv, char searched_phrase[255],char path_to_file[255]); --copy argument of calling to arrays of chars

>> void check_if_file_exist(char path_to_file[255]);                                            -- Open file in read only mode and check if file exist

>> void check_number_of_arguments(int number_of_calling_args);                                  --Check if number of (ext) calling arugments is correct

>> int analyse_data_from_from_line (char temp_line[255],char searched_phrase[255],unsigned short aray_of_pattern_positions_in_line[255])
 
 Return number of matches from current line. Write into array amount of matches and positions of found patterns.
>> void clear_current_line(char current_line[255]);                                             -- Clear buffor;

>>void show_line_statistics(unsigned short aray_of_pattern_positions_in_line[255],short line_number) --Show amount of patterns and their positions in current line

>> void write_line_in_the_screen(char temp_line[255],char searched_phrase[255],unsigned short aray_of_pattern_positions_in_line[255]);  
--Display current line and highlight the searched phraze

## Rules
>1. User have to call the program with two (EXTERNAL) arguments
>2. Frist argument must be a path pointing to an existing file
>3. File must be in txt format
>4. Second argument is phrase you want to search for
# How it works?
* Step 1 Call the program with two correct arguments
* Step 2 Program check if your file exist and show you a message about correcitivty of your args.
* Step 3 Program analyze your text file line by line.The pattern will be found.  Its position will be saved. 
Amount of patterns in the line will be saved.
* Step 4 Each line will be displayed in the screen and found paterns will be highlighted.
* Step 5 Total number of matches will be displayed and the end.
### Examples of uses
> Examples of uses are in directory called "EXAMPLES_OF_USE" in this repository

> There are some pictures that show how it works
