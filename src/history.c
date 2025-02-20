#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/shell.h"

#define HISTORY_FILE "mysh_history.txt"
extern char *history[];
extern int history_count;

char *get_history_path() {
    static char path[1024];
    snprintf(path, sizeof(path), "%s/bin/%s", getenv("HOME"), HISTORY_FILE);
    return path;
}

void save_history() {
  FILE *file = fopen(get_history_path(), "w");
  if (!file) return;

  for (int i = 0; i < history_count; i++) {
    fprintf(file, "%s\n", history[i]);
  }

  fclose(file);
}

void load_history() {
    FILE *file = fopen(get_history_path(), "r");
    if (!file) return;

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        add_to_history(line);
    }

    fclose(file);
}
