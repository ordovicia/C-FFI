#include <stdint.h>
#include <stdio.h>

extern "C" {
int32_t mult2(int32_t x);
ssize_t find_substr(const char* haystack, const char* needle);
}

int main(void)
{
    for (int x = 0; x < 10; x++)
        printf("%d * 2 = %d\n", x, mult2(x));

    const char* haystack = "po-he";
    const char* needle = "-";
    auto p = find_substr(haystack, needle);
    if (p > 0) {
        printf("%ld, \"%s\"\n", p, haystack + p);
    } else {
        printf("not found\n");
    }

    return 0;
}
