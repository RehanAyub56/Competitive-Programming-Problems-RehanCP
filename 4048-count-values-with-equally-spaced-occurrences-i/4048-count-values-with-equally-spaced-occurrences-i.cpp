class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<bool>b(n,0);
        for(int i=0;i<n;i++){
            vector<int>a;
            for(int j=i+1;!b[i] && j<n;j++){
                if(nums[i]==nums[j]){
                    a.push_back(j);
                    b[j]=1;
                }
            }
            if(a.size()==2){
                if(a[0]-i == a[1]-a[0]){
                    ans++;
                }
            }
        }


        
        return ans;

        
    }
};