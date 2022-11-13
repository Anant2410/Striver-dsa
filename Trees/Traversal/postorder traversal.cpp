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

//iterative//
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
