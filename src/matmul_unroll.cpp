void matmul_unroll(int A[4][4], int B[4][4], int C[4][4]) {
  #pragma HLS ARRAY_PARTITION variable=A complete dim=2
  #pragma HLS ARRAY_PARTITION variable=B complete dim=1

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int sum = 0;

            #pragma HLS UNROLL factor=4
            for (int k = 0; k < 4; k++) {
                sum += A[i][k] * B[k][j];
            }

            C[i][j] = sum;
        }
    }
}
