/*
topo sort for bfs is kahn algo
calculate indegree and push node to queue if 0
now traverse to element and reduce indegree
if found 0 push to  queue
*/

vector<int> topoSort(int V, vector<int> adj[]) 
	{
      //for saving ans
	    vector<int> ans;
      //mark as vis
	    int vis[V] = {0};
      //for storing indegree
	    int indegree[V] = {0};
      //calculate indegree
	    for(int i=0;i<V;i++)
	    {
	        for(auto it: adj[i])
	        {
	            indegree[it]++;
	        }
	    }
      //declare a queue and push elements with 0 indegree//
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
      //store elements till q is not empty//
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        vis[node] = 1;
	        ans.push_back(node);
	        for(auto it: adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0)
	            {
	                q.push(it);
	            }
	        }
	    }
      //return ans
	    return ans;
