class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size() , p = 0, ans = 0;

        while(true){
            int freq[101]{};
            bool valid = true;
            for (int i=p ; i<n ; i++){
                freq[nums[i]]++;
                if (freq[nums[i]] > 1){
                    valid = false;
                    break;
                }
            }

            if (valid) {
                break;
            }
            ans++;
            p+=3;
        }

        return ans;
    }
};