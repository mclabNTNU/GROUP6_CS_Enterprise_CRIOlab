/*
 * ctrl_DP_private.h
 *
 * Code generation for model "ctrl_DP".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Sun Mar 15 22:06:20 2015
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_ctrl_DP_private_h_
#define RTW_HEADER_ctrl_DP_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void ctrl_DP_MATLABFunction(real_T rtu_K_p1, real_T rtu_K_p1_c, real_T
  rtu_K_p1_h, B_MATLABFunction_ctrl_DP_T *localB);

/* private model entry point functions */
extern void ctrl_DP_derivatives(void);

#endif                                 /* RTW_HEADER_ctrl_DP_private_h_ */
