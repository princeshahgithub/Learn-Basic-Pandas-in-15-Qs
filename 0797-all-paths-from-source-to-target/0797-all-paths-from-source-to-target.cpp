class Solution {
public:

void dfs(int node,int target,vector<vector<int>>& graph,vector<int>& path,vector<vector<int>>&allPaths) {
        path.push_back(node);
        
        if(node==target)
        {
            allPaths.push_back(path);
        }
        for(int i:graph[node]) 
        {
            dfs(i,target,graph,path,allPaths);
        }
        //backtrack to prev node
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>allPaths;
        vector<int>path;
        int target = graph.size()-1;
        dfs(0,target,graph,path,allPaths);
        return allPaths;
    }
};