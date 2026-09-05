class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        int top=0,bottom=n,left=0,right=m;

        while(top<bottom && left<right){
            for(int i=left;i<right;i++){
                ans.push_back(matrix[top][i]);
            }
            for(int i=top+1;i<bottom-1;i++){
                ans.push_back(matrix[i][right-1]);
            }

             if(top < bottom-1){
            for(int i=right-1;i>left;i--){
                ans.push_back(matrix[bottom-1][i]);
            }
             }

            for(int i=bottom-1;i>top;i--){
                if(i==bottom-1 || left<right-1){      
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;


        }

        return ans;

    }
};