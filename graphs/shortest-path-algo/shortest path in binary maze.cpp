class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // getting the size of rows and cols
        int rows = grid.size();
        int cols = grid[0].size();
        // creating the visited array to keep track of traversal
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        // creating a queue to hold the row,col and distance 
        queue<pair<pair<int,int>,int>> q;
        // checking the initial condition
        if(grid[0][0]!=0 || grid[rows-1][cols-1]!=0) return -1;
        // staring the BFS with setting the q with initial postion and distance
        q.push({{0,0},0});
        // marking the visited array position
        vis[0][0] =1;
        // untill q is not empty
        while(!q.empty()){
            //getting the row postion from the queue
            int sr = q.front().first.first;
            //getting the col postion from the queue
            int sc = q.front().first.second;
            // //getting the distance from the queue
            int distance = q.front().second;
            q.pop();
            //checking if final postion reached, if yes return distance+1
            if(sr==rows-1 and sc== cols-1) return distance+1;
            // created the delrow and delcol array with all the 8 direction values
            int delrow[] = {1,0,-1,-1,-1,0,1,1};
            int delcol[] = {-1,-1,-1,0,1,1,1,0};
            // checking all 8 direction from current postion
            for(int i=0;i<8;i++){
                int drow = sr + delrow[i];
                int dcol = sc + delcol[i];
                // Again checking the valid values before pushing the values on the queue
                if(drow>= 0 && drow<rows && dcol>=0 && dcol<cols && 
                grid[drow][dcol]==0 && vis[drow][dcol]==0){
                    //pushing it into the queue and marking visited.
                    q.push({{drow,dcol},distance+1});
                    vis[drow][dcol]=1;
                }
            }
        }
        return -1;

    }
};
