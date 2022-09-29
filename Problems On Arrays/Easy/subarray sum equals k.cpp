int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0,ans=0;
        mp[sum] = 1;
        for(auto it: nums)
        {
            sum += it;
            int rem = sum-k;
            if(mp.find(rem) != mp.end())
            {
                ans += mp[rem];
            }
            mp[sum]++;
        }
        return ans;
    }
    
    / gfg
    
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = -1;
        
        for(int i=0;i<N;i++)
        {
            sum += A[i];
            int rem = sum - k;
            if(mp.count(rem) > 0)
            {
                ans = max(ans,i-mp[sum-k]);
            }
            if(!mp.count(sum)) mp[sum] = i;
        }
        return ans;
    } 
