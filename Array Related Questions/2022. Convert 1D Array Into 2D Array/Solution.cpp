#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    vector<vector<int>>mat (m, vector<int>(n));
    if (m*n==original.size()){
        int k = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                mat[i][j] = original[k];
                k++;
            }
        }
    }else{
        return {};
    }
    return mat;
}

int main(){
    return 0;
}