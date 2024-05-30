typedef pair<int,pair<int,int>> pi;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[entrance[0]][entrance[1]]=0;
        maze[entrance[0]][entrance[1]]='+';
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({dist[entrance[0]][entrance[1]],{entrance[0],entrance[1]}});
        while(!pq.empty())
        {
            int d=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            if((x==0 or x==m-1 or y==0 or y==n-1) and maze[x][y]!='+')
                return dist[x][y];
            pq.pop();
            for(int k=0;k<4;k++)
            {
                int newx=x+dx[k];
                int newy=y+dy[k];
                if(newx<0 or newy<0 or newx>=m or newy>=n or maze[newx][newy]=='+')
                    continue;
                if(dist[newx][newy]>dist[x][y]+1)
                {
                    dist[newx][newy]=1+dist[x][y];
                    pq.push({dist[newx][newy],{newx,newy}});
                    if((newx==0 or newx==m-1 or newy==0 or newy==n-1) and maze[newx][newy]!='+')
                     return dist[newx][newy];
                }
            }
        }
        return -1;
    }
};