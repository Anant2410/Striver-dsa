bool allocation(int arr[] , int number, int student, int n)
    {
        int stu = 1,pages = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] > number) return false;
            
            if(arr[i] + pages > number)
            {
                stu++;
                pages = arr[i];
            }
            else
            {
                pages += arr[i];
            }
        }
        if(stu > student) return false;
        return true;
    }
    int findPages(int arr[], int n, int student) 
    {
        if(student > n) return -1;
        int sum = 0,mini=INT_MAX;
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            mini = min(mini,arr[i]);
            sum += arr[i];
        }
        int low = mini, high = sum;
        
        while(low<=high)
        {
            int mid  = low + (high-low)/2;
            
            if(allocation(arr,mid,student, n))
            {
                ans = mid;
                high = mid-1;
            }
            else
            low = mid+1;
        }
        return ans;
    }
