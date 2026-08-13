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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
        return nullptr;
        if(root1 && root2)
        {
        TreeNode* ans =new TreeNode(root1->val+root2->val);
        ans->left = mergeTrees(root1->left,root2->left);
        ans->right = mergeTrees(root1->right,root2->right);
        return ans;
        }

        if(root1 && !root2)
        {
            TreeNode* ans =new TreeNode(root1->val);
            ans->left = mergeTrees(root1->left,nullptr);
            ans->right = mergeTrees(root1->right,nullptr);
            return ans;
        }
        if(!root1 && root2)
        {
        TreeNode* ans =new TreeNode(root2->val);
        ans->left = mergeTrees(nullptr,root2->left);
        ans->right = mergeTrees(nullptr,root2->right);
        return ans;
        }
        return {};
    }
};