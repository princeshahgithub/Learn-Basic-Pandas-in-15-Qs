class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        vector<int>vis(rooms.size(),0);
        vis[0]=1;
      vector<int>st(rooms.size()+1,0);
        for(int i=0;i<rooms[0].size();i++){
            q.push(rooms[0][i]);
        }
     while(q.size()){
            int s=q.size();
            for(int j=0;j<s;j++){
                int a=q.front();
                q.pop();
                if(vis[a]==0){
                    vis[a]=1;
                 for(int k=0;k<rooms[a].size();k++){

                     q.push(rooms[a][k]);
    
                 }
                }
            }
        }
        for(auto it:vis) cout<<it<<" ";
        for(int i=1;i<rooms.size();i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};