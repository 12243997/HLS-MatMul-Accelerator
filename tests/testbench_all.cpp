#include <iostream>
using namespace std;

void matmul(int A[4][4], int B[4][4], int C[4][4]);
void matmul_pipeline(int A[4][4], int B[4][4], int C[4][4]);
void matmul_unroll(int A[4][4], int B[4][4], int C[4][4]);

int main() {
    int A[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int B[4][4] = {
    {1, 2, 0, 0},
    {0, 1, 2, 0},
    {0, 0, 1, 2},
    {2, 0, 0, 1}
    };

    int C_basic[4][4] = {};
    int C_pipeline[4][4] = {};
    int C_unroll[4][4] = {};

    matmul(A, B, C_basic);
    matmul_pipeline(A, B, C_pipeline);
    matmul_unroll(A, B, C_unroll);

    bool passed = true;

    for(int i = 0; i < 4; ++i) {
      for(int j = 0; j < 4; ++j) {
        if(C_basic[i][j] != C_pipeline[i][j] || C_basic[i][j] != C_unroll[i][j]) {
          passed = false;
        }
      }
    }

    if(passed) { cout << "All tests passed!" << endl;} else {
      cout << "Failed" << endl;
    }

    return 0;
}
