#include <stdio.h>
#include <stdlib.h>

#define number_of_expected_ext_args 1

int main(int argc,char **argv)
{   
    FILE *myfile;
    printf("\nProgram with  calling arguments from cmd line\n\n");
    for(unsigned short int i = 0;i<argc;i++ )  //Wypisanie argumentow
    {
     if (i == 0)printf("Number of (external) calling argumetns = %d \n",argc-1);
     printf("argv[%d]=%s\n",i,argv[i]);
    }
    if(argc!=2)
    {
     printf("\nIncorrect number of (ext) calling arguments\n");
     printf("expected number of  (ext) calling agrumetns is %d\n",number_of_expected_ext_args);
     printf("\n\tIMPORTANT!\t\nPlease use a path to the file as a calling argument\n");
     exit(EXIT_FAILURE);
    }
    printf("\nSection - File operations\n");
    printf("File has been opened\n");
    if((myfile = fopen(argv[1],"w")) == NULL)
    {
        printf("Input data status = incorrect FILE ERROR\n");
        printf("Please check the path to the file.\n");
        exit(EXIT_FAILURE);
    } 
    else
    {
        printf("\nInput data status = correct \n");
    }

    fclose(myfile);
    printf("\nThe file has been closed\n");
 
    return 0;
}