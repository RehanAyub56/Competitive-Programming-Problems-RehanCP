class Solution {
public:
    int ans;
    void XOR(vector<int>& nums,int Xor,int i){
        int n=nums.size();   
        ans+=Xor;
        if(i>=n){
            return ;
        }      
        for(int j=i;j<n;j++){
            XOR(nums,Xor^nums[j],j+1);
        }
        return ;
    }
    int subsetXORSum(vector<int>& nums) {
        ans=0;
        XOR(nums,0,0);
        return ans;  
    }
};