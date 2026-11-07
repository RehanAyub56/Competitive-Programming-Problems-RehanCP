class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int x=0;
            int sum=0;
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    x++;
                    sum+=j;
                    if(j!=nums[i]/j)x++,sum+=(nums[i]/j);
                }
                if(x>=5)break;
            }
            if(x==4)ans+=sum;
        }

        return ans;
    }
};