class Solution {
public:
    vector<vector<long long>> dp;
    long long tryall(int i,int j,vector<int>& r, vector<int>& f){
        if (i==r.size()) return 0;
        if (j==f.size()) return 10000000000000;
        long long &ret = dp[i][j];
        if (ret!=-1) return ret;
        long long ch1 = tryall(i+1,j+1,r,f)+abs(r[i]-f[j]);
        long long ch2 = tryall(i,j+1,r,f);
        return ret = min(ch1,ch2);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> f;
        for (auto i:factory){
            for (int j=0 ; j<i[1] ; j++){
                f.push_back(i[0]);
            }
        }
        dp.assign(robot.size(),vector<long long>(f.size(),-1));
        return tryall(0,0,robot,f);
    }
};