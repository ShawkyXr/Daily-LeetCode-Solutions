class Solution {

    struct node {
        int i, j;

        node() : i(-1), j(-1) {} 
        node(int i, int j) : i(i), j(j) {}

        bool operator==(const node &other) const {
            return i == other.i && j == other.j;
        }

        bool operator<(const node &other) const {
            if (i != other.i) return i < other.i;
            return j < other.j;
        }
    };

    map <node,node> parent;
    map <node,int> size;
    
    node get_parent(node u){
        if (parent[u] == u){
            return u;
        }
        return parent[u] = get_parent(parent[u]);
    }

    bool connected(node u, node v){
            return get_parent(u) == get_parent(v);
    }

    void join(node u ,node v){
        if (connected(u,v)) return;

        node Pu = get_parent(u) , Pv = get_parent(v);

        if (size[Pu] < size[Pv]){
            swap(Pu,Pv);
        }

        size[Pu] += size[Pv];
        parent[Pv] = Pu;

    }

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    bool valid(int i,int j,int n){
        return i>=0 && i<n && j>=0 && j<n;
    }


public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ;j++){
                if (grid[i][j]){
                    parent[node(i,j)] = node(i,j);
                    size[node(i,j)] = 1;

                    if (valid(i-1,j,grid.size()) && grid[i-1][j]){
                            join(node(i,j),node(i-1,j));
                    }

                    if (valid(i,j-1,grid.size()) && grid[i][j-1]){
                            join(node(i,j),node(i,j-1));
                    }
                }
            }
        }

        int ans = 0;

        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ;j++){
                if (grid[i][j]){
                    node Pu = get_parent(node(i,j));
                    ans = max(ans,size[Pu]);
                }else{
                    set <node> neig;
                    for (int k=0 ; k<4 ;k++){
                        if (!valid(i+dx[k],j+dy[k],grid.size())) continue;
                        if (!grid[i+dx[k]][j+dy[k]]) continue;
                        node Pu = get_parent(node(i+dx[k],j+dy[k]));
                        neig.emplace(Pu);
                    }
                    int island = 1;
                    for (auto is : neig){
                        island += size[is];
                    }

                    ans = max(ans,island);
                }
            }
        }

        return ans;
    }
};