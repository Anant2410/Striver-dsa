long long int countandMerge(long long arr[], long long l, long long m, long long h){
       long long n1=m-l+1,n2=h-m;
       long long left[n1], right[n2];
       for(long long i=0;i<n1;i++)
       left[i]=arr[l+i];
       
       for(long long i=0;i<n2;i++)
       right[i]=arr[m+i+1];
       
       long long i=0, j=0, k=l, res=0;
       while(i<n1&&j<n2){
           if(left[i]<=right[j]){
               arr[k]=left[i];
               i++,k++;
           }else{
               arr[k]=right[j];
               j++,k++;
               res+=(n1-i);
           }
       }
       while(i<n1){
           arr[k]=left[i];
           i++,k++;
       }
       while(j<n2){
           arr[k]=right[j];
           j++,k++;
       }
       return res;
   }
   
   
   long long int countInversion(long long arr[],long long l, long long h){
       long long int res=0;
       if(h>l){
           long long m=l+(h-l)/2;
           res+=countInversion(arr,l,m);
           res+=countInversion(arr,m+1,h);
           res+=countandMerge(arr,l,m,h);
       }
       return res;
   }
    long long int inversionCount(long long arr[], long long n)
    {
        return countInversion(arr,0,n-1);
    }
