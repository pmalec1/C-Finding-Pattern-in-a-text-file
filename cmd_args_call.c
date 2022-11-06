#include <stdio.h>
#include <stdlib.h>

  
#include "file_operation_lib.h"
#include "file_operation_lib.c"
/****************************************************************************************************************/
//there is always at least one argument of calling(invocation) because program itself  is considered an argument*/
/****************************************************************************************************************/
int main(int argc,char **argv)
{   
   FILE *myfile;
   show_arguments_of_calling_the_program(argc,argv);   // display on screen list of calling(invocation) arguments  of the program
   check_number_of_arguments(argc);                    // this function check if amount of agrumetns is correct
   check_if_file_exist(argv);                          // open file in read only mode to check if file exist 
   myfile = fopen(argv[1],"w");                        // open file in write and read mode
   printf("\nFile has been opened\n");                 // a message to  user that file has been opened succesfully (access - ok)
   fclose(myfile);                                     // close previous opened file
   printf("\nThe file has been closed\n\n");           // a message to user that file has been closed (the file can no longer be accessed until it is reopened)
   return 0;                                           // if everything is ok return 0
}

