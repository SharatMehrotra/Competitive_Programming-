/*1219
Find max gold.
*/
int maxfunc(int x,int y,int z,int a)
    {
        return max(x,max(y,max(z,a)));
    }
int dfs(vector<vector<int>>&grid,int i,int j,int m, int n,vector<vector<bool>>&visited)   // Use & to reduce running time. 
    {
        if(i<0 || j<0 || i==m|| j==n|| grid[i][j]==0 || visited[i][j])
            return 0;
        visited[i][j]=true;
        int maxval=maxfunc(dfs(grid,i+1,j, m,n, visited),dfs(grid,i-1,j,m,n,visited),dfs(grid,i,j-1,m,n, visited),dfs(grid,i,j+1,m,n,visited)); // cannot visit a visited vertex.Hence cannot backtrack and just choose the max of the initial 4 movements.
        visited[i][j]=false;  
        return maxval+grid[i][j];
    }
int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));  // avoid initializing vectors in loop. takes more time. got TLE
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                res=max(res,dfs(grid,i,j,m,n,visited));
            }
        }
        return res;
        }
