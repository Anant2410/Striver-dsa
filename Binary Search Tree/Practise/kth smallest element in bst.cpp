int c=0,ans=-1;
    int KthSmallestElement(Node *root, int k) {
        if(root!=NULL){

            KthSmallestElement(root->left,k);

             c++;

             if(c==k)

             ans=root->data;

             KthSmallestElement(root->right,k);

        }

        return ans;
    }


// inorder//
void fun(TreeNode* root, vector<int>&ans)
    {
        if(root==NULL)
        {
           return; 
        }
        fun(root->left,ans);
        ans.push_back(root->val);
        fun(root->right,ans);
        
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        fun(root,inorder);
        return inorder[k-1];
    }
