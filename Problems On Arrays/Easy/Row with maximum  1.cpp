//agar 1 aajaye  to c-- krna hai verna nahi karna 

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int r = 0;
	    int c = arr[0].size()-1;
	    int maxi = -1;
	    while(r<arr.size() && c>=0)
	    {
	        if(arr[r][c] == 1)
	        {
	            maxi = r;
	            c--;
	        }
	        
	        else
	        r++;
	    }
	    return maxi;
	}
