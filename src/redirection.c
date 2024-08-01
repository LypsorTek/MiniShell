#include "../includes/my.h"

void error_dup2(int fd)
{
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
}

void right_redirection(char **arguments)
{
    int fd;

    for (int i = 0; arguments[i] != NULL; i++) {
        if (my_strcmp(arguments[i], ">") == 0 && arguments[i + 1] != NULL) {
            fd = open(arguments[i + 1], O_WRONLY | O_CREAT, 300);
            error_dup2(fd);
            arguments[i] = NULL;
            arguments[i + 1] = NULL;
            break;
        }
        if (my_strcmp(arguments[i], ">>") == 0 &&
            arguments[i + 1] != NULL) {
            fd = open(arguments[i + 1], O_WRONLY | O_CREAT | O_APPEND, 300);
            error_dup2(fd);
            arguments[i] = NULL;
            arguments[i + 1] = NULL;
            break;
        }
    }
}

void handle_redirection(char **arguments)
{
    int fd;

    right_redirection(arguments);
    for (int i = 0; arguments[i] != NULL; i++) {
        if (my_strcmp(arguments[i], "<") == 0 && arguments[i + 1] != NULL) {
            fd = open(arguments[i + 1], O_RDONLY);
            error_dup2(fd);
            arguments[i] = NULL;
            arguments[i + 1] = NULL;
            break;
        }
    }
}
