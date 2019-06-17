#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int parseACommand(char option, int argc, char **argv);
int parseBCommand();
int validateCommand();

int main(int argc, char **argv)
{
    char* command;
    char* paramter1;
    char* restParameters;
    int option;
    
    while((option = getopt(argc, argv, "ab:")) != -1) {
      printf("OPTION IS %c", option);
      
      switch(option) {
       case 'a':
        parseACommand(option, argc, argv);
        break;
       case 'b':
        parseBCommand();
        break;
       case '?':
        printf("Call function for help \n");
        break;
       default:
        printf("Invalid command hence aborting \n");
        abort();
        break;
      }
      
      if (validateCommand() != 0){
          return 1;
      }
    }

    return 0;
}

int parseACommand(char option, int argc, char **argv) {
    char* paramter1;
    char restParameters[1000];
    int paramter1Found = 0;
    int secondParameter =0;
    int pos = 0;
    
    printf("A command parsing. OptArg %c. \n", option);
    
    for( ;optind < argc && *argv[optind] != '-'; optind++) {
        if (paramter1Found == 0) {
          paramter1 = argv[optind];    
          paramter1Found = 1;
        } else {
           pos = sprintf(&restParameters[pos], "%s ", argv[optind]);
        }       
    }
    
    restParameters[strlen(restParameters) - 1] = '\0';
    
    printf("Pos %d optopt is %c \n", pos, optopt);
    
    printf("paramter1 %s \n", paramter1);
    
    printf("restParameters %s and length is %d\n", restParameters, strlen(restParameters));
} 

int parseBCommand() {
    printf("B command parsing. OptArg %c", optopt);
}

int validateCommand() {
    //printf("Check if command follow expected structure. If no then return 1 else return 0");
    
    return 0;
}


