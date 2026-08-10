class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left=1;
        long long right=INT_MIN;
        int result=0;
        for(int i=0;i<candies.size();i++)
        {
            right=max(right,(long long )candies[i]);
        }

        while(left<=right)
        {
            long long  mid = left+(right-left)/2;
            long long count=0;
             for(auto x:candies)
             {
                count += x/mid;
             }
             if(count >= k)
             {
                result=mid;
                left=mid+1;
             }
             else
             {
                right=mid-1;
             }
        }
        return result;
    }
};