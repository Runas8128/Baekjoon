#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int value;
    struct _Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} SLL;

Node* make(int value) {
    Node* d = malloc(sizeof(Node));
    d->value = value;
    d->next = NULL;
    return d;
}

void push(SLL *sll, int value) {
    sll->tail->next = make(value);
    sll->tail = sll->tail->next;
}

int main() {
    int n, k, d=0, v, map[200000] = {0,}, xs[3] = {0,}, i, x;
    SLL sll;

    scanf("%d %d", &n, &k);
    if (n == k) {
        printf("0");
        return 0;
    }
    
    sll.head = sll.tail = make(n);
    sll.head->next = sll.tail;
    map[n] = 1;
    while (sll.head) {
        d = sll.head->value;
        xs[0] = d-1; xs[1] = d+1; xs[2] = d*2;
        for (i=0; i<3; i++) {
            x = xs[i];
            if (x == k) {
                printf("%d", map[d]);
                return 0;
            }
            if (0 <= x && x <= 200000 && !map[x]) {
                map[x] = map[d]+1;
                push(&sll, x);
            }
        }
        sll.head = sll.head->next;
    }
    printf("-1");
    return 0;
}
