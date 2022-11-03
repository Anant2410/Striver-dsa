class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min heap
        priority_queue<int, vector<int>, greater<int>> minh;
        for(auto it: nums)
        {
            minh.push(it);
            if(minh.size() > k)
            {
                minh.pop();
            }
        }
        return minh.top();
    }
};


//gfg for k largest number(array return krni hai basically jo bhi heap me hai usse array me dalke return krdo)

 vector<int> kLargest(int arr[], int n, int k)
    {
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>>minh;
        for(int i=0;i<n;i++)
        {
            minh.push(arr[i]);
            if(minh.size() > k)
            {
                minh.pop();
            }
        }
        while(!minh.empty())
        {
            ans.push_back(minh.top());
            minh.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
