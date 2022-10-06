/// recursion based solution so  gives tle the optimised approach in by using Dp;


int f(int i, int arr[] , int n , int k, int sum)
	{
	    if(i==n)
	    {
	        if(sum==k)
	        return 1;
	        
	        return 0;
	    }
	    sum += arr[i];
	    int l = f(i+1,arr,n,k,sum);
	    sum -= arr[i];
	    int r = f(i+1,arr,n,k,sum);
	    
	    return l+r;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        return f(0,arr,n,sum,0);
	}
