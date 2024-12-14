class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int i=0,j=0;
        long long ans = 0;
        map <int,int> freq;
        while(j<nums.size()){
            freq[nums[j]]++;
            while(freq.rbegin()->first - freq.begin()->first > 2){
                freq[nums[i]]--;
                if (!freq[nums[i]]) freq.erase(nums[i]);
                i++;
            }
            j++;
            ans+=(j-i);
        }
        
        return ans;
    }
};