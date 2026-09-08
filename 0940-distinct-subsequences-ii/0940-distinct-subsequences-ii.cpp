class Solution {
public:
    int distinctSubseqII(string s) {
        int mod =1000000000+7;
        vector<long long> count(26,0);
        long long sum =0;
        for(char c:s){
            long long x =(1+sum)%mod;
            int idx =c-'a';
            sum =(sum+x-count[idx]+mod)%mod;
            count[idx] = x;
        }
        return (int)sum;
    }
};