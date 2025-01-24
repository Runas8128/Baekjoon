#include <cstdio>

using namespace std;

struct Node {
    int x;
    int y;
    int depth;
    Node* next;
};

int main() {
    int m, n, **status, depth, maxDepth=0, all, count=0;
    Node *head = NULL, *tail = NULL, *garbage = NULL;

    scanf("%d %d", &m, &n);
    status = new int*[n];
    all = m * n;

    for (int i = 0; i < n; i++) {
        status[i] = new int[m];
        for (int j = 0; j < m; j++) {
            scanf("%d", &(status[i][j]));
            if (status[i][j] == -1) all--;
            if (status[i][j] == 1) {
                if (tail) tail = tail->next = new Node { j, i, 0, NULL };
                else tail = head = new Node { j, i, 0, NULL };
                status[i][j] = 0;
            }
        }
    }

    while (head) {
        if (!(
            head->x < 0 || head->x >= m ||
            head->y < 0 || head->y >= n ||
            status[head->y][head->x]
        )) {
            if (head->depth > maxDepth) maxDepth = head->depth;
            status[head->y][head->x] = 1;
            count++;
            tail = tail->next = new Node { head->x, head->y-1, head->depth+1 };
            tail = tail->next = new Node { head->x-1, head->y, head->depth+1 };
            tail = tail->next = new Node { head->x+1, head->y, head->depth+1 };
            tail = tail->next = new Node { head->x, head->y+1, head->depth+1 };
        }
        garbage = head;
        head = head->next;
        delete garbage;
    }

    printf("%d", count == all ? maxDepth : -1);

    return 0;
}
