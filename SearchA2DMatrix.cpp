class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m*n-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (target > matrix[mid/n][mid%n]) left = mid+1;
            else right = mid;
        }
        return matrix[left/n][left%n] == target ? true : false;
    }
};
