#include "../includes/my.h"

void execute_commands(char **commands, int num_commands,
    char **path, char **env)
{
    char *token = NULL;

    for (int i = 0; i < num_commands; i++) {
        token = strtok(commands[i], " \t");
        if (token != NULL) {
            allcommand(token, env, path);
        }
    }
}

void prompt_user(void)
{
    if (isatty(0) == 1) {
        my_pwd();
        my_printf("~$>");
    }
}

void execute_commands_from_input(char **path, char **env, char *input)
{
    char *token = NULL;
    char *commands[MAX_ARGS];
    int num_commands = 0;

    num_commands = 0;
    token = strtok(input, ";");
    while (token != NULL && num_commands < MAX_ARGS - 1) {
        commands[num_commands] = token;
        num_commands++;
        token = strtok(NULL, ";");
    }
    commands[num_commands] = NULL;
    execute_commands(commands, num_commands, path, env);
}

void prompt_and_execute_command(char **path, char **env)
{
    ssize_t read;
    char *str = NULL;
    size_t len = 0;

    prompt_user();
    read = getline(&str, &len, stdin);
    if (read != -1 && str[read - 1] == '\n') {
        str[read - 1] = '\0';
        execute_commands_from_input(path, env, str);
    } else if (read == -1) {
        exit(0);
    }
    free(str);
}
