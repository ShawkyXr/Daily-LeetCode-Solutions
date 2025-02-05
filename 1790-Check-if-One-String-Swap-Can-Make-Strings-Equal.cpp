class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map <char,int> mp,mp2;
        
        for (auto i : s1) mp[i]++;
        for (auto i : s2) mp2[i]++;

        for (char c = 'a' ; c<='z' ; c++){
            if (mp[c] != mp2[c]) return false;
        }

        int dif = 0;

        for (int i=0 ; i<s1.size() ; i++){
            if (s1[i] != s2[i]) dif++;
        }

        return dif <=2;
    }
};