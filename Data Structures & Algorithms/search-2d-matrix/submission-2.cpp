class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = (n*m)-1;

        while(l<=r) {
            int mid = l+(r-l)/2;
            int row = mid/n;
            int col = mid%n;

            if(matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                l = mid +1;
            } else if (matrix[row][col] > target) {
                r = mid -1;
            }
        }
        return false;
    }
};
