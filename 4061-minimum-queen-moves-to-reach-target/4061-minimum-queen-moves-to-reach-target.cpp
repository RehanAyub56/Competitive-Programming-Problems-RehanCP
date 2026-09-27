class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int a=source[0],b=target[0],c=source[1],d=target[1];
        if(a==b && c==d){
            return 0;
        }
        else if((a+c == b+d)|| (a-b)==(c-d) || (a==b) || (c==d)){
            return 1;
        }
        else{
            return 2;
        }
        
        
    }
};