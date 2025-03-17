class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[501]{};
        for (auto &i : nums){
            freq[i]++;
        }

        for (int i=1 ; i<=500 ; i++){
            if (freq[i]&1) return false;
        }

        return true;
    }
};