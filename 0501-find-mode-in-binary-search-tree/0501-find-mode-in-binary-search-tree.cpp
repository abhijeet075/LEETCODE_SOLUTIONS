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
     
    // bool flag =false;
    // int temp = 0;
    // int count = 0;
    // int count_max = 0;
    // vector<int>ans;
    //  void helper(TreeNode * root)
    //  {
    //     if(root==NULL)
    //     return;
    //     helper(root->left);

    //     if(flag && root->val == temp)
    //     {
    //         count++;
    //     }
    //     else
    //     {
    //         count = 1;
    //     }

    //     if(count > count_max)
    //     {
    //         ans.clear();
    //         ans.push_back(root->val);
    //     }
    //     else if( count == count_max)
    //     {
    //         ans.push_back(root->val);
    //           count_max =count
    //     }

    //     flag = true ;
    //     temp =root->val;

    //     helper(root->left);
        // void inorder(TreeNode * root)
        // {
        //     helper(root);
        //     return ans ;
        // }

    //  }


    unordered_map<int,int>mp;
    void inorder(TreeNode * root)
    {
        if(root == NULL)
        {
            return ;
        }
     inorder(root->left);
     mp[root->val]++;
     inorder(root->right);

    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        vector<int>ans;
        int max_fre = INT_MIN;
        for(auto x :mp)
        {
          if(x.second > max_fre)
          {
            max_fre = x.second;
          }
        }
        for(auto x : mp)
        {
            if(max_fre ==x.second)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};