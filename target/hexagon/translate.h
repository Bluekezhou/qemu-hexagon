/* Copyright (c) 2019 Qualcomm Innovation Center, Inc. All Rights Reserved. */

#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "cpu.h"
#include "exec/translator.h"
#include "exec/helper-proto.h"
#include "exec/helper-gen.h"

typedef struct DisasContext {
    DisasContextBase base;
    uint32_t mem_idx;
    int ctx_reg_log[REG_WRITES_MAX];
    int ctx_reg_log_idx;
    int ctx_preg_log[PRED_WRITES_MAX];
    int ctx_preg_log_idx;
    size1u_t ctx_store_width[STORES_MAX];
    int ctx_temp_vregs_idx;
    int ctx_temp_qregs_idx;
    int ctx_vreg_log[NUM_VREGS];
    int ctx_vreg_is_predicated[NUM_VREGS];
    int ctx_vreg_log_idx;
    int ctx_qreg_log[NUM_QREGS];
    int ctx_qreg_is_predicated[NUM_QREGS];
    int ctx_qreg_log_idx;
} DisasContext;

extern TCGv hex_gpr[TOTAL_PER_THREAD_REGS];
extern TCGv hex_pred[NUM_PREGS];
extern TCGv hex_next_PC;
extern TCGv hex_this_PC;
extern TCGv hex_slot_cancelled;
extern TCGv hex_branch_taken;
extern TCGv hex_new_value[TOTAL_PER_THREAD_REGS];
#ifdef DEBUG_HEX
extern TCGv hex_reg_written[TOTAL_PER_THREAD_REGS];
#endif
extern TCGv hex_new_pred_value[NUM_PREGS];
extern TCGv hex_pred_written[NUM_PREGS];
extern TCGv hex_store_addr[STORES_MAX];
extern TCGv hex_store_width[STORES_MAX];
extern TCGv hex_store_val32[STORES_MAX];
extern TCGv_i64 hex_store_val64[STORES_MAX];
extern TCGv hex_dczero_addr;
extern TCGv llsc_addr;
extern TCGv llsc_val;
extern TCGv_i64 llsc_val_i64;
extern TCGv hex_VRegs_updated_tmp;
extern TCGv hex_VRegs_updated;
extern TCGv hex_VRegs_select;
extern TCGv hex_QRegs_updated;
extern TCGv hex_is_gather_store_insn;
extern TCGv hex_gather_issued;

extern void gen_exception(int excp);
extern void gen_exception_debug(void);

#ifdef DEBUG_HEX
void print_thread_prefix(CPUHexagonState *env);
#endif

extern void gen_memcpy(TCGv_ptr dest, TCGv_ptr src, size_t n);

#endif
