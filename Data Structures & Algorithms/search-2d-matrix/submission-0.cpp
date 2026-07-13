class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<int> temp(n*m);

        int arrIdx = 0;
        while(arrIdx<m) {
            if(matrix[arrIdx][0] <= target && target <= matrix[arrIdx][n-1]) {
                break;
            }
            arrIdx++;
        }

        if(arrIdx == m){
            return false;
        }

        int l = 0;
        int r = n-1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(matrix[arrIdx][mid] == target) {
                // cout<<arrIdx<<endl;
                return true;
            } else if (matrix[arrIdx][mid] < target) {
                l = mid +1;
            } else if (matrix[arrIdx][mid] > target) {
                r = mid -1;
            }
        }
        return false;
    }
};
