int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxi = INT_MIN;
        for(auto it: nums)
        {
            if(it==0) cnt = 0;
            else{
                cnt += 1;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }


/* gfg 
int findZeroes(int arr[], int n, int m) {
        int end=0;
        int countzero=0;
        int maxlen=INT_MIN;
        for(int i=0;i<=n;i++){
            if(i<n && arr[i]==0){
                countzero++;
            }
            if(i==n || countzero==m+1){
                maxlen=max(maxlen,i-end);
                while(countzero>m){
                    if(arr[end]==0){
                        countzero--;
                    }
                    end++;
                }
            }
        }
        return maxlen;
    }  
    
    */
