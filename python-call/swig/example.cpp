#include "example.hpp"

int fact(int n)
{
    return n <= 0 ? 1 : n * fact(n - 1);
}

int global_var = 0;
void inc_gvar(void)
{
    global_var++;
}
