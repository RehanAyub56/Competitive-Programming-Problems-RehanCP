class Solution {
public:
    int lengthOfLastWord(string s) {
        while(!s.empty() && s.back()==' '){
            s.pop_back();
        }
        int ans=0;
        while(!s.empty() && s.back()!=' '){
            ans++;
            s.pop_back();
        }

        return ans;
    }
};