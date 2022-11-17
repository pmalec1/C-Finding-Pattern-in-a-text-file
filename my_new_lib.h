
#define NUMBER_OF_EXPECTED_EXT_ARGS 3
void read_line (char temp_line[255]);
void copy_arguments_to_chars(char **argv, char searched_phrase[255],char path_to_file[255]);
void check_if_file_exist(char path_to_file[255]);
void check_number_of_arguments(int number_of_calling_args);
int analyse_data_from_from_line (char temp_line[255],char searched_phrase[255],unsigned short aray_of_pattern_positions_in_line[255]);
void clear_current_line(char current_line[255]);
void show_line(char temp_line[255]);
void write_line_in_the_screen(char temp_line[255],char searched_phrase[255],unsigned short aray_of_pattern_positions_in_line[255]);
#define  BLUE 93
#define  RED 31

