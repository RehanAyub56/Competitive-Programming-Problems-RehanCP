class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        int bits=0;
        while(n){
            ans=ans<<1;
            if(n&1){
                ans=ans | 1;
            }
            n=n>>1;
            bits++;
        }

        while(32-bits>0){
            ans=ans<<1;
            bits++;
        }

        return ans;
    }
};