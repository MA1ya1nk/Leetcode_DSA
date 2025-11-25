#include <iostream>
#include <vector>
using namespace std;

typedef int node_type;

class SegmentTree {
    vector<node_type> tree, lazy;
    int n;

    node_type merge(node_type l, node_type r) {
        return max(l,r); // can change to max/sum/bitwise etc.
    }

    void build_tree(vector<int> &nums, int s, int e, int node) {
        if (s == e) {
            tree[node] = nums[s];
            return;
        }

        int mid = (s + e) / 2;
        build_tree(nums, s, mid, 2 * node);
        build_tree(nums, mid + 1, e, 2 * node + 1);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void push_lazy(int s, int e, int node) {
    if (lazy[node] != 0) {
        tree[node] = max(tree[node], lazy[node]);  // Fix: apply max not assign
        if (s != e) {
            lazy[2 * node] = max(lazy[2 * node], lazy[node]);
            lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
        }
        lazy[node] = 0;
    }
}


    node_type range_query(int s, int e, int node, int l, int r) {
        push_lazy(s, e, node);

        if (r < s || e < l) return -1e9; // Neutral element for min

        if (l <= s && e <= r) return tree[node];

        int mid = (s + e) / 2;
        node_type left = range_query(s, mid, 2 * node, l, r);
        node_type right = range_query(mid + 1, e, 2 * node + 1, l, r);
        return merge(left, right);
    }

    void range_update(int s, int e, int node, int l, int r, int val) {
        push_lazy(s, e, node);

        if (r < s || e < l) return;

        if (l <= s && e <= r) {
            lazy[node] = max(val,lazy[node]);
            push_lazy(s, e, node);
            return;
        }

        int mid = (s + e) / 2;
        range_update(s, mid, 2 * node, l, r, val);
        range_update(mid + 1, e, 2 * node + 1, l, r, val);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update_tree(int s, int e, int node, int idx, int val) {
        push_lazy(s, e, node);

        if (s == e) {
            tree[node] += val;
            return;
        }

        int mid = (s + e) / 2;
        if (idx <= mid) update_tree(s, mid, 2 * node, idx, val);
        else update_tree(mid + 1, e, 2 * node + 1, idx, val);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(vector<int> &nums) {
        n = nums.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build_tree(nums, 0, n - 1, 1);
    }

    node_type query(int l, int r) {
        return range_query(0, n - 1, 1, l, r);
    }

    void update(int idx, int val) {
        update_tree(0, n - 1, 1, idx, val);
    }

    void range_update(int l, int r, int val) {
        range_update(0, n - 1, 1, l, r, val);
    }
};




class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& nums) {
        set<int> coords;

        for (auto& sq : nums) {
            coords.insert(sq[0]);
            coords.insert(sq[0] + sq[1] - 1);
        }

        // Index mapping: large coord → small index
        unordered_map<int, int> mp;
        int idx = 0;
        for (int x : coords) {
            mp[x] = idx++;
        }

        vector<int> init(idx, 0);
        SegmentTree st(init);

        vector<int> ans;
        int mx = 0;

        for (auto& sq : nums) {
            int l = mp[sq[0]];
            int r = mp[sq[0] + sq[1] - 1];
            int h = sq[1];

            int base = st.query(l, r);
            st.range_update(l, r, base + h);
            mx = max(mx, st.query(0, idx - 1));
            ans.push_back(mx);
        }

        return ans;
    }
};