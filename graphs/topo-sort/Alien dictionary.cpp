/*just find the character sequence not equal and form a directed graph 
now find the topo sort and return the ans*/

//topo sort logic
vector<int> topo(int n, vector<int>adj[])
    {
        int indegree[n] = {0};
        for(int i=0;i<n;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
    string findOrder(string dict[], int N, int K) {
      //for storing directed graph  
      vector<int> adj[K];
      //take 2 strings and compare wheather char equal or not
      //if not equal make edge and store in adjlist
        for(int i=0;i<N-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            for(int it=0;it<len;it++)
            {
              //if not equal move to adjlist and break no need to check furthur
                if(s1[it] != s2[it])
                {
                    adj[s1[it] - 'a'].push_back(s2[it] - 'a');
                    break;
                }
            }
        }
        //find topo sort
        vector<int> temp = topo(K,adj);
        string ans = "";
        //convert to string
        for(auto it: temp)
        {
            ans += char(it+'a');
        }
        return ans;
    }
