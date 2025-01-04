class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        map <char,pair<int,int>> freq;

        for (int i=0 ; i<26 ; i++){
            int start = n , end = 0;
            for (int j=0 ; j<n ; j++){
                if (s[j]-'a' == i) {
                    start = min(start,j);
                    end = max(end,j);
                }
            }
            if (start!=n) freq['a'+i] = {start,end};
        }

        int ans=0;

        for (auto & i: freq){
            cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
        }

        for (int i=0 ; i<26 ; i++){
            if (freq.count(char('a'+i))){
                int done[26]{};
                for (int j= freq[i+'a'].first+1 ; j<freq[i+'a'].second ; j++){
                    if (!done[s[j]-'a']){
                        ans++;
                        done[s[j]-'a'] = 1;
                        cout << char('a'+i) << " " << s[j] << " " << char('a'+i) << "\n"; 
                    }
                }
            }
        }

        return ans;
    }
};