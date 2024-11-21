class Solution {

    vector<vector<int>> ans; 

public:

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        ans.assign(m,vector<int>(n,1));
        for (auto wall : walls){
            ans[wall[0]][wall[1]] = -1;
        }
        
        for (auto guard : guards){
            ans[guard[0]][guard[1]]=-1;
        }
        
        for (auto guard : guards){
            
            // guard down
            int x = guard[0]+1,y = guard[1];
            while(x < m && ans[x][y]>=0){
                ans[x][y] = 0;
                x++;
            }

            // guard up
            x = guard[0]-1,y = guard[1];
            while (x>=0 && ans[x][y]>=0){
                ans[x][y] = 0;
                x--;
            }

            // guard right
             x = guard[0],y = guard[1]+1;
            while (y<n && ans[x][y]>=0 ){
                ans[x][y] = 0;
                y++;
            }

            // guard left
             x = guard[0],y = guard[1]-1;
            while (y>=0 && ans[x][y]>=0){
                ans[x][y] = 0;
                y--;
            }
        }

        int ret = 0;

        for (int i=0 ;i<m ;i++){
            for (int j=0 ; j<n ; j++){
                if (ans[i][j]>0) ret++;
            }
        }
       
        return ret;
    }
};