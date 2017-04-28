#include <stdint.h>
#include <stdio.h>

int32_t mult2(int32_t);

int main(void)
{
    for (int x = 0; x < 10; x++)
        printf("%d * 2 = %d\n", x, mult2(x));

    return 0;
}
