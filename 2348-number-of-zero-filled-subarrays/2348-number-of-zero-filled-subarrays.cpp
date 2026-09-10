class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int cons=0;
        long long int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cons++;
            }
            else{
                ans+=(cons*(cons+1))/2;
                cons=0;
            }
        }
        ans+=(cons*(cons+1))/2;
        return ans;
    }
};