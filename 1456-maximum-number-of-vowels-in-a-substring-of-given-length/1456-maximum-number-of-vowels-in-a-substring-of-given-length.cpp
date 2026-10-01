class Solution {
public:
    int maxVowels(string s, int k) {
        // int ans =0;
        // int n = s.size();
        // for(int i=0;i<n-k+1;i++)
        // {

        //     int j=i;
        //     int x=0;
        //     int count =0;
        //     while(x<k)
        //     {

        //         if(s[j]=='a' || s[j]=='e' || s[j] == 'i' || s[j] =='o' || s[j]=='u')
        //         {
        //             count+=1;
        //         }
        //         j++;
        //         x++;
        //     }
        //     ans = max(ans,count);
        //     if(ans == k)
        //     return ans;
        // }
        // return ans;


        int count =0;
        int maxi =0;
        int n= s.size();
        for(int i =0;i<k;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i] == 'i' || s[i] =='o' || s[i]=='u')
                 {
                     count+=1;
                 }
        }

        maxi =max(maxi,count);

        for(int i=k;i<n;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i] == 'i' || s[i] =='o' || s[i]=='u')
                 {
                     count+=1;
                }

            if(s[i-k]=='a' || s[i-k]=='e' || s[i-k] == 'i' || s[i-k] =='o' || s[i-k]=='u')
                 {
                     count--;
                }
            maxi =max(count,maxi);
        }
        return maxi;
    }
};