class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector <int> ans;
        for (int i=0 ; i<n ; i++){
            if (digits[i]==0) continue;
            for (int j = 0 ; j<n ; j++){
                for (int k=0 ; k<n ; k++){
                    if (i==j || j == k || k==i) continue;
                    int num = digits[i];
                    num *= 10;
                    num+=digits[j];
                    num*=10;
                    num+=digits[k];
                    if (num%2==0) ans.push_back(num);
                }
            }
        }
        if (ans.empty()) return {};
        sort(ans.begin(),ans.end());
        vector <int> ret;
        ret.push_back(ans[0]);
        for (int i=1 ; i<ans.size() ; i++){
            if (ans[i]!=ans[i-1]) ret.push_back(ans[i]);
        }
        return ret;
    }
};