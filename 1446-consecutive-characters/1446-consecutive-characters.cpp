class Solution {
public:
    int maxPower(string s) {
        int x=1;
        s+='M';
        int ans=0;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                x++;
            }
            else{
                ans=max(ans,x);
                x=1;
            }
        }

        return ans;
    }
};