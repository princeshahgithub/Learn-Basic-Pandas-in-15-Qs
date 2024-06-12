class Solution {
public:
    void dfs(int &m,int &n,int i,int j,vector<vector<int>>&visit,
        vector<vector<int>>&grid){
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        visit[i][j] = 1;

        for(int k = 0;k<4;k++){
            int newrow = i + delrow[k];
            int newcol = j + delcol[k];
            if(newrow >= 0 && newrow < m && newcol >= 0 && newcol < n &&
             !visit[newrow][newcol] && grid[newrow][newcol] == 1){
                 dfs(m,n,newrow,newcol,visit,grid);
             }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visit(m,vector<int>(n,0));

        for(int i = 0 ;i<n;i++){
            if(grid[0][i] == 1){
                dfs(m,n,0,i,visit,grid);
            }
            if(grid[m-1][i] == 1){
                dfs(m,n,m-1,i,visit,grid);
            }
        }
        for(int i = 0;i<m;i++){
            if(grid[i][0] == 1 && !visit[i][0]){
                dfs(m,n,i,0,visit,grid);
            }
            if(grid[i][n-1] == 1 && !visit[i][n-1]){
                dfs(m,n,i,n-1,visit,grid);
            }
        }
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!visit[i][j] && grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};