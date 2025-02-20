#include <stdio.h>

void display_help() {
    printf("Welcome to mysh (My Simple Shell)\n");
    printf("Available commands:\n");
    printf("  help      - Show this help message\n");
    printf("  exit      - Exit the shell\n");
    printf("  cd <dir>  - Change directory\n");
    printf("  ls        - List directory contents\n");
    printf("  pwd       - Print current working directory\n");
    printf("  echo <msg> - Print message to console\n");
    printf("You can also run any system command available in /bin.\n");
}
