
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_new_lib.h"
FILE *myfile;
int check_number_of_arguments(int argc)
{
 if(argc!=NUMBER_OF_EXPECTED_EXT_ARGS)                                                                                                                
    {
      return false;                                                                                    
    }                                                                                                             
 else                                                               
 {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_new_lib.h"

int check_number_of_arguments(int argc)
{
 if(argc!=NUMBER_OF_EXPECTED_EXT_ARGS)                                                                                                                
    {
      return false;                                                                                    
    }                                                                                                             
 else                                                               
 {
   return true;
 }
}
       
int check_if_file_exists(char path_to_file[255]) 
{                                                          // remeber arg no.1 must be path to existing file or name of file in project enviroment
      if((myfile = fopen(path_to_file,"r")) == NULL)                   //check if file exist if no display a message to user
        {
          return false;
        } 
        else
        {
        fclose(myfile);
        return true;  
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
        {   
          ++i;    
          if(searched_phrase[iteration]==temp_line[i])++matching_letters;
          else 
          { matching_letters = 0;
            break;
          }
        }
        if(matching_letters==(int)(strlen(searched_phrase)))
        {  ++number_of_matches_in_line;     
            aray_of_pattern_positions_in_line[number_of_matches_in_line] = i- (int)(strlen(searched_phrase))+1;
            matching_letters = 0;
        }
      }
                
    }
  aray_of_pattern_positions_in_line[0]=number_of_matches_in_line;
  return number_of_matches_in_line;  
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
   if(aray_of_pattern_positions_in_line[0]>0)
   {
    printf("Matches-line%d=%d ",line_number,aray_of_pattern_positions_in_line[0]);
    printf("patern_on_index:");
      for(unsigned short int i=1; i<=aray_of_pattern_positions_in_line[0];++i)
      {
      printf("%d,",aray_of_pattern_positions_in_line[i]);
      }
      printf("\n");
   }
   
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_new_lib.h"

int check_number_of_arguments(int argc)
{
 if(argc!=NUMBER_OF_EXPECTED_EXT_ARGS)                                                                                                                
    {
      return false;                                                                                    
    }                                                                                                             
 else                                                               
 {
   return true;
 }
}
       
int check_if_file_exists(char path_to_file[255]) 
{                                                          // remeber arg no.1 must be path to existing file or name of file in project enviroment
      if((myfile = fopen(path_to_file,"r")) == NULL)                   //check if file exist if no display a message to user
        {
          return false;
        } 
        else
        {
        fclose(myfile);
        return true;  
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
        {   
          ++i;    
          if(searched_phrase[iteration]==temp_line[i])++matching_letters;
          else 
          { matching_letters = 0;
            break;
          }
        }
        if(matching_letters==(int)(strlen(searched_phrase)))
        {  ++number_of_matches_in_line;     
            aray_of_pattern_positions_in_line[number_of_matches_in_line] = i- (int)(strlen(searched_phrase))+1;
            matching_letters = 0;
        }
      }
                
    }
  aray_of_pattern_positions_in_line[0]=number_of_matches_in_line;
  return number_of_matches_in_line;  
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
   if(aray_of_pattern_positions_in_line[0]>0)
   {
    printf("Matches-line%d=%d ",line_number,aray_of_pattern_positions_in_line[0]);
    printf("patern_on_index:");
      for(unsigned short int i=1; i<=aray_of_pattern_positions_in_line[0];++i)
      {
      printf("%d,",aray_of_pattern_positions_in_line[i]);
      }
      printf("\n");
   }
   
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_new_lib.h"

int check_number_of_arguments(int argc)
{
 if(argc!=NUMBER_OF_EXPECTED_EXT_ARGS)                                                                                                                
    {
      return false;                                                                                    
    }                                                                                                             
 else                                                               
 {
   return true;
 }
}
       
int check_if_file_exists(char path_to_file[255]) 
{                                                          // remeber arg no.1 must be path to existing file or name of file in project enviroment
      if((myfile = fopen(path_to_file,"r")) == NULL)                   //check if file exist if no display a message to user
        {
          return false;
        } 
        else
        {
        fclose(myfile);
        return true;  
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
        {   
          ++i;    
          if(searched_phrase[iteration]==temp_line[i])++matching_letters;
          else 
          { matching_letters = 0;
            break;
          }
        }
        if(matching_letters==(int)(strlen(searched_phrase)))
        {  ++number_of_matches_in_line;     
            aray_of_pattern_positions_in_line[number_of_matches_in_line] = i- (int)(strlen(searched_phrase))+1;
            matching_letters = 0;
        }
      }
                
    }
  aray_of_pattern_positions_in_line[0]=number_of_matches_in_line;
  return number_of_matches_in_line;  
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
   if(aray_of_pattern_positions_in_line[0]>0)
   {
    printf("Matches-line%d=%d ",line_number,aray_of_pattern_positions_in_line[0]);
    printf("patern_on_index:");
      for(unsigned short int i=1; i<=aray_of_pattern_positions_in_line[0];++i)
      {
      printf("%d,",aray_of_pattern_positions_in_line[i]);
      }
      printf("\n");
   }
   
}
   return true;
 }
}
       
int check_if_file_exists(char path_to_file[255]) 
{                                                          // remeber arg no.1 must be path to existing file or name of file in project enviroment
      if((myfile = fopen(path_to_file,"r")) == NULL)                   //check if file exist if no display a message to user
        {
          return false;
        } 
        else
        {
        fclose(myfile);
        return true;  
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
        {   
          ++i;    
          if(searched_phrase[iteration]==temp_line[i])++matching_letters;
          else 
          { matching_letters = 0;
            break;
          }
        }
        if(matching_letters==(int)(strlen(searched_phrase)))
        {  ++number_of_matches_in_line;     
            aray_of_pattern_positions_in_line[number_of_matches_in_line] = i- (int)(strlen(searched_phrase))+1;
            matching_letters = 0;
        }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_new_lib.h"

int check_number_of_arguments(int argc)
{
 if(argc!=NUMBER_OF_EXPECTED_EXT_ARGS)                                                                                                                
    {
      return false;                                                                                    
    }                                                                                                             
 else                                                               
 {
   return true;
 }
}
       
int check_if_file_exists(char path_to_file[255]) 
{                                                          // remeber arg no.1 must be path to existing file or name of file in project enviroment
      if((myfile = fopen(path_to_file,"r")) == NULL)                   //check if file exist if no display a message to user
        {
          return false;
        } 
        else
        {
        fclose(myfile);
        return true;  
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
        {   
          ++i;    
          if(searched_phrase[iteration]==temp_line[i])++matching_letters;
          else 
          { matching_letters = 0;
            break;
          }
        }
        if(matching_letters==(int)(strlen(searched_phrase)))
        {  ++number_of_matches_in_line;     
            aray_of_pattern_positions_in_line[number_of_matches_in_line] = i- (int)(strlen(searched_phrase))+1;
            matching_letters = 0;
        }
      }
                
    }
  aray_of_pattern_positions_in_line[0]=number_of_matches_in_line;
  return number_of_matches_in_line;  
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
   if(aray_of_pattern_positions_in_line[0]>0)
   {
    printf("Matches-line%d=%d ",line_number,aray_of_pattern_positions_in_line[0]);
    printf("patern_on_index:");
      for(unsigned short int i=1; i<=aray_of_pattern_positions_in_line[0];++i)
      {
      printf("%d,",aray_of_pattern_positions_in_line[i]);
      }
      printf("\n");
   }
   
}
      }
                
    }
  aray_of_pattern_positions_in_line[0]=number_of_matches_in_line;
  return number_of_matches_in_line;  
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
   if(aray_of_pattern_positions_in_line[0]>0)
   {
    printf("\t\tMatches-line%d=%d ",line_number,aray_of_pattern_positions_in_line[0]);
    printf("patern_on_index:");
      for(unsigned short int i=1; i<=aray_of_pattern_positions_in_line[0];++i)
      {
      printf("%d,",aray_of_pattern_positions_in_line[i]);
      }
      printf("\n");
   }
   
}
