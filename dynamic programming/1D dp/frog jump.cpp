/*recurrence is 
int up = f(ind-1) + abs(arr[i] - arr[i-1]);
int down = f(i-2) + abs(arr[i] - arr[i-2]);

return min(up,down);
*/
  //recurrence
  int f(int ind, vector<int>& arr, int n)
  {
      if(ind==0) return 0;
      
      int up = f(ind-1,arr,n) + abs(arr[ind] - arr[ind-1]);
      int down;
      if(ind>1)
      {
        down = f(ind-2,arr,n) + abs(arr[ind] - arr[ind-2]);
      }
      
      return min(up,down);
  }
    int minimumEnergy(vector<int>& height, int n) {
        return f(n-1,height,n);
    }

//memoization
//3 easy steps 
int f(int ind, vector<int>& arr, int n, vector<int>& dp)
  {
    //step 1 declare a dp array
      if(ind==0) return 0;
      //step 2;
      if(dp[ind] != -1) return dp[ind];
      int up = f(ind-1,arr,n,dp) + abs(arr[ind] - arr[ind-1]);
      int down = INT_MAX;
      if(ind>1)
      {
        down = f(ind-2,arr,n,dp) + abs(arr[ind] - arr[ind-2]);
      }
      //return recurrence relation to dp
      return dp[ind] = min(up,down);
  }

//tabulation
//bottom up approach
int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        dp[0] = 0;
        for(int i=1;i<n;i++)
        {
            int up = dp[i-1] + abs(height[i] - height[i-1]);
            int down = INT_MAX;
            if(i>1)
            {
                down = dp[i-2] + abs(height[i] - height[i-2]);
            }
            dp[i] = min(up,down);
        }
        return dp[n-1];
    }
// space optimization
//whenever there is ind-1 or ind-2 there is always be space optimization
//this is a thumb rule  
 int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        int prev = 0,prev2 = -1;
        for(int i=1;i<n;i++)
        {
            int up = prev + abs(height[i] - height[i-1]);
            int down = INT_MAX;
            if(i>1)
            {
                down = prev2 + abs(height[i] - height[i-2]);
            }
            int curr = min(up,down);
            
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
