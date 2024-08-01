#include "../includes/my.h"

char *my_getenv(const char *name, char **env)
{
    int name_length = my_strlen(name);

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strcmp(name, env[i]) == 0 && env[i][name_length] == '=') {
            return env[i] + name_length + 1;
        }
    }
    return NULL;
}

void acces_dir(char *token)
{
    if (chdir(token) != 0) {
        if (errno == ENOENT) {
            my_printf("%s%s", token, ": No such file or directory\n");
        }
        if (errno == EACCES) {
            my_printf("%s%s", token, ": Permission denied.");
        }
        if (errno == ENOTDIR) {
            my_printf("%s%s", token, ": Not a directory.\n");
        }
    }
}

void change_directory(char *token, char **env)
{
    if (my_strcmp(token, "cd ~ ") == 0) {
        chdir(my_getenv("HOME", env));
    }
    if (my_strcmp(token, "-") == 0) {
        chdir(my_getenv("OLDPWD", env));
        my_setenv("OLDPWD", my_getenv("PWD", env), env);
        my_setenv("PWD", getcwd(NULL, 0), env);
    } else {
        acces_dir(token);
        my_setenv("OLDPWD", my_getenv("PWD", env), env);
        chdir(token);
    }
}

void built_in_cd(char *token, char **env)
{
    if (token != NULL) {
        change_directory(token, env);
    } else {
        my_setenv("OLDPWD", my_getenv("PWD", env), env);
        chdir(my_getenv("HOME", env));
        my_setenv("PWD", getcwd(NULL, 0), env);
    }
}
