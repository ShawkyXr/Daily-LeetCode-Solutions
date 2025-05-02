class Solution {
public:
    string pushDominoes(string dominoes) {
        int lstr = -1,lstl = -1;
        string ans = "";
        for (int i=0 ;i<dominoes.size() ; i++){
            if (dominoes[i]=='R'){
                if (lstr > lstl){
                    int p = i-1;
                    while (p>lstr){
                        ans[p] = 'R';
                        p--;
                    }
                }
                lstr = i;
            }
            if (dominoes[i]=='L'){
                cout << lstr << " " << lstl << "\n";
                if (lstr > lstl){
                    int p1 = lstr+1 , p2=i-1;
                    while(p1<p2){
                        ans[p1] = 'R';
                        ans[p2] = 'L';
                        p1++,p2--;
                    }
                }else if (lstr <= lstl){
                    int p = i-1;
                    while (p>lstl){
                        ans[p] = 'L';
                        p--;
                    }
                }
                lstl = i;
            }
            ans.push_back(dominoes[i]);
        }

        if (lstr > lstl){
            int p = dominoes.size()-1;
                while (p>lstr){
                    ans[p] = 'R';
                     p--;
                }
         }
            
        return ans;
    }
};