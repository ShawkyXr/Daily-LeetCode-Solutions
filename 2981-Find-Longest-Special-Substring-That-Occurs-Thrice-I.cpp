class Solution {
public:
    int maximumLength(string s) {
        map <char,vector<int>> mp;
        for (int i=0 ; i<26 ; i++){
            int sub=0;
            for (int j=0 ; j<s.size() ;j++){
                if (s[j]-'a'==i){
                    sub++;
                }else{
                    if (sub) mp['a'+i].push_back(sub);
                    sub=0;
                }
            }
            if (sub) mp[i+'a'].push_back(sub);
        }
        int ans=-1;
        for (auto ch : mp){
            sort(ch.second.rbegin(),ch.second.rend());
            int mx=-1;
            for (int i=0 ; i<min(3,(int)ch.second.size()) ;i++){
                if (i==0){
                    mx = max(ch.second[i]-2,mx);
                }else if (i==1){
                    if (ch.second[i]==ch.second[i-1]){
                        mx = max(mx,ch.second[i]-1);
                    }else{
                        mx = max(mx,ch.second[i]);
                    }
                }else{
                      mx = max(mx,ch.second[i]);
                }
            }
            if (!mx) mx = -1;
            ans = max(ans,mx);
        }
        return ans;
    }
};