class Solution {
public:
vector<string>ans;
    void Brackets(int n,string r,int open,int close){
        if(close>open || open>n || close>n){
            return;
        }
        if(open == n && open==close){
            ans.push_back(r);
        }

        string r1=r,r2=r;        
        r1.push_back('('),r2.push_back(')');

        Brackets(n,r1,open+1,close);
        Brackets(n,r2,open,close+1);


    }
    vector<string> generateParenthesis(int n) {
        
        Brackets(n,"",0,0);

        return ans;

    }
};