#include<iostream>
#include<vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<int>freqRow = {0,0,0,0,0,0,0,0,0};
    vector<int>freqCol = {0,0,0,0,0,0,0,0,0};
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            int currRow = board[i][j];
            if (currRow=='.'){
                continue;
            }
            if(freqRow[currRow-'1']==0){
                freqRow[currRow-'1']++;
            }else{
                return false;
            }
        }
        freqRow = {0,0,0,0,0,0,0,0,0};
    }
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            int currCol = board[j][i];
            if (currCol=='.'){
                continue;
            }
            if(freqCol[currCol-'1']==0){
                freqCol[currCol-'1']++;
            }else{
                return false;
            }
        }
        freqCol = {0,0,0,0,0,0,0,0,0};
    }
    vector<int>box = {0,0,0,0,0,0,0,0,0};
    int k=0, l=0;
    for (int k=0; k<9; k+=3){
        for (int l=0; l<9; l+=3){
            for (int i=k; i<k+3; i++){
                for (int j=l; j<l+3; j++){
                    int curr = board[i][j];
                    if (curr=='.'){
                        continue;
                    }
                    if(box[curr-'1']==0){
                        box[curr-'1']++;
                    }else{
                        return false;
                    }
                }
            }
            box = {0,0,0,0,0,0,0,0,0};
        }
    }
    return true;
}

int main(){
    return 0;
}