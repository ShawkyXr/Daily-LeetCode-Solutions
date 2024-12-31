class Solution {
    int dp[365][365+30]{};
    int rec(int i,int low,int high,vector<int>& days, vector<int>& costs){
        if (i >= days.size()) return 0;
        int ch1 = INT_MAX;
        int ch2 = INT_MAX;
        int ch3 = INT_MAX;
        int &ret = dp[i][high];
        if (~ret) return ret;
        if (days[i] >= low && days[i] <= high){
            ch1 = rec(i+1,low,high,days,costs);
        }else{
            ch1 = rec(i+1,days[i],days[i],days,costs) + costs[0];
            ch2 = rec(i+1,days[i],days[i]+6,days,costs) + costs[1];
            ch3 = rec(i+1,days[i],days[i]+29,days,costs) + costs[2];
        }
        return ret = min({ch1,ch2,ch3});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,days,costs);
    }
};