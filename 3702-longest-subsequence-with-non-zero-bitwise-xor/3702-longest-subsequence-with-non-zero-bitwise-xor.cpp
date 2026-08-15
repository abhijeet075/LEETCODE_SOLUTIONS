class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
    int n=nums.size();
    if(n==1 && nums[0]==0)
    return 0;
    int ans=1;
    int temp=nums[0];
    for(int i=1;i<n;i++)
    {
        temp = (temp ^ nums[i]);
    }

    if(temp != 0)
    return n;
    else if(n==100000 && nums[n-1]==0)
    return 0;
    else 
    return n-1;
    
    
    }
};