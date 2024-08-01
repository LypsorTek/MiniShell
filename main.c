#include "includes/my.h"

void my_pwd(void)
{
    char cwd[1024];

        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            my_printf("%s", cwd);
        }
}

void my_env(char **env, char *token)
{
    if (my_strcmp(token, "env") == 0) {
        for (int i = 0; env[i] != NULL; i++) {
            my_printf("%s\n", env[i]);
        }
    }
}

int main(int ac, char **av, char **env)
{
    char *path[2];

    ac = ac;
    av = av;
    path[0] = "/bin/";
    path[1] = NULL;
    while (1) {
        prompt_and_execute_command(path, env);
    }
    return 0;
}
