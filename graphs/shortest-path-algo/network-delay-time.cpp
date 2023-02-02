/*take the distance array to store 
the distance from one node to every node*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create an adj list
        vector<pair<int,int>> adj[n+1];
        //store nodes in adjlist
        for(auto it: times)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        //create distance array to store the min distance 
        //require to reach the node
        vector<int> dist(n+1, 1e9);
        //mark 0th node as 0 as 1 based indexing
        dist[0] = 0;
        dist[k] = 0;
        //create a priority_Queue<distance,node>
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        //push initial node with distance
        pq.push({0,k});
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            //traverse the adjnodes 
            for(auto it: adj[node])
            {
                int adjnode = it.first;
                int adjdist = it.second;
                //if the distance of adjnode is greater than the reached
                //distance update the disatnce array and push to pq
                if(dist[adjnode] > wt + adjdist)
                {
                    dist[adjnode] = wt + adjdist;
                    pq.push({wt+adjdist,adjnode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<dist.size();i++)
        {
            //if node not vis  return -1 as ans  is not possible
            if(dist[i] == 1e9) return -1;
            //store the maximum as  it will give the min answer
            else ans = max(ans,dist[i]);
        }
        //return the desired ans
        return ans;
    }
};
