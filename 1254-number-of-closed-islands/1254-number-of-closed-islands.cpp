class Solution {
public:

    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(int i,int j,vector<vector<int>>&grid){
        //what each dfs call will tell 
        //each dfs call will tell that whether the island centered around given 
        //corndinate cell is a closed one or note
        //so in the base of this recursive dfs function we checked whether 
        // it is directory touching any border of the grid

        // if the the current grid is non zero it is an indication that either there is1 
        //or that cell has already been visited 
        // then in recurrence we checked whether any neighbour of it is unclosed or not 
        //if so then the island from the currrent cell will also be an unclosed one



          if(i<0||j<0||i>=grid.size()||j>=grid[0].size()){
              return false;
          }
          if(grid[i][j]!=0){
              return true;
          }
        //   vis[i][j]=1;
        grid[i][j]=1;
          bool ist=true;
          for(auto e:dir){
              int nx=e[0]+i;
              int ny=e[1]+j;
              if(dfs(nx,ny,grid)==false){
                  ist=false;
              }
          }
          return ist;

    }

    bool bfs (int i,int j,vector<vector<int>>&grid){

        //here each bfs call will tell whether the island of which the current cell is 
        //part of is a closed one or not 
        queue<vector<int>>qp;
        qp.push({i,j});
        bool pos=true;

        while(!qp.empty()){
            auto t= qp.front();
            qp.pop();
            grid[t[0]][t[1]]=1;
            for(auto e:dir){
                int nx=t[0]+e[0];
                int ny=t[1]+e[1];
                if(nx<0||ny<0||nx>=grid.size()||ny>=grid[0].size()){
                    pos=false;
                }else if(grid[nx][ny]==1){
                    continue;
                }else{
                    qp.push({nx,ny});

                }
            }
        }
        return pos;

    }
   
    int closedIsland(vector<vector<int>>& grid) {



        //intuition is that each time a zero cell is encountered we try to find 
        //whether any cell in its connected component is touching the boundary of the grid 
        //in that case that island cannot be a closed island in rest of the cases that 
        //island will be a connected component 
        //do not use a visited array just modify the grid in  place as visted array '
        //this is a space optimsation step

        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0    && bfs(i,j,grid)){
                    c++;
                }
            }
        }
        return c;




        
    }
};