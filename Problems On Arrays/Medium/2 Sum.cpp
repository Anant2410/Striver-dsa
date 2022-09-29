//leetcode


vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target- nums[i]) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
    
    //
    
    
    //gfg
    
    bool bs(int B[], int start, int end , int tar)
    {
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(B[mid] > tar) end = mid-1;
            else if(B[mid] < tar) start = mid + 1;
            else{
                return true;
            }
        }
        return false;
    }
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
          vector<pair<int, int>>ans;
          sort(A, A+N);
          sort(B, B+M);
          
          for(int i=0;i<N;i++)
          {
              int temp = X - A[i];
              if(bs(B,0,M-1,temp))
              {
                  ans.push_back({A[i],temp});
              }
          }
          return ans;
    }
    
    // gfg
