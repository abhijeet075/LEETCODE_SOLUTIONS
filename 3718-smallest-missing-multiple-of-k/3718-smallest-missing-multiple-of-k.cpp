class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       int n=nums.size();
       unordered_set<int>st;
       for(int i=0;i<n;i++)
       {
         if(nums[i]%k==0)
         {
            st.insert(nums[i]);
         }
       }
       for(int i=1;i<=n+1;i++)
       {
        if(st.find(k*i)==st.end())
        {
            return k*i;
        }
       }
       return {};
    }
};