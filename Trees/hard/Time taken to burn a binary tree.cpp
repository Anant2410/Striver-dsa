Node* f(Node* root, unordered_map<Node*,Node*>&mp, int target) /// for finding the parent of the node // 
    {
        Node* temp;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();
            if(node->data == target)
            {
                temp = node;
            }
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
        return temp;                                     // returns the address of the target node//
    }
    int minTime(Node* root, int target) 
    {
       unordered_map<Node*,Node*>mp;
       Node* tar = f(root,mp,target);
       unordered_map<Node*, bool> vis;
       queue<Node*>q;
       q.push(tar);
       vis[tar] = true;
       int dist = 0;
       while(!q.empty())
       {
           int size = q.size();
           bool flag = false;
           for(int i=0;i<size;i++)
           {
               Node* node = q.front();
               q.pop();
               if(node->left && !vis[node->left])               // for finding the left of the tree
               {
                   flag = true;
                   vis[node->left] = true;
                   q.push(node->left);
               }
               if(node->right && !vis[node->right])               // for finding the right//
               {
                   flag = true;
                   vis[node->right] = node;
                   q.push(node->right);
               }
               if(mp[node] && !vis[mp[node]])                // for tracing the upward part of the tree//
               {
                   flag = true;
                   vis[mp[node]] = true;
                   q.push(mp[node]);
               }
           }
           if(flag)                                            // if flag is true just increase the distance //
           {
               dist++;
           }
       }  
       return dist;                                       // return the distance to burn the tree
    }
