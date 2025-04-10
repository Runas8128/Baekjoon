/**
문제
큰 방에 N개의 풍선이 떠있다. 풍선들은 왼쪽부터 오른쪽까지 일렬로 있다.
진솔이는 화살 가지고 노는 것과 사냥 연습하는 것을 좋아한다.
진솔이는 화살을 왼쪽에서 오른쪽으로 쏜다.
높이는 임의로 선택한다.
화살은 선택된 높이 H에서 풍선을 마주칠 때까지 왼쪽에서 오른쪽으로 이동한다.
화살이 풍선을 마주치는 순간, 풍선은 터지고 사라진다.
화살은 계속해서 가던길을 가는데 높이는 1 줄어든다.
그러므로 만약 화살이 높이 H에서 이동 중이었다면 풍선을 터트린 후에는 높이가 H-1이 된다.

우리의 목표는 모든 풍선을 터트리되 가능한한 적은 화살을 사용하는 것이다.

입력
첫 번째 줄에는 정수 N(1 ≤ N ≤ 1 000 000)이 들어온다.

두 번째 줄에는 배열 Hi가 N개 들어온다.

각각의 Hi(1 ≤ Hi ≤ 1 000 000)는 i번째 풍선의 높이에 해당하며 왼쪽에서 오른쪽으로 나열되는 순서이다.

출력
첫 번째 줄 한줄에 최소한 필요한 화살의 개수를 출력한다.
 */

#include <cstdio>
using namespace std;

int main() {
    int N; scanf("%d", &N);
    int H[N]; for (int i = 0; i < N; i++) scanf("%d", &(H[i]));
    int hNow = 0, tarIdx = 0, aCnt = 0;

    while (true) {
        while (tarIdx < N && !H[tarIdx]) tarIdx++;
        if (tarIdx == N) break;
        
        aCnt++;
        hNow = H[tarIdx];
        for (int i = tarIdx; i < N && hNow; i++) {
            if (H[i] == hNow) {
                H[i] = 0;
                hNow--;
            }
        }
    }

    printf("%d", aCnt);
    return 0;
}
