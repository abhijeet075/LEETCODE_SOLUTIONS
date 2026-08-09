int dp[101][201][2];
class Solution {
public:

    int solve(int i,int M,int turn ,vector<int>&piles)
    {
        int n=piles.size();
        if(i==n)
        return 0;

        if(dp[i][M][turn] != -1)
        {
            return dp[i][M][turn];
        }
        if(turn == 0)
        {
            int mx=0;
            int sum =0;
            for(int x=1;x<=2*M;x++)
            {
                if(x+i-1 >= piles.size())
               {
                    break;
               }

                sum+=piles[i+x-1];
                int val = solve(i+x,max(M,x),1-turn,piles);
                mx = max(mx,val+sum);
            }
            return dp[i][M][turn]=mx;
        }
        int mn=INT_MAX;
        for(int x=1;x<=2*M;x++)
        {
            if(x+i-1 >= piles.size())
               {
                    break;
               }

                int val = solve(i+x,max(M,x),1-turn,piles);
                mn = min(mn,val);
        }
        return dp[i][M][turn]=mn;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof dp);
        return solve(0,1,0,piles);
    }
};