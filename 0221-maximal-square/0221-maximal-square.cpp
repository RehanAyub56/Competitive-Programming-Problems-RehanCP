class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

/*

Down-Top Aproch is used Because Brute Forces increase Time Complexity 
chach memory is used because storing result of below cells Dont need to traverse again and again to form more efficient way to decrease complexity 

*/


        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>chach(r,vector<int>(c));       
    for(int i=matrix.size()-1;i>=0;i--){
        for(int j=matrix[i].size()-1;j>=0;j--){

        if(i<r-1 && j<c-1 && matrix[i+1][j]=='1' && matrix[i][j+1]=='1' && matrix[i+1][j+1]=='1'){

            if(matrix[i][j]=='0'){
                chach[i][j]=0;
            }
            else{
                chach[i][j]=min({chach[i+1][j],chach[i][j+1],chach[i+1][j+1]})+1;
            }

        }
        else{
            if(matrix[i][j]=='0'){
                chach[i][j]=0;
            }
            else{
                chach[i][j]=1;
            }


        }

        }
    }

int ans=0;
    for(int i=0;i<chach.size();i++){
        for(int j=0;j<chach[i].size();j++){
            ans=max(ans,chach[i][j]*chach[i][j]);
        }
    }

    return ans;

    }
};