 int f(vector<int> arr, int N, int K, vector<vector<int>>& dp)
    {
        if(N==0)
        {
            return K==0;
        }
        if(dp[N][K] != -1) return dp[N][K];
        int take = f(arr,N-1, K^arr[N-1],dp);
        
        int leave = f(arr,N-1,K,dp);
        
        return dp[N][K] = take + leave;
    }
    int subsetXOR(vector<int> arr, int N, int K) {
        vector<vector<int>> dp(N+1, vector<int>(128,-1));
        return f(arr,N,K,dp);
    }


//
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    int xorr=0,cnt=0;
    
    for(auto it: A){
        xorr ^= it;
        
        if(xorr == B) cnt += 1;
        
        if(mp.find(xorr^B) != mp.end()){
            cnt += mp[xorr^B];
        }
        mp[xorr] += 1;
    }
    return cnt;
}

