
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<long long> freq(100001, 0);
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            mx = max(mx, d);
        }

        for (int i = mx; i > 0 && k > 0; i--) {
            long long take = min(k, freq[i]);
            freq[i] -= take;
            freq[i - 1] += take;
            k -= take;
        }

        long long ans = 0;

        for (int i = 1; i <= 100000; i++) {
            ans += 1LL * i * i * freq[i];
        }

        return ans;
    }
};

