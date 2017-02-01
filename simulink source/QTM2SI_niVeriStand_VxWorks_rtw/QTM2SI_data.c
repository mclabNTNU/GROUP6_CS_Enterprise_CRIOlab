/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#include "NIVERISTAND_API.h"
#if defined VXWORKS || defined kNIOSLinux
# define QTM2SI_P                      QTM2SI_P DataSection(".NIVS.defaultparams")
#endif

/*
 * QTM2SI_data.c
 *
 * Code generation for model "QTM2SI".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Feb 25 13:54:05 2015
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "QTM2SI.h"
#include "QTM2SI_private.h"

/* Block parameters (auto storage) */
P_QTM2SI_T QTM2SI_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/X'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/X'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/X'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<Root>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Y'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Pitch'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Pitch'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Pitch'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Pitch'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Pitch'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Pitch'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Z'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Z'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<Root>/Gain2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/z'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/z'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/z'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Roll'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Roll'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Roll'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Roll'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Roll'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Roll'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/phi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/phi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/phi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/phi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/phi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/phi'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/theta'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/theta'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/theta'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/theta'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/theta'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/theta'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Yaw'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Yaw'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Yaw'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Yaw'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Yaw'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Yaw'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain5'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<Root>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<Root>/Gain6'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<Root>/psi'
                                        */
};

#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  long size;
  long width;
  long basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_QTM2SI_T_sizes[] DataSection(".NIVS.defaultparamsizes") = {
  { sizeof(P_QTM2SI_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
