class Solution {
public:
    long long int size(long long int n,long long int w){
        string ans=to_string(n);
        long long int v=1;
        for(int i=0;i<(int)ans.size()-w;i++){
            v*=10;
        }
        return v;
    }
    long long power(long long b, long long p, long long mod) {
    long long v = 1;

    while (p > 0) {
        if (p & 1)
            v = (v * b) % mod;

        b = (b * b) % mod;
        p /= 2;
    }

    return v;
    }
    int sumDecoded(vector<long long>& nums) {
        const long long int mod=1e9 + 7;
         int n=nums.size();
        long long int ans=0;
         for(int i=0;i<n;i++){
            long long int x=nums[i];
            long long int s=size(x/10,x%10);
            nums[i]/=10;
            int b=nums[i]/s;
            int p=nums[i]%s;

            long long v = power(b, p, mod);

            ans=((v+ans)%mod);
         }

         return ans;
    }
};