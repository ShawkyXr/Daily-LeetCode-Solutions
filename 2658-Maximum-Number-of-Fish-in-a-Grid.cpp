class Solution {
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};

    int n,m;

    bool valid(int i, int j){
        return i >=0 && i <n && j>=0 && j < m;
    }

    int dfs(int i,int j, vector<vector<int>>& grid){
        if (!valid(i,j) || grid[i][j] == 0) return 0;
        
        int ans = grid[i][j];
        grid[i][j] = 0;
        for (int k=0 ; k<4 ; k++){
            ans += dfs(i+dx[k],j+dy[k],grid);
        }
        return ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size() , m  = grid[0].size();
        int ans = 0;
        
        for (int i=0 ; i<n ;i++){
            for (int j=0 ;j<m ; j++){
                ans = max(ans,dfs(i,j,grid));
            }
        }

        return ans;
    }
};