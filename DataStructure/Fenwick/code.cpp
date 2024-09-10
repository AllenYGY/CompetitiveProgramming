#include<bits/stdc++.h>
#include<iostream>
#define endl '\n'
using namespace std;

// 树状数组
class Fenwick {
    vector<int> tree;
 
public:
    Fenwick(int n) : tree(n) {}
    // 把下标为 i 的元素增加 1
    void add(int i) {
        while (i < tree.size()) {
            tree[i]++;
            i += i & -i; // i & -i 会得到 i 的最后一个 1 即 lowbit
        }
    }

    void update(int i, int val) {
        for (; i < tree.size(); i += i & -i) { // i & -i 会得到 i 的最后一个 1 即 lowbit
            tree[i] += val;
        }
    }

    // 返回下标在 [1,i] 的元素之和,
    int pre(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i &= i - 1; // i & (i - 1) 会把 i 的最后一个 1 变成 0 
        }
        return res;
    }

    // 返回下标在 [l,r] 的元素之和
    int query(int l, int r) {
        if (r < l) {
            return -1;
        }
        return pre(r) - pre(l - 1);
    }

};

class Fenwick {
    vector<int> tree;
 
public:
    Fenwick(int n) : tree(n) {}
    // 把下标为 i 的元素增加 1
    void add(int i) {
        while (i < tree.size()) {
            tree[i]++;
            i += i & -i;
        }
    }
    // 把下标为 i 的元素增加 val
    void update(int i, int val) {
        for (; i < tree.size() ;i += i & -1){
            tree[i] += val;
        }
    }
    // 返回下标在 [1,i] 的元素之和,
    int pre(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i &= i - 1;
        }
        return res;
    }
    // 返回下标在 [l,r] 的元素之和
    int query(int l, int r) {
       if (l > r) return -1;
       return pre(r) - pre(l - 1);
    }
};