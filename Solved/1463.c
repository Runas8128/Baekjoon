#include <stdio.h>
#include <stdlib.h>

#ifndef ONLINE_JUDGE
    #define LOG(x, t) printf(#x ": " t, x)
    #define LOG_ls(ls, len) printf(#ls ": [ ");\
    for (int _index = 0; _index < len; _index++) {\
        printf("%d ", ls[_index]);\
    }\
    printf("]\n");
#else
    #define LOG(x, t)
    #define LOG_ls(ls, len)
#endif

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./io/input.txt", "r", stdin);
    freopen("./io/output.txt", "w", stdout);
#endif

    /* WRITE YOUR CODE HERE */

    int N, *arr;
    scanf("%d", &N);
    arr = calloc(N, sizeof(int));
    arr[0] = 0; // 1 -> 0

    for (int i = 1; i < N; i++) {
        arr[i] = arr[i - 1];

        if ((i+1) % 2 == 0) {
            if (arr[(i+1)/2-1] < arr[i]) arr[i] = arr[(i+1)/2-1];
        }
        if ((i+1) % 3 == 0) {
            if (arr[(i+1)/3-1] < arr[i]) arr[i] = arr[(i+1)/3-1];
        }
        arr[i]++;
    }

    printf("%d", arr[N-1]);

    free(arr);
    return 0;
}
