#include "CPUBackend.hpp"
#include "CPUView.hpp"
#include "CPUAdd.hpp"
#include "CPUCausalMask.hpp"
#include "CPUMatmul.hpp"
#include "CPURMSNorm.hpp"
#include "CPURoPE.hpp"
#include "CPUScale.hpp"
#include "CPUSiLU.hpp"
#include "CPUSoftMax.hpp"
#include "CPULinear.hpp"
#include "CPUEmbedding.hpp"
#include "CPUMul.hpp"
#include "CPUKVCache.hpp"
#include "CPUReLU.hpp"
#include "CPUReLU2.hpp"
#include "CPUSplit.hpp"
#include "CPULayerNorm.hpp"
#include "CPUGather.hpp"


#include <math.h>
namespace mllm {
CPUBackend::CPUBackend(shared_ptr<MemoryManager>& mm) :
    Backend(mm) {
    //initCreatorMap();
    registerOps();
}
void CPUBackend::initTable() {
    for (int i = 0; i < 1 << 16; i++) {
        SOFT_MAX_TABLE_[i] = MLLM_FP32_TO_FP16(expf(i));
    }
}
// Op *CPUBackend::OpCreate(const vector<shared_ptr<Tensor>> &inputs, const vector<shared_ptr<Tensor>> &outputs,OpParam op_param)
// {
//     return map_creator_->find(optype)->second->Create(inputs, outputs, optype, this);
//     // return nullptr;
// }
Op *CPUBackend::opCreate(const OpParam &op_param, string name) {
    OpType optype = OpType(op_param.find("type")->second);
    auto iter = map_creator_.find(optype);
    if (iter == map_creator_.end()) {
        printf("Don't support type \n");
        return nullptr;
    }
    Op *exe = nullptr;
    exe = iter->second->create(op_param, this, name);
    return exe;
    // return nullptr;
}
void CPUBackend::registerOps() {
    addCreator(ADD, (CPUBackend::Creator *)(new CPUAddCreator()));
    addCreator(CAUSALMASK, (CPUBackend::Creator *)(new CPUCausalMaskCreator()));
    addCreator(MATMUL, (CPUBackend::Creator *)(new CPUMatmulCreator()));
    addCreator(RMSNORM, (CPUBackend::Creator *)(new CPURMSNormCreator()));
    addCreator(ROPE, (CPUBackend::Creator *)(new CPURoPECreator()));
    addCreator(SCALE, (CPUBackend::Creator *)(new CPUScaleCreator()));
    addCreator(SILU, (CPUBackend::Creator *)(new CPUSiLUCreator()));
    addCreator(SOFTMAX, (CPUBackend::Creator *)(new CPUSoftMaxCreator()));
    addCreator(LINEAR, (CPUBackend::Creator *)(new CPULinearCreator()));
    addCreator(EMBEDDING, (CPUBackend::Creator *)(new CPUEmbeddingCreator()));
    addCreator(MUL, (CPUBackend::Creator *)(new CPUMulCreator()));
    addCreator(VIEW, (CPUBackend::Creator *)(new CPUViewCreator()));
    addCreator(KVCACHE, (CPUBackend::Creator *)(new CPUKVCacheCreator()));
    addCreator(RELU, (CPUBackend::Creator *)(new CPUReLUCreator()));
    addCreator(RELU2, (CPUBackend::Creator *)(new CPUReLU2Creator()));
    addCreator(LAYERNORM, (CPUBackend::Creator *)(new CPULayerNormCreator()));
    addCreator(SPLIT, (CPUBackend::Creator *)(new CPUSplitCreator()));
    addCreator(GATHER, (CPUBackend::Creator *)(new CPUGatherCreator()));
}

} // namespace mllm
