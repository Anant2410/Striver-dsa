void f(Node* root, vector<int>& ans)
{
    if(!root) return ;
    f(root->left,ans);
    f(root->right,ans);
    ans.push_back(root->data);
    return ;
}
vector <int> postOrder(Node* root)
{
  vector<int>ans;
  f(root,ans);
  return ans;
}

// iterative using 2 stack//
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode* node = st1.top();
            st2.push(node);
            st1.pop();
            if(node->left)
            {
                st1.push(node->left);
            }
            if(node->right)
            {
                st1.push(node->right);
            }
        }
        while(!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }

//iterative using 1 stack//
 vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*>st;
        TreeNode* curr = root;
        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* temp = st.top() -> right;
                if(temp==NULL){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        return ans; 
    }
