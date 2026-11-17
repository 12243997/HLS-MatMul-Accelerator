# HLS Matrix Multiplication Accelerator

## 1. Project Overview

This project explores FPGA-oriented optimization of a 4x4 matrix multiplication kernel using High-Level Synthesis (HLS) directives.

Three implementations were developed:
- Baseline matrix multiplication
- Pipelined matrix multiplication
- Loop-unrolled matrix multiplication with array partitioning

## 2. Project Structure

- `src/matmul.cpp`: Baseline implementation
- `src/matmul_pipeline.cpp`: PIPELINE optimization
- `src/matmul_unroll.cpp`: UNROLL and ARRAY_PARTITION optimization
- `tests/testbench_all.cpp`: Functional verification

## 3. HLS Optimization Techniques

### Baseline
Standard matrix multiplication using three nested loops.

### PIPELINE
Applies `#pragma HLS PIPELINE II=1` to the innermost loop to request overlapped execution of loop iterations.

### UNROLL + ARRAY_PARTITION
Applies `#pragma HLS UNROLL factor=4` to the innermost loop.

The input arrays are partitioned to enable parallel memory accesses:
- A: `complete dim=2`
- B: `complete dim=1`

## 4. Verification

All three implementations were compiled and tested using GCC in Google Colab.

The implementations produced matching results for:
- Identity matrix multiplication
- Non-identity matrix multiplication

## 5. Limitations

HLS synthesis was not performed.

Therefore, hardware latency, initiation interval (II), LUT usage, DSP usage, and FPGA performance improvements have not been measured.

The HLS directives express intended hardware optimizations, but their effectiveness requires validation using an HLS synthesis tool.

## 6. Development Environment

- Google Colab (Linux)
- C++17
- GCC
