bool f(int i, int arr[] , int n , int k, int sum)
	{
	    if(i==n)
	    {
	        if(sum==k)
	        return true;;
	        
	        return false;
	    }
	    sum += arr[i];
	     if(f(i+1,arr,n,k,sum)) return true;
	    sum -= arr[i];
	     if(f(i+1,arr,n,k,sum)) return true;
	    
	    return false;
	}
	bool perfectSum(int arr[], int n, int sum)
	{
        return f(0,arr,n,sum,0);
	}
