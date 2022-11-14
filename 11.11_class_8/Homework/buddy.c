#include <stdio.h>
#include <math.h>

typedef struct node {
    int pos;
    int size;//k
    int id;//0 for free
    int nxt;//0 for end
} node;

node buddy[3100005];
int n, q, cnt = 0, head;

node *newNode() {
    cnt++;
    buddy[cnt].pos = cnt;
    return &buddy[cnt];
}

void init() {
    node *now = newNode();
    head = now->pos;
    now->size = n;
    now->nxt = 0;
    now->id = 0;
    return;
}

int find(int k, int id) {
    for (int i = head; i; i = buddy[i].nxt) {
        if (buddy[i].size == k && (!buddy[i].id)) {
            buddy[i].id = id;
            return 0;
        }
    }
    return 1;
}

void separate(int k) {
    for (int i = head; i; i = buddy[i].nxt) {
        if (buddy[i].size > k && (!buddy[i].id)) {
            node *now = newNode();
            buddy[i].size--;
            now->size = buddy[i].size;
            now->nxt = buddy[i].nxt;
            buddy[i].nxt = now->pos;
            return;
        }
    }
}

void memAllocate(int k, int id) {
    while (1) {
        if (!find(k, id)) {
            break;
        }
        separate(k);
    }
}

void query() {
    printf("%d\n", cnt);
    for (int i = head; i; i = buddy[i].nxt) {
        printf("%d ", buddy[i].id);
    }
    printf("\n");
}

int main() {
    scanf("%d%d", &n, &q);
    init();
    for (int i = 1; i <= q; i++) {
        getchar();
        char ch = getchar();
        if (ch == 'A') {
            int id, size;
            scanf("%d%d", &id, &size);
            memAllocate(ceil(log2(size)), id);
        } else {
            query();
        }
    }

    return 0;
}