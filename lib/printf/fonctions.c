#include "../../includes/my.h"

void fonctions(va_list args)
{
    my_putstr(va_arg(args, const char *));
}
