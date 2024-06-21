class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& r) {
        vector<int> v(n,0);
        
        for(auto &it:r) sort(it.begin(),it.end());  // to reduce time complexity
        sort(r.begin(),r.end());                    // to reduce time complexity
		
        for(auto it: r) v[it[0]]++, v[it[1]]++;
        
        int it = *max_element(v.begin(), v.end());
        int xxx = 0;
        for(auto i: v)if(i<it) xxx = max(xxx, i);
        
        vector<vector<int>> t;
        for( int i = 0;i<n;i++) if(v[i]==it or v[i] == xxx) t.push_back({i,v[i]}); 
        
        int tt = t.size();
        int ans = 0,x;
        for(int i = 0;i<tt;i++){
            for(int j = i+1;j<tt;j++){
                x = 0;
                x+=t[i][1] + t[j][1];
                if(binary_search(r.begin(),r.end(),vector{min(t[i][0] , t[j][0]), max(t[i][0] , t[j][0])})) x--;
                ans = max(ans,x);
            }
        }
        
        return ans;
    }
};