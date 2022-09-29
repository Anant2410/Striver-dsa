int smaller(vector<int>& row, int mid)
    {
        int low = 0, high = row.size()-1;
        while(low<=high)
        {
            int x = low + (high-low)/2;
            if(row[x] <= mid) low = x+1;
            else high = x-1;
        }
        return low;
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        int low = 1, high = 1e9;
        int n = matrix.size(),m = matrix[0].size();
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int cnt = 0;
            for(int i=0;i<n;i++)
            {
                cnt += smaller(matrix[i], mid);
            }
            if(cnt <= (n*m)/2) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
