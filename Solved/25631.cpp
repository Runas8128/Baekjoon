/**
문제
마트료시카는 속이 비어있는 인형이다. 성빈이는 N개의 마트료시카를 가지고 있다. 
i번째 마트료시카의 크기는 ai이고, 마트료시카 속은 모두 비어있다.

성빈이는 남아 있는 마트료시카 중에서 i번째와 j번째 (i < j) 마트료시카를 고른 뒤에 
i번째 마트료시카를 j번째 마트료시카 속에 넣을 수 있다.
단, j번째 마트료시카의 속이 비어있어야 하고,
i번째 마트료시카보다 j번째 마트료시카가 더 커야 한다.
합친 후에는 남아 있는 마트료시카의 개수가 한 개 줄어든다.

성빈이는 마트료시카를 최대한 합쳐서 정리하려고 한다.
성빈이가 마트료시카를 잘 합친다면 남아 있는 마트료시카의 최소 개수는 얼마일까?

입력
첫째 줄에 마트료시카의 개수 N(1<=N<=1000)이 주어진다.

둘째 줄에 정수 a1, a2, ..., aN이 주어진다. 
ai(1 <= a_i <= 10^9)는 i번째 마트료시카의 크기이다.

출력
남아있는 마트료시카의 최소 개수를 출력한다.
 */

#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

int main() {
    int N; scanf("%d", &N);
    int size[N]; for (int i = 0; i < N; i++) scanf("%d", &(size[i]));
    sort(size, size+N);
    
    list<int> li[N];
    li[0].push_back(size[0]);
    int count = 1;

    for (int i = 1; i < N; i++) {
        bool pushed = false;
        for (int j = 0; j < count; j++) {
            if (li[j].back() < size[i]) {
                li[j].push_back(size[i]);
                pushed = true;
                break;
            }
        }
        if (!pushed) li[count++].push_back(size[i]);
    }
    printf("%d", count);

    return 0;
}
