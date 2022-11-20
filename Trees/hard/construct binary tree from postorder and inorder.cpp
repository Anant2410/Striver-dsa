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
//1. place the values of inorder int the map along with their indexes//
//2. pass poststart,postend,instart,inend to the fun//
//3. find the number of terms in the left side of the root//
//4. call for the left side//
//5. call for the right side//
//6. return the node//



class Solution {
public:
    TreeNode* f(vector<int>& postorder, int poststart, int postend, 
               vector<int>& inorder, int instart, int inend, map<int,int>&mp)
    {
        if(poststart > postend || instart > inend)
        {
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[postend]);
        int inroot = mp[node->val];
        int rem = inroot - instart;    //3
        
        node->left = f(postorder,poststart, poststart+rem-1,inorder,instart, 
                       inroot-1,mp);  //4
        node->right = f(postorder,poststart+rem,postend-1,
                        inorder,inroot+1,inend,mp);     //5
        return node;           //6
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;      //1
        }
        TreeNode* root = f(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);  //2
        return root;
    }
};
