/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#include "NIVERISTAND_API.h"
#if defined VXWORKS || defined kNIOSLinux
# define u2pwm_P                       u2pwm_P DataSection(".NIVS.defaultparams")
#endif

/*
 * u2pwm_data.c
 *
 * Code generation for model "u2pwm".
 *
 * Model version              : 1.24
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Dec 04 15:19:16 2015
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "u2pwm.h"
#include "u2pwm_private.h"

/* Block parameters (auto storage) */
P_u2pwm_T u2pwm_P = {
  1.9350000000000003,                  /* Variable: BT_u2pwm_gain
                                        * Referenced by: '<Root>/VPS_Speed_Gain1'
                                        */
  4.965,                               /* Variable: BT_zero_pwm
                                        * Referenced by: '<Root>/VPS_Power_Offset1'
                                        */
  1.8900000000000001,                  /* Variable: VSP_u2pwm_gain
                                        * Referenced by:
                                        *   '<Root>/VPS_Speed_Gain'
                                        *   '<Root>/VPS_Speed_Gain2'
                                        */
  5.01,                                /* Variable: VSP_zero_pwm
                                        * Referenced by: '<Root>/VPS_Power_Offset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  1.5707963267948966,                  /* Expression: pi/2
                                        * Referenced by: '<Root>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation4'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation4'
                                        */
  0.88,                                /* Expression: .88
                                        * Referenced by: '<Root>/Gain4'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */

  /*  Expression: servo_mapping(:,:,1)
   * Referenced by: '<Root>/2-D Lookup Table'
   */
  { 4.4757359312880709, 4.6661165235168145, 5.25, 5.7828279195104679,
    6.1020815280171306, 4.3732233047033624, 4.6, 5.1474873734152915, 5.75,
    5.9995689014324221, 4.25, 4.4403805922287445, 4.9, 5.6707463914933367, 5.99,
    4.0514718625761423, 4.3, 4.9, 5.4, 5.6071067811865483, 4.0514718625761423,
    4.2418524548048868, 4.9, 5.2878531726798848, 5.6071067811865483 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<Root>/2-D Lookup Table'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<Root>/2-D Lookup Table'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */

  /*  Expression: servo_mapping(:,:,2)
   * Referenced by: '<Root>/2-D Lookup Table1'
   */
  { 5.9937972567696693, 5.8824978336205573, 5.75, 5.8168124086713195,
    5.7816652224137046, 5.7214065632731588, 5.65, 5.4776093065034894, 5.5,
    5.509274528917194, 5.2, 5.0887005768508882, 4.82, 4.7351471862576142, 4.7,
    4.5929794385269682, 4.5, 4.2755277784863583, 4.1, 4.0272940135777295,
    4.36745166004061, 4.2561522368914977, 4.05, 3.8369134213489855,
    3.801766235091371 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<Root>/2-D Lookup Table1'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<Root>/2-D Lookup Table1'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },
  1.5707963267948966,                  /* Expression: pi/2
                                        * Referenced by: '<Root>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain2'
                                        */

  /*  Expression: servo_mapping(:,:,3)
   * Referenced by: '<Root>/2-D Lookup Table2'
   */
  { 3.9390454557049503, 3.9038982694473359, 4.15, 4.1160303038032993,
    4.1511774900609133, 4.1382128444980975, 4.2, 4.3491673887931483, 4.35,
    4.3503448788540613, 4.95, 4.9148528137423861, 4.83, 4.9148528137423861, 4.95,
    5.6084776310850231, 5.6, 5.5795331880577406, 5.6, 5.6084776310850231,
    5.9189444430272822, 5.8837972567696681, 5.89, 5.8837972567696681,
    5.9189444430272822 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<Root>/2-D Lookup Table2'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<Root>/2-D Lookup Table2'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain3'
                                        */

  /*  Expression: servo_mapping(:,:,4)
   * Referenced by: '<Root>/2-D Lookup Table3'
   */
  { 4.2088730162779191, 4.4051114728829317, 4.85, 5.47747258045114,
    5.7645079348883241, 4.11221825406948, 4.3, 4.75334523779156, 5.4,
    5.6678531726798855, 3.85, 4.0462384566050131, 4.52, 5.2129646455628169, 5.5,
    3.6841926419625644, 3.9, 4.4210050506338829, 5.0, 5.2398275605729694,
    3.6431875913286813, 3.8394260479336939, 4.38, 4.9117871555019024,
    5.1988225099390863 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<Root>/2-D Lookup Table3'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },

  /*  Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
   * Referenced by: '<Root>/2-D Lookup Table3'
   */
  { -1.0, -0.70710678118654757, 0.0, 0.70710678118654757, 1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/pwm_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_BT'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/pwm_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/pwm_BT'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/pwm_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/pwm_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/pwm_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/pwm_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/pwm_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/pwm_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/pwm_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/pwm_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/pwm_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/pwm_servo1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_servo1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_servo1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/pwm_servo1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/pwm_servo1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/pwm_servo1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/pwm_servo2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_servo2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_servo2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/pwm_servo2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/pwm_servo2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/pwm_servo2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/pwm_servo3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_servo3'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_servo3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/pwm_servo3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/pwm_servo3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/pwm_servo3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/pwm_servo4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_servo4'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_servo4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/pwm_servo4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/pwm_servo4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/pwm_servo4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/manual override'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/manual override'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/manual override'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/manual override'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/manual override'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/manual override'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_VSP1'
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
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_BT'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_BT'
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
  1.0,                                 /* Expression: btype
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
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/pwm_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_VSP1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/pwm_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/pwm_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/pwm_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/pwm_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/pwm_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/pwm_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/pwm_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/pwm_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_BT'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/pwm_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/pwm_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/pwm_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/pwm_servo4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_servo4'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_servo4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/pwm_servo4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/pwm_servo4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/pwm_servo4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/pwm_servo3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_servo3'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_servo3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/pwm_servo3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/pwm_servo3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/pwm_servo3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/pwm_servo1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_servo1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_servo1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/pwm_servo1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/pwm_servo1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/pwm_servo1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/pwm_servo2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_servo2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_servo2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/pwm_servo2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/pwm_servo2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/pwm_servo2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */

  /*  Computed Parameter: DLookupTable_maxIndex
   * Referenced by: '<Root>/2-D Lookup Table'
   */
  { 4U, 4U },

  /*  Computed Parameter: DLookupTable1_maxIndex
   * Referenced by: '<Root>/2-D Lookup Table1'
   */
  { 4U, 4U },

  /*  Computed Parameter: DLookupTable2_maxIndex
   * Referenced by: '<Root>/2-D Lookup Table2'
   */
  { 4U, 4U },

  /*  Computed Parameter: DLookupTable3_maxIndex
   * Referenced by: '<Root>/2-D Lookup Table3'
   */
  { 4U, 4U }
};

#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  long size;
  long width;
  long basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_u2pwm_T_sizes[] DataSection(".NIVS.defaultparamsizes") = {
  { sizeof(P_u2pwm_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 25, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 25, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 25, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 25, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 5, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(uint32_T), 2, 7 },

  { sizeof(uint32_T), 2, 7 },

  { sizeof(uint32_T), 2, 7 },

  { sizeof(uint32_T), 2, 7 },
};

#endif
