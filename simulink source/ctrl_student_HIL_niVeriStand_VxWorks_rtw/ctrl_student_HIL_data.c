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
 * Model version              : 1.300
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Apr 05 16:00:53 2017
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
  /*  Variable: K
   * Referenced by: '<Root>/K'
   */
  { 2.0, 10.0 },

  /*  Variable: eta_dot_ini
   * Referenced by:
   *   '<Root>/Constant2'
   *   '<S12>/Constant1'
   */
  { 6.0, 5.0, 0.0 },

  /*  Variable: lim
   * Referenced by: '<Root>/Lim'
   */
  { 20.0, -20.0, 9.0, -9.0 },

  /*  Variable: lim_2
   * Referenced by: '<Root>/Lim2'
   */
  { 25.0, -25.0, 10.0, -10.0 },
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
                                        * Referenced by: '<S11>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S7>/Constant'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<S7>/IC'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/reset'
                                        */
  9.0,                                 /* Expression: portnum
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
  8.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S2>/Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Dropout_signaINl'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Dropout_signaINl'
                                        */
  10.0,                                /* Expression: portnum
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_tilde'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_tilde'
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
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/CurrentMode'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/CurrentMode'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/CurrentMode'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/CurrentMode'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/CurrentMode'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/CurrentMode'
                                        */

  /*  Expression:  [2*1.165 4*(1.165*0.8) 4*(1.165*0.8)*0.4575 2.629*0.3875]
   * Referenced by: '<S9>/Max_Global_Forces'
   */
  { 2.33, 3.728, 1.7055600000000002, 1.0187375 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S9>/Dead Zone'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S9>/Dead Zone'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S9>/Dead Zone1'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S9>/Dead Zone1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S9>/Gain'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S9>/Dead Zone2'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S9>/Dead Zone2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/tau_yaw'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/tau_yaw'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/tau_yaw'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/tau_yaw'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/tau_yaw'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/tau_yaw'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/tau_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/tau_x'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/tau_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/tau_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/tau_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/tau_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/tau_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/tau_y'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/tau_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/tau_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/tau_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/tau_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/Select'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/Select'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/Select'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/Select'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/Select'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/Select'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<S5>/k_P'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Psi_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Psi_d'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/Psi_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Psi_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Psi_d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Psi_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  0.02,                                /* Expression: 0.02
                                        * Referenced by: '<S5>/k_I'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/CaseSwitch'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/CaseSwitch'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/CaseSwitch'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/CaseSwitch'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/CaseSwitch'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/CaseSwitch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Tau_pre'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Tau_pre'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Tau_pre'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Tau_pre'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Tau_pre'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Tau_pre'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/v_in'
                                        */
  7.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S11>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/SZ_Owerwrite'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/SZ_Owerwrite'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/SZ_Owerwrite'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/SZ_Owerwrite'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/SZ_Owerwrite'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/SZ_Owerwrite'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Switch2'
                                        */

  /*  Expression:  [1.165*2 2.629]
   * Referenced by: '<S8>/Actuator_Sat_Forces'
   */
  { 2.33, 2.629 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_tilde'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_hat'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/Y_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/psi_0 '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/x_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/integrator reset model'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S10>/Integrator'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/bias'
                                        */
  0.059559261465157838,                /* Expression: 1/16.79
                                        * Referenced by: '<S7>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/TurnOffomega1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/TurnOffomega1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_BT'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/TurnOffomega2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/TurnOffomega2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/TurnOffomega2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/Step'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<S8>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Switch'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Switch1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/f_bt'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/f_bt'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/f_bt'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/f_bt'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/f_bt'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/f_bt'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/f_vspx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/f_vspx'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/f_vspx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/f_vspx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/f_vspx'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/f_vspx'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ f_vspy'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ f_vspy'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/ f_vspy'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ f_vspy'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ f_vspy'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ f_vspy'
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

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
