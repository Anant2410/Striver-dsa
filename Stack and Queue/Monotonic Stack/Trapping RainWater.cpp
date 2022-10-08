// hume ye pta hai ki water can be stored by the formulae min(left[i], right[i]) - arr[i] 
//ab ye code isliye chal rha hai kyuki ye hume assurance de rha hai kki right me aesa kuch hai jo ki is building se bda hai tabhi to um yahan tak aagye 
//hai verna nii aa pate//
//same thing happen with the right one //


class Solution {
public:
    
    // we know  the water can be stored is min(left[i], right[i]) - arr[i]//
    // this works as it guarantee us that the height is greater int he right part that,s why we reached here//
    int trap(vector<int>& height) {
        int ans = 0, maxl=0,maxr=0,low=0,high=height.size()-1;
        while(low<=high)
        {
            if(height[low] <= height[high])
            {
                if(height[low] > maxl)
                {
                    maxl = height[low];
                }
                else
                {
                    ans += maxl - height[low];
                }
                low++;
            }
            else if(height[high] < height[low])
            {
                if(height[high] > maxr)
                {
                    maxr = height[high];
                }
                else
                {
                    ans += maxr - height[high];
                }
                high--;
            }
        }
        return ans;
    }
};
