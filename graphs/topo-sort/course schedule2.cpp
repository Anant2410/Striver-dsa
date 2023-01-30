/*same as course schedule 1 bass yahan ans print krna hai*/

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        //for storing ans
        vector<int> ans;
        //create adjlist
        vector<int> adj[n];
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        //store indegree of all vertices
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        //push elements to queue with 0 indegree
        for(int i=0;i<n;i++)
        {
            if(indegree[i] ==0) q.push(i);
        }
        //basic topo-sort logic
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
        //if size equals to n then return ans
        if(ans.size() == n) return ans;
        //return empty array is ans is not possible
        return {};
    }
