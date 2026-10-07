#include <stdlib.h>
#include <limits.h>

int reverse(int x) {
    long r = 0;
    long n = (x < 0) ? -(long)x : (long)x;   // safe: widen before negating

    while (n > 0) {
        r = (r * 10) + (n % 10);
        n /= 10;
    }

    if (x < 0) {
        r = -r;
    }

    if (r > INT_MAX || r < INT_MIN) {
        return 0;
    }

    return (int)r;
}
