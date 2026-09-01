/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,vector<int>v,vector<vector<int>>&ans)
    {
        if(root==NULL)
        return;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(v);
            return ;
        }
        dfs(root->left,v,ans);
        dfs(root->right,v,ans);
    }
    int sum (vector<int>a)
    {
        int sum =0;
        for(int i=0;i<a.size();i++)
        {
            sum+=a[i];
        }
        return sum;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<vector<int>>ans;
        vector<int>v;
        dfs(root,v,ans);
        for(int i=0;i<ans.size();i++)
        {
             if(sum(ans[i])==targetSum)
             {
                result.push_back(ans[i]);
             }
        }
        return result;
    }
};