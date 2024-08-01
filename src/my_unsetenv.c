#include "../includes/my.h"

void deletenv(char **env, int z)
{
    int j;

    for (j = z; env[j] != NULL; j++) {
        env[j] = env[j + 1];
    }
}

int my_unsetenv(char *name, char **env)
{
    int i = 0;

    if (name == NULL) {
        return 84;
    }
    while (env[i] != NULL) {
        if (my_strcmp(env[i], name) == 0) {
            deletenv(env, i);
            break;
        }
        i++;
    }
    return (0);
}
