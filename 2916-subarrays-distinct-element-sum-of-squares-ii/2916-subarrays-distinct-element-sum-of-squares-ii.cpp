
class Solution {
    using ll = long long;
    static const int MOD = 1000000007;

    struct Node {
        ll sum = 0, sq = 0, lazy = 0;
    };

    vector<Node> st;
    int n;

    void apply(int p, int l, int r, ll v) {
        ll len = r - l + 1;
        st[p].sq = (st[p].sq + 2LL * v % MOD * st[p].sum % MOD
                    + v * v % MOD * len) % MOD;
        st[p].sum = (st[p].sum + v * len) % MOD;
        st[p].lazy = (st[p].lazy + v) % MOD;
    }

    void push(int p, int l, int r) {
        if (st[p].lazy == 0 || l == r) return;

        int m = (l + r) / 2;
        ll v = st[p].lazy;

        apply(p * 2, l, m, v);
        apply(p * 2 + 1, m + 1, r, v);

        st[p].lazy = 0;
    }

    void update(int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;

        if (ql <= l && r <= qr) {
            apply(p, l, r, 1);
            return;
        }

        push(p, l, r);

        int m = (l + r) / 2;
        update(p * 2, l, m, ql, qr);
        update(p * 2 + 1, m + 1, r, ql, qr);

        st[p].sum = (st[p * 2].sum + st[p * 2 + 1].sum) % MOD;
        st[p].sq = (st[p * 2].sq + st[p * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        st.assign(4 * n + 5, Node());

        unordered_map<int, int> last;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int left = 0;

            auto it = last.find(nums[i]);
            if (it != last.end())
                left = it->second + 1;

            update(1, 0, n - 1, left, i);

            ans = (ans + st[1].sq) % MOD;
            last[nums[i]] = i;
        }

        return (int)ans;
    }
};
