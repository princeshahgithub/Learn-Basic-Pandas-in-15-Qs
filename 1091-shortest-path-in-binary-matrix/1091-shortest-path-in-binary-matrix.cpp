int delRow[]={-1,-1,0,+1,+1,+1,0,-1};
int delCol[]={0,+1,+1,+1,0,-1,-1,-1};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(grid[0][0] != 0) return -1;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            auto top=pq.top();
            int row=top.second.first;
            int col=top.second.second;
            int dis=top.first;
            pq.pop();
            if(row==m-1 and col==n-1) return dis;  
            for(int i=0;i<8;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and grid[nrow][ncol]==0 and dist[nrow][ncol]>dis+1){
                    dist[nrow][ncol]=dis+1;
                    pq.push({dis+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};