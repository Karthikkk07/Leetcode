class Solution {
public:
int maxElement(vector<vector<int>>& mat, int col) {
int n = mat.size();
int maxRow = 0;
    for (int row = 0; row < n; row++) {
        if (mat[row][col] > mat[maxRow][col]) {
            maxRow = row;
        }
    }

    return maxRow;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = m - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int row = maxElement(mat, mid);

        int left = (mid > 0) ? mat[row][mid - 1] : -1;
        int right = (mid < m - 1) ? mat[row][mid + 1] : -1;

        if (mat[row][mid] > left && mat[row][mid] > right) {
            return {row, mid};
        }
        else if (left > mat[row][mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return {-1, -1};
}
};
