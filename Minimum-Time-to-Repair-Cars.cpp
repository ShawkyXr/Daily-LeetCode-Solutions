class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1 , r = 1e18,ans = r;
        while(l <= r){
            long long md = (l+r)/2;
            
            long long cnt = 0;
            for (auto &r : ranks){
                cnt += sqrt(md/r);
            }

            if (cnt >= cars){
                r = md-1;
                ans = md;
            }else{
                l = md +1;
            }
        }

        return ans;
    }
};