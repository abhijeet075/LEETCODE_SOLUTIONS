class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto num:nums)
        {
            mp[num]++;
        }
        
        if(k==1)
        {
            int maxxx=-1;
          for(int i=0;i<n;i++)
          {
            if(mp[nums[i]]==1 && nums[i]>maxxx)
            {
                maxxx=nums[i];
            }
          }
          return maxxx;
        }

        if(k==n)
        {
           int ans=INT_MIN;
            for(int i=0;i<n;i++)
          {
            ans=max(ans,nums[i]);
          } 
          return ans;
        }   

        if(nums[0]==nums[n-1])    
        return -1;

        else if(mp[nums[0]]==1 && mp[nums[n-1]]==1)
            return max(nums[0],nums[n-1]);
        
        else if(mp[nums[0]]==1 && mp[nums[n-1]]>1)
        return nums[0];

        else if(mp[nums[0]]>1 && mp[nums[n-1]]==1)
        return nums[n-1];
        return -1;
    }
};