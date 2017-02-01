/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#include "NIVERISTAND_API.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_DP_P                     ctrl_DP_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_DP_data.c
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
#include "ctrl_DP.h"
#include "ctrl_DP_private.h"

/* Block parameters (auto storage) */
P_ctrl_DP_T ctrl_DP_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_p_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_p_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/K_p_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_p_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_p_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_p_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_p_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_p_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/K_p_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_p_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_p_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_p_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_p_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_p_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/K_p_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_p_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_p_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_p_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_i_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_i_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/K_i_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_i_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_i_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_i_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_i_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_i_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/K_i_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_i_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_i_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_i_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_i_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_i_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/K_i_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_i_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_i_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_i_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_d_psi'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/K_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_d_x'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/K_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_d_y'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/K_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_ff_r_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_ff_r_dot'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S17>/K_ff_r_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_ff_r_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_ff_r_dot'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_ff_r_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_ff_u_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_ff_u_dot'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S17>/K_ff_u_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_ff_u_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_ff_u_dot'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_ff_u_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_ff_v_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_ff_v_dot'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S17>/K_ff_v_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_ff_v_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_ff_v_dot'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_ff_v_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_ff_r'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_ff_r'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S17>/K_ff_r'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_ff_r'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_ff_r'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_ff_r'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_ff_u'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_ff_u'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<S17>/K_ff_u'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_ff_u'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_ff_u'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_ff_u'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/K_ff_v'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/K_ff_v'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<S17>/K_ff_v'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/K_ff_v'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/K_ff_v'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/K_ff_v'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/reset'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/w_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/w_d_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/w_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/w_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/w_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/w_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/w_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/w_d_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/w_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/w_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/w_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/w_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/w_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/w_d_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/w_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/w_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/w_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/w_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/zeta_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/zeta_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/zeta_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/zeta_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/zeta_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/zeta_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/zeta_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/zeta_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/zeta_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/zeta_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/zeta_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/zeta_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/zeta_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/zeta_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/zeta_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/zeta_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/zeta_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/zeta_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/VSP_on'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/VSP_on'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/VSP_on'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/VSP_on'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/VSP_on'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/VSP_on'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/psi_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/psi_ref'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/psi_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/psi_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/psi_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/psi_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/x_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/x_ref'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/x_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/x_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/x_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/x_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/y_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/y_ref'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/y_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/y_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/y_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/y_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/x'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/y'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/psi'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/r_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/r_hat'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/r_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/r_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/r_hat'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/r_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_hat'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_hat'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/v_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/v_hat'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/v_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/v_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/v_hat'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/v_hat'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S11>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S11>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S11>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S11>/Constant'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S10>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S10>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S10>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S10>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Integrator3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Integrator2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/DP_alpha2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/DP_alpha2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/DP_alpha2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/DP_alpha2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/DP_alpha2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/DP_alpha2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/DP_u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/DP_u_BT'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/DP_u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/DP_u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/DP_u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/DP_u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/DP_u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/DP_u_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/DP_u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/DP_u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/DP_u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/DP_u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/DP_omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/DP_omega_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/DP_omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/DP_omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/DP_omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/DP_omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/DP_u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/DP_u_VSP1'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/DP_u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/DP_u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/DP_u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/DP_u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/DP_alpha1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/DP_alpha1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/DP_alpha1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/DP_alpha1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/DP_alpha1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/DP_alpha1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/DP_omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/DP_omega_VSP1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/DP_omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/DP_omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/DP_omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/DP_omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S26>/tau_N'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S26>/tau_N'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S26>/tau_N'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S26>/tau_N'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S26>/tau_N'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S26>/tau_N'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S26>/tau_X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S26>/tau_X'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S26>/tau_X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S26>/tau_X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S26>/tau_X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S26>/tau_X'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S26>/tau_Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S26>/tau_Y'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S26>/tau_Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S26>/tau_Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S26>/tau_Y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S26>/tau_Y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S27>/x_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S27>/x_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S27>/x_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S27>/x_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S27>/x_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S27>/x_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S27>/y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S27>/y_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S27>/y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S27>/y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S27>/y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S27>/y_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S27>/psi_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S27>/psi_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S27>/psi_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S27>/psi_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S27>/psi_d'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<S27>/psi_d'
                                        */
};

#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  long size;
  long width;
  long basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_DP_T_sizes[] DataSection(".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_DP_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
