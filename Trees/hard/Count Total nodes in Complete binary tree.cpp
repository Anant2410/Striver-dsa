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
    int fun(TreeNode* root)
    {
        int ans = 0;
        while(root)
        {
            ans++;
            root = root->right;
        }
        return ans;
    }
    int f(TreeNode* root)
    {
        int ans = 0;
        while(root)
        {
            ans++;
            root = root->left;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {               // we cn check whether the tree is complte or not if so then simply return 2*l-1;
        int l = f(root);                           // finding the left height of tree
        int r = fun(root);                            // finding the right height of tree//
         
        if(l==r)                              
        {
            return pow(2,l) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);            // return 1 + left() + right();
    }
};
