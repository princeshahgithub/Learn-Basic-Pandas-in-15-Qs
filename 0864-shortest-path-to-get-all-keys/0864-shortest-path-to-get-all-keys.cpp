class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int keys = 0;
        queue<vector<int>> q; //{i,j,mask}
        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(islower(grid[i][j]))keys++;
                else if(grid[i][j]=='@')
                {
                    q.push({i,j,0});
                }
            }
        } 
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        set<vector<int>>vis;
        int ans =0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0;i<sz;i++)
            {
                vector<int> temp = q.front();
                q.pop();
                int x = temp[0];
                int y = temp[1];
                int mask = temp[2];
                if(__builtin_popcount(mask) == keys) return ans;
                for(int k = 0;k<4;k++)
                {
                    int nrow = x + dx[k];
                    int ncol = y + dy[k];
                    if(nrow < 0 || nrow >=n || ncol < 0 || ncol >=m || grid[nrow][ncol]=='#') continue;
                    int curr_mask = mask;
                    char ch = grid[nrow][ncol];
                    if(ch >= 'a' && ch <= 'z' )
                    {
                        curr_mask |= (1<< (ch - 'a'));
                    }
                    if(vis.find({nrow, ncol, curr_mask})!= vis.end()) continue;
                    if(ch >= 'A' && ch <= 'Z')
                    {
                        if((mask & (1<<(ch-'A')))== 0) continue;
                    }
                    q.push({nrow, ncol, curr_mask});
                    vis.insert({{nrow, ncol, curr_mask}});
                }
            }
            ans++;
        }
        return -1;
    }
};