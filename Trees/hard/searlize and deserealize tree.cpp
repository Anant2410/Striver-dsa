/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root==NULL)
        {
            return "";
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr==NULL)
            {
                s.append("#,");
            }
            else
            {
                s.append(to_string(curr->val)+',');
            }
            if(curr!=NULL)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#")
            {
                curr->left=NULL;
            }
            else
            {
                TreeNode* leftchild = new TreeNode(stoi(str));
                curr->left = leftchild;
                q.push(leftchild);
            }
            getline(s,str,',');
            if(str=="#")
            {
                curr->right=NULL;
            }
            else
            {
                TreeNode* rightchild = new TreeNode(stoi(str));
                curr->right = rightchild;
                q.push(rightchild);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
