class Solution {
    string buildcycle(){
        string s="";
        for (int i=0 ; i<26 ; i++){
            s+= char('a'+i);
        }
        return s;
    }
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        string cycle = buildcycle();
        int ptr = 0;

        vector <int> par(n+1,0);
        for (auto &op : shifts){
            int start = op[0], end = op[1];
            bool pos = op[2];
            par[start] += pos? 1 : -1;
            par[end+1] += pos? -1 : 1;
        }
        
        for (int i=1 ; i<n ; i++){
            par[i] += par[i-1];
        }

        for (int i=0 ; i<n ;i++){
            ptr = s[i]-'a';
            if (par[i]>=0){
                s[i] = 'a'+ ((ptr + par[i])%26);
            }else{
                int op = ptr + par[i]  ;
                s[i] = 'a' + ((op%26 + 26)%26); 
            }
        }

        return s;
    }
};