 bool f(TreeNode* a, TreeNode* b){
        if(a==NULL || b==NULL)
            return a==b;
        if(a->val != b->val) return false;
        return f(a->right, b->left) && f(a->left, b->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return f(root->left, root->right);
    }
