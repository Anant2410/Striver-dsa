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
