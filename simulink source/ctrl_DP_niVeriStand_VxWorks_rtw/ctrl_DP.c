/*
 * ctrl_DP.c
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

/* Block signals (auto storage) */
B_ctrl_DP_T ctrl_DP_B;

/* Continuous states */
X_ctrl_DP_T ctrl_DP_X;

/* Block states (auto storage) */
DW_ctrl_DP_T ctrl_DP_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_DP_T ctrl_DP_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_DP_T ctrl_DP_M_;
RT_MODEL_ctrl_DP_T *const ctrl_DP_M = &ctrl_DP_M_;

/* Forward declaration for local functions */
static void ctrl_DP_mldivide(const real_T A[9], const real_T B[3], real_T Y[3]);

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_DP_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_DP_output();
  ctrl_DP_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_DP_output();
  ctrl_DP_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_DP_output();
  ctrl_DP_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S17>/MATLAB Function'
 *    '<S17>/MATLAB Function3'
 *    '<S17>/MATLAB Function4'
 */
void ctrl_DP_MATLABFunction(real_T rtu_K_p1, real_T rtu_K_p1_c, real_T
  rtu_K_p1_h, B_MATLABFunction_ctrl_DP_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function': '<S19>:1' */
  /* '<S19>:1:4' */
  memset(&localB->K_p[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S19>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_p[0] = rtu_K_p1;
  localB->K_p[4] = rtu_K_p1_c;
  localB->K_p[8] = rtu_K_p1_h;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = u0 / u1;
      if (fabs(u1_0 - rt_roundd_snf(u1_0)) <= DBL_EPSILON * fabs(u1_0)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S33>/Thrust allocation' */
static void ctrl_DP_mldivide(const real_T A[9], const real_T B[3], real_T Y[3])
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

/* Model output function */
void ctrl_DP_output(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator2[3];
  real_T rtb_MatrixMultiply4[3];
  static const real_T b[9] = { 1.165, 0.0, 0.0, 0.0, 1.165, 0.0, 0.0, 0.0, 2.629
  };

  static const real_T c[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, -0.4575, 0.0, 1.0,
    0.3875 };

  boolean_T firstmult;
  int32_T p1;
  int32_T p3;
  int32_T itmp;
  real_T rtb_Row3_l;
  real_T rtb_Row2;
  real_T rtb_Row1;
  real_T rtb_Row3;
  real_T rtb_TmpSignalConversionAtMatrix[3];
  real_T rtb_TmpSignalConversionAtSFu_di[3];
  real_T rtb_Sum3[3];
  real_T rtb_K_i[9];
  real_T rtb_K_d[9];
  real_T rtb_w_d[9];
  real_T rtb_Zeta[9];
  int32_T i;
  real_T tmp[3];
  real_T rtb_w_d_0[9];
  real_T tmp_0[3];
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* set solver stop time */
    if (!(ctrl_DP_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_DP_M->solverInfo,
                            ((ctrl_DP_M->Timing.clockTickH0 + 1) *
        ctrl_DP_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_DP_M->solverInfo,
                            ((ctrl_DP_M->Timing.clockTick0 + 1) *
        ctrl_DP_M->Timing.stepSize0 + ctrl_DP_M->Timing.clockTickH0 *
        ctrl_DP_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_DP_M)) {
    ctrl_DP_M->Timing.t[0] = rtsiGetT(&ctrl_DP_M->solverInfo);
  }

  /* MATLAB Function: '<S17>/MATLAB Function' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.K_p_x, ctrl_DP_B.K_p_y, ctrl_DP_B.K_p_psi,
    &ctrl_DP_B.sf_MATLABFunction);

  /* MATLAB Function 'Input/Control Gains/MATLAB Function1': '<S20>:1' */
  /* '<S20>:1:4' */
  for (i = 0; i < 9; i++) {
    /* MATLAB Function: '<S17>/MATLAB Function1' */
    rtb_K_i[i] = 0.0;

    /* MATLAB Function: '<S17>/MATLAB Function2' */
    rtb_K_d[i] = 0.0;
  }

  /* MATLAB Function: '<S17>/MATLAB Function1' incorporates:
   *  SignalConversion: '<S20>/TmpSignal ConversionAt SFunction Inport1'
   */
  rtb_K_i[0] = ctrl_DP_B.K_i_x;
  rtb_K_i[4] = ctrl_DP_B.K_i_y;
  rtb_K_i[8] = ctrl_DP_B.K_i_psi;

  /* MATLAB Function: '<S17>/MATLAB Function2' incorporates:
   *  SignalConversion: '<S21>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Input/Control Gains/MATLAB Function2': '<S21>:1' */
  /* '<S21>:1:4' */
  rtb_K_d[0] = ctrl_DP_B.K_d_x;
  rtb_K_d[4] = ctrl_DP_B.K_d_y;
  rtb_K_d[8] = ctrl_DP_B.K_d_psi;

  /* MATLAB Function: '<S17>/MATLAB Function3' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.K_ff_u, ctrl_DP_B.K_ff_v, ctrl_DP_B.K_ff_r,
    &ctrl_DP_B.sf_MATLABFunction3);

  /* MATLAB Function: '<S17>/MATLAB Function4' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.K_ff_u_dot, ctrl_DP_B.K_ff_v_dot,
    ctrl_DP_B.K_ff_r_dot, &ctrl_DP_B.sf_MATLABFunction4);

  /* MATLAB Function 'Input/Guidance gains/diag': '<S24>:1' */
  /* '<S24>:1:4' */
  for (i = 0; i < 9; i++) {
    /* MATLAB Function: '<S18>/diag' */
    rtb_w_d[i] = 0.0;

    /* MATLAB Function: '<S18>/diag1' */
    rtb_Zeta[i] = 0.0;
  }

  /* MATLAB Function: '<S18>/diag' incorporates:
   *  SignalConversion: '<S24>/TmpSignal ConversionAt SFunction Inport1'
   */
  rtb_w_d[0] = ctrl_DP_B.w_d_x;
  rtb_w_d[4] = ctrl_DP_B.w_d_y;
  rtb_w_d[8] = ctrl_DP_B.w_d_psi;

  /* MATLAB Function: '<S18>/diag1' incorporates:
   *  SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Input/Guidance gains/diag1': '<S25>:1' */
  /* '<S25>:1:4' */
  rtb_Zeta[0] = ctrl_DP_B.zeta_x;
  rtb_Zeta[4] = ctrl_DP_B.zeta_y;
  rtb_Zeta[8] = ctrl_DP_B.zeta_psi;

  /* Saturate: '<S11>/Saturation' incorporates:
   *  Fcn: '<S6>/yaw angle'
   */
  if (ctrl_DP_B.psi > ctrl_DP_P.Saturation_UpperSat) {
    rtb_Row3_l = ctrl_DP_P.Saturation_UpperSat;
  } else if (ctrl_DP_B.psi < ctrl_DP_P.Saturation_LowerSat) {
    rtb_Row3_l = ctrl_DP_P.Saturation_LowerSat;
  } else {
    rtb_Row3_l = ctrl_DP_B.psi;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Signum: '<S11>/Sign' */
  if (rtb_Row3_l < 0.0) {
    rtb_Row1 = -1.0;
  } else if (rtb_Row3_l > 0.0) {
    rtb_Row1 = 1.0;
  } else if (rtb_Row3_l == 0.0) {
    rtb_Row1 = 0.0;
  } else {
    rtb_Row1 = rtb_Row3_l;
  }

  /* Gain: '<S11>/Gain' incorporates:
   *  Signum: '<S11>/Sign'
   */
  rtb_Row2 = ctrl_DP_P.Gain_Gain * rtb_Row1;

  /* Sum: '<S11>/Sum1' */
  rtb_Row3_l += rtb_Row2;

  /* Math: '<S11>/Math Function' incorporates:
   *  Constant: '<S11>/Constant'
   */
  rtb_Row3_l = rt_remd_snf(rtb_Row3_l, ctrl_DP_P.Constant_Value);

  /* Sum: '<S11>/Sum' */
  rtb_Row3_l -= rtb_Row2;

  /* Integrator: '<S12>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_DP_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_DP_DW.Integrator1_IWORK.IcNeedsLoading) {
      ctrl_DP_X.Integrator1_CSTATE[0] = ctrl_DP_B.x;
      ctrl_DP_X.Integrator1_CSTATE[1] = ctrl_DP_B.y;
      ctrl_DP_X.Integrator1_CSTATE[2] = ctrl_DP_B.psi;
    }
  }

  ctrl_DP_B.Integrator1[0] = ctrl_DP_X.Integrator1_CSTATE[0];
  ctrl_DP_B.Integrator1[1] = ctrl_DP_X.Integrator1_CSTATE[1];
  ctrl_DP_B.Integrator1[2] = ctrl_DP_X.Integrator1_CSTATE[2];

  /* Sum: '<S6>/Sum2' */
  rtb_TmpSignalConversionAtSFu_di[0] = ctrl_DP_B.x - ctrl_DP_B.Integrator1[0];
  rtb_TmpSignalConversionAtSFu_di[1] = ctrl_DP_B.y - ctrl_DP_B.Integrator1[1];
  rtb_TmpSignalConversionAtSFu_di[2] = ctrl_DP_B.psi - ctrl_DP_B.Integrator1[2];

  /* Saturate: '<S10>/Saturation' */
  if (rtb_TmpSignalConversionAtSFu_di[2] > ctrl_DP_P.Saturation_UpperSat_g) {
    rtb_Row2 = ctrl_DP_P.Saturation_UpperSat_g;
  } else if (rtb_TmpSignalConversionAtSFu_di[2] <
             ctrl_DP_P.Saturation_LowerSat_b) {
    rtb_Row2 = ctrl_DP_P.Saturation_LowerSat_b;
  } else {
    rtb_Row2 = rtb_TmpSignalConversionAtSFu_di[2];
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Signum: '<S10>/Sign' */
  if (rtb_Row2 < 0.0) {
    rtb_Row1 = -1.0;
  } else if (rtb_Row2 > 0.0) {
    rtb_Row1 = 1.0;
  } else if (rtb_Row2 == 0.0) {
    rtb_Row1 = 0.0;
  } else {
    rtb_Row1 = rtb_Row2;
  }

  /* Gain: '<S10>/Gain' incorporates:
   *  Signum: '<S10>/Sign'
   */
  rtb_Row1 *= ctrl_DP_P.Gain_Gain_e;

  /* Sum: '<S10>/Sum1' */
  rtb_Row2 += rtb_Row1;

  /* Math: '<S10>/Math Function' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_Row2 = rt_remd_snf(rtb_Row2, ctrl_DP_P.Constant_Value_n);

  /* Sum: '<S10>/Sum' */
  rtb_Row2 -= rtb_Row1;

  /* SignalConversion: '<S6>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Fcn: '<S7>/Row1'
   *  Fcn: '<S7>/Row2'
   *  Fcn: '<S7>/Row3'
   */
  ctrl_DP_B.TmpSignalConversionAtMatrixMult[0] = cos(rtb_Row3_l) *
    rtb_TmpSignalConversionAtSFu_di[0] + sin(rtb_Row3_l) *
    rtb_TmpSignalConversionAtSFu_di[1];
  ctrl_DP_B.TmpSignalConversionAtMatrixMult[1] = -sin(rtb_Row3_l) *
    rtb_TmpSignalConversionAtSFu_di[0] + cos(rtb_Row3_l) *
    rtb_TmpSignalConversionAtSFu_di[1];
  ctrl_DP_B.TmpSignalConversionAtMatrixMult[2] = rtb_Row2;

  /* Product: '<S6>/Matrix Multiply' */
  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtSFu_di[i] = ctrl_DP_B.sf_MATLABFunction.K_p[i + 6] *
      ctrl_DP_B.TmpSignalConversionAtMatrixMult[2] +
      (ctrl_DP_B.sf_MATLABFunction.K_p[i + 3] *
       ctrl_DP_B.TmpSignalConversionAtMatrixMult[1] +
       ctrl_DP_B.sf_MATLABFunction.K_p[i] *
       ctrl_DP_B.TmpSignalConversionAtMatrixMult[0]);
  }

  /* End of Product: '<S6>/Matrix Multiply' */

  /* Integrator: '<S6>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_DP_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_X.Integrator_CSTATE[0] = ctrl_DP_P.Integrator_IC;
      ctrl_DP_X.Integrator_CSTATE[1] = ctrl_DP_P.Integrator_IC;
      ctrl_DP_X.Integrator_CSTATE[2] = ctrl_DP_P.Integrator_IC;
    }
  }

  rtb_MatrixMultiply4[0] = ctrl_DP_X.Integrator_CSTATE[0];
  rtb_MatrixMultiply4[1] = ctrl_DP_X.Integrator_CSTATE[1];
  rtb_MatrixMultiply4[2] = ctrl_DP_X.Integrator_CSTATE[2];

  /* Product: '<S6>/Matrix Multiply1' */
  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtMatrix[i] = rtb_K_i[i + 6] * rtb_MatrixMultiply4[2]
      + (rtb_K_i[i + 3] * rtb_MatrixMultiply4[1] + rtb_K_i[i] *
         rtb_MatrixMultiply4[0]);
  }

  /* End of Product: '<S6>/Matrix Multiply1' */

  /* Fcn: '<S6>/yaw angle1' */
  rtb_Row3 = ctrl_DP_B.Integrator1[2];

  /* Integrator: '<S12>/Integrator3' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator3_Reset_ZCE,
                       ctrl_DP_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_X.Integrator3_CSTATE[0] = ctrl_DP_P.Integrator3_IC;
      ctrl_DP_X.Integrator3_CSTATE[1] = ctrl_DP_P.Integrator3_IC;
      ctrl_DP_X.Integrator3_CSTATE[2] = ctrl_DP_P.Integrator3_IC;
    }
  }

  ctrl_DP_B.Integrator3[0] = ctrl_DP_X.Integrator3_CSTATE[0];
  ctrl_DP_B.Integrator3[1] = ctrl_DP_X.Integrator3_CSTATE[1];
  ctrl_DP_B.Integrator3[2] = ctrl_DP_X.Integrator3_CSTATE[2];

  /* SignalConversion: '<S6>/TmpSignal ConversionAtMatrix Multiply3Inport2' incorporates:
   *  Fcn: '<S8>/Row1'
   *  Fcn: '<S8>/Row2'
   *  Fcn: '<S8>/Row3'
   */
  rtb_MatrixMultiply4[0] = cos(rtb_Row3) * ctrl_DP_B.Integrator3[0] + sin
    (rtb_Row3) * ctrl_DP_B.Integrator3[1];
  rtb_MatrixMultiply4[1] = -sin(rtb_Row3) * ctrl_DP_B.Integrator3[0] + cos
    (rtb_Row3) * ctrl_DP_B.Integrator3[1];
  rtb_MatrixMultiply4[2] = ctrl_DP_B.Integrator3[2];

  /* Sum: '<S6>/Sum4' */
  rtb_Integrator2[0] = ctrl_DP_B.u_hat - rtb_MatrixMultiply4[0];
  rtb_Integrator2[1] = ctrl_DP_B.v_hat - rtb_MatrixMultiply4[1];
  rtb_Integrator2[2] = ctrl_DP_B.r_hat - rtb_MatrixMultiply4[2];

  /* Sum: '<S6>/Sum3' incorporates:
   *  Product: '<S6>/Matrix Multiply2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum3[i] = ((0.0 - rtb_TmpSignalConversionAtSFu_di[i]) -
                   rtb_TmpSignalConversionAtMatrix[i]) - ((rtb_K_d[i + 3] *
      rtb_Integrator2[1] + rtb_K_d[i] * rtb_Integrator2[0]) + rtb_K_d[i + 6] *
      rtb_Integrator2[2]);
  }

  /* End of Sum: '<S6>/Sum3' */

  /* Product: '<S6>/Matrix Multiply3' */
  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtSFu_di[i] = ctrl_DP_B.sf_MATLABFunction3.K_p[i + 6]
      * rtb_MatrixMultiply4[2] + (ctrl_DP_B.sf_MATLABFunction3.K_p[i + 3] *
      rtb_MatrixMultiply4[1] + ctrl_DP_B.sf_MATLABFunction3.K_p[i] *
      rtb_MatrixMultiply4[0]);
  }

  /* End of Product: '<S6>/Matrix Multiply3' */

  /* Integrator: '<S12>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator2_Reset_ZCE,
                       ctrl_DP_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_X.Integrator2_CSTATE[0] = ctrl_DP_P.Integrator2_IC;
      ctrl_DP_X.Integrator2_CSTATE[1] = ctrl_DP_P.Integrator2_IC;
      ctrl_DP_X.Integrator2_CSTATE[2] = ctrl_DP_P.Integrator2_IC;
    }
  }

  rtb_Integrator2[0] = ctrl_DP_X.Integrator2_CSTATE[0];
  rtb_Integrator2[1] = ctrl_DP_X.Integrator2_CSTATE[1];
  rtb_Integrator2[2] = ctrl_DP_X.Integrator2_CSTATE[2];

  /* MATLAB Function: '<S12>/w_d*w_d' incorporates:
   *  Product: '<S12>/Matrix Multiply2'
   */
  /* MATLAB Function 'Guidance/Reference model/w_d*w_d': '<S13>:1' */
  /* '<S13>:1:4' */
  /* MATLAB Function 'Guidance/Reference model/w_d*w_d1': '<S14>:1' */
  /* '<S14>:1:4' */
  for (i = 0; i < 3; i++) {
    for (p3 = 0; p3 < 3; p3++) {
      rtb_w_d_0[i + 3 * p3] = 0.0;
      rtb_w_d_0[i + 3 * p3] += rtb_w_d[3 * p3] * rtb_w_d[i];
      rtb_w_d_0[i + 3 * p3] += rtb_w_d[3 * p3 + 1] * rtb_w_d[i + 3];
      rtb_w_d_0[i + 3 * p3] += rtb_w_d[3 * p3 + 2] * rtb_w_d[i + 6];
    }
  }

  /* End of MATLAB Function: '<S12>/w_d*w_d' */

  /* MATLAB Function: '<S12>/w_d*w_d1' incorporates:
   *  Product: '<S12>/Matrix Multiply5'
   */
  for (i = 0; i < 3; i++) {
    for (p3 = 0; p3 < 3; p3++) {
      rtb_K_i[i + 3 * p3] = 0.0;
      rtb_K_i[i + 3 * p3] += 2.0 * rtb_Zeta[i] * rtb_w_d[3 * p3];
      rtb_K_i[i + 3 * p3] += rtb_Zeta[i + 3] * 2.0 * rtb_w_d[3 * p3 + 1];
      rtb_K_i[i + 3 * p3] += rtb_Zeta[i + 6] * 2.0 * rtb_w_d[3 * p3 + 2];
    }
  }

  /* End of MATLAB Function: '<S12>/w_d*w_d1' */

  /* Sum: '<S12>/Sum2' incorporates:
   *  Product: '<S12>/Matrix Multiply2'
   *  Sum: '<S12>/Sum5'
   */
  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtMatrix[i] = rtb_Integrator2[i] - ((rtb_w_d_0[i + 3]
      * ctrl_DP_B.Integrator1[1] + rtb_w_d_0[i] * ctrl_DP_B.Integrator1[0]) +
      rtb_w_d_0[i + 6] * ctrl_DP_B.Integrator1[2]);
  }

  /* End of Sum: '<S12>/Sum2' */

  /* Product: '<S12>/Matrix Multiply5' incorporates:
   *  Sum: '<S12>/Sum5'
   */
  for (i = 0; i < 3; i++) {
    tmp_0[i] = rtb_K_i[i + 6] * ctrl_DP_B.Integrator3[2] + (rtb_K_i[i + 3] *
      ctrl_DP_B.Integrator3[1] + rtb_K_i[i] * ctrl_DP_B.Integrator3[0]);
  }

  /* Sum: '<S12>/Sum5' */
  ctrl_DP_B.Sum5[0] = rtb_TmpSignalConversionAtMatrix[0] - tmp_0[0];
  ctrl_DP_B.Sum5[1] = rtb_TmpSignalConversionAtMatrix[1] - tmp_0[1];
  ctrl_DP_B.Sum5[2] = rtb_TmpSignalConversionAtMatrix[2] - tmp_0[2];

  /* Fcn: '<S9>/Row1' */
  rtb_Row1 = cos(rtb_Row3) * ctrl_DP_B.Sum5[0] + sin(rtb_Row3) * ctrl_DP_B.Sum5
    [1];

  /* Fcn: '<S9>/Row2' */
  rtb_Row2 = -sin(rtb_Row3) * ctrl_DP_B.Sum5[0] + cos(rtb_Row3) *
    ctrl_DP_B.Sum5[1];

  /* Product: '<S6>/Matrix Multiply4' incorporates:
   *  Fcn: '<S9>/Row3'
   *  SignalConversion: '<S6>/TmpSignal ConversionAtMatrix Multiply4Inport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_MatrixMultiply4[i] = 0.0;
    rtb_MatrixMultiply4[i] += ctrl_DP_B.sf_MATLABFunction4.K_p[i] * rtb_Row1;
    rtb_MatrixMultiply4[i] += ctrl_DP_B.sf_MATLABFunction4.K_p[i + 3] * rtb_Row2;
    rtb_MatrixMultiply4[i] += ctrl_DP_B.sf_MATLABFunction4.K_p[i + 6] *
      ctrl_DP_B.Sum5[2];
  }

  /* End of Product: '<S6>/Matrix Multiply4' */

  /* Sum: '<S6>/Sum1' incorporates:
   *  Sum: '<S6>/Sum5'
   */
  ctrl_DP_B.Sum1[0] = (rtb_TmpSignalConversionAtSFu_di[0] + rtb_MatrixMultiply4
                       [0]) + rtb_Sum3[0];
  ctrl_DP_B.Sum1[1] = (rtb_TmpSignalConversionAtSFu_di[1] + rtb_MatrixMultiply4
                       [1]) + rtb_Sum3[1];
  ctrl_DP_B.Sum1[2] = (rtb_TmpSignalConversionAtSFu_di[2] + rtb_MatrixMultiply4
                       [2]) + rtb_Sum3[2];

  /* MATLAB Function: '<S33>/Thrust allocation' */
  /* MATLAB Function 'Thrust allocation/linear thrust allocation/Thrust allocation': '<S34>:1' */
  /*  Forces and moments vector */
  /* '<S34>:1:4' */
  /*  Extended thrust configuration matrix */
  /*  Extended thrust coefficient matrix */
  /*  tau = T*K*u inverse */
  /* '<S34>:1:23' */
  tmp[0] = ctrl_DP_B.Sum1[0];
  tmp[1] = ctrl_DP_B.Sum1[1];
  tmp[2] = ctrl_DP_B.Sum1[2];
  ctrl_DP_mldivide(c, tmp, rtb_TmpSignalConversionAtMatrix);
  ctrl_DP_mldivide(b, rtb_TmpSignalConversionAtMatrix,
                   rtb_TmpSignalConversionAtSFu_di);

  /* '<S34>:1:25' */
  /* '<S34>:1:27' */
  /* '<S34>:1:28' */
  /* '<S34>:1:29' */
  /* '<S34>:1:30' */
  if (ctrl_DP_B.VSP_on != 0.0) {
    /* '<S34>:1:33' */
    ctrl_DP_B.omega_VSP = 0.3;
  } else {
    /* '<S34>:1:35' */
    ctrl_DP_B.omega_VSP = 0.0;
  }

  ctrl_DP_B.u_BT = rtb_TmpSignalConversionAtSFu_di[2];
  ctrl_DP_B.u_VSP = sqrt(rtb_TmpSignalConversionAtSFu_di[0] *
    rtb_TmpSignalConversionAtSFu_di[0] + rtb_TmpSignalConversionAtSFu_di[1] *
    rtb_TmpSignalConversionAtSFu_di[1]);
  ctrl_DP_B.alpha_VSP = rt_atan2d_snf(rtb_TmpSignalConversionAtSFu_di[1],
    rtb_TmpSignalConversionAtSFu_di[0]);

  /* End of MATLAB Function: '<S33>/Thrust allocation' */

  /* MATLAB Function: '<S12>/w_d^3' */
  /* MATLAB Function 'Guidance/Reference model/w_d^3': '<S16>:1' */
  /* '<S16>:1:4' */
  memcpy(&rtb_K_i[0], &rtb_w_d[0], 9U * sizeof(real_T));
  rtb_Row3_l = 3.0;
  firstmult = true;
  do {
    p1 = 0;
    rtb_Row2 = floor(rtb_Row3_l / 2.0);
    if (2.0 * rtb_Row2 != rtb_Row3_l) {
      if (firstmult) {
        memcpy(&rtb_K_d[0], &rtb_K_i[0], 9U * sizeof(real_T));
        firstmult = false;
      } else {
        for (i = 0; i < 3; i++) {
          for (p3 = 0; p3 < 3; p3++) {
            rtb_w_d_0[i + 3 * p3] = 0.0;
            rtb_w_d_0[i + 3 * p3] += rtb_K_i[3 * p3] * rtb_K_d[i];
            rtb_w_d_0[i + 3 * p3] += rtb_K_i[3 * p3 + 1] * rtb_K_d[i + 3];
            rtb_w_d_0[i + 3 * p3] += rtb_K_i[3 * p3 + 2] * rtb_K_d[i + 6];
          }
        }

        for (i = 0; i < 3; i++) {
          rtb_K_d[3 * i] = rtb_w_d_0[3 * i];
          rtb_K_d[1 + 3 * i] = rtb_w_d_0[3 * i + 1];
          rtb_K_d[2 + 3 * i] = rtb_w_d_0[3 * i + 2];
        }
      }
    }

    if (rtb_Row2 == 0.0) {
      p1 = 1;
    } else {
      rtb_Row3_l = rtb_Row2;
      for (i = 0; i < 3; i++) {
        for (p3 = 0; p3 < 3; p3++) {
          rtb_w_d_0[i + 3 * p3] = 0.0;
          rtb_w_d_0[i + 3 * p3] += rtb_K_i[3 * p3] * rtb_K_i[i];
          rtb_w_d_0[i + 3 * p3] += rtb_K_i[3 * p3 + 1] * rtb_K_i[i + 3];
          rtb_w_d_0[i + 3 * p3] += rtb_K_i[3 * p3 + 2] * rtb_K_i[i + 6];
        }
      }

      for (i = 0; i < 3; i++) {
        rtb_K_i[3 * i] = rtb_w_d_0[3 * i];
        rtb_K_i[1 + 3 * i] = rtb_w_d_0[3 * i + 1];
        rtb_K_i[2 + 3 * i] = rtb_w_d_0[3 * i + 2];
      }
    }
  } while (p1 == 0);

  /* End of MATLAB Function: '<S12>/w_d^3' */

  /* MATLAB Function: '<S12>/w_d^-2' */
  /* MATLAB Function 'Guidance/Reference model/w_d^-2': '<S15>:1' */
  /* '<S15>:1:4' */
  for (i = 0; i < 3; i++) {
    for (p3 = 0; p3 < 3; p3++) {
      rtb_K_i[i + 3 * p3] = 0.0;
      rtb_K_i[i + 3 * p3] += rtb_w_d[3 * p3] * rtb_w_d[i];
      rtb_K_i[i + 3 * p3] += rtb_w_d[3 * p3 + 1] * rtb_w_d[i + 3];
      rtb_K_i[i + 3 * p3] += rtb_w_d[3 * p3 + 2] * rtb_w_d[i + 6];
    }
  }

  memcpy(&rtb_w_d_0[0], &rtb_K_i[0], 9U * sizeof(real_T));
  p1 = 0;
  i = 3;
  p3 = 6;
  rtb_Row3_l = fabs(rtb_K_i[0]);
  rtb_Row2 = fabs(rtb_K_i[1]);
  rtb_Row1 = fabs(rtb_K_i[2]);
  if ((rtb_Row2 > rtb_Row3_l) && (rtb_Row2 > rtb_Row1)) {
    p1 = 3;
    i = 0;
    rtb_w_d_0[0] = rtb_K_i[1];
    rtb_w_d_0[1] = rtb_K_i[0];
    rtb_w_d_0[3] = rtb_K_i[4];
    rtb_w_d_0[4] = rtb_K_i[3];
    rtb_w_d_0[6] = rtb_K_i[7];
    rtb_w_d_0[7] = rtb_K_i[6];
  } else {
    if (rtb_Row1 > rtb_Row3_l) {
      p1 = 6;
      p3 = 0;
      rtb_w_d_0[0] = rtb_K_i[2];
      rtb_w_d_0[2] = rtb_K_i[0];
      rtb_w_d_0[3] = rtb_K_i[5];
      rtb_w_d_0[5] = rtb_K_i[3];
      rtb_w_d_0[6] = rtb_K_i[8];
      rtb_w_d_0[8] = rtb_K_i[6];
    }
  }

  rtb_Row3_l = rtb_w_d_0[1] / rtb_w_d_0[0];
  rtb_w_d_0[1] /= rtb_w_d_0[0];
  rtb_Row2 = rtb_w_d_0[2] / rtb_w_d_0[0];
  rtb_w_d_0[2] /= rtb_w_d_0[0];
  rtb_w_d_0[4] -= rtb_Row3_l * rtb_w_d_0[3];
  rtb_w_d_0[5] -= rtb_Row2 * rtb_w_d_0[3];
  rtb_w_d_0[7] -= rtb_Row3_l * rtb_w_d_0[6];
  rtb_w_d_0[8] -= rtb_Row2 * rtb_w_d_0[6];
  if (fabs(rtb_w_d_0[5]) > fabs(rtb_w_d_0[4])) {
    itmp = i;
    i = p3;
    p3 = itmp;
    rtb_w_d_0[1] = rtb_Row2;
    rtb_w_d_0[2] = rtb_Row3_l;
    rtb_Row3_l = rtb_w_d_0[4];
    rtb_w_d_0[4] = rtb_w_d_0[5];
    rtb_w_d_0[5] = rtb_Row3_l;
    rtb_Row3_l = rtb_w_d_0[7];
    rtb_w_d_0[7] = rtb_w_d_0[8];
    rtb_w_d_0[8] = rtb_Row3_l;
  }

  rtb_Row1 = rtb_w_d_0[5];
  rtb_Row3 = rtb_w_d_0[4];
  rtb_Row3_l = rtb_w_d_0[5] / rtb_w_d_0[4];
  rtb_w_d_0[8] -= rtb_Row3_l * rtb_w_d_0[7];
  rtb_Row3_l = (rtb_Row3_l * rtb_w_d_0[1] - rtb_w_d_0[2]) / rtb_w_d_0[8];
  rtb_Row2 = -(rtb_w_d_0[7] * rtb_Row3_l + rtb_w_d_0[1]) / rtb_w_d_0[4];
  rtb_K_i[p1] = ((1.0 - rtb_w_d_0[3] * rtb_Row2) - rtb_w_d_0[6] * rtb_Row3_l) /
    rtb_w_d_0[0];
  rtb_K_i[p1 + 1] = rtb_Row2;
  rtb_K_i[p1 + 2] = rtb_Row3_l;
  rtb_Row3_l = -(rtb_Row1 / rtb_Row3) / rtb_w_d_0[8];
  rtb_Row2 = (1.0 - rtb_w_d_0[7] * rtb_Row3_l) / rtb_w_d_0[4];
  rtb_K_i[i] = -(rtb_w_d_0[3] * rtb_Row2 + rtb_w_d_0[6] * rtb_Row3_l) /
    rtb_w_d_0[0];
  rtb_K_i[i + 1] = rtb_Row2;
  rtb_K_i[i + 2] = rtb_Row3_l;
  rtb_Row3_l = 1.0 / rtb_w_d_0[8];
  rtb_Row2 = -rtb_w_d_0[7] * rtb_Row3_l / rtb_w_d_0[4];
  rtb_K_i[p3] = -(rtb_w_d_0[3] * rtb_Row2 + rtb_w_d_0[6] * rtb_Row3_l) /
    rtb_w_d_0[0];
  rtb_K_i[p3 + 1] = rtb_Row2;
  rtb_K_i[p3 + 2] = rtb_Row3_l;

  /* End of MATLAB Function: '<S12>/w_d^-2' */

  /* Product: '<S12>/Matrix Multiply1' incorporates:
   *  Sum: '<S12>/Sum'
   */
  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtMatrix[i] = rtb_K_i[i + 6] * rtb_Integrator2[2] +
      (rtb_K_i[i + 3] * rtb_Integrator2[1] + rtb_K_i[i] * rtb_Integrator2[0]);
  }

  /* End of Product: '<S12>/Matrix Multiply1' */

  /* Sum: '<S12>/Sum' incorporates:
   *  Product: '<S12>/Matrix Multiply'
   */
  rtb_Row1 = ctrl_DP_B.x_ref - rtb_TmpSignalConversionAtMatrix[0];
  rtb_Row3 = ctrl_DP_B.y_ref - rtb_TmpSignalConversionAtMatrix[1];
  rtb_Row2 = ctrl_DP_B.psi_ref - rtb_TmpSignalConversionAtMatrix[2];

  /* Product: '<S12>/Matrix Multiply' */
  for (i = 0; i < 3; i++) {
    ctrl_DP_B.MatrixMultiply[i] = 0.0;
    ctrl_DP_B.MatrixMultiply[i] += rtb_K_d[i] * rtb_Row1;
    ctrl_DP_B.MatrixMultiply[i] += rtb_K_d[i + 3] * rtb_Row3;
    ctrl_DP_B.MatrixMultiply[i] += rtb_K_d[i + 6] * rtb_Row2;
  }
}

/* Model update function */
void ctrl_DP_update(void)
{
  /* Update for Integrator: '<S12>/Integrator1' */
  ctrl_DP_DW.Integrator1_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_DP_M->solverInfo);
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
  if (!(++ctrl_DP_M->Timing.clockTick0)) {
    ++ctrl_DP_M->Timing.clockTickH0;
  }

  ctrl_DP_M->Timing.t[0] = rtsiGetSolverStopTime(&ctrl_DP_M->solverInfo);

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
    if (!(++ctrl_DP_M->Timing.clockTick1)) {
      ++ctrl_DP_M->Timing.clockTickH1;
    }

    ctrl_DP_M->Timing.t[1] = ctrl_DP_M->Timing.clockTick1 *
      ctrl_DP_M->Timing.stepSize1 + ctrl_DP_M->Timing.clockTickH1 *
      ctrl_DP_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_DP_derivatives(void)
{
  /* Derivatives for Integrator: '<S12>/Integrator1' */
  {
    ((XDot_ctrl_DP_T *) ctrl_DP_M->ModelData.derivs)->Integrator1_CSTATE[0] =
      ctrl_DP_B.Integrator3[0];
    ((XDot_ctrl_DP_T *) ctrl_DP_M->ModelData.derivs)->Integrator1_CSTATE[1] =
      ctrl_DP_B.Integrator3[1];
    ((XDot_ctrl_DP_T *) ctrl_DP_M->ModelData.derivs)->Integrator1_CSTATE[2] =
      ctrl_DP_B.Integrator3[2];
  }

  /* Derivatives for Integrator: '<S6>/Integrator' */
  {
    ((XDot_ctrl_DP_T *) ctrl_DP_M->ModelData.derivs)->Integrator_CSTATE[0] =
      ctrl_DP_B.TmpSignalConversionAtMatrixMult[0];
    ((XDot_ctrl_DP_T *) ctrl_DP_M->ModelData.derivs)->Integrator_CSTATE[1] =
      ctrl_DP_B.TmpSignalConversionAtMatrixMult[1];
    ((XDot_ctrl_DP_T *) ctrl_DP_M->ModelData.derivs)->Integrator_CSTATE[2] =
      ctrl_DP_B.TmpSignalConversionAtMatrixMult[2];
  }

  /* Derivatives for Integrator: '<S12>/Integrator3' */
  {
    ((XDot_ctrl_DP_T *) ctrl_DP_M->ModelData.derivs)->Integrator3_CSTATE[0] =
      ctrl_DP_B.Sum5[0];
    ((XDot_ctrl_DP_T *) ctrl_DP_M->ModelData.derivs)->Integrator3_CSTATE[1] =
      ctrl_DP_B.Sum5[1];
    ((XDot_ctrl_DP_T *) ctrl_DP_M->ModelData.derivs)->Integrator3_CSTATE[2] =
      ctrl_DP_B.Sum5[2];
  }

  /* Derivatives for Integrator: '<S12>/Integrator2' */
  {
    ((XDot_ctrl_DP_T *) ctrl_DP_M->ModelData.derivs)->Integrator2_CSTATE[0] =
      ctrl_DP_B.MatrixMultiply[0];
    ((XDot_ctrl_DP_T *) ctrl_DP_M->ModelData.derivs)->Integrator2_CSTATE[1] =
      ctrl_DP_B.MatrixMultiply[1];
    ((XDot_ctrl_DP_T *) ctrl_DP_M->ModelData.derivs)->Integrator2_CSTATE[2] =
      ctrl_DP_B.MatrixMultiply[2];
  }
}

/* Model initialize function */
void ctrl_DP_initialize(void)
{
  ctrl_DP_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator3_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S12>/Integrator1' */
  if (rtmIsFirstInitCond(ctrl_DP_M)) {
    ctrl_DP_X.Integrator1_CSTATE[0] = 0.0;
    ctrl_DP_X.Integrator1_CSTATE[1] = 0.0;
    ctrl_DP_X.Integrator1_CSTATE[2] = 0.0;
  }

  ctrl_DP_DW.Integrator1_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  ctrl_DP_X.Integrator_CSTATE[0] = ctrl_DP_P.Integrator_IC;
  ctrl_DP_X.Integrator_CSTATE[1] = ctrl_DP_P.Integrator_IC;
  ctrl_DP_X.Integrator_CSTATE[2] = ctrl_DP_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S12>/Integrator3' */
  ctrl_DP_X.Integrator3_CSTATE[0] = ctrl_DP_P.Integrator3_IC;
  ctrl_DP_X.Integrator3_CSTATE[1] = ctrl_DP_P.Integrator3_IC;
  ctrl_DP_X.Integrator3_CSTATE[2] = ctrl_DP_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S12>/Integrator2' */
  ctrl_DP_X.Integrator2_CSTATE[0] = ctrl_DP_P.Integrator2_IC;
  ctrl_DP_X.Integrator2_CSTATE[1] = ctrl_DP_P.Integrator2_IC;
  ctrl_DP_X.Integrator2_CSTATE[2] = ctrl_DP_P.Integrator2_IC;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ctrl_DP_M)) {
    rtmSetFirstInitCond(ctrl_DP_M, 0);
  }
}

/* Model terminate function */
void ctrl_DP_terminate(void)
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
  ctrl_DP_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_DP_update();
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
  ctrl_DP_initialize();
}

void MdlTerminate(void)
{
  ctrl_DP_terminate();
}

/* Registration function */
RT_MODEL_ctrl_DP_T *ctrl_DP(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_DP_M, 0,
                sizeof(RT_MODEL_ctrl_DP_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_DP_M->solverInfo, &ctrl_DP_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_DP_M->solverInfo, &rtmGetTPtr(ctrl_DP_M));
    rtsiSetStepSizePtr(&ctrl_DP_M->solverInfo, &ctrl_DP_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_DP_M->solverInfo, &ctrl_DP_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_DP_M->solverInfo, (real_T **)
                         &ctrl_DP_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_DP_M->solverInfo, (&rtmGetErrorStatus(ctrl_DP_M)));
    rtsiSetRTModelPtr(&ctrl_DP_M->solverInfo, ctrl_DP_M);
  }

  rtsiSetSimTimeStep(&ctrl_DP_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_DP_M->ModelData.intgData.y = ctrl_DP_M->ModelData.odeY;
  ctrl_DP_M->ModelData.intgData.f[0] = ctrl_DP_M->ModelData.odeF[0];
  ctrl_DP_M->ModelData.intgData.f[1] = ctrl_DP_M->ModelData.odeF[1];
  ctrl_DP_M->ModelData.intgData.f[2] = ctrl_DP_M->ModelData.odeF[2];
  ctrl_DP_M->ModelData.intgData.f[3] = ctrl_DP_M->ModelData.odeF[3];
  ctrl_DP_M->ModelData.contStates = ((real_T *) &ctrl_DP_X);
  rtsiSetSolverData(&ctrl_DP_M->solverInfo, (void *)
                    &ctrl_DP_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_DP_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_DP_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_DP_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_DP_M->Timing.sampleTimes = (&ctrl_DP_M->Timing.sampleTimesArray[0]);
    ctrl_DP_M->Timing.offsetTimes = (&ctrl_DP_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_DP_M->Timing.sampleTimes[0] = (0.0);
    ctrl_DP_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_DP_M->Timing.offsetTimes[0] = (0.0);
    ctrl_DP_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_DP_M, &ctrl_DP_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_DP_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_DP_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_DP_M, -1);
  ctrl_DP_M->Timing.stepSize0 = 0.01;
  ctrl_DP_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_DP_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_DP_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_DP_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_DP_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_DP_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_DP_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_DP_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_DP_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_DP_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_DP_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_DP_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_DP_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_DP_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_DP_M->rtwLogInfo, (NULL));
  }

  ctrl_DP_M->solverInfoPtr = (&ctrl_DP_M->solverInfo);
  ctrl_DP_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_DP_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_DP_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_DP_M->ModelData.blockIO = ((void *) &ctrl_DP_B);
  (void) memset(((void *) &ctrl_DP_B), 0,
                sizeof(B_ctrl_DP_T));

  /* parameters */
  ctrl_DP_M->ModelData.defaultParam = ((real_T *)&ctrl_DP_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_DP_X;
    ctrl_DP_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_DP_X, 0,
                  sizeof(X_ctrl_DP_T));
  }

  /* states (dwork) */
  ctrl_DP_M->ModelData.dwork = ((void *) &ctrl_DP_DW);
  (void) memset((void *)&ctrl_DP_DW, 0,
                sizeof(DW_ctrl_DP_T));

  /* Initialize Sizes */
  ctrl_DP_M->Sizes.numContStates = (12);/* Number of continuous states */
  ctrl_DP_M->Sizes.numY = (0);         /* Number of model outputs */
  ctrl_DP_M->Sizes.numU = (0);         /* Number of model inputs */
  ctrl_DP_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_DP_M->Sizes.numSampTimes = (2); /* Number of sample times */
  ctrl_DP_M->Sizes.numBlocks = (121);  /* Number of blocks */
  ctrl_DP_M->Sizes.numBlockIO = (45);  /* Number of block outputs */
  ctrl_DP_M->Sizes.numBlockPrms = (281);/* Sum of parameter "widths" */
  return ctrl_DP_M;
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
#ifdef NI_ROOTMODEL_ctrl_DP
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 34:
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
    //Type is array. Call SetValueByDataType on its contained type
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_DP_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // Input/Control Gains/K_p_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_p_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_p_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_p_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_p_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_p_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_i_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_i_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_i_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_i_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_i_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_i_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_ff_r_dot
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_ff_r_dot, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_ff_u_dot
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_ff_u_dot, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_ff_v_dot
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_ff_v_dot, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_ff_r
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_ff_r, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_ff_u
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_ff_u, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_ff_v
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_ff_v, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Guidance gains/w_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.w_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Guidance gains/w_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.w_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Guidance gains/w_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.w_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Guidance gains/zeta_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.zeta_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Guidance gains/zeta_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.zeta_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Guidance gains/zeta_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.zeta_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/VSP_on
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.VSP_on, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/psi_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.psi_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/x_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.x_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/y_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.y_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/r_hat
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.r_hat, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/u_hat
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.u_hat, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/v_hat
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.v_hat, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 32;
}

double ni_extout[13];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // DP_alpha2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_VSP,0,0,0);
  } else {
    index += 1;
  }

  // DP_u_BT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u_BT,0,0,0);
  } else {
    index += 1;
  }

  // DP_u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u_VSP,0,0,0);
  } else {
    index += 1;
  }

  // DP_omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.omega_VSP,0,0,0);
  } else {
    index += 1;
  }

  // DP_u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u_VSP,0,0,0);
  } else {
    index += 1;
  }

  // DP_alpha1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_VSP,0,0,0);
  } else {
    index += 1;
  }

  // DP_omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.omega_VSP,0,0,0);
  } else {
    index += 1;
  }

  // Output/Control output/tau_N: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum1,2,17,0);
  } else {
    index += 1;
  }

  // Output/Control output/tau_X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum1,0,17,0);
  } else {
    index += 1;
  }

  // Output/Control output/tau_Y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum1,1,17,0);
  } else {
    index += 1;
  }

  // Output/Guidance output/x_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1,0,17,0);
  } else {
    index += 1;
  }

  // Output/Guidance output/y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1,1,17,0);
  } else {
    index += 1;
  }

  // Output/Guidance output/psi_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1,2,17,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 13;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // DP_alpha2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_VSP,0,0,0);

  // DP_u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u_BT,0,0,0);

  // DP_u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u_VSP,0,0,0);

  // DP_omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.omega_VSP,0,0,0);

  // DP_u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u_VSP,0,0,0);

  // DP_alpha1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_VSP,0,0,0);

  // DP_omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.omega_VSP,0,0,0);

  // Output/Control output/tau_N: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum1,2,17,0);

  // Output/Control output/tau_X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum1,0,17,0);

  // Output/Control output/tau_Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum1,1,17,0);

  // Output/Guidance output/x_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1,0,17,0);

  // Output/Guidance output/y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1,1,17,0);

  // Output/Guidance output/psi_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1,2,17,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0,
    "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat), 33, 1, 2, 0, 0 },

  { 1,
    "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat), 33, 1, 2, 2, 0 },

  { 2, "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain), 33, 1, 2, 4, 0 },

  { 3, "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value), 33, 1, 2, 6, 0 },

  { 4,
    "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_g), 33, 1, 2, 8, 0 },

  { 5,
    "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_b), 33, 1, 2, 10, 0 },

  { 6, "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_e), 33, 1, 2, 12, 0 },

  { 7, "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value_n), 33, 1, 2, 14, 0 },

  { 8, "ctrl_dp/Control/DP Controller/Integrator/InitialCondition", offsetof
    (P_ctrl_DP_T, Integrator_IC), 33, 1, 2, 16, 0 },

  { 9, "ctrl_dp/Guidance/Reference model/Integrator3/InitialCondition", offsetof
    (P_ctrl_DP_T, Integrator3_IC), 33, 1, 2, 18, 0 },

  { 10, "ctrl_dp/Guidance/Reference model/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator2_IC), 33, 1, 2, 20, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 11;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_dp/Input/Control Gains/K_p_x", 0, "", offsetof(B_ctrl_DP_T, K_p_x)+
    0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_dp/Input/Control Gains/K_p_y", 0, "", offsetof(B_ctrl_DP_T, K_p_y)+
    0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "ctrl_dp/Input/Control Gains/K_p_psi", 0, "", offsetof(B_ctrl_DP_T,
    K_p_psi)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "ctrl_dp/Input/Control Gains/K_i_psi", 0, "", offsetof(B_ctrl_DP_T,
    K_i_psi)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "ctrl_dp/Input/Control Gains/K_i_x", 0, "", offsetof(B_ctrl_DP_T, K_i_x)+
    0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "ctrl_dp/Input/Control Gains/K_i_y", 0, "", offsetof(B_ctrl_DP_T, K_i_y)+
    0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "ctrl_dp/Input/Control Gains/K_d_psi", 0, "", offsetof(B_ctrl_DP_T,
    K_d_psi)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "ctrl_dp/Input/Control Gains/K_d_x", 0, "", offsetof(B_ctrl_DP_T, K_d_x)+
    0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8, "ctrl_dp/Input/Control Gains/K_d_y", 0, "", offsetof(B_ctrl_DP_T, K_d_y)+
    0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 16, 0 },

  { 9, "ctrl_dp/Input/Control Gains/K_ff_r_dot", 0, "", offsetof(B_ctrl_DP_T,
    K_ff_r_dot)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 18, 0 },

  { 10, "ctrl_dp/Input/Control Gains/K_ff_u_dot", 0, "", offsetof(B_ctrl_DP_T,
    K_ff_u_dot)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 20, 0 },

  { 11, "ctrl_dp/Input/Control Gains/K_ff_v_dot", 0, "", offsetof(B_ctrl_DP_T,
    K_ff_v_dot)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 22, 0 },

  { 12, "ctrl_dp/Input/Control Gains/K_ff_r", 0, "", offsetof(B_ctrl_DP_T,
    K_ff_r)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 24, 0 },

  { 13, "ctrl_dp/Input/Control Gains/K_ff_u", 0, "", offsetof(B_ctrl_DP_T,
    K_ff_u)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 26, 0 },

  { 14, "ctrl_dp/Input/Control Gains/K_ff_v", 0, "", offsetof(B_ctrl_DP_T,
    K_ff_v)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 28, 0 },

  { 15, "ctrl_dp/Input/reset", 0, "", offsetof(B_ctrl_DP_T, reset)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 30, 0 },

  { 16, "ctrl_dp/Input/Guidance gains/w_d_x", 0, "", offsetof(B_ctrl_DP_T, w_d_x)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 32, 0 },

  { 17, "ctrl_dp/Input/Guidance gains/w_d_y", 0, "", offsetof(B_ctrl_DP_T, w_d_y)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 34, 0 },

  { 18, "ctrl_dp/Input/Guidance gains/w_d_psi", 0, "", offsetof(B_ctrl_DP_T,
    w_d_psi)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 36, 0 },

  { 19, "ctrl_dp/Input/Guidance gains/zeta_psi", 0, "", offsetof(B_ctrl_DP_T,
    zeta_psi)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 38, 0 },

  { 20, "ctrl_dp/Input/Guidance gains/zeta_x", 0, "", offsetof(B_ctrl_DP_T,
    zeta_x)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 40, 0 },

  { 21, "ctrl_dp/Input/Guidance gains/zeta_y", 0, "", offsetof(B_ctrl_DP_T,
    zeta_y)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 42, 0 },

  { 22, "ctrl_dp/Input/VSP_on", 0, "", offsetof(B_ctrl_DP_T, VSP_on)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 44, 0 },

  { 23, "ctrl_dp/Input/psi_ref", 0, "", offsetof(B_ctrl_DP_T, psi_ref)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 46, 0 },

  { 24, "ctrl_dp/Input/x_ref", 0, "", offsetof(B_ctrl_DP_T, x_ref)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 48, 0 },

  { 25, "ctrl_dp/Input/y_ref", 0, "", offsetof(B_ctrl_DP_T, y_ref)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 50, 0 },

  { 26, "ctrl_dp/Input/x", 0, "", offsetof(B_ctrl_DP_T, x)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 52, 0 },

  { 27, "ctrl_dp/Input/y", 0, "", offsetof(B_ctrl_DP_T, y)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 54, 0 },

  { 28, "ctrl_dp/Input/psi", 0, "", offsetof(B_ctrl_DP_T, psi)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 56, 0 },

  { 29, "ctrl_dp/Input/r_hat", 0, "", offsetof(B_ctrl_DP_T, r_hat)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 58, 0 },

  { 30, "ctrl_dp/Input/u_hat", 0, "", offsetof(B_ctrl_DP_T, u_hat)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 60, 0 },

  { 31, "ctrl_dp/Input/v_hat", 0, "", offsetof(B_ctrl_DP_T, v_hat)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 62, 0 },

  { 32, "ctrl_dp/Guidance/Reference model/Integrator1", 0, "(1,1)", offsetof
    (B_ctrl_DP_T, Integrator1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 64, 0 },

  { 33, "ctrl_dp/Guidance/Reference model/Integrator1", 0, "(1,2)", offsetof
    (B_ctrl_DP_T, Integrator1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 66, 0 },

  { 34, "ctrl_dp/Guidance/Reference model/Integrator1", 0, "(1,3)", offsetof
    (B_ctrl_DP_T, Integrator1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 68, 0 },

  { 35, "ctrl_dp/Guidance/Reference model/Integrator3", 0, "(1,1)", offsetof
    (B_ctrl_DP_T, Integrator3)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 70, 0 },

  { 36, "ctrl_dp/Guidance/Reference model/Integrator3", 0, "(1,2)", offsetof
    (B_ctrl_DP_T, Integrator3)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 72, 0 },

  { 37, "ctrl_dp/Guidance/Reference model/Integrator3", 0, "(1,3)", offsetof
    (B_ctrl_DP_T, Integrator3)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 74, 0 },

  { 38, "ctrl_dp/Guidance/Reference model/Sum5", 0, "(1,1)", offsetof
    (B_ctrl_DP_T, Sum5)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 76, 0 },

  { 39, "ctrl_dp/Guidance/Reference model/Sum5", 0, "(1,2)", offsetof
    (B_ctrl_DP_T, Sum5)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 78, 0 },

  { 40, "ctrl_dp/Guidance/Reference model/Sum5", 0, "(1,3)", offsetof
    (B_ctrl_DP_T, Sum5)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 80, 0 },

  { 41, "ctrl_dp/Control/DP Controller/Sum1", 0, "(1,1)", offsetof(B_ctrl_DP_T,
    Sum1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 82, 0 },

  { 42, "ctrl_dp/Control/DP Controller/Sum1", 0, "(1,2)", offsetof(B_ctrl_DP_T,
    Sum1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 84, 0 },

  { 43, "ctrl_dp/Control/DP Controller/Sum1", 0, "(1,3)", offsetof(B_ctrl_DP_T,
    Sum1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 86, 0 },

  { 44, "ctrl_dp/Guidance/Reference model/Matrix Multiply", 0, "(1,1)", offsetof
    (B_ctrl_DP_T, MatrixMultiply)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 88, 0
  },

  { 45, "ctrl_dp/Guidance/Reference model/Matrix Multiply", 0, "(1,2)", offsetof
    (B_ctrl_DP_T, MatrixMultiply)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 90, 0
  },

  { 46, "ctrl_dp/Guidance/Reference model/Matrix Multiply", 0, "(1,3)", offsetof
    (B_ctrl_DP_T, MatrixMultiply)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 92, 0
  },

  { 47, "ctrl_dp/Thrust allocation/linear thrust allocation/Thrust allocation",
    0, "u_BT", offsetof(B_ctrl_DP_T, u_BT)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 94, 0 },

  { 48, "ctrl_dp/Thrust allocation/linear thrust allocation/Thrust allocation",
    1, "u_VSP", offsetof(B_ctrl_DP_T, u_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 96, 0 },

  { 49, "ctrl_dp/Thrust allocation/linear thrust allocation/Thrust allocation",
    2, "alpha_VSP", offsetof(B_ctrl_DP_T, alpha_VSP)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 98, 0 },

  { 50, "ctrl_dp/Thrust allocation/linear thrust allocation/Thrust allocation",
    3, "omega_VSP", offsetof(B_ctrl_DP_T, omega_VSP)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 100, 0 },

  { 51, "ctrl_dp/Input/Control Gains/MATLAB Function4", 0, "K_p(1,1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction4.K_p)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 102, 0 },

  { 52, "ctrl_dp/Input/Control Gains/MATLAB Function4", 0, "K_p(2,1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction4.K_p)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 104, 0 },

  { 53, "ctrl_dp/Input/Control Gains/MATLAB Function4", 0, "K_p(3,1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction4.K_p)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 106, 0 },

  { 54, "ctrl_dp/Input/Control Gains/MATLAB Function4", 0, "K_p(1,2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction4.K_p)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 108, 0 },

  { 55, "ctrl_dp/Input/Control Gains/MATLAB Function4", 0, "K_p(2,2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction4.K_p)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 110, 0 },

  { 56, "ctrl_dp/Input/Control Gains/MATLAB Function4", 0, "K_p(3,2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction4.K_p)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 112, 0 },

  { 57, "ctrl_dp/Input/Control Gains/MATLAB Function4", 0, "K_p(1,3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction4.K_p)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 114, 0 },

  { 58, "ctrl_dp/Input/Control Gains/MATLAB Function4", 0, "K_p(2,3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction4.K_p)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 116, 0 },

  { 59, "ctrl_dp/Input/Control Gains/MATLAB Function4", 0, "K_p(3,3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction4.K_p)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 118, 0 },

  { 60, "ctrl_dp/Input/Control Gains/MATLAB Function3", 0, "K_p(1,1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction3.K_p)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 120, 0 },

  { 61, "ctrl_dp/Input/Control Gains/MATLAB Function3", 0, "K_p(2,1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction3.K_p)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 122, 0 },

  { 62, "ctrl_dp/Input/Control Gains/MATLAB Function3", 0, "K_p(3,1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction3.K_p)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 124, 0 },

  { 63, "ctrl_dp/Input/Control Gains/MATLAB Function3", 0, "K_p(1,2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction3.K_p)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 126, 0 },

  { 64, "ctrl_dp/Input/Control Gains/MATLAB Function3", 0, "K_p(2,2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction3.K_p)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 128, 0 },

  { 65, "ctrl_dp/Input/Control Gains/MATLAB Function3", 0, "K_p(3,2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction3.K_p)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 130, 0 },

  { 66, "ctrl_dp/Input/Control Gains/MATLAB Function3", 0, "K_p(1,3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction3.K_p)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 132, 0 },

  { 67, "ctrl_dp/Input/Control Gains/MATLAB Function3", 0, "K_p(2,3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction3.K_p)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 134, 0 },

  { 68, "ctrl_dp/Input/Control Gains/MATLAB Function3", 0, "K_p(3,3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction3.K_p)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 136, 0 },

  { 69, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "K_p(1,1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    138, 0 },

  { 70, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "K_p(2,1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    140, 0 },

  { 71, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "K_p(3,1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    142, 0 },

  { 72, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "K_p(1,2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    144, 0 },

  { 73, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "K_p(2,2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    146, 0 },

  { 74, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "K_p(3,2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    148, 0 },

  { 75, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "K_p(1,3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    150, 0 },

  { 76, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "K_p(2,3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    152, 0 },

  { 77, "ctrl_dp/Input/Control Gains/MATLAB Function", 0, "K_p(3,3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.K_p)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    154, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 78;
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
};

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 45;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "Input/Control Gains/K_p_x", 0, EXT_IN, 1, 1, 1 },

  { 1, "Input/Control Gains/K_p_y", 0, EXT_IN, 1, 1, 1 },

  { 2, "Input/Control Gains/K_p_psi", 0, EXT_IN, 1, 1, 1 },

  { 3, "Input/Control Gains/K_i_psi", 0, EXT_IN, 1, 1, 1 },

  { 4, "Input/Control Gains/K_i_x", 0, EXT_IN, 1, 1, 1 },

  { 5, "Input/Control Gains/K_i_y", 0, EXT_IN, 1, 1, 1 },

  { 6, "Input/Control Gains/K_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 7, "Input/Control Gains/K_d_x", 0, EXT_IN, 1, 1, 1 },

  { 8, "Input/Control Gains/K_d_y", 0, EXT_IN, 1, 1, 1 },

  { 9, "Input/Control Gains/K_ff_r_dot", 0, EXT_IN, 1, 1, 1 },

  { 10, "Input/Control Gains/K_ff_u_dot", 0, EXT_IN, 1, 1, 1 },

  { 11, "Input/Control Gains/K_ff_v_dot", 0, EXT_IN, 1, 1, 1 },

  { 12, "Input/Control Gains/K_ff_r", 0, EXT_IN, 1, 1, 1 },

  { 13, "Input/Control Gains/K_ff_u", 0, EXT_IN, 1, 1, 1 },

  { 14, "Input/Control Gains/K_ff_v", 0, EXT_IN, 1, 1, 1 },

  { 15, "Input/reset", 0, EXT_IN, 1, 1, 1 },

  { 16, "Input/Guidance gains/w_d_x", 0, EXT_IN, 1, 1, 1 },

  { 17, "Input/Guidance gains/w_d_y", 0, EXT_IN, 1, 1, 1 },

  { 18, "Input/Guidance gains/w_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 19, "Input/Guidance gains/zeta_psi", 0, EXT_IN, 1, 1, 1 },

  { 20, "Input/Guidance gains/zeta_x", 0, EXT_IN, 1, 1, 1 },

  { 21, "Input/Guidance gains/zeta_y", 0, EXT_IN, 1, 1, 1 },

  { 22, "Input/VSP_on", 0, EXT_IN, 1, 1, 1 },

  { 23, "Input/psi_ref", 0, EXT_IN, 1, 1, 1 },

  { 24, "Input/x_ref", 0, EXT_IN, 1, 1, 1 },

  { 25, "Input/y_ref", 0, EXT_IN, 1, 1, 1 },

  { 26, "Input/x", 0, EXT_IN, 1, 1, 1 },

  { 27, "Input/y", 0, EXT_IN, 1, 1, 1 },

  { 28, "Input/psi", 0, EXT_IN, 1, 1, 1 },

  { 29, "Input/r_hat", 0, EXT_IN, 1, 1, 1 },

  { 30, "Input/u_hat", 0, EXT_IN, 1, 1, 1 },

  { 31, "Input/v_hat", 0, EXT_IN, 1, 1, 1 },

  { 0, "DP_alpha2", 0, EXT_OUT, 1, 1, 1 },

  { 1, "DP_u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 2, "DP_u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 3, "DP_omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 4, "DP_u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 5, "DP_alpha1", 0, EXT_OUT, 1, 1, 1 },

  { 6, "DP_omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 7, "Output/Control output/tau_N", 0, EXT_OUT, 1, 1, 1 },

  { 8, "Output/Control output/tau_X", 0, EXT_OUT, 1, 1, 1 },

  { 9, "Output/Control output/tau_Y", 0, EXT_OUT, 1, 1, 1 },

  { 10, "Output/Guidance output/x_d", 0, EXT_OUT, 1, 1, 1 },

  { 11, "Output/Guidance output/y_d", 0, EXT_OUT, 1, 1, 1 },

  { 12, "Output/Guidance output/psi_d", 0, EXT_OUT, 1, 1, 1 },

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
  "ctrl_dp";
static char* NI_CompiledModelVersion = "1.11";
static char* NI_CompiledModelDateTime = "Sun Mar 15 22:06:20 2015";
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
   The undef allows us to access the real ctrl_DP_P
   In the rest of the code ctrl_DP_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_DP_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_DP_P, sizeof(P_ctrl_DP_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_DP_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_DP_T));
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
             (P_ctrl_DP_T));
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
               (P_ctrl_DP_T));

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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_ctrl_DP_T));
    WriteSideDirtyFlag = 0;
    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_ctrl_DP_T));
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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_ctrl_DP_T));
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
      *numContStates = 12;
      *numDiscStates = 406;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_X.Integrator1_CSTATE[0],
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_X.Integrator1_CSTATE[0],
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_X.Integrator1_CSTATE[0],
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_X.Integrator_CSTATE[0], 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_X.Integrator_CSTATE[0], 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_X.Integrator_CSTATE[0], 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_X.Integrator3_CSTATE[0],
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_X.Integrator3_CSTATE[0],
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_X.Integrator3_CSTATE[0],
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_X.Integrator2_CSTATE[0],
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_X.Integrator2_CSTATE[0],
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_X.Integrator2_CSTATE[0],
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_ff_r_dot_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_ff_r_dot_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_ff_u_dot_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_ff_u_dot_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_ff_v_dot_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_ff_v_dot_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_ff_r_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_ff_r_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_ff_u_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_ff_u_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_ff_v_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_ff_v_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.VSP_on_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.VSP_on_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_ref_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_ref_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_ref_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_alpha2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_alpha2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_u_BT_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_u_VSP2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_omega_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_u_VSP1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_alpha1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_alpha1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_omega_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_N_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_N_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_X_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_Y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_Y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.Integrator1_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.Integrator1_IWORK.IcNeedsLoading");
    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_ff_r_dot_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_ff_r_dot_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_ff_u_dot_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_ff_u_dot_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_ff_v_dot_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_ff_v_dot_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_ff_r_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_ff_r_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_ff_u_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_ff_u_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_ff_v_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_ff_v_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.VSP_on_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.VSP_on_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_ref_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_ref_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_ref_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_ref_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_ref_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_ref_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_DWORK2, count, 20,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_DWORK2, count, 20,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_hat_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_hat_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_hat_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_alpha2_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_alpha2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_u_BT_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_u_BT_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_u_VSP2_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_u_VSP2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_omega_VSP2_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_omega_VSP2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_u_VSP1_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_u_VSP1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_alpha1_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_alpha1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.DP_omega_VSP1_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.DP_omega_VSP1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_N_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_N_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_X_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_X_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_Y_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_Y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_d_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_d_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_d_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_d_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_d_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_d_DWORK2");
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
    NIRT_SetValueByDataType(&ctrl_DP_X.Integrator1_CSTATE[0], 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_X.Integrator1_CSTATE[0], 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_X.Integrator1_CSTATE[0], 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_X.Integrator_CSTATE[0], 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_X.Integrator_CSTATE[0], 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_X.Integrator_CSTATE[0], 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_X.Integrator3_CSTATE[0], 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_X.Integrator3_CSTATE[0], 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_X.Integrator3_CSTATE[0], 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_X.Integrator2_CSTATE[0], 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_X.Integrator2_CSTATE[0], 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_X.Integrator2_CSTATE[0], 2, contStates[idx
      ++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_ff_r_dot_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_ff_u_dot_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_ff_v_dot_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_ff_r_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_ff_u_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_ff_v_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.VSP_on_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_ref_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_ref_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_ref_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.r_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.v_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DP_alpha2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DP_u_BT_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DP_u_VSP2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DP_omega_VSP2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DP_u_VSP1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DP_alpha1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DP_omega_VSP1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.tau_N_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.tau_X_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.tau_Y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_d_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_d_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_d_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Integrator1_IWORK.IcNeedsLoading, 0,
      discStates[idx++], 10, 0);
    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_ff_r_dot_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_ff_u_dot_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_ff_v_dot_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_ff_r_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_ff_u_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_ff_v_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.VSP_on_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_ref_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_ref_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_ref_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_DWORK2, count, discStates[idx++], 20,
        0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_DWORK2, count, discStates[idx++], 20,
        0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.r_hat_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_hat_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.v_hat_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.DP_alpha2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.DP_u_BT_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.DP_u_VSP2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.DP_omega_VSP2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.DP_u_VSP1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.DP_alpha1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.DP_omega_VSP1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.tau_N_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.tau_X_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.tau_Y_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_d_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_d_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_d_DWORK2, count, discStates[idx++],
        20, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_DP
