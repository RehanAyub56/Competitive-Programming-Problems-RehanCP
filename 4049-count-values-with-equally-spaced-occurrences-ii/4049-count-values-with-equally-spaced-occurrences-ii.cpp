class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        v.push_back({INT_MAX,INT_MAX});
        int ans=0;
        stable_sort(v.begin(),v.end());
        vector<int>a;
        for(int i=1;i<v.size();i++){
            if(v[i].first==v[i-1].first){
                a.push_back(v[i].second-v[i-1].second);
            }
            else{
                if(a.size()>=2){
                    bool yes=true;
                    for(int k=1;k<a.size();k++){
                        if(a[k]!=a[k-1]){
                            yes=false;
                            break;
                        }
                    }

                    if(yes){
                        ans++;
                    }
                }
                a.clear();
            }
        }

        return ans;
        
    }
};