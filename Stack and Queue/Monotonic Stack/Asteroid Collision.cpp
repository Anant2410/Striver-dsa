//agar a[i] < 0 hai aur stack ka top >0 hai tabhi case handle karna hai verna mat karna //
//

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(auto it: asteroids)
        {
            if(it>0)
            {
                st.push(it);
            }
            else
            {
                while(!st.empty() && st.top() > 0 && st.top() < -it) // this is the case i am talking about 
                {
                    st.pop();
                }
                if(!st.empty() && st.top() == -it) // agar both are equal tab bhi pop karna 
                {
                    st.pop();
                }
                else if(!st.empty() && st.top() > -it)
                {
                    continue;
                }
                else
                {
                    st.push(it);
                }
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
