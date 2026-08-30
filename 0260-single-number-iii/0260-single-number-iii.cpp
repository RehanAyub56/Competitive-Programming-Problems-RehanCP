class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)ans^=nums[i];
        int num1=0,num2=0;
       int bit=0;
        while(ans){
            if(ans&1){
                break;
            }
            ans=ans>>1;
            bit++;
        }
        for(int i=0;i<nums.size();i++){
            if((nums[i]&(1<<bit))==(1<<bit)){
                num1^=nums[i];
                cout<<num1<<endl;
            }
            if((nums[i]&(1<<bit))==0){
                num2^=nums[i];
            }
        }

        return {num1,num2};

    }
};