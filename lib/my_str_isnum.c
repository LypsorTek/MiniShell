char *my_str_isnum(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return ("false");
        i++;
    }
    return ("true");
}
