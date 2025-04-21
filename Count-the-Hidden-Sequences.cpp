class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector <long long> pre;
        for (auto &dif : differences){
            if (pre.empty()) pre.push_back(dif);
            else pre.push_back(pre.back()+dif);
        }

        long long mn = *min_element(pre.begin(),pre.end());
        int mx = *max_element(pre.begin(),pre.end());

        long long ans = 0;
        for (long long i=lower ; i<=upper ; i++){
            if (i+mx>=lower && i+mx<=upper && i+mn >= lower && i+mn <= upper)
                ans++;
        }

        return ans;
    }
};