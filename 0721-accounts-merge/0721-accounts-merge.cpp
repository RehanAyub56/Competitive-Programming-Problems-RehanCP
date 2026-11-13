class Disjoint{
    private:
    vector<int>parent,size;

    public:

    Disjoint(int n){
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int LargestParent(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=LargestParent(parent[u]);
    }

    void Findunion(int u,int v){
        int u_pu=LargestParent(u);
        int u_pv=LargestParent(v);

        if(u_pu==u_pv){
            return;
        }
        else{
            if(size[u_pu]<size[u_pv]){
                parent[u_pu]=u_pv;
                size[u_pv]+=size[u_pu];
            }
            else{
                parent[u_pv]=parent[u_pu];
                size[u_pu]+=size[u_pv];
            }
        }
    }

};



class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        map<string,int>mp;
        Disjoint ds(accounts.size());
       
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    ds.Findunion(i,mp[accounts[i][j]]);
                }
                else{
                    mp[accounts[i][j]]=i;
                }
            }
        }

        map<int,vector<string>>merged;
        for(auto it : mp){
            int x=it.second;
            string y=it.first;
            x=ds.LargestParent(x);
            merged[x].push_back(y);
        }
        vector<vector<string>>ans;
        for(auto it:merged){
            vector<string>temp;
            int x=ds.LargestParent(it.first);
            if(x==it.first){
                temp.push_back(accounts[it.first][0]);
                for(int j=0;j<it.second.size();j++){
                    temp.push_back(it.second[j]);
                }
            }
            ans.push_back(temp);
        }



        return ans;

    }
};