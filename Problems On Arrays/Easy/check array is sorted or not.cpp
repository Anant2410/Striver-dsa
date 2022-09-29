bool arraySortedOrNot(int arr[], int n) {
        for(int i=0;i<n-1;i++)
        {
            if(arr[i] > arr[i+1]) return false;
        }
        return true;
    }
    
    
// leetcode :- check array is sorted and rotated//
bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n])count++;
        }
        
        return count<=1;
    }
