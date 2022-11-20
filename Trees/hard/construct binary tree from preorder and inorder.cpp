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

// 1. assign inorder to map with their respective indexes//
//2.  pass the values prestart,preend,instart,inend, mp//
//3. find the number of left nodes and right nodes//
//4. find the number of values located to left of the value(root)//
//5. find the values located at the right of the value(root) // 
//6. return the root//


class Solution {
public:
    TreeNode* f(vector<int>&preorder,int prestart, int preend,
               vector<int>&inorder, int instart, int inend, map<int,int>&mp)
    {
        if(prestart>preend || instart > inend)
        {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[prestart]);
        int inroot = mp[node->val];  //3
        int rem = inroot - instart;      
        node->left = f(preorder,prestart+1,prestart+rem,inorder,instart,inroot-1,mp); //4
        node->right = f(preorder,prestart+rem+1,preend,inorder,inroot+1,inend,mp); //5
        
        return node;   //6
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)   //1
        {
            mp[inorder[i]] = i;            
        }
        root = f(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);   //2
        
        return root;
    }
};
