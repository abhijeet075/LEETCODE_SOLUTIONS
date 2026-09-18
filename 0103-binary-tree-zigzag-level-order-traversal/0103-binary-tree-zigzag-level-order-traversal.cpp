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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
       
        while(q.size()>0)
        {
            int size=q.size();
            vector<int>vec;
            for(int i=0;i<size;i++)
            {
             TreeNode* curr=q.front();
             q.pop();
            
              vec.push_back(curr->val);
              if(curr->left!=NULL)
              {
                q.push(curr->left);
              }
              if(curr->right!=NULL)
              {
                q.push(curr->right);
              }
            }

              ans.push_back(vec);
        }
    vector<vector<int>>res;

    for(int i =0;i<ans.size();i++)
    {
        if(i%2==0)
        {
            res.push_back(ans[i]);
        }
        else
        {
            reverse(ans[i].begin(),ans[i].end());
            res.push_back(ans[i]);
        }
    }
    return res;
    }
};