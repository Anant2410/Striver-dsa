class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        if(x==0 || x==1)
        {
            return x;
        }
        long long int low = 1, end = x, ans;
        
        while(low<=end)
        {
            long long int mid = low + (end-low)/2;
            
            if(mid*mid == x)
            {
                return mid;
            }
            else if(mid*mid < x)
            {
                low = mid+1;
                ans = mid;
            }
            else
            {
                end = mid-1;
            }
        }
        return ans;
    }
};
