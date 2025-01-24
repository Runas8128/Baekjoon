#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

struct Node {
    int x;
    int y;
    int d;
    Node* next;
};

int main() {
    int n, m, **info, **board;
    Node *head, *tail, *garbage;

    scanf("%d %d", &n, &m);

    info = new int*[n];
    board = new int*[n];

    for (int i = 0; i < n; i++) {
        info[i] = new int[m];
        board[i] = new int[m];

        for (int j = 0; j < m; j++) {
            scanf("%d", &(info[i][j]));
            board[i][j] = -info[i][j];
            if (info[i][j] == 2) {
                head = tail = new Node { j, i, 0, NULL };
                info[i][j] = 1;
            }
        }
    }

    while (head) {
        if (!(head->x < 0 || head->x >= m ||
            head->y < 0 || head->y >= n ||
            info[head->y][head->x] != 1)) {
            if (board[head->y][head->x] < 0) {
                board[head->y][head->x] = head->d;
                info[head->y][head->x] = 2;
            }

            tail->next = new Node {head->x, head->y-1, head->d+1}; tail = tail->next;
            tail->next = new Node {head->x-1, head->y, head->d+1}; tail = tail->next;
            tail->next = new Node {head->x+1, head->y, head->d+1}; tail = tail->next;
            tail->next = new Node {head->x, head->y+1, head->d+1}; tail = tail->next;
        }


        garbage = head;
        head = head->next;
        delete garbage;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }

    return 0;
}
