void pushZerosToEnd(int arr[], int n) {
	    vector<int> temp;
	    int c = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i] == 0)
	        {
	            c++;
	        }
	        else
	        {
	            temp.push_back(arr[i]);
	        }
	    }
	    while(c!=0)
	    {
	        temp.push_back(0);
	        c--;
	    }
	    for(int i=0;i<n;i++)
	    {
	        arr[i] = temp[i];
	    }
	}



	o(1) solution :- 
	void pushZerosToEnd(int arr[], int n) {
	    int st = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i] != 0) arr[st] = arr[i], st++;
	    }
	    for(int i = st; i<n;i++) arr[i] = 0;
	}
