/**
도시 N개, C[0] -> C[N-1] / 길이 단위 km
초기 기름 0L -> 무조건 기름 넣고 출발 // 기름통 크기 무제한
연비 1km/L, 가격 단위 원

[in]
>>> N // N <= 10^6
>>> d1 d2 ... dn-1 // dk = C[0]<->C[k] 거리, 1 <= dk <= 10^9 // C[k-1] <-> C[k] = dk - d(k-1)
>>> p0 p1 ... pn-1 // pk = C[k] 기름 1L 가격, 1 <= pk <= 10^9

[out]
C[N-1]까지 가는 최소비용
 */

#include <cstdio>
using namespace std;

int main() {
    int N; scanf("%d", &N);
    unsigned long long D[N]; D[0] = 0;
    int P[N], d;
    for (int i = 1; i < N; i++) { scanf("%d", &d); D[i] = D[i-1] + d; }
    for (int i = 0; i < N; i++) scanf("%d", &(P[i]));
    
    unsigned long long total = 0;
    int begin = 0, end = 0;
    while (begin < N-1) {
        while (end < N-1 && P[begin] <= P[end]) end++;
        total += (D[end] - D[begin]) * P[begin];
        begin = end;
    }

    printf("%llu", total);
    
    return 0;
}
