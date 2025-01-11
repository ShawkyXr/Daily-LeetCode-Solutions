class Solution {
    bool is_pal(string s,int k){
        map <char,int> mp;
        for (auto c : s) mp[c]++;
        int od =0;
        for (auto i : mp) {
            if (i.second&1) od++;
        }

        return od<=k && k < s.size();
    }
public:
    bool canConstruct(string s, int k) {
        return k==s.size() || is_pal(s,k);
    }
};