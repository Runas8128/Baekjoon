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

    int A, B, N, rst=0;
    scanf("%d %d %d", &A, &B, &N);

    for (int cnt=0; cnt <= N; cnt++) {
        rst = A / B;
        A = (A - B * rst) * 10;
    }
    printf("%d", rst);

    return 0;
}
