/* this algo is used to find shortest distance from every node to every other node
we use adjmatrix to store the minimum path from every node to every node
for detecting -ve cycle:
for(int i=0;i<n;i++)
{if(matrix[i][i]<0) then yes -ve cycle}
*/
void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j] == -1)
	            {
	                matrix[i][j] = 1e9;
	            }
	            if(i==j) matrix[i][j] = 0;
	        }
	    }
	    //main logic of floyd warshall
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                matrix[i][j] = min(matrix[i][j], 
	                matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j] == 1e9)
	            {
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
