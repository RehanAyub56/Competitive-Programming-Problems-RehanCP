class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n);
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            prefix[i]=gcd(mx,nums[i]);
        }
        sort(prefix.begin(),prefix.end());
        long long int ans=0;
        for(int i=0;i<n/2;i++){
            ans+=(gcd(prefix[i],prefix[n-i-1]));
        }

        return ans;
    }
};