class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long l = 1,r = accumulate(candies.begin(),candies.end(),0LL),ans = 0;
        while(l<=r){
            long long md = l + (r-l) / 2;
            
            long long cnt = 0;
            for (auto &can : candies){
                cnt += can / md;
            }

            if (cnt >= k){
                l = md+1;
                ans = md;
            }else{
                r = md-1;
            }
        }

        return ans;
    }
};