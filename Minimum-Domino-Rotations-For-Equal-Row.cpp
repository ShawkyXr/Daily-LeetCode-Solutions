class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX,n = tops.size();
        for (int target = 1 ; target <=6 ; target++){
            int maketop = 0, makebottom = 0,i=0;
            for ( ; i<n ; i++){
                if (tops[i]!=target && bottoms[i]!=target) break;
                if (tops[i]==target) makebottom++;
                if (bottoms[i]==target) maketop++;
            }
            if (i==n) ans = min({ans,n-maketop,n-makebottom});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};