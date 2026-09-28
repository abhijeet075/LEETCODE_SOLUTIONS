class Solution {
public:
    int maxDepth(string s) {
        int n =s.size();
        int i=0;
        int d =0;
        int ans =0;
        while(i<n)
        {
            if(s[i] == '(')
            {
                d++;
                ans =max(ans,d);
            }
            else if(s[i] == ')')
            {
                d--;
            }
            i++;
        }

        return ans;
    }
};