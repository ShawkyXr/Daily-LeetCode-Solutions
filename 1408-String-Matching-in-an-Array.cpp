class Solution {
    bool is_match(string a,string b){
        if (a.size()>b.size()) return false;
        int p=0;
        for (int i=0 ; i<b.size() ; i++){
            int j=i;
            while(p < a.size() && a[p]==b[j] && j<b.size()) p++,j++;
            if (p>=a.size()) return true;
            p=0;
        }
        return false;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector <string> ans;

        for (int i=0; i<n ; i++){
            for(int j=0 ; j<n ;j++){
                if (i!=j){
                    if (is_match(words[i],words[j])){
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};