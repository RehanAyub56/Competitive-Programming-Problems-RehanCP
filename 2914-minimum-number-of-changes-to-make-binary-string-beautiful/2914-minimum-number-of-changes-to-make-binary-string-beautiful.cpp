class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i+=2){
            if((s[i]=='1' && s[i+1]=='0') || (s[i]=='0' && s[i+1]=='1')){
                ans++;
            }
            
        }

        return ans;
    }
};