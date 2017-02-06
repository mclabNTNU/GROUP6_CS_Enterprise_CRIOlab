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
 * Model version              : 1.108
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Feb 06 10:26:20 2017
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
                                        * Referenced by: '<S19>/Constant1'
                                        */
  0.1,                                 /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S19>/Step'
                                        */
  0.0,                                 /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S19>/Constant'
                                        *   '<S19>/Step'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S1>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/counter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S12>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S12>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S13>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S13>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S11>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S11>/White Noise'
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
                                        * Referenced by: '<S7>/Hold'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_har'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_har'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_har'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_har'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_har'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_har'
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
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_in'
                                        */
  5.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/v_in'
                                        */
  6.0,                                 /* Expression: portnum
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
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S3>/Memory1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Select'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Select'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/Select'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Select'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Select'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Select'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S3>/Dead Zone'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S3>/Dead Zone'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S3>/Dead Zone1'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S3>/Dead Zone1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S3>/Gain'
                                        */
  -0.05,                               /* Expression: -0.05
                                        * Referenced by: '<S3>/Dead Zone2'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S3>/Dead Zone2'
                                        */

  /*  Expression:  [1.165*2 2.629+1.165*2 0.3875*2.629+0.4575*1.165*2 2.629 ]
   * Referenced by: '<S3>/Max_Global_Forces'
   */
  { 2.33, 4.959, 2.0847125, 2.629 },

  /*  Expression:  [1.165*2 2.629 ]
   * Referenced by: '<S3>/Sat_Forces'
   */
  { 2.33, 2.629 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_BT'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Step'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<S3>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Current Mode '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Current Mode '
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Current Mode '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Current Mode '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Current Mode '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Current Mode '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Error State Flag'
                                        */
  10.0,                                /* Expression: dtype
                                        * Referenced by: '<S3>/Error State Flag'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Error State Flag'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Error State Flag'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Error State Flag'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Error State Flag'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/f_vspx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/f_vspx'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/f_vspx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/f_vspx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/f_vspx'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/f_vspx'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/f_vspy'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/f_vspy'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/f_vspy'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/f_vspy'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/f_vspy'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/f_vspy'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/f_bt'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/f_bt'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/f_bt'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/f_bt'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/f_bt'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/f_bt'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/tau_yaw'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/tau_yaw'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/tau_yaw'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/tau_yaw'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/tau_yaw'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/tau_yaw'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/tau_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/tau_x'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/tau_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/tau_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/tau_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/tau_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/tau_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/tau_y'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/tau_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/tau_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/tau_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/tau_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/integrator reset model'
                                        */
  0.0676132521974307,                  /* Expression: 1/14.79
                                        * Referenced by: '<S2>/Gain'
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
};

#endif
