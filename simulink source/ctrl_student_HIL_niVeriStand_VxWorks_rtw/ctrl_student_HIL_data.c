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
 * Model version              : 1.291
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sun Apr 02 15:42:11 2017
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
  0.0,                                 /* Variable: DesiredPath
                                        * Referenced by: '<S15>/SwitchSignalFromFile'
                                        */

  /*  Variable: Elipscenter_radi
   * Referenced by: '<S35>/Elipscenter_radi'
   */
  { 6.0, 0.0, 5.0, 3.0 },

  /*  Variable: K
   * Referenced by: '<Root>/K'
   */
  { 2.0, 10.0 },

  /*  Variable: K1
   * Referenced by:
   *   '<S2>/Constant1'
   *   '<S21>/Kp '
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 4.0 },

  /*  Variable: K2
   * Referenced by: '<S2>/Constant2'
   */
  { 200.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 3.0 },
  0.0,                                 /* Variable: LAW
                                        * Referenced by:
                                        *   '<S36>/TASK'
                                        *   '<S43>/TASK'
                                        */
  4000.0,                              /* Variable: T_initialDP
                                        * Referenced by: '<S45>/Constant1'
                                        */
  0.25,                                /* Variable: U_ref
                                        * Referenced by:
                                        *   '<S34>/Constant'
                                        *   '<S45>/Constant'
                                        */

  /*  Variable: eta_dot_ini
   * Referenced by:
   *   '<Root>/Constant2'
   *   '<S13>/Constant1'
   */
  { 6.0, 5.0, 0.0 },

  /*  Variable: l1
   * Referenced by: '<S7>/Constant1'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.05 },

  /*  Variable: l2
   * Referenced by: '<S7>/Constant2'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.05 },

  /*  Variable: l3
   * Referenced by: '<S7>/Constant3'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.05 },

  /*  Variable: lim
   * Referenced by: '<Root>/Lim'
   */
  { 20.0, -20.0, 9.0, -9.0 },

  /*  Variable: lim_2
   * Referenced by: '<Root>/Lim2'
   */
  { 25.0, -25.0, 10.0, -10.0 },
  14.79,                               /* Variable: m
                                        * Referenced by: '<S27>/Constant'
                                        */
  0.001,                               /* Variable: mu
                                        * Referenced by:
                                        *   '<S36>/mu '
                                        *   '<S43>/mu '
                                        */

  /*  Variable: pd
   * Referenced by: '<S42>/Desired Position'
   */
  { 2.0, 0.0, 10.0, 4.0, 2.0, 0.0, 10.0, 4.0 },
  0.0,                                 /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S72>/Constant1'
                                        */
  0.1,                                 /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S72>/Step'
                                        */
  0.0,                                 /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S72>/Constant'
                                        *   '<S72>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Switch1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/reset'
                                        */
  13.0,                                /* Expression: portnum
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

  /*  Expression: [0;0;0]
   * Referenced by: '<S56>/etaHat'
   */
  { 0.0, 0.0, 0.0 },
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
  17.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S6>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S62>/counter'
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
                                        * Referenced by: '<S68>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S68>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S68>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S69>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S69>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S69>/White Noise'
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
                                        * Referenced by: '<S67>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S67>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S67>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/Hold'
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
                                        * Referenced by: '<S5>/Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Dropout_signaINl'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Dropout_signaINl'
                                        */
  14.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  19.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S21>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/IC'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S33>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S43>/Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S45>/Memory2'
                                        */

  /*  Expression: [0,0]
   * Referenced by: '<S45>/Memory1'
   */
  { 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S44>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S44>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Switch3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S19>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S33>/IC'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Switch4'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S54>/nuHat'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  20.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Switch5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S42>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S42>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S42>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Switch6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S42>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Switch7'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Constant1'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S14>/Constant'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Switch2'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S10>/Memory1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/Select'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/Select'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/Select'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/Select'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/Select'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/Select'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/Current Mode '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/Current Mode '
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/Current Mode '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/Current Mode '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/Current Mode '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/Current Mode '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/PosXRight'
                                        */

  /*  Expression:  [2*1.165 4*(1.165*0.8) 4*(1.165*0.8)*0.4575 2.629*0.3875]
   * Referenced by: '<S10>/Max_Global_Forces'
   */
  { 2.33, 3.728, 1.7055600000000002, 1.0187375 },
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S10>/Dead Zone'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S10>/Dead Zone'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S10>/Dead Zone1'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S10>/Dead Zone1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S10>/Gain'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S10>/Dead Zone2'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S10>/Dead Zone2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/tau_yaw'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/tau_yaw'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/tau_yaw'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/tau_yaw'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/tau_yaw'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/tau_yaw'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/tau_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/tau_x'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/tau_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/tau_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/tau_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/tau_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/tau_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/tau_y'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/tau_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/tau_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/tau_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/tau_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  18.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch2'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch3'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  15.0,                                /* Expression: portnum
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
  16.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S12>/Switch2'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */

  /*  Expression:  [1.165*2 2.629]
   * Referenced by: '<S9>/Actuator_Sat_Forces'
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
                                        * Referenced by: '<Root>/P_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/P_d'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/P_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/P_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/P_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/P_d'
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
                                        * Referenced by: '<Root>/S_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/S_out'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/S_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/S_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/S_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/S_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/sf2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/sf2'
                                        */
  10.0,                                /* Expression: portnum
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
  11.0,                                /* Expression: portnum
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
  12.0,                                /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/Y_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/psi_0 '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/x_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/integrator reset model'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S45>/Memory'
                                        */

  /*  Expression: [1;1;1]
   * Referenced by: '<S52>/Constant'
   */
  { 1.0, 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S52>/bHat'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S52>/IC1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S54>/IC'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/TurnOffomega1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/TurnOffomega1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_BT'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/TurnOffomega2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/TurnOffomega2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/TurnOffomega2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S72>/Step'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Switch'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Switch1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/f_bt'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/f_bt'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/f_bt'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/f_bt'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/f_bt'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/f_bt'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/f_vspx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/f_vspx'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/f_vspx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/f_vspx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/f_vspx'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/f_vspx'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ f_vspy'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ f_vspy'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/ f_vspy'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ f_vspy'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ f_vspy'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ f_vspy'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S11>/Integrator'
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 8, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
