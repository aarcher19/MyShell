#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define HISTORY_SIZE 100
#define BUFFER_SIZE 1024

char *history[HISTORY_SIZE];
int history_count = 0;

void add_to_history(const char *command){
  if (history_count < HISTORY_SIZE) {
    history[history_count] = strdup(command);
    history_count++;
  } else {
    free(history[0]);
    for (int i  = 1; i < HISTORY_SIZE; i++){
      history[i - 1] = history[i];
    }
    history[HISTORY_SIZE - 1] = strdup(command);
  }
}

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

  if (strlen(buffer) > 0) {
    add_to_history(buffer);
  }
  return buffer;
}


