// c
int **ary = new int*[row_num];
for(int i = 0; i < row_num; ++i) {
    ary[i] = new int[col_num];
    // delete[] ary[i];
}
// delete[] ary;

// cpp
vector<vector<int> > ary(row_num, vector<int>(col_num, 0));
