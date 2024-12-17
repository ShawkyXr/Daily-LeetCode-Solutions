class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map <char,int> mp;
        for (auto &c :s){
            mp[c]++;
        }

        vector<pair<char,int>> vec;

        for (auto &m : mp){
            vec.push_back({m.first,m.second});
        }
        reverse(vec.begin(),vec.end());
        
        string ans="";

        for (int i=0 ; i<vec.size() ; i++){
            // cout << vec[i].second << " ";
            for (int j=0 ; j < repeatLimit ;j++){
                if (vec[i].second<=0) break;
                ans+=vec[i].first;
                vec[i].second--;
            }

            if (vec[i].second){
                bool found = 0;
                for (int k=i+1; k<vec.size() ;k++){
                    if (vec[k].second){
                        ans+=vec[k].first;
                        vec[k].second --;
                        found =1;
                        i--;
                        break;
                    }
                }
                if (!found) return ans;
            }
        }
        
        return ans;
    }
};