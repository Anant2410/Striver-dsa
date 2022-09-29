int findLongestConseqSubseq(int arr[], int N)
    {
      set<int> st;
      for(int i=0;i<N;i++) st.insert(arr[i]);
      
      int ans = 0;
      for(int i=0;i<N;i++)
      {
          if(!st.count(arr[i] - 1))
          {
              int temp = arr[i];
              int len = 1;
              
              while(st.count(temp+1))
              {
                  temp += 1;
                  len += 1;
              }
              ans = max(ans,len);
          }
      }
      return ans;
    }
