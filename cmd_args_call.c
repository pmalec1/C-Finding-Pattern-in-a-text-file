#include <stdio.h>
#include <stdlib.h>
#define number_of_expected_ext_args 1 //definition of number of expected files to open
void show_arguments_of_calling_the_program(int argc,char **argv);
void check_number_of_arguments(int argc);
void open_file_from_path(int argc,char **argv);
void check_if_file_exist(char **argv);
/**************************************************************************************************/
//there is always at least one argument of calling because program itself  is considered an argument
// Frist arg is paths to text file
// second is phrase that you want to search and modify
// third is phrase that will replace previously found phrase 
/**************************************************************************************************/
int main(int argc,char **argv)
{   
   FILE *myfile;
   show_arguments_of_calling_the_program(argc,argv); // display on screen list of calling(invocation) arguments  of the program
   check_number_of_arguments(argc);                  // this function check if amount of agrumetns is correct
   check_if_file_exist(argv);                        // open file in read only mode to check if file exist  
   myfile = fopen(argv[1],"w");
   printf("\nFile has been opened\n");
   printf("\nHere will be some file operations :D\n");
   fclose(myfile);
   printf("\nThe file has been closed\n\n");                  // open file in write mode. you can modify file using this function 
    return 0;                                        // if everything is ok return 0
}

void show_arguments_of_calling_the_program(int argc,char **argv)
{
    printf("\nProgram with  calling arguments from cmd line\n\n");
        for(unsigned short int i = 0;i<argc;i++ )  //print list of arguments
        {
             if (i == 0)printf("Number of (external) calling argumetns = %d \n", argc-1);
            printf("argv[%d]=%s\n",i,argv[i]);
        }
       
}
void check_number_of_arguments(int argc)
{
 if(argc!=4)
    {
     printf("\nIncorrect number of (ext) calling arguments\n");
     printf("expected number of  (ext) calling agrumetns is %d\n",number_of_expected_ext_args);
     printf("\n\tIMPORTANT!\t\n Please enter a path to the file as a calling argument as a frist arg.\n");
     printf("\n as the second argument, please enter the phrase you want to search for and modify\n");
     printf("\n as the third argument, enter the phrase you want to replace the previously found phrase \n\n");

     exit(EXIT_FAILURE);
    }
 else printf("\ncorrect number of arguments\n");
}

void check_if_file_exist(char **argv)
{  
        FILE *myfile;
      if((myfile = fopen(argv[1],"r")) == NULL)
        {
            printf("Input data status = incorrect FILE ERROR\n");
            printf("Please check the path/name to the file.\n");
            exit(EXIT_FAILURE);
        } 
        else
        {
        printf("\nInput data status = correct \n");
        printf("Path to data exist :)\n\n");
        }
}
