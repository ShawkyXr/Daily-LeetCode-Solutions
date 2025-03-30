class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector <int> freq(26),met(26);
        int num = 0,full = 0;
        for (auto &c : s) freq[c-'a']++;
        
        vector <int> parts;
        for (int i=0 ; i<s.size() ;i++){
            if (!met[s[i]-'a']) full++;
            met[s[i]-'a']++;
            num++;
            if (met[s[i]-'a'] == freq[s[i]-'a']){
                full--;
                if (!full) parts.push_back(num) ,num = 0;
                
            }
        }

        return parts;
    }
};