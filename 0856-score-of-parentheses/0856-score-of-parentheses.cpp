class Solution {
public:
    int scoreOfParentheses(string s) {
        
     int temp =0;
     int  ans =0;
        for(int i =0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
               temp++;
            }
            else 
            {
                temp--;
                if (s[i-1] =='(') 
                {
                    ans += (1 << temp);
                }
            }
        }
        return ans ;
    }
};