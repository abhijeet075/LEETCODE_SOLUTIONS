class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        int n=nums.size();

        int sum=0;
        for(int i=0;i<n;i++)
        {
            int d_sum=0;
            while(nums[i]>0)
            {
                d_sum += nums[i]%10;
                nums[i]/=10;
            }
            if(d_sum == i)
            return i;
        }
        return -1;
    }
};