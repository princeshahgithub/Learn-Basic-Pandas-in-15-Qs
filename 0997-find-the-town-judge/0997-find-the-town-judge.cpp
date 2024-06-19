class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>v1(1000,0);
        vector<int>v2(1000,0);
        int x = trust.size();
        for(int i=0;i<x;i++){
            v1[trust[i][0]-1]++;
            v2[trust[i][1]-1]++;
        }
        vector<int>v;
        for(int i=0;i<1000;i++){
            // if(v1[i]==v2[i])return -1;
            if(v1[i]==0){
                if(i+1>n){return -1;}
                if(v2[i]==n-1) return i+1;
            }
        }
        return -1;
    }
};