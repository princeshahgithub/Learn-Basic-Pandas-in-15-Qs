class Solution {
public:
void dfs(int node, vector<int> adj[], vector<int> &dp, vector<int>& informTime){
    for(auto it: adj[node]){
        dfs(it, adj, dp, informTime);
        dp[node] = max(informTime[node] + dp[it], dp[node]);
    }
}
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(manager[i] != -1) adj[manager[i]].push_back(i);
        }
        vector<int> dp(n, 0);
        dfs(headID, adj, dp, informTime);
        return dp[headID];
    }
};