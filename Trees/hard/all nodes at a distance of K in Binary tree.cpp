/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mp, TreeNode* Target) // this is the function for marking the parent of the nodes//
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left)
            {
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right)
            {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*>mp;
        f(root,mp,target);
        queue<TreeNode*> q;                          // take a queue to place the node 
        unordered_map<TreeNode*, bool> vis;           // to check wheather the node is visited or not// 
        q.push(target);
        vis[target] = true;
        int dist = 0;
        while(!q.empty())
        {
            int size = q.size();
            if(dist++ == k)                                // as soon as the distance ==k break from the loop and return the values present in the queue
            {
                break;
            }
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left])           // for checking the left part of the node//
                {
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right])           // for checking the right part of the node//
                {
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if(mp[node] && !vis[mp[node]])                 // for checking the parent part of the node // 
                {
                    vis[mp[node]] = true;
                    q.push(mp[node]);
                }
            }
        }
        while(!q.empty())                                      //  for returning the answer//
        {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};
