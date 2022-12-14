void pre(Node* root, vector<int>& ans)
{
    if(root==NULL)
    {
        return ;
    }
    ans.push_back(root->data);
    pre(root->left,ans);
    pre(root->right,ans);
}
vector <int> preorder(Node* root)
{
    vector<int> ans;
    pre(root,ans);
    return ans;
}

// iterative using stack//
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* x = st.top();
            st.pop();
            ans.push_back(x->val);
            if(x->right!=NULL)
            {
                st.push(x->right);
            }
            if(x->left!=NULL)
            {
                st.push(x->left);
            }
        }
        return ans;
    }


// iterative//
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root, *prev;
        if(root==NULL) return ans;
        while(curr!= NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right==NULL){
                    prev->right= curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right=NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
