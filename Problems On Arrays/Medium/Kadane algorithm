 int maxSubArray(vector<int>& nums) {
        int  n = nums.size();
        if(n<1) return 0;
        if(n==1) return nums[0];
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            sum += nums[i];
            maxi = max(maxi, sum);
            if(sum<0)
                sum = 0;
        }
        return maxi;
    }
    
    
   //gfg// 
     long long maxSubarraySum(int arr[], int n){
        if(n==1) return (long long)arr[0];
        int sum=0;
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            ans = max(ans,sum);
            if(sum<0)
            {
                sum = 0;
            }
        
        }
       
        return (long long)ans ;
    }
