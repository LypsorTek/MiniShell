#include "../includes/my.h"

static int checkifisalnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '_' && str[i] != '-' && str[i] != '.' && str[i] != '/' &&
            str[i] != '=' &&
            (str[i] < '0' || str[i] > '9') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < 'a' || str[i] > 'z')) {
            return 84;
        }
    }
    return 0;
}

void changevalue(char *value, char *new_value)
{
    char *valueenv = my_strchr(value, '=');

    if (valueenv != NULL) {
        valueenv++;
        my_strcpy(valueenv, new_value);
    }
}

int error_gestionn(char *name, char *value, char **env)
{
    if (name == NULL) {
        for (int i = 0; env[i] != NULL; i++) {
            my_printf("%s\n", env[i]);
        }
        return 84;
    }
    if (checkifisalnum(name) == 84) {
        my_printf("setenv: Variable name must");
        my_printf(" contain alphanumeric characters.\n");
        return 84;
    }
    return 0;
}

void update_env(char *name, char *value, char **env, int i)
{
    int name_len = my_strlen(name);
    int value_len = my_strlen(value);

    env[i] = (char *)malloc(name_len + value_len + 2);
    my_strcpy(env[i], name);
    env[i][name_len] = '=';
    my_strcpy(env[i] + name_len + 1, value);
    env[i + 1] = NULL;
}

void my_setenv(char *name, char *value, char **env)
{
    int i = 0;

    if (error_gestionn(name, value, env) == 84) {
        return;
    }
    while (env[i] != NULL) {
        if (my_strcmp(env[i], name) == 0) {
            changevalue(env[i], value);
            return;
        }
        i++;
    }
    if (value == NULL) {
        update_env(name, "", env, i);
    } else if (value != NULL) {
    update_env(name, value, env, i);
    }
}
