class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(),[&](vector <int> &v1, vector <int> &v2){
            if (v1[0]==v2[0]) return v1[1] < v2[1];
            return v1[0] < v2[0];
        });

        int ans = meetings[0][0]-1;

        int mxmeet = meetings[0][1];
        for (int i=1 ; i < meetings.size() ; i++){
            mxmeet = max(mxmeet,meetings[i-1][1]);
            ans += max(0,meetings[i][0] - mxmeet - 1);
        }

        mxmeet = max(mxmeet,meetings.back()[1]);
        ans += days-mxmeet;

        return ans;
    }
};