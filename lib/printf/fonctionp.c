#include "../../includes/my.h"

void fonctionp(va_list args)
{
    my_putstr("0x");
    my_put_nbr(va_arg(args, int));
}
