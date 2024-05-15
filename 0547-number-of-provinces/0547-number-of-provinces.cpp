class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        int res = n;

        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] == 1) 
                {
                    int x = Find(i, parent);
                    int y = Find(j, parent);

                    if (x == y) continue;

                    res--;
                    if (x > y) 
                        parent[x] = y;
                    else
                        parent[y] = x;
                }
            }
        }

        return res;
    }

private:

    int Find(int x, vector<int>& parent)
    {
        if (x != parent[x]) 
        {
            parent[x] = Find(parent[x], parent);
        }

        return parent[x];
    }
};