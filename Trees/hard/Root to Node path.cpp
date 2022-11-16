/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool f(TreeNode* root, int x , vector<int>& ans){
    if(!root) return false; 
    ans.push_back(root->val);
    if(root->val==x) return true;
    
    if(f(root->left,x,ans) || f(root->right,x,ans)) return true;
    
    ans.pop_back();
    return false; 
} 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(f(A,B,ans)){
        return ans;
    }
}
