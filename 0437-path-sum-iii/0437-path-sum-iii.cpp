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
    int df(TreeNode * root, long long sum, int targetSum)
    {
        int count=0;
        if(root==NULL)
        {
            return{};
        }
        sum += root->val;

        if(sum == targetSum)
        {
            count+=1;
        }
        count += df(root->left,sum,targetSum);
        count += df(root->right,sum,targetSum);
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        return 0;
        return df(root,0,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};