#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 64

char **parse_input(char *input) {
  char **args = malloc(MAX_ARGS * sizeof(char *));
  char *token;
  int index = 0;

  if (!args) {
    perror("malloc failed");
    exit(EXIT_FAILURE);
  }

  token = strtok(input, " ");
  while (token != NULL) {
    args[index++] = token;
    token = strtok(NULL, " ");
  }

  args[index] = NULL;

  return args;
}
