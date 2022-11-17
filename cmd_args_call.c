#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_new_lib.h"
#include "my_new_lib.c"
/****************************************************************************************************************/
//there is always at least one argument of calling(invocation) because program itself  is considered an argument*/
/****************************************************************************************************************/
int main(int argc,char **argv)
{  
   char searched_phrase[255];
   char path_to_file[255];
   char current_line[255];
   unsigned short aray_of_pattern_positions_in_line[255];
   int total_number_of_matches = 0;
   int matches_in_line = 0;
   char control_flag_EOF ='0';
   short line_number = 1;
   check_number_of_arguments(argc);                            
   copy_arguments_to_chars(argv,searched_phrase,path_to_file); 
   check_if_file_exist(path_to_file);                           
   myfile = fopen(argv[1],"r");      

   printf("\n\t\t\tFile has been opened\n"); 
   printf("\n\n\t\tPatterns will be displayed in yellow\n\n");
   while((control_flag_EOF = fgetc(myfile)) != EOF )                                     
   {
      fseek(myfile, -1,1);      
      clear_current_line(current_line);                                                          
      read_line(current_line); 
      matches_in_line = analyse_data_from_from_line(current_line,searched_phrase,aray_of_pattern_positions_in_line); 
      show_line_statistics(aray_of_pattern_positions_in_line,line_number);
      write_line_in_the_screen(current_line,searched_phrase,aray_of_pattern_positions_in_line);

      total_number_of_matches += matches_in_line;
      ++line_number;
   }

   printf("\n\n\t\tTOTAL NUMBER OF MATCHES = %d\n\n",total_number_of_matches);    
   printf("\n\t\tThe file has been closed\n\n");  \

   fclose(myfile);                                                         
   return 0;                                                               
}
