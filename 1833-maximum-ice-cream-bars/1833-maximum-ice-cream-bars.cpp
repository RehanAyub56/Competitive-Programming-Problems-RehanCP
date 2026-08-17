class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,costs[i]);
        }

        vector<int>cnt(mx+1,0);
        for(int i=0;i<n;i++){
            cnt[costs[i]]++;
        }

        vector<int>sorted;

        for(int i=0;i<cnt.size();i++){
            while(cnt[i]--){
                sorted.push_back(i);
            }
        }

        int i=0;
        int ans=0;
        while(i<sorted.size() && coins && sorted[i]<=coins){
            coins-=sorted[i];
            ans++;
            i++;
        }

        return ans;
    }
};