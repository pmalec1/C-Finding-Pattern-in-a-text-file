

/*This library consists of some functions that allow you to do some basic files operations and */
/*it allows some operations to be done on invocation(calling) arguments more easily*************/



/************************ DEFINITIONS of functions *********************************************/
/***********************************************************************************************/

void show_arguments_of_calling_the_program(int argc,char **argv)
{
        for(unsigned short int i = 0;i<argc;i++ )  
        {
             if (i == 0)printf("\nNumber of (external) calling argumetns = %d \n", argc-1);   // show amount of ext arguments ingore argv[0] because program itself is considered an argument
            printf("argv[%d]=%s\n",i,argv[i]);                                                //display a list of calling arguments
        }
       
}
void check_number_of_arguments(int argc)
{
 if(argc!=number_of_expected_ext_args)                                                                      //check if user enter correct number of (ext) arguments                                            
    {
     printf("\nIncorrect number of (ext) calling arguments\n");                                                    // **messages to user about error
     printf("expected number of  (ext) calling agrumetns is %d\n",number_of_expected_ext_args);                    // **
     printf("\n\tIMPORTANT!\t\n Please enter a path to the file as a calling argument as a frist arg.\n");         // ***
     printf("\n as the second argument, please enter the phrase you want to search for and modify\n");             //  messages to the user about the correct form of the arguments
     printf("\n as the third argument, enter the phrase you want to replace the previously found phrase \n\n");    // ***

     exit(EXIT_FAILURE);                                                                                          //leave the loop and program with failure code
    }                                                                                                             //a message that user enter correct amount of arguments
 else printf("\ncorrect number of arguments\n\n");                                                                //if everything is correct 
                                                                                                                  //leave the loop without failure code
}

void check_if_file_exist(char **argv)
{  
      FILE *myfile;                                                           // remeber arg no.1 must be path to existing file or name of file in project enviroment
      if((myfile = fopen(argv[1],"r")) == NULL)                   //check if file exist if no display a message to user
        {
            printf("Input data status = incorrect FILE ERROR\n"); // mesasge to user
            printf("Please check the path/name to the file.\n");  // 
            exit(EXIT_FAILURE);                                   // exit program with failure code
        } 
        else
        {
        fclose(myfile);
        printf("\nInput data status = correct \n");               // if everything is ok display message about it
        printf("Path is pointing to existing file :)\n\n");                      // and leave the loop and continue program execution
        }
}

