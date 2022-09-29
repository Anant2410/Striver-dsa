void f(int arr[] , int l, int h)
	{
	    while(l<h)
	    {
	        int temp = arr[l];
	        arr[l] = arr[h];
	        arr[h] = temp;
	        l++;
	        h--;
	    }
	}
	void leftRotate(int arr[], int k, int n) 
	{ 
	  k = k%n;
	  if(k==0) return ;
	  f(arr,0,k-1);
	  f(arr,k,n-1);
	  f(arr,0,n-1);
	} 
  
  // leetcode
  void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(k==0) return ;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
