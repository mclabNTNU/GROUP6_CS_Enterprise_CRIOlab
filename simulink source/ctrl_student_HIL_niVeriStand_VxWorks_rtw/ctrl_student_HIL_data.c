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
#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

/* Block parameters (auto storage) */
P_ctrl_student_HIL_T ctrl_student_HIL_P = {
  1.0,                                 /* Variable: DesiredPath
                                        * Referenced by: '<S20>/SwitchSignalFromFile'
                                        */

  /*  Variable: Elipscenter_radi
   * Referenced by: '<S40>/Elipscenter_radi'
   */
  { 3.0, 0.0, 2.0, 1.0 },

  /*  Variable: K
   * Referenced by: '<Root>/K'
   */
  { 2.0, 10.0 },

  /*  Variable: K1
   * Referenced by:
   *   '<S2>/Constant1'
   *   '<S26>/Kp '
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 4.0 },

  /*  Variable: K2
   * Referenced by: '<S2>/Constant2'
   */
  { 200.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 3.0 },
  0.0,                                 /* Variable: LAW
                                        * Referenced by:
                                        *   '<S41>/TASK'
                                        *   '<S48>/TASK'
                                        */
  6000.0,                              /* Variable: T_initialDP
                                        * Referenced by: '<S50>/Constant1'
                                        */
  0.1,                                 /* Variable: U_ref
                                        * Referenced by:
                                        *   '<S39>/Constant'
                                        *   '<S50>/Constant'
                                        */

  /*  Variable: eta_dot_ini
   * Referenced by: '<S17>/Constant1'
   */
  { 7.0, 0.0, 0.0 },

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
                                        * Referenced by: '<S32>/Constant'
                                        */
  0.001,                               /* Variable: mu
                                        * Referenced by:
                                        *   '<S41>/mu '
                                        *   '<S48>/mu '
                                        */

  /*  Variable: pd
   * Referenced by: '<S47>/Desired Position'
   */
  { 2.0, 0.0, 10.0, 4.0 },
  0.0,                                 /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S81>/Constant1'
                                        */
  0.1,                                 /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S81>/Step'
                                        */
  0.0,                                 /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S81>/Constant'
                                        *   '<S81>/Step'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S61>/etaHat'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S61>/etaHat2'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S6>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S70>/counter'
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
                                        * Referenced by: '<S76>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S76>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S76>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S77>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S77>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S77>/White Noise'
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
                                        * Referenced by: '<S75>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S75>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S75>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/X_ship'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/X_ship'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/X_ship'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/X_ship'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/X_ship'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/X_ship'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S8>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/Y_ship'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/Y_ship'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/Y_ship'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/Y_ship'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/Y_ship'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/Y_ship'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S8>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/PSI_ship'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/PSI_ship'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/PSI_ship'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/PSI_ship'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/PSI_ship'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/PSI_ship'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S71>/Hold'
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
                                        * Referenced by: '<Root>/dropOutTolerance'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/dropOutTolerance'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/dropOutTolerance'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/dropOutTolerance'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/dropOutTolerance'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/dropOutTolerance'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/res_ship'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/res_ship'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/res_ship'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/res_ship'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/res_ship'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/res_ship'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Residual'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Residual'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Residual'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Residual'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Residual'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Residual'
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
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  18.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S26>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S41>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/IC'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S48>/Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S50>/Memory2'
                                        */

  /*  Expression: [0,0]
   * Referenced by: '<S50>/Memory1'
   */
  { 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S49>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Switch3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S24>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/IC'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Switch4'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S59>/nuHat'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  19.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S20>/Switch5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S47>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S47>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S47>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Switch6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S47>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Switch7'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Constant1'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S19>/Constant'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Switch2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/CurrentModeSelector'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/CurrentModeSelector'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<S14>/CurrentModeSelector'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/CurrentModeSelector'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/CurrentModeSelector'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/CurrentModeSelector'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/Current Mode '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/Current Mode '
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/Current Mode '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/Current Mode '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/Current Mode '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/Current Mode '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/PosXRight'
                                        */

  /*  Expression:  [2*1.165 4*(1.165*0.8) 4*(1.165*0.8)*0.4575 2.629]
   * Referenced by: '<S14>/Max_Global_Forces'
   */
  { 2.33, 3.728, 1.7055600000000002, 2.629 },
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S14>/Dead Zone'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S14>/Dead Zone'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/PosYRight'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S14>/Dead Zone1'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S14>/Dead Zone1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/R2_continuous'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S14>/Gain'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S14>/Dead Zone2'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S14>/Dead Zone2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/tau_yaw'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/tau_yaw'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/tau_yaw'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/tau_yaw'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/tau_yaw'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/tau_yaw'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/tau_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/tau_x'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/tau_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/tau_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/tau_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/tau_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/tau_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/tau_y'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/tau_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/tau_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/tau_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/tau_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S14>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S14>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S14>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/ArrowRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/Select'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/Select'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S14>/Select'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/Select'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/Select'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/Select'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  17.0,                                /* Expression: portnum
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
  5.0,                                 /* Expression: portnum
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
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */

  /*  Expression:  [1.165*2 2.629]
   * Referenced by: '<S10>/Actuator_Sat_Forces'
   */
  { 2.33, 2.629 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  6.0,                                 /* Expression: portnum
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
  7.0,                                 /* Expression: portnum
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

  /*  Expression: [0;0;0]
   * Referenced by: '<S11>/Memory'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/dropoutFlag'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/dropoutFlag'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/dropoutFlag'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/dropoutFlag'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/dropoutFlag'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/dropoutFlag'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S57>/bHat'
                                        */

  /*  Expression: [1;1;1]
   * Referenced by: '<S57>/Constant'
   */
  { 1.0, 1.0, 1.0 },
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

  /*  Expression: [0;0;0]
   * Referenced by: '<S57>/IC1'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Bias'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Bias'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Bias'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Bias'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Bias'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Bias'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Switch1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/S'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/S'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/S'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/S'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/S'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/S'
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
                                        * Referenced by: '<Root>/nu_hat '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/nu_hat '
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/nu_hat '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/nu_hat '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/nu_hat '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/nu_hat '
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

  /*  Expression: [0,0,0]'
   * Referenced by: '<S59>/Delay'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/delay2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/delay2'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/delay2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/delay2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/delay2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/delay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/delay1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/delay1'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/delay1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/delay1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/delay1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/delay1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  14.0,                                /* Expression: portnum
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
  15.0,                                /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/Y_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/psi_0 '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/x_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/integrator reset model'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/TurnOffomega1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/TurnOffomega1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/TurnOffomega2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/TurnOffomega2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S18>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S98>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S98>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S98>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S98>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S98>/control input u exceeds bounds'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S98>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S100>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S100>/alpha_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S100>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S100>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S100>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S100>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S100>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S100>/alpha_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S100>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S100>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S100>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S100>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S100>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S100>/omega_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S100>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S100>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S100>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S100>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S100>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S100>/omega_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S100>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S100>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S100>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S100>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S100>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S100>/u_BT'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S100>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S100>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S100>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S100>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S100>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S100>/u_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S100>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S100>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S100>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S100>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S100>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S100>/u_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S100>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S100>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S100>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S100>/u_VSP2'
                                        */

  /*  Expression:  [1.165*2 2.629]
   * Referenced by: '<S18>/Actuator_Sat_Forces'
   */
  { 2.33, 2.629 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S18>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S18>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S50>/Memory'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S67>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S67>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S67>/Switch3'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S59>/IC'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<Root>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/eta_real'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/eta_real'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/eta_real'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/eta_real'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/eta_real'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/eta_real'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/TurnOffomega1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/TurnOffomega1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/TurnOffomega1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/TurnOffomega2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/TurnOffomega2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/TurnOffomega2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/TurnOffomega2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S81>/Step'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<S10>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Switch'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Switch1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/f_bt'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/f_bt'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/f_bt'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/f_bt'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/f_bt'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/f_bt'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/f_vspx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/f_vspx'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/f_vspx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/f_vspx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/f_vspx'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/f_vspx'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ f_vspy'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ f_vspy'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/ f_vspy'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ f_vspy'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ f_vspy'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ f_vspy'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/y_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/y_in'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/y_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/y_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/y_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/y_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/psi_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/psi_in'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/psi_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/psi_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/psi_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/psi_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/u_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/u_in'
                                        */
  17.0,                                /* Expression: portnum
                                        * Referenced by: '<S13>/u_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/u_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/u_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/u_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/u_real  '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/u_real  '
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/u_real  '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/u_real  '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/u_real  '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/u_real  '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/x_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/x_in'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/x_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/x_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/x_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/x_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/r_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/r_in'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/r_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/r_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/r_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/r_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/v_in'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/v_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/v_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/v_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/v_in'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
  1U                                   /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S59>/Delay'
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

  { sizeof(real_T), 2, 0 },

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

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(uint32_T), 1, 7 },
};

#endif
