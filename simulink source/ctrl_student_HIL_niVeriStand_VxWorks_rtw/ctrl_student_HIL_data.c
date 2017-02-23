/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#include "NIVERISTAND_API.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_student_HIL_P            ctrl_student_HIL_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_student_HIL_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.155
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Feb 23 09:16:19 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

/* Block parameters (auto storage) */
P_ctrl_student_HIL_T ctrl_student_HIL_P = {
  0.0,                                 /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S27>/Constant1'
                                        */
  0.1,                                 /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S27>/Step'
                                        */
  0.0,                                 /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S27>/Constant'
                                        *   '<S27>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S4>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/counter'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/NoisePowPos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/NoisePowPos'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/NoisePowPos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/NoisePowPos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/NoisePowPos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/NoisePowPos'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S20>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S20>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S21>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S21>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/NoisePowHead'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/NoisePowHead'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/NoisePowHead'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/NoisePowHead'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/NoisePowHead'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/NoisePowHead'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S19>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S19>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_in'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Hold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/NoiseEnable'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/NoiseEnable'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/NoiseEnable'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/NoiseEnable'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/NoiseEnable'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/NoiseEnable'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Dropout_signaINl'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Dropout_signaINl'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/Dropout_signaINl'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Dropout_signaINl'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Dropout_signaINl'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Dropout_signaINl'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/K_phi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/K_phi'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/K_phi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/K_phi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/K_phi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/K_phi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/ResetIntegra_Select'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ResetIntegra_Select'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/ResetIntegra_Select'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/ResetIntegra_Select'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/ResetIntegra_Select'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/ResetIntegra_Select'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_in'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/u_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_real  '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_real  '
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_real  '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_real  '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_real  '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_real  '
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S7>/Memory1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/Select'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/Select'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/Select'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/Select'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/Select'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/Select'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S7>/Dead Zone'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S7>/Dead Zone'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S7>/Dead Zone1'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S7>/Dead Zone1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S7>/Gain'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S7>/Dead Zone2'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S7>/Dead Zone2'
                                        */

  /*  Expression:  [1.165*2 2.629+1.165*2 0.3875*2.629+0.4575*1.165*2 2.629 ]
   * Referenced by: '<S7>/Max_Global_Forces'
   */
  { 2.33, 4.959, 2.0847125, 2.629 },

  /*  Expression:  [1.165*2 2.629 ]
   * Referenced by: '<S7>/Sat_Forces'
   */
  { 2.33, 2.629 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/Step'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<S7>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Saturation'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/Current Mode '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/Current Mode '
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/Current Mode '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/Current Mode '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/Current Mode '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/Current Mode '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/Error State Flag'
                                        */
  10.0,                                /* Expression: dtype
                                        * Referenced by: '<S7>/Error State Flag'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/Error State Flag'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/Error State Flag'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/Error State Flag'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/Error State Flag'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/f_vspx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/f_vspx'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/f_vspx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/f_vspx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/f_vspx'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/f_vspx'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/f_vspy'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/f_vspy'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/f_vspy'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/f_vspy'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/f_vspy'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/f_vspy'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/f_bt'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/f_bt'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/f_bt'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/f_bt'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/f_bt'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/f_bt'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/tau_yaw'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/tau_yaw'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/tau_yaw'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/tau_yaw'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/tau_yaw'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/tau_yaw'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/tau_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/tau_x'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/tau_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/tau_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/tau_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/tau_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/tau_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/tau_y'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/tau_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/tau_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/tau_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/tau_y'
                                        */
  40.0,                                /* Expression: 40
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  6.45,                                /* Expression: 6.45
                                        * Referenced by: '<Root>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Safety_zonee_signal'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Safety_zonee_signal'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Safety_zonee_signal'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Safety_zonee_signal'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Safety_zonee_signal'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Safety_zonee_signal'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Dropout_signaOUT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Dropout_signaOUT'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Dropout_signaOUT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Dropout_signaOUT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Dropout_signaOUT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Dropout_signaOUT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/r_in'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/r_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/r_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/v_in'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/v_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/v_in'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Switch'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/imu_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/imu_in'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/imu_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/imu_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/imu_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/imu_in'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.059559261465157838,                /* Expression: 1/16.79
                                        * Referenced by: '<S5>/Gain'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
};

#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  long size;
  long width;
  long basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_student_HIL_T_sizes[] DataSection(
  ".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_student_HIL_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
