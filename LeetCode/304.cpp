/*******************************************************************************
	> File Name: 304.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Wed Mar 23 11:29:53 2016
*******************************************************************************/

class NumMatrix {
private:
    vector<vector<int>> rowSum;
    vector<vector<int>> colRowSum;
    int rn, ln;
    
public:
    NumMatrix(vector<vector<int>> &matrix) {
        rn = matrix.size();
        if (rn == 0) return;
        ln = matrix[0].size();
        for (int i = 0; i < rn; ++i) {
            vector<int> row = matrix[i];
            vector<int> tmp;
            int sum = 0;
            for (int j = 0; j < ln; ++j) {
                sum += row[j];
                tmp.push_back(sum);
            }
            rowSum.push_back(tmp);
        }
        for (int i = 0; i < ln; ++i) {
            int sum = 0;
            vector<int> tmp;
            for (int j = 0; j < rn; ++j) {
                sum += rowSum[j][i];
                tmp.push_back(sum);
            }
            colRowSum.push_back(tmp);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret;
        int rt1, rt2, rt3, rt4;
        rt1 = colRowSum[col2][row2];
        if (row1 == 0) {
            rt2 = 0;
        } else {
            rt2 = colRowSum[col2][row1-1];   
        }
        if (col1 == 0) {
            rt3 = 0;
        } else {
            rt3 = colRowSum[col1-1][row2];
        }
        if (row1 == 0 || col1 == 0) {
            rt4 = 0;
        } else {
            rt4 = colRowSum[col1-1][row1-1];   
        }
        ret = rt1 - rt2 - rt3 + rt4;
        return ret;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
