class dsu{
    private:
    vector<int>parent,size;

    public:

    dsu(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }

    int LargestParent(int u){
        if(parent[u]==u){
            return u;
        }
        
        return parent[u]=LargestParent(parent[u]);
    }

    void Findunion(int u,int v){
        int LP_u=LargestParent(u);
        int LP_v=LargestParent(v);

        if(size[LP_u]<size[LP_v]){
            size[LP_v]+=size[LP_u];
            parent[LP_u]=parent[LP_v];
        }
        else{
            size[LP_u]+=size[LP_v];
            parent[LP_v]=parent[LP_u];
        }
    }



};

class Solution {
public:


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu ds(n);

        for(int i=0;i<n;i++){
            int x=edges[i][0];
            int y=edges[i][1];

            int P_u=ds.LargestParent(x);
            int P_v=ds.LargestParent(y);

            if(P_v==P_u){
                return {x,y};
            }
            else{
                ds.Findunion(x,y);
            }
        }
        
        return {};

    }
};