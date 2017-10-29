#include <cassert>
#include <cstdint>
#include <iostream>

extern "C" {

int32_t mult2(int32_t x);

ssize_t find_substr(const char* haystack, const char* needle);

struct DivMod {
    int32_t div;
    int32_t mod;
};

DivMod divmod(int32_t x, int32_t y);

}  // extern "C"

int main(void)
{
    using namespace std;

    cout << "# mult2()" << endl;
    for (int x = 0; x < 10; x++) {
        cout << x << " * 2 = " << mult2(x) << '\n';
        assert(x * 2 == mult2(x));
    }
    cout << endl;

    cout << "# find_substr()" << endl;
    const char* haystack = "po-he";
    const char* needle = "-";
    auto p = find_substr(haystack, needle);
    assert(p == 2);
    cout << p << ", " << (haystack + p) << '\n'
         << endl;

    cout << "# divmod()" << '\n';
    for (int32_t x = 4; x <= 8; x++) {
        for (int32_t y = 1; y <= 4; y++) {
            auto dm = divmod(x, y);
            assert(x == y * dm.div + dm.mod);
            cout << x << " = "
                 << y << " * " << dm.div << " + " << dm.mod << '\n';
        }
    }
    cout << endl;

    return 0;
}
