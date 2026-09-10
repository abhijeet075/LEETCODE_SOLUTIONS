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
    int sum =0;
    int count =0;
     int inorder (TreeNode* root)
     {
         if(root==NULL)
         return 0;
        
        
        inorder(root->left);

        sum+=root->val;
        count+=1;

        inorder(root->right);

        return sum/count;
     }


    int averageOfSubtree(TreeNode* root) {
        int ans =0;
        if(root==NULL)
        return 0;

         sum=0;
         count=0;
        int avvg =inorder(root);
        if(root->val == avvg)
        {
            ans+=1;
        }
        ans+= averageOfSubtree(root->left);
        ans+= averageOfSubtree(root->right);

        return ans;
    }
};