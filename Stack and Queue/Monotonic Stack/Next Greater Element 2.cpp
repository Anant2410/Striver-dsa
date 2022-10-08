// You can resize the array like 1,3,5,4,2 to 1,3,5,4,2,1,3,5,4,2.
//Now just apply the logic in the code given below  //

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() && st.top() <= nums[i%n])
            {
                st.pop();
            }
            if(i<n)
            {
                if(!st.empty())
                    ans[i%n] = st.top();
                else
                    ans[i%n] = -1;
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};
