#include <stdio.h>
#include <stdlib.h>

#ifndef ONLINE_JUDGE
    #define LOG(x, t) printf(#x ": " t, x)
#else
    #define LOG(x, t)
#endif

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./io/input.txt", "r", stdin);
    freopen("./io/output.txt", "w", stdout);
#endif

    /* WRITE YOUR CODE HERE */
    char* str = "Hello, world!";
    LOG(str, "%s");

    return 0;
}
