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

    int set[7][10] = { 0, }, buf = 0, maxSet = -1;

    while ((buf = getchar()) != EOF) {
        buf -= '0';
        for (int i = 0; i < 7; i++) {
            if (set[i][buf] == 0) {
                set[i][buf] = 1;
                if (i > maxSet) maxSet = i;
                break;
            }
            if (buf == 6 && set[i][9] == 0) {
                set[i][9] = 1;
                if (i > maxSet) maxSet = i;
                break;
            }
            if (buf == 9 && set[i][6] == 0) {
                set[i][6] = 1;
                if (i > maxSet) maxSet = i;
                break;
            }
        }
    }
    printf("%d", maxSet + 1);

    return 0;
}
