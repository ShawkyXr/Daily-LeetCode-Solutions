class Solution {

    struct node{
        double pass;
        double num;
        double perc;

        node(int p,int n): pass(p),num(n), perc(pass/(double)num) {};

        bool operator < (const node other) const{
            return ((pass+1)/(num+1))-(pass/num) < ((other.pass+1) /( other.num+1))-(other.pass / other.num);
        }
    };

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue <node> pq;

        for (auto &c : classes){
            pq.push(node(c[0],c[1]));
        }

        while(extraStudents--){
            node mn = pq.top();
            pq.pop();
            node nw(mn.pass+1,mn.num+1);
            pq.push(nw);
        }

        double ans = 0.0;

        while(!pq.empty()){
            node mn = pq.top();
            pq.pop();
            ans += mn.perc;
        }
        ans = ans/double(classes.size());

        return ans;
    }
};