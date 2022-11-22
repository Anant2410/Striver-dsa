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
    bool fun(TreeNode* root, int mini, int maxi)
    {
        if(root==NULL) return true;
        if(root->val >= maxi || root->val<=mini)
            return false;
        return fun(root->left,mini,root->val) && fun(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
       return fun(root,INT_MIN,INT_MAX);
    }
};

//simply can find the inorder traversal and return the k-1 value of the inorder traversal//
