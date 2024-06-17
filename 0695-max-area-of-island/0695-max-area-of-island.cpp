class Solution {
    int helper(vector<vector<int>>& grid,int i,int j,int m,int n){
        
        if(i<0 || j<0 || i>=m || j>=n)
            return 0;
        if(grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        
        int ret=1;
        ret=ret+helper(grid,i-1,j,m,n);
        ret=ret+helper(grid,i,j-1,m,n);
        ret=ret+helper(grid,i+1,j,m,n);
        ret=ret+helper(grid,i,j+1,m,n);
        
        return ret;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int rr=helper(grid,i,j,m,n);
                // cout<<rr<<endl;
                if(ret<rr)
                    ret=rr;
            }
        }
        return ret;
    }
};