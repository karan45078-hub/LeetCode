#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i=0; i<n/2; i++){
            int row1 = i, row2 = i, row3 = n-1-i, row4 = n-1-i;
            int col1 = i, col2 = n-1-i, col3 = n-1-i, col4 = i;

            while (col1<col2){
                //take edge of matrix in starting 
                int ptr1 = matrix[row1][col1];
                int ptr2 = matrix[row2][col2];
                int ptr3 = matrix[row3][col3];
                int ptr4 = matrix[row4][col4];

                //ptr1 --> ptr2
                int temp1 = ptr2;
                matrix[row2][col2] = ptr1;
                row2++;
                //ptr2 --> ptr3
                int temp2 = ptr3;
                matrix[row3][col3] = temp1;
                col3--;
                //ptr3 --> ptr4
                int temp3 = ptr4;
                matrix[row4][col4] = temp2;
                row4--;
                //ptr4 --> ptr1
                matrix[row1][col1] = temp3;
                col1++;
            }
        }
    }

int main(){
    return 0;
}