/*
 * A script interpreter cannot be another script. Hence this tiny C wrapper
 * that forwards fsh to fsh.py, so you can use #!/usr/bin/fsh as shbang for
 * your fsh scripts.
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp) {
    char *buf = malloc(strlen(argv[0]) + 4);
    strcpy(buf, argv[0]);
    strcat(buf + strlen(buf), ".py");
    execve(buf, argv, envp);
    perror("exec failed:");
    return 1;
}
