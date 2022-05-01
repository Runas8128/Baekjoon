#include <stdio.h>
#include <stdlib.h>

#ifndef ONLINE_JUDGE
    #define LOG(x, t) printf(#x ": " t "\n", x)
#else
    #define LOG(x, t)
#endif

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* HEAD = NULL;

void insert(int value);
int popMin();
void freeList();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./io/input.txt", "r", stdin);
    freopen("./io/output.txt", "w", stdout);
#endif

    int N, tmp; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        if (tmp == 0) printf("%d\n", popMin());
        else insert(tmp);
    }
    freeList();

    return 0;
}

void insert(int value) {
    // push front
    if (HEAD == NULL || HEAD->value >= value) {
        Node* newHead = (Node*) malloc(sizeof(Node));
        newHead->value = value;
        newHead->next = HEAD;
        HEAD = newHead;
    }

    // insert
    else {
        Node* head = HEAD;
        while (head->next != NULL && head->next->value < value) {
            head = head->next;
        }

        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->value = value;
        newNode->next = head->next;
        head->next = newNode;
    }
}

int popMin() {
    if (HEAD != NULL) {
        int min = HEAD->value;
        Node* head = HEAD->next;
        free(HEAD);
        HEAD = head;
        return min;
    }
    else {
        return 0;
    }
}

void freeList() {
    Node* head = HEAD;

    while(head != NULL) {
        LOG(head->value, "%d");
        head = HEAD->next;
        free(HEAD);
        HEAD = head;
    }
}
