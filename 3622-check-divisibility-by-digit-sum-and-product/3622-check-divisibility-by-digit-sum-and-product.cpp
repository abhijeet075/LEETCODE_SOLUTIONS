class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum=0;
        int produ=1;
        while(num>0)
        {
           int d=num%10;
           sum+=d;
           produ*=d;
           num/=10;
        }

        if(n%(sum+produ)==0)
        return true;
        return false;
    }
};