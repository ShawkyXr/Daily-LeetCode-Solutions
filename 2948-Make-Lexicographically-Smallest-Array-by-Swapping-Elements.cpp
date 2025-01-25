class Solution {
    template <typename T> struct DSU{

    public:

        int n;
        unordered_map <int,int> parent;
        unordered_map <int,deque<int>> size;


        DSU(vector<int> vec) : n(vec.size()) {

            for (int i=0 ; i<n ; i++){
                parent[vec[i]] = vec[i];
                size[vec[i]].push_back(vec[i]);
            }

        }
        

        T get_parent(T u){
            return parent[u] = (parent[u] == u ? u : get_parent(parent[u])); // path compression
        }


        bool connected(T u, T v){
            return get_parent(u) == get_parent(v);
        }


        void unoin(T u ,T v){
            

            int Pu = get_parent(u), Pv = get_parent(v);
            if (connected(u,v)) {
                if (Pv == v || Pu == u) return;
            }
            
            size[Pu].push_back(v);
            parent[Pv] = Pu;
           
        }

};

public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector <int> cp = nums;
        sort(cp.begin(),cp.end());
        
        DSU <int> dsu(cp);
        for (int i=1 ; i<cp.size() ;i++){
            if (cp[i]-cp[i-1] <= limit){
                dsu.unoin(cp[i-1],cp[i]);
            }
        }

        for (int i=0 ; i<nums.size() ; i++){
            int Pu = dsu.get_parent(nums[i]);
            nums[i] = dsu.size[Pu].front();
            dsu.size[Pu].pop_front();
        }

        return nums;
    }
};