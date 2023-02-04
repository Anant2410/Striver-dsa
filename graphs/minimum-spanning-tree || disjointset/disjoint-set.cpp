int find(int A[],int X)
{
       if(A[X] == X) return X;
      return A[X] = find(A, A[X]);
}
void unionSet(int A[],int X,int Z)
{
    int parx = find(A,X);
    int parz = find(A,Z);
    if(parx == parz) return;
    else 
    {
        A[parx] = parz;
    }
}
