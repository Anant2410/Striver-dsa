/*adj list bnao aur fir tropo sort lgao*/


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> ans;
        vector<int> adj[n];
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] ==0) q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(ans.size() ==n) return true;
        
        return false;
    }
