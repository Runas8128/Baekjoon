/**
문제
영선이는 총 N개의 정수로 이루어져 있는 배열 A를 가지고 있다.

배열에 적용할 수 있는 연산은 다음과 같다.

A에 있는 수 중 하나를 골라서 K를 더한다.
위의 연산은 사용하고 싶은 만큼 사용할 수 있다.

배열 A가 주어졌을 때, 연산을 적용해서 1부터 N까지의 수가 모두 하나씩 있는 배열을 만들 수 있는지 없는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 배열의 크기 N과 K가 주어진다. (1 ≤ N ≤ 50, 1 ≤ K ≤ 10)

둘째에는 배열 A가 주어진다. 배열 A에 들어있는 수는 50보다 작거나 같은 자연수이다.

출력
연산을 적용해서 1부터 N까지의 수가 모두 하나씩 있는 배열을 만들 수 있으면 1을, 없으면 0을 출력한다.
 */

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N, K; scanf("%d %d", &N, &K);
    int A[N]; for (int i = 0; i < N; i++) scanf("%d", &(A[i]));
    sort(A, A+N);
    bool B[N+1] = { 0, };
    for (int i = 0; i < N; i++) {
        while (A[i] <= N && B[A[i]]) A[i] += K;
        if (A[i] > N) { printf("0"); return 0; }
        B[A[i]] = true;
    }
    printf("1");
    return 0;
}
