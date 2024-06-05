class Solution {
public:
bool solve(vector<int>& arr, int i,vector<bool>&visited)
{
    if(i>=arr.size() || i<0 || visited[i] )
    {
        return false;
    }
    if(arr[i]==0)
    {
        return true;
    }
    visited[i]=true;
    bool left = solve(arr,i-arr[i],visited);
    bool right = solve(arr,i+arr[i],visited);
    return left || right; 

}
    bool canReach(vector<int>& arr, int start) {
        vector<bool>visited(arr.size(),false);
        if(arr[start]==0) return true;
        return solve(arr, start,visited);
    }
};