#include "../../includes/my.h"


void fonctionn(va_list args)
{
    int *countn = 0;
    int *value = va_arg(args, int *);

    *value = *countn;
}
