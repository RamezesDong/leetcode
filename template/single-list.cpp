#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int head, node[N], ne[N], idx;
// head is the head of linked list, node and ne is the node value and point
// idx indicates how many nodes have used

void init() {
    head = -1;
    idx = 0;
}

// insert val to the head 
void insert(int val) {
    node[idx] = val;
    ne[idx] = head;
    head = idx++;
}

// remove the head node
void remove() {
    head = ne[head];
}

//remove the k's inserted num
void remove(int k) {
    if (k == 0) {
        remove();
    }
    int removed = ne[k - 1];
    ne[k - 1] = ne[removed];
}

// insert a new node after the k's inserted num
void insert(int k, int val) {
    int inserted = ne[k - 1];
    node[idx] = val;
    ne[idx] = inserted;
    ne[k - 1] = idx;
    idx ++;
}

int main() {
    int m;
    cin >> m;
    char op;
    int k, val;
    init();
    while (m --) {
        cin >> op;
        switch (op)
        {
        case 'H':
            cin >> val;
            insert(val);
            break;
        case 'D':
            cin >> k;
            remove(k);
            break;
        case 'I':
            cin >> k >> val;
            insert(k ,val);
            break;
        }
    }
    int now = head;
    while (now != -1) {
        cout << node[now] << " ";
        now = ne[now];
    }
    return 0;
}