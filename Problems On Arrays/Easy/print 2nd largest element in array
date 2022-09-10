int print2largest(int arr[], int n) {
	    int ans = INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        ans = max(ans, arr[i]);
	    }
	    int res = -1;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i] == ans) continue;
	        res = max(res, arr[i]);
	    }
	    return res;
	}
