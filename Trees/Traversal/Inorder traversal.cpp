void f(Node* root, vector<int>& ans)
    {
        if(!root) return ;
        
        f(root->left,ans);
        ans.push_back(root->data);
        f(root->right,ans);
        return;
    }
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        f(root,ans);
        return ans;
    }



// iterative usinng 1 stack//\
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true)
        {
            if(node!=NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if(st.empty()) break;
                TreeNode* x = st.top();
                st.pop();
                ans.push_back(x->val);
                node = x->right;
            }
        }
        return ans;
    }

//iterative//
//morris traversal
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        TreeNode* prev;
        
        while(curr!=NULL){
            //case 1 when the left child is null simply  add it to vector  and move right//
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                //else make a threaded binary tree
                prev = curr->left;
                //go to the rightest part of the left subtree
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                //if it is not connected then connect them and move to left
                if(prev->right==NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                //else mark it as null and move to right
                else{
                    prev->right=NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
