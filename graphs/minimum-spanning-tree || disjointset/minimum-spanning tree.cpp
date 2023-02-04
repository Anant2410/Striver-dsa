/*tree that has n nodes and exactly n-1 edges and all nodes are reachable is known as minimum spanning tree
*/

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
      //declare a priority_queue<distance,node> 
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
      // push the start node along with the distance 
        pq.push({0,0});
      //take a vis array
        vector<int> vis(V,0);
      //for storing the min. sum
        int sum = 0;
      //iterate while heap is not empty
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
          //if already visited continue as we have find a smaller distance 
            if(vis[node]) continue;
            //else mark vis  and add distance to sum
            vis[node] = 1;
            sum += wt;
          //traverse the adjnode , if not vis push to queue along with distance
            for(auto it: adj[node])
            {
                int adjnode = it[0];
                int edwt = it[1];
                if(!vis[adjnode])
                {
                    pq.push({edwt,adjnode});
                }
            }
        }
      
        return sum;
    }
};
