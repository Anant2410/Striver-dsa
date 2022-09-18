class Solution {
public:
    int first(vector<int>& nums, int target){
        int start = 0,end = nums.size()-1,res = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target){
                res = mid;
                end = mid-1;
            }
            else if(nums[mid]< target)
                start = mid+1;
            else
                end = mid-1;
        }
        return res;
    }
    int last(vector<int>& nums, int target){
        int start = 0,end = nums.size()-1,res = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target){
                res = mid;
                start = mid+1;
            }
            else if(nums[mid]< target)
                start = mid+1;
            else
                end = mid-1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = first(nums,target);
        int j = last(nums,target);
        vector<int> res;
        res.push_back(i);
        res.push_back(j);
        return res;
    }
};
