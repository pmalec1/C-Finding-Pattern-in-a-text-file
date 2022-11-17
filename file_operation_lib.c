FILE *myfile;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_new_lib.h"

void check_number_of_arguments(int argc)
{
 if(argc!=NUMBER_OF_EXPECTED_EXT_ARGS)                                                                      //check if user enter correct number of (ext) arguments                                            
    {
     printf("\nIncorrect number of (ext) calling arguments\n");                                                    // **messages to user about error
     printf("expected number of  (ext) calling agrumetns is %d\n",NUMBER_OF_EXPECTED_EXT_ARGS-1);                    // **
     printf("\n\tIMPORTANT!\t\n Path to file (existing) should be frist argument of calling.\n");         // ***
     printf("\n Phrase wanted to search in text file should be second argument of calling\n");             //  messages to the user about the correct form of the arguments
     exit(1);                                                                                          //leave the loop and program with failure code
    }                                                                                                             //a message that user enter correct amount of arguments
 else printf("\nNumber of arguments = correct\n\n");                                                                //if everything is correct 
                                                                                                                  //leave the loop without failure code
}
       
void check_if_file_exist(char path_to_file[255]) 
{                                                          // remeber arg no.1 must be path to existing file or name of file in project enviroment
      if((myfile = fopen(path_to_file,"r")) == NULL)                   //check if file exist if no display a message to user
        {
            printf("File name/path = incorrect FILE ERROR\n"); // mesasge to user
            printf("Please check the path/name to the file.\n\n");  // 
            exit(1);                                   // exit program with failure code
        } 
        else
        {
        fclose(myfile);
        printf("\nInput data status = correct \n");               // if everything is ok display message about it
        printf("Path is pointing to existing file :)\n\n");                      // and leave the loop and continue program execution
        }
}

void copy_arguments_to_chars(char **argv, char searched_phrase[255],char path_to_file[255])
{
  strcpy(searched_phrase, argv[2]);
  strcpy(path_to_file, argv[1]);
}

void read_line (char temp_line[255])
{   

    int index_in_line = 0;
    char temp_char = '0';

    while((temp_char = fgetc(myfile)) != '\n' && temp_char != EOF)
   {  
      temp_line[index_in_line]=temp_char;
      ++index_in_line;
   }
}


int analyse_data_from_from_line (char temp_line[255],char searched_phrase[255],unsigned short aray_of_pattern_positions_in_line[255])
{
 int number_of_matches_in_line = 0, matching_letters = 0;
 for(int i = 0; i<(int)strlen(temp_line);i++)
    { 
      matching_letters = 0;
      if(searched_phrase[0] == temp_line[i])
      {   
       ++matching_letters;
        for(int iteration = 1; iteration<(int)strlen(searched_phrase);iteration++)
        {   ++i;  
            if(searched_phrase[iteration]==temp_line[i])++matching_letters;
            else 
            { matching_letters = 0;
              break;
            }
        }
        if(matching_letters==(int)(strlen(searched_phrase)))
        {  ++number_of_matches_in_line;
            for(int i = 0; i < (int)strlen(searched_phrase); i++ ) printf("\b");          
            aray_of_pattern_positions_in_line[number_of_matches_in_line] = i- (int)(strlen(searched_phrase))+1;
            matching_letters = 0;
        
        }
      }
                
    }
   aray_of_pattern_positions_in_line[0]=number_of_matches_in_line;
  return number_of_matches_in_line;  
}

void write_line_in_the_screen(char temp_line[255],char searched_phrase[255],unsigned short aray_of_pattern_positions_in_line[255])
{
  printf("\t\t\t");
  unsigned short written_patterns = 0;
  for(unsigned short int position_in_line = 0; position_in_line < (unsigned short int)strlen(temp_line); ++position_in_line)
  {
    if(written_patterns<aray_of_pattern_positions_in_line[0])
    {
    if(position_in_line == aray_of_pattern_positions_in_line[written_patterns+1])
      {
        printf("\b%c[%dm %s",0x1B,BLUE,searched_phrase);
        printf("%c[%dm",0X1B,0);   
        position_in_line += (unsigned short int)strlen(searched_phrase);
        ++written_patterns;
      }
    }
    printf("%c[%dm" "%c[%dm",0x1B,RED,0x1B,1);
    printf("%c",temp_line[position_in_line]);
    printf("%c[%dm%c[%dm",0X1B,0,0X1B,22);
    //printf("%c[%dm",0X1B,22);
  //   printf("\b");  
  }
  printf("\n");
}

void clear_current_line(char current_line[255])
{
  for(int iteration=0; iteration<(int)strlen(current_line);iteration++)
  {
    current_line[iteration]=' ';
  }
}



void show_line_statistics(unsigned short aray_of_pattern_positions_in_line[255],short line_number)
{
  printf("Matches-line%d=%d ",line_number,aray_of_pattern_positions_in_line[0]);
   
   if(aray_of_pattern_positions_in_line[0]>0)
   {
    printf("patern_on_index:");
   for(unsigned short int i=1; i<=aray_of_pattern_positions_in_line[0];++i)
   {
    printf("%d,",aray_of_pattern_positions_in_line[i]);
   }

   }
   else 
   {
    printf("NO PATTERN");
   }
   printf("\n");
}