class Solution {
    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freq[26]{};

        for (auto &b : words2){
            int tmpf[26]{};
            for (auto &c : b){
                tmpf[c-'a']++;
            }
            for (int i=0 ; i<26  ;i++){
                freq[i] = max(freq[i],tmpf[i]);
            }
        }

        vector <string> ans;
        for (auto &a : words1){
            bool uni = true;
            int tmpf[26]{};
            for (auto &c : a){
                tmpf[c-'a']++;
            }
            for (int i=0 ; i<26  ;i++){
                if (tmpf[i] < freq[i]) uni = false;
            }
            if (uni) ans.push_back(a);
        }
        
        return ans;
    }
};