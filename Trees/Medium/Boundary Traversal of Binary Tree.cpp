bool leaf(Node* root){
        if(root->left==NULL && root->right==NULL) return true;
        
        return false;
    }
    void left(Node* root, vector<int>& ans){
        Node* curr = root->left;
        while(curr){
            if(!leaf(curr)) ans.push_back(curr->data);
            
            if(curr->left) curr = curr->left;
            
            else  curr = curr->right;
        }
    }
    void leave(Node* root, vector<int>& ans){
        if(leaf(root)) ans.push_back(root->data);
        if(root->left) leave(root->left,ans);
        if(root->right) leave(root->right,ans);
    }
    void right(Node* root, vector<int>& ans){
        Node* curr = root->right;
        vector<int> ds;
        while(curr){
            if(!leaf(curr)) ds.push_back(curr->data);
            
            if(curr->right) curr = curr->right;
            
            else  curr = curr->left;
        }
        for(int i= ds.size()-1;i>=0;i--) ans.push_back(ds[i]);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL) return ans;
        if(!leaf(root)) ans.push_back(root->data);
        left(root,ans);
        leave(root,ans);
        right(root,ans);
        
        return ans;
    }
