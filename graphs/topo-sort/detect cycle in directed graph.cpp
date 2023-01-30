/*topo sort vala function lgana hai 
aur count krna hai ki total elements vertices ke equal hai ya nahi*/


 bool isCyclic(int V, vector<int> adj[]) {
      //count variable 
	    int count=0;
      // vis and indegree 
	    int vis[V] = {0};
	    int indegree[V] = {0};
      //indegree calculate krne ke liye
	    for(int i=0;i<V;i++)
	    {
	        for(auto it: adj[i])
	        {
	            indegree[it]++;
	        }
	    }
      //q for finding topo sort
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        vis[node] = 1;
	        count++;
	        for(auto it: adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0)
	            {
	                q.push(it);
	            }
	        }
	    }
      //if count is eual to v i.e no cycle is detected
	    if(count==V) return false;
	    
	    return true;
    }
