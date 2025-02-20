#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../includes/parser.h"
#include "../includes/help.h"

void execute_command(char *input) {
  char **args = parse_input(input);

  if (args[0] == NULL){
    free(args);
    return;
  }

  if(strcmp(args[0], "exit") == 0) {
    free(args);
    exit(0);
  }

  if (strcmp(args[0], "help") == 0) {  
        display_help();
        free(args);
        return;
    }

  if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "cd: missing argument\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("cd failed");
            }
        }
        free(args);
        return;
    }

  pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("command execution failed");
        }
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
    }

    free(args);
}
