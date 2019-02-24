class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row==0) return false;
        int col = matrix[0].size();
        int i = 0;
        int j = col-1;
        //start from the right corner
        //while(i<row){        
            while(j>=0 && i<row){
                //target<right_corner
                if(target<matrix[i][j]){
                    j--;
                }else if(target>matrix[i][j]){
                    i++;
                }else if(target==matrix[i][j]){
                    return true;
                }
            }
        //}
        return false;
    }
};