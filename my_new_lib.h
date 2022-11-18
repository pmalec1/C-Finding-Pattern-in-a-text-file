FILE *myfile;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
#define NUMBER_OF_EXPECTED_EXT_ARGS 3
void read_line (char temp_line[255]);
void copy_arguments_to_chars(char **argv, char searched_phrase[255],char path_to_file[255]);
int check_if_file_exists(char path_to_file[255]);
int check_number_of_arguments(int number_of_calling_args);
int analyse_data_from_from_line (char temp_line[255],char searched_phrase[255],unsigned short aray_of_pattern_positions_in_line[255]);
void clear_current_line(char current_line[255]);
void show_line_statistics(unsigned short aray_of_pattern_positions_in_line[255],short line_number);


