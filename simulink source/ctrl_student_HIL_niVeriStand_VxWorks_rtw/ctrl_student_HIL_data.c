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
 * Model version              : 1.207
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Mar 14 17:32:43 2017
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
  /*  Variable: K2
   * Referenced by: '<S11>/K2'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Variable: l1
   * Referenced by: '<Root>/Constant1'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Variable: l2
   * Referenced by: '<Root>/Constant2'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Variable: l3
   * Referenced by: '<Root>/Constant3'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },
  0.0,                                 /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S32>/Constant1'
                                        */
  0.1,                                 /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S32>/Step'
                                        */
  0.0,                                 /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S32>/Constant'
                                        *   '<S32>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/etaHat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_hat'
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_in'
                                        */
  10.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/eta_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_tilde'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_tilde'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S5>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/counter'
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
  9.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S27>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S27>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S27>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S28>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S28>/White Noise'
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
                                        * Referenced by: '<S26>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S26>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S26>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Hold'
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
                                        * Referenced by: '<S4>/Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Dropout_signaINl'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Dropout_signaINl'
                                        */
  15.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/eta_noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_noise'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_noise'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_noise'
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
                                        * Referenced by: '<Root>/Dropout_signaOUT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Dropout_signaOUT'
                                        */
  5.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/sf1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/sf1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/sf1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/sf1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/sf1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/sf1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/v_in'
                                        */
  8.0,                                 /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/sf2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/sf2'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/sf2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/sf2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/sf2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/sf2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/sf3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/sf3'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/sf3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/sf3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/sf3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/sf3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/biasOffset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/biasOffset'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/biasOffset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/biasOffset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/biasOffset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/biasOffset'
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

  /*  Expression:  [1.03 2.5 0.98]
   * Referenced by: '<S7>/Max_Global_Forces'
   */
  { 1.03, 2.5, 0.98 },

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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Step'
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
                                        * Referenced by: '<S7>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/L1'
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
                                        * Referenced by: '<S7>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/R1'
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
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowDown'
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
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowUp'
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
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowLeft'
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
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowRight'
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/reset'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/reset'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/integrator reset model'
                                        */

  /*  Expression: [1;1;1]
   * Referenced by: '<S9>/Constant'
   */
  { 1.0, 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/bHat'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S9>/IC1'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/nuHat'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S11>/IC'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S1>/tauNull '
   */
  { 0.0, 0.0, 0.0 },
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

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
