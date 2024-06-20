class Solution {
public:
	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& v) {
		vector<int> adj[n];vector<int> a;
		for(auto it:v)adj[it[1]].push_back(it[0]);
		for(int i=0;i<n;i++)if(adj[i].size()==0)a.push_back(i);
		return a; 
	}
};