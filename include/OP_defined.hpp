#ifndef MLLM_OP_DEFINED
#define MLLM_OP_DEFINED
namespace mllm {
enum OpType{
    None=0,
    Add,
    SoftMax,
    Silu,
    Matmul,
    Scale,
    RoPE,
    RMSNorm,
    CausalMask,
    OP_NUM,
    Input
};
}
#endif
