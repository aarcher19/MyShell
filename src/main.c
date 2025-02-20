#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../includes/shell.h"
#include "executor.h"
#include "../includes/history.h"

int main() 
{
  char *input;
  char cwd[1024];
  
  load_history();

  while (1) {
     if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd() error");
            strcpy(cwd, "unknown"); // Fallback in case of an error
        }

     printf("mysh:%s$ ", cwd);
     fflush(stdout);
 
    input = read_input();
    if(input == NULL) {
      printf("\n");
      break;
    }
    execute_command(input);
    free(input);
  }
  save_history();
}
