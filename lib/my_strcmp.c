#include "../includes/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] && s2[j]) {
        if (s1[i] != s2[j])
            return (s1[i] - s2[j]);
        i++;
        j++;
    }
    return (0);
}

int my_strcmp2(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] && s2[j]) {
        if (s1[i] != s2[j])
            return (s1[i] - s2[j]);
        i++;
        j++;
    }
    if (my_strlen(s1) != my_strlen(s2)) {
        return 1;
    }
    return (0);
}
