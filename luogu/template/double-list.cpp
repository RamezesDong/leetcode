#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
int  node[N], pr[N] ,ne[N], idx;
// there is no head in double-list 
// node and ne is the node value and point
// pr is the prev node point
// idx indicates how many nodes have used

void init() {
    ne[0] = 1, pr[1] = 0; // pseudo head and tail
    idx = 2;
}

// insert val to the head 
void insert_head(int val) {
    node[idx] = val;
    pr[idx] = 0;
    ne[idx] = ne[0];
    ne[0] = idx;
    pr[ne[idx]] = idx;
    idx++;
}

void insert_tail(int val) {
    node[idx] = val;
    ne[idx] = 1;
    pr[idx] = pr[1];
    pr[1] = idx;
    ne[pr[idx]] = idx;
    idx++;
}

// remove the head node
void remove_head() {
    ne[0] = ne[ne[0]];
    pr[ne[0]] = 0;
}

//remove the k's inserted num
void remove(int k) {
    ne[pr[k]] = ne[k];
    pr[ne[k]] = pr[k];
}

// insert a new node after the k's inserted num
void insert_right(int k, int val) {
    node[idx] = val;
    pr[idx] = k;
    ne[idx] = ne[k];
    ne[k] = idx;
    pr[ne[idx]] = idx;
    idx ++;
}

void insert_left(int k, int val) {
    node[idx] = val;
    ne[idx] = k;
    pr[idx] = pr[k];
    pr[k] = idx;
    ne[pr[idx]] = idx;
    idx ++;
}

int main() {
    int m;
    cin >> m;
    string op;
    int k, val;
    init();
    while (m --) {
        cin >> op;
        if (op == "L") {
            cin >> val;
            insert_head(val);
        } else if (op == "R")
        {
            cin >> val;
            insert_tail(val);
        } else if (op == "D")
        {
            /* code */
            cin >> k;
            remove(k + 1);
        } else if (op == "IL") {
            cin >> k >> val;
                insert_left(k + 1 ,val);
        } else {
            cin >> k >> val;
                insert_right(k + 1,val);
        }
    
    }
    int now = ne[0];
    while (now != 1) {
        cout << node[now] << " ";
        now = ne[now];
    }
    return 0;
}