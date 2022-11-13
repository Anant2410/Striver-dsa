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

//iterative//

vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        TreeNode* prev;
        
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right==NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right=NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
