class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
         vector<int>indegree(n,0);
         //we will reverse the edges direction
        for(int i=0;i<n;i++){
            int m=graph[i].size();
            for(int j=0;j<m;j++){
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
vector<int>ans;
queue<int>q;

for(int i=0;i<n;i++){
    if(indegree[i]==0)q.push(i);
}

while(!q.empty()){
    int node=q.front();
    q.pop();
    ans.push_back(node);
    for(auto it:adj[node]){
        indegree[it]--;
        if(indegree[it]==0)q.push(it);
    }
}
sort(ans.begin(),ans.end());
return ans;
    }
};