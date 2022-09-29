void rearrange(int arr[], int n) {
	   vector<int> pos;
	   vector<int> neg;
	   for(int i=0;i<n;i++)
	   {
	       if(arr[i] >=0)
	       {
	           pos.push_back(arr[i]);
	       }
	       else
	       {
	           neg.push_back(arr[i]);
	       }
	   }
	   int pn = pos.size();
	   int nn = neg.size();
	   int i=0,j=0;
	   int k = 0 ;
	   while(i<pn && j<nn)
	   {
	       arr[k++] = pos[i++];
	       arr[k++] = neg[j++];
	   }
	   while(i<pn)
	   {
	       arr[k++] = pos[i++];
	   }
	   while(j<nn)
	   {
	       arr[k++] = neg[j++];
	   }
	}
  
  //leetcode//
  
  vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int pos =0,neg=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > 0)
            {
                ans[pos] = nums[i];
                pos+= 2;
            }
            else
            {
                ans[neg] = nums[i];
                neg+= 2;
            }
        }
        return ans;
    }
