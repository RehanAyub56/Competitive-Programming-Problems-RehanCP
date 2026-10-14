class Solution {
public:
    int ans;
    void XOR(vector<int>& nums,vector<int>a,int i){
        int n=nums.size();
        int Xor=0;
        for(int k=0;k<a.size();k++){
            Xor^=a[k];
        }
        ans+=Xor;

        if(i>=n){
            return ;
        }
        
        for(int j=i;j<n;j++){
            a.push_back(nums[j]);
            XOR(nums,a,j+1);
            a.pop_back();
        }

        return ;
    }
    int subsetXORSum(vector<int>& nums) {
        ans=0;
        XOR(nums,{},0);

        return ans;
        
    }
};