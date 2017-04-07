/*
 * ctrl_student_HIL_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.392
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Apr 07 16:40:01 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_student_HIL_private_h_
#define RTW_HEADER_ctrl_student_HIL_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void ctrl_student_HI_MATLABFunction1(const real_T rtu_R[9],
  B_MATLABFunction1_ctrl_studen_T *localB);
extern void ctrl_student__MATLABFunction1_m(real_T rtu_SwitchSignal_In,
  B_MATLABFunction1_ctrl_stud_k_T *localB);
extern void ctrl_student_H_ForceAllocation1(real_T rtu_current_mode, real_T
  rtu_tau_surge, real_T rtu_tau_sway, real_T rtu_tau_yaw,
  B_ForceAllocation1_ctrl_stude_T *localB);
extern void ctrl_student_HIL_Force2Control(real_T rtu_current_mode, real_T
  rtu_f_vspx1, real_T rtu_f_vspx2, real_T rtu_f_vspy1, real_T rtu_f_vspy2, const
  real_T rtu_sat_forces[2], B_Force2Control_ctrl_student__T *localB);

/* private model entry point functions */
extern void ctrl_student_HIL_derivatives(void);

#endif                                 /* RTW_HEADER_ctrl_student_HIL_private_h_ */
