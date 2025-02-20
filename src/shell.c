#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *read_input() {
  char *buffer = malloc(BUFFER_SIZE);
  if(!buffer){
    perror("malloc failed");
    exit(EXIT_FAILURE);
  }

  if(fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
    free(buffer);
    return NULL;
  }

  buffer[strcspn(buffer, "\n")] = '\0';
  return buffer;
}
