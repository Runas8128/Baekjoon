#include <stdio.h>
#include <stdlib.h>

#ifndef ONLINE_JUDGE
    #define LOG(x, t) printf(#x ": " t, x)
    #define LOGS(s) printf(s "\n")
#else
    #define LOG(x, t)
    #define LOGS(s)
#endif

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./io/input.txt", "r", stdin);
    freopen("./io/output.txt", "w", stdout);
#endif

    unsigned int x, y, w, s, rst;
    scanf("%u %u %u %u", &x, &y, &w, &s);

    if (s >= 2 * w) {
        LOGS("s >= 2 * w");
        rst = (x + y) * w;
    }
    else {
        if (x >= y) {
            LOGS("s < 2 * w, x >= y");
            rst = y * s + (x - y) * w;
        }
        else {
            LOGS("s < 2 * w, x < y");
            rst = x * s + (y - x) * w;
        }
    }
    printf("%u", rst);

    return 0;
}
