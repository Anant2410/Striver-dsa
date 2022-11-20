int isSumProperty(Node *root)
    {
        if(!root) return 1;
        int s = ((root->left)? root->left->data : 0)+((root->right)? root->right->data : 0);
        if((root->left || root->right) && s != root->data)
            return 0;
        return  isSumProperty(root->left) && isSumProperty(root->right);
    }
