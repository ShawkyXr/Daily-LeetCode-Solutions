class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        priority_queue <int,vector<int>,greater<int>> a,b,c;
        for (int i=0 ; i<n ;i++){
            if (s[i]=='a') a.push(i);
            if (s[i]=='b') b.push(i);
            if (s[i]=='c') c.push(i);
        }
        int cnt = 0;
        for (int i=0 ; i<n ; i++){
            if (a.empty() || b.empty() || c.empty()) break;
            int topa = a.top(),topb = b.top(), topc = c.top();
            if (topa<=i) a.pop();
            if (topb<=i) b.pop();
            if (topc<=i) c.pop();
            cnt += n-max({topa,topb,topc});
        }
        return cnt;
    }
};