#include <bits/stdc++.h>

using namespace std;

struct SegTree {
public:
    SegTree(int _n, vector<int>& arr) : n(_n) {
        tree.resize(4 * n, 0);
        build(0, n - 1, 0, arr);
    }

    long long query(int x, int y) {
        return query(x, y, 0, n - 1, 0);
    }

    void update(int pos, int val) {
        update(pos, val, 0, n - 1, 0);
    }

private:
    vector<long long> tree;
    int n;

    void build(int l, int r, int i, const vector<int>& arr) {
        if (l == r) {
            tree[i] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, 2 * i + 1, arr);
        build(m + 1, r, 2 * i + 2, arr);
        tree[i] = (tree[2 * i + 1] + tree[2 * i + 2]);
    }

    long long query(int x, int y, int l, int r, int i) {
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) return tree[i];

        int m = (l + r) >> 1;
        return (
            (
                query(x, y, l, m, 2 * i + 1) +
                query(x, y, m + 1, r, 2 * i + 2)
            )
        );
    }

    void update(int pos, int val, int l, int r, int i) {
        if (l == r) {
            tree[i] += val;
            return;
        }
        int m = (l + r) >> 1;
        if (pos <= m)
            update(pos, val, l, m, i * 2 + 1);
        else
            update(pos, val, m + 1, r, 2 * i + 2);

        tree[i] = (tree[2 * i + 1] + tree[2 * i + 2]);
    }
};


int main(){

}