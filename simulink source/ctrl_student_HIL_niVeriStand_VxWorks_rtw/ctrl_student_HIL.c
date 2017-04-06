/*
 * ctrl_student_HIL.c
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

/* Block signals (auto storage) */
B_ctrl_student_HIL_T ctrl_student_HIL_B;

/* Continuous states */
X_ctrl_student_HIL_T ctrl_student_HIL_X;

/* Block states (auto storage) */
DW_ctrl_student_HIL_T ctrl_student_HIL_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_student_HIL_T ctrl_student_HIL_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_student_HIL_T ctrl_student_HIL_M_;
RT_MODEL_ctrl_student_HIL_T *const ctrl_student_HIL_M = &ctrl_student_HIL_M_;

/* Forward declaration for local functions */
static void ctrl_student_HIL_mldivide(const real_T A[9], const real_T B[3],
  real_T Y[3]);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 17;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_student_HIL_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S23>/MATLAB Function1'
 *    '<S24>/R Transposed'
 */
void ctrl_student_HI_MATLABFunction1(const real_T rtu_R[9],
  B_MATLABFunction1_ctrl_studen_T *localB)
{
  int32_T i;

  /* MATLAB Function 'ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1': '<S27>:1' */
  /* '<S27>:1:3' */
  for (i = 0; i < 3; i++) {
    localB->R_T[3 * i] = rtu_R[i];
    localB->R_T[1 + 3 * i] = rtu_R[i + 3];
    localB->R_T[2 + 3 * i] = rtu_R[i + 6];
  }
}

/*
 * Output and update for atomic system:
 *    '<S23>/Rotation Matrix'
 *    '<S24>/Rotation Matrix'
 */
void ctrl_student_HIL_RotationMatrix(real_T rtu_yaw,
  B_RotationMatrix_ctrl_student_T *localB)
{
  /* MATLAB Function 'ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix': '<S28>:1' */
  /* '<S28>:1:3' */
  localB->R[0] = cos(rtu_yaw);
  localB->R[3] = -sin(rtu_yaw);
  localB->R[6] = 0.0;
  localB->R[1] = sin(rtu_yaw);
  localB->R[4] = cos(rtu_yaw);
  localB->R[7] = 0.0;
  localB->R[2] = 0.0;
  localB->R[5] = 0.0;
  localB->R[8] = 1.0;
}

/*
 * Output and update for atomic system:
 *    '<S40>/MATLAB Function1'
 *    '<S47>/MATLAB Function1'
 */
void ctrl_student__MATLABFunction1_m(real_T rtu_SwitchSignal_In,
  B_MATLABFunction1_ctrl_stud_k_T *localB)
{
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/MATLAB Function1': '<S44>:1' */
  if (rtu_SwitchSignal_In == 0.0) {
    /* '<S44>:1:3' */
    /* '<S44>:1:4' */
    localB->SwitchSignal_Out = 1.0;
  } else {
    /* '<S44>:1:6' */
    localB->SwitchSignal_Out = 0.0;
  }
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S17>/Full thrust allocation' */
static void ctrl_student_HIL_mldivide(const real_T A[9], const real_T B[3],
  real_T Y[3])
{
  real_T b_A[9];
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real_T maxval;
  real_T a21;
  int32_T rtemp;
  memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(A[0]);
  a21 = fabs(A[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(A[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  b_A[r2] = A[r2] / A[r1];
  b_A[r3] /= b_A[r1];
  b_A[3 + r2] -= b_A[3 + r1] * b_A[r2];
  b_A[3 + r3] -= b_A[3 + r1] * b_A[r3];
  b_A[6 + r2] -= b_A[6 + r1] * b_A[r2];
  b_A[6 + r3] -= b_A[6 + r1] * b_A[r3];
  if (fabs(b_A[3 + r3]) > fabs(b_A[3 + r2])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  b_A[3 + r3] /= b_A[3 + r2];
  b_A[6 + r3] -= b_A[3 + r3] * b_A[6 + r2];
  Y[1] = B[r2] - B[r1] * b_A[r2];
  Y[2] = (B[r3] - B[r1] * b_A[r3]) - b_A[3 + r3] * Y[1];
  Y[2] /= b_A[6 + r3];
  Y[0] = B[r1] - b_A[6 + r1] * Y[2];
  Y[1] -= b_A[6 + r2] * Y[2];
  Y[1] /= b_A[3 + r2];
  Y[0] -= b_A[3 + r1] * Y[1];
  Y[0] /= b_A[r1];
}

/* Model output function */
void ctrl_student_HIL_output(void)
{
  /* local block i/o variables */
  real_T rtb_etaHat;
  real_T rtb_etaHat2;
  real_T rtb_etaHat1;
  real_T rtb_Integrator1[3];
  real_T rtb_Integrator[3];
  real_T rtb_Clock;
  real_T rtb_Memory;
  real_T rtb_Memory_b;
  real_T deg2;
  real_T S_T[9];
  real_T y[9];
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  static const real_T b[9] = { 1.165, 0.0, 0.0, 0.0, 1.165, 0.0, 0.0, 0.0, 2.629
  };

  static const real_T c[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, -0.4575, 0.0, 1.0,
    0.3875 };

  real_T rtb_reset;
  real_T rtb_Gain;
  real_T rtb_Gain1;
  real_T rtb_Switch5;
  real_T rtb_U_ss;
  real_T rtb_rad;
  real_T rtb_eta_ds[3];
  real_T rtb_safety_sig_4;
  real_T rtb_Product2_o[9];
  real_T rtb_Product_j[3];
  real_T rtb_M[9];
  int32_T i;
  static const real_T tmp[9] = { 16.79, 0.0, 0.0, 0.0, 24.79,
    0.55462499999999992, 0.0, 0.55462499999999992, 2.76 };

  real_T tmp_0[3];
  real_T tmp_1[3];
  real_T S_T_0[3];
  real_T S_T_1[3];
  real_T rtb_Product2_i[3];
  real_T S_T_2[3];
  real_T tmp_2[9];
  real_T tmp_3[9];
  real_T tmp_4[9];
  real_T tmp_5[9];
  real_T rtb_eta_dss_idx_1;
  real_T rtb_eta_dss_idx_0;
  real_T rtb_pd_s_idx_0;
  real_T rtb_pd_s_idx_1;
  real_T rtb_eta_dss_idx_2;
  real_T rtb_DesPosOut_idx_0;
  real_T rtb_DesPosOut_idx_1;
  real_T rtb_Switch3_idx_2;
  real_T rtb_Switch3_idx_0;
  real_T rtb_Switch3_idx_1;
  real_T rtb_InitPosOut_idx_0;
  real_T rtb_InitPosOut_idx_1;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* set solver stop time */
    if (!(ctrl_student_HIL_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_student_HIL_M->solverInfo,
                            ((ctrl_student_HIL_M->Timing.clockTickH0 + 1) *
        ctrl_student_HIL_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_student_HIL_M->solverInfo,
                            ((ctrl_student_HIL_M->Timing.clockTick0 + 1) *
        ctrl_student_HIL_M->Timing.stepSize0 +
        ctrl_student_HIL_M->Timing.clockTickH0 *
        ctrl_student_HIL_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_student_HIL_M)) {
    ctrl_student_HIL_M->Timing.t[0] = rtsiGetT(&ctrl_student_HIL_M->solverInfo);
  }

  /* Integrator: '<S60>/etaHat' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.etaHat_Reset_ZCE,
                       ctrl_student_HIL_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.etaHat_CSTATE = ctrl_student_HIL_P.etaHat_IC;
    }
  }

  rtb_etaHat = ctrl_student_HIL_X.etaHat_CSTATE;

  /* Integrator: '<S60>/etaHat2' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.etaHat2_Reset_ZCE,
                       ctrl_student_HIL_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.etaHat2_CSTATE = ctrl_student_HIL_P.etaHat2_IC;
    }
  }

  rtb_etaHat2 = ctrl_student_HIL_X.etaHat2_CSTATE;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S7>/Memory' */
    ctrl_student_HIL_B.Memory = ctrl_student_HIL_DW.Memory_PreviousInput;
  }

  /* MATLAB Function: '<S7>/Deg2Rad' */
  /* MATLAB Function 'Position/Deg2Rad': '<S76>:1' */
  /* '<S76>:1:3' */
  deg2 = ctrl_student_HIL_B.PSI_ship - floor(ctrl_student_HIL_B.PSI_ship / 360.0)
    * 360.0;

  /* '<S76>:1:4' */
  ctrl_student_HIL_B.deg_out = deg2;
  if (deg2 - ctrl_student_HIL_B.Memory > 320.0) {
    /* '<S76>:1:6' */
    /* '<S76>:1:7' */
    rtb_reset = 1.0;
  } else if (deg2 - ctrl_student_HIL_B.Memory < -320.0) {
    /* '<S76>:1:8' */
    /* '<S76>:1:9' */
    rtb_reset = -1.0;
  } else {
    /* '<S76>:1:11' */
    rtb_reset = 0.0;
  }

  /* '<S76>:1:14' */
  rtb_rad = deg2 * 3.1415926535897931 / 180.0;

  /* End of MATLAB Function: '<S7>/Deg2Rad' */

  /* Sum: '<S60>/Sum' */
  ctrl_student_HIL_B.Sum = ctrl_student_HIL_B.reset + rtb_reset;

  /* MATLAB Function: '<S65>/MATLAB Function1' */
  /* MATLAB Function 'DPObserver1/etaHat/Subsystem/MATLAB Function1': '<S67>:1' */
  if (rtb_reset == -1.0) {
    /* '<S67>:1:3' */
    /* '<S67>:1:4' */
    deg2 = 0.0;
  } else {
    /* '<S67>:1:6' */
    deg2 = 1.0;
  }

  /* End of MATLAB Function: '<S65>/MATLAB Function1' */

  /* Switch: '<S65>/Switch3' incorporates:
   *  Constant: '<S65>/Constant'
   *  Constant: '<S65>/Constant1'
   */
  if (deg2 > ctrl_student_HIL_P.Switch3_Threshold) {
    ctrl_student_HIL_B.Switch3 = ctrl_student_HIL_P.Constant_Value;
  } else {
    ctrl_student_HIL_B.Switch3 = ctrl_student_HIL_P.Constant1_Value;
  }

  /* End of Switch: '<S65>/Switch3' */

  /* Integrator: '<S65>/etaHat1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.etaHat1_Reset_ZCE,
                       ctrl_student_HIL_B.Sum);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_student_HIL_DW.etaHat1_IWORK.IcNeedsLoading) {
      ctrl_student_HIL_X.etaHat1_CSTATE = ctrl_student_HIL_B.Switch3;
    }
  }

  rtb_etaHat1 = ctrl_student_HIL_X.etaHat1_CSTATE;

  /* SignalConversion: '<Root>/TmpSignal ConversionAteta_hatInport1' */
  ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp[0] = rtb_etaHat;
  ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp[1] = rtb_etaHat2;
  ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp[2] = rtb_etaHat1;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* MATLAB Function 'MATLAB Function': '<S4>:1' */
    if (ctrl_student_HIL_B.res_ship >= 1.0) {
      /* '<S4>:1:3' */
      /* '<S4>:1:4' */
      deg2 = 1.0;
    } else {
      /* '<S4>:1:6' */
      deg2 = 0.0;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function' */

    /* SignalConversion: '<Root>/TmpSignal ConversionAtResidualInport1' */
    ctrl_student_HIL_B.TmpSignalConversionAtResidualIn[0] =
      ctrl_student_HIL_B.res_ship;
    ctrl_student_HIL_B.TmpSignalConversionAtResidualIn[1] = deg2;
  }

  /* Gain: '<S7>/Gain' */
  rtb_Gain = ctrl_student_HIL_P.Gain_Gain * ctrl_student_HIL_B.X_ship;

  /* Gain: '<S7>/Gain1' */
  rtb_Gain1 = ctrl_student_HIL_P.Gain1_Gain * ctrl_student_HIL_B.Y_ship;

  /* SignalConversion: '<S7>/TmpSignal ConversionAteta_realInport1' */
  ctrl_student_HIL_B.TmpSignalConversionAteta_realIn[0] = rtb_Gain;
  ctrl_student_HIL_B.TmpSignalConversionAteta_realIn[1] = rtb_Gain1;
  ctrl_student_HIL_B.TmpSignalConversionAteta_realIn[2] = rtb_rad;

  /* Sum: '<Root>/Sum1' */
  ctrl_student_HIL_B.Sum1[0] =
    ctrl_student_HIL_B.TmpSignalConversionAteta_realIn[0] -
    ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp[0];
  ctrl_student_HIL_B.Sum1[1] =
    ctrl_student_HIL_B.TmpSignalConversionAteta_realIn[1] -
    ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp[1];
  ctrl_student_HIL_B.Sum1[2] =
    ctrl_student_HIL_B.TmpSignalConversionAteta_realIn[2] -
    ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* MATLAB Function: '<S68>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<S5>/Step size'
     *  Memory: '<S68>/counter'
     */
    /* MATLAB Function 'Noise generator/Downsample	signal/MATLAB Function': '<S71>:1' */
    /* '<S71>:1:3' */
    if ((ctrl_student_HIL_DW.counter_PreviousInput + 1.0) *
        ctrl_student_HIL_P.Stepsize_Value >= 1.0 /
        ctrl_student_HIL_P.Constant_Value_d) {
      /* '<S71>:1:4' */
      /* '<S71>:1:5' */
      ctrl_student_HIL_B.count = 0.0;
    } else {
      /* '<S71>:1:7' */
      ctrl_student_HIL_B.count = ctrl_student_HIL_DW.counter_PreviousInput + 1.0;
    }

    /* End of MATLAB Function: '<S68>/MATLAB Function' */
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S74>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise = ctrl_student_HIL_DW.NextOutput;
  }

  /* Product: '<S75>/Divide' incorporates:
   *  Constant: '<S5>/Step size'
   */
  rtb_Clock = ctrl_student_HIL_B.NoisePowPos / ctrl_student_HIL_P.Stepsize_Value;

  /* Sqrt: '<S75>/Sqrt' */
  rtb_Clock = sqrt(rtb_Clock);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S75>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_e = ctrl_student_HIL_DW.NextOutput_c;
  }

  /* Product: '<S75>/Product' */
  rtb_Clock *= ctrl_student_HIL_B.WhiteNoise_e;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S73>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_m = ctrl_student_HIL_DW.NextOutput_p;

    /* Memory: '<S69>/Hold' */
    ctrl_student_HIL_B.Hold[0] = ctrl_student_HIL_DW.Hold_PreviousInput[0];
    ctrl_student_HIL_B.Hold[1] = ctrl_student_HIL_DW.Hold_PreviousInput[1];
    ctrl_student_HIL_B.Hold[2] = ctrl_student_HIL_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S69>/MATLAB Function1' incorporates:
   *  Constant: '<S5>/Step size'
   *  Product: '<S73>/Divide'
   *  Product: '<S73>/Product'
   *  Product: '<S74>/Divide'
   *  Product: '<S74>/Product'
   *  Sqrt: '<S73>/Sqrt'
   *  Sqrt: '<S74>/Sqrt'
   *  Sum: '<S5>/Sum'
   */
  /* MATLAB Function 'Noise generator/Sample & hold/MATLAB Function1': '<S72>:1' */
  if (ctrl_student_HIL_B.count == 0.0) {
    /* '<S72>:1:4' */
    /* '<S72>:1:5' */
    ctrl_student_HIL_B.output[0] = sqrt(ctrl_student_HIL_B.NoisePowPos /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise +
      ctrl_student_HIL_B.TmpSignalConversionAteta_realIn[0];
    ctrl_student_HIL_B.output[1] = rtb_Clock +
      ctrl_student_HIL_B.TmpSignalConversionAteta_realIn[1];
    ctrl_student_HIL_B.output[2] = sqrt(ctrl_student_HIL_B.NoisePowHead /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise_m +
      ctrl_student_HIL_B.TmpSignalConversionAteta_realIn[2];
  } else {
    /* '<S72>:1:7' */
    ctrl_student_HIL_B.output[0] = ctrl_student_HIL_B.Hold[0];
    ctrl_student_HIL_B.output[1] = ctrl_student_HIL_B.Hold[1];
    ctrl_student_HIL_B.output[2] = ctrl_student_HIL_B.Hold[2];
  }

  /* End of MATLAB Function: '<S69>/MATLAB Function1' */

  /* Switch: '<S5>/Switch' */
  if (ctrl_student_HIL_B.NoiseEnable != 0.0) {
    ctrl_student_HIL_B.Switch[0] = ctrl_student_HIL_B.output[0];
    ctrl_student_HIL_B.Switch[1] = ctrl_student_HIL_B.output[1];
    ctrl_student_HIL_B.Switch[2] = ctrl_student_HIL_B.output[2];
  } else {
    ctrl_student_HIL_B.Switch[0] =
      ctrl_student_HIL_B.TmpSignalConversionAteta_realIn[0];
    ctrl_student_HIL_B.Switch[1] =
      ctrl_student_HIL_B.TmpSignalConversionAteta_realIn[1];
    ctrl_student_HIL_B.Switch[2] =
      ctrl_student_HIL_B.TmpSignalConversionAteta_realIn[2];
  }

  /* End of Switch: '<S5>/Switch' */

  /* Product: '<S2>/Product2' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  for (i = 0; i < 9; i++) {
    rtb_Product2_o[i] = ctrl_student_HIL_B.ControllerGainK2 *
      ctrl_student_HIL_P.K2[i];
  }

  /* End of Product: '<S2>/Product2' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Gain: '<S25>/Gain' incorporates:
     *  Constant: '<S25>/Kp '
     */
    for (i = 0; i < 9; i++) {
      ctrl_student_HIL_B.Gain[i] = ctrl_student_HIL_P.Gain_Gain_p *
        ctrl_student_HIL_P.K1[i];
    }

    /* End of Gain: '<S25>/Gain' */
  }

  /* MATLAB Function: '<S24>/Rotation Matrix' */
  ctrl_student_HIL_RotationMatrix(rtb_etaHat1,
    &ctrl_student_HIL_B.sf_RotationMatrix);

  /* MATLAB Function: '<S24>/R Transposed' */
  ctrl_student_HI_MATLABFunction1(ctrl_student_HIL_B.sf_RotationMatrix.R,
    &ctrl_student_HIL_B.sf_RTransposed);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S36>/Memory' */
    rtb_Memory = ctrl_student_HIL_DW.Memory_PreviousInput_f;

    /* MATLAB Function: '<S40>/MATLAB Function1' */
    ctrl_student__MATLABFunction1_m(rtb_Memory,
      &ctrl_student_HIL_B.sf_MATLABFunction1_m);
  }

  /* Integrator: '<S40>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_student_HIL_B.sf_MATLABFunction1_m.SwitchSignal_Out);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator_CSTATE = ctrl_student_HIL_P.Integrator_IC;
    }
  }

  ctrl_student_HIL_B.Integrator = ctrl_student_HIL_X.Integrator_CSTATE;

  /* MATLAB Function: '<S38>/CheckS&getU' */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Check_s/CheckS&getU': '<S41>:1' */
  if (ctrl_student_HIL_B.Integrator >= 1.0) {
    /* '<S41>:1:3' */
    /* '<S41>:1:4' */
    ctrl_student_HIL_B.s_out_j = 0.0;

    /* '<S41>:1:5' */
    ctrl_student_HIL_B.Switch_d = 0.0;
  } else {
    /* '<S41>:1:7' */
    ctrl_student_HIL_B.s_out_j = ctrl_student_HIL_B.Integrator;

    /* '<S41>:1:8' */
    ctrl_student_HIL_B.Switch_d = 1.0;
  }

  /* InitialCondition: '<S36>/IC' incorporates:
   *  Constant: '<S38>/Constant'
   *  MATLAB Function: '<S38>/CheckS&getU'
   */
  /* '<S41>:1:11' */
  /* U scaled again for the ellipsoidal case */
  if ((ctrl_student_HIL_DW.IC_FirstOutputTime == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC_FirstOutputTime == ctrl_student_HIL_M->Timing.t[0]))
  {
    ctrl_student_HIL_DW.IC_FirstOutputTime = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC = ctrl_student_HIL_P.IC_Value;
  } else {
    ctrl_student_HIL_B.IC = ctrl_student_HIL_P.U_ref / 2.0;
  }

  /* End of InitialCondition: '<S36>/IC' */

  /* MATLAB Function: '<S42>/MATLAB Function' incorporates:
   *  Constant: '<S39>/Elipscenter_radi'
   */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization /Subsystem/MATLAB Function': '<S43>:1' */
  /* '<S43>:1:2' */
  ctrl_student_HIL_B.pd[0] = 0.0;
  ctrl_student_HIL_B.pd[1] = 0.0;

  /* '<S43>:1:4' */
  /* '<S43>:1:5' */
  /* '<S43>:1:7' */
  ctrl_student_HIL_B.pd[0] = cos(6.2831853071795862 * ctrl_student_HIL_B.s_out_j)
    * ctrl_student_HIL_P.Elipscenter_radi[2] +
    ctrl_student_HIL_P.Elipscenter_radi[0];

  /* '<S43>:1:8' */
  ctrl_student_HIL_B.pd[1] = sin(6.2831853071795862 * ctrl_student_HIL_B.s_out_j)
    * ctrl_student_HIL_P.Elipscenter_radi[3] +
    ctrl_student_HIL_P.Elipscenter_radi[1];

  /* '<S43>:1:10' */
  rtb_pd_s_idx_0 = -6.2831853071795862 * ctrl_student_HIL_P.Elipscenter_radi[2] *
    sin(6.2831853071795862 * ctrl_student_HIL_B.s_out_j);

  /* '<S43>:1:11' */
  rtb_pd_s_idx_1 = 6.2831853071795862 * ctrl_student_HIL_P.Elipscenter_radi[3] *
    cos(6.2831853071795862 * ctrl_student_HIL_B.s_out_j);

  /* '<S43>:1:13' */
  /* '<S43>:1:14' */
  /* '<S43>:1:15' */
  deg2 = -39.478417604357432 * ctrl_student_HIL_P.Elipscenter_radi[2] * cos
    (6.2831853071795862 * ctrl_student_HIL_B.s_out_j);

  /* '<S43>:1:16' */
  rtb_reset = -39.478417604357432 * ctrl_student_HIL_P.Elipscenter_radi[3] * sin
    (6.2831853071795862 * ctrl_student_HIL_B.s_out_j);

  /* '<S43>:1:17' */
  /* '<S43>:1:18' */
  /* '<S43>:1:19' */
  rtb_eta_ds[2] = (rtb_pd_s_idx_0 * rtb_reset - deg2 * rtb_pd_s_idx_1) /
    (rtb_pd_s_idx_0 * rtb_pd_s_idx_0 + rtb_pd_s_idx_1 * rtb_pd_s_idx_1);

  /* '<S43>:1:20' */
  rtb_eta_dss_idx_0 = deg2;

  /* '<S43>:1:21' */
  rtb_eta_dss_idx_1 = rtb_reset;

  /* '<S43>:1:23' */
  /* '<S43>:1:24' */
  /* '<S43>:1:25' */
  /* '<S43>:1:26' */
  rtb_Switch5 = rtb_pd_s_idx_0 * rtb_pd_s_idx_0 + rtb_pd_s_idx_1 *
    rtb_pd_s_idx_1;

  /* '<S43>:1:27' */
  rtb_eta_dss_idx_2 = (-248.05021344239853 *
                       ctrl_student_HIL_P.Elipscenter_radi[3] * cos
                       (6.2831853071795862 * ctrl_student_HIL_B.s_out_j) *
                       rtb_pd_s_idx_0 - 248.05021344239853 *
                       ctrl_student_HIL_P.Elipscenter_radi[2] * sin
                       (6.2831853071795862 * ctrl_student_HIL_B.s_out_j) *
                       rtb_pd_s_idx_1) / (rtb_pd_s_idx_0 * rtb_pd_s_idx_0 +
    rtb_pd_s_idx_1 * rtb_pd_s_idx_1) + -((2.0 * rtb_pd_s_idx_0 * deg2 + 2.0 *
    rtb_pd_s_idx_1 * rtb_reset) * (rtb_pd_s_idx_0 * rtb_reset - rtb_pd_s_idx_1 *
    deg2)) / (rtb_Switch5 * rtb_Switch5);

  /* '<S43>:1:28' */
  rtb_U_ss = (-rtb_pd_s_idx_0 * deg2 - rtb_pd_s_idx_1 * rtb_reset) *
    ctrl_student_HIL_B.IC / rt_powd_snf(rtb_pd_s_idx_0 * rtb_pd_s_idx_0 +
    rtb_pd_s_idx_1 * rtb_pd_s_idx_1, 1.5);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S37>/Memory' */
    rtb_Memory_b = ctrl_student_HIL_DW.Memory_PreviousInput_m;

    /* MATLAB Function: '<S47>/MATLAB Function1' */
    ctrl_student__MATLABFunction1_m(rtb_Memory_b,
      &ctrl_student_HIL_B.sf_MATLABFunction1_p);
  }

  /* Integrator: '<S47>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_c,
                       ctrl_student_HIL_B.sf_MATLABFunction1_p.SwitchSignal_Out);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator_CSTATE_f =
        ctrl_student_HIL_P.Integrator_IC_p;
    }
  }

  ctrl_student_HIL_B.Integrator_m = ctrl_student_HIL_X.Integrator_CSTATE_f;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S49>/Memory2' */
    ctrl_student_HIL_B.Memory2 = ctrl_student_HIL_DW.Memory2_PreviousInput;

    /* Memory: '<S49>/Memory1' */
    ctrl_student_HIL_B.Memory1[0] = ctrl_student_HIL_DW.Memory1_PreviousInput[0];
    ctrl_student_HIL_B.Memory1[1] = ctrl_student_HIL_DW.Memory1_PreviousInput[1];
  }

  /* MATLAB Function: '<S49>/MATLAB Function' incorporates:
   *  Constant: '<S46>/Desired Position'
   *  Constant: '<S49>/Constant'
   *  Constant: '<S49>/Constant1'
   */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function': '<S52>:1' */
  /* '<S52>:1:3' */
  /* '<S52>:1:5' */
  ctrl_student_HIL_B.init_time[0] = ctrl_student_HIL_B.Memory1[0] + 1.0;

  /* '<S52>:1:6' */
  ctrl_student_HIL_B.init_time[1] = ctrl_student_HIL_B.Memory1[1];
  if (ctrl_student_HIL_B.Memory1[0] + 1.0 < ctrl_student_HIL_P.T_initialDP) {
    /* '<S52>:1:11' */
    /*  DP for N_iterations */
    /* '<S52>:1:12' */
    deg2 = ctrl_student_HIL_B.Memory2;

    /* '<S52>:1:13' */
    i = (int32_T)ctrl_student_HIL_B.Memory2;
    rtb_InitPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
    rtb_InitPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

    /* '<S52>:1:14' */
    i = (int32_T)(ctrl_student_HIL_B.Memory2 + 1.0);
    rtb_DesPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
    rtb_DesPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

    /* '<S52>:1:15' */
    ctrl_student_HIL_B.SwitchSignal_out = 1.0;

    /* '<S52>:1:16' */
    rtb_reset = 0.0;

    /* '<S52>:1:17' */
    i = 1;

    /* '<S52>:1:18' */
    ctrl_student_HIL_B.flag = 1.0;
  } else if (ctrl_student_HIL_B.Memory2 == 1.0) {
    /* '<S52>:1:21' */
    /*  if we are at final stretch */
    if (ctrl_student_HIL_B.Integrator_m >= 0.9999) {
      /* '<S52>:1:22' */
      /* '<S52>:1:23' */
      deg2 = ctrl_student_HIL_B.Memory2;

      /* '<S52>:1:24' */
      i = (int32_T)ctrl_student_HIL_B.Memory2;
      rtb_InitPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
      rtb_InitPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

      /* '<S52>:1:25' */
      i = (int32_T)(ctrl_student_HIL_B.Memory2 + 1.0);
      rtb_DesPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
      rtb_DesPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

      /* '<S52>:1:26' */
      ctrl_student_HIL_B.SwitchSignal_out = 1.0;

      /* '<S52>:1:27' */
      rtb_reset = 1.0;

      /* '<S52>:1:28' */
      i = 1;

      /* '<S52>:1:29' */
      ctrl_student_HIL_B.flag = 2.0;
    } else {
      /* '<S52>:1:32' */
      deg2 = ctrl_student_HIL_B.Memory2;

      /* '<S52>:1:33' */
      i = (int32_T)ctrl_student_HIL_B.Memory2;
      rtb_InitPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
      rtb_InitPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

      /* '<S52>:1:34' */
      i = (int32_T)(ctrl_student_HIL_B.Memory2 + 1.0);
      rtb_DesPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
      rtb_DesPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

      /* '<S52>:1:35' */
      ctrl_student_HIL_B.SwitchSignal_out = 1.0;

      /* '<S52>:1:36' */
      rtb_reset = ctrl_student_HIL_B.Integrator_m;

      /* '<S52>:1:37' */
      i = 0;

      /* '<S52>:1:38' */
      ctrl_student_HIL_B.flag = 3.0;
    }
  } else if (ctrl_student_HIL_B.Integrator_m >= 0.9999) {
    /* '<S52>:1:42' */
    if (ctrl_student_HIL_B.Memory2 + 1.0 == 1.0) {
      /* '<S52>:1:43' */
      /* '<S52>:1:44' */
      ctrl_student_HIL_B.SwitchSignal_out = 0.0;

      /* '<S52>:1:45' */
      ctrl_student_HIL_B.flag = 40.0;
    } else {
      /* '<S52>:1:47' */
      ctrl_student_HIL_B.SwitchSignal_out = 0.0;

      /* '<S52>:1:48' */
      ctrl_student_HIL_B.flag = 50.0;
    }

    /* '<S52>:1:50' */
    deg2 = ctrl_student_HIL_B.Memory2 + 1.0;

    /* '<S52>:1:51' */
    i = (int32_T)(ctrl_student_HIL_B.Memory2 + 1.0);
    rtb_InitPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
    rtb_InitPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

    /* '<S52>:1:52' */
    i = (int32_T)((ctrl_student_HIL_B.Memory2 + 1.0) + 1.0);
    rtb_DesPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
    rtb_DesPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

    /* '<S52>:1:53' */
    rtb_reset = 0.0;

    /* '<S52>:1:54' */
    i = 0;
  } else {
    if (ctrl_student_HIL_B.Memory1[1] == 0.0) {
      /* '<S52>:1:57' */
      /* '<S52>:1:58' */
      ctrl_student_HIL_B.init_time[1] = 1.0;

      /* '<S52>:1:59' */
      ctrl_student_HIL_B.SwitchSignal_out = 0.0;

      /* '<S52>:1:60' */
      ctrl_student_HIL_B.flag = 5.75;
    } else {
      /* '<S52>:1:62' */
      ctrl_student_HIL_B.SwitchSignal_out = 1.0;

      /* '<S52>:1:63' */
      ctrl_student_HIL_B.flag = 5.25;
    }

    /* '<S52>:1:65' */
    deg2 = ctrl_student_HIL_B.Memory2;

    /* '<S52>:1:66' */
    i = (int32_T)ctrl_student_HIL_B.Memory2;
    rtb_InitPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
    rtb_InitPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

    /* '<S52>:1:67' */
    i = (int32_T)(ctrl_student_HIL_B.Memory2 + 1.0);
    rtb_DesPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
    rtb_DesPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

    /* '<S52>:1:68' */
    rtb_reset = ctrl_student_HIL_B.Integrator_m;

    /* '<S52>:1:69' */
    i = 0;
  }

  if (i == 1) {
    /* '<S52>:1:75' */
    /* '<S52>:1:76' */
    ctrl_student_HIL_B.U = 0.0;
  } else {
    /* '<S52>:1:78' */
    ctrl_student_HIL_B.U = (sin(6.2831853071795862 * rtb_reset -
      1.5707963267948966) + 1.01) * ctrl_student_HIL_P.U_ref;
  }

  ctrl_student_HIL_B.N_out = deg2;
  ctrl_student_HIL_B.s_out = rtb_reset;

  /* End of MATLAB Function: '<S49>/MATLAB Function' */

  /* Sum: '<S46>/Sum1' */
  rtb_DesPosOut_idx_0 -= rtb_InitPosOut_idx_0;
  rtb_Switch5 = rtb_DesPosOut_idx_1 - rtb_InitPosOut_idx_1;

  /* Sum: '<S46>/Sum' incorporates:
   *  Product: '<S46>/Product'
   */
  ctrl_student_HIL_B.Sum_a[0] = rtb_DesPosOut_idx_0 * ctrl_student_HIL_B.s_out +
    rtb_InitPosOut_idx_0;
  ctrl_student_HIL_B.Sum_a[1] = rtb_Switch5 * ctrl_student_HIL_B.s_out +
    rtb_InitPosOut_idx_1;

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/SwitchSignalFromFile'
   */
  if (ctrl_student_HIL_P.DesiredPath > ctrl_student_HIL_P.Switch_Threshold) {
    ctrl_student_HIL_B.Switch_j[0] = ctrl_student_HIL_B.pd[0];
    ctrl_student_HIL_B.Switch_j[1] = ctrl_student_HIL_B.pd[1];
  } else {
    ctrl_student_HIL_B.Switch_j[0] = ctrl_student_HIL_B.Sum_a[0];
    ctrl_student_HIL_B.Switch_j[1] = ctrl_student_HIL_B.Sum_a[1];
  }

  /* End of Switch: '<S19>/Switch' */

  /* Sum: '<S24>/Sum' incorporates:
   *  Product: '<S24>/Product'
   */
  rtb_DesPosOut_idx_1 = ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp[0] -
    ctrl_student_HIL_B.Switch_j[0];
  rtb_InitPosOut_idx_0 = ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp[1] -
    ctrl_student_HIL_B.Switch_j[1];
  rtb_InitPosOut_idx_1 = ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp[2] -
    rtb_etaHat1;

  /* Product: '<S24>/Product' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Product[i] = 0.0;
    ctrl_student_HIL_B.Product[i] += ctrl_student_HIL_B.sf_RTransposed.R_T[i] *
      rtb_DesPosOut_idx_1;
    ctrl_student_HIL_B.Product[i] += ctrl_student_HIL_B.sf_RTransposed.R_T[i + 3]
      * rtb_InitPosOut_idx_0;
    ctrl_student_HIL_B.Product[i] += ctrl_student_HIL_B.sf_RTransposed.R_T[i + 6]
      * rtb_InitPosOut_idx_1;
  }

  /* Switch: '<S19>/Switch3' incorporates:
   *  Constant: '<S19>/SwitchSignalFromFile'
   *  Constant: '<S48>/Constant'
   *  Constant: '<S48>/Constant1'
   *  MATLAB Function: '<S42>/MATLAB Function'
   *  MATLAB Function: '<S48>/MATLAB Function'
   */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Eta_ds/MATLAB Function': '<S50>:1' */
  /* '<S50>:1:3' */
  if (ctrl_student_HIL_P.DesiredPath > ctrl_student_HIL_P.Switch3_Threshold_e) {
    rtb_Switch3_idx_0 = rtb_pd_s_idx_0;
    rtb_Switch3_idx_1 = rtb_pd_s_idx_1;
    rtb_Switch3_idx_2 = rtb_eta_ds[2];
  } else {
    rtb_Switch3_idx_0 = rtb_DesPosOut_idx_0;
    rtb_Switch3_idx_1 = rtb_Switch5;
    rtb_Switch3_idx_2 = (rtb_DesPosOut_idx_0 *
                         ctrl_student_HIL_P.Constant1_Value_g - rtb_Switch5 *
                         ctrl_student_HIL_P.Constant_Value_k) / (rtb_Switch5 *
      rtb_Switch5 + rtb_DesPosOut_idx_0 * rtb_DesPosOut_idx_0);
  }

  /* End of Switch: '<S19>/Switch3' */

  /* MATLAB Function: '<S23>/Rotation Matrix' */
  /* MATLAB Function 'ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function': '<S26>:1' */
  /* '<S26>:1:3' */
  ctrl_student_HIL_RotationMatrix(rtb_etaHat1,
    &ctrl_student_HIL_B.sf_RotationMatrix_j);

  /* MATLAB Function: '<S23>/MATLAB Function1' */
  ctrl_student_HI_MATLABFunction1(ctrl_student_HIL_B.sf_RotationMatrix_j.R,
    &ctrl_student_HIL_B.sf_MATLABFunction1_pa);

  /* Product: '<S23>/Product' incorporates:
   *  MATLAB Function: '<S23>/MATLAB Function'
   *  Product: '<S23>/Product1'
   */
  for (i = 0; i < 3; i++) {
    tmp_1[i] = ctrl_student_HIL_B.sf_MATLABFunction1_pa.R_T[3 * i + 2] *
      ctrl_student_HIL_B.Product[2] +
      (ctrl_student_HIL_B.sf_MATLABFunction1_pa.R_T[3 * i + 1] *
       ctrl_student_HIL_B.Product[1] +
       ctrl_student_HIL_B.sf_MATLABFunction1_pa.R_T[3 * i] *
       ctrl_student_HIL_B.Product[0]);
  }

  /* End of Product: '<S23>/Product' */

  /* Gain: '<S23>/Gain' incorporates:
   *  Product: '<S23>/Product1'
   */
  rtb_reset = ((tmp_1[0] * rtb_Switch3_idx_0 + tmp_1[1] * rtb_Switch3_idx_1) +
               tmp_1[2] * rtb_Switch3_idx_2) * ctrl_student_HIL_P.Gain_Gain_a;

  /* MATLAB Function: '<S40>/UpdateLaw' incorporates:
   *  Constant: '<S40>/TASK'
   *  Constant: '<S40>/mu '
   *  MATLAB Function: '<S42>/MATLAB Function'
   */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/UpdateLaw': '<S45>:1' */
  /* '<S45>:1:4' */
  rtb_safety_sig_4 = ctrl_student_HIL_B.IC / sqrt(rtb_pd_s_idx_0 *
    rtb_pd_s_idx_0 + rtb_pd_s_idx_1 * rtb_pd_s_idx_1);
  if (ctrl_student_HIL_P.LAW == 1.0) {
    /* '<S45>:1:5' */
    /* '<S45>:1:7' */
    ctrl_student_HIL_B.s_dot_l = rtb_safety_sig_4 - ctrl_student_HIL_P.mu *
      rtb_reset;
  } else {
    /* '<S45>:1:9' */
    ctrl_student_HIL_B.s_dot_l = rtb_safety_sig_4 - ctrl_student_HIL_P.mu / sqrt
      (rtb_pd_s_idx_0 * rtb_pd_s_idx_0 + rtb_pd_s_idx_1 * rtb_pd_s_idx_1) *
      rtb_reset;
  }

  /* InitialCondition: '<S37>/IC' */
  if ((ctrl_student_HIL_DW.IC_FirstOutputTime_p == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC_FirstOutputTime_p == ctrl_student_HIL_M->Timing.t
       [0])) {
    ctrl_student_HIL_DW.IC_FirstOutputTime_p = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC_n = ctrl_student_HIL_P.IC_Value_e;
  } else {
    ctrl_student_HIL_B.IC_n = ctrl_student_HIL_B.U;
  }

  /* End of InitialCondition: '<S37>/IC' */

  /* MATLAB Function: '<S47>/UpdateLaw' incorporates:
   *  Constant: '<S47>/TASK'
   *  Constant: '<S47>/mu '
   *  SignalConversion: '<S55>/TmpSignal ConversionAt SFunction Inport5'
   */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/UpdateLaw': '<S55>:1' */
  /* '<S55>:1:4' */
  deg2 = ctrl_student_HIL_B.IC_n / sqrt(rtb_DesPosOut_idx_0 *
    rtb_DesPosOut_idx_0 + rtb_Switch5 * rtb_Switch5);
  if (ctrl_student_HIL_P.LAW == 1.0) {
    /* '<S55>:1:5' */
    /* '<S55>:1:7' */
    ctrl_student_HIL_B.s_dot = deg2 - ctrl_student_HIL_P.mu * rtb_reset;
  } else {
    /* '<S55>:1:9' */
    ctrl_student_HIL_B.s_dot = deg2 - ctrl_student_HIL_P.mu / sqrt
      (rtb_DesPosOut_idx_0 * rtb_DesPosOut_idx_0 + rtb_Switch5 * rtb_Switch5) *
      rtb_reset;
  }

  ctrl_student_HIL_B.U_s = deg2;

  /* End of MATLAB Function: '<S47>/UpdateLaw' */

  /* Switch: '<S19>/Switch4' incorporates:
   *  Constant: '<S19>/SwitchSignalFromFile'
   *  MATLAB Function: '<S40>/UpdateLaw'
   */
  if (ctrl_student_HIL_P.DesiredPath > ctrl_student_HIL_P.Switch4_Threshold) {
    rtb_reset = rtb_safety_sig_4;
  } else {
    rtb_reset = ctrl_student_HIL_B.U_s;
  }

  /* End of Switch: '<S19>/Switch4' */

  /* Integrator: '<S58>/nuHat' */
  ctrl_student_HIL_B.nuHat[0] = ctrl_student_HIL_X.nuHat_CSTATE[0];
  ctrl_student_HIL_B.nuHat[1] = ctrl_student_HIL_X.nuHat_CSTATE[1];
  ctrl_student_HIL_B.nuHat[2] = ctrl_student_HIL_X.nuHat_CSTATE[2];

  /* Product: '<S25>/Product' incorporates:
   *  Sum: '<S25>/Sum'
   */
  for (i = 0; i < 3; i++) {
    tmp_1[i] = ctrl_student_HIL_B.Gain[i + 6] * ctrl_student_HIL_B.Product[2] +
      (ctrl_student_HIL_B.Gain[i + 3] * ctrl_student_HIL_B.Product[1] +
       ctrl_student_HIL_B.Gain[i] * ctrl_student_HIL_B.Product[0]);
  }

  /* End of Product: '<S25>/Product' */

  /* Product: '<S25>/Product2' incorporates:
   *  Product: '<S25>/Product1'
   *  Sum: '<S25>/Sum'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product_j[i] = ctrl_student_HIL_B.sf_RTransposed.R_T[i + 6] *
      (rtb_Switch3_idx_2 * rtb_reset) + (ctrl_student_HIL_B.sf_RTransposed.R_T[i
      + 3] * (rtb_Switch3_idx_1 * rtb_reset) + rtb_Switch3_idx_0 * rtb_reset *
      ctrl_student_HIL_B.sf_RTransposed.R_T[i]);
  }

  /* End of Product: '<S25>/Product2' */

  /* Sum: '<S22>/Sum' incorporates:
   *  Sum: '<S25>/Sum'
   */
  ctrl_student_HIL_B.Sum_g[0] = ctrl_student_HIL_B.nuHat[0] - (tmp_1[0] +
    rtb_Product_j[0]);
  ctrl_student_HIL_B.Sum_g[1] = ctrl_student_HIL_B.nuHat[1] - (tmp_1[1] +
    rtb_Product_j[1]);
  ctrl_student_HIL_B.Sum_g[2] = ctrl_student_HIL_B.nuHat[2] - (tmp_1[2] +
    rtb_Product_j[2]);

  /* Product: '<S31>/K*z_2' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Kz_2[i] = 0.0;
    ctrl_student_HIL_B.Kz_2[i] += rtb_Product2_o[i] * ctrl_student_HIL_B.Sum_g[0];
    ctrl_student_HIL_B.Kz_2[i] += rtb_Product2_o[i + 3] *
      ctrl_student_HIL_B.Sum_g[1];
    ctrl_student_HIL_B.Kz_2[i] += rtb_Product2_o[i + 6] *
      ctrl_student_HIL_B.Sum_g[2];
  }

  /* End of Product: '<S31>/K*z_2' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* MATLAB Function: '<S31>/MATLAB Function1' incorporates:
     *  Constant: '<S31>/Constant'
     */
    /* MATLAB Function 'ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1': '<S33>:1' */
    /* % MATRICES */
    /* '<S33>:1:4' */
    /*  x_g  =  0.0460; % Table B.1 */
    /* % Added mass */
    /* '<S33>:1:8' */
    /*  Table B.1 */
    /* '<S33>:1:9' */
    /*  Table B.1 guestimate */
    /* '<S33>:1:10' */
    /*  Table B.1 */
    /* % Total mass matrix */
    /* '<S33>:1:13' */
    /* '<S33>:1:14' */
    /* '<S33>:1:15' */
    /* '<S33>:1:16' */
    /* '<S33>:1:17' */
    /* '<S33>:1:19' */
    ctrl_student_HIL_B.M[0] = ctrl_student_HIL_P.m - -2.0;
    ctrl_student_HIL_B.M[3] = 0.0;
    ctrl_student_HIL_B.M[6] = 0.0;
    ctrl_student_HIL_B.M[1] = 0.0;
    ctrl_student_HIL_B.M[4] = ctrl_student_HIL_P.m - -1.0;
    ctrl_student_HIL_B.M[7] = ctrl_student_HIL_P.m * 0.0375;
    ctrl_student_HIL_B.M[2] = 0.0;
    ctrl_student_HIL_B.M[5] = ctrl_student_HIL_P.m * 0.0375;
    ctrl_student_HIL_B.M[8] = 2.76;
  }

  /* Product: '<S2>/Product1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  for (i = 0; i < 9; i++) {
    rtb_Product2_o[i] = ctrl_student_HIL_B.ControllerGainK1 *
      ctrl_student_HIL_P.K1[i];
  }

  /* End of Product: '<S2>/Product1' */

  /* Switch: '<S19>/Switch5' incorporates:
   *  Constant: '<S19>/SwitchSignalFromFile'
   */
  if (ctrl_student_HIL_P.DesiredPath > ctrl_student_HIL_P.Switch5_Threshold) {
    rtb_Switch5 = ctrl_student_HIL_B.s_dot_l;
  } else {
    rtb_Switch5 = ctrl_student_HIL_B.s_dot;
  }

  /* End of Switch: '<S19>/Switch5' */

  /* Switch: '<S19>/Switch7' incorporates:
   *  Constant: '<S19>/SwitchSignalFromFile'
   *  Constant: '<S46>/Constant3'
   */
  if (ctrl_student_HIL_P.DesiredPath > ctrl_student_HIL_P.Switch7_Threshold) {
    deg2 = rtb_U_ss;
  } else {
    deg2 = ctrl_student_HIL_P.Constant3_Value;
  }

  /* End of Switch: '<S19>/Switch7' */

  /* MATLAB Function: '<S34>/MATLAB Function' */
  /* MATLAB Function 'ControllerAndParanetrization/Controller1/Controller/Controller/alpha_1dott/MATLAB Function': '<S35>:1' */
  /* % term 1 */
  /* '<S35>:1:3' */
  S_T[0] = 0.0;
  S_T[3] = ctrl_student_HIL_B.nuHat[2];
  S_T[6] = 0.0;
  S_T[1] = -ctrl_student_HIL_B.nuHat[2];
  S_T[4] = 0.0;
  S_T[7] = 0.0;
  S_T[2] = 0.0;
  S_T[5] = 0.0;
  S_T[8] = 0.0;

  /* '<S35>:1:5' */
  /* % term 2 */
  /* '<S35>:1:8' */
  /* % term 3 */
  /* '<S35>:1:11' */
  /* % term 4 */
  /* '<S35>:1:14' */
  /* % term 5  */
  /* '<S35>:1:17' */
  /* % summary */
  /* '<S35>:1:20' */
  for (i = 0; i < 3; i++) {
    for (p2 = 0; p2 < 3; p2++) {
      rtb_M[i + 3 * p2] = 0.0;
      rtb_M[i + 3 * p2] += ctrl_student_HIL_B.sf_RTransposed.R_T[3 * p2] * S_T[i];
      rtb_M[i + 3 * p2] += ctrl_student_HIL_B.sf_RTransposed.R_T[3 * p2 + 1] *
        S_T[i + 3];
      rtb_M[i + 3 * p2] += ctrl_student_HIL_B.sf_RTransposed.R_T[3 * p2 + 2] *
        0.0;
    }
  }

  for (i = 0; i < 3; i++) {
    S_T_0[i] = rtb_M[i + 6] * rtb_Switch3_idx_2 + (rtb_M[i + 3] *
      rtb_Switch3_idx_1 + rtb_M[i] * rtb_Switch3_idx_0);
  }

  for (i = 0; i < 3; i++) {
    rtb_M[3 * i] = -S_T[3 * i];
    rtb_M[1 + 3 * i] = -S_T[3 * i + 1];
    rtb_M[2 + 3 * i] = -S_T[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    S_T_1[i] = ((rtb_M[i + 3] * ctrl_student_HIL_B.Product[1] + rtb_M[i] *
                 ctrl_student_HIL_B.Product[0]) + rtb_M[i + 6] *
                ctrl_student_HIL_B.Product[2]) - ctrl_student_HIL_B.nuHat[i];
  }

  for (i = 0; i < 3; i++) {
    for (p2 = 0; p2 < 3; p2++) {
      rtb_M[i + 3 * p2] = 0.0;
      rtb_M[i + 3 * p2] += ctrl_student_HIL_B.sf_RTransposed.R_T[3 * p2] *
        rtb_Product2_o[i];
      rtb_M[i + 3 * p2] += ctrl_student_HIL_B.sf_RTransposed.R_T[3 * p2 + 1] *
        rtb_Product2_o[i + 3];
      rtb_M[i + 3 * p2] += ctrl_student_HIL_B.sf_RTransposed.R_T[3 * p2 + 2] *
        rtb_Product2_o[i + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    rtb_Product2_i[i] = rtb_M[i + 6] * rtb_Switch3_idx_2 + (rtb_M[i + 3] *
      rtb_Switch3_idx_1 + rtb_M[i] * rtb_Switch3_idx_0);
  }

  /* Switch: '<S19>/Switch6' incorporates:
   *  Constant: '<S19>/SwitchSignalFromFile'
   *  Constant: '<S46>/Constant'
   *  Constant: '<S46>/Constant1'
   *  Constant: '<S46>/Constant2'
   */
  if (!(ctrl_student_HIL_P.DesiredPath > ctrl_student_HIL_P.Switch6_Threshold))
  {
    rtb_eta_dss_idx_0 = ctrl_student_HIL_P.Constant_Value_o;
    rtb_eta_dss_idx_1 = ctrl_student_HIL_P.Constant1_Value_l;
    rtb_eta_dss_idx_2 = ctrl_student_HIL_P.Constant2_Value;
  }

  /* End of Switch: '<S19>/Switch6' */

  /* MATLAB Function: '<S34>/MATLAB Function' incorporates:
   *  Product: '<S31>/M*alpha_dott'
   */
  for (i = 0; i < 3; i++) {
    tmp_1[i] = ctrl_student_HIL_B.sf_RTransposed.R_T[i + 6] * rtb_eta_dss_idx_2
      + (ctrl_student_HIL_B.sf_RTransposed.R_T[i + 3] * rtb_eta_dss_idx_1 +
         ctrl_student_HIL_B.sf_RTransposed.R_T[i] * rtb_eta_dss_idx_0);
  }

  for (i = 0; i < 3; i++) {
    rtb_Product_j[i] = ctrl_student_HIL_B.sf_RTransposed.R_T[i + 6] *
      rtb_Switch3_idx_2 + (ctrl_student_HIL_B.sf_RTransposed.R_T[i + 3] *
      rtb_Switch3_idx_1 + ctrl_student_HIL_B.sf_RTransposed.R_T[i] *
      rtb_Switch3_idx_0);
  }

  for (i = 0; i < 3; i++) {
    S_T_2[i] = (((((rtb_Product2_o[i + 3] * S_T_1[1] + rtb_Product2_o[i] *
                    S_T_1[0]) + rtb_Product2_o[i + 6] * S_T_1[2]) + S_T_0[i] *
                  rtb_reset) + rtb_Product2_i[i] * rtb_Switch5) + tmp_1[i] *
                rtb_Switch5 * rtb_reset) + rtb_Product_j[i] * deg2 * rtb_Switch5;
  }

  /* Product: '<S31>/M*alpha_dott' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Malpha_dott[i] = 0.0;
    ctrl_student_HIL_B.Malpha_dott[i] += ctrl_student_HIL_B.M[i] * S_T_2[0];
    ctrl_student_HIL_B.Malpha_dott[i] += ctrl_student_HIL_B.M[i + 3] * S_T_2[1];
    ctrl_student_HIL_B.Malpha_dott[i] += ctrl_student_HIL_B.M[i + 6] * S_T_2[2];
  }

  /* MATLAB Function: '<S31>/MATLAB Function' */
  /* MATLAB Function 'ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function': '<S32>:1' */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S32>:1:4' */
  /* '<S32>:1:8' */
  /*  Y_r */
  /*  Y_rr */
  /*  Y_rv, Y_vr */
  /* '<S32>:1:14' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /* '<S32>:1:18' */
  /* '<S32>:1:19' */
  /* '<S32>:1:20' */
  /*  using abs(r) */
  /* '<S32>:1:23' */
  /* '<S32>:1:24' */
  /* '<S32>:1:26' */
  tmp_2[0] = (0.6555 - 0.3545 * ctrl_student_HIL_B.nuHat[0]) -
    ctrl_student_HIL_B.nuHat[0] * ctrl_student_HIL_B.nuHat[0] * -3.787;
  tmp_2[3] = 0.0;
  tmp_2[6] = 0.0;
  tmp_2[1] = 0.0;
  tmp_2[4] = ((1.33 - -2.776 * ctrl_student_HIL_B.nuHat[1]) -
              ctrl_student_HIL_B.nuHat[1] * ctrl_student_HIL_B.nuHat[1] * -64.91)
    - -0.805 * fabs(ctrl_student_HIL_B.nuHat[2]);
  tmp_2[7] = ((7.25 - -3.45 * fabs(ctrl_student_HIL_B.nuHat[2])) -
              ctrl_student_HIL_B.nuHat[2] * ctrl_student_HIL_B.nuHat[2] * 0.0) -
    -0.845 * fabs(ctrl_student_HIL_B.nuHat[1]);
  tmp_2[2] = 0.0;
  tmp_2[5] = ((-0.0 - -0.2088 * ctrl_student_HIL_B.nuHat[1]) -
              ctrl_student_HIL_B.nuHat[1] * ctrl_student_HIL_B.nuHat[1] * 0.0) -
    0.13 * fabs(ctrl_student_HIL_B.nuHat[2]);
  tmp_2[8] = ((1.9 - -0.75 * fabs(ctrl_student_HIL_B.nuHat[2])) -
              ctrl_student_HIL_B.nuHat[2] * ctrl_student_HIL_B.nuHat[2] * 0.0) -
    0.08 * fabs(ctrl_student_HIL_B.nuHat[1]);

  /* Product: '<S31>/K*z_1' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Kz_1[i] = 0.0;
    ctrl_student_HIL_B.Kz_1[i] += tmp_2[i] * ctrl_student_HIL_B.nuHat[0];
    ctrl_student_HIL_B.Kz_1[i] += tmp_2[i + 3] * ctrl_student_HIL_B.nuHat[1];
    ctrl_student_HIL_B.Kz_1[i] += tmp_2[i + 6] * ctrl_student_HIL_B.nuHat[2];
  }

  /* End of Product: '<S31>/K*z_1' */

  /* Sum: '<S31>/Sum2' incorporates:
   *  Sum: '<S31>/Sum'
   *  Sum: '<S31>/Sum1'
   */
  ctrl_student_HIL_B.Sum2[0] = ((ctrl_student_HIL_B.Malpha_dott[0] -
    ctrl_student_HIL_B.Product[0]) - ctrl_student_HIL_B.Kz_2[0]) +
    ctrl_student_HIL_B.Kz_1[0];
  ctrl_student_HIL_B.Sum2[1] = ((ctrl_student_HIL_B.Malpha_dott[1] -
    ctrl_student_HIL_B.Product[1]) - ctrl_student_HIL_B.Kz_2[1]) +
    ctrl_student_HIL_B.Kz_1[1];
  ctrl_student_HIL_B.Sum2[2] = ((ctrl_student_HIL_B.Malpha_dott[2] -
    ctrl_student_HIL_B.Product[2]) - ctrl_student_HIL_B.Kz_2[2]) +
    ctrl_student_HIL_B.Kz_1[2];

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant1'
   */
  if (ctrl_student_HIL_P.Constant1_Value_d >
      ctrl_student_HIL_P.Switch2_Threshold) {
    ctrl_student_HIL_B.Switch2[0] = ctrl_student_HIL_B.Sum2[0];
    ctrl_student_HIL_B.Switch2[1] = ctrl_student_HIL_B.Sum2[1];
    ctrl_student_HIL_B.Switch2[2] = ctrl_student_HIL_B.Sum2[2];
  } else {
    ctrl_student_HIL_B.Switch2[0] = ctrl_student_HIL_P.Constant_Value_dg[0];
    ctrl_student_HIL_B.Switch2[1] = ctrl_student_HIL_P.Constant_Value_dg[1];
    ctrl_student_HIL_B.Switch2[2] = ctrl_student_HIL_P.Constant_Value_dg[2];
  }

  /* End of Switch: '<S21>/Switch2' */

  /* DeadZone: '<S13>/Dead Zone' */
  if (ctrl_student_HIL_B.PosXRight > ctrl_student_HIL_P.DeadZone_End) {
    rtb_reset = ctrl_student_HIL_B.PosXRight - ctrl_student_HIL_P.DeadZone_End;
  } else if (ctrl_student_HIL_B.PosXRight >= ctrl_student_HIL_P.DeadZone_Start)
  {
    rtb_reset = 0.0;
  } else {
    rtb_reset = ctrl_student_HIL_B.PosXRight - ctrl_student_HIL_P.DeadZone_Start;
  }

  /* End of DeadZone: '<S13>/Dead Zone' */

  /* Gain: '<S13>/Gain' incorporates:
   *  Sum: '<S13>/Sum'
   */
  deg2 = (ctrl_student_HIL_B.L2_continuous - ctrl_student_HIL_B.R2_continuous) *
    ctrl_student_HIL_P.Gain_Gain_ps;

  /* DeadZone: '<S13>/Dead Zone2' */
  if (deg2 > ctrl_student_HIL_P.DeadZone2_End) {
    deg2 -= ctrl_student_HIL_P.DeadZone2_End;
  } else if (deg2 >= ctrl_student_HIL_P.DeadZone2_Start) {
    deg2 = 0.0;
  } else {
    deg2 -= ctrl_student_HIL_P.DeadZone2_Start;
  }

  /* End of DeadZone: '<S13>/Dead Zone2' */

  /* MATLAB Function: '<S13>/Contoller_Map1' incorporates:
   *  Constant: '<S13>/Max_Global_Forces'
   */
  /* MATLAB Function 'joystick/Contoller_Map1': '<S82>:1' */
  if (ctrl_student_HIL_B.Select == 2.0) {
    /* '<S82>:1:3' */
    /* '<S82>:1:4' */
    ctrl_student_HIL_B.tau_surge = rtb_reset *
      ctrl_student_HIL_P.Max_Global_Forces_Value[0];

    /* '<S82>:1:5' */
    ctrl_student_HIL_B.tau_sway = 0.0;

    /* '<S82>:1:6' */
    ctrl_student_HIL_B.tau_yaw = deg2 *
      ctrl_student_HIL_P.Max_Global_Forces_Value[3];
  } else {
    /* '<S82>:1:8' */
    ctrl_student_HIL_B.tau_surge = rtb_reset *
      ctrl_student_HIL_P.Max_Global_Forces_Value[0];

    /* DeadZone: '<S13>/Dead Zone1' incorporates:
     *  Constant: '<S13>/Max_Global_Forces'
     */
    /* '<S82>:1:9' */
    if (ctrl_student_HIL_B.PosYRight > ctrl_student_HIL_P.DeadZone1_End) {
      rtb_DesPosOut_idx_1 = ctrl_student_HIL_B.PosYRight -
        ctrl_student_HIL_P.DeadZone1_End;
    } else if (ctrl_student_HIL_B.PosYRight >=
               ctrl_student_HIL_P.DeadZone1_Start) {
      rtb_DesPosOut_idx_1 = 0.0;
    } else {
      rtb_DesPosOut_idx_1 = ctrl_student_HIL_B.PosYRight -
        ctrl_student_HIL_P.DeadZone1_Start;
    }

    /* End of DeadZone: '<S13>/Dead Zone1' */
    ctrl_student_HIL_B.tau_sway = rtb_DesPosOut_idx_1 *
      ctrl_student_HIL_P.Max_Global_Forces_Value[1];

    /* '<S82>:1:10' */
    ctrl_student_HIL_B.tau_yaw = deg2 *
      ctrl_student_HIL_P.Max_Global_Forces_Value[2];
  }

  /* End of MATLAB Function: '<S13>/Contoller_Map1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Switch: '<Root>/Switch2' incorporates:
   *  Sum: '<Root>/Sum'
   */
  if (ctrl_student_HIL_B.JoysticControllerSwitch >
      ctrl_student_HIL_P.Switch2_Threshold_i) {
    ctrl_student_HIL_B.Switch2_g[0] = ctrl_student_HIL_B.Switch2[0] +
      ctrl_student_HIL_B.tau_surge;
    ctrl_student_HIL_B.Switch2_g[1] = ctrl_student_HIL_B.Switch2[1] +
      ctrl_student_HIL_B.tau_sway;
    ctrl_student_HIL_B.Switch2_g[2] = ctrl_student_HIL_B.Switch2[2] +
      ctrl_student_HIL_B.tau_yaw;
  } else {
    ctrl_student_HIL_B.Switch2_g[0] = ctrl_student_HIL_B.tau_surge;
    ctrl_student_HIL_B.Switch2_g[1] = ctrl_student_HIL_B.tau_sway;
    ctrl_student_HIL_B.Switch2_g[2] = ctrl_student_HIL_B.tau_yaw;
  }

  /* End of Switch: '<Root>/Switch2' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S10>/Memory' */
    ctrl_student_HIL_B.Memory_m[0] = ctrl_student_HIL_DW.Memory_PreviousInput_d
      [0];
    ctrl_student_HIL_B.Memory_m[1] = ctrl_student_HIL_DW.Memory_PreviousInput_d
      [1];
    ctrl_student_HIL_B.Memory_m[2] = ctrl_student_HIL_DW.Memory_PreviousInput_d
      [2];
  }

  /* MATLAB Function: '<S10>/dropOutDetect' incorporates:
   *  SignalConversion: '<S81>/TmpSignal ConversionAt SFunction Inport3'
   */
  /* MATLAB Function 'dropoutdet/dropOutDetect': '<S81>:1' */
  /* '<S81>:1:3' */
  /* '<S81>:1:4' */
  ctrl_student_HIL_B.posOut[0] = rtb_Gain;
  ctrl_student_HIL_B.posOut[1] = rtb_Gain1;
  ctrl_student_HIL_B.posOut[2] = rtb_rad;
  if (fabs(rtb_Gain - ctrl_student_HIL_B.Memory_m[0]) <=
      ctrl_student_HIL_B.dropOutTolerance) {
    /* '<S81>:1:6' */
    /* '<S81>:1:7' */
    i = 1;
  } else if (fabs(rtb_Gain1 - ctrl_student_HIL_B.Memory_m[1]) <=
             ctrl_student_HIL_B.dropOutTolerance) {
    /* '<S81>:1:8' */
    /* '<S81>:1:9' */
    i = 1;
  } else if (fabs(rtb_rad - ctrl_student_HIL_B.Memory_m[2]) <=
             ctrl_student_HIL_B.dropOutTolerance) {
    /* '<S81>:1:10' */
    /* '<S81>:1:11' */
    i = 1;
  } else {
    /* '<S81>:1:13' */
    i = 0;
  }

  if (i == 1) {
    /* '<S81>:1:16' */
    /* '<S81>:1:17' */
    ctrl_student_HIL_B.dropout = 1.0;
  } else {
    /* '<S81>:1:19' */
    ctrl_student_HIL_B.dropout = 0.0;
  }

  /* End of MATLAB Function: '<S10>/dropOutDetect' */

  /* Sum: '<Root>/Sum2' */
  ctrl_student_HIL_B.Sum2_a = ctrl_student_HIL_B.dropout +
    ctrl_student_HIL_B.reset;

  /* Integrator: '<S14>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_student_HIL_B.Sum2_a);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_student_HIL_DW.Integrator1_IWORK.IcNeedsLoading) {
      ctrl_student_HIL_X.Integrator1_CSTATE[0] =
        ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp[0];
      ctrl_student_HIL_X.Integrator1_CSTATE[1] =
        ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp[1];
      ctrl_student_HIL_X.Integrator1_CSTATE[2] =
        ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp[2];
    }
  }

  rtb_Integrator1[0] = ctrl_student_HIL_X.Integrator1_CSTATE[0];
  rtb_Integrator1[1] = ctrl_student_HIL_X.Integrator1_CSTATE[1];
  rtb_Integrator1[2] = ctrl_student_HIL_X.Integrator1_CSTATE[2];

  /* Switch: '<Root>/Switch3' */
  if (ctrl_student_HIL_B.dropout > ctrl_student_HIL_P.Switch3_Threshold_a) {
    rtb_Switch3_idx_0 = rtb_Integrator1[0];
    rtb_Switch3_idx_1 = rtb_Integrator1[1];
    rtb_Switch3_idx_2 = rtb_Integrator1[2];
  } else {
    rtb_Switch3_idx_0 = ctrl_student_HIL_B.Switch[0];
    rtb_Switch3_idx_1 = ctrl_student_HIL_B.Switch[1];
    rtb_Switch3_idx_2 = ctrl_student_HIL_B.Switch[2];
  }

  /* End of Switch: '<Root>/Switch3' */

  /* MATLAB Function: '<S3>/calcR(psi) ' */
  /* MATLAB Function 'DPObserver1/calcR(psi) ': '<S59>:1' */
  /* '<S59>:1:3' */
  rtb_Product2_o[0] = cos(rtb_Switch3_idx_2);
  rtb_Product2_o[3] = -sin(rtb_Switch3_idx_2);
  rtb_Product2_o[6] = 0.0;
  rtb_Product2_o[1] = sin(rtb_Switch3_idx_2);
  rtb_Product2_o[4] = cos(rtb_Switch3_idx_2);
  rtb_Product2_o[7] = 0.0;
  rtb_Product2_o[2] = 0.0;
  rtb_Product2_o[5] = 0.0;
  rtb_Product2_o[8] = 1.0;

  /* Product: '<S15>/Product' */
  /* MATLAB Function 'safety zone /MATLAB Function1': '<S88>:1' */
  /* '<S88>:1:2' */
  for (i = 0; i < 3; i++) {
    rtb_Product_j[i] = rtb_Product2_o[i + 6] * ctrl_student_HIL_B.Switch2_g[2] +
      (rtb_Product2_o[i + 3] * ctrl_student_HIL_B.Switch2_g[1] +
       rtb_Product2_o[i] * ctrl_student_HIL_B.Switch2_g[0]);
  }

  /* End of Product: '<S15>/Product' */

  /* MATLAB Function: '<S15>/safety check' incorporates:
   *  Constant: '<Root>/Lim'
   *  SignalConversion: '<S90>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'safety zone /safety check': '<S90>:1' */
  /* safety_sig=[0;0;0;0];%orginal safety signal */
  /* lim=[40.00;0;6.45;0];%space limitation [x_max;x_min;y_max;y_min] */
  if (rtb_etaHat >= ctrl_student_HIL_P.lim[0]) {
    /* '<S90>:1:6' */
    /* '<S90>:1:7' */
    deg2 = 1.0;

    /* '<S90>:1:8' */
    rtb_reset = 0.0;
  } else if (rtb_etaHat <= ctrl_student_HIL_P.lim[1]) {
    /* '<S90>:1:9' */
    /* '<S90>:1:10' */
    rtb_reset = 1.0;

    /* '<S90>:1:11' */
    deg2 = 0.0;
  } else {
    /* '<S90>:1:13' */
    deg2 = 0.0;

    /* '<S90>:1:14' */
    rtb_reset = 0.0;
  }

  if (rtb_etaHat2 > ctrl_student_HIL_P.lim[2]) {
    /* '<S90>:1:16' */
    /* '<S90>:1:17' */
    rtb_Switch5 = 1.0;

    /* '<S90>:1:18' */
    rtb_safety_sig_4 = 0.0;
  } else if (rtb_etaHat2 < ctrl_student_HIL_P.lim[3]) {
    /* '<S90>:1:19' */
    /* '<S90>:1:20' */
    rtb_safety_sig_4 = 1.0;

    /* '<S90>:1:21' */
    rtb_Switch5 = 0.0;
  } else {
    /* '<S90>:1:24' */
    rtb_Switch5 = 0.0;

    /* '<S90>:1:25' */
    rtb_safety_sig_4 = 0.0;
  }

  /* End of MATLAB Function: '<S15>/safety check' */
  /*  safety_sig_1=safety_sig(1); */
  /*  safety_sig_2=safety_sig(2); */
  /* safety_sig_3=safety_sig(3); */
  /* safety_sig_4=safety_sig(4); */

  /* MATLAB Function: '<S60>/etaHatDot' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Product: '<S6>/Product1'
   *  SignalConversion: '<S66>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'DPObserver1/etaHat/etaHatDot': '<S66>:1' */
  /* etaHatDot=zeros(3,1); */
  /* '<S66>:1:4' */
  rtb_DesPosOut_idx_1 = rtb_Switch3_idx_0 - rtb_etaHat;
  rtb_InitPosOut_idx_0 = rtb_Switch3_idx_1 - rtb_etaHat2;
  rtb_InitPosOut_idx_1 = rtb_Switch3_idx_2 - rtb_etaHat1;
  for (i = 0; i < 3; i++) {
    rtb_Product2_i[i] = rtb_Product2_o[i + 6] * ctrl_student_HIL_B.nuHat[2] +
      (rtb_Product2_o[i + 3] * ctrl_student_HIL_B.nuHat[1] + rtb_Product2_o[i] *
       ctrl_student_HIL_B.nuHat[0]);
  }

  for (i = 0; i < 3; i++) {
    tmp_1[i] = ctrl_student_HIL_P.l1[i + 6] * ctrl_student_HIL_B.sf1 *
      rtb_InitPosOut_idx_1 + (ctrl_student_HIL_P.l1[i + 3] *
      ctrl_student_HIL_B.sf1 * rtb_InitPosOut_idx_0 + ctrl_student_HIL_B.sf1 *
      ctrl_student_HIL_P.l1[i] * rtb_DesPosOut_idx_1);
  }

  ctrl_student_HIL_B.etaHatDot[0] = rtb_Product2_i[0] + tmp_1[0];
  ctrl_student_HIL_B.etaHatDot[1] = rtb_Product2_i[1] + tmp_1[1];
  ctrl_student_HIL_B.etaHatDot[2] = rtb_Product2_i[2] + tmp_1[2];

  /* End of MATLAB Function: '<S60>/etaHatDot' */

  /* MATLAB Function: '<S15>/Safety Act' incorporates:
   *  Constant: '<Root>/K'
   */
  /* MATLAB Function 'safety zone /Safety Act': '<S89>:1' */
  /* K=[1;1];     */
  if ((deg2 == 0.0) && (rtb_reset == 0.0) && (rtb_Switch5 == 0.0) &&
      (rtb_safety_sig_4 == 0.0)) {
    /* '<S89>:1:7' */
    /* Check to see if intervention is requiered */
    /* '<S89>:1:9' */
    rtb_U_ss = 0.0;

    /* Intervention is NOT requiered */
    /* '<S89>:1:10' */
    rtb_reset = rtb_Product_j[0];

    /* '<S89>:1:11' */
    deg2 = rtb_Product_j[1];

    /* disp('Flag 0.0 All OK - No safety sig'); */
  } else {
    /* '<S89>:1:14' */
    rtb_U_ss = 1.0;

    /* Intervention IS requiered */
    if ((deg2 == 1.0) || (rtb_reset == 1.0)) {
      /* '<S89>:1:16' */
      /* Problem in X dir */
      /* disp('Flag 1.0 Problem in x'); */
      if (rtb_Product_j[0] == 0.0) {
        /* '<S89>:1:18' */
        /* Check if inputforce fore is zero or correct, (but the velocity might not be) */
        /* Perhaps a proprtional gain depending on the velocity? */
        if ((ctrl_student_HIL_B.etaHatDot[0] < 0.0) && (rtb_reset == 1.0)) {
          /* '<S89>:1:20' */
          /* '<S89>:1:21' */
          rtb_reset = ctrl_student_HIL_P.K[0] * -ctrl_student_HIL_B.etaHatDot[0];

          /* disp('Flag 1.1 (x - tau=0 - Negative vel + to low x pos -> thrust =-vel*K_1)'); */
        } else if ((ctrl_student_HIL_B.etaHatDot[0] > 0.0) && (deg2 == 1.0)) {
          /* '<S89>:1:23' */
          /* '<S89>:1:24' */
          rtb_reset = ctrl_student_HIL_P.K[0] * -ctrl_student_HIL_B.etaHatDot[0];

          /* disp('Flag 1.2 (x - tau=0 - Positive vel + to high x pos -> thrust =-vel*K_1)'); */
        } else {
          /* '<S89>:1:27' */
          rtb_reset = ctrl_student_HIL_P.K[0] * ctrl_student_HIL_B.etaHatDot[0];

          /* disp('Flag 1.3 (x - tau=0 - Positive vel + to low x pos / Negative vel + to highx pos -> keep current trust)'); */
        }

        /* thrust_out=[ThrustX;joyStick(2);joyStick(3)]; */
      } else if ((rtb_Product_j[0] > 0.0) && (rtb_reset == 1.0)) {
        /* '<S89>:1:32' */
        /* X cord to small, but thrust right way */
        /* '<S89>:1:33' */
        rtb_reset = rtb_Product_j[0];

        /* thrust_out=[joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 1.4 (x - Positive thrust + to low x post -> keep current trust)'); */
      } else if ((rtb_Product_j[0] < 0.0) && (deg2 == 1.0)) {
        /* '<S89>:1:36' */
        /* X cord to large, but thrust right way */
        /* '<S89>:1:37' */
        rtb_reset = rtb_Product_j[0];

        /* thrust_out=[joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 1.5 (x - Negative thrust + to high x post -> Keep current trust)'); */
      } else {
        /* '<S89>:1:41' */
        rtb_reset = -rtb_Product_j[0];

        /* thrust_out=[-joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 1.6 (x - Negative thrust + to low x post / Positive thrust + to high x post -> reverse trust)'); */
      }

      /* If */
    } else {
      /* '<S89>:1:46' */
      rtb_reset = rtb_Product_j[0];
    }

    /* IF   */
    if ((rtb_Switch5 == 1.0) || (rtb_safety_sig_4 == 1.0)) {
      /* '<S89>:1:49' */
      /* Problem in X dir%Problem in Y dir */
      /* disp('Flag 2.0 Problem in y'); */
      if (rtb_Product_j[1] == 0.0) {
        /* '<S89>:1:51' */
        /* Check if inputforce fore is zero or correct */
        /* Perhaps a proprtional gain depending on the velocity?   */
        if ((ctrl_student_HIL_B.etaHatDot[1] > 0.0) && (rtb_Switch5 == 1.0)) {
          /* '<S89>:1:53' */
          /* '<S89>:1:54' */
          deg2 = ctrl_student_HIL_P.K[1] * -ctrl_student_HIL_B.etaHatDot[1];

          /* disp('Flag 2.1 (y - tau=0 - Negative vel + to low y pos -> thrust =-vel*K_2)'); */
        } else if ((ctrl_student_HIL_B.etaHatDot[1] < 0.0) && (rtb_safety_sig_4 ==
                    1.0)) {
          /* '<S89>:1:56' */
          /* '<S89>:1:57' */
          deg2 = ctrl_student_HIL_P.K[1] * -ctrl_student_HIL_B.etaHatDot[1];

          /* disp('Flag 2.2 (y - tau=0 - Positive vel + to high y pos -> thrust =-vel*K_2)'); */
        } else {
          /* '<S89>:1:60' */
          deg2 = ctrl_student_HIL_P.K[1] * ctrl_student_HIL_B.etaHatDot[1];

          /* disp('Flag 2.3 (y - tau=0 - Positive vel + to low y pos / Negative vel + to high y pos -> keep current trust)'); */
        }

        /* IF */
        /* thrust_out=[joyStick(1);ThrustY;joyStick(3)]; */
      } else if ((rtb_Product_j[1] > 0.0) && (rtb_safety_sig_4 == 1.0)) {
        /* '<S89>:1:65' */
        /* Y cord to small */
        /* '<S89>:1:66' */
        deg2 = rtb_Product_j[1];

        /* thrust_out=[joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 2.4 (y - Positive thrust + to low y post -> keep current trust)'); */
      } else if ((rtb_Product_j[1] < 0.0) && (rtb_Switch5 == 1.0)) {
        /* '<S89>:1:70' */
        /* Y cord to large */
        /* '<S89>:1:71' */
        deg2 = rtb_Product_j[1];

        /* thrust_out=[joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 2.5 (y - Negative thrust + to high y post -> Keep current trust)'); */
      } else {
        /* '<S89>:1:76' */
        deg2 = -rtb_Product_j[1];

        /* thrust_out=[joyStick(1);-joyStick(2);joyStick(3)]; */
        /* disp('Flag 2.6 (y - Negative thrust + to low y post / Positive thrust + to high y post -> reverse trust)'); */
      }

      /* IF */
    } else {
      /* '<S89>:1:82' */
      deg2 = rtb_Product_j[1];
    }

    /* IF */
  }

  /* Switch: '<S15>/Switch' incorporates:
   *  MATLAB Function: '<S15>/Safety Act'
   */
  /* IF */
  /* '<S89>:1:86' */
  /* Function */
  if (rtb_U_ss > ctrl_student_HIL_P.Switch_Threshold_n) {
    rtb_eta_dss_idx_0 = rtb_reset;
    rtb_eta_dss_idx_1 = deg2;
  } else {
    rtb_eta_dss_idx_0 = rtb_Product_j[0];
    rtb_eta_dss_idx_1 = rtb_Product_j[1];
  }

  rtb_eta_dss_idx_2 = rtb_Product_j[2];

  /* End of Switch: '<S15>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S15>/Memory' */
    ctrl_student_HIL_B.Memory_n = ctrl_student_HIL_DW.Memory_PreviousInput_e;
  }

  /* MATLAB Function: '<S15>/KillSwitch' incorporates:
   *  Constant: '<Root>/Lim2'
   *  MATLAB Function: '<S15>/Safety Act'
   *  SignalConversion: '<S86>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'safety zone /KillSwitch': '<S86>:1' */
  if (ctrl_student_HIL_B.Memory_n == 1.0) {
    /* '<S86>:1:3' */
    /* '<S86>:1:4' */
    i = 1;

    /* disp('Flag 3.0 KILL - previous kill'); */
  } else {
    if (rtb_etaHat >= ctrl_student_HIL_P.lim_2[0]) {
      /* '<S86>:1:7' */
      /* '<S86>:1:9' */
      i = 1;

      /* disp('Flag 3.1 KILL - large x'); */
    } else if (rtb_etaHat <= ctrl_student_HIL_P.lim_2[1]) {
      /* '<S86>:1:11' */
      /* '<S86>:1:13' */
      i = 1;

      /* disp('Flag 3.2 KILL - small x'); */
    } else {
      /* '<S86>:1:17' */
      i = 0;
    }

    /* IF */
    if (rtb_etaHat2 >= ctrl_student_HIL_P.lim_2[2]) {
      /* '<S86>:1:19' */
      /* '<S86>:1:20' */
      i = 1;

      /* disp('Flag 3.3 KILL - large y'); */
    } else {
      if (rtb_etaHat2 <= ctrl_student_HIL_P.lim_2[3]) {
        /* '<S86>:1:22' */
        /* '<S86>:1:23' */
        i = 1;

        /* disp('Flag 3.4 KILL - small y'); */
      }
    }

    /* IF */
  }

  /*  IF */
  if (i == 1) {
    /* '<S86>:1:35' */
    /* '<S86>:1:36' */
    rtb_eta_ds[0] = 0.0;
    rtb_eta_ds[1] = 0.0;
    rtb_eta_ds[2] = 0.0;
  } else {
    /* '<S86>:1:38' */
    rtb_eta_ds[0] = rtb_eta_dss_idx_0;
    rtb_eta_ds[1] = rtb_eta_dss_idx_1;
    rtb_eta_ds[2] = rtb_Product_j[2];
  }

  /* IF */
  /* Function */

  /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S15>/KillSwitch'
   */
  /* MATLAB Function 'safety zone /MATLAB Function': '<S87>:1' */
  if (ctrl_student_HIL_B.SZ_ResetKill == 1.0) {
    /* '<S87>:1:3' */
    /* '<S87>:1:4' */
    ctrl_student_HIL_B.kill_signal = 0.0;
  } else {
    /* '<S87>:1:6' */
    ctrl_student_HIL_B.kill_signal = i;
  }

  /* End of MATLAB Function: '<S15>/MATLAB Function' */

  /* Switch: '<S15>/Switch2' */
  if (!(ctrl_student_HIL_B.SZ_Owerwrite > ctrl_student_HIL_P.Switch2_Threshold_p))
  {
    /* Switch: '<S15>/Switch1' */
    if (ctrl_student_HIL_B.kill_signal > ctrl_student_HIL_P.Switch1_Threshold) {
      rtb_Product_j[0] = rtb_eta_ds[0];
      rtb_Product_j[1] = rtb_eta_ds[1];
      rtb_Product_j[2] = rtb_eta_ds[2];
    } else {
      rtb_Product_j[0] = rtb_eta_dss_idx_0;
      rtb_Product_j[1] = rtb_eta_dss_idx_1;
      rtb_Product_j[2] = rtb_eta_dss_idx_2;
    }

    /* End of Switch: '<S15>/Switch1' */
  }

  /* End of Switch: '<S15>/Switch2' */

  /* Product: '<S15>/Product1' incorporates:
   *  MATLAB Function: '<S15>/MATLAB Function1'
   */
  for (i = 0; i < 3; i++) {
    rtb_eta_ds[i] = rtb_Product2_o[3 * i + 2] * rtb_Product_j[2] +
      (rtb_Product2_o[3 * i + 1] * rtb_Product_j[1] + rtb_Product2_o[3 * i] *
       rtb_Product_j[0]);
  }

  /* End of Product: '<S15>/Product1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (ctrl_student_HIL_B.JoysticControllerSwitch >
      ctrl_student_HIL_P.Switch1_Threshold_l) {
    rtb_safety_sig_4 = ctrl_student_HIL_P.Constant1_Value_i;
  } else {
    rtb_safety_sig_4 = ctrl_student_HIL_B.Select;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* MATLAB Function: '<S9>/Force Allocation1' */
  /* MATLAB Function 'ThrustAllocationAndSaturation/Force Allocation1': '<S77>:1' */
  if (rtb_safety_sig_4 == 2.0) {
    /* '<S77>:1:5' */
    /* 2DOF stick control */
    /* '<S77>:1:7' */
    rtb_Gain1 = rtb_eta_ds[0] / 2.0;

    /* '<S77>:1:8' */
    rtb_U_ss = rtb_Gain1;

    /* '<S77>:1:9' */
    rtb_Gain = rtb_eta_ds[1] / 2.0;

    /* '<S77>:1:10' */
  } else {
    /* 3 DOF stick control, no BT */
    /* '<S77>:1:13' */
    deg2 = rtb_eta_ds[0] / 2.0;

    /* '<S77>:1:16' */
    rtb_Gain = rtb_eta_ds[1] / 2.0;

    /* '<S77>:1:19' */
    rtb_reset = 0.5 * rtb_eta_ds[2] / 0.062;

    /* '<S77>:1:20' */
    /* '<S77>:1:22' */
    rtb_Switch5 = rtb_Gain * 0.4575 / 0.062;

    /* '<S77>:1:23' */
    /* '<S77>:1:25' */
    rtb_Gain1 = (deg2 + rtb_reset) + rtb_Switch5;

    /* '<S77>:1:26' */
    rtb_U_ss = (deg2 + -rtb_reset) + -rtb_Switch5;

    /* '<S77>:1:27' */
    /* '<S77>:1:28' */
  }

  /* MATLAB Function: '<S9>/Force2Control' incorporates:
   *  Constant: '<S9>/Actuator_Sat_Forces'
   *  MATLAB Function: '<S9>/Force Allocation1'
   */
  /* original equations from 30/1/2017 */
  /*  f_vspx=tau_surge; */
  /*  f_vspy=(tau_yaw-tau_sway*l_bt)/(l_vsp-l_bt); */
  /*  f_bt=tau_sway-f_vspy; */
  /* tau_yaw = f_vspy*l_vsp+f_bt*l_bt */
  /* tau_sway=f_vspy+f_bt */
  /* solve for f_bt and f_vspy */
  /* MATLAB Function 'ThrustAllocationAndSaturation/Force2Control': '<S78>:1' */
  if (rtb_safety_sig_4 == 2.0) {
    /* '<S78>:1:3' */
    /* '<S78>:1:4' */
    deg2 = sqrt(rtb_Gain1 * rtb_Gain1 + rtb_Gain * rtb_Gain) /
      ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0];

    /* '<S78>:1:5' */
    rtb_reset = deg2;

    /* '<S78>:1:6' */
    rtb_safety_sig_4 = rt_atan2d_snf(rtb_Gain, rtb_Gain1);

    /* '<S78>:1:7' */
    ctrl_student_HIL_B.alpha2 = rtb_safety_sig_4;
  } else {
    /* '<S78>:1:9' */
    deg2 = sqrt(rtb_Gain1 * rtb_Gain1 + rtb_Gain * rtb_Gain) /
      ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0];

    /* '<S78>:1:10' */
    rtb_reset = sqrt(rtb_U_ss * rtb_U_ss + rtb_Gain * rtb_Gain) /
      ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0];

    /* '<S78>:1:11' */
    rtb_safety_sig_4 = rt_atan2d_snf(rtb_Gain, rtb_Gain1);

    /* '<S78>:1:12' */
    ctrl_student_HIL_B.alpha2 = rt_atan2d_snf(rtb_Gain, rtb_U_ss);
  }

  if (fabs(deg2) > 1.0) {
    /* '<S78>:1:15' */
    /* '<S78>:1:16' */
    rtb_Switch5 = 1.0 / fabs(deg2);

    /* '<S78>:1:17' */
  } else if (fabs(rtb_reset) > 1.0) {
    /* '<S78>:1:18' */
    /* '<S78>:1:19' */
    rtb_Switch5 = 1.0 / fabs(rtb_reset);

    /* '<S78>:1:20' */
  } else {
    /* '<S78>:1:22' */
    rtb_Switch5 = 1.0;

    /* '<S78>:1:23' */
  }

  /* '<S78>:1:26' */
  ctrl_student_HIL_B.u_vsp1 = deg2 * rtb_Switch5;

  /* '<S78>:1:27' */
  ctrl_student_HIL_B.u_vsp2 = rtb_reset * rtb_Switch5;

  /* '<S78>:1:28' */
  ctrl_student_HIL_B.alpha1 = rtb_safety_sig_4;

  /* End of MATLAB Function: '<S9>/Force2Control' */

  /* MATLAB Function: '<S9>/actForces1' incorporates:
   *  Constant: '<S9>/Actuator_Sat_Forces'
   *  SignalConversion: '<S80>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'ThrustAllocationAndSaturation/actForces1': '<S80>:1' */
  /* '<S80>:1:3' */
  deg2 = ctrl_student_HIL_B.u_vsp1 *
    ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0] * cos
    (ctrl_student_HIL_B.alpha1);

  /* '<S80>:1:4' */
  rtb_reset = ctrl_student_HIL_B.u_vsp2 *
    ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0] * cos
    (ctrl_student_HIL_B.alpha2);

  /* '<S80>:1:5' */
  rtb_safety_sig_4 = ctrl_student_HIL_B.u_vsp1 *
    ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0] * sin
    (ctrl_student_HIL_B.alpha1);

  /* '<S80>:1:6' */
  rtb_Switch5 = ctrl_student_HIL_B.u_vsp2 *
    ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0] * sin
    (ctrl_student_HIL_B.alpha2);

  /* '<S80>:1:7' */
  /* '<S80>:1:9' */
  ctrl_student_HIL_B.tauAct[0] = deg2 + rtb_reset;
  ctrl_student_HIL_B.tauAct[1] = rtb_safety_sig_4 + rtb_Switch5;
  ctrl_student_HIL_B.tauAct[2] = (deg2 - rtb_reset) * 0.062 - (rtb_safety_sig_4
    + rtb_Switch5) * 0.4575;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* ToWorkspace: '<S1>/To Workspace3' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (ctrl_student_HIL_DW.ToWorkspace3_PWORK.LoggedData),
                    &ctrl_student_HIL_B.Switch_j[0], 0);

    /* Memory: '<S49>/Memory' */
    ctrl_student_HIL_B.Memory_o = ctrl_student_HIL_DW.Memory_PreviousInput_p;
  }

  /* MATLAB Function: '<S49>/MATLAB Function1' */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function1': '<S53>:1' */
  if (ctrl_student_HIL_B.reset == 1.0) {
    /* '<S53>:1:3' */
    /* '<S53>:1:4' */
    ctrl_student_HIL_B.SwitchSignal = 0.0;

    /* '<S53>:1:5' */
    ctrl_student_HIL_B.N = 1.0;
  } else {
    /* '<S53>:1:7' */
    ctrl_student_HIL_B.SwitchSignal = ctrl_student_HIL_B.SwitchSignal_out;

    /* '<S53>:1:8' */
    ctrl_student_HIL_B.N = ctrl_student_HIL_B.Memory_o;
  }

  /* End of MATLAB Function: '<S49>/MATLAB Function1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* InitialCondition: '<S56>/IC1' incorporates:
   *  Constant: '<S56>/Constant'
   *  Integrator: '<S56>/bHat'
   *  Product: '<S56>/Product'
   *  Sum: '<S56>/Sum'
   */
  if ((ctrl_student_HIL_DW.IC1_FirstOutputTime == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC1_FirstOutputTime == ctrl_student_HIL_M->Timing.t[0]))
  {
    ctrl_student_HIL_DW.IC1_FirstOutputTime = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC1[0] = ctrl_student_HIL_P.IC1_Value[0];
    ctrl_student_HIL_B.IC1[1] = ctrl_student_HIL_P.IC1_Value[1];
    ctrl_student_HIL_B.IC1[2] = ctrl_student_HIL_P.IC1_Value[2];
  } else {
    ctrl_student_HIL_B.IC1[0] = ctrl_student_HIL_B.biasOffset *
      ctrl_student_HIL_P.Constant_Value_e[0] + ctrl_student_HIL_X.bHat_CSTATE[0];
    ctrl_student_HIL_B.IC1[1] = ctrl_student_HIL_B.biasOffset *
      ctrl_student_HIL_P.Constant_Value_e[1] + ctrl_student_HIL_X.bHat_CSTATE[1];
    ctrl_student_HIL_B.IC1[2] = ctrl_student_HIL_B.biasOffset *
      ctrl_student_HIL_P.Constant_Value_e[2] + ctrl_student_HIL_X.bHat_CSTATE[2];
  }

  /* End of InitialCondition: '<S56>/IC1' */

  /* MATLAB Function: '<S56>/bHatDot' incorporates:
   *  Constant: '<S6>/Constant3'
   *  Product: '<S6>/Product'
   *  SignalConversion: '<S61>/TmpSignal ConversionAt SFunction Inport3'
   */
  /* MATLAB Function 'DPObserver1/Bias/bHatDot': '<S61>:1' */
  /* '<S61>:1:3' */
  rtb_DesPosOut_idx_1 = rtb_Switch3_idx_0 - rtb_etaHat;
  rtb_InitPosOut_idx_0 = rtb_Switch3_idx_1 - rtb_etaHat2;
  rtb_InitPosOut_idx_1 = rtb_Switch3_idx_2 - rtb_etaHat1;
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.bHatDot[i] = 0.0;
    ctrl_student_HIL_B.bHatDot[i] += ctrl_student_HIL_B.sf3 *
      ctrl_student_HIL_P.l3[i] * rtb_DesPosOut_idx_1;
    ctrl_student_HIL_B.bHatDot[i] += ctrl_student_HIL_P.l3[i + 3] *
      ctrl_student_HIL_B.sf3 * rtb_InitPosOut_idx_0;
    ctrl_student_HIL_B.bHatDot[i] += ctrl_student_HIL_P.l3[i + 6] *
      ctrl_student_HIL_B.sf3 * rtb_InitPosOut_idx_1;
  }

  /* bHatDot=[0;0;0]; */
  /* MATLAB Function 'DPObserver1/D': '<S57>:1' */
  /* '<S57>:1:3' */
  /* u=0;  */
  /* '<S57>:1:4' */
  /* v=0;  */
  /* '<S57>:1:5' */
  /* r=0; */
  /* '<S57>:1:7' */
  /* '<S57>:1:10' */
  /* '<S57>:1:13' */
  /* '<S57>:1:18' */
  /* '<S57>:1:21' */
  /* '<S57>:1:27' */
  /* '<S57>:1:28' */
  /* '<S57>:1:29' */
  /* '<S57>:1:30' */
  /* '<S57>:1:31' */
  /* '<S57>:1:33' */
  /* MATLAB Function 'DPObserver1/Subsystem/M': '<S62>:1' */
  /* '<S62>:1:3' */
  /* '<S62>:1:4' */
  /* MATLAB Function 'DPObserver1/Subsystem/nuHatDot': '<S63>:1' */
  /* nuHatDot=inv(M)*(-D*nuHat+transpose(R)*bHat+tau+K2*transpose(R)*L2*(eta-etaHat)); */
  /* '<S63>:1:5' */
  for (i = 0; i < 9; i++) {
    /* MATLAB Function: '<S58>/nuHatDot' incorporates:
     *  MATLAB Function: '<S58>/M'
     */
    S_T[i] = tmp[i];

    /* MATLAB Function: '<S58>/M' */
    rtb_M[i] = tmp[i];
  }

  /* End of MATLAB Function: '<S56>/bHatDot' */

  /* MATLAB Function: '<S58>/nuHatDot' */
  i = 0;
  p2 = 3;
  p3 = 6;
  if ((rtb_M[1] > rtb_M[0]) && (rtb_M[1] > rtb_M[2])) {
    i = 3;
    p2 = 0;
    S_T[0] = rtb_M[1];
    S_T[1] = rtb_M[0];
    S_T[3] = rtb_M[4];
    S_T[4] = rtb_M[3];
    S_T[6] = rtb_M[7];
    S_T[7] = rtb_M[6];
  } else {
    if (rtb_M[2] > rtb_M[0]) {
      i = 6;
      p3 = 0;
      S_T[0] = rtb_M[2];
      S_T[2] = rtb_M[0];
      S_T[3] = rtb_M[5];
      S_T[5] = rtb_M[3];
      S_T[6] = rtb_M[8];
      S_T[8] = rtb_M[6];
    }
  }

  deg2 = S_T[1] / S_T[0];
  S_T[1] /= S_T[0];
  rtb_reset = S_T[2] / S_T[0];
  S_T[2] /= S_T[0];
  S_T[4] -= deg2 * S_T[3];
  S_T[5] -= rtb_reset * S_T[3];
  S_T[7] -= deg2 * S_T[6];
  S_T[8] -= rtb_reset * S_T[6];
  if (fabs(S_T[5]) > fabs(S_T[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    S_T[1] = rtb_reset;
    S_T[2] = deg2;
    deg2 = S_T[4];
    S_T[4] = S_T[5];
    S_T[5] = deg2;
    deg2 = S_T[7];
    S_T[7] = S_T[8];
    S_T[8] = deg2;
  }

  rtb_safety_sig_4 = S_T[5];
  rtb_Switch5 = S_T[4];
  deg2 = S_T[5] / S_T[4];
  S_T[8] -= deg2 * S_T[7];
  deg2 = (deg2 * S_T[1] - S_T[2]) / S_T[8];
  rtb_reset = -(S_T[7] * deg2 + S_T[1]) / S_T[4];
  y[i] = ((1.0 - S_T[3] * rtb_reset) - S_T[6] * deg2) / S_T[0];
  y[i + 1] = rtb_reset;
  y[i + 2] = deg2;
  deg2 = -(rtb_safety_sig_4 / rtb_Switch5) / S_T[8];
  rtb_reset = (1.0 - S_T[7] * deg2) / S_T[4];
  y[p2] = -(S_T[3] * rtb_reset + S_T[6] * deg2) / S_T[0];
  y[p2 + 1] = rtb_reset;
  y[p2 + 2] = deg2;
  deg2 = 1.0 / S_T[8];
  rtb_reset = -S_T[7] * deg2 / S_T[4];
  y[p3] = -(S_T[3] * rtb_reset + S_T[6] * deg2) / S_T[0];
  y[p3 + 1] = rtb_reset;
  y[p3 + 2] = deg2;

  /* InitialCondition: '<S58>/IC' incorporates:
   *  MATLAB Function: '<S58>/nuHatDot'
   */
  if ((ctrl_student_HIL_DW.IC_FirstOutputTime_n == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC_FirstOutputTime_n == ctrl_student_HIL_M->Timing.t
       [0])) {
    ctrl_student_HIL_DW.IC_FirstOutputTime_n = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC_i[0] = ctrl_student_HIL_P.IC_Value_f[0];
    ctrl_student_HIL_B.IC_i[1] = ctrl_student_HIL_P.IC_Value_f[1];
    ctrl_student_HIL_B.IC_i[2] = ctrl_student_HIL_P.IC_Value_f[2];
  } else {
    /* MATLAB Function: '<S3>/D' */
    tmp_3[0] = (0.6555 - 0.3545 * fabs(ctrl_student_HIL_B.etaHatDot[0])) -
      ctrl_student_HIL_B.etaHatDot[0] * ctrl_student_HIL_B.etaHatDot[0] * -3.787;
    tmp_3[3] = 0.0;
    tmp_3[6] = 0.0;
    tmp_3[1] = 0.0;
    tmp_3[4] = ((1.33 - -2.776 * fabs(ctrl_student_HIL_B.etaHatDot[1])) -
                ctrl_student_HIL_B.etaHatDot[1] * ctrl_student_HIL_B.etaHatDot[1]
                * -64.91) - -0.805 * fabs(ctrl_student_HIL_B.etaHatDot[2]);
    tmp_3[7] = ((7.25 - -0.845 * fabs(ctrl_student_HIL_B.etaHatDot[1])) - -3.45 *
                fabs(ctrl_student_HIL_B.etaHatDot[2])) -
      ctrl_student_HIL_B.etaHatDot[2] * ctrl_student_HIL_B.etaHatDot[2] * 0.0;
    tmp_3[2] = 0.0;
    tmp_3[5] = ((-0.0 - -0.2088 * fabs(ctrl_student_HIL_B.etaHatDot[1])) -
                ctrl_student_HIL_B.etaHatDot[1] * ctrl_student_HIL_B.etaHatDot[1]
                * 0.0) - 0.13 * fabs(ctrl_student_HIL_B.etaHatDot[2]);
    tmp_3[8] = ((1.9 - 0.08 * fabs(ctrl_student_HIL_B.etaHatDot[1])) - -0.75 *
                fabs(ctrl_student_HIL_B.etaHatDot[2])) -
      ctrl_student_HIL_B.etaHatDot[2] * ctrl_student_HIL_B.etaHatDot[2] * 0.0;

    /* MATLAB Function: '<S58>/nuHatDot' incorporates:
     *  Constant: '<S6>/Constant2'
     *  Product: '<S6>/Product2'
     *  SignalConversion: '<S63>/TmpSignal ConversionAt SFunction Inport9'
     */
    for (i = 0; i < 3; i++) {
      tmp_2[3 * i] = -tmp_3[3 * i];
      tmp_2[1 + 3 * i] = -tmp_3[3 * i + 1];
      tmp_2[2 + 3 * i] = -tmp_3[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      tmp_1[i] = tmp_2[i + 6] * ctrl_student_HIL_B.nuHat[2] + (tmp_2[i + 3] *
        ctrl_student_HIL_B.nuHat[1] + tmp_2[i] * ctrl_student_HIL_B.nuHat[0]);
    }

    for (i = 0; i < 3; i++) {
      rtb_Product2_i[i] = rtb_Product2_o[3 * i + 2] * ctrl_student_HIL_B.IC1[2]
        + (rtb_Product2_o[3 * i + 1] * ctrl_student_HIL_B.IC1[1] +
           rtb_Product2_o[3 * i] * ctrl_student_HIL_B.IC1[0]);
    }

    for (i = 0; i < 3; i++) {
      for (p2 = 0; p2 < 3; p2++) {
        rtb_M[i + 3 * p2] = 0.0;
        rtb_M[i + 3 * p2] += ctrl_student_HIL_P.l2[3 * p2] *
          ctrl_student_HIL_B.sf2 * rtb_Product2_o[3 * i];
        rtb_M[i + 3 * p2] += ctrl_student_HIL_P.l2[3 * p2 + 1] *
          ctrl_student_HIL_B.sf2 * rtb_Product2_o[3 * i + 1];
        rtb_M[i + 3 * p2] += ctrl_student_HIL_P.l2[3 * p2 + 2] *
          ctrl_student_HIL_B.sf2 * rtb_Product2_o[3 * i + 2];
      }
    }

    rtb_Switch3_idx_0 -= rtb_etaHat;
    rtb_Switch3_idx_1 -= rtb_etaHat2;
    rtb_Switch3_idx_2 -= rtb_etaHat1;
    for (i = 0; i < 3; i++) {
      rtb_Product_j[i] = ((rtb_M[i + 3] * rtb_Switch3_idx_1 + rtb_M[i] *
                           rtb_Switch3_idx_0) + rtb_M[i + 6] * rtb_Switch3_idx_2)
        + ((tmp_1[i] + rtb_Product2_i[i]) + ctrl_student_HIL_B.tauAct[i]);
    }

    for (i = 0; i < 3; i++) {
      ctrl_student_HIL_B.IC_i[i] = 0.0;
      ctrl_student_HIL_B.IC_i[i] += y[i] * rtb_Product_j[0];
      ctrl_student_HIL_B.IC_i[i] += y[i + 3] * rtb_Product_j[1];
      ctrl_student_HIL_B.IC_i[i] += y[i + 6] * rtb_Product_j[2];
    }
  }

  /* End of InitialCondition: '<S58>/IC' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Clock: '<S79>/Clock' */
  rtb_Clock = ctrl_student_HIL_M->Timing.t[0];

  /* Step: '<S79>/Step' */
  if (ctrl_student_HIL_M->Timing.t[0] < ctrl_student_HIL_P.Ramp_start) {
    rtb_DesPosOut_idx_1 = ctrl_student_HIL_P.Step_Y0;
  } else {
    rtb_DesPosOut_idx_1 = ctrl_student_HIL_P.Ramp_slope;
  }

  /* End of Step: '<S79>/Step' */

  /* Sum: '<S79>/Output' incorporates:
   *  Constant: '<S79>/Constant'
   *  Constant: '<S79>/Constant1'
   *  Product: '<S79>/Product'
   *  Sum: '<S79>/Sum'
   */
  deg2 = (rtb_Clock - ctrl_student_HIL_P.Ramp_start) * rtb_DesPosOut_idx_1 +
    ctrl_student_HIL_P.Ramp_X0;

  /* Saturate: '<S9>/Saturation' */
  if (deg2 > ctrl_student_HIL_P.Saturation_UpperSat) {
    deg2 = ctrl_student_HIL_P.Saturation_UpperSat;
  } else {
    if (deg2 < ctrl_student_HIL_P.Saturation_LowerSat) {
      deg2 = ctrl_student_HIL_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S9>/Saturation' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   */
  if (ctrl_student_HIL_B.TurnOffomega1 > ctrl_student_HIL_P.Switch_Threshold_j)
  {
    ctrl_student_HIL_B.Switch_b = ctrl_student_HIL_P.Constant_Value_ks;
  } else {
    ctrl_student_HIL_B.Switch_b = deg2;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  if (ctrl_student_HIL_B.TurnOffomega2 > ctrl_student_HIL_P.Switch1_Threshold_o)
  {
    ctrl_student_HIL_B.Switch1 = ctrl_student_HIL_P.Constant1_Value_o;
  } else {
    ctrl_student_HIL_B.Switch1 = deg2;
  }

  /* End of Switch: '<S9>/Switch1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Sum: '<S9>/Sum' incorporates:
   *  MATLAB Function: '<S9>/Force Allocation1'
   */
  ctrl_student_HIL_B.Sum_n = rtb_Gain1 + rtb_U_ss;

  /* Sum: '<S9>/Sum1' incorporates:
   *  MATLAB Function: '<S9>/Force Allocation1'
   */
  ctrl_student_HIL_B.Sum1_n = rtb_Gain + rtb_Gain;

  /* Integrator: '<S14>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_p,
                       ctrl_student_HIL_B.Sum2_a);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading) {
      ctrl_student_HIL_X.Integrator_CSTATE_b[0] = ctrl_student_HIL_B.nuHat[0];
      ctrl_student_HIL_X.Integrator_CSTATE_b[1] = ctrl_student_HIL_B.nuHat[1];
      ctrl_student_HIL_X.Integrator_CSTATE_b[2] = ctrl_student_HIL_B.nuHat[2];
    }
  }

  rtb_Integrator[0] = ctrl_student_HIL_X.Integrator_CSTATE_b[0];
  rtb_Integrator[1] = ctrl_student_HIL_X.Integrator_CSTATE_b[1];
  rtb_Integrator[2] = ctrl_student_HIL_X.Integrator_CSTATE_b[2];

  /* MATLAB Function: '<S14>/kinematics' */
  /* MATLAB Function 'physics_model/kinematics': '<S84>:1' */
  /* '<S84>:1:3' */
  /* '<S84>:1:5' */
  /* '<S84>:1:9' */
  tmp_4[0] = cos(rtb_Integrator1[2]);
  tmp_4[3] = -sin(rtb_Integrator1[2]);
  tmp_4[6] = 0.0;
  tmp_4[1] = sin(rtb_Integrator1[2]);
  tmp_4[4] = cos(rtb_Integrator1[2]);
  tmp_4[7] = 0.0;
  tmp_4[2] = 0.0;
  tmp_4[5] = 0.0;
  tmp_4[8] = 1.0;
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.eta_dot[i] = 0.0;
    ctrl_student_HIL_B.eta_dot[i] += tmp_4[i] * rtb_Integrator[0];
    ctrl_student_HIL_B.eta_dot[i] += tmp_4[i + 3] * rtb_Integrator[1];
    ctrl_student_HIL_B.eta_dot[i] += tmp_4[i + 6] * rtb_Integrator[2];
  }

  /* End of MATLAB Function: '<S14>/kinematics' */

  /* MATLAB Function: '<S14>/kinetics' */
  /* MATLAB Function 'physics_model/kinetics': '<S85>:1' */
  /* '<S85>:1:3' */
  /* '<S85>:1:4' */
  /* '<S85>:1:5' */
  /* '<S85>:1:7' */
  /* % MATRICES */
  /*  x_g  =  0.0460; % Table B.1 */
  /* % Added mass */
  /*  Table B.1 */
  /*  Table B.1 guestimate */
  /*  Table B.1 */
  /* % Total mass matrix */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S85>:1:33' */
  /* '<S85>:1:37' */
  /*  Y_r */
  /*  Y_rr */
  /*  Y_rv, Y_vr */
  /* '<S85>:1:43' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /* % Correolis matrix */
  /* from ItsLearning */
  /*  c_13 = -(m-Y_vd)*v-(m*x_g-Y_rd)*r; */
  /*  c_23 = (m-X_ud)*u; */
  /*  C    = [0     0     c_13 */
  /*          0     0     c_23 */
  /*          -c_13 -c_23 0   ]; */
  /* From Handbook of Marine Craft Hydr 1st ed pp.120 */
  /* % Assembly of the damping matrix */
  /* '<S85>:1:65' */
  /* '<S85>:1:66' */
  /* '<S85>:1:67' */
  /*  using abs(r) */
  /* '<S85>:1:70' */
  /* '<S85>:1:71' */
  /* From ItsLearning */
  /*  D    = [d_11 d_12 0 */
  /*          0    d_22 d_23 */
  /*          0    d_32 d_33]; */
  /* From Feb. 2017 lab manual. Agrees with Handbook of Marine Craft Hydro */
  /* '<S85>:1:79' */
  /* % CALCULATION */
  /* nu_dot = M\(tau-(C+D)*nu); */
  /* '<S85>:1:88' */
  tmp_5[0] = (0.6555 - 0.3545 * rtb_Integrator[0]) - rtb_Integrator[0] *
    rtb_Integrator[0] * -3.787;
  tmp_5[3] = 0.0;
  tmp_5[6] = 0.0;
  tmp_5[1] = 0.0;
  tmp_5[4] = ((1.33 - -2.776 * rtb_Integrator[1]) - rtb_Integrator[1] *
              rtb_Integrator[1] * -64.91) - -0.805 * fabs(rtb_Integrator[2]);
  tmp_5[7] = ((7.25 - -3.45 * fabs(rtb_Integrator[2])) - rtb_Integrator[2] *
              rtb_Integrator[2] * 0.0) - -0.845 * fabs(rtb_Integrator[1]);
  tmp_5[2] = 0.0;
  tmp_5[5] = ((-0.0 - -0.2088 * rtb_Integrator[1]) - rtb_Integrator[1] *
              rtb_Integrator[1] * 0.0) - 0.13 * fabs(rtb_Integrator[2]);
  tmp_5[8] = ((1.9 - -0.75 * fabs(rtb_Integrator[2])) - rtb_Integrator[2] *
              rtb_Integrator[2] * 0.0) - 0.08 * fabs(rtb_Integrator[1]);
  for (i = 0; i < 3; i++) {
    tmp_1[i] = tmp_5[i + 6] * rtb_Integrator[2] + (tmp_5[i + 3] *
      rtb_Integrator[1] + tmp_5[i] * rtb_Integrator[0]);
  }

  ctrl_student_HIL_B.nu_dot[0] = ctrl_student_HIL_B.tauAct[0] - tmp_1[0];
  ctrl_student_HIL_B.nu_dot[1] = (ctrl_student_HIL_B.tauAct[1] - tmp_1[1]) -
    ctrl_student_HIL_B.nu_dot[0] * 0.0;
  ctrl_student_HIL_B.nu_dot[2] = ((ctrl_student_HIL_B.tauAct[2] - tmp_1[2]) -
    ctrl_student_HIL_B.nu_dot[0] * 0.0) - ctrl_student_HIL_B.nu_dot[1] *
    0.026721040528887609;
  ctrl_student_HIL_B.nu_dot[2] /= 2.7351594526983325;
  ctrl_student_HIL_B.nu_dot[0] -= ctrl_student_HIL_B.nu_dot[2] * 0.0;
  ctrl_student_HIL_B.nu_dot[1] -= ctrl_student_HIL_B.nu_dot[2] *
    0.92962499999999992;
  ctrl_student_HIL_B.nu_dot[1] /= 34.79;
  ctrl_student_HIL_B.nu_dot[0] -= ctrl_student_HIL_B.nu_dot[1] * 0.0;
  ctrl_student_HIL_B.nu_dot[0] /= 26.79;

  /* End of MATLAB Function: '<S14>/kinetics' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* MATLAB Function: '<S17>/Full thrust allocation' incorporates:
     *  Constant: '<S17>/Constant'
     */
    /* MATLAB Function 'tau to real ship (only use in MCLab)/Full thrust allocation': '<S91>:1' */
    /*  Forces and moments vector */
    /* '<S91>:1:4' */
    /*  Extended thrust configuration matrix */
    /*  Extended thrust coefficient matrix */
    /*  tau = T*K*u inverse */
    /* '<S91>:1:23' */
    tmp_0[0] = 0.0;
    tmp_0[1] = 0.0;
    tmp_0[2] = 0.0;
    ctrl_student_HIL_mldivide(c, tmp_0, tmp_1);
    ctrl_student_HIL_mldivide(b, tmp_1, rtb_eta_ds);

    /* '<S91>:1:25' */
    /* '<S91>:1:27' */
    /* '<S91>:1:28' */
    /* '<S91>:1:29' */
    /* '<S91>:1:30' */
    if (ctrl_student_HIL_P.Constant_Value_b != 0.0) {
      /* '<S91>:1:33' */
      ctrl_student_HIL_B.omega_VSP = 0.3;
    } else {
      /* '<S91>:1:35' */
      ctrl_student_HIL_B.omega_VSP = 0.0;
    }

    ctrl_student_HIL_B.u_BT = rtb_eta_ds[2];
    ctrl_student_HIL_B.u_VSP = sqrt(rtb_eta_ds[0] * rtb_eta_ds[0] + rtb_eta_ds[1]
      * rtb_eta_ds[1]);
    ctrl_student_HIL_B.alpha_VSP = rt_atan2d_snf(rtb_eta_ds[1], rtb_eta_ds[0]);

    /* End of MATLAB Function: '<S17>/Full thrust allocation' */

    /* MATLAB Function: '<S93>/control limit checking' incorporates:
     *  SignalConversion: '<S94>/TmpSignal ConversionAt SFunction Inport1'
     */
    /* MATLAB Function 'tau to real ship (only use in MCLab)/To thruster of real ship/control limit checking': '<S94>:1' */
    /* '<S94>:1:2' */
    /* '<S94>:1:3' */
    /* '<S94>:1:4' */
    /* '<S94>:1:5' */
    /* '<S94>:1:6' */
    /* '<S94>:1:7' */
    /* '<S94>:1:8' */
    /* '<S94>:1:10' */
    /* '<S94>:1:18' */
    ctrl_student_HIL_B.fault = !((-1.0 <= ctrl_student_HIL_B.u_BT) &&
      (ctrl_student_HIL_B.u_BT <= 1.0) && (0.0 <= ctrl_student_HIL_B.u_VSP) &&
      (ctrl_student_HIL_B.u_VSP <= 1.0) && (0.0 <= ctrl_student_HIL_B.u_VSP) &&
      (ctrl_student_HIL_B.u_VSP <= 1.0) && (-3.1415926535897931 <=
      ctrl_student_HIL_B.alpha_VSP) && (ctrl_student_HIL_B.alpha_VSP <=
      3.1415926535897931) && (-3.1415926535897931 <=
      ctrl_student_HIL_B.alpha_VSP) && (ctrl_student_HIL_B.alpha_VSP <=
      3.1415926535897931) && (-1.0 <= ctrl_student_HIL_B.omega_VSP) &&
      (ctrl_student_HIL_B.omega_VSP <= 1.0) && (-1.0 <=
      ctrl_student_HIL_B.omega_VSP) && (ctrl_student_HIL_B.omega_VSP <= 1.0));
  }
}

/* Model update function */
void ctrl_student_HIL_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S7>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput = ctrl_student_HIL_B.deg_out;
  }

  /* Update for Integrator: '<S65>/etaHat1' */
  ctrl_student_HIL_DW.etaHat1_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S68>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_B.count;

    /* Update for RandomNumber: '<S74>/White Noise' */
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S75>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_j) * ctrl_student_HIL_P.WhiteNoise_StdDev_d
      + ctrl_student_HIL_P.WhiteNoise_Mean_h;

    /* Update for RandomNumber: '<S73>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_c) * ctrl_student_HIL_P.WhiteNoise_StdDev_g
      + ctrl_student_HIL_P.WhiteNoise_Mean_f;

    /* Update for Memory: '<S69>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_B.output[0];
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_B.output[1];
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_B.output[2];

    /* Update for Memory: '<S36>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_f = ctrl_student_HIL_B.Switch_d;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S37>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_m = ctrl_student_HIL_B.SwitchSignal;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S49>/Memory2' */
    ctrl_student_HIL_DW.Memory2_PreviousInput = ctrl_student_HIL_B.N;

    /* Update for Memory: '<S49>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput[0] = ctrl_student_HIL_B.init_time
      [0];
    ctrl_student_HIL_DW.Memory1_PreviousInput[1] = ctrl_student_HIL_B.init_time
      [1];

    /* Update for Memory: '<S10>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_d[0] = ctrl_student_HIL_B.posOut[0];
    ctrl_student_HIL_DW.Memory_PreviousInput_d[1] = ctrl_student_HIL_B.posOut[1];
    ctrl_student_HIL_DW.Memory_PreviousInput_d[2] = ctrl_student_HIL_B.posOut[2];
  }

  /* Update for Integrator: '<S14>/Integrator1' */
  ctrl_student_HIL_DW.Integrator1_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S15>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_e = ctrl_student_HIL_B.kill_signal;

    /* Update for Memory: '<S49>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_p = ctrl_student_HIL_B.N_out;
  }

  /* Update for Integrator: '<S14>/Integrator' */
  ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_student_HIL_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_student_HIL_M->Timing.clockTick0)) {
    ++ctrl_student_HIL_M->Timing.clockTickH0;
  }

  ctrl_student_HIL_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ctrl_student_HIL_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_student_HIL_M->Timing.clockTick1)) {
      ++ctrl_student_HIL_M->Timing.clockTickH1;
    }

    ctrl_student_HIL_M->Timing.t[1] = ctrl_student_HIL_M->Timing.clockTick1 *
      ctrl_student_HIL_M->Timing.stepSize1 +
      ctrl_student_HIL_M->Timing.clockTickH1 *
      ctrl_student_HIL_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_student_HIL_derivatives(void)
{
  XDot_ctrl_student_HIL_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S60>/etaHat' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->etaHat_CSTATE = ctrl_student_HIL_B.etaHatDot[0];
  }

  /* Derivatives for Integrator: '<S60>/etaHat2' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->etaHat2_CSTATE = ctrl_student_HIL_B.etaHatDot[1];
  }

  /* Derivatives for Integrator: '<S65>/etaHat1' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->etaHat1_CSTATE = ctrl_student_HIL_B.etaHatDot[2];
  }

  /* Derivatives for Integrator: '<S40>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE = ctrl_student_HIL_B.s_dot_l;
  }

  /* Derivatives for Integrator: '<S47>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_f = ctrl_student_HIL_B.s_dot;
  }

  /* Derivatives for Integrator: '<S58>/nuHat' */
  _rtXdot->nuHat_CSTATE[0] = ctrl_student_HIL_B.IC_i[0];
  _rtXdot->nuHat_CSTATE[1] = ctrl_student_HIL_B.IC_i[1];
  _rtXdot->nuHat_CSTATE[2] = ctrl_student_HIL_B.IC_i[2];

  /* Derivatives for Integrator: '<S14>/Integrator1' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE[0] = ctrl_student_HIL_B.eta_dot[0];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE[1] = ctrl_student_HIL_B.eta_dot[1];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE[2] = ctrl_student_HIL_B.eta_dot[2];
  }

  /* Derivatives for Integrator: '<S56>/bHat' */
  _rtXdot->bHat_CSTATE[0] = ctrl_student_HIL_B.bHatDot[0];
  _rtXdot->bHat_CSTATE[1] = ctrl_student_HIL_B.bHatDot[1];
  _rtXdot->bHat_CSTATE[2] = ctrl_student_HIL_B.bHatDot[2];

  /* Derivatives for Integrator: '<S14>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_b[0] = ctrl_student_HIL_B.nu_dot[0];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_b[1] = ctrl_student_HIL_B.nu_dot[1];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_b[2] = ctrl_student_HIL_B.nu_dot[2];
  }
}

/* Model initialize function */
void ctrl_student_HIL_initialize(void)
{
  /* Start for InitialCondition: '<S36>/IC' */
  ctrl_student_HIL_B.IC = ctrl_student_HIL_P.IC_Value;
  ctrl_student_HIL_DW.IC_FirstOutputTime = (rtMinusInf);

  /* Start for InitialCondition: '<S37>/IC' */
  ctrl_student_HIL_B.IC_n = ctrl_student_HIL_P.IC_Value_e;
  ctrl_student_HIL_DW.IC_FirstOutputTime_p = (rtMinusInf);

  /* Start for ToWorkspace: '<S1>/To Workspace3' */
  {
    int_T dimensions[2] = { 2, 1 };

    ctrl_student_HIL_DW.ToWorkspace3_PWORK.LoggedData = rt_CreateLogVar(
      ctrl_student_HIL_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(ctrl_student_HIL_M),
      ctrl_student_HIL_M->Timing.stepSize0,
      (&rtmGetErrorStatus(ctrl_student_HIL_M)),
      "pd_data",
      SS_DOUBLE,
      0,
      0,
      0,
      2,
      2,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.01,
      1);
    if (ctrl_student_HIL_DW.ToWorkspace3_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for InitialCondition: '<S56>/IC1' */
  ctrl_student_HIL_B.IC1[0] = ctrl_student_HIL_P.IC1_Value[0];
  ctrl_student_HIL_B.IC1[1] = ctrl_student_HIL_P.IC1_Value[1];
  ctrl_student_HIL_B.IC1[2] = ctrl_student_HIL_P.IC1_Value[2];
  ctrl_student_HIL_DW.IC1_FirstOutputTime = (rtMinusInf);

  /* Start for InitialCondition: '<S58>/IC' */
  ctrl_student_HIL_DW.IC_FirstOutputTime_n = (rtMinusInf);
  ctrl_student_HIL_PrevZCX.etaHat_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.etaHat2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.etaHat1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_c = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_p = UNINITIALIZED_ZCSIG;

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Integrator: '<S60>/etaHat' */
    ctrl_student_HIL_X.etaHat_CSTATE = ctrl_student_HIL_P.etaHat_IC;

    /* InitializeConditions for Integrator: '<S60>/etaHat2' */
    ctrl_student_HIL_X.etaHat2_CSTATE = ctrl_student_HIL_P.etaHat2_IC;

    /* InitializeConditions for Memory: '<S7>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput = ctrl_student_HIL_P.Memory_X0;

    /* InitializeConditions for Integrator: '<S65>/etaHat1' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      ctrl_student_HIL_X.etaHat1_CSTATE = 0.0;
    }

    ctrl_student_HIL_DW.etaHat1_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Memory: '<S68>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S74>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed = tseed;
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S74>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S75>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed_b);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed_j = tseed;
    ctrl_student_HIL_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_j) * ctrl_student_HIL_P.WhiteNoise_StdDev_d
      + ctrl_student_HIL_P.WhiteNoise_Mean_h;

    /* End of InitializeConditions for RandomNumber: '<S75>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S73>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed_l);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed_c = tseed;
    ctrl_student_HIL_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_c) * ctrl_student_HIL_P.WhiteNoise_StdDev_g
      + ctrl_student_HIL_P.WhiteNoise_Mean_f;

    /* End of InitializeConditions for RandomNumber: '<S73>/White Noise' */

    /* InitializeConditions for Memory: '<S69>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_P.Hold_X0;

    /* InitializeConditions for Memory: '<S36>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_f = ctrl_student_HIL_P.Memory_X0_n;

    /* InitializeConditions for Integrator: '<S40>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE = ctrl_student_HIL_P.Integrator_IC;

    /* InitializeConditions for Memory: '<S37>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_m = ctrl_student_HIL_P.Memory_X0_l;

    /* InitializeConditions for Integrator: '<S47>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE_f = ctrl_student_HIL_P.Integrator_IC_p;

    /* InitializeConditions for Memory: '<S49>/Memory2' */
    ctrl_student_HIL_DW.Memory2_PreviousInput = ctrl_student_HIL_P.Memory2_X0;

    /* InitializeConditions for Memory: '<S49>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput[0] =
      ctrl_student_HIL_P.Memory1_X0[0];
    ctrl_student_HIL_DW.Memory1_PreviousInput[1] =
      ctrl_student_HIL_P.Memory1_X0[1];

    /* InitializeConditions for Integrator: '<S58>/nuHat' */
    ctrl_student_HIL_X.nuHat_CSTATE[0] = ctrl_student_HIL_P.nuHat_IC[0];
    ctrl_student_HIL_X.nuHat_CSTATE[1] = ctrl_student_HIL_P.nuHat_IC[1];
    ctrl_student_HIL_X.nuHat_CSTATE[2] = ctrl_student_HIL_P.nuHat_IC[2];

    /* InitializeConditions for Memory: '<S10>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_d[0] =
      ctrl_student_HIL_P.Memory_X0_n2;
    ctrl_student_HIL_DW.Memory_PreviousInput_d[1] =
      ctrl_student_HIL_P.Memory_X0_n2;
    ctrl_student_HIL_DW.Memory_PreviousInput_d[2] =
      ctrl_student_HIL_P.Memory_X0_n2;

    /* InitializeConditions for Integrator: '<S14>/Integrator1' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      ctrl_student_HIL_X.Integrator1_CSTATE[0] = 0.0;
      ctrl_student_HIL_X.Integrator1_CSTATE[1] = 0.0;
      ctrl_student_HIL_X.Integrator1_CSTATE[2] = 0.0;
    }

    ctrl_student_HIL_DW.Integrator1_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Memory: '<S15>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_e = ctrl_student_HIL_P.Memory_X0_i;

    /* InitializeConditions for Memory: '<S49>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_p = ctrl_student_HIL_P.Memory_X0_j;

    /* InitializeConditions for Integrator: '<S56>/bHat' */
    ctrl_student_HIL_X.bHat_CSTATE[0] = ctrl_student_HIL_P.bHat_IC;
    ctrl_student_HIL_X.bHat_CSTATE[1] = ctrl_student_HIL_P.bHat_IC;
    ctrl_student_HIL_X.bHat_CSTATE[2] = ctrl_student_HIL_P.bHat_IC;

    /* InitializeConditions for Integrator: '<S14>/Integrator' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      ctrl_student_HIL_X.Integrator_CSTATE_b[0] = 0.0;
      ctrl_student_HIL_X.Integrator_CSTATE_b[1] = 0.0;
      ctrl_student_HIL_X.Integrator_CSTATE_b[2] = 0.0;
    }

    ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading = 1;

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      rtmSetFirstInitCond(ctrl_student_HIL_M, 0);
    }
  }
}

/* Model terminate function */
void ctrl_student_HIL_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ctrl_student_HIL_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_student_HIL_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ctrl_student_HIL_initialize();
}

void MdlTerminate(void)
{
  ctrl_student_HIL_terminate();
}

/* Registration function */
RT_MODEL_ctrl_student_HIL_T *ctrl_student_HIL(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_student_HIL_M, 0,
                sizeof(RT_MODEL_ctrl_student_HIL_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_student_HIL_M->solverInfo,
                          &ctrl_student_HIL_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_student_HIL_M->solverInfo, &rtmGetTPtr(ctrl_student_HIL_M));
    rtsiSetStepSizePtr(&ctrl_student_HIL_M->solverInfo,
                       &ctrl_student_HIL_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_student_HIL_M->solverInfo,
                 &ctrl_student_HIL_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_student_HIL_M->solverInfo, (real_T **)
                         &ctrl_student_HIL_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_student_HIL_M->solverInfo,
      &ctrl_student_HIL_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_student_HIL_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_student_HIL_M)));
    rtsiSetRTModelPtr(&ctrl_student_HIL_M->solverInfo, ctrl_student_HIL_M);
  }

  rtsiSetSimTimeStep(&ctrl_student_HIL_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_student_HIL_M->ModelData.intgData.y = ctrl_student_HIL_M->ModelData.odeY;
  ctrl_student_HIL_M->ModelData.intgData.f[0] =
    ctrl_student_HIL_M->ModelData.odeF[0];
  ctrl_student_HIL_M->ModelData.intgData.f[1] =
    ctrl_student_HIL_M->ModelData.odeF[1];
  ctrl_student_HIL_M->ModelData.intgData.f[2] =
    ctrl_student_HIL_M->ModelData.odeF[2];
  ctrl_student_HIL_M->ModelData.contStates = ((real_T *) &ctrl_student_HIL_X);
  rtsiSetSolverData(&ctrl_student_HIL_M->solverInfo, (void *)
                    &ctrl_student_HIL_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_student_HIL_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_student_HIL_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_student_HIL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_student_HIL_M->Timing.sampleTimes =
      (&ctrl_student_HIL_M->Timing.sampleTimesArray[0]);
    ctrl_student_HIL_M->Timing.offsetTimes =
      (&ctrl_student_HIL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_student_HIL_M->Timing.sampleTimes[0] = (0.0);
    ctrl_student_HIL_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_student_HIL_M->Timing.offsetTimes[0] = (0.0);
    ctrl_student_HIL_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_student_HIL_M, &ctrl_student_HIL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_student_HIL_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_student_HIL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_student_HIL_M, -1);
  ctrl_student_HIL_M->Timing.stepSize0 = 0.01;
  ctrl_student_HIL_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_student_HIL_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_student_HIL_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_student_HIL_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_student_HIL_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_student_HIL_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_student_HIL_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_student_HIL_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_student_HIL_M->rtwLogInfo, (NULL));
  }

  ctrl_student_HIL_M->solverInfoPtr = (&ctrl_student_HIL_M->solverInfo);
  ctrl_student_HIL_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_student_HIL_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_student_HIL_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_student_HIL_M->ModelData.blockIO = ((void *) &ctrl_student_HIL_B);
  (void) memset(((void *) &ctrl_student_HIL_B), 0,
                sizeof(B_ctrl_student_HIL_T));

  /* parameters */
  ctrl_student_HIL_M->ModelData.defaultParam = ((real_T *)&ctrl_student_HIL_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_student_HIL_X;
    ctrl_student_HIL_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_student_HIL_X, 0,
                  sizeof(X_ctrl_student_HIL_T));
  }

  /* states (dwork) */
  ctrl_student_HIL_M->ModelData.dwork = ((void *) &ctrl_student_HIL_DW);
  (void) memset((void *)&ctrl_student_HIL_DW, 0,
                sizeof(DW_ctrl_student_HIL_T));

  /* Initialize Sizes */
  ctrl_student_HIL_M->Sizes.numContStates = (17);/* Number of continuous states */
  ctrl_student_HIL_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_M->Sizes.numBlocks = (343);/* Number of blocks */
  ctrl_student_HIL_M->Sizes.numBlockIO = (123);/* Number of block outputs */
  ctrl_student_HIL_M->Sizes.numBlockPrms = (639);/* Sum of parameter "widths" */
  return ctrl_student_HIL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================*
 * This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_student_HIL
#include "model_info.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;
double NIRT_GetValueByDataType(void* ptr,int subindex, int type, int Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 46:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 47:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

long NIRT_SetValueByDataType(void* ptr,int subindex, double value, int type, int
  Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 17:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 31:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 32:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 46:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 47:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_student_HIL_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // from enterprise/X_ship
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.X_ship, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // from enterprise/Y_ship
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Y_ship, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // from enterprise/PSI_ship
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PSI_ship, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // from enterprise/res_ship
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.res_ship, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // dropOutTolerance
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.dropOutTolerance, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // NoisePowPos
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.NoisePowPos, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // NoisePowHead
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.NoisePowHead, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // NoiseEnable
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.NoiseEnable, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ControllerGainK2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ControllerGainK2, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // ControllerGainK1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ControllerGainK1, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/Select
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Select, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosXRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/PosYRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosYRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/R2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.R2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosXLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosYLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/R1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.R1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowDown
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowDown, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/ArrowUp
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowUp, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowLeft, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/ArrowRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // JoysticControllerSwitch
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.JoysticControllerSwitch, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // sf1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.sf1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // SZ_ResetKill
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.SZ_ResetKill, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // SZ_Owerwrite
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.SZ_Owerwrite, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // sf2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.sf2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // sf3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.sf3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // biasOffset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.biasOffset, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/TurnOffomega1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.TurnOffomega1, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/TurnOffomega2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.TurnOffomega2, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // from model/y_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // from model/psi_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.psi_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // from model/u_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.u_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // from model/x_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // from model/r_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.r_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // from model/v_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.v_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 39;
}

double ni_extout[53];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // eta_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp,0,18,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp,1,18,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp,2,18,0);
  } else {
    index += 3;
  }

  // Residual: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAtResidualIn,0,22,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAtResidualIn,1,22,0);
  } else {
    index += 2;
  }

  // eta_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,18,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,1,18,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,2,18,0);
  } else {
    index += 3;
  }

  // eta_noise: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,0,17,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,1,17,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,2,17,
      0);
  } else {
    index += 3;
  }

  // joystick/Current Mode : Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Select,0,0,
      0);
  } else {
    index += 1;
  }

  // joystick/tau_yaw: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau_yaw,0,0,
      0);
  } else {
    index += 1;
  }

  // joystick/tau_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau_surge,0,
      0,0);
  } else {
    index += 1;
  }

  // joystick/tau_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau_sway,0,
      0,0);
  } else {
    index += 1;
  }

  // Tau_pre: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch2_g,0,
      18,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch2_g,1,
      18,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch2_g,2,
      18,0);
  } else {
    index += 3;
  }

  // Tau_post: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,0,17,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,1,17,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,2,17,
      0);
  } else {
    index += 3;
  }

  // P_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,0,
      20,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,1,
      20,0);
  } else {
    index += 2;
  }

  // dropoutFlag: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.dropout,0,0,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,0,17,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,2,17,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,1,17,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_P.eta_dot_ini,
      2,17,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_P.eta_dot_ini,
      0,17,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_P.eta_dot_ini,
      1,17,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.reset,0,0,0);
  } else {
    index += 1;
  }

  // Position/eta_real: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_realIn,0,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_realIn,1,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_realIn,2,17,0);
  } else {
    index += 3;
  }

  // ThrustAllocationAndSaturation/u_BT: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant2_Value_o,0,0,0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_vsp1,0,0,
      0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_vsp2,0,0,
      0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha1,0,0,
      0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha2,0,0,
      0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_b,0,
      0,0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1,0,0,
      0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/f_bt: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant3_Value_i,0,0,0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/f_vspx: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum_n,0,0,0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/ f_vspy: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1_n,0,0,
      0);
  } else {
    index += 1;
  }

  // from model/u_real  : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_in,0,0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/control input u exceeds bounds: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.fault,0,8,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_BT: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_BT,0,0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 53;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // eta_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp,0,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp,1,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_hatInp,2,18,0);

  // Residual: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAtResidualIn,0,22,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAtResidualIn,1,22,0);

  // eta_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,1,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,2,18,0);

  // eta_noise: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,0,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,1,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,2,17,0);

  // joystick/Current Mode : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Select,0,0,0);

  // joystick/tau_yaw: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau_yaw,0,0,0);

  // joystick/tau_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau_surge,0,0,
    0);

  // joystick/tau_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau_sway,0,0,
    0);

  // Tau_pre: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch2_g,0,
    18,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch2_g,1,
    18,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch2_g,2,
    18,0);

  // Tau_post: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,0,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,1,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,2,17,0);

  // P_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,0,20,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,1,20,
    0);

  // dropoutFlag: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.dropout,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,0,17,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,2,17,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,1,17,0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_P.eta_dot_ini,2,
    17,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_P.eta_dot_ini,0,
    17,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_P.eta_dot_ini,1,
    17,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.reset,0,0,0);

  // Position/eta_real: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_realIn,0,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_realIn,1,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_realIn,2,17,0);

  // ThrustAllocationAndSaturation/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant2_Value_o,0,0,0);

  // ThrustAllocationAndSaturation/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_vsp1,0,0,0);

  // ThrustAllocationAndSaturation/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_vsp2,0,0,0);

  // ThrustAllocationAndSaturation/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha1,0,0,0);

  // ThrustAllocationAndSaturation/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha2,0,0,0);

  // ThrustAllocationAndSaturation/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_b,0,0,
    0);

  // ThrustAllocationAndSaturation/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1,0,0,0);

  // ThrustAllocationAndSaturation/f_bt: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant3_Value_i,0,0,0);

  // ThrustAllocationAndSaturation/f_vspx: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum_n,0,0,0);

  // ThrustAllocationAndSaturation/ f_vspy: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1_n,0,0,0);

  // from model/u_real  : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_in,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/control input u exceeds bounds: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.fault,0,8,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_VSP,0,0,
    0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_VSP,0,0,
    0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,0,
    0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,0,
    0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_BT,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/SwitchSignalFromFile/Value",
    offsetof(P_ctrl_student_HIL_T, DesiredPath), 46, 1, 2, 0, 0 },

  { 1,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization /Elipscenter_radi/Value",
    offsetof(P_ctrl_student_HIL_T, Elipscenter_radi), 23, 4, 2, 2, 0 },

  { 2, "ctrl_student_hil/K/Value", offsetof(P_ctrl_student_HIL_T, K), 20, 2, 2,
    4, 0 },

  { 3, "ctrl_student_hil/ControllerGain/Constant1/Value", offsetof
    (P_ctrl_student_HIL_T, K1), 19, 9, 2, 6, 0 },

  { 4,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Kp/Value",
    offsetof(P_ctrl_student_HIL_T, K1), 19, 9, 2, 8, 0 },

  { 5, "ctrl_student_hil/ControllerGain/Constant2/Value", offsetof
    (P_ctrl_student_HIL_T, K2), 19, 9, 2, 10, 0 },

  { 6,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/TASK/Value",
    offsetof(P_ctrl_student_HIL_T, LAW), 46, 1, 2, 12, 0 },

  { 7,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/TASK/Value",
    offsetof(P_ctrl_student_HIL_T, LAW), 46, 1, 2, 14, 0 },

  { 8,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, T_initialDP), 46, 1, 2, 16, 0 },

  { 9,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Check_s/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, U_ref), 46, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, U_ref), 46, 1, 2, 20, 0 },

  { 11,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, eta_dot_ini), 18, 3, 2, 22, 0 },

  { 12, "ctrl_student_hil/ObserverGain/Constant1/Value", offsetof
    (P_ctrl_student_HIL_T, l1), 19, 9, 2, 24, 0 },

  { 13, "ctrl_student_hil/ObserverGain/Constant2/Value", offsetof
    (P_ctrl_student_HIL_T, l2), 19, 9, 2, 26, 0 },

  { 14, "ctrl_student_hil/ObserverGain/Constant3/Value", offsetof
    (P_ctrl_student_HIL_T, l3), 19, 9, 2, 28, 0 },

  { 15, "ctrl_student_hil/Lim/Value", offsetof(P_ctrl_student_HIL_T, lim), 27, 4,
    2, 30, 0 },

  { 16, "ctrl_student_hil/Lim2/Value", offsetof(P_ctrl_student_HIL_T, lim_2), 27,
    4, 2, 32, 0 },

  { 17,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, m), 46, 1, 2, 34, 0 },

  { 18,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/mu/Value",
    offsetof(P_ctrl_student_HIL_T, mu), 46, 1, 2, 36, 0 },

  { 19,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/mu/Value",
    offsetof(P_ctrl_student_HIL_T, mu), 46, 1, 2, 38, 0 },

  { 20,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Desired Position/Value",
    offsetof(P_ctrl_student_HIL_T, pd), 23, 4, 2, 40, 0 },

  { 21, "ctrl_student_hil/ThrustAllocationAndSaturation/Ramp/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Ramp_X0), 46, 1, 2, 42, 0 },

  { 22, "ctrl_student_hil/ThrustAllocationAndSaturation/Ramp/Step/After",
    offsetof(P_ctrl_student_HIL_T, Ramp_slope), 46, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil/ThrustAllocationAndSaturation/Ramp/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Ramp_start), 46, 1, 2, 46, 0 },

  { 24, "ctrl_student_hil/ThrustAllocationAndSaturation/Ramp/Step/Time",
    offsetof(P_ctrl_student_HIL_T, Ramp_start), 46, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil/safety zone /Switch1/Threshold", offsetof
    (P_ctrl_student_HIL_T, Switch1_Threshold), 46, 1, 2, 50, 0 },

  { 26, "ctrl_student_hil/DPObserver1/etaHat/etaHat/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, etaHat_IC), 46, 1, 2, 52, 0 },

  { 27, "ctrl_student_hil/DPObserver1/etaHat/etaHat2/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, etaHat2_IC), 46, 1, 2, 54, 0 },

  { 28, "ctrl_student_hil/Position/Memory/X0", offsetof(P_ctrl_student_HIL_T,
    Memory_X0), 46, 1, 2, 56, 0 },

  { 29, "ctrl_student_hil/DPObserver1/etaHat/Subsystem/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value), 46, 1, 2, 58, 0 },

  { 30, "ctrl_student_hil/DPObserver1/etaHat/Subsystem/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value), 46, 1, 2, 60, 0 },

  { 31, "ctrl_student_hil/DPObserver1/etaHat/Subsystem/Switch3/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch3_Threshold), 46, 1, 2, 62, 0 },

  { 32, "ctrl_student_hil/Position/Gain/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain_Gain), 46, 1, 2, 64, 0 },

  { 33, "ctrl_student_hil/Position/Gain1/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain1_Gain), 46, 1, 2, 66, 0 },

  { 34, "ctrl_student_hil/Noise generator/Step size/Value", offsetof
    (P_ctrl_student_HIL_T, Stepsize_Value), 46, 1, 2, 68, 0 },

  { 35, "ctrl_student_hil/Noise generator/Downsamplesignal/counter/X0", offsetof
    (P_ctrl_student_HIL_T, counter_X0), 46, 1, 2, 70, 0 },

  { 36, "ctrl_student_hil/Constant/Value", offsetof(P_ctrl_student_HIL_T,
    Constant_Value_d), 46, 1, 2, 72, 0 },

  { 37,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean), 46, 1, 2, 74, 0 },

  { 38,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev), 46, 1, 2, 76, 0 },

  { 39,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed), 46, 1, 2, 78, 0 },

  { 40,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_h), 46, 1, 2, 80, 0 },

  { 41,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_d), 46, 1, 2, 82, 0 },

  { 42,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_b), 46, 1, 2, 84, 0 },

  { 43,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_f), 46, 1, 2, 86, 0 },

  { 44,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_g), 46, 1, 2, 88, 0 },

  { 45,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_l), 46, 1, 2, 90, 0 },

  { 46, "ctrl_student_hil/Noise generator/Sample & hold/Hold/X0", offsetof
    (P_ctrl_student_HIL_T, Hold_X0), 46, 1, 2, 92, 0 },

  { 47,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain/Gain",
    offsetof(P_ctrl_student_HIL_T, Gain_Gain_p), 46, 1, 2, 94, 0 },

  { 48,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Memory/X0",
    offsetof(P_ctrl_student_HIL_T, Memory_X0_n), 46, 1, 2, 96, 0 },

  { 49,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/Integrator/InitialCondition",
    offsetof(P_ctrl_student_HIL_T, Integrator_IC), 46, 1, 2, 98, 0 },

  { 50,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/IC/Value",
    offsetof(P_ctrl_student_HIL_T, IC_Value), 46, 1, 2, 100, 0 },

  { 51,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Memory/X0",
    offsetof(P_ctrl_student_HIL_T, Memory_X0_l), 46, 1, 2, 102, 0 },

  { 52,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/Integrator/InitialCondition",
    offsetof(P_ctrl_student_HIL_T, Integrator_IC_p), 46, 1, 2, 104, 0 },

  { 53,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Memory2/X0",
    offsetof(P_ctrl_student_HIL_T, Memory2_X0), 46, 1, 2, 106, 0 },

  { 54,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Memory1/X0",
    offsetof(P_ctrl_student_HIL_T, Memory1_X0), 32, 2, 2, 108, 0 },

  { 55,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch_Threshold), 46, 1, 2, 110, 0 },

  { 56,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Eta_ds/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_k), 46, 1, 2, 112, 0 },

  { 57,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Eta_ds/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value_g), 46, 1, 2, 114, 0 },

  { 58,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch3/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch3_Threshold_e), 46, 1, 2, 116, 0 },

  { 59,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Gain/Gain",
    offsetof(P_ctrl_student_HIL_T, Gain_Gain_a), 46, 1, 2, 118, 0 },

  { 60,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/IC/Value",
    offsetof(P_ctrl_student_HIL_T, IC_Value_e), 46, 1, 2, 120, 0 },

  { 61,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch4/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch4_Threshold), 46, 1, 2, 122, 0 },

  { 62, "ctrl_student_hil/DPObserver1/Subsystem/nuHat/InitialCondition",
    offsetof(P_ctrl_student_HIL_T, nuHat_IC), 18, 3, 2, 124, 0 },

  { 63,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch5/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch5_Threshold), 46, 1, 2, 126, 0 },

  { 64,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_o), 46, 1, 2, 128, 0 },

  { 65,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value_l), 46, 1, 2, 130, 0 },

  { 66,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value), 46, 1, 2, 132, 0 },

  { 67,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch6/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch6_Threshold), 46, 1, 2, 134, 0 },

  { 68,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Constant3/Value",
    offsetof(P_ctrl_student_HIL_T, Constant3_Value), 46, 1, 2, 136, 0 },

  { 69,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch7/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch7_Threshold), 46, 1, 2, 138, 0 },

  { 70,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value_d), 46, 1, 2, 140, 0 },

  { 71,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_dg), 18, 3, 2, 142, 0 },

  { 72,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Switch2/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch2_Threshold), 46, 1, 2, 144, 0 },

  { 73, "ctrl_student_hil/joystick/Max_Global_Forces/Value", offsetof
    (P_ctrl_student_HIL_T, Max_Global_Forces_Value), 33, 4, 2, 146, 0 },

  { 74, "ctrl_student_hil/joystick/Dead Zone/LowerValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone_Start), 46, 1, 2, 148, 0 },

  { 75, "ctrl_student_hil/joystick/Dead Zone/UpperValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone_End), 46, 1, 2, 150, 0 },

  { 76, "ctrl_student_hil/joystick/Dead Zone1/LowerValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone1_Start), 46, 1, 2, 152, 0 },

  { 77, "ctrl_student_hil/joystick/Dead Zone1/UpperValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone1_End), 46, 1, 2, 154, 0 },

  { 78, "ctrl_student_hil/joystick/Gain/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain_Gain_ps), 46, 1, 2, 156, 0 },

  { 79, "ctrl_student_hil/joystick/Dead Zone2/LowerValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone2_Start), 46, 1, 2, 158, 0 },

  { 80, "ctrl_student_hil/joystick/Dead Zone2/UpperValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone2_End), 46, 1, 2, 160, 0 },

  { 81, "ctrl_student_hil/Switch2/Threshold", offsetof(P_ctrl_student_HIL_T,
    Switch2_Threshold_i), 46, 1, 2, 162, 0 },

  { 82, "ctrl_student_hil/dropoutdet/Memory/X0", offsetof(P_ctrl_student_HIL_T,
    Memory_X0_n2), 46, 1, 2, 164, 0 },

  { 83, "ctrl_student_hil/Switch3/Threshold", offsetof(P_ctrl_student_HIL_T,
    Switch3_Threshold_a), 46, 1, 2, 166, 0 },

  { 84, "ctrl_student_hil/safety zone /Switch/Threshold", offsetof
    (P_ctrl_student_HIL_T, Switch_Threshold_n), 46, 1, 2, 168, 0 },

  { 85, "ctrl_student_hil/safety zone /Memory/X0", offsetof(P_ctrl_student_HIL_T,
    Memory_X0_i), 46, 1, 2, 170, 0 },

  { 86, "ctrl_student_hil/safety zone /Switch2/Threshold", offsetof
    (P_ctrl_student_HIL_T, Switch2_Threshold_p), 46, 1, 2, 172, 0 },

  { 87, "ctrl_student_hil/Constant1/Value", offsetof(P_ctrl_student_HIL_T,
    Constant1_Value_i), 46, 1, 2, 174, 0 },

  { 88, "ctrl_student_hil/Switch1/Threshold", offsetof(P_ctrl_student_HIL_T,
    Switch1_Threshold_l), 46, 1, 2, 176, 0 },

  { 89,
    "ctrl_student_hil/ThrustAllocationAndSaturation/Actuator_Sat_Forces/Value",
    offsetof(P_ctrl_student_HIL_T, Actuator_Sat_Forces_Value), 32, 2, 2, 178, 0
  },

  { 90,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Memory/X0",
    offsetof(P_ctrl_student_HIL_T, Memory_X0_j), 46, 1, 2, 180, 0 },

  { 91, "ctrl_student_hil/DPObserver1/Bias/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_e), 18, 3, 2, 182, 0 },

  { 92, "ctrl_student_hil/DPObserver1/Bias/bHat/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, bHat_IC), 46, 1, 2, 184, 0 },

  { 93, "ctrl_student_hil/DPObserver1/Bias/IC1/Value", offsetof
    (P_ctrl_student_HIL_T, IC1_Value), 18, 3, 2, 186, 0 },

  { 94, "ctrl_student_hil/DPObserver1/Subsystem/IC/Value", offsetof
    (P_ctrl_student_HIL_T, IC_Value_f), 18, 3, 2, 188, 0 },

  { 95, "ctrl_student_hil/ThrustAllocationAndSaturation/Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value_o), 46, 1, 2, 190, 0 },

  { 96, "ctrl_student_hil/ThrustAllocationAndSaturation/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_ks), 46, 1, 2, 192, 0 },

  { 97, "ctrl_student_hil/ThrustAllocationAndSaturation/Ramp/Step/Before",
    offsetof(P_ctrl_student_HIL_T, Step_Y0), 46, 1, 2, 194, 0 },

  { 98, "ctrl_student_hil/ThrustAllocationAndSaturation/Saturation/UpperLimit",
    offsetof(P_ctrl_student_HIL_T, Saturation_UpperSat), 46, 1, 2, 196, 0 },

  { 99, "ctrl_student_hil/ThrustAllocationAndSaturation/Saturation/LowerLimit",
    offsetof(P_ctrl_student_HIL_T, Saturation_LowerSat), 46, 1, 2, 198, 0 },

  { 100, "ctrl_student_hil/ThrustAllocationAndSaturation/Switch/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch_Threshold_j), 46, 1, 2, 200, 0 },

  { 101, "ctrl_student_hil/ThrustAllocationAndSaturation/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value_o), 46, 1, 2, 202, 0 },

  { 102, "ctrl_student_hil/ThrustAllocationAndSaturation/Switch1/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch1_Threshold_o), 46, 1, 2, 204, 0 },

  { 103, "ctrl_student_hil/ThrustAllocationAndSaturation/Constant3/Value",
    offsetof(P_ctrl_student_HIL_T, Constant3_Value_i), 46, 1, 2, 206, 0 },

  { 104, "ctrl_student_hil/tau to real ship (only use in MCLab)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_b), 46, 1, 2, 208, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 105;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  2, 2,                                /* Parameter at index 1 */
  2, 1,                                /* Parameter at index 2 */
  3, 3,                                /* Parameter at index 3 */
  3, 3,                                /* Parameter at index 4 */
  3, 3,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  3, 1,                                /* Parameter at index 11 */
  3, 3,                                /* Parameter at index 12 */
  3, 3,                                /* Parameter at index 13 */
  3, 3,                                /* Parameter at index 14 */
  4, 1,                                /* Parameter at index 15 */
  4, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  2, 2,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
  1, 1,                                /* Parameter at index 36 */
  1, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
  1, 1,                                /* Parameter at index 39 */
  1, 1,                                /* Parameter at index 40 */
  1, 1,                                /* Parameter at index 41 */
  1, 1,                                /* Parameter at index 42 */
  1, 1,                                /* Parameter at index 43 */
  1, 1,                                /* Parameter at index 44 */
  1, 1,                                /* Parameter at index 45 */
  1, 1,                                /* Parameter at index 46 */
  1, 1,                                /* Parameter at index 47 */
  1, 1,                                /* Parameter at index 48 */
  1, 1,                                /* Parameter at index 49 */
  1, 1,                                /* Parameter at index 50 */
  1, 1,                                /* Parameter at index 51 */
  1, 1,                                /* Parameter at index 52 */
  1, 1,                                /* Parameter at index 53 */
  1, 2,                                /* Parameter at index 54 */
  1, 1,                                /* Parameter at index 55 */
  1, 1,                                /* Parameter at index 56 */
  1, 1,                                /* Parameter at index 57 */
  1, 1,                                /* Parameter at index 58 */
  1, 1,                                /* Parameter at index 59 */
  1, 1,                                /* Parameter at index 60 */
  1, 1,                                /* Parameter at index 61 */
  3, 1,                                /* Parameter at index 62 */
  1, 1,                                /* Parameter at index 63 */
  1, 1,                                /* Parameter at index 64 */
  1, 1,                                /* Parameter at index 65 */
  1, 1,                                /* Parameter at index 66 */
  1, 1,                                /* Parameter at index 67 */
  1, 1,                                /* Parameter at index 68 */
  1, 1,                                /* Parameter at index 69 */
  1, 1,                                /* Parameter at index 70 */
  3, 1,                                /* Parameter at index 71 */
  1, 1,                                /* Parameter at index 72 */
  1, 4,                                /* Parameter at index 73 */
  1, 1,                                /* Parameter at index 74 */
  1, 1,                                /* Parameter at index 75 */
  1, 1,                                /* Parameter at index 76 */
  1, 1,                                /* Parameter at index 77 */
  1, 1,                                /* Parameter at index 78 */
  1, 1,                                /* Parameter at index 79 */
  1, 1,                                /* Parameter at index 80 */
  1, 1,                                /* Parameter at index 81 */
  1, 1,                                /* Parameter at index 82 */
  1, 1,                                /* Parameter at index 83 */
  1, 1,                                /* Parameter at index 84 */
  1, 1,                                /* Parameter at index 85 */
  1, 1,                                /* Parameter at index 86 */
  1, 1,                                /* Parameter at index 87 */
  1, 1,                                /* Parameter at index 88 */
  1, 2,                                /* Parameter at index 89 */
  1, 1,                                /* Parameter at index 90 */
  3, 1,                                /* Parameter at index 91 */
  1, 1,                                /* Parameter at index 92 */
  3, 1,                                /* Parameter at index 93 */
  3, 1,                                /* Parameter at index 94 */
  1, 1,                                /* Parameter at index 95 */
  1, 1,                                /* Parameter at index 96 */
  1, 1,                                /* Parameter at index 97 */
  1, 1,                                /* Parameter at index 98 */
  1, 1,                                /* Parameter at index 99 */
  1, 1,                                /* Parameter at index 100 */
  1, 1,                                /* Parameter at index 101 */
  1, 1,                                /* Parameter at index 102 */
  1, 1,                                /* Parameter at index 103 */
  1, 1,                                /* Parameter at index 104 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student_hil/reset", 0, "", offsetof(B_ctrl_student_HIL_T, reset)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_student_hil/from enterprise/X_ship", 0, "", offsetof
    (B_ctrl_student_HIL_T, X_ship)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0
  },

  { 2, "ctrl_student_hil/from enterprise/Y_ship", 0, "", offsetof
    (B_ctrl_student_HIL_T, Y_ship)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0
  },

  { 3, "ctrl_student_hil/from enterprise/PSI_ship", 0, "", offsetof
    (B_ctrl_student_HIL_T, PSI_ship)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 6,
    0 },

  { 4, "ctrl_student_hil/from enterprise/res_ship", 0, "", offsetof
    (B_ctrl_student_HIL_T, res_ship)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8,
    0 },

  { 5, "ctrl_student_hil/Position/Memory", 0, "", offsetof(B_ctrl_student_HIL_T,
    Memory)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/DPObserver1/etaHat/Sum", 0, "", offsetof
    (B_ctrl_student_HIL_T, Sum)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil/DPObserver1/etaHat/Subsystem/Switch3", 0, "", offsetof
    (B_ctrl_student_HIL_T, Switch3)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 14,
    0 },

  { 8, "ctrl_student_hil/dropOutTolerance", 0, "", offsetof(B_ctrl_student_HIL_T,
    dropOutTolerance)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 16, 0 },

  { 9, "ctrl_student_hil/Sum1", 0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Sum1)
    +0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 18, 0 },

  { 10, "ctrl_student_hil/Sum1", 0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Sum1)
    +1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 20, 0 },

  { 11, "ctrl_student_hil/Sum1", 0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Sum1)
    +2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 22, 0 },

  { 12, "ctrl_student_hil/NoisePowPos", 0, "", offsetof(B_ctrl_student_HIL_T,
    NoisePowPos)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 24, 0 },

  { 13,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 26, 0 },

  { 14,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_e)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 28, 0 },

  { 15, "ctrl_student_hil/NoisePowHead", 0, "", offsetof(B_ctrl_student_HIL_T,
    NoisePowHead)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 30, 0 },

  { 16,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_m)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 32, 0 },

  { 17, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Hold)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    34, 0 },

  { 18, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, Hold)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    36, 0 },

  { 19, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, Hold)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    38, 0 },

  { 20, "ctrl_student_hil/NoiseEnable", 0, "", offsetof(B_ctrl_student_HIL_T,
    NoiseEnable)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 40, 0 },

  { 21, "ctrl_student_hil/Noise generator/Switch", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Switch)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 42,
    0 },

  { 22, "ctrl_student_hil/Noise generator/Switch", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Switch)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 44,
    0 },

  { 23, "ctrl_student_hil/Noise generator/Switch", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Switch)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 46,
    0 },

  { 24, "ctrl_student_hil/ControllerGainK2", 0, "", offsetof
    (B_ctrl_student_HIL_T, ControllerGainK2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 48, 0 },

  { 25,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Gain)+0*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 50, 0 },

  { 26,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Gain)+1*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 52, 0 },

  { 27,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Gain)+2*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 54, 0 },

  { 28,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Gain)+3*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 56, 0 },

  { 29,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(2,2)", offsetof(B_ctrl_student_HIL_T, Gain)+4*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 58, 0 },

  { 30,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(3,2)", offsetof(B_ctrl_student_HIL_T, Gain)+5*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 60, 0 },

  { 31,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(1,3)", offsetof(B_ctrl_student_HIL_T, Gain)+6*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 62, 0 },

  { 32,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(2,3)", offsetof(B_ctrl_student_HIL_T, Gain)+7*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 64, 0 },

  { 33,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(3,3)", offsetof(B_ctrl_student_HIL_T, Gain)+8*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 66, 0 },

  { 34,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/Integrator",
    0, "", offsetof(B_ctrl_student_HIL_T, Integrator)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 68, 0 },

  { 35,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/IC",
    0, "", offsetof(B_ctrl_student_HIL_T, IC)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 70, 0 },

  { 36,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/Integrator",
    0, "", offsetof(B_ctrl_student_HIL_T, Integrator_m)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 72, 0 },

  { 37,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Memory2",
    0, "", offsetof(B_ctrl_student_HIL_T, Memory2)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 74, 0 },

  { 38,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Memory1",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Memory1)+0*sizeof(real_T),
    BLOCKIO_SIG, 22, 1, 2, 76, 0 },

  { 39,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Memory1",
    0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Memory1)+1*sizeof(real_T),
    BLOCKIO_SIG, 22, 1, 2, 78, 0 },

  { 40,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Sum",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Sum_a)+0*sizeof(real_T),
    BLOCKIO_SIG, 20, 1, 2, 80, 0 },

  { 41,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Sum",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Sum_a)+1*sizeof(real_T),
    BLOCKIO_SIG, 20, 1, 2, 82, 0 },

  { 42,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Switch_j)+0*sizeof(real_T),
    BLOCKIO_SIG, 20, 1, 2, 84, 0 },

  { 43,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Switch_j)+1*sizeof(real_T),
    BLOCKIO_SIG, 20, 1, 2, 86, 0 },

  { 44,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Product",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Product)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 88, 0 },

  { 45,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Product",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Product)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 90, 0 },

  { 46,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Product",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Product)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 92, 0 },

  { 47,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/IC",
    0, "", offsetof(B_ctrl_student_HIL_T, IC_n)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 94, 0 },

  { 48, "ctrl_student_hil/DPObserver1/Subsystem/nuHat", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, nuHat)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 96, 0
  },

  { 49, "ctrl_student_hil/DPObserver1/Subsystem/nuHat", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, nuHat)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 98, 0
  },

  { 50, "ctrl_student_hil/DPObserver1/Subsystem/nuHat", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, nuHat)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 100,
    0 },

  { 51,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Sum",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Sum_g)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 102, 0 },

  { 52,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Sum",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Sum_g)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 104, 0 },

  { 53,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Sum",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Sum_g)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 106, 0 },

  { 54,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/K*z_2",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Kz_2)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 108, 0 },

  { 55,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/K*z_2",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Kz_2)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 110, 0 },

  { 56,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/K*z_2",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Kz_2)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 112, 0 },

  { 57, "ctrl_student_hil/ControllerGainK1", 0, "", offsetof
    (B_ctrl_student_HIL_T, ControllerGainK1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 114, 0 },

  { 58,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/M*alpha_dott",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Malpha_dott)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 116, 0 },

  { 59,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/M*alpha_dott",
    0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Malpha_dott)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 118, 0 },

  { 60,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/M*alpha_dott",
    0, "(1,3)", offsetof(B_ctrl_student_HIL_T, Malpha_dott)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 120, 0 },

  { 61,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/K*z_1",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Kz_1)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 122, 0 },

  { 62,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/K*z_1",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Kz_1)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 124, 0 },

  { 63,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/K*z_1",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Kz_1)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 126, 0 },

  { 64,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/Sum2",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Sum2)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 128, 0 },

  { 65,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/Sum2",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Sum2)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 130, 0 },

  { 66,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/Sum2",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Sum2)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 132, 0 },

  { 67,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Switch2",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Switch2)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 134, 0 },

  { 68,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Switch2",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Switch2)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 136, 0 },

  { 69,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Switch2",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Switch2)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 138, 0 },

  { 70, "ctrl_student_hil/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    140, 0 },

  { 71, "ctrl_student_hil/joystick/Select", 0, "", offsetof(B_ctrl_student_HIL_T,
    Select)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 142, 0 },

  { 72, "ctrl_student_hil/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    144, 0 },

  { 73, "ctrl_student_hil/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    146, 0 },

  { 74, "ctrl_student_hil/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    148, 0 },

  { 75, "ctrl_student_hil/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 150,
    0 },

  { 76, "ctrl_student_hil/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 152,
    0 },

  { 77, "ctrl_student_hil/joystick/L1", 0, "", offsetof(B_ctrl_student_HIL_T, L1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 154, 0 },

  { 78, "ctrl_student_hil/joystick/R1", 0, "", offsetof(B_ctrl_student_HIL_T, R1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 156, 0 },

  { 79, "ctrl_student_hil/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    158, 0 },

  { 80, "ctrl_student_hil/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 160,
    0 },

  { 81, "ctrl_student_hil/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    162, 0 },

  { 82, "ctrl_student_hil/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    164, 0 },

  { 83, "ctrl_student_hil/JoysticControllerSwitch", 0, "", offsetof
    (B_ctrl_student_HIL_T, JoysticControllerSwitch)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 166, 0 },

  { 84, "ctrl_student_hil/Switch2", 0, "(1,1)", offsetof(B_ctrl_student_HIL_T,
    Switch2_g)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 168, 0 },

  { 85, "ctrl_student_hil/Switch2", 0, "(2,1)", offsetof(B_ctrl_student_HIL_T,
    Switch2_g)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 170, 0 },

  { 86, "ctrl_student_hil/Switch2", 0, "(3,1)", offsetof(B_ctrl_student_HIL_T,
    Switch2_g)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 172, 0 },

  { 87, "ctrl_student_hil/dropoutdet/Memory", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory_m)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    174, 0 },

  { 88, "ctrl_student_hil/dropoutdet/Memory", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory_m)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    176, 0 },

  { 89, "ctrl_student_hil/dropoutdet/Memory", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory_m)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    178, 0 },

  { 90, "ctrl_student_hil/Sum2", 0, "", offsetof(B_ctrl_student_HIL_T, Sum2_a)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 180, 0 },

  { 91, "ctrl_student_hil/sf1", 0, "", offsetof(B_ctrl_student_HIL_T, sf1)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 182, 0 },

  { 92, "ctrl_student_hil/safety zone /Memory", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory_n)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 184,
    0 },

  { 93, "ctrl_student_hil/SZ_ResetKill", 0, "", offsetof(B_ctrl_student_HIL_T,
    SZ_ResetKill)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 186, 0 },

  { 94, "ctrl_student_hil/SZ_Owerwrite", 0, "", offsetof(B_ctrl_student_HIL_T,
    SZ_Owerwrite)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 188, 0 },

  { 95, "ctrl_student_hil/sf2", 0, "", offsetof(B_ctrl_student_HIL_T, sf2)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 190, 0 },

  { 96, "ctrl_student_hil/sf3", 0, "", offsetof(B_ctrl_student_HIL_T, sf3)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 192, 0 },

  { 97, "ctrl_student_hil/biasOffset", 0, "", offsetof(B_ctrl_student_HIL_T,
    biasOffset)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 194, 0 },

  { 98,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Memory",
    0, "", offsetof(B_ctrl_student_HIL_T, Memory_o)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 196, 0 },

  { 99, "ctrl_student_hil/DPObserver1/Bias/IC1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, IC1)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 198, 0
  },

  { 100, "ctrl_student_hil/DPObserver1/Bias/IC1", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, IC1)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 200, 0
  },

  { 101, "ctrl_student_hil/DPObserver1/Bias/IC1", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, IC1)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 202, 0
  },

  { 102, "ctrl_student_hil/DPObserver1/Subsystem/IC", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, IC_i)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 204, 0
  },

  { 103, "ctrl_student_hil/DPObserver1/Subsystem/IC", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, IC_i)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 206, 0
  },

  { 104, "ctrl_student_hil/DPObserver1/Subsystem/IC", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, IC_i)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 208, 0
  },

  { 105, "ctrl_student_hil/ThrustAllocationAndSaturation/TurnOffomega1", 0, "",
    offsetof(B_ctrl_student_HIL_T, TurnOffomega1)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 210, 0 },

  { 106, "ctrl_student_hil/ThrustAllocationAndSaturation/TurnOffomega2", 0, "",
    offsetof(B_ctrl_student_HIL_T, TurnOffomega2)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 212, 0 },

  { 107, "ctrl_student_hil/ThrustAllocationAndSaturation/Switch", 0, "",
    offsetof(B_ctrl_student_HIL_T, Switch_b)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 214, 0 },

  { 108, "ctrl_student_hil/ThrustAllocationAndSaturation/Switch1", 0, "",
    offsetof(B_ctrl_student_HIL_T, Switch1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 216, 0 },

  { 109, "ctrl_student_hil/ThrustAllocationAndSaturation/Sum", 0, "", offsetof
    (B_ctrl_student_HIL_T, Sum_n)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 218, 0
  },

  { 110, "ctrl_student_hil/ThrustAllocationAndSaturation/Sum1", 0, "", offsetof
    (B_ctrl_student_HIL_T, Sum1_n)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 220,
    0 },

  { 111, "ctrl_student_hil/from model/y_in", 0, "", offsetof
    (B_ctrl_student_HIL_T, y_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 222, 0
  },

  { 112, "ctrl_student_hil/from model/psi_in", 0, "", offsetof
    (B_ctrl_student_HIL_T, psi_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 224,
    0 },

  { 113, "ctrl_student_hil/from model/u_in", 0, "", offsetof
    (B_ctrl_student_HIL_T, u_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 226, 0
  },

  { 114, "ctrl_student_hil/from model/x_in", 0, "", offsetof
    (B_ctrl_student_HIL_T, x_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 228, 0
  },

  { 115, "ctrl_student_hil/from model/r_in", 0, "", offsetof
    (B_ctrl_student_HIL_T, r_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 230, 0
  },

  { 116, "ctrl_student_hil/from model/v_in", 0, "", offsetof
    (B_ctrl_student_HIL_T, v_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 232, 0
  },

  { 117,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Full thrust allocation",
    0, "u_BT", offsetof(B_ctrl_student_HIL_T, u_BT)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 234, 0 },

  { 118,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Full thrust allocation",
    1, "u_VSP", offsetof(B_ctrl_student_HIL_T, u_VSP)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 236, 0 },

  { 119,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Full thrust allocation",
    2, "alpha_VSP", offsetof(B_ctrl_student_HIL_T, alpha_VSP)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 238, 0 },

  { 120,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Full thrust allocation",
    3, "omega_VSP", offsetof(B_ctrl_student_HIL_T, omega_VSP)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 240, 0 },

  { 121, "ctrl_student_hil/safety zone /MATLAB Function", 0, "kill_signal",
    offsetof(B_ctrl_student_HIL_T, kill_signal)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 242, 0 },

  { 122, "ctrl_student_hil/physics_model/kinetics", 0, "nu_dot(1,1)", offsetof
    (B_ctrl_student_HIL_T, nu_dot)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 244,
    0 },

  { 123, "ctrl_student_hil/physics_model/kinetics", 0, "nu_dot(1,2)", offsetof
    (B_ctrl_student_HIL_T, nu_dot)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 246,
    0 },

  { 124, "ctrl_student_hil/physics_model/kinetics", 0, "nu_dot(1,3)", offsetof
    (B_ctrl_student_HIL_T, nu_dot)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 248,
    0 },

  { 125, "ctrl_student_hil/physics_model/kinematics", 0, "eta_dot(1,1)",
    offsetof(B_ctrl_student_HIL_T, eta_dot)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 250, 0 },

  { 126, "ctrl_student_hil/physics_model/kinematics", 0, "eta_dot(1,2)",
    offsetof(B_ctrl_student_HIL_T, eta_dot)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 252, 0 },

  { 127, "ctrl_student_hil/physics_model/kinematics", 0, "eta_dot(1,3)",
    offsetof(B_ctrl_student_HIL_T, eta_dot)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 254, 0 },

  { 128, "ctrl_student_hil/joystick/Contoller_Map1", 0, "tau_surge", offsetof
    (B_ctrl_student_HIL_T, tau_surge)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    256, 0 },

  { 129, "ctrl_student_hil/joystick/Contoller_Map1", 1, "tau_sway", offsetof
    (B_ctrl_student_HIL_T, tau_sway)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 258,
    0 },

  { 130, "ctrl_student_hil/joystick/Contoller_Map1", 2, "tau_yaw", offsetof
    (B_ctrl_student_HIL_T, tau_yaw)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 260,
    0 },

  { 131, "ctrl_student_hil/dropoutdet/dropOutDetect", 0, "posOut(1,1)", offsetof
    (B_ctrl_student_HIL_T, posOut)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 262,
    0 },

  { 132, "ctrl_student_hil/dropoutdet/dropOutDetect", 0, "posOut(1,2)", offsetof
    (B_ctrl_student_HIL_T, posOut)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 264,
    0 },

  { 133, "ctrl_student_hil/dropoutdet/dropOutDetect", 0, "posOut(1,3)", offsetof
    (B_ctrl_student_HIL_T, posOut)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 266,
    0 },

  { 134, "ctrl_student_hil/dropoutdet/dropOutDetect", 1, "dropout", offsetof
    (B_ctrl_student_HIL_T, dropout)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 268,
    0 },

  { 135, "ctrl_student_hil/ThrustAllocationAndSaturation/actForces1", 0,
    "tauAct(1,1)", offsetof(B_ctrl_student_HIL_T, tauAct)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 270, 0 },

  { 136, "ctrl_student_hil/ThrustAllocationAndSaturation/actForces1", 0,
    "tauAct(1,2)", offsetof(B_ctrl_student_HIL_T, tauAct)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 272, 0 },

  { 137, "ctrl_student_hil/ThrustAllocationAndSaturation/actForces1", 0,
    "tauAct(1,3)", offsetof(B_ctrl_student_HIL_T, tauAct)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 274, 0 },

  { 138, "ctrl_student_hil/ThrustAllocationAndSaturation/Force2Control", 0,
    "u_vsp1", offsetof(B_ctrl_student_HIL_T, u_vsp1)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 276, 0 },

  { 139, "ctrl_student_hil/ThrustAllocationAndSaturation/Force2Control", 1,
    "u_vsp2", offsetof(B_ctrl_student_HIL_T, u_vsp2)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 278, 0 },

  { 140, "ctrl_student_hil/ThrustAllocationAndSaturation/Force2Control", 2,
    "alpha1", offsetof(B_ctrl_student_HIL_T, alpha1)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 280, 0 },

  { 141, "ctrl_student_hil/ThrustAllocationAndSaturation/Force2Control", 3,
    "alpha2", offsetof(B_ctrl_student_HIL_T, alpha2)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 282, 0 },

  { 142, "ctrl_student_hil/Position/Deg2Rad", 1, "deg_out", offsetof
    (B_ctrl_student_HIL_T, deg_out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 284,
    0 },

  { 143, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,1)", offsetof(B_ctrl_student_HIL_T, output)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 286, 0 },

  { 144, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,2)", offsetof(B_ctrl_student_HIL_T, output)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 288, 0 },

  { 145, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,3)", offsetof(B_ctrl_student_HIL_T, output)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 290, 0 },

  { 146, "ctrl_student_hil/Noise generator/Downsamplesignal/MATLAB Function", 0,
    "count", offsetof(B_ctrl_student_HIL_T, count)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 292, 0 },

  { 147, "ctrl_student_hil/DPObserver1/etaHat/etaHatDot", 0, "etaHatDot(1,1)",
    offsetof(B_ctrl_student_HIL_T, etaHatDot)+0*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 294, 0 },

  { 148, "ctrl_student_hil/DPObserver1/etaHat/etaHatDot", 0, "etaHatDot(1,2)",
    offsetof(B_ctrl_student_HIL_T, etaHatDot)+1*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 296, 0 },

  { 149, "ctrl_student_hil/DPObserver1/etaHat/etaHatDot", 0, "etaHatDot(1,3)",
    offsetof(B_ctrl_student_HIL_T, etaHatDot)+2*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 298, 0 },

  { 150, "ctrl_student_hil/DPObserver1/Bias/bHatDot", 0, "bHatDot(1,1)",
    offsetof(B_ctrl_student_HIL_T, bHatDot)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 300, 0 },

  { 151, "ctrl_student_hil/DPObserver1/Bias/bHatDot", 0, "bHatDot(1,2)",
    offsetof(B_ctrl_student_HIL_T, bHatDot)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 302, 0 },

  { 152, "ctrl_student_hil/DPObserver1/Bias/bHatDot", 0, "bHatDot(1,3)",
    offsetof(B_ctrl_student_HIL_T, bHatDot)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 304, 0 },

  { 153,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/UpdateLaw",
    0, "s_dot", offsetof(B_ctrl_student_HIL_T, s_dot)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 306, 0 },

  { 154,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/UpdateLaw",
    1, "U_s", offsetof(B_ctrl_student_HIL_T, U_s)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 308, 0 },

  { 155,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function1",
    0, "SwitchSignal", offsetof(B_ctrl_student_HIL_T, SwitchSignal)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 310, 0 },

  { 156,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function1",
    1, "N", offsetof(B_ctrl_student_HIL_T, N)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 312, 0 },

  { 157,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    2, "SwitchSignal_out", offsetof(B_ctrl_student_HIL_T, SwitchSignal_out)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 314, 0 },

  { 158,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    3, "N_out", offsetof(B_ctrl_student_HIL_T, N_out)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 316, 0 },

  { 159,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    4, "U", offsetof(B_ctrl_student_HIL_T, U)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 318, 0 },

  { 160,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    5, "s_out", offsetof(B_ctrl_student_HIL_T, s_out)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 320, 0 },

  { 161,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    6, "init_time(1,1)", offsetof(B_ctrl_student_HIL_T, init_time)+0*sizeof
    (real_T), BLOCKIO_SIG, 22, 1, 2, 322, 0 },

  { 162,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    6, "init_time(1,2)", offsetof(B_ctrl_student_HIL_T, init_time)+1*sizeof
    (real_T), BLOCKIO_SIG, 22, 1, 2, 324, 0 },

  { 163,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    7, "flag", offsetof(B_ctrl_student_HIL_T, flag)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 326, 0 },

  { 164,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/UpdateLaw",
    0, "s_dot", offsetof(B_ctrl_student_HIL_T, s_dot_l)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 328, 0 },

  { 165,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization /Subsystem/MATLAB Function",
    0, "pd(1,1)", offsetof(B_ctrl_student_HIL_T, pd)+0*sizeof(real_T),
    BLOCKIO_SIG, 22, 1, 2, 330, 0 },

  { 166,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization /Subsystem/MATLAB Function",
    0, "pd(1,2)", offsetof(B_ctrl_student_HIL_T, pd)+1*sizeof(real_T),
    BLOCKIO_SIG, 22, 1, 2, 332, 0 },

  { 167,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Check_s/CheckS&getU",
    0, "s_out", offsetof(B_ctrl_student_HIL_T, s_out_j)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 334, 0 },

  { 168,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Check_s/CheckS&getU",
    2, "Switch", offsetof(B_ctrl_student_HIL_T, Switch_d)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 336, 0 },

  { 169,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(1,1)", offsetof(B_ctrl_student_HIL_T, M)+0*sizeof(real_T), BLOCKIO_SIG,
    19, 1, 2, 338, 0 },

  { 170,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(2,1)", offsetof(B_ctrl_student_HIL_T, M)+1*sizeof(real_T), BLOCKIO_SIG,
    19, 1, 2, 340, 0 },

  { 171,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(3,1)", offsetof(B_ctrl_student_HIL_T, M)+2*sizeof(real_T), BLOCKIO_SIG,
    19, 1, 2, 342, 0 },

  { 172,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(1,2)", offsetof(B_ctrl_student_HIL_T, M)+3*sizeof(real_T), BLOCKIO_SIG,
    19, 1, 2, 344, 0 },

  { 173,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(2,2)", offsetof(B_ctrl_student_HIL_T, M)+4*sizeof(real_T), BLOCKIO_SIG,
    19, 1, 2, 346, 0 },

  { 174,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(3,2)", offsetof(B_ctrl_student_HIL_T, M)+5*sizeof(real_T), BLOCKIO_SIG,
    19, 1, 2, 348, 0 },

  { 175,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(1,3)", offsetof(B_ctrl_student_HIL_T, M)+6*sizeof(real_T), BLOCKIO_SIG,
    19, 1, 2, 350, 0 },

  { 176,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(2,3)", offsetof(B_ctrl_student_HIL_T, M)+7*sizeof(real_T), BLOCKIO_SIG,
    19, 1, 2, 352, 0 },

  { 177,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(3,3)", offsetof(B_ctrl_student_HIL_T, M)+8*sizeof(real_T), BLOCKIO_SIG,
    19, 1, 2, 354, 0 },

  { 178,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/To thruster of real ship/control limit checking",
    0, "fault", offsetof(B_ctrl_student_HIL_T, fault)+0*sizeof(boolean_T),
    BLOCKIO_SIG, 8, 1, 2, 356, 0 },

  { 179,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/MATLAB Function1",
    0, "SwitchSignal_Out", offsetof(B_ctrl_student_HIL_T,
    sf_MATLABFunction1_p.SwitchSignal_Out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 358, 0 },

  { 180,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/MATLAB Function1",
    0, "SwitchSignal_Out", offsetof(B_ctrl_student_HIL_T,
    sf_MATLABFunction1_m.SwitchSignal_Out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 360, 0 },

  { 181,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Rotation Matrix",
    0, "R(1,1)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix.R)+0*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 362, 0 },

  { 182,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Rotation Matrix",
    0, "R(2,1)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix.R)+1*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 364, 0 },

  { 183,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Rotation Matrix",
    0, "R(3,1)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix.R)+2*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 366, 0 },

  { 184,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Rotation Matrix",
    0, "R(1,2)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix.R)+3*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 368, 0 },

  { 185,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Rotation Matrix",
    0, "R(2,2)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix.R)+4*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 370, 0 },

  { 186,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Rotation Matrix",
    0, "R(3,2)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix.R)+5*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 372, 0 },

  { 187,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Rotation Matrix",
    0, "R(1,3)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix.R)+6*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 374, 0 },

  { 188,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Rotation Matrix",
    0, "R(2,3)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix.R)+7*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 376, 0 },

  { 189,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Rotation Matrix",
    0, "R(3,3)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix.R)+8*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 378, 0 },

  { 190,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(1,1)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+0*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 380, 0 },

  { 191,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(2,1)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+1*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 382, 0 },

  { 192,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(3,1)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+2*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 384, 0 },

  { 193,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(1,2)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+3*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 386, 0 },

  { 194,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(2,2)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+4*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 388, 0 },

  { 195,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(3,2)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+5*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 390, 0 },

  { 196,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(1,3)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+6*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 392, 0 },

  { 197,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(2,3)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+7*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 394, 0 },

  { 198,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(3,3)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+8*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 396, 0 },

  { 199,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix",
    0, "R(1,1)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix_j.R)+0*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 398, 0 },

  { 200,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix",
    0, "R(2,1)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix_j.R)+1*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 400, 0 },

  { 201,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix",
    0, "R(3,1)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix_j.R)+2*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 402, 0 },

  { 202,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix",
    0, "R(1,2)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix_j.R)+3*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 404, 0 },

  { 203,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix",
    0, "R(2,2)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix_j.R)+4*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 406, 0 },

  { 204,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix",
    0, "R(3,2)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix_j.R)+5*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 408, 0 },

  { 205,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix",
    0, "R(1,3)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix_j.R)+6*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 410, 0 },

  { 206,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix",
    0, "R(2,3)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix_j.R)+7*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 412, 0 },

  { 207,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix",
    0, "R(3,3)", offsetof(B_ctrl_student_HIL_T, sf_RotationMatrix_j.R)+8*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 414, 0 },

  { 208,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(1,1)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+0*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 416, 0 },

  { 209,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(2,1)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+1*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 418, 0 },

  { 210,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(3,1)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+2*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 420, 0 },

  { 211,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(1,2)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+3*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 422, 0 },

  { 212,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(2,2)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+4*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 424, 0 },

  { 213,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(3,2)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+5*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 426, 0 },

  { 214,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(1,3)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+6*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 428, 0 },

  { 215,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(2,3)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+7*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 430, 0 },

  { 216,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(3,3)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+8*
    sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 432, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 217;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 78;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "reset", 0, EXT_IN, 1, 1, 1 },

  { 1, "from enterprise/X_ship", 0, EXT_IN, 1, 1, 1 },

  { 2, "from enterprise/Y_ship", 0, EXT_IN, 1, 1, 1 },

  { 3, "from enterprise/PSI_ship", 0, EXT_IN, 1, 1, 1 },

  { 4, "from enterprise/res_ship", 1, EXT_IN, 1, 1, 1 },

  { 5, "dropOutTolerance", 0, EXT_IN, 1, 1, 1 },

  { 6, "NoisePowPos", 0, EXT_IN, 1, 1, 1 },

  { 7, "NoisePowHead", 0, EXT_IN, 1, 1, 1 },

  { 8, "NoiseEnable", 0, EXT_IN, 1, 1, 1 },

  { 9, "ControllerGainK2", 0, EXT_IN, 1, 1, 1 },

  { 10, "ControllerGainK1", 0, EXT_IN, 1, 1, 1 },

  { 11, "joystick/L2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 12, "joystick/Select", 0, EXT_IN, 1, 1, 1 },

  { 13, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 14, "joystick/PosYRight", 0, EXT_IN, 1, 1, 1 },

  { 15, "joystick/R2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 16, "joystick/PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 17, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 18, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 19, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 20, "joystick/ArrowDown", 1, EXT_IN, 1, 1, 1 },

  { 21, "joystick/ArrowUp", 1, EXT_IN, 1, 1, 1 },

  { 22, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 23, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { 24, "JoysticControllerSwitch", 0, EXT_IN, 1, 1, 1 },

  { 25, "sf1", 0, EXT_IN, 1, 1, 1 },

  { 26, "SZ_ResetKill", 0, EXT_IN, 1, 1, 1 },

  { 27, "SZ_Owerwrite", 0, EXT_IN, 1, 1, 1 },

  { 28, "sf2", 0, EXT_IN, 1, 1, 1 },

  { 29, "sf3", 0, EXT_IN, 1, 1, 1 },

  { 30, "biasOffset", 0, EXT_IN, 1, 1, 1 },

  { 31, "ThrustAllocationAndSaturation/TurnOffomega1", 0, EXT_IN, 1, 1, 1 },

  { 32, "ThrustAllocationAndSaturation/TurnOffomega2", 0, EXT_IN, 1, 1, 1 },

  { 33, "from model/y_in", 1, EXT_IN, 1, 1, 1 },

  { 34, "from model/psi_in", 1, EXT_IN, 1, 1, 1 },

  { 35, "from model/u_in", 1, EXT_IN, 1, 1, 1 },

  { 36, "from model/x_in", 1, EXT_IN, 1, 1, 1 },

  { 37, "from model/r_in", 1, EXT_IN, 1, 1, 1 },

  { 38, "from model/v_in", 1, EXT_IN, 1, 1, 1 },

  { 0, "eta_hat", 0, EXT_OUT, 3, 3, 1 },

  { 1, "Residual", 1, EXT_OUT, 2, 2, 1 },

  { 2, "eta_tilde", 0, EXT_OUT, 3, 3, 1 },

  { 3, "eta_noise", 0, EXT_OUT, 3, 3, 1 },

  { 4, "joystick/Current Mode ", 0, EXT_OUT, 1, 1, 1 },

  { 5, "joystick/tau_yaw", 0, EXT_OUT, 1, 1, 1 },

  { 6, "joystick/tau_x", 0, EXT_OUT, 1, 1, 1 },

  { 7, "joystick/tau_y", 0, EXT_OUT, 1, 1, 1 },

  { 8, "Tau_pre", 0, EXT_OUT, 3, 3, 1 },

  { 9, "Tau_post", 0, EXT_OUT, 3, 3, 1 },

  { 10, "P_d", 0, EXT_OUT, 2, 2, 1 },

  { 11, "dropoutFlag", 0, EXT_OUT, 1, 1, 1 },

  { 12, "tau to CSE mocell (only use for HIL testing)/X_d", 0, EXT_OUT, 1, 1, 1
  },

  { 13, "tau to CSE mocell (only use for HIL testing)/N_d", 0, EXT_OUT, 1, 1, 1
  },

  { 14, "tau to CSE mocell (only use for HIL testing)/Y_d", 0, EXT_OUT, 1, 1, 1
  },

  { 15, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 16, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1
  },

  { 17, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 18, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 0,
    EXT_OUT, 1, 1, 1 },

  { 19, "Position/eta_real", 0, EXT_OUT, 3, 3, 1 },

  { 20, "ThrustAllocationAndSaturation/u_BT", 1, EXT_OUT, 1, 1, 1 },

  { 21, "ThrustAllocationAndSaturation/u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 22, "ThrustAllocationAndSaturation/u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 23, "ThrustAllocationAndSaturation/alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 24, "ThrustAllocationAndSaturation/alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 25, "ThrustAllocationAndSaturation/omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 26, "ThrustAllocationAndSaturation/omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 27, "ThrustAllocationAndSaturation/f_bt", 1, EXT_OUT, 1, 1, 1 },

  { 28, "ThrustAllocationAndSaturation/f_vspx", 0, EXT_OUT, 1, 1, 1 },

  { 29, "ThrustAllocationAndSaturation/ f_vspy", 0, EXT_OUT, 1, 1, 1 },

  { 30, "from model/u_real  ", 1, EXT_OUT, 1, 1, 1 },

  { 31,
    "tau to real ship (only use in MCLab)/To thruster of real ship/control input u exceeds bounds",
    1, EXT_OUT, 1, 1, 1 },

  { 32,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP1",
    1, EXT_OUT, 1, 1, 1 },

  { 33,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP2",
    1, EXT_OUT, 1, 1, 1 },

  { 34,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP1",
    1, EXT_OUT, 1, 1, 1 },

  { 35,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP2",
    1, EXT_OUT, 1, 1, 1 },

  { 36, "tau to real ship (only use in MCLab)/To thruster of real ship/u/u_BT",
    1, EXT_OUT, 1, 1, 1 },

  { 37, "tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP1",
    1, EXT_OUT, 1, 1, 1 },

  { 38, "tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP2",
    1, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.01, 0 }
};

int NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_student_hil";
static char* NI_CompiledModelVersion = "1.339";
static char* NI_CompiledModelDateTime = "Thu Apr 06 16:23:57 2017";
static char* NI_builder DataSection(".NIVS.builder") =
  "NI VeriStand 2014.0.0.82 (2014) RTW Build";
static char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2014.0.0.82";

/* Model Information Query fucntions for MATLAB
 */
/* dll information
 * Returns 1 for RTW DLL
 *		   2 for AutoCode DLL
 */
DLL_EXPORT long NIRT_GetBuildInfo(char* detail, long* len)
{
  // There are no console properties to set for VxWorks, because the console is simply serial output data.
  // Just do printf for VxWorks and ignore all console properties.
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  printf("\n*******************************************************************************\n");
  printf("%s\nModel Name: %s\nModel Version: %s\nCompiled On: %s",
         NI_builder, NI_CompiledModelName, NI_CompiledModelVersion,
         NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len>=(long)strlen(NI_builder))
    *len = strlen(NI_builder)+1;
  strncpy(detail,NI_builder,*len);
  return 1;
}

/*
 * Distinction between Index and ID:
 * Index is a long datatype (used to set parameter/probe signals).
 * ID on the other hand is a string (tag "2-3-2-12" for MatrixX/ Full path "f14/Gain/Gain" for Matlab).
 * If Bus support is added then signal path from the block name is added to the end of the port number (Model/subsystem1:1/X/A)
 * where X/A is the path from the block
 * NOTE: ID may not be the same as Paramname or signal name.
 */

/* signal information
   NOTE: signal ID == the blockname and port that feeds it extended with /sinalname.

   The port number in Simulation Environment is 1 indexed.. but on RT is 0 indexed.
 */
DLL_EXPORT long NIRT_GetSignalSpec(long* sidx, char* ID, long* ID_len, char
  * blkname, long *bnlen,
  long *portnum, char* signame, long *snlen, long *dattype, long* dims, long
  * numdim)
{
  long sigidx = *sidx;
  int i = 0;
  char *IDblk = 0;
  int IDport = 0;
  if (sigidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // parse ID into blkname and port
      i = strrchr(ID, ':') - ID;

      // malformed ID
      if (i<=0)
        return NI_SigListSize;

      //ID[i] = 0;
      IDblk = ID;
      IDport = atoi(ID+i+1);

      // lookup the table for matching ID
      // Bus support
      for (i=0;i<NI_SigListSize;i++) {
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname)+ 11, sizeof(char));

        //sprintf(tempID,"%s%s%s",NI_SigList[i].blockname,"/",NI_SigList[i].signalname);
        if (strlen(NI_SigList[i].signalname)>0)
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        else
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1))
          break;
        free(tempID);
      }

      if (i<NI_SigListSize)
        sigidx = *sidx = i;
      else
        return NI_SigListSize;
    } else                             // no index or ID specified.
      return NI_SigListSize;
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID) {
      // no need for return string to be null terminated!
      // 11 to accomodate ':','/', port number and null character
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0)
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      else
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      if ((long)strlen(tempID)<*ID_len)
        *ID_len = strlen(tempID);
      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].blockname)<*bnlen)
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].signalname)<*snlen)
        *snlen = strlen(NI_SigList[sigidx].signalname);
      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum)
      *portnum = NI_SigList[sigidx].portno;
    if (dattype)
      *dattype = NI_SigList[sigidx].datatype;
    if (dims && *numdim>=NI_SigList[sigidx].numofdims) {
      *numdim = NI_SigList[sigidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_SigListSize;
}

/*
 * Get parameter indices
 */
DLL_EXPORT long NIRT_GetParameterIndices(long* indices, long* len)
{
  long i;
  for (i=0;i<NI_ParamListSize && i<*len;i++)
    indices[i] = NI_ParamList[i].idx;
  *len = i;
  return NI_OK;
}

/*
 * parameter information
 *
 * if *pidx < 0, Lookup parameter by ID if ID != NULL.
 * if ID == NULL or no matching ID found, return number of parameters.
 *
 * plen  -> size of path
 * pnlen -> size of paramname
 * numdim -> size of dims array
 */
DLL_EXPORT long NIRT_GetParameterSpec(long* pidx, char* ID, long* ID_len, char
  * paramname, long *pnlen,
  long *dattype, long* dims, long* numdim)
{
  int i= 0;
  int paramidx = *pidx;
  if (paramidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // lookup the table for matching ID
      for (i=0;i<NI_ParamListSize;i++) {
        if (!strcmp(ID,NI_ParamList[i].paramname))
          break;
      }

      if (i<NI_ParamListSize)
        paramidx = *pidx = i;
      else
        return NI_ParamListSize;
    } else                             // no index or ID specified.
      return NI_ParamListSize;
  }

  if (paramidx>=0 && paramidx<NI_ParamListSize) {
    if (ID) {
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*ID_len)
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*pnlen)
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype)
      *dattype = NI_ParamList[paramidx].datatype;
    if (!numdim)
      return 0;
    if (*numdim>=NI_ParamList[paramidx].numofdims) {
      *numdim = NI_ParamList[paramidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_ParamListSize;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetParameterExpression(long paramidx, char* expression,
  long *exp_len)
{
  return 0;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetVariableName(long varidx, char* variable_name, long
  *var_len)
{
  return 0;
}

/*
 * NIRT_GetExtIOSpec
 *
 * Inputs:
 *		index: index of the task
 * Outputs:
 *		idx:  idx of the IO.
 *		name: Name of the IO block
 *		tid: task id
 *		type: EXT_IN or EXT_OUT
 *		dimX: size of 0th dimension
 *		dimY: size of 1th dimension
 * Return value: 0 if no error. (if index == -1, return number of tasks in the model)
 */
DLL_EXPORT long NIRT_GetExtIOSpec(long index, long *idx, char* name, long* tid,
  long *type, long *dims, long* numdims)
{
  if (index==-1)
    return NI_ExtListSize;
  if (idx)
    *idx = NI_ExtList[index].idx;
  if (name) {
    int sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid)
    *tid = NI_ExtList[index].TID;
  if (type)
    *type = NI_ExtList[index].type;
  if (numdims && dims) {
    if (*numdims>=2) {
      *numdims= 2;
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    } else
      *numdims= 0;
  }

  return 0;
}

/* Helper function to probe one	signal. baseaddr must NOT be VIRTUAL_SIG */
static long NI_ProbeOneSignal(long idx, double *value, long len, long *count,
  long vOffset, long vLength)
{
  char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ?
                      S->ModelData.blockIO : S->ModelData.inputs) + (int)
    NI_SigList[idx].addr;
  long subindex = (vLength == -1) ? 0 : vOffset;
  long sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength + vOffset);
  while ((subindex < sublength) && (*count < len))
    value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++, NI_SigList[idx]
      .datatype, NI_SigList[idx].IsComplex);
  return *count;
}

/*
 * NIRT_ProbeSignals
 *
 * Inputs:
 *		sigindices: indeces of signals
 *		numsigs: number of signals
 *		len: total length of all signals
 * Outputs:
 *		value: probed signal data
 *		len: length of data (may vary from input)
 * Return value: equal to len
 */
DLL_EXPORT long NIRT_ProbeSignals(long* sigindices, long numsigs,
  double* value, long* len)
{
  int i, j, idx;
  long count = 0;
  if (!SITexportglobals.inCriticalSection)
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0)
      break;
    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        for (j = 0; j < 2; j++) {
          long vidx = NI_VirtualBlockSources[NI_SigList[idx].addr][j];
          long voff = NI_VirtualBlockOffsets[NI_SigList[idx].addr][j];
          long vlen = NI_VirtualBlockLengths[NI_SigList[idx].addr][j];
          if (vidx == -1)
            break;
          NI_ProbeOneSignal(vidx, value, *len, &count, voff, vlen);
        }
      } else
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
    }
  }

  *len = count;
  return count;
}

/* Copy the	statically initialized params into our copy of the param struct
   The undef allows us to access the real ctrl_student_HIL_P
   In the rest of the code ctrl_student_HIL_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_student_HIL_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_student_HIL_P, sizeof(P_ctrl_student_HIL_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_student_HIL_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_student_HIL_T));
  return NI_OK;
}

static int NI_SetParamTxStatus = NI_OK;

// This function is called by the BGL to set parameters.  When a commit is requested (index < 0),
// the code enters a critical section shared with the TCL. This ensures that the flip occurs only
// when safe, and acts as a messaging scheme for us to copy back the parameters.
DLL_EXPORT long NIRT_SetParameter(long index, long subindex, double value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_student_HIL_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0)
        return NI_OK;
      SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                         1);
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    if (NI_SetParamTxStatus==NI_ERROR) {
      // fail the transaction.
      // copy old	list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1)
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_ctrl_student_HIL_T));

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /*Do nothing if no new parameters were written after last commit*/
    if (WriteSideDirtyFlag == 0)
      return NI_OK;

    // commit changes
    S->ModelData.defaultParam = (double *)&rtParameter[1-READSIDE];
    WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
    READSIDE = 1 - READSIDE;
    SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
    ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

    // Copy back the newly set parameters to the writeside.
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    WriteSideDirtyFlag = 0;
    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,value,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_SetVectorParameter( unsigned long index, const double
  * paramvalues, unsigned long paramlength)
{
  unsigned int i = 0;
  long retval= NI_OK, temp_retval;
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    if (temp_retval = NIRT_SetValueByDataType(ptr, i, paramvalues[i],
         NI_ParamList[index].datatype, NI_ParamList[index].IsComplex))//assignment intended in if condition
      retval= temp_retval;
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

DLL_EXPORT long NIRT_SetScalarParameterInline( unsigned long index, unsigned
  long subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,paramvalue,NI_ParamList[index].
    datatype,NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_GetParameter(long index, long subindex, double *value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  *value = NIRT_GetValueByDataType(ptr,subindex,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

DLL_EXPORT long NIRT_GetVectorParameter(unsigned long index, double* paramvalues,
  unsigned long paramlength)
{
  char* ptr = NULL;
  unsigned int i = 0;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_GetSimState(long* numContStates, char* contStatesNames,
  double* contStates, long* numDiscStates, char* discStatesNames, double
  * discStates, long* numClockTicks, char* clockTicksNames, long* clockTicks)
{
  long count, idx;
  if (numContStates && numDiscStates && numClockTicks) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 17;
      *numDiscStates = 1548;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.etaHat_CSTATE,
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "etaHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.etaHat2_CSTATE,
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "etaHat2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.etaHat1_CSTATE,
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "etaHat1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_f, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_f");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.nuHat_CSTATE[0],
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "nuHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.nuHat_CSTATE[0],
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "nuHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.nuHat_CSTATE[0],
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "nuHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.bHat_CSTATE[0],
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "bHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.bHat_CSTATE[0],
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "bHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.bHat_CSTATE[0],
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "bHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_b[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_b");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_b[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_b");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_b[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_b");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.reset_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_ship_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_ship_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_ship_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_ship_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PSI_ship_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PSI_ship_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.res_ship_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.res_ship_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_hat_DWORK1, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_hat_DWORK1, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_hat_DWORK1, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.dropOutTolerance_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.dropOutTolerance_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Residual_DWORK1, 0, 22, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Residual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Residual_DWORK1, 1, 22, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Residual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_tilde_DWORK1, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_tilde_DWORK1, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_tilde_DWORK1, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.NoisePowPos_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.NoisePowPos_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_c,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.NoisePowHead_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.NoisePowHead_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_p,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.NoiseEnable_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.NoiseEnable_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_noise_DWORK1, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_noise_DWORK1, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_noise_DWORK1, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ControllerGainK2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ControllerGainK2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC_FirstOutputTime, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC_FirstOutputTime");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_m, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory2_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory1_PreviousInput, 0, 22, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory1_PreviousInput, 1, 22, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC_FirstOutputTime_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC_FirstOutputTime_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ControllerGainK1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ControllerGainK1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Select_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Select_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.CurrentMode_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.CurrentMode_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosXRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosYRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosYRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_yaw_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_yaw_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.tau_x_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.tau_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.tau_y_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.tau_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosXLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosYLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowDown_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowDown_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowUp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.JoysticControllerSwitch_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.JoysticControllerSwitch_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Tau_pre_DWORK1, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Tau_pre_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Tau_pre_DWORK1, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Tau_pre_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Tau_pre_DWORK1, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Tau_pre_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_d, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_d, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_d, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.sf1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.sf1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_e, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.SZ_ResetKill_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.SZ_ResetKill_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.SZ_Owerwrite_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.SZ_Owerwrite_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Tau_post_DWORK1, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Tau_post_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Tau_post_DWORK1, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Tau_post_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Tau_post_DWORK1, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Tau_post_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.P_d_DWORK1, 0,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.P_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.P_d_DWORK1, 1,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.P_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.dropoutFlag_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.dropoutFlag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.sf2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.sf2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.sf3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.sf3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.biasOffset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.biasOffset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.integratorresetmodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC1_FirstOutputTime, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC1_FirstOutputTime");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC_FirstOutputTime_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC_FirstOutputTime_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_real_DWORK1, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_real_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_real_DWORK1, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_real_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_real_DWORK1, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_real_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.TurnOffomega1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.TurnOffomega1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.TurnOffomega2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.TurnOffomega2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.f_bt_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.f_bt_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.f_vspx_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.f_vspx_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.f_vspy_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.f_vspy_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_real_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_real_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.controlinputuexceedsbounds_DWOR, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.controlinputuexceedsbounds_DWOR");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP1_DWORK1_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP1_DWORK1_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP2_DWORK1_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP2_DWORK1_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP1_DWORK1_b, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP1_DWORK1_b");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP2_DWORK1_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP2_DWORK1_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1_j,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK1_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.u_VSP1_DWORK1_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.u_VSP1_DWORK1_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.u_VSP2_DWORK1_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.u_VSP2_DWORK1_o");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Eta_dss_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Eta_dss_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToWorkspace3_PWORK, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToWorkspace3_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope1_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope1_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope2_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope2_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope3_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope3_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK_d,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope_PWORK_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Scope1_PWORK_j, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Scope1_PWORK_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Scope2_PWORK_k, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Scope2_PWORK_k");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Scope3_PWORK_b, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Scope3_PWORK_b");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Scope1_PWORK_e, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Scope1_PWORK_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Scope2_PWORK_m, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Scope2_PWORK_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Scope3_PWORK_d, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Scope3_PWORK_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope4_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope4_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Scope_PWORK_db, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Scope_PWORK_db");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Scope1_PWORK_d, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Scope1_PWORK_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Scope3_PWORK_bj, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Scope3_PWORK_bj");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Scope4_PWORK_k, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Scope4_PWORK_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope_s_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope_s_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Scope_s_inn_PWORK, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Scope_s_inn_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Scope_switch_PWORK, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Scope_switch_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Flag_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Flag_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.SwitchSig_PWORK, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.SwitchSig_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.U_scope_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.U_scope_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_j, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_c, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.etaHat1_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.etaHat1_IWORK.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Integrator1_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Integrator1_IWORK.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading");
    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.reset_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.reset_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.X_ship_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.X_ship_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Y_ship_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Y_ship_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PSI_ship_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PSI_ship_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.res_ship_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.res_ship_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_hat_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.dropOutTolerance_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.dropOutTolerance_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Residual_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Residual_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_tilde_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_tilde_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NoisePowPos_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NoisePowPos_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NoisePowHead_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NoisePowHead_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NoiseEnable_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NoiseEnable_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_noise_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_noise_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ControllerGainK2_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ControllerGainK2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ControllerGainK1_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ControllerGainK1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L2_continuous_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Select_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Select_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.CurrentMode_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.CurrentMode_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXRight_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYRight_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.R2_continuous_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_yaw_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_yaw_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_x_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_y_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXLeft_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYLeft_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowDown_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowUp_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowRight_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.JoysticControllerSwitch_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.JoysticControllerSwitch_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Tau_pre_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Tau_pre_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.sf1_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.sf1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.SZ_ResetKill_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.SZ_ResetKill_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.SZ_Owerwrite_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.SZ_Owerwrite_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Tau_post_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Tau_post_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.P_d_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.P_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.dropoutFlag_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.dropoutFlag_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.sf2_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.sf2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.sf3_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.sf3_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.biasOffset_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.biasOffset_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_0_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.integratorresetmodel_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_real_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_real_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.TurnOffomega1_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.TurnOffomega1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.TurnOffomega2_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.TurnOffomega2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP1_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP2_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.f_bt_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.f_bt_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.f_vspx_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.f_vspx_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.f_vspy_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.f_vspy_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_in_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_real_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_real_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.controlinputuexceedsbounds_DW_g, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.controlinputuexceedsbounds_DW_g");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP1_DWORK2_i, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP1_DWORK2_i");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP2_DWORK2_k, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP2_DWORK2_k");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP1_DWORK2_h, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP1_DWORK2_h");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP2_DWORK2_f, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP2_DWORK2_f");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_BT_DWORK2_k, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_BT_DWORK2_k");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP1_DWORK2_f, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP1_DWORK2_f");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP2_DWORK2_b, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP2_DWORK2_b");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 60; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3, count, 26, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3");
    }
  }

  if (clockTicks && clockTicksNames) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_SetSimState(double* contStates, double* discStates, long
  * clockTicks)
{
  long count, idx;
  if (contStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.etaHat_CSTATE, 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.etaHat2_CSTATE, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.etaHat1_CSTATE, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_f, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.nuHat_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.nuHat_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.nuHat_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.bHat_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.bHat_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.bHat_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_b[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_b[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_b[0], 2,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.reset_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_ship_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_ship_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PSI_ship_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.res_ship_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_DWORK1, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.dropOutTolerance_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Residual_DWORK1, 0,
      discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Residual_DWORK1, 1,
      discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_DWORK1, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NoisePowPos_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_c, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NoisePowHead_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_p, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NoiseEnable_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_noise_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_noise_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_noise_DWORK1, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ControllerGainK2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_f, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory2_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput, 0,
      discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput, 1,
      discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC_FirstOutputTime_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ControllerGainK1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Select_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.CurrentMode_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_yaw_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_x_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_y_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.JoysticControllerSwitch_DWORK1,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_pre_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_pre_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_pre_DWORK1, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_d, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_d, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_d, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_e, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SZ_ResetKill_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SZ_Owerwrite_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_post_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_post_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_post_DWORK1, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.P_d_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.P_d_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.dropoutFlag_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.biasOffset_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC1_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC_FirstOutputTime_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_real_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_real_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_real_DWORK1, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.TurnOffomega1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.TurnOffomega2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.f_bt_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.f_vspx_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.f_vspy_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_real_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.controlinputuexceedsbounds_DWOR,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK1_o, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK1_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK1_b, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK1_c, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1_j, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1_o, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1_o, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Eta_dss_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToWorkspace3_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope1_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope2_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope3_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK_d, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope1_PWORK_j, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope2_PWORK_k, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope3_PWORK_b, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope1_PWORK_e, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope2_PWORK_m, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope3_PWORK_d, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope4_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK_db, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope1_PWORK_d, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope3_PWORK_bj, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope4_PWORK_k, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope_s_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope_s_inn_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope_switch_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Flag_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SwitchSig_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.U_scope_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2,
      0, discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_j, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_c, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.etaHat1_IWORK.IcNeedsLoading, 0,
      discStates[idx++], 10, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_DW.Integrator1_IWORK.IcNeedsLoading, 0, discStates[idx
       ++], 10, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading,
      0, discStates[idx++], 10, 0);
    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.reset_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_ship_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_ship_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PSI_ship_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.res_ship_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.dropOutTolerance_DWORK2,
        count, discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Residual_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NoisePowPos_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NoisePowHead_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NoiseEnable_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_noise_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ControllerGainK2_DWORK2,
        count, discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ControllerGainK1_DWORK2,
        count, discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Select_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.CurrentMode_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_yaw_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_x_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_y_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_DW.JoysticControllerSwitch_DWORK2, count,
         discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_pre_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf1_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SZ_ResetKill_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SZ_Owerwrite_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_post_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.P_d_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.dropoutFlag_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf2_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf3_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.biasOffset_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK2,
        count, discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_real_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.TurnOffomega1_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.TurnOffomega2_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.f_bt_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.f_vspx_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.f_vspy_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_real_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_DW.controlinputuexceedsbounds_DW_g, count,
         discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK2_i, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK2_k, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK2_h, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK2_f, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2_k, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK2_f, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK2_b, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1,
        count, discStates[idx++], 24, 0);
    }

    for (count = 0; count < 60; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3,
        count, discStates[idx++], 26, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student_HIL
