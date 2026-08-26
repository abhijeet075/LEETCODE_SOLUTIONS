class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int j = 0;
        int count = 0;
        string ans = "";

        for (int i = 0; i< n; ++i) {
            if (s[i] == '1') {
                count++;
            }

            while (count == k) {
                string tempSub = s.substr(j, i - j + 1);

                if (ans == "" || tempSub.length() < ans.length() ||(tempSub.length() == ans.length() && tempSub < ans)) {
                    ans = tempSub;
                }

                if (s[j] == '1') {
                    count--;
                }
                j++;
            }
        }
        return ans;
    }
};
