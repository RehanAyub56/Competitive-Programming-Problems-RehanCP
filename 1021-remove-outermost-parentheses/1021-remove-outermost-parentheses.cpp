class Solution {
public:
    string removeOuterParentheses(string s) {
        int b=0;
        string r="";
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
 
                if(b)
                r.push_back('(');
                b++;
            }
            else if(s[i]==')'){
                r.push_back(')');
                b--;
            }
            if(b==0){
                r.pop_back();
                ans+=r;
                r="";
            }
        }

        return ans;
    }
};