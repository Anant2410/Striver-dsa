/*the minimum wedges are the number of connected components -1
find connected components 
now given in question ki hume edge connected components me se hi dekhne hai
to extra edge count krlo agar vo jayada hue to return ans verna -1*/

class Disjoint{
public:
    vector<int> size,parent,rank;
    //initialize all the arrays
    Disjoint(int n)
    {
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
    }
    //find the ultimate parent of the node
    int findpar(int node)
    {
        if(parent[node] ==node) return node;

        return parent[node] = findpar(parent[node]);
    }
    //combine by size method
    void unionbysize(int u, int v)
    {
        int ul_u = findpar(u);
        int ul_v = findpar(v);
        if(size[ul_u] < size[ul_v])
        {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
        else
        {
            parent[ul_v] = ul_u;
            size[ul_u] = ul_v;
        }
    }
    //combine by rank method
    void unionbyrank(int u, int v)
    {
        int ul_u = findpar(u);
        int ul_v = findpar(v);
        if(rank[ul_u] < rank[ul_v])
        {
            parent[ul_u] = ul_v;
        }
        else if(rank[ul_u] > rank[ul_v])
        {
            parent[ul_v] = ul_u;
        }
        else
        {
            parent[ul_v] = ul_u;
            rank[ul_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //create initials
        Disjoint ds(n);
        int cnt=0;
        for(auto it: connections)
        {
            int u = it[0];
            int v = it[1];
            //if parent of both the nodes are different then combine them
            if(ds.findpar(u) != ds.findpar(v))
            {
                ds.unionbyrank(u,v);
            }
            //else tthey have extra edge
            else
            {
                cnt++;
            }
        }
        //count trhe connected components
        int nc=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i] == i) nc++;
        }
        //minimum ans is connected components -1
        int ans = nc-1;
        //if extra are enough to satisfy the ans than retun ans
        if(cnt >= ans) return ans;
        //else ans not possible
        return -1;
    }
};
