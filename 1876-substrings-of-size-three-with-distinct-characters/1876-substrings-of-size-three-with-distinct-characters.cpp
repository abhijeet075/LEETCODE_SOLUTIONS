class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.size();
        int count =0;
        for(int i=0;i<n-2;
        i++)
        {
            unordered_set<int>st;
            int j=i;
            int k=1;
            while(k<4)
            {
                st.insert(s[j]);
                k++;
                j++;
            }
            if(st.size()==3)
            {
                count++;
            }
        }
        return count;
    }
};