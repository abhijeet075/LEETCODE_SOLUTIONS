class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if(nums[j]!=val && nums[i]==val)
            {
                swap(nums[i],nums[j]);
                i++;
            }
            else if(nums[i]!=val)
            {
               i++;
            }
            else
            {
                j--;
            }
        }
        vector<int> result={};
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=val)
            {
               result.push_back(nums[i]);
            }
        }
        int m = result.size();
        return m;
        return result[m];
        
    }
};