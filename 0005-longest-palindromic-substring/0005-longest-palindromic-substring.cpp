class Solution {
public:

    bool pilandrome(string s){
        string r=s;
        reverse(r.begin(),r.end());
        for(int i=0;i<s.length();i++){
            if(s[i]!=r[i]){
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        int l,r;
        string ans="";
        int mx=INT_MIN;

        for(int i=0;i<s.length();i++){
            int l=i,r=i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>mx){
                    mx=r-l+1;
                    ans=s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
        }


        for(int i=0;i<s.length();i++){
            int l=i,r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>mx){
                    mx=r-l+1;
                    ans=s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
        }
        
        return ans;

    }
};