void f(int i, int j, vector<vector<int>> &m, int n, string path, vector<vector<int>>& vis, 
    vector<string>& ans){
        if(i==n-1 && j==n-1) {
            ans.push_back(path);
            return;
        }
        if(i+1<n && vis[i+1][j] ==0 && m[i+1][j] ==1){
            vis[i][j] =1;
            f(i+1,j,m,n,path + 'D', vis,ans);
            vis[i][j] = 0;
        }
        if(j-1>=0 && vis[i][j-1] ==0 && m[i][j-1] ==1){
            vis[i][j] =1;
            f(i,j-1,m,n,path + 'L', vis,ans);
            vis[i][j] = 0;
        }
        if(j+1<n && vis[i][j+1] ==0 && m[i][j+1] ==1){
            vis[i][j] =1;
            f(i,j+1,m,n,path + 'R', vis,ans);
            vis[i][j] = 0;
        }
        if(i-1>=0 && vis[i-1][j] ==0 && m[i-1][j] ==1){
            vis[i][j] =1;
            f(i-1,j,m,n,path + 'U', vis,ans);
            vis[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n,0));
        if(m[0][0] ==1) f(0,0,m,n,"",vis,ans);
        return ans;
    }
//optimised one //

void f(int i, int j, vector<vector<int>> &m, int n, string path, vector<vector<int>>& vis, 
    vector<string>& ans, int di[] , int dj[]){
        if(i==n-1 && j==n-1) {
            ans.push_back(path);
            return;
        }
        string dir = "DLRU";
        for(int ind=0;ind<4;ind++){
            int ni = i + di[ind];
            int nj = j + dj[ind];
            if(ni>=0 && nj>=0 && ni<n && nj<n && !vis[ni][nj] && m[ni][nj] ==1){
                vis[i][j] = 1;
                f(ni,nj,m,n,path + dir[ind],vis,ans,di,dj);
                vis[i][j] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n,0));
        int di[] = {1,0,0,-1};
        int dj[] = {0,-1,1,0};
        if(m[0][0] ==1) f(0,0,m,n,"",vis,ans,di,dj);
        return ans;
    }
