#ifndef MLLM_OPDEFINED_H
#define MLLM_OPDEFINED_H

#include <string>
#include <vector>
using std::string;
using std::vector;

namespace mllm {
enum OpType {
    INVALID_VALUE = 0,
    PARAMETER,
    ADD,
    SOFTMAX,
    SILU,
    MATMUL,
    SCALE,
    ROPE,
    RMSNORM,
    CAUSALMASK,
    LINEAR,
    EMBEDDING,
    MUL,
    VIEW,
    KVCACHE,
    RELU,
    RELU2,
    OP_GELU,
    QUICKGLUE,
    LAYERNORM,
    SPLIT,
    GATHER,
    CONVOLUTION2D,
    CONVOLUTION3D,
    AVGPOOL2D,
    MAXPOOL2D,
    CAT,
    TRANSPOSE,
    SUBDIM,
    DIVISION,
    NORM,
    SHAPE,
    MEAN,
    RANGE,
    WHERE,
    REPLACE,
    OP_NUM
};

static const vector<string> OpNames = {
    "INVALID_VALUE",
    "Parameter",
    "Add",
    "SoftMax",
    "SiLU",
    "MatMul",
    "Scale",
    "RoPE",
    "RMSNorm",
    "CausalMask",
    "Linear",
    "Embedding",
    "Mul",
    "VIEW",
    "KVCACHE",
    "ReLU",
    "ReLUSquaredActivation",
    "GELU",
    "QuickGELU",
    "LayerNorm",
    "Split",
    "Gqther",
    "Convolution2D",
    "Convolution3D",
    "AvgPool2D",
    "MaxPool2D",
    "Cat",
    "Transpose",
    "SubDim",
    "Division",
    "Norm",
    "Shape",
    "Mean",
    "Range",
    "Where",
    "Replace",
    "OP_NUM"};

enum TensorFuncType {
    FUNC_ADD,
    FUNC_SUB,
    FUNC_MUL,
    FUNC_DIV,
    FUNC_TTADD,
    FUNC_TTSUB,
    FUNC_TTMUL,
    FUNC_TTDIV,
    FUNC_MM,
    FUNC_NORM,
    FUNC_MEAN,
    FUNC_CAT,
    FUNC_VIEW,
    FUNC_TRANPOSE,
    FUNC_FLATTEN,
    FUNC_CLIP,
    FUNC_CLIPAXIS,
    FUNC_RANGE,
    FUNC_WHERE
};

} // namespace mllm
#endif
