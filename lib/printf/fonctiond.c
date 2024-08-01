#include "../../includes/my.h"

void fonctiond(va_list args)
{
    my_put_nbr(va_arg(args, int));
}
