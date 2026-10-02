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
        Brackets(n,r+"(",open+1,close);
        Brackets(n,r+")",open,close+1);
    }
    vector<string> generateParenthesis(int n) {       
        Brackets(n,"",0,0);
        return ans;
    }
};