/*
 * ctrl_DP_basic_private.h
 *
 * Code generation for model "ctrl_DP_basic".
 *
 * Model version              : 1.39
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Mar 17 11:25:22 2015
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_ctrl_DP_basic_private_h_
#define RTW_HEADER_ctrl_DP_basic_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void ctrl_DP_basic_MATLABFunction(real_T rtu_K_p1, real_T rtu_K_p1_e,
  real_T rtu_K_p1_f, B_MATLABFunction_ctrl_DP_basi_T *localB);
extern void ctrl_DP_basic_MATLABFunction1(real_T rtu_K_i1, real_T rtu_K_i1_m,
  real_T rtu_K_i1_n, B_MATLABFunction1_ctrl_DP_bas_T *localB);
extern void ctrl_DP_basic_MATLABFunction2(real_T rtu_K_d1, real_T rtu_K_d1_p,
  real_T rtu_K_d1_i, B_MATLABFunction2_ctrl_DP_bas_T *localB);

/* private model entry point functions */
extern void ctrl_DP_basic_derivatives(void);

#endif                                 /* RTW_HEADER_ctrl_DP_basic_private_h_ */
