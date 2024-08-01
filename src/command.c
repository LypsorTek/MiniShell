#include "../includes/my.h"

static int other_command(char *token, char **env, char **path)
{
    if (my_strcmp(token, "cd") == 0) {
        path = strtok(NULL, " \t");
        built_in_cd(path, env);
        return 1;
    }
    if (my_strcmp(token, "setenv") == 0) {
        path = strtok(NULL, " \t");
        my_setenv(path, strtok(NULL, " "), env);
        return 1;
    }
    if (my_strcmp(token, "unsetenv") == 0) {
        path = strtok(NULL, " \t");
        my_unsetenv(path, env);
        return 1;
    }
    if (my_strcmp(token, "env") == 0) {
        my_env(env, token);
        return 1;
    }
    return 0;
}

void allcommand(char *token, char **env, char **path)
{
    if (other_command(token, env, path) == 1) {
        return;
    } else {
        execute_command(token, path, env);
    }
}

void line_formatting(char *command, char **arguments)
{
    int i = 0;

    arguments[i] = command;
    while (arguments[i] != NULL) {
        i++;
        arguments[i] = strtok(NULL, " \t");
    }
}

int error_gestion(char *command_path)
{
    if (command_path == NULL) {
        return 84;
    }
    return (0);
}

void process_command(char *command, char **path, char **env)
{
    char *arguments[100];
    char *command_path = NULL;
    char *path_command = NULL;

    error_gestion(command);
    line_formatting(command, arguments);
    for (int j = 0; path[j] != NULL; j++) {
        path_command = malloc(my_strlen(path[j]) +
        my_strlen(arguments[0]) + 2);
        my_strcpy(path_command, path[j]);
        my_strcat(path_command, arguments[0]);
        if (access(path_command, X_OK) == 0) {
            command_path = path_command;
            break;
        }
    }
    handle_redirection(arguments);
    if (execve(command_path, arguments, env) == -1) {
        my_printf("%s%s", command, ": Command not found.\n");
    }
}

void execute_command(char *str, char **path, char **env)
{
    pid_t pid = fork();

    if (my_strcmp2(str, "exit") == 0) {
        exit(0);
    }
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        process_command(str, path, env);
    } else {
        wait(NULL);
    }
}
