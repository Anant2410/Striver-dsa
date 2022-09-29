int findKRotation(int arr[], int n) {
	    int low = 0, high = n-1;
	    while(low<high)
	    {
	        int mid = low + (high-low)/2;
	        
	        if(arr[mid] < arr[high]) high = mid;
	        else if(arr[mid] > arr[high]) low = mid+1;
	        else return mid;
	    }
	    return low;
	}