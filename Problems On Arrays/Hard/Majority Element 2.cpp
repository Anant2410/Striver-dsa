 vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int count1=0,count2=0;
        int ans1=-1,ans2=-1;
        int n = nums.size();
        for(auto it: nums)
        {
            if(it==ans1)
            {
                count1++;
            }
            else if(it==ans2)
            {
                count2++;
            }
            else if(count1==0)
            {
                ans1 = it;
                count1 = 1;
            }
            else if(count2==0)
            {
                ans2 = it;
                count2 = 1;
            }
            else  
            {
                count1--;
                count2--;
            }
        }
        count1=count2=0;
        for(auto it: nums)
        {
            if(it==ans1) count1++;
            else if(it==ans2) count2++;
        }
        if(count1 > nums.size()/3) ans.push_back(ans1);
        if(count2 > nums.size()/3) ans.push_back(ans2);
        
        return ans;
    }
