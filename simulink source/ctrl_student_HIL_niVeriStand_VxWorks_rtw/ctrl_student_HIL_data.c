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
 * Model version              : 1.339
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Apr 06 16:23:57 2017
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
                                        * Referenced by: '<S19>/SwitchSignalFromFile'
                                        */

  /*  Variable: Elipscenter_radi
   * Referenced by: '<S39>/Elipscenter_radi'
   */
  { 6.0, 0.0, 5.0, 3.0 },

  /*  Variable: K
   * Referenced by: '<Root>/K'
   */
  { 2.0, 10.0 },

  /*  Variable: K1
   * Referenced by:
   *   '<S2>/Constant1'
   *   '<S25>/Kp '
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 4.0 },

  /*  Variable: K2
   * Referenced by: '<S2>/Constant2'
   */
  { 200.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 3.0 },
  1.0,                                 /* Variable: LAW
                                        * Referenced by:
                                        *   '<S40>/TASK'
                                        *   '<S47>/TASK'
                                        */
  9000.0,                              /* Variable: T_initialDP
                                        * Referenced by: '<S49>/Constant1'
                                        */
  0.16,                                /* Variable: U_ref
                                        * Referenced by:
                                        *   '<S38>/Constant'
                                        *   '<S49>/Constant'
                                        */

  /*  Variable: eta_dot_ini
   * Referenced by: '<S16>/Constant1'
   */
  { 1.6, -1.75, 0.0 },

  /*  Variable: l1
   * Referenced by: '<S6>/Constant1'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.05 },

  /*  Variable: l2
   * Referenced by: '<S6>/Constant2'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.05 },

  /*  Variable: l3
   * Referenced by: '<S6>/Constant3'
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
                                        * Referenced by: '<S31>/Constant'
                                        */
  0.0,                                 /* Variable: mu
                                        * Referenced by:
                                        *   '<S40>/mu '
                                        *   '<S47>/mu '
                                        */

  /*  Variable: pd
   * Referenced by: '<S46>/Desired Position'
   */
  { 1.6, -1.75, 0.6, 5.6 },
  0.0,                                 /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S79>/Constant1'
                                        */
  0.1,                                 /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S79>/Step'
                                        */
  0.0,                                 /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S79>/Constant'
                                        *   '<S79>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Switch1'
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
                                        * Referenced by: '<S60>/etaHat'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S60>/etaHat2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/X_ship'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/X_ship'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/X_ship'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/X_ship'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/X_ship'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/X_ship'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/Y_ship'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/Y_ship'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/Y_ship'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/Y_ship'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/Y_ship'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/Y_ship'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/PSI_ship'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/PSI_ship'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/PSI_ship'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/PSI_ship'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/PSI_ship'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/PSI_ship'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/res_ship'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/res_ship'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/res_ship'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/res_ship'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/res_ship'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/res_ship'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S65>/Constant'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S65>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S65>/Switch3'
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
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S7>/Gain'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S7>/Gain1'
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
                                        * Referenced by: '<S68>/counter'
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
                                        * Referenced by: '<S74>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S74>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S74>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S75>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S75>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S75>/White Noise'
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
                                        * Referenced by: '<S73>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S73>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S73>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S69>/Hold'
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
                                        * Referenced by: '<S25>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S40>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/IC'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S47>/Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S49>/Memory2'
                                        */

  /*  Expression: [0,0]
   * Referenced by: '<S49>/Memory1'
   */
  { 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S48>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S48>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Switch3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S23>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/IC'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Switch4'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S58>/nuHat'
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
                                        * Referenced by: '<S19>/Switch5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S46>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S46>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S46>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Switch6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S46>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Switch7'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S18>/Constant1'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S18>/Constant'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Switch2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/Select'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/Select'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S13>/Select'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/Select'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/Select'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/Select'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/Current Mode '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/Current Mode '
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/Current Mode '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/Current Mode '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/Current Mode '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/Current Mode '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/PosXRight'
                                        */

  /*  Expression:  [2*1.165 4*(1.165*0.8) 4*(1.165*0.8)*0.4575 2.629]
   * Referenced by: '<S13>/Max_Global_Forces'
   */
  { 2.33, 3.728, 1.7055600000000002, 2.629 },
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S13>/Dead Zone'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S13>/Dead Zone'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/PosYRight'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S13>/Dead Zone1'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S13>/Dead Zone1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/R2_continuous'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S13>/Gain'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S13>/Dead Zone2'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S13>/Dead Zone2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/tau_yaw'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/tau_yaw'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/tau_yaw'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/tau_yaw'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/tau_yaw'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/tau_yaw'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/tau_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/tau_x'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/tau_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/tau_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/tau_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/tau_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/tau_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/tau_y'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/tau_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/tau_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/tau_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/tau_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S13>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S13>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S13>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/ArrowRight'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Memory'
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
                                        * Referenced by: '<S15>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Memory'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Switch2'
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
                                        * Referenced by: '<S16>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/Y_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/psi_0 '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/x_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/integrator reset model'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S49>/Memory'
                                        */

  /*  Expression: [1;1;1]
   * Referenced by: '<S56>/Constant'
   */
  { 1.0, 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S56>/bHat'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S56>/IC1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S58>/IC'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/eta_real'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/eta_real'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/eta_real'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/eta_real'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/eta_real'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/eta_real'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant2'
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
                                        * Referenced by: '<S79>/Step'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant3'
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/y_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/y_in'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/y_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/y_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/y_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/y_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/psi_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/psi_in'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/psi_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/psi_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/psi_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/psi_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/u_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/u_in'
                                        */
  17.0,                                /* Expression: portnum
                                        * Referenced by: '<S12>/u_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/u_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/u_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/u_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/u_real  '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/u_real  '
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/u_real  '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/u_real  '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/u_real  '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/u_real  '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/x_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/x_in'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/x_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/x_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/x_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/x_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/r_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/r_in'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/r_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/r_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/r_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/r_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/v_in'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/v_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/v_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/v_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/v_in'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S93>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S93>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S93>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S93>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S93>/control input u exceeds bounds'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S93>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S95>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S95>/alpha_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S95>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S95>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S95>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S95>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S95>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S95>/alpha_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S95>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S95>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S95>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S95>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S95>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S95>/omega_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S95>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S95>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S95>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S95>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S95>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S95>/omega_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S95>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S95>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S95>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S95>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S95>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S95>/u_BT'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S95>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S95>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S95>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S95>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S95>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S95>/u_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S95>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S95>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S95>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S95>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S95>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S95>/u_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S95>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S95>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S95>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S95>/u_VSP2'
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
