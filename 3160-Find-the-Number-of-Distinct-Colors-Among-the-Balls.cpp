class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map <int,int> colorscount;
        unordered_map <int,int> colorofx;
        
        vector <int> ans;

        int dis = 0;
        for (auto q : queries){
            int x = q[0], y = q[1];

            if (colorofx.count(x)){
                int curcolor = colorofx[x];
                colorscount[curcolor]--;
                if (!colorscount[curcolor]) dis--; 
            }
            colorofx[x] = y;
            colorscount[y]++;
            if (colorscount[y] == 1) dis++;
            ans.push_back(dis);
        }

        return ans;
    }
};