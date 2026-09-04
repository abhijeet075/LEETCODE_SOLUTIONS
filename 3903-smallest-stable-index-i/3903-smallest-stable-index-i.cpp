class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>vec(n,0);
        vec[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            vec[i] =max(nums[i],vec[i-1]);
        }
        int temp =INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            temp =min(nums[i],temp);
            vec[i] -= temp;
        }
        for(int i=0;i<n;i++)
        {
            if(vec[i]<=k)
            return i;
        }
        return -1;
    }
};