class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(int i=0;i<s.length();i++){
            if(s[i]>=65 && s[i]<=90){
                s[i]+=32;
            }
            if((s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57)){
                t.push_back(s[i]);
            }
        }

        string m=t;
        reverse(t.begin(),t.end());

        for(int i=0;i<t.size();i++){
            if(t[i]!=m[i]){
                return false;
            }
        }

        return true;

    }
};