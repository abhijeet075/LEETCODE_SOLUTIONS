class Solution {
public:
    int reverseDegree(string s) {
       int ans=0;
       int n= s.length();
       for(int i=0;i<n;i++)
       {
            ans += (i+1) * abs(s[i]-'a'- 26);
       }
       return ans;
    }
};