#include <stdio.h>
#include <stdlib.h>

#ifdef ONLINE_JUDGE
#define LOG(x, t) printf(#x ": " t, x)
#else
#define LOG(x, t) ((void)0)
#endif

int main()
{
    char* str = "Hello, world!";
    LOG(str, "%s");

    return 0;
}
