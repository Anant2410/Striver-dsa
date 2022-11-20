//1  recursive//

class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};


//2 using stack//

void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            if(node->right)
            {
                st.push(node->right);
            }
            if(node->left)
            {
                st.push(node->left);
            }
            if(!st.empty())
            {
                node->right = st.top();
            }
            node->left = NULL;
        }
    }
