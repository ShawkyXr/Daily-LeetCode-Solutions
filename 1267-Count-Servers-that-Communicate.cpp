class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector <int> row(n),col(m);

        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ;j++){
                if (grid[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int ans = 0;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                if (grid[i][j]){
                    if (row[i]>=2 || col[j]>=2) ans++;
                }
            }
        }

        return ans;
    }
};