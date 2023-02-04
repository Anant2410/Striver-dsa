class Disjoint{
    vector<int> parent, size,rank;
public:
    Disjoint(int n)
    {
       //parent,size and rankl are three array   
        size.resize(n+1,1);
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
    }
  //function find the ultimate parent of a node
    int find_parent(int node)
    {
        if(node == parent[node]) return node;
        
        return parent[node] = find_parent(parent[node]);
    }
  //union by size
    void us(int u, int v)
    {
        int paru = find_parent(u);
        int parv = find_parent(v);
        if(size[paru] < size[parv])
        {
            parent[paru] = parv;
            size[parv] += size[paru];
        }
        else
        {
            parent[parv] = paru;
            size[paru] += size[parv];
        }
      //unio by rank
      void ur(int u, int v)
    {
        int paru = find_parent(u);
        int parv = find_parent(v);
        if(paru == parv) retun;
        if(rank[paru] < size[parv])
        {
            parent[paru] = parv;
        }
        else if(rank[parv) < rank[paru])
        {
            parent[parv] = paru;
        }
        else{
          parent[parv] = paru;
          rank[paru]++;
        }
    }
};

class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
      //edgeslist<wt,nodee,adjnode>
        vector<pair<int, pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                int node= i;
                int adjnode = it[0];
                int wt = it[1];
                edges.push_back({wt,{node,adjnode}});
            }
        }
        Disjoint ds(V);
        int ans = 0;
      //sort //list acc to weight
        sort(edges.begin(), edges.end());
        for(auto it: edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            //if parent of both nodes are not equal merge them and add wt to ans
            if(ds.find_parent(u) != ds.find_parent(v))
            {
                ans += wt;
                ds.us(u,v);
            }
        }
        return ans;
    }
};
