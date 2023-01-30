/*exclude the elements that are in loop
reverse the edges of the node so that topo logic can be applied*/


vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        //create adj list
        vector<int> adj[n];
        //storing indegree
        vector<int> indegree(n,0);
        //reverse the edges and store indegree
        for(int i=0;i<n;i++)
        {
            for(auto it: graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        //store elements with 0 indegree
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int>ans;
        //topo logic
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        //sort the desired ans
        sort(ans.begin(),ans.end());
        return ans;
    }
