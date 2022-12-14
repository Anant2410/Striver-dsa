	int NthRoot(int n, int m)
	{
	    long long low = 1, high = m;
	    while(low<=high)
	    {
	        long long mid = (high+low)/2;
	        if(pow(mid,n) == m) return mid;
	        
	        else if(pow(mid,n) > m) high = mid-1;
	        else low = mid+1; 
	    }
	    return -1;
	}  
