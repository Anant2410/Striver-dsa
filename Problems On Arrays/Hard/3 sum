int closest3Sum(int arr[], int n, int tar)
    {
        sort(arr,arr+n);
        int diff = 1e9;
        int ans;
        for(int i=0;i<n-2;i++)
        {
            int res = tar- arr[i];
            int l = i+1,h = n-1;
            while(l<h)
            {
                int sum = arr[l] + arr[h];
                
                if(sum == res)
                {
                    return tar;
                }
                else if(abs(sum-res) < diff)
                {
                    if(sum-res >0)
                    {
                        diff = sum - res;
                    }
                    else
                    {
                        diff = res - sum;
                    }
                    ans = sum + arr[i];
                }
                if(sum > res) h--;
                else l++;
            }
        }
        return ans;
    }
    
    
    
    
    
    
    // leetcode//
    
 vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || (i>0 && nums[i] != nums[i-1]))
            {
                int l = i+1, h = n-1, sum = 0 - nums[i];
                while(l<h)
                {
                    if(nums[l] + nums[h] == sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        ans.push_back(temp);
                        while(l<h && nums[l] == nums[l+1]) l++;
                        while(l<h && nums[h] == nums[h-1]) h--;
                        l++;
                        h--;
                    }
                    else if(nums[l] + nums[h] > sum)
                    {
                        h--;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        return ans
