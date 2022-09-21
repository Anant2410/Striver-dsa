 int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(arr[mid] - (1 + mid) < k)       // arr[mid] - (1+mid) it gives the  number of missing numbers before arr[mid];
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return low + k;
    }
