class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            s.push_back(s[i]);
            int score=0;
            for(int j=i+1;j<s.length()-1;j++){
                if(s[j]==s[j+1]){
                    score++;
                }
            }

            if(score==k){
                ans++;
            }
        }

        return ans;
    }
};