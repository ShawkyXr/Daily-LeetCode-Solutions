class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int z=0 , o =n-1;
        vector <int> zeros(n),ones(n);
        zeros[0] = (s[0]=='0'? 1:0);
        ones[n-1] = (s[n-1]=='1'? 1:0);
        for (int i = 1 ;i<n ; i++){
            zeros[i] += zeros[i-1] + (s[i]=='0'? 1:0);
        }
        
        for (int i = n-2 ; i>=0 ;i--){
            ones[i]+=ones[i+1] +(s[i]=='1'? 1:0);
        }

        int ans = 0;
        for (int i=1 ;i<n ;i++){
            ans = max(ans,zeros[i-1]+ones[i]);
        }

        return ans;
    }
};