#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../includes/shell.h"
#include "executor.h"
#include "../includes/history.h"
#include <readline/readline.h>
#include <readline/history.h>

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

    char prompt[1050];
    input = readline(prompt);

    if(input == NULL) {
      printf("\n");
      break;
    }

     if (strlen(input) > 0) {
            add_history(input);  // Add to history
            add_to_history(input);  // Store in our custom history
      }

    execute_command(input);
    free(input);
    save_history();
  }
  
}
