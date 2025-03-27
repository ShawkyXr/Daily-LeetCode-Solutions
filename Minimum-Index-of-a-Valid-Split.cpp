class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map <int,int> freq;

        int x = -1 , mx = 0;
        for (auto &n : nums) {
            freq[n]++;

            if (freq[n] > mx) {
                mx = freq[n];
                x = n;
            }
        }

        int lfreq = 0 , rfreq = mx;
        for (int i=0 ; i<nums.size() ; i++){
            if (nums[i]==x){
                lfreq++;
                rfreq--;
            }
            if (lfreq > (i+1)/2 && rfreq > (nums.size()-(i+1))/2) return i;
        }

        return -1;
    }
};