class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector <int> freq(26);

        for (auto &c : s){
            freq[c-'a']++;
        }

        int cntz = freq[25];
        freq[25] = 0;
        for(int i=0 ; i<t ; i++){
            for (int j=25 ; j>0 ; j--){
                freq[j] = freq[j-1];
            }
            freq[0] =  cntz;
            freq[1] = (freq[1]%1000000007 + cntz%1000000007)%1000000007;
            cntz = freq[25];
            freq[25] = 0;
        }

        int ans = 0;

        for (int i=0 ; i<25 ; i++){
            ans = (ans%1000000007 + freq[i]%1000000007) %1000000007;
        }
        ans = (ans%1000000007 + cntz%1000000007) %1000000007;
        return ans;
    }
};