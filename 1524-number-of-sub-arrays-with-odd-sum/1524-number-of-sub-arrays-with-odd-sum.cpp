class Solution {
public:
    const int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        long long int n=arr.size();
        vector<long long int>pref(n);
        pref[0]=arr[0];
        for(int i=1;i<n;i++){
            pref[i]=arr[i]+pref[i-1];
        }
        long long int ans=0;
        long long int o=0,e=0;


        for(int i=0;i<n;i++){
            if(pref[i]&1)o++;
            else e++;

            if(pref[i]&1){
                ans=(1+ans+e)%MOD;
            }
            else{
                ans=(ans+o)%MOD;
            }
        }
        

        return ans;
    }
};