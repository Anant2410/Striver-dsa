int majorityElement(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0) ans = nums[i];
            
            if(ans == nums[i]) count+=1;
            
            else count-=1;
        }
        return ans;
    }
    
    
    //gfg
    int majorityElement(int a[], int size)
    {
        map<int,int>mp;
        for(int i=0;i<size;i++){
            mp[a[i]]++;
        }
    int ans=-1;
        
    for (auto x: mp) {
    if (x.second > (size /2))
      ans=x.first;
  }
return ans;
    }
