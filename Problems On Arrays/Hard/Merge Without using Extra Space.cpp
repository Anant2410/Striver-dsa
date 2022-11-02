// gap ko half krna hai//

class Solution {
public:
    int f(int gap)
    {
        if(gap<=1) return 0;
        
        return (gap/2) + (gap%2);
    }
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i,j,gap = n+m;
        
        for(gap = f(gap) ; gap > 0 ; gap = f(gap))
        {
            for(i=0;i+gap<n;i++)
            {
                if(nums1[i] > nums1[i+gap])
                    swap(nums1[i], nums1[i+gap]);
            }
        }
        
        for(j = gap > n ? gap-n:0;i<n && j<m ; i++,j++)
        {
            if(nums1[i] > nums2[j])
                swap(nums1[i],nums2[j]);
        }
        if(j<m)
        {
             for(j=0;j+gap<m;j++)
            {
                if(nums2[j] > nums2[j+gap])
                    swap(nums2[j], nums2[j+gap]);
            }
        }
    }
};
