class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map <int,int> mp;
        for (auto ans : answers) mp[ans]++;

        int ans=0;
        for (auto &r: mp){
            while(r.second > r.first){
                r.second -= r.first+1;
                ans += r.first+1;
            }
            if (r.second > 0) ans += r.first+1;
        }

        return ans;
    }
};