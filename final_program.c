#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_new_lib.h"
//#include "my_new_lib.c"
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

    if(check_number_of_arguments(argc)!=true)
   {
      printf("\t\tIncorrect number of arguments \n");
      printf("\t\tExpected number of arguments(ext) is 2\n");
      exit(1);
   }                        
   else
   {
      printf("\t\tNumber of arguments is correct :D\n");
   }    
   copy_arguments_to_chars(argv,searched_phrase,path_to_file); 
   if(check_if_file_exists(path_to_file)==true)
   {
      printf("\t\tFile exists :D\n");
   }                 
   else
   {
      printf("\t\tFile doesn't exist\n");
      exit(1);
   }
   FILE *myfile;
   myfile = fopen(argv[1],"r");

   printf("\t\tFile has been opened\n\n"); 
   while((control_flag_EOF = fgetc(myfile)) != EOF )                                     
   {
      fseek(myfile, -1,1);      
      clear_current_line(current_line);                                                          
      read_line(current_line); 
      matches_in_line = analyse_data_from_from_line(current_line,searched_phrase,aray_of_pattern_positions_in_line); 
      show_line_statistics(aray_of_pattern_positions_in_line,line_number);
      total_number_of_matches += matches_in_line;
      ++line_number;
   }

   printf("\n\n\t\tTOTAL NUMBER OF MATCHES = %d\n\n",total_number_of_matches);    
   printf("\t\tThe file has been closed\n\n");  \

   fclose(myfile);                                                         
   return 0;                                                               
}

