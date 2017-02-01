/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#include "NIVERISTAND_API.h"
#if defined VXWORKS || defined kNIOSLinux
# define CSEI_u_P                      CSEI_u_P DataSection(".NIVS.defaultparams")
#endif

/*
 * CSEI_u_data.c
 *
 * Code generation for model "CSEI_u".
 *
 * Model version              : 1.26
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Mar 08 19:36:06 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "CSEI_u.h"
#include "CSEI_u_private.h"

/* Block parameters (auto storage) */
P_CSEI_u_T CSEI_u_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/integrator_reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/psi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/psi'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<Root>/Velocity'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/r'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/r'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/r'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/r'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/r'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/r'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/v'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/v'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/v'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/v'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/v'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/v'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/r_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/r_dot'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/r_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/r_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/r_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/r_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_dot'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/v_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/v_dot'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/v_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/v_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/v_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/v_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/X'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/X'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/Y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/Y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/Y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/N'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/N'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/N'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/N'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/N'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/N'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/psi_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/psi_0'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/psi_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/psi_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/psi_0'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/psi_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/x_0'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/x_0'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/x_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/y_0'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/y_0'
                                        */
  1.0                                  /* Expression: btype
                                        * Referenced by: '<S4>/y_0'
                                        */
};

#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  long size;
  long width;
  long basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_CSEI_u_T_sizes[] DataSection(".NIVS.defaultparamsizes") = {
  { sizeof(P_CSEI_u_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
};

#endif
