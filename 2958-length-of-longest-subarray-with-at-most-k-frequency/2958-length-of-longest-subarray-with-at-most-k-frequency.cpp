class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        while(j<n)
        {
            mp[nums[j]]++;
            if(mp[nums[j]]<=k)
            {
              ans=max(ans,j-i+1);
            }
            while(mp[nums[j]]>k)
            {
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};