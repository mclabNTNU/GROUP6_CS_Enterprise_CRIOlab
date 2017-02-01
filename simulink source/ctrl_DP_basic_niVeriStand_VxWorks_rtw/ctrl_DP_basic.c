/*
 * ctrl_DP_basic.c
 *
 * Code generation for model "ctrl_DP_basic".
 *
 * Model version              : 1.39
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Mar 17 11:25:22 2015
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_DP_basic.h"
#include "ctrl_DP_basic_private.h"

/* Block signals (auto storage) */
B_ctrl_DP_basic_T ctrl_DP_basic_B;

/* Continuous states */
X_ctrl_DP_basic_T ctrl_DP_basic_X;

/* Block states (auto storage) */
DW_ctrl_DP_basic_T ctrl_DP_basic_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_DP_basic_T ctrl_DP_basic_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_DP_basic_T ctrl_DP_basic_M_;
RT_MODEL_ctrl_DP_basic_T *const ctrl_DP_basic_M = &ctrl_DP_basic_M_;

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
  int_T nXc = 21;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_DP_basic_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_DP_basic_output();
  ctrl_DP_basic_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_DP_basic_output();
  ctrl_DP_basic_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_DP_basic_output();
  ctrl_DP_basic_derivatives();

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
 *    '<S22>/MATLAB Function'
 *    '<S24>/MATLAB Function'
 */
void ctrl_DP_basic_MATLABFunction(real_T rtu_K_p1, real_T rtu_K_p1_e, real_T
  rtu_K_p1_f, B_MATLABFunction_ctrl_DP_basi_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function': '<S25>:1' */
  /* '<S25>:1:4' */
  memset(&localB->K_p[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_p[0] = rtu_K_p1;
  localB->K_p[4] = rtu_K_p1_e;
  localB->K_p[8] = rtu_K_p1_f;
}

/*
 * Output and update for atomic system:
 *    '<S22>/MATLAB Function1'
 *    '<S24>/MATLAB Function1'
 */
void ctrl_DP_basic_MATLABFunction1(real_T rtu_K_i1, real_T rtu_K_i1_m, real_T
  rtu_K_i1_n, B_MATLABFunction1_ctrl_DP_bas_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function1': '<S26>:1' */
  /* '<S26>:1:4' */
  memset(&localB->K_i[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S26>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_i[0] = rtu_K_i1;
  localB->K_i[4] = rtu_K_i1_m;
  localB->K_i[8] = rtu_K_i1_n;
}

/*
 * Output and update for atomic system:
 *    '<S22>/MATLAB Function2'
 *    '<S24>/MATLAB Function2'
 */
void ctrl_DP_basic_MATLABFunction2(real_T rtu_K_d1, real_T rtu_K_d1_p, real_T
  rtu_K_d1_i, B_MATLABFunction2_ctrl_DP_bas_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function2': '<S27>:1' */
  /* '<S27>:1:4' */
  memset(&localB->K_d[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S27>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_d[0] = rtu_K_d1;
  localB->K_d[4] = rtu_K_d1_p;
  localB->K_d[8] = rtu_K_d1_i;
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
void ctrl_DP_basic_output(void)
{
  /* local block i/o variables */
  real_T rtb_MatrixMultiply[3];
  static const real_T a[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, -0.4575, 0.0, 1.0,
    0.3875 };

  real_T D_NL[9];
  real_T C_NL[9];
  boolean_T firstmult;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  real_T rtb_Row2;
  real_T rtb_Row1;
  real_T rtb_psi_dot;
  real_T rtb_Row1_o;
  real_T rtb_Sum[3];
  real_T rtb_TmpSignalConversionAtSFu_pa[3];
  real_T rtb_y[9];
  real_T rtb_y_l[9];
  real_T rtb_w_d[9];
  real_T tmp[3];
  real_T tmp_0[3];
  real_T rtb_MatrixMultiply5_idx_2;
  real_T rtb_MatrixMultiply5_idx_0;
  real_T rtb_MatrixMultiply5_idx_1;
  real_T u_idx_1;
  real_T u_idx_2;
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* set solver stop time */
    if (!(ctrl_DP_basic_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_DP_basic_M->solverInfo,
                            ((ctrl_DP_basic_M->Timing.clockTickH0 + 1) *
        ctrl_DP_basic_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_DP_basic_M->solverInfo,
                            ((ctrl_DP_basic_M->Timing.clockTick0 + 1) *
        ctrl_DP_basic_M->Timing.stepSize0 + ctrl_DP_basic_M->Timing.clockTickH0 *
        ctrl_DP_basic_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_DP_basic_M)) {
    ctrl_DP_basic_M->Timing.t[0] = rtsiGetT(&ctrl_DP_basic_M->solverInfo);
  }

  /* MATLAB Function: '<S22>/MATLAB Function' */
  ctrl_DP_basic_MATLABFunction(ctrl_DP_basic_B.K_p_x, ctrl_DP_basic_B.K_p_y,
    ctrl_DP_basic_B.K_p_psi, &ctrl_DP_basic_B.sf_MATLABFunction);

  /* Saturate: '<S14>/Saturation' incorporates:
   *  Fcn: '<S10>/yaw angle'
   */
  if (ctrl_DP_basic_B.psi > ctrl_DP_basic_P.Saturation_UpperSat) {
    rtb_Row2 = ctrl_DP_basic_P.Saturation_UpperSat;
  } else if (ctrl_DP_basic_B.psi < ctrl_DP_basic_P.Saturation_LowerSat) {
    rtb_Row2 = ctrl_DP_basic_P.Saturation_LowerSat;
  } else {
    rtb_Row2 = ctrl_DP_basic_B.psi;
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* Signum: '<S14>/Sign' */
  if (rtb_Row2 < 0.0) {
    u_idx_1 = -1.0;
  } else if (rtb_Row2 > 0.0) {
    u_idx_1 = 1.0;
  } else if (rtb_Row2 == 0.0) {
    u_idx_1 = 0.0;
  } else {
    u_idx_1 = rtb_Row2;
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  Signum: '<S14>/Sign'
   */
  rtb_Row1 = ctrl_DP_basic_P.Gain_Gain * u_idx_1;

  /* Sum: '<S14>/Sum1' */
  rtb_Row2 += rtb_Row1;

  /* Math: '<S14>/Math Function' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Row2 = rt_remd_snf(rtb_Row2, ctrl_DP_basic_P.Constant_Value);

  /* Sum: '<S14>/Sum' */
  rtb_Row2 -= rtb_Row1;

  /* MATLAB Function: '<S22>/MATLAB Function1' */
  ctrl_DP_basic_MATLABFunction1(ctrl_DP_basic_B.K_i_x, ctrl_DP_basic_B.K_i_y,
    ctrl_DP_basic_B.K_i_psi, &ctrl_DP_basic_B.sf_MATLABFunction1);

  /* MATLAB Function: '<S22>/MATLAB Function2' */
  ctrl_DP_basic_MATLABFunction2(ctrl_DP_basic_B.K_d_x, ctrl_DP_basic_B.K_d_y,
    ctrl_DP_basic_B.K_d_psi, &ctrl_DP_basic_B.sf_MATLABFunction2);
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* MATLAB Function: '<S24>/MATLAB Function2' incorporates:
     *  Constant: '<S24>/Constant6'
     *  Constant: '<S24>/Constant7'
     *  Constant: '<S24>/Constant8'
     */
    ctrl_DP_basic_MATLABFunction2(ctrl_DP_basic_P.Constant6_Value,
      ctrl_DP_basic_P.Constant7_Value, ctrl_DP_basic_P.Constant8_Value,
      &ctrl_DP_basic_B.sf_MATLABFunction2_p);
  }

  /* MATLAB Function: '<S23>/diag' incorporates:
   *  SignalConversion: '<S28>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Input/Guidance gains/diag': '<S28>:1' */
  /* '<S28>:1:4' */
  memset(&rtb_w_d[0], 0, 9U * sizeof(real_T));
  rtb_w_d[0] = ctrl_DP_basic_B.w_d_x;
  rtb_w_d[4] = ctrl_DP_basic_B.w_d_y;
  rtb_w_d[8] = ctrl_DP_basic_B.w_d_psi;

  /* Integrator: '<S15>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_DP_basic_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading) {
      ctrl_DP_basic_X.Integrator1_CSTATE[0] = ctrl_DP_basic_B.x;
      ctrl_DP_basic_X.Integrator1_CSTATE[1] = ctrl_DP_basic_B.y;
      ctrl_DP_basic_X.Integrator1_CSTATE[2] = ctrl_DP_basic_B.psi;
    }
  }

  ctrl_DP_basic_B.Integrator1[0] = ctrl_DP_basic_X.Integrator1_CSTATE[0];
  ctrl_DP_basic_B.Integrator1[1] = ctrl_DP_basic_X.Integrator1_CSTATE[1];
  ctrl_DP_basic_B.Integrator1[2] = ctrl_DP_basic_X.Integrator1_CSTATE[2];

  /* Saturate: '<S16>/Saturation' */
  if (ctrl_DP_basic_B.Integrator1[2] > ctrl_DP_basic_P.Saturation_UpperSat_j) {
    rtb_Row1 = ctrl_DP_basic_P.Saturation_UpperSat_j;
  } else if (ctrl_DP_basic_B.Integrator1[2] <
             ctrl_DP_basic_P.Saturation_LowerSat_c) {
    rtb_Row1 = ctrl_DP_basic_P.Saturation_LowerSat_c;
  } else {
    rtb_Row1 = ctrl_DP_basic_B.Integrator1[2];
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* Signum: '<S16>/Sign' */
  if (rtb_Row1 < 0.0) {
    u_idx_1 = -1.0;
  } else if (rtb_Row1 > 0.0) {
    u_idx_1 = 1.0;
  } else if (rtb_Row1 == 0.0) {
    u_idx_1 = 0.0;
  } else {
    u_idx_1 = rtb_Row1;
  }

  /* Gain: '<S16>/Gain' incorporates:
   *  Signum: '<S16>/Sign'
   */
  rtb_psi_dot = ctrl_DP_basic_P.Gain_Gain_j * u_idx_1;

  /* Sum: '<S16>/Sum1' */
  rtb_Row1 += rtb_psi_dot;

  /* Math: '<S16>/Math Function' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_Row1 = rt_remd_snf(rtb_Row1, ctrl_DP_basic_P.Constant_Value_f);

  /* Sum: '<S16>/Sum' */
  ctrl_DP_basic_B.Sum = rtb_Row1 - rtb_psi_dot;

  /* SignalConversion: '<S15>/TmpSignal ConversionAtMatrix Multiply2Inport2' */
  rtb_MatrixMultiply5_idx_0 = ctrl_DP_basic_B.Integrator1[0];
  rtb_MatrixMultiply5_idx_1 = ctrl_DP_basic_B.Integrator1[1];
  rtb_MatrixMultiply5_idx_2 = ctrl_DP_basic_B.Sum;

  /* Sum: '<S10>/Sum2' incorporates:
   *  SignalConversion: '<S15>/TmpSignal ConversionAtMatrix Multiply2Inport2'
   */
  ctrl_DP_basic_B.regulationerror[0] = ctrl_DP_basic_B.x -
    ctrl_DP_basic_B.Integrator1[0];
  ctrl_DP_basic_B.regulationerror[1] = ctrl_DP_basic_B.y -
    ctrl_DP_basic_B.Integrator1[1];
  ctrl_DP_basic_B.regulationerror[2] = ctrl_DP_basic_B.psi - ctrl_DP_basic_B.Sum;

  /* Saturate: '<S13>/Saturation' */
  if (ctrl_DP_basic_B.regulationerror[2] > ctrl_DP_basic_P.Saturation_UpperSat_a)
  {
    rtb_psi_dot = ctrl_DP_basic_P.Saturation_UpperSat_a;
  } else if (ctrl_DP_basic_B.regulationerror[2] <
             ctrl_DP_basic_P.Saturation_LowerSat_d) {
    rtb_psi_dot = ctrl_DP_basic_P.Saturation_LowerSat_d;
  } else {
    rtb_psi_dot = ctrl_DP_basic_B.regulationerror[2];
  }

  /* End of Saturate: '<S13>/Saturation' */

  /* Signum: '<S13>/Sign' */
  if (rtb_psi_dot < 0.0) {
    u_idx_1 = -1.0;
  } else if (rtb_psi_dot > 0.0) {
    u_idx_1 = 1.0;
  } else if (rtb_psi_dot == 0.0) {
    u_idx_1 = 0.0;
  } else {
    u_idx_1 = rtb_psi_dot;
  }

  /* Gain: '<S13>/Gain' incorporates:
   *  Signum: '<S13>/Sign'
   */
  rtb_Row1 = ctrl_DP_basic_P.Gain_Gain_g * u_idx_1;

  /* Sum: '<S13>/Sum1' */
  rtb_psi_dot += rtb_Row1;

  /* Math: '<S13>/Math Function' incorporates:
   *  Constant: '<S13>/Constant'
   */
  rtb_psi_dot = rt_remd_snf(rtb_psi_dot, ctrl_DP_basic_P.Constant_Value_p);

  /* Sum: '<S13>/Sum' */
  rtb_psi_dot -= rtb_Row1;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Fcn: '<S11>/Row1'
   *  Fcn: '<S11>/Row2'
   *  Fcn: '<S11>/Row3'
   */
  ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[0] = cos(rtb_Row2) *
    ctrl_DP_basic_B.regulationerror[0] + sin(rtb_Row2) *
    ctrl_DP_basic_B.regulationerror[1];
  ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[1] = -sin(rtb_Row2) *
    ctrl_DP_basic_B.regulationerror[0] + cos(rtb_Row2) *
    ctrl_DP_basic_B.regulationerror[1];
  ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[2] = rtb_psi_dot;

  /* Product: '<S10>/Matrix Multiply' */
  for (p2 = 0; p2 < 3; p2++) {
    rtb_TmpSignalConversionAtSFu_pa[p2] =
      ctrl_DP_basic_B.sf_MATLABFunction.K_p[p2 + 6] *
      ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[2] +
      (ctrl_DP_basic_B.sf_MATLABFunction.K_p[p2 + 3] *
       ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[1] +
       ctrl_DP_basic_B.sf_MATLABFunction.K_p[p2] *
       ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[0]);
  }

  /* End of Product: '<S10>/Matrix Multiply' */

  /* Integrator: '<S10>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_DP_basic_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_basic_X.Integrator_CSTATE[0] = ctrl_DP_basic_P.Integrator_IC;
      ctrl_DP_basic_X.Integrator_CSTATE[1] = ctrl_DP_basic_P.Integrator_IC;
      ctrl_DP_basic_X.Integrator_CSTATE[2] = ctrl_DP_basic_P.Integrator_IC;
    }
  }

  rtb_MatrixMultiply[0] = ctrl_DP_basic_X.Integrator_CSTATE[0];
  rtb_MatrixMultiply[1] = ctrl_DP_basic_X.Integrator_CSTATE[1];
  rtb_MatrixMultiply[2] = ctrl_DP_basic_X.Integrator_CSTATE[2];

  /* Product: '<S10>/Matrix Multiply1' */
  for (p2 = 0; p2 < 3; p2++) {
    rtb_Sum[p2] = ctrl_DP_basic_B.sf_MATLABFunction1.K_i[p2 + 6] *
      rtb_MatrixMultiply[2] + (ctrl_DP_basic_B.sf_MATLABFunction1.K_i[p2 + 3] *
      rtb_MatrixMultiply[1] + ctrl_DP_basic_B.sf_MATLABFunction1.K_i[p2] *
      rtb_MatrixMultiply[0]);
  }

  /* End of Product: '<S10>/Matrix Multiply1' */

  /* Integrator: '<S6>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator1_Reset_ZCE_e,
                       ctrl_DP_basic_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_basic_X.Integrator1_CSTATE_g[0] = (ctrl_DP_basic_P.Integrator1_IC
        [0]);
      ctrl_DP_basic_X.Integrator1_CSTATE_g[1] = (ctrl_DP_basic_P.Integrator1_IC
        [1]);
      ctrl_DP_basic_X.Integrator1_CSTATE_g[2] = (ctrl_DP_basic_P.Integrator1_IC
        [2]);
    }
  }

  ctrl_DP_basic_B.Integrator1_g[0] = ctrl_DP_basic_X.Integrator1_CSTATE_g[0];
  ctrl_DP_basic_B.Integrator1_g[1] = ctrl_DP_basic_X.Integrator1_CSTATE_g[1];
  ctrl_DP_basic_B.Integrator1_g[2] = ctrl_DP_basic_X.Integrator1_CSTATE_g[2];

  /* Integrator: '<S15>/Integrator3' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator3_Reset_ZCE,
                       ctrl_DP_basic_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_basic_X.Integrator3_CSTATE[0] = ctrl_DP_basic_P.Integrator3_IC;
      ctrl_DP_basic_X.Integrator3_CSTATE[1] = ctrl_DP_basic_P.Integrator3_IC;
      ctrl_DP_basic_X.Integrator3_CSTATE[2] = ctrl_DP_basic_P.Integrator3_IC;
    }
  }

  ctrl_DP_basic_B.Integrator3[0] = ctrl_DP_basic_X.Integrator3_CSTATE[0];
  ctrl_DP_basic_B.Integrator3[1] = ctrl_DP_basic_X.Integrator3_CSTATE[1];
  ctrl_DP_basic_B.Integrator3[2] = ctrl_DP_basic_X.Integrator3_CSTATE[2];

  /* Sum: '<S10>/Sum4' incorporates:
   *  Fcn: '<S10>/yaw angle1'
   *  Fcn: '<S12>/Row1'
   *  Fcn: '<S12>/Row2'
   *  Fcn: '<S12>/Row3'
   */
  ctrl_DP_basic_B.Sum4[0] = ctrl_DP_basic_B.Integrator1_g[0] - (cos
    (rtb_MatrixMultiply5_idx_2) * ctrl_DP_basic_B.Integrator3[0] + sin
    (rtb_MatrixMultiply5_idx_2) * ctrl_DP_basic_B.Integrator3[1]);
  ctrl_DP_basic_B.Sum4[1] = ctrl_DP_basic_B.Integrator1_g[1] - (-sin
    (rtb_MatrixMultiply5_idx_2) * ctrl_DP_basic_B.Integrator3[0] + cos
    (rtb_MatrixMultiply5_idx_2) * ctrl_DP_basic_B.Integrator3[1]);
  ctrl_DP_basic_B.Sum4[2] = ctrl_DP_basic_B.Integrator1_g[2] -
    ctrl_DP_basic_B.Integrator3[2];

  /* Product: '<S10>/Matrix Multiply2' */
  for (p2 = 0; p2 < 3; p2++) {
    rtb_MatrixMultiply[p2] = 0.0;
    rtb_MatrixMultiply[p2] += ctrl_DP_basic_B.sf_MATLABFunction2.K_d[p2] *
      ctrl_DP_basic_B.Sum4[0];
    rtb_MatrixMultiply[p2] += ctrl_DP_basic_B.sf_MATLABFunction2.K_d[p2 + 3] *
      ctrl_DP_basic_B.Sum4[1];
    rtb_MatrixMultiply[p2] += ctrl_DP_basic_B.sf_MATLABFunction2.K_d[p2 + 6] *
      ctrl_DP_basic_B.Sum4[2];
  }

  /* End of Product: '<S10>/Matrix Multiply2' */

  /* Sum: '<S10>/Sum3' */
  ctrl_DP_basic_B.Sum3[0] = ((0.0 - rtb_TmpSignalConversionAtSFu_pa[0]) -
    rtb_Sum[0]) - rtb_MatrixMultiply[0];
  ctrl_DP_basic_B.Sum3[1] = ((0.0 - rtb_TmpSignalConversionAtSFu_pa[1]) -
    rtb_Sum[1]) - rtb_MatrixMultiply[1];
  ctrl_DP_basic_B.Sum3[2] = ((0.0 - rtb_TmpSignalConversionAtSFu_pa[2]) -
    rtb_Sum[2]) - rtb_MatrixMultiply[2];

  /* MATLAB Function: '<Root>/Thrust allocation' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* MATLAB Function 'Thrust allocation': '<S8>:1' */
  /*  Forces and moments vector */
  /* '<S8>:1:4' */
  /*  Extended thrust configuration matrix */
  /*  Extended thrust coefficient matrix */
  /*  tau = T*K*u inverse */
  /* '<S8>:1:23' */
  u_idx_1 = ctrl_DP_basic_B.Sum3[1] - ctrl_DP_basic_B.Sum3[0] * 0.0;
  u_idx_2 = ((ctrl_DP_basic_B.Sum3[2] - ctrl_DP_basic_B.Sum3[0] * 0.0) - u_idx_1
             * -0.4575) / 2.221505;
  u_idx_1 -= u_idx_2 * 2.629;
  rtb_Row1 = u_idx_1 / 1.165;
  u_idx_1 /= 1.165;
  u_idx_1 = (ctrl_DP_basic_B.Sum3[0] - u_idx_2 * 0.0) - u_idx_1 * 0.0;

  /* '<S8>:1:25' */
  /* '<S8>:1:27' */
  rtb_Row2 = u_idx_1 / 1.165;

  /* '<S8>:1:28' */
  /* '<S8>:1:29' */
  /* '<S8>:1:30' */
  if (ctrl_DP_basic_P.Constant_Value_l != 0.0) {
    /* '<S8>:1:33' */
    ctrl_DP_basic_B.omega_VSP = 0.3;
  } else {
    /* '<S8>:1:35' */
    ctrl_DP_basic_B.omega_VSP = 0.0;
  }

  ctrl_DP_basic_B.u_BT = u_idx_2;
  ctrl_DP_basic_B.u_VSP = sqrt(rtb_Row2 * rtb_Row2 + rtb_Row1 * rtb_Row1);
  ctrl_DP_basic_B.alpha_VSP = rt_atan2d_snf(rtb_Row1, u_idx_1 / 1.165);

  /* End of MATLAB Function: '<Root>/Thrust allocation' */

  /* Integrator: '<S6>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator_Reset_ZCE_n,
                       ctrl_DP_basic_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading) {
      ctrl_DP_basic_X.Integrator_CSTATE_l[0] = ctrl_DP_basic_B.x;
      ctrl_DP_basic_X.Integrator_CSTATE_l[1] = ctrl_DP_basic_B.y;
      ctrl_DP_basic_X.Integrator_CSTATE_l[2] = ctrl_DP_basic_B.psi;
    }
  }

  ctrl_DP_basic_B.Integrator[0] = ctrl_DP_basic_X.Integrator_CSTATE_l[0];
  ctrl_DP_basic_B.Integrator[1] = ctrl_DP_basic_X.Integrator_CSTATE_l[1];
  ctrl_DP_basic_B.Integrator[2] = ctrl_DP_basic_X.Integrator_CSTATE_l[2];

  /* Saturate: '<S38>/Saturation' */
  if (ctrl_DP_basic_B.Integrator[2] > ctrl_DP_basic_P.Saturation_UpperSat_l) {
    rtb_Row1_o = ctrl_DP_basic_P.Saturation_UpperSat_l;
  } else if (ctrl_DP_basic_B.Integrator[2] <
             ctrl_DP_basic_P.Saturation_LowerSat_cz) {
    rtb_Row1_o = ctrl_DP_basic_P.Saturation_LowerSat_cz;
  } else {
    rtb_Row1_o = ctrl_DP_basic_B.Integrator[2];
  }

  /* End of Saturate: '<S38>/Saturation' */

  /* Signum: '<S38>/Sign' */
  if (rtb_Row1_o < 0.0) {
    u_idx_1 = -1.0;
  } else if (rtb_Row1_o > 0.0) {
    u_idx_1 = 1.0;
  } else if (rtb_Row1_o == 0.0) {
    u_idx_1 = 0.0;
  } else {
    u_idx_1 = rtb_Row1_o;
  }

  /* Gain: '<S38>/Gain' incorporates:
   *  Signum: '<S38>/Sign'
   */
  rtb_psi_dot = ctrl_DP_basic_P.Gain_Gain_d * u_idx_1;

  /* Sum: '<S38>/Sum1' */
  rtb_Row1_o += rtb_psi_dot;

  /* Math: '<S38>/Math Function' incorporates:
   *  Constant: '<S38>/Constant'
   */
  rtb_Row1_o = rt_remd_snf(rtb_Row1_o, ctrl_DP_basic_P.Constant_Value_p4);

  /* Sum: '<S38>/Sum' */
  ctrl_DP_basic_B.Sum_f = rtb_Row1_o - rtb_psi_dot;

  /* Saturate: '<S39>/Saturation' */
  if (ctrl_DP_basic_B.psi > ctrl_DP_basic_P.Saturation_UpperSat_o) {
    rtb_Row1_o = ctrl_DP_basic_P.Saturation_UpperSat_o;
  } else if (ctrl_DP_basic_B.psi < ctrl_DP_basic_P.Saturation_LowerSat_j) {
    rtb_Row1_o = ctrl_DP_basic_P.Saturation_LowerSat_j;
  } else {
    rtb_Row1_o = ctrl_DP_basic_B.psi;
  }

  /* End of Saturate: '<S39>/Saturation' */

  /* Signum: '<S39>/Sign' */
  if (rtb_Row1_o < 0.0) {
    u_idx_1 = -1.0;
  } else if (rtb_Row1_o > 0.0) {
    u_idx_1 = 1.0;
  } else if (rtb_Row1_o == 0.0) {
    u_idx_1 = 0.0;
  } else {
    u_idx_1 = rtb_Row1_o;
  }

  /* Gain: '<S39>/Gain' incorporates:
   *  Signum: '<S39>/Sign'
   */
  rtb_psi_dot = ctrl_DP_basic_P.Gain_Gain_h * u_idx_1;

  /* Sum: '<S39>/Sum1' */
  rtb_Row1_o += rtb_psi_dot;

  /* Math: '<S39>/Math Function' incorporates:
   *  Constant: '<S39>/Constant'
   */
  rtb_Row1_o = rt_remd_snf(rtb_Row1_o, ctrl_DP_basic_P.Constant_Value_i);

  /* Sum: '<S39>/Sum' */
  rtb_Row1_o -= rtb_psi_dot;

  /* Fcn: '<S6>/Fcn' */
  rtb_psi_dot = rtb_Row1_o;

  /* Integrator: '<S6>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator2_Reset_ZCE,
                       ctrl_DP_basic_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_basic_X.Integrator2_CSTATE[0] = (ctrl_DP_basic_P.Integrator2_IC[0]);
      ctrl_DP_basic_X.Integrator2_CSTATE[1] = (ctrl_DP_basic_P.Integrator2_IC[1]);
      ctrl_DP_basic_X.Integrator2_CSTATE[2] = (ctrl_DP_basic_P.Integrator2_IC[2]);
    }
  }

  ctrl_DP_basic_B.Integrator2[0] = ctrl_DP_basic_X.Integrator2_CSTATE[0];
  ctrl_DP_basic_B.Integrator2[1] = ctrl_DP_basic_X.Integrator2_CSTATE[1];
  ctrl_DP_basic_B.Integrator2[2] = ctrl_DP_basic_X.Integrator2_CSTATE[2];

  /* Sum: '<S6>/Sum' */
  rtb_Sum[0] = ctrl_DP_basic_B.x - ctrl_DP_basic_B.Integrator[0];
  rtb_Sum[1] = ctrl_DP_basic_B.y - ctrl_DP_basic_B.Integrator[1];
  rtb_Sum[2] = rtb_Row1_o - ctrl_DP_basic_B.Sum_f;

  /* Product: '<S6>/Matrix Multiply2' */
  for (p2 = 0; p2 < 3; p2++) {
    rtb_MatrixMultiply[p2] = 0.0;
    rtb_MatrixMultiply[p2] += ctrl_DP_basic_B.sf_MATLABFunction2_p.K_d[p2] *
      rtb_Sum[0];
    rtb_MatrixMultiply[p2] += ctrl_DP_basic_B.sf_MATLABFunction2_p.K_d[p2 + 3] *
      rtb_Sum[1];
    rtb_MatrixMultiply[p2] += ctrl_DP_basic_B.sf_MATLABFunction2_p.K_d[p2 + 6] *
      rtb_Sum[2];
  }

  /* End of Product: '<S6>/Matrix Multiply2' */

  /* MATLAB Function: '<S45>/Bow thruster' */
  /* MATLAB Function 'u_2_tau/Thruster mapping/Bow thruster': '<S46>:1' */
  /* '<S46>:1:3' */
  /*  Thruster characteristics */
  if (ctrl_DP_basic_B.u_BT > 0.0879) {
    /* '<S46>:1:5' */
    /* '<S46>:1:10' */
    rtb_Row2 = exp(0.1174 * ctrl_DP_basic_B.u_BT) * 2.515 + exp(-1.131 *
      ctrl_DP_basic_B.u_BT) * -2.807;
  } else if (ctrl_DP_basic_B.u_BT < -0.059) {
    /* '<S46>:1:11' */
    /* '<S46>:1:16' */
    rtb_Row2 = exp(0.193 * ctrl_DP_basic_B.u_BT) * -548.0 + exp(0.1992 *
      ctrl_DP_basic_B.u_BT) * 548.2;
  } else {
    /* '<S46>:1:18' */
    rtb_Row2 = 0.0;
  }

  /* MATLAB Function: '<S9>/Thruster configuration matrix' incorporates:
   *  MATLAB Function: '<S45>/Bow thruster'
   *  MATLAB Function: '<S45>/VSP'
   */
  /*  Thruster losses due to forward speed */
  /* '<S46>:1:21' */
  /* '<S46>:1:24' */
  /* '<S46>:1:25' */
  /* MATLAB Function 'u_2_tau/Thruster mapping/VSP': '<S47>:1' */
  /*  Calculating the force in x-direction */
  /* '<S47>:1:6' */
  /* '<S47>:1:9' */
  /* '<S47>:1:12' */
  /* '<S47>:1:15' */
  /* '<S47>:1:18' */
  /* '<S47>:1:21' */
  /* '<S47>:1:22' */
  /*  Calculating the force in y-direction */
  /* '<S47>:1:31' */
  /* '<S47>:1:34' */
  /* '<S47>:1:37' */
  /* '<S47>:1:40' */
  /* '<S47>:1:43' */
  /* '<S47>:1:46' */
  /* '<S47>:1:47' */
  /* MATLAB Function 'u_2_tau/Thruster configuration matrix': '<S44>:1' */
  /* '<S44>:1:7' */
  /* '<S44>:1:13' */
  u_idx_2 = (((((sin(1.001 * ctrl_DP_basic_B.alpha_VSP + 1.564) * 1.107 + sin
                 (0.1397 * ctrl_DP_basic_B.alpha_VSP + -1.599) * 0.3471) + sin
                (1.993 * ctrl_DP_basic_B.alpha_VSP + 1.886) * 0.1558) + sin
               (0.218 * ctrl_DP_basic_B.alpha_VSP + 1.513) * 0.1599) + sin(2.986
    * ctrl_DP_basic_B.alpha_VSP + -1.601) * 0.08237) + sin(3.964 *
              ctrl_DP_basic_B.alpha_VSP + 1.738) * 0.04641) *
    ctrl_DP_basic_B.u_VSP;
  rtb_Row1 = (((((sin(1.001 * ctrl_DP_basic_B.alpha_VSP + 0.01605) * 0.7936 +
                  sin(1.997 * ctrl_DP_basic_B.alpha_VSP + 0.03229) * 0.2112) +
                 sin(2.991 * ctrl_DP_basic_B.alpha_VSP + 2.986) * 0.07608) + sin
                (3.999 * ctrl_DP_basic_B.alpha_VSP + -0.8668) * 0.04817) + sin
               (4.904 * ctrl_DP_basic_B.alpha_VSP + -2.622) * 0.01757) + sin
              (5.068 * ctrl_DP_basic_B.alpha_VSP + 0.2548) * -0.02089) *
    ctrl_DP_basic_B.u_VSP;
  u_idx_1 = (atan(-10.22 * ctrl_DP_basic_B.Integrator1_g[0] + 2.947) * 0.3075 +
             0.7561) * rtb_Row2 / 1.1385;
  for (p2 = 0; p2 < 3; p2++) {
    rtb_TmpSignalConversionAtSFu_pa[p2] = a[p2 + 6] * u_idx_1 + (a[p2 + 3] *
      rtb_Row1 + a[p2] * u_idx_2);
  }

  /* Fcn: '<S36>/Row2' */
  /* '<S44>:1:15' */
  /* '<S44>:1:16' */
  /* '<S44>:1:17' */
  u_idx_1 = rtb_MatrixMultiply[0];
  u_idx_2 = rtb_MatrixMultiply[1];

  /* Fcn: '<S36>/Row3' */
  rtb_Row1 = rtb_MatrixMultiply[2];

  /* Sum: '<S6>/Sum2' incorporates:
   *  Fcn: '<S36>/Row1'
   *  Fcn: '<S36>/Row2'
   *  Fcn: '<S36>/Row3'
   *  Fcn: '<S6>/Fcn'
   *  MATLAB Function: '<S9>/Thruster configuration matrix'
   */
  rtb_MatrixMultiply[0] = (cos(rtb_Row1_o) * rtb_MatrixMultiply[0] + sin
    (rtb_Row1_o) * rtb_MatrixMultiply[1]) + rtb_TmpSignalConversionAtSFu_pa[0];
  rtb_MatrixMultiply[1] = (-sin(rtb_Row1_o) * u_idx_1 + cos(rtb_Row1_o) *
    u_idx_2) + rtb_TmpSignalConversionAtSFu_pa[1];
  rtb_MatrixMultiply[2] = rtb_Row1 + rtb_TmpSignalConversionAtSFu_pa[2];

  /* MATLAB Function: '<S6>/D(nu)*nu' */
  /* MATLAB Function 'Nonlinear Passisve Observer/D(nu)*nu': '<S34>:1' */
  /* '<S34>:1:3' */
  /* '<S34>:1:4' */
  /* '<S34>:1:5' */
  /* '<S34>:1:7' */
  /* D */
  /*     D = D(U,V,R) */
  /*     This function was generated by the Symbolic Math Toolbox version 6.0. */
  /*     17-Mar-2015 11:18:31 */
  rtb_Row2 = fabs(ctrl_DP_basic_B.Integrator1_g[2]);
  rtb_Row1 = fabs(ctrl_DP_basic_B.Integrator1_g[1]);
  rtb_y_l[0] = (ctrl_DP_basic_B.Integrator1_g[0] *
                ctrl_DP_basic_B.Integrator1_g[0] * 3.787 +
                ctrl_DP_basic_B.Integrator1_g[0] * -0.3545) + 0.6555;
  rtb_y_l[1] = 0.0;
  rtb_y_l[2] = 0.0;
  rtb_y_l[3] = ctrl_DP_basic_B.Integrator1_g[1] * 2.443;
  rtb_y_l[4] = ((rtb_Row2 * 0.805 + ctrl_DP_basic_B.Integrator1_g[1] * 2.776) +
                ctrl_DP_basic_B.Integrator1_g[1] *
                ctrl_DP_basic_B.Integrator1_g[1] * 64.91) + 1.33;
  rtb_y_l[5] = rtb_Row2 * -0.13 + ctrl_DP_basic_B.Integrator1_g[1] * 0.2088;
  rtb_y_l[6] = 0.0;
  rtb_y_l[7] = (rtb_Row2 * 3.45 + rtb_Row1 * 0.845) + 7.25;
  rtb_y_l[8] = (rtb_Row2 * 0.75 - rtb_Row1 * 0.08) + 1.9;
  memcpy(&D_NL[0], &rtb_y_l[0], 9U * sizeof(real_T));

  /* MATLAB Function: '<S6>/C(nu)*nu' */
  /* '<S34>:1:9' */
  /* MATLAB Function 'Nonlinear Passisve Observer/C(nu)*nu': '<S33>:1' */
  /* '<S33>:1:3' */
  /* '<S33>:1:4' */
  /* '<S33>:1:5' */
  /* '<S33>:1:7' */
  /* C */
  /*     C = C(U,V,R) */
  /*     This function was generated by the Symbolic Math Toolbox version 6.0. */
  /*     17-Mar-2015 11:18:31 */
  rtb_Row2 = ctrl_DP_basic_B.Integrator1_g[0] * 16.79;
  rtb_y_l[0] = 0.0;
  rtb_y_l[1] = 0.0;
  rtb_y_l[2] = ctrl_DP_basic_B.Integrator1_g[2] * 0.554625 +
    ctrl_DP_basic_B.Integrator1_g[1] * 24.79;
  rtb_y_l[3] = 0.0;
  rtb_y_l[4] = 0.0;
  rtb_y_l[5] = -rtb_Row2;
  rtb_y_l[6] = ctrl_DP_basic_B.Integrator1_g[2] * -0.554625 -
    ctrl_DP_basic_B.Integrator1_g[1] * 24.79;
  rtb_y_l[7] = rtb_Row2;
  rtb_y_l[8] = 0.0;
  memcpy(&C_NL[0], &rtb_y_l[0], 9U * sizeof(real_T));

  /* Sum: '<S6>/Sum3' incorporates:
   *  Fcn: '<S37>/Row1'
   *  Fcn: '<S37>/Row2'
   *  Fcn: '<S37>/Row3'
   *  Fcn: '<S6>/Fcn'
   *  MATLAB Function: '<S6>/D(nu)*nu'
   */
  /* '<S33>:1:9' */
  tmp[0] = cos(rtb_Row1_o) * ctrl_DP_basic_B.Integrator2[0] + sin(rtb_Row1_o) *
    ctrl_DP_basic_B.Integrator2[1];
  tmp[1] = -sin(rtb_Row1_o) * ctrl_DP_basic_B.Integrator2[0] + cos(rtb_Row1_o) *
    ctrl_DP_basic_B.Integrator2[1];
  tmp[2] = ctrl_DP_basic_B.Integrator2[2];
  for (p2 = 0; p2 < 3; p2++) {
    tmp_0[p2] = (tmp[p2] + rtb_MatrixMultiply[p2]) - ((D_NL[p2 + 3] *
      ctrl_DP_basic_B.Integrator1_g[1] + D_NL[p2] *
      ctrl_DP_basic_B.Integrator1_g[0]) + D_NL[p2 + 6] *
      ctrl_DP_basic_B.Integrator1_g[2]);
  }

  /* MATLAB Function: '<S6>/C(nu)*nu' incorporates:
   *  Sum: '<S6>/Sum3'
   */
  for (p2 = 0; p2 < 3; p2++) {
    rtb_TmpSignalConversionAtSFu_pa[p2] = C_NL[p2 + 6] *
      ctrl_DP_basic_B.Integrator1_g[2] + (C_NL[p2 + 3] *
      ctrl_DP_basic_B.Integrator1_g[1] + C_NL[p2] *
      ctrl_DP_basic_B.Integrator1_g[0]);
  }

  /* Sum: '<S6>/Sum3' */
  rtb_MatrixMultiply[0] = tmp_0[0] - rtb_TmpSignalConversionAtSFu_pa[0];
  rtb_MatrixMultiply[1] = tmp_0[1] - rtb_TmpSignalConversionAtSFu_pa[1];
  rtb_MatrixMultiply[2] = tmp_0[2] - rtb_TmpSignalConversionAtSFu_pa[2];

  /* Gain: '<S6>/M^-1' */
  for (p2 = 0; p2 < 3; p2++) {
    ctrl_DP_basic_B.M1[p2] = 0.0;
    ctrl_DP_basic_B.M1[p2] += ctrl_DP_basic_P.M1_Gain[p2] * rtb_MatrixMultiply[0];
    ctrl_DP_basic_B.M1[p2] += ctrl_DP_basic_P.M1_Gain[p2 + 3] *
      rtb_MatrixMultiply[1];
    ctrl_DP_basic_B.M1[p2] += ctrl_DP_basic_P.M1_Gain[p2 + 6] *
      rtb_MatrixMultiply[2];
  }

  /* End of Gain: '<S6>/M^-1' */

  /* Integrator: '<S15>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator2_Reset_ZCE_m,
                       ctrl_DP_basic_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_basic_X.Integrator2_CSTATE_e[0] = ctrl_DP_basic_P.Integrator2_IC_h;
      ctrl_DP_basic_X.Integrator2_CSTATE_e[1] = ctrl_DP_basic_P.Integrator2_IC_h;
      ctrl_DP_basic_X.Integrator2_CSTATE_e[2] = ctrl_DP_basic_P.Integrator2_IC_h;
    }
  }

  rtb_MatrixMultiply[0] = ctrl_DP_basic_X.Integrator2_CSTATE_e[0];
  rtb_MatrixMultiply[1] = ctrl_DP_basic_X.Integrator2_CSTATE_e[1];
  rtb_MatrixMultiply[2] = ctrl_DP_basic_X.Integrator2_CSTATE_e[2];

  /* MATLAB Function: '<S15>/w_d^3' */
  /* MATLAB Function 'Guidance/Reference model/w_d^3': '<S20>:1' */
  /* '<S20>:1:4' */
  memcpy(&D_NL[0], &rtb_w_d[0], 9U * sizeof(real_T));
  rtb_Row2 = 3.0;
  firstmult = true;
  do {
    p1 = 0;
    rtb_Row1 = floor(rtb_Row2 / 2.0);
    if (2.0 * rtb_Row1 != rtb_Row2) {
      if (firstmult) {
        memcpy(&rtb_y[0], &D_NL[0], 9U * sizeof(real_T));
        firstmult = false;
      } else {
        for (p2 = 0; p2 < 3; p2++) {
          for (p3 = 0; p3 < 3; p3++) {
            rtb_y_l[p2 + 3 * p3] = 0.0;
            rtb_y_l[p2 + 3 * p3] += D_NL[3 * p3] * rtb_y[p2];
            rtb_y_l[p2 + 3 * p3] += D_NL[3 * p3 + 1] * rtb_y[p2 + 3];
            rtb_y_l[p2 + 3 * p3] += D_NL[3 * p3 + 2] * rtb_y[p2 + 6];
          }
        }

        for (p2 = 0; p2 < 3; p2++) {
          rtb_y[3 * p2] = rtb_y_l[3 * p2];
          rtb_y[1 + 3 * p2] = rtb_y_l[3 * p2 + 1];
          rtb_y[2 + 3 * p2] = rtb_y_l[3 * p2 + 2];
        }
      }
    }

    if (rtb_Row1 == 0.0) {
      p1 = 1;
    } else {
      rtb_Row2 = rtb_Row1;
      for (p2 = 0; p2 < 3; p2++) {
        for (p3 = 0; p3 < 3; p3++) {
          rtb_y_l[p2 + 3 * p3] = 0.0;
          rtb_y_l[p2 + 3 * p3] += D_NL[3 * p3] * D_NL[p2];
          rtb_y_l[p2 + 3 * p3] += D_NL[3 * p3 + 1] * D_NL[p2 + 3];
          rtb_y_l[p2 + 3 * p3] += D_NL[3 * p3 + 2] * D_NL[p2 + 6];
        }
      }

      for (p2 = 0; p2 < 3; p2++) {
        D_NL[3 * p2] = rtb_y_l[3 * p2];
        D_NL[1 + 3 * p2] = rtb_y_l[3 * p2 + 1];
        D_NL[2 + 3 * p2] = rtb_y_l[3 * p2 + 2];
      }
    }
  } while (p1 == 0);

  /* End of MATLAB Function: '<S15>/w_d^3' */

  /* MATLAB Function: '<S15>/w_d^-2' */
  /* MATLAB Function 'Guidance/Reference model/w_d^-2': '<S19>:1' */
  /* '<S19>:1:4' */
  for (p2 = 0; p2 < 3; p2++) {
    for (p3 = 0; p3 < 3; p3++) {
      D_NL[p2 + 3 * p3] = 0.0;
      D_NL[p2 + 3 * p3] += rtb_w_d[3 * p3] * rtb_w_d[p2];
      D_NL[p2 + 3 * p3] += rtb_w_d[3 * p3 + 1] * rtb_w_d[p2 + 3];
      D_NL[p2 + 3 * p3] += rtb_w_d[3 * p3 + 2] * rtb_w_d[p2 + 6];
    }
  }

  memcpy(&C_NL[0], &D_NL[0], 9U * sizeof(real_T));
  p1 = 0;
  p2 = 3;
  p3 = 6;
  rtb_Row2 = fabs(D_NL[0]);
  rtb_Row1 = fabs(D_NL[1]);
  rtb_Row1_o = fabs(D_NL[2]);
  if ((rtb_Row1 > rtb_Row2) && (rtb_Row1 > rtb_Row1_o)) {
    p1 = 3;
    p2 = 0;
    C_NL[0] = D_NL[1];
    C_NL[1] = D_NL[0];
    C_NL[3] = D_NL[4];
    C_NL[4] = D_NL[3];
    C_NL[6] = D_NL[7];
    C_NL[7] = D_NL[6];
  } else {
    if (rtb_Row1_o > rtb_Row2) {
      p1 = 6;
      p3 = 0;
      C_NL[0] = D_NL[2];
      C_NL[2] = D_NL[0];
      C_NL[3] = D_NL[5];
      C_NL[5] = D_NL[3];
      C_NL[6] = D_NL[8];
      C_NL[8] = D_NL[6];
    }
  }

  rtb_Row1 = C_NL[1] / C_NL[0];
  C_NL[1] /= C_NL[0];
  rtb_Row2 = C_NL[2] / C_NL[0];
  C_NL[2] /= C_NL[0];
  C_NL[4] -= rtb_Row1 * C_NL[3];
  C_NL[5] -= rtb_Row2 * C_NL[3];
  C_NL[7] -= rtb_Row1 * C_NL[6];
  C_NL[8] -= rtb_Row2 * C_NL[6];
  if (fabs(C_NL[5]) > fabs(C_NL[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    C_NL[1] = rtb_Row2;
    C_NL[2] = rtb_Row1;
    rtb_Row2 = C_NL[4];
    C_NL[4] = C_NL[5];
    C_NL[5] = rtb_Row2;
    rtb_Row2 = C_NL[7];
    C_NL[7] = C_NL[8];
    C_NL[8] = rtb_Row2;
  }

  rtb_Row1_o = C_NL[5];
  u_idx_1 = C_NL[4];
  rtb_Row2 = C_NL[5] / C_NL[4];
  C_NL[8] -= rtb_Row2 * C_NL[7];
  rtb_Row1 = (rtb_Row2 * C_NL[1] - C_NL[2]) / C_NL[8];
  rtb_Row2 = -(C_NL[7] * rtb_Row1 + C_NL[1]) / C_NL[4];
  rtb_y_l[p1] = ((1.0 - C_NL[3] * rtb_Row2) - C_NL[6] * rtb_Row1) / C_NL[0];
  rtb_y_l[p1 + 1] = rtb_Row2;
  rtb_y_l[p1 + 2] = rtb_Row1;
  rtb_Row1 = -(rtb_Row1_o / u_idx_1) / C_NL[8];
  rtb_Row2 = (1.0 - C_NL[7] * rtb_Row1) / C_NL[4];
  rtb_y_l[p2] = -(C_NL[3] * rtb_Row2 + C_NL[6] * rtb_Row1) / C_NL[0];
  rtb_y_l[p2 + 1] = rtb_Row2;
  rtb_y_l[p2 + 2] = rtb_Row1;
  rtb_Row1 = 1.0 / C_NL[8];
  rtb_Row2 = -C_NL[7] * rtb_Row1 / C_NL[4];
  rtb_y_l[p3] = -(C_NL[3] * rtb_Row2 + C_NL[6] * rtb_Row1) / C_NL[0];
  rtb_y_l[p3 + 1] = rtb_Row2;
  rtb_y_l[p3 + 2] = rtb_Row1;

  /* End of MATLAB Function: '<S15>/w_d^-2' */

  /* Product: '<S15>/Matrix Multiply1' incorporates:
   *  Sum: '<S15>/Sum'
   */
  for (p2 = 0; p2 < 3; p2++) {
    rtb_TmpSignalConversionAtSFu_pa[p2] = rtb_y_l[p2 + 6] * rtb_MatrixMultiply[2]
      + (rtb_y_l[p2 + 3] * rtb_MatrixMultiply[1] + rtb_y_l[p2] *
         rtb_MatrixMultiply[0]);
  }

  /* End of Product: '<S15>/Matrix Multiply1' */

  /* Sum: '<S15>/Sum' incorporates:
   *  Product: '<S15>/Matrix Multiply'
   */
  u_idx_2 = ctrl_DP_basic_B.x_ref - rtb_TmpSignalConversionAtSFu_pa[0];
  rtb_Row1 = ctrl_DP_basic_B.y_ref - rtb_TmpSignalConversionAtSFu_pa[1];
  u_idx_1 = ctrl_DP_basic_B.psi_ref - rtb_TmpSignalConversionAtSFu_pa[2];

  /* Product: '<S15>/Matrix Multiply' */
  for (p2 = 0; p2 < 3; p2++) {
    ctrl_DP_basic_B.MatrixMultiply[p2] = 0.0;
    ctrl_DP_basic_B.MatrixMultiply[p2] += rtb_y[p2] * u_idx_2;
    ctrl_DP_basic_B.MatrixMultiply[p2] += rtb_y[p2 + 3] * rtb_Row1;
    ctrl_DP_basic_B.MatrixMultiply[p2] += rtb_y[p2 + 6] * u_idx_1;
  }

  /* MATLAB Function: '<S23>/diag1' incorporates:
   *  SignalConversion: '<S29>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Guidance/Reference model/w_d*w_d': '<S17>:1' */
  /* '<S17>:1:4' */
  /* MATLAB Function 'Input/Guidance gains/diag1': '<S29>:1' */
  /* '<S29>:1:4' */
  memset(&rtb_y[0], 0, 9U * sizeof(real_T));
  rtb_y[0] = ctrl_DP_basic_B.zeta_x;
  rtb_y[4] = ctrl_DP_basic_B.zeta_y;
  rtb_y[8] = ctrl_DP_basic_B.zeta_psi;

  /* MATLAB Function: '<S15>/w_d*w_d' incorporates:
   *  Product: '<S15>/Matrix Multiply2'
   */
  /* MATLAB Function 'Guidance/Reference model/w_d*w_d1': '<S18>:1' */
  /* '<S18>:1:4' */
  for (p2 = 0; p2 < 3; p2++) {
    for (p3 = 0; p3 < 3; p3++) {
      rtb_y_l[p2 + 3 * p3] = 0.0;
      rtb_y_l[p2 + 3 * p3] += rtb_w_d[3 * p3] * rtb_w_d[p2];
      rtb_y_l[p2 + 3 * p3] += rtb_w_d[3 * p3 + 1] * rtb_w_d[p2 + 3];
      rtb_y_l[p2 + 3 * p3] += rtb_w_d[3 * p3 + 2] * rtb_w_d[p2 + 6];
    }
  }

  /* End of MATLAB Function: '<S15>/w_d*w_d' */

  /* MATLAB Function: '<S15>/w_d*w_d1' incorporates:
   *  Product: '<S15>/Matrix Multiply5'
   */
  for (p2 = 0; p2 < 3; p2++) {
    for (p3 = 0; p3 < 3; p3++) {
      C_NL[p2 + 3 * p3] = 0.0;
      C_NL[p2 + 3 * p3] += 2.0 * rtb_y[p2] * rtb_w_d[3 * p3];
      C_NL[p2 + 3 * p3] += rtb_y[p2 + 3] * 2.0 * rtb_w_d[3 * p3 + 1];
      C_NL[p2 + 3 * p3] += rtb_y[p2 + 6] * 2.0 * rtb_w_d[3 * p3 + 2];
    }
  }

  /* End of MATLAB Function: '<S15>/w_d*w_d1' */

  /* Sum: '<S15>/Sum2' incorporates:
   *  Product: '<S15>/Matrix Multiply2'
   *  Sum: '<S15>/Sum5'
   */
  for (p2 = 0; p2 < 3; p2++) {
    tmp[p2] = rtb_MatrixMultiply[p2] - ((rtb_y_l[p2 + 3] *
      rtb_MatrixMultiply5_idx_1 + rtb_y_l[p2] * rtb_MatrixMultiply5_idx_0) +
      rtb_y_l[p2 + 6] * rtb_MatrixMultiply5_idx_2);
  }

  /* End of Sum: '<S15>/Sum2' */

  /* Product: '<S15>/Matrix Multiply5' incorporates:
   *  Sum: '<S15>/Sum5'
   */
  for (p2 = 0; p2 < 3; p2++) {
    tmp_0[p2] = C_NL[p2 + 6] * ctrl_DP_basic_B.Integrator3[2] + (C_NL[p2 + 3] *
      ctrl_DP_basic_B.Integrator3[1] + C_NL[p2] * ctrl_DP_basic_B.Integrator3[0]);
  }

  /* Sum: '<S15>/Sum5' */
  ctrl_DP_basic_B.Sum5[0] = tmp[0] - tmp_0[0];
  ctrl_DP_basic_B.Sum5[1] = tmp[1] - tmp_0[1];
  ctrl_DP_basic_B.Sum5[2] = tmp[2] - tmp_0[2];
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* MATLAB Function: '<S24>/MATLAB Function' incorporates:
     *  Constant: '<S24>/Constant'
     *  Constant: '<S24>/Constant1'
     *  Constant: '<S24>/Constant2'
     */
    ctrl_DP_basic_MATLABFunction(ctrl_DP_basic_P.Constant_Value_k,
      ctrl_DP_basic_P.Constant1_Value, ctrl_DP_basic_P.Constant2_Value,
      &ctrl_DP_basic_B.sf_MATLABFunction_l);

    /* MATLAB Function: '<S24>/MATLAB Function1' incorporates:
     *  Constant: '<S24>/Constant3'
     *  Constant: '<S24>/Constant4'
     *  Constant: '<S24>/Constant5'
     */
    ctrl_DP_basic_MATLABFunction1(ctrl_DP_basic_P.Constant3_Value,
      ctrl_DP_basic_P.Constant4_Value, ctrl_DP_basic_P.Constant5_Value,
      &ctrl_DP_basic_B.sf_MATLABFunction1_c);
  }

  /* Product: '<S6>/Matrix Multiply' */
  for (p2 = 0; p2 < 3; p2++) {
    rtb_MatrixMultiply[p2] = 0.0;
    rtb_MatrixMultiply[p2] += ctrl_DP_basic_B.sf_MATLABFunction_l.K_p[p2] *
      rtb_Sum[0];
    rtb_MatrixMultiply[p2] += ctrl_DP_basic_B.sf_MATLABFunction_l.K_p[p2 + 3] *
      rtb_Sum[1];
    rtb_MatrixMultiply[p2] += ctrl_DP_basic_B.sf_MATLABFunction_l.K_p[p2 + 6] *
      rtb_Sum[2];
  }

  /* End of Product: '<S6>/Matrix Multiply' */

  /* Product: '<S6>/Matrix Multiply1' */
  for (p2 = 0; p2 < 3; p2++) {
    ctrl_DP_basic_B.MatrixMultiply1[p2] = 0.0;
    ctrl_DP_basic_B.MatrixMultiply1[p2] +=
      ctrl_DP_basic_B.sf_MATLABFunction1_c.K_i[p2] * rtb_Sum[0];
    ctrl_DP_basic_B.MatrixMultiply1[p2] +=
      ctrl_DP_basic_B.sf_MATLABFunction1_c.K_i[p2 + 3] * rtb_Sum[1];
    ctrl_DP_basic_B.MatrixMultiply1[p2] +=
      ctrl_DP_basic_B.sf_MATLABFunction1_c.K_i[p2 + 6] * rtb_Sum[2];
  }

  /* End of Product: '<S6>/Matrix Multiply1' */

  /* Sum: '<S6>/Sum1' incorporates:
   *  Fcn: '<S35>/Fcn'
   *  Fcn: '<S35>/Fcn1'
   *  Fcn: '<S35>/Fcn2'
   */
  ctrl_DP_basic_B.Sum1[0] = (cos(rtb_psi_dot) * ctrl_DP_basic_B.Integrator1_g[0]
    - sin(rtb_psi_dot) * ctrl_DP_basic_B.Integrator1_g[1]) + rtb_MatrixMultiply
    [0];
  ctrl_DP_basic_B.Sum1[1] = (sin(rtb_psi_dot) * ctrl_DP_basic_B.Integrator1_g[0]
    + cos(rtb_psi_dot) * ctrl_DP_basic_B.Integrator1_g[1]) + rtb_MatrixMultiply
    [1];
  ctrl_DP_basic_B.Sum1[2] = rtb_MatrixMultiply[2] +
    ctrl_DP_basic_B.Integrator1_g[2];

  /* Fcn: '<S21>/Row3' */
  ctrl_DP_basic_B.Row3 = ctrl_DP_basic_B.Integrator3[2];

  /* Fcn: '<S21>/Row1' */
  ctrl_DP_basic_B.Row1 = cos(ctrl_DP_basic_B.Sum) * ctrl_DP_basic_B.Integrator3
    [0] + sin(ctrl_DP_basic_B.Sum) * ctrl_DP_basic_B.Integrator3[1];

  /* Fcn: '<S21>/Row2' */
  ctrl_DP_basic_B.Row2 = -sin(ctrl_DP_basic_B.Sum) *
    ctrl_DP_basic_B.Integrator3[0] + cos(ctrl_DP_basic_B.Sum) *
    ctrl_DP_basic_B.Integrator3[1];
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
  }
}

/* Model update function */
void ctrl_DP_basic_update(void)
{
  /* Update for Integrator: '<S15>/Integrator1' */
  ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading = 0;

  /* Update for Integrator: '<S6>/Integrator' */
  ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_DP_basic_M->solverInfo);
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
  if (!(++ctrl_DP_basic_M->Timing.clockTick0)) {
    ++ctrl_DP_basic_M->Timing.clockTickH0;
  }

  ctrl_DP_basic_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ctrl_DP_basic_M->solverInfo);

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
    if (!(++ctrl_DP_basic_M->Timing.clockTick1)) {
      ++ctrl_DP_basic_M->Timing.clockTickH1;
    }

    ctrl_DP_basic_M->Timing.t[1] = ctrl_DP_basic_M->Timing.clockTick1 *
      ctrl_DP_basic_M->Timing.stepSize1 + ctrl_DP_basic_M->Timing.clockTickH1 *
      ctrl_DP_basic_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_DP_basic_derivatives(void)
{
  /* Derivatives for Integrator: '<S15>/Integrator1' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE[0] = ctrl_DP_basic_B.Integrator3[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE[1] = ctrl_DP_basic_B.Integrator3[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE[2] = ctrl_DP_basic_B.Integrator3[2];
  }

  /* Derivatives for Integrator: '<S10>/Integrator' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE[0] = ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE[1] = ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE[2] = ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[2];
  }

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE_g[0] = ctrl_DP_basic_B.M1[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE_g[1] = ctrl_DP_basic_B.M1[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE_g[2] = ctrl_DP_basic_B.M1[2];
  }

  /* Derivatives for Integrator: '<S15>/Integrator3' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator3_CSTATE[0] = ctrl_DP_basic_B.Sum5[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator3_CSTATE[1] = ctrl_DP_basic_B.Sum5[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator3_CSTATE[2] = ctrl_DP_basic_B.Sum5[2];
  }

  /* Derivatives for Integrator: '<S6>/Integrator' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE_l[0] = ctrl_DP_basic_B.Sum1[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE_l[1] = ctrl_DP_basic_B.Sum1[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE_l[2] = ctrl_DP_basic_B.Sum1[2];
  }

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator2_CSTATE[0] = ctrl_DP_basic_B.MatrixMultiply1[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator2_CSTATE[1] = ctrl_DP_basic_B.MatrixMultiply1[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator2_CSTATE[2] = ctrl_DP_basic_B.MatrixMultiply1[2];
  }

  /* Derivatives for Integrator: '<S15>/Integrator2' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator2_CSTATE_e[0] = ctrl_DP_basic_B.MatrixMultiply[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator2_CSTATE_e[1] = ctrl_DP_basic_B.MatrixMultiply[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator2_CSTATE_e[2] = ctrl_DP_basic_B.MatrixMultiply[2];
  }
}

/* Model initialize function */
void ctrl_DP_basic_initialize(void)
{
  ctrl_DP_basic_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator1_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator3_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator2_Reset_ZCE_m = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S15>/Integrator1' */
  if (rtmIsFirstInitCond(ctrl_DP_basic_M)) {
    ctrl_DP_basic_X.Integrator1_CSTATE[0] = 0.0;
    ctrl_DP_basic_X.Integrator1_CSTATE[1] = 0.0;
    ctrl_DP_basic_X.Integrator1_CSTATE[2] = 0.0;
  }

  ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S10>/Integrator' */
  ctrl_DP_basic_X.Integrator_CSTATE[0] = ctrl_DP_basic_P.Integrator_IC;
  ctrl_DP_basic_X.Integrator_CSTATE[1] = ctrl_DP_basic_P.Integrator_IC;
  ctrl_DP_basic_X.Integrator_CSTATE[2] = ctrl_DP_basic_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S6>/Integrator1' */
  ctrl_DP_basic_X.Integrator1_CSTATE_g[0] = (ctrl_DP_basic_P.Integrator1_IC[0]);
  ctrl_DP_basic_X.Integrator1_CSTATE_g[1] = (ctrl_DP_basic_P.Integrator1_IC[1]);
  ctrl_DP_basic_X.Integrator1_CSTATE_g[2] = (ctrl_DP_basic_P.Integrator1_IC[2]);

  /* InitializeConditions for Integrator: '<S15>/Integrator3' */
  ctrl_DP_basic_X.Integrator3_CSTATE[0] = ctrl_DP_basic_P.Integrator3_IC;
  ctrl_DP_basic_X.Integrator3_CSTATE[1] = ctrl_DP_basic_P.Integrator3_IC;
  ctrl_DP_basic_X.Integrator3_CSTATE[2] = ctrl_DP_basic_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  if (rtmIsFirstInitCond(ctrl_DP_basic_M)) {
    ctrl_DP_basic_X.Integrator_CSTATE_l[0] = 0.0;
    ctrl_DP_basic_X.Integrator_CSTATE_l[1] = 0.0;
    ctrl_DP_basic_X.Integrator_CSTATE_l[2] = 0.0;
  }

  ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S6>/Integrator2' */
  ctrl_DP_basic_X.Integrator2_CSTATE[0] = (ctrl_DP_basic_P.Integrator2_IC[0]);
  ctrl_DP_basic_X.Integrator2_CSTATE[1] = (ctrl_DP_basic_P.Integrator2_IC[1]);
  ctrl_DP_basic_X.Integrator2_CSTATE[2] = (ctrl_DP_basic_P.Integrator2_IC[2]);

  /* InitializeConditions for Integrator: '<S15>/Integrator2' */
  ctrl_DP_basic_X.Integrator2_CSTATE_e[0] = ctrl_DP_basic_P.Integrator2_IC_h;
  ctrl_DP_basic_X.Integrator2_CSTATE_e[1] = ctrl_DP_basic_P.Integrator2_IC_h;
  ctrl_DP_basic_X.Integrator2_CSTATE_e[2] = ctrl_DP_basic_P.Integrator2_IC_h;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ctrl_DP_basic_M)) {
    rtmSetFirstInitCond(ctrl_DP_basic_M, 0);
  }
}

/* Model terminate function */
void ctrl_DP_basic_terminate(void)
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
  ctrl_DP_basic_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_DP_basic_update();
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
  ctrl_DP_basic_initialize();
}

void MdlTerminate(void)
{
  ctrl_DP_basic_terminate();
}

/* Registration function */
RT_MODEL_ctrl_DP_basic_T *ctrl_DP_basic(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_DP_basic_M, 0,
                sizeof(RT_MODEL_ctrl_DP_basic_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_DP_basic_M->solverInfo,
                          &ctrl_DP_basic_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_DP_basic_M->solverInfo, &rtmGetTPtr(ctrl_DP_basic_M));
    rtsiSetStepSizePtr(&ctrl_DP_basic_M->solverInfo,
                       &ctrl_DP_basic_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_DP_basic_M->solverInfo,
                 &ctrl_DP_basic_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_DP_basic_M->solverInfo, (real_T **)
                         &ctrl_DP_basic_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_DP_basic_M->solverInfo,
      &ctrl_DP_basic_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_DP_basic_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_DP_basic_M)));
    rtsiSetRTModelPtr(&ctrl_DP_basic_M->solverInfo, ctrl_DP_basic_M);
  }

  rtsiSetSimTimeStep(&ctrl_DP_basic_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_DP_basic_M->ModelData.intgData.y = ctrl_DP_basic_M->ModelData.odeY;
  ctrl_DP_basic_M->ModelData.intgData.f[0] = ctrl_DP_basic_M->ModelData.odeF[0];
  ctrl_DP_basic_M->ModelData.intgData.f[1] = ctrl_DP_basic_M->ModelData.odeF[1];
  ctrl_DP_basic_M->ModelData.intgData.f[2] = ctrl_DP_basic_M->ModelData.odeF[2];
  ctrl_DP_basic_M->ModelData.intgData.f[3] = ctrl_DP_basic_M->ModelData.odeF[3];
  ctrl_DP_basic_M->ModelData.contStates = ((real_T *) &ctrl_DP_basic_X);
  rtsiSetSolverData(&ctrl_DP_basic_M->solverInfo, (void *)
                    &ctrl_DP_basic_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_DP_basic_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_DP_basic_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_DP_basic_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_DP_basic_M->Timing.sampleTimes =
      (&ctrl_DP_basic_M->Timing.sampleTimesArray[0]);
    ctrl_DP_basic_M->Timing.offsetTimes =
      (&ctrl_DP_basic_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_DP_basic_M->Timing.sampleTimes[0] = (0.0);
    ctrl_DP_basic_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_DP_basic_M->Timing.offsetTimes[0] = (0.0);
    ctrl_DP_basic_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_DP_basic_M, &ctrl_DP_basic_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_DP_basic_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_DP_basic_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_DP_basic_M, -1);
  ctrl_DP_basic_M->Timing.stepSize0 = 0.01;
  ctrl_DP_basic_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_DP_basic_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_DP_basic_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_DP_basic_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_DP_basic_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_DP_basic_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_DP_basic_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_DP_basic_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_DP_basic_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_DP_basic_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_DP_basic_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_DP_basic_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_DP_basic_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_DP_basic_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_DP_basic_M->rtwLogInfo, (NULL));
  }

  ctrl_DP_basic_M->solverInfoPtr = (&ctrl_DP_basic_M->solverInfo);
  ctrl_DP_basic_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_DP_basic_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_DP_basic_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_DP_basic_M->ModelData.blockIO = ((void *) &ctrl_DP_basic_B);
  (void) memset(((void *) &ctrl_DP_basic_B), 0,
                sizeof(B_ctrl_DP_basic_T));

  /* parameters */
  ctrl_DP_basic_M->ModelData.defaultParam = ((real_T *)&ctrl_DP_basic_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_DP_basic_X;
    ctrl_DP_basic_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_DP_basic_X, 0,
                  sizeof(X_ctrl_DP_basic_T));
  }

  /* states (dwork) */
  ctrl_DP_basic_M->ModelData.dwork = ((void *) &ctrl_DP_basic_DW);
  (void) memset((void *)&ctrl_DP_basic_DW, 0,
                sizeof(DW_ctrl_DP_basic_T));

  /* Initialize Sizes */
  ctrl_DP_basic_M->Sizes.numContStates = (21);/* Number of continuous states */
  ctrl_DP_basic_M->Sizes.numY = (0);   /* Number of model outputs */
  ctrl_DP_basic_M->Sizes.numU = (0);   /* Number of model inputs */
  ctrl_DP_basic_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_DP_basic_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_DP_basic_M->Sizes.numBlocks = (191);/* Number of blocks */
  ctrl_DP_basic_M->Sizes.numBlockIO = (51);/* Number of block outputs */
  ctrl_DP_basic_M->Sizes.numBlockPrms = (385);/* Sum of parameter "widths" */
  return ctrl_DP_basic_M;
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
#ifdef NI_ROOTMODEL_ctrl_DP_basic
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

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 36:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 37:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 38:
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

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 36:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 37:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 38:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_DP_basic_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // Input/Control Gains/K_p_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_p_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_p_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_p_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_p_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_p_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_i_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_i_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_i_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_i_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_i_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_i_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Control Gains/K_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Guidance gains/w_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.w_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Guidance gains/w_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.w_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Guidance gains/w_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.w_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Guidance gains/zeta_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.zeta_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Guidance gains/zeta_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.zeta_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/Guidance gains/zeta_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.zeta_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/psi_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.psi_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/x_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.x_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Input/y_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.y_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 22;
}

double ni_extout[34];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_VSP,0,0,
      0);
  } else {
    index += 1;
  }

  // omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.omega_VSP,0,0,
      0);
  } else {
    index += 1;
  }

  // omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.omega_VSP,0,0,
      0);
  } else {
    index += 1;
  }

  // alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_VSP,0,0,
      0);
  } else {
    index += 1;
  }

  // u_BT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_BT,0,0,0);
  } else {
    index += 1;
  }

  // u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_VSP,0,0,0);
  } else {
    index += 1;
  }

  // Observer output /eta_hat output/x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator,0,
      17,0);
  } else {
    index += 1;
  }

  // Observer output /eta_hat output/y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator,1,
      17,0);
  } else {
    index += 1;
  }

  // Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum_f,0,0,0);
  } else {
    index += 1;
  }

  // Observer output /nu_hat output/u_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g,
      0,17,0);
  } else {
    index += 1;
  }

  // Observer output /nu_hat output/v_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g,
      1,17,0);
  } else {
    index += 1;
  }

  // Observer output /nu_hat output/r_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g,
      2,17,0);
  } else {
    index += 1;
  }

  // Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1,0,17,0);
  } else {
    index += 1;
  }

  // Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1,1,17,0);
  } else {
    index += 1;
  }

  // Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1,2,17,0);
  } else {
    index += 1;
  }

  // Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2,0,
      17,0);
  } else {
    index += 1;
  }

  // Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2,1,
      17,0);
  } else {
    index += 1;
  }

  // Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2,2,
      17,0);
  } else {
    index += 1;
  }

  // u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_VSP,0,0,0);
  } else {
    index += 1;
  }

  // Control output/tau_N: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3,2,17,0);
  } else {
    index += 1;
  }

  // Control output/tau_X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3,0,17,0);
  } else {
    index += 1;
  }

  // Control output/tau_Y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3,1,17,0);
  } else {
    index += 1;
  }

  // Control output/psi_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_B.regulationerror,2,17,0);
  } else {
    index += 1;
  }

  // Control output/x_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_B.regulationerror,0,17,0);
  } else {
    index += 1;
  }

  // Control output/y_tidle: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_B.regulationerror,1,17,0);
  } else {
    index += 1;
  }

  // Control output/r_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4,2,17,0);
  } else {
    index += 1;
  }

  // Control output/u_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4,0,17,0);
  } else {
    index += 1;
  }

  // Control output/v_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4,1,17,0);
  } else {
    index += 1;
  }

  // Guidance output/x_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1,0,
      17,0);
  } else {
    index += 1;
  }

  // Guidance output/y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1,1,
      17,0);
  } else {
    index += 1;
  }

  // Guidance output/psi_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum,0,0,0);
  } else {
    index += 1;
  }

  // Guidance output/r_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row3,0,0,0);
  } else {
    index += 1;
  }

  // Guidance output/u_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row1,0,0,0);
  } else {
    index += 1;
  }

  // Guidance output/v_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row2,0,0,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 34;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_VSP,0,0,0);

  // omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.omega_VSP,0,0,0);

  // omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.omega_VSP,0,0,0);

  // alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_VSP,0,0,0);

  // u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_BT,0,0,0);

  // u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_VSP,0,0,0);

  // Observer output /eta_hat output/x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator,0,17,
    0);

  // Observer output /eta_hat output/y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator,1,17,
    0);

  // Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum_f,0,0,0);

  // Observer output /nu_hat output/u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g,0,
    17,0);

  // Observer output /nu_hat output/v_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g,1,
    17,0);

  // Observer output /nu_hat output/r_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g,2,
    17,0);

  // Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1,0,17,0);

  // Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1,1,17,0);

  // Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1,2,17,0);

  // Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2,0,17,
    0);

  // Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2,1,17,
    0);

  // Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2,2,17,
    0);

  // u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_VSP,0,0,0);

  // Control output/tau_N: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3,2,17,0);

  // Control output/tau_X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3,0,17,0);

  // Control output/tau_Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3,1,17,0);

  // Control output/psi_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.regulationerror,
    2,17,0);

  // Control output/x_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.regulationerror,
    0,17,0);

  // Control output/y_tidle: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.regulationerror,
    1,17,0);

  // Control output/r_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4,2,17,0);

  // Control output/u_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4,0,17,0);

  // Control output/v_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4,1,17,0);

  // Guidance output/x_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1,0,17,
    0);

  // Guidance output/y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1,1,17,
    0);

  // Guidance output/psi_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum,0,0,0);

  // Guidance output/r_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row3,0,0,0);

  // Guidance output/u_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row1,0,0,0);

  // Guidance output/v_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row2,0,0,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat), 36, 1, 2, 0, 0 },

  { 1,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat), 36, 1, 2, 2, 0 },

  { 2, "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain), 36, 1, 2, 4, 0 },

  { 3,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value), 36, 1, 2, 6, 0 },

  { 4, "ctrl_dp_basic/Input/Observer Gains/Constant6/Value", offsetof
    (P_ctrl_DP_basic_T, Constant6_Value), 36, 1, 2, 8, 0 },

  { 5, "ctrl_dp_basic/Input/Observer Gains/Constant7/Value", offsetof
    (P_ctrl_DP_basic_T, Constant7_Value), 36, 1, 2, 10, 0 },

  { 6, "ctrl_dp_basic/Input/Observer Gains/Constant8/Value", offsetof
    (P_ctrl_DP_basic_T, Constant8_Value), 36, 1, 2, 12, 0 },

  { 7,
    "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat_j), 36, 1, 2, 14, 0 },

  { 8,
    "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat_c), 36, 1, 2, 16, 0 },

  { 9,
    "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_j), 36, 1, 2, 18, 0 },

  { 10,
    "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value_f), 36, 1, 2, 20, 0 },

  { 11,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat_a), 36, 1, 2, 22, 0 },

  { 12,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat_d), 36, 1, 2, 24, 0 },

  { 13, "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_g), 36, 1, 2, 26, 0 },

  { 14,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value_p), 36, 1, 2, 28, 0 },

  { 15, "ctrl_dp_basic/Control/DP Controller/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator_IC), 36, 1, 2, 30, 0 },

  { 16, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator1/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator1_IC), 37, 3, 2, 32, 0 },

  { 17, "ctrl_dp_basic/Guidance/Reference model/Integrator3/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator3_IC), 36, 1, 2, 34, 0 },

  { 18, "ctrl_dp_basic/Constant/Value", offsetof(P_ctrl_DP_basic_T,
    Constant_Value_l), 36, 1, 2, 36, 0 },

  { 19,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat_l), 36, 1, 2, 38, 0 },

  { 20,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat_cz), 36, 1, 2, 40, 0 },

  { 21,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_d), 36, 1, 2, 42, 0 },

  { 22,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value_p4), 36, 1, 2, 44, 0 },

  { 23,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat_o), 36, 1, 2, 46, 0 },

  { 24,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat_j), 36, 1, 2, 48, 0 },

  { 25,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_h), 36, 1, 2, 50, 0 },

  { 26,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value_i), 36, 1, 2, 52, 0 },

  { 27, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator2_IC), 37, 3, 2, 54, 0 },

  { 28, "ctrl_dp_basic/Nonlinear Passisve Observer/M^-1/Gain", offsetof
    (P_ctrl_DP_basic_T, M1_Gain), 18, 9, 2, 56, 0 },

  { 29, "ctrl_dp_basic/Guidance/Reference model/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator2_IC_h), 36, 1, 2, 58, 0 },

  { 30, "ctrl_dp_basic/Input/Observer Gains/Constant/Value", offsetof
    (P_ctrl_DP_basic_T, Constant_Value_k), 36, 1, 2, 60, 0 },

  { 31, "ctrl_dp_basic/Input/Observer Gains/Constant1/Value", offsetof
    (P_ctrl_DP_basic_T, Constant1_Value), 36, 1, 2, 62, 0 },

  { 32, "ctrl_dp_basic/Input/Observer Gains/Constant2/Value", offsetof
    (P_ctrl_DP_basic_T, Constant2_Value), 36, 1, 2, 64, 0 },

  { 33, "ctrl_dp_basic/Input/Observer Gains/Constant3/Value", offsetof
    (P_ctrl_DP_basic_T, Constant3_Value), 36, 1, 2, 66, 0 },

  { 34, "ctrl_dp_basic/Input/Observer Gains/Constant4/Value", offsetof
    (P_ctrl_DP_basic_T, Constant4_Value), 36, 1, 2, 68, 0 },

  { 35, "ctrl_dp_basic/Input/Observer Gains/Constant5/Value", offsetof
    (P_ctrl_DP_basic_T, Constant5_Value), 36, 1, 2, 70, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 36;
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
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  3, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  3, 1,                                /* Parameter at index 27 */
  3, 3,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_dp_basic/Input/Control Gains/K_p_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_p_x)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_dp_basic/Input/Control Gains/K_p_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_p_y)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "ctrl_dp_basic/Input/Control Gains/K_p_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_p_psi)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "ctrl_dp_basic/Input/Control Gains/K_i_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_i_psi)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "ctrl_dp_basic/Input/Control Gains/K_i_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_i_x)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "ctrl_dp_basic/Input/Control Gains/K_i_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_i_y)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "ctrl_dp_basic/Input/Control Gains/K_d_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_d_psi)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "ctrl_dp_basic/Input/Control Gains/K_d_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_d_x)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8, "ctrl_dp_basic/Input/Control Gains/K_d_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_d_y)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 16, 0 },

  { 9, "ctrl_dp_basic/x", 0, "", offsetof(B_ctrl_DP_basic_T, x)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 18, 0 },

  { 10, "ctrl_dp_basic/y", 0, "", offsetof(B_ctrl_DP_basic_T, y)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 20, 0 },

  { 11, "ctrl_dp_basic/psi", 0, "", offsetof(B_ctrl_DP_basic_T, psi)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 22, 0 },

  { 12, "ctrl_dp_basic/Input/reset", 0, "", offsetof(B_ctrl_DP_basic_T, reset)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 24, 0 },

  { 13, "ctrl_dp_basic/Input/Guidance gains/w_d_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, w_d_x)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 26, 0 },

  { 14, "ctrl_dp_basic/Input/Guidance gains/w_d_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, w_d_y)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 28, 0 },

  { 15, "ctrl_dp_basic/Input/Guidance gains/w_d_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, w_d_psi)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 30, 0 },

  { 16, "ctrl_dp_basic/Input/Guidance gains/zeta_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, zeta_psi)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 32, 0
  },

  { 17, "ctrl_dp_basic/Input/Guidance gains/zeta_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, zeta_x)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 34, 0 },

  { 18, "ctrl_dp_basic/Input/Guidance gains/zeta_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, zeta_y)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 36, 0 },

  { 19, "ctrl_dp_basic/Input/psi_ref", 0, "", offsetof(B_ctrl_DP_basic_T,
    psi_ref)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 38, 0 },

  { 20, "ctrl_dp_basic/Input/x_ref", 0, "", offsetof(B_ctrl_DP_basic_T, x_ref)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 40, 0 },

  { 21, "ctrl_dp_basic/Input/y_ref", 0, "", offsetof(B_ctrl_DP_basic_T, y_ref)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 42, 0 },

  { 22, "ctrl_dp_basic/Guidance/Reference model/Integrator1", 0, "(1,1)",
    offsetof(B_ctrl_DP_basic_T, Integrator1)+0*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 44, 0 },

  { 23, "ctrl_dp_basic/Guidance/Reference model/Integrator1", 0, "(1,2)",
    offsetof(B_ctrl_DP_basic_T, Integrator1)+1*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 46, 0 },

  { 24, "ctrl_dp_basic/Guidance/Reference model/Integrator1", 0, "(1,3)",
    offsetof(B_ctrl_DP_basic_T, Integrator1)+2*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 48, 0 },

  { 25, "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Sum", 0,
    "", offsetof(B_ctrl_DP_basic_T, Sum)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    50, 0 },

  { 26, "ctrl_dp_basic/Control/DP Controller/Sum2", 0, "regulation error(1,1)",
    offsetof(B_ctrl_DP_basic_T, regulationerror)+0*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 52, 0 },

  { 27, "ctrl_dp_basic/Control/DP Controller/Sum2", 0, "regulation error(1,2)",
    offsetof(B_ctrl_DP_basic_T, regulationerror)+1*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 54, 0 },

  { 28, "ctrl_dp_basic/Control/DP Controller/Sum2", 0, "regulation error(1,3)",
    offsetof(B_ctrl_DP_basic_T, regulationerror)+2*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 56, 0 },

  { 29, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator1", 0, "(1,1)",
    offsetof(B_ctrl_DP_basic_T, Integrator1_g)+0*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 58, 0 },

  { 30, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator1", 0, "(1,2)",
    offsetof(B_ctrl_DP_basic_T, Integrator1_g)+1*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 60, 0 },

  { 31, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator1", 0, "(1,3)",
    offsetof(B_ctrl_DP_basic_T, Integrator1_g)+2*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 62, 0 },

  { 32, "ctrl_dp_basic/Guidance/Reference model/Integrator3", 0, "(1,1)",
    offsetof(B_ctrl_DP_basic_T, Integrator3)+0*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 64, 0 },

  { 33, "ctrl_dp_basic/Guidance/Reference model/Integrator3", 0, "(1,2)",
    offsetof(B_ctrl_DP_basic_T, Integrator3)+1*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 66, 0 },

  { 34, "ctrl_dp_basic/Guidance/Reference model/Integrator3", 0, "(1,3)",
    offsetof(B_ctrl_DP_basic_T, Integrator3)+2*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 68, 0 },

  { 35, "ctrl_dp_basic/Control/DP Controller/Sum4", 0, "(1,1)", offsetof
    (B_ctrl_DP_basic_T, Sum4)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 70, 0 },

  { 36, "ctrl_dp_basic/Control/DP Controller/Sum4", 0, "(1,2)", offsetof
    (B_ctrl_DP_basic_T, Sum4)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 72, 0 },

  { 37, "ctrl_dp_basic/Control/DP Controller/Sum4", 0, "(1,3)", offsetof
    (B_ctrl_DP_basic_T, Sum4)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 74, 0 },

  { 38, "ctrl_dp_basic/Control/DP Controller/Sum3", 0, "(1,1)", offsetof
    (B_ctrl_DP_basic_T, Sum3)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 76, 0 },

  { 39, "ctrl_dp_basic/Control/DP Controller/Sum3", 0, "(1,2)", offsetof
    (B_ctrl_DP_basic_T, Sum3)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 78, 0 },

  { 40, "ctrl_dp_basic/Control/DP Controller/Sum3", 0, "(1,3)", offsetof
    (B_ctrl_DP_basic_T, Sum3)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 80, 0 },

  { 41, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator", 0, "(1,1)",
    offsetof(B_ctrl_DP_basic_T, Integrator)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 82, 0 },

  { 42, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator", 0, "(1,2)",
    offsetof(B_ctrl_DP_basic_T, Integrator)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 84, 0 },

  { 43, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator", 0, "(1,3)",
    offsetof(B_ctrl_DP_basic_T, Integrator)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 86, 0 },

  { 44, "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Sum",
    0, "", offsetof(B_ctrl_DP_basic_T, Sum_f)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 88, 0 },

  { 45, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator2", 0, "(1,1)",
    offsetof(B_ctrl_DP_basic_T, Integrator2)+0*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 90, 0 },

  { 46, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator2", 0, "(1,2)",
    offsetof(B_ctrl_DP_basic_T, Integrator2)+1*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 92, 0 },

  { 47, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator2", 0, "(1,3)",
    offsetof(B_ctrl_DP_basic_T, Integrator2)+2*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 94, 0 },

  { 48, "ctrl_dp_basic/Nonlinear Passisve Observer/M^-1", 0, "(1,1)", offsetof
    (B_ctrl_DP_basic_T, M1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 96, 0 },

  { 49, "ctrl_dp_basic/Nonlinear Passisve Observer/M^-1", 0, "(1,2)", offsetof
    (B_ctrl_DP_basic_T, M1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 98, 0 },

  { 50, "ctrl_dp_basic/Nonlinear Passisve Observer/M^-1", 0, "(1,3)", offsetof
    (B_ctrl_DP_basic_T, M1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 100, 0 },

  { 51, "ctrl_dp_basic/Guidance/Reference model/Matrix Multiply", 0, "(1,1)",
    offsetof(B_ctrl_DP_basic_T, MatrixMultiply)+0*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 102, 0 },

  { 52, "ctrl_dp_basic/Guidance/Reference model/Matrix Multiply", 0, "(1,2)",
    offsetof(B_ctrl_DP_basic_T, MatrixMultiply)+1*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 104, 0 },

  { 53, "ctrl_dp_basic/Guidance/Reference model/Matrix Multiply", 0, "(1,3)",
    offsetof(B_ctrl_DP_basic_T, MatrixMultiply)+2*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 106, 0 },

  { 54, "ctrl_dp_basic/Guidance/Reference model/Sum5", 0, "(1,1)", offsetof
    (B_ctrl_DP_basic_T, Sum5)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 108, 0 },

  { 55, "ctrl_dp_basic/Guidance/Reference model/Sum5", 0, "(1,2)", offsetof
    (B_ctrl_DP_basic_T, Sum5)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 110, 0 },

  { 56, "ctrl_dp_basic/Guidance/Reference model/Sum5", 0, "(1,3)", offsetof
    (B_ctrl_DP_basic_T, Sum5)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 112, 0 },

  { 57, "ctrl_dp_basic/Nonlinear Passisve Observer/Matrix Multiply1", 0, "(1,1)",
    offsetof(B_ctrl_DP_basic_T, MatrixMultiply1)+0*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 114, 0 },

  { 58, "ctrl_dp_basic/Nonlinear Passisve Observer/Matrix Multiply1", 0, "(1,2)",
    offsetof(B_ctrl_DP_basic_T, MatrixMultiply1)+1*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 116, 0 },

  { 59, "ctrl_dp_basic/Nonlinear Passisve Observer/Matrix Multiply1", 0, "(1,3)",
    offsetof(B_ctrl_DP_basic_T, MatrixMultiply1)+2*sizeof(real_T), BLOCKIO_SIG,
    17, 1, 2, 118, 0 },

  { 60, "ctrl_dp_basic/Nonlinear Passisve Observer/Sum1", 0, "(1,1)", offsetof
    (B_ctrl_DP_basic_T, Sum1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 120, 0 },

  { 61, "ctrl_dp_basic/Nonlinear Passisve Observer/Sum1", 0, "(1,2)", offsetof
    (B_ctrl_DP_basic_T, Sum1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 122, 0 },

  { 62, "ctrl_dp_basic/Nonlinear Passisve Observer/Sum1", 0, "(1,3)", offsetof
    (B_ctrl_DP_basic_T, Sum1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 124, 0 },

  { 63, "ctrl_dp_basic/Guidance output/Transposed rotation  matrix in yaw2/Row3",
    0, "", offsetof(B_ctrl_DP_basic_T, Row3)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 126, 0 },

  { 64, "ctrl_dp_basic/Guidance output/Transposed rotation  matrix in yaw2/Row1",
    0, "", offsetof(B_ctrl_DP_basic_T, Row1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 128, 0 },

  { 65, "ctrl_dp_basic/Guidance output/Transposed rotation  matrix in yaw2/Row2",
    0, "", offsetof(B_ctrl_DP_basic_T, Row2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 130, 0 },

  { 66, "ctrl_dp_basic/Thrust allocation", 0, "u_BT", offsetof(B_ctrl_DP_basic_T,
    u_BT)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 132, 0 },

  { 67, "ctrl_dp_basic/Thrust allocation", 1, "u_VSP", offsetof
    (B_ctrl_DP_basic_T, u_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 134, 0 },

  { 68, "ctrl_dp_basic/Thrust allocation", 2, "alpha_VSP", offsetof
    (B_ctrl_DP_basic_T, alpha_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 136,
    0 },

  { 69, "ctrl_dp_basic/Thrust allocation", 3, "omega_VSP", offsetof
    (B_ctrl_DP_basic_T, omega_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 138,
    0 },

  { 70, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "K_d(1,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 140, 0 },

  { 71, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "K_d(2,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 142, 0 },

  { 72, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "K_d(3,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 144, 0 },

  { 73, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "K_d(1,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d)+3*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 146, 0 },

  { 74, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "K_d(2,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d)+4*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 148, 0 },

  { 75, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "K_d(3,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d)+5*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 150, 0 },

  { 76, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "K_d(1,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d)+6*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 152, 0 },

  { 77, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "K_d(2,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d)+7*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 154, 0 },

  { 78, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "K_d(3,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d)+8*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 156, 0 },

  { 79, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "K_i(1,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 158, 0 },

  { 80, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "K_i(2,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 160, 0 },

  { 81, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "K_i(3,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 162, 0 },

  { 82, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "K_i(1,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i)+3*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 164, 0 },

  { 83, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "K_i(2,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i)+4*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 166, 0 },

  { 84, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "K_i(3,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i)+5*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 168, 0 },

  { 85, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "K_i(1,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i)+6*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 170, 0 },

  { 86, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "K_i(2,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i)+7*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 172, 0 },

  { 87, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "K_i(3,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i)+8*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 174, 0 },

  { 88, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "K_p(1,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 176, 0 },

  { 89, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "K_p(2,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 178, 0 },

  { 90, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "K_p(3,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 180, 0 },

  { 91, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "K_p(1,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p)+3*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 182, 0 },

  { 92, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "K_p(2,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p)+4*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 184, 0 },

  { 93, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "K_p(3,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p)+5*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 186, 0 },

  { 94, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "K_p(1,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p)+6*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 188, 0 },

  { 95, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "K_p(2,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p)+7*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 190, 0 },

  { 96, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "K_p(3,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p)+8*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 192, 0 },

  { 97, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "K_d(1,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 194, 0 },

  { 98, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "K_d(2,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 196, 0 },

  { 99, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "K_d(3,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 198, 0 },

  { 100, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "K_d(1,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d)+3*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 200, 0 },

  { 101, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "K_d(2,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d)+4*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 202, 0 },

  { 102, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "K_d(3,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d)+5*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 204, 0 },

  { 103, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "K_d(1,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d)+6*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 206, 0 },

  { 104, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "K_d(2,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d)+7*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 208, 0 },

  { 105, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "K_d(3,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d)+8*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 210, 0 },

  { 106, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "K_i(1,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 212, 0 },

  { 107, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "K_i(2,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 214, 0 },

  { 108, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "K_i(3,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 216, 0 },

  { 109, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "K_i(1,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i)+3*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 218, 0 },

  { 110, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "K_i(2,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i)+4*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 220, 0 },

  { 111, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "K_i(3,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i)+5*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 222, 0 },

  { 112, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "K_i(1,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i)+6*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 224, 0 },

  { 113, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "K_i(2,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i)+7*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 226, 0 },

  { 114, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "K_i(3,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i)+8*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 228, 0 },

  { 115, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "K_p(1,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 230, 0 },

  { 116, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "K_p(2,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 232, 0 },

  { 117, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "K_p(3,1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 234, 0 },

  { 118, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "K_p(1,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p)+3*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 236, 0 },

  { 119, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "K_p(2,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p)+4*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 238, 0 },

  { 120, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "K_p(3,2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p)+5*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 240, 0 },

  { 121, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "K_p(1,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p)+6*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 242, 0 },

  { 122, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "K_p(2,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p)+7*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 244, 0 },

  { 123, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "K_p(3,3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p)+8*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 246, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 124;
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
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 56;
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

  { 9, "x", 0, EXT_IN, 1, 1, 1 },

  { 10, "y", 0, EXT_IN, 1, 1, 1 },

  { 11, "psi", 0, EXT_IN, 1, 1, 1 },

  { 12, "Input/reset", 0, EXT_IN, 1, 1, 1 },

  { 13, "Input/Guidance gains/w_d_x", 0, EXT_IN, 1, 1, 1 },

  { 14, "Input/Guidance gains/w_d_y", 0, EXT_IN, 1, 1, 1 },

  { 15, "Input/Guidance gains/w_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 16, "Input/Guidance gains/zeta_psi", 0, EXT_IN, 1, 1, 1 },

  { 17, "Input/Guidance gains/zeta_x", 0, EXT_IN, 1, 1, 1 },

  { 18, "Input/Guidance gains/zeta_y", 0, EXT_IN, 1, 1, 1 },

  { 19, "Input/psi_ref", 0, EXT_IN, 1, 1, 1 },

  { 20, "Input/x_ref", 0, EXT_IN, 1, 1, 1 },

  { 21, "Input/y_ref", 0, EXT_IN, 1, 1, 1 },

  { 0, "alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 1, "omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 2, "omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 3, "alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 4, "u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 5, "u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 6, "Observer output /eta_hat output/x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 7, "Observer output /eta_hat output/y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 8, "Observer output /eta_hat output/psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 9, "Observer output /nu_hat output/u_hat", 0, EXT_OUT, 1, 1, 1 },

  { 10, "Observer output /nu_hat output/v_hat", 0, EXT_OUT, 1, 1, 1 },

  { 11, "Observer output /nu_hat output/r_hat", 0, EXT_OUT, 1, 1, 1 },

  { 12, "Observer output /nu_dot_hat output/u_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 13, "Observer output /nu_dot_hat output/v_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 14, "Observer output /nu_dot_hat output/r_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 15, "Observer output /b_hat output/b_x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 16, "Observer output /b_hat output/b_y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 17, "Observer output /b_hat output/b_psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 18, "u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 19, "Control output/tau_N", 0, EXT_OUT, 1, 1, 1 },

  { 20, "Control output/tau_X", 0, EXT_OUT, 1, 1, 1 },

  { 21, "Control output/tau_Y", 0, EXT_OUT, 1, 1, 1 },

  { 22, "Control output/psi_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 23, "Control output/x_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 24, "Control output/y_tidle", 0, EXT_OUT, 1, 1, 1 },

  { 25, "Control output/r_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 26, "Control output/u_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 27, "Control output/v_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 28, "Guidance output/x_d", 0, EXT_OUT, 1, 1, 1 },

  { 29, "Guidance output/y_d", 0, EXT_OUT, 1, 1, 1 },

  { 30, "Guidance output/psi_d", 0, EXT_OUT, 1, 1, 1 },

  { 31, "Guidance output/r_d", 0, EXT_OUT, 1, 1, 1 },

  { 32, "Guidance output/u_d", 0, EXT_OUT, 1, 1, 1 },

  { 33, "Guidance output/v_d", 0, EXT_OUT, 1, 1, 1 },

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
  "ctrl_dp_basic";
static char* NI_CompiledModelVersion = "1.39";
static char* NI_CompiledModelDateTime = "Tue Mar 17 11:25:18 2015";
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
   The undef allows us to access the real ctrl_DP_basic_P
   In the rest of the code ctrl_DP_basic_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_DP_basic_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_DP_basic_P, sizeof(P_ctrl_DP_basic_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_DP_basic_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_DP_basic_T));
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
             (P_ctrl_DP_basic_T));
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
               (P_ctrl_DP_basic_T));

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
           (P_ctrl_DP_basic_T));
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
           (P_ctrl_DP_basic_T));
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
           (P_ctrl_DP_basic_T));
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
      *numContStates = 21;
      *numDiscStates = 914;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator1_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator1_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator1_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator1_CSTATE_g[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator1_CSTATE_g[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator1_CSTATE_g[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator3_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator3_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator3_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator_CSTATE_l[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator_CSTATE_l[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator_CSTATE_l[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator2_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator2_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator2_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator2_CSTATE_e[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator2_CSTATE_e[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_X.Integrator2_CSTATE_e[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_e");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.zeta_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.zeta_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.zeta_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.zeta_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.zeta_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.zeta_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_ref_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_ref_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_ref_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.alpha_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.omega_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.omega_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.alpha_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_BT_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_VSP1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_dot_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_dot_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_dot_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.b_x_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.b_x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.b_y_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.b_y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.b_psi_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.b_psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_VSP2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_N_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_N_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_X_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_Y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_Y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_tilde_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_tilde_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_tidle_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_tidle_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_tilde_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_tilde_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_tilde_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading");
    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_x_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_x_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_x_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_x_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.zeta_psi_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.zeta_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.zeta_x_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.zeta_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.zeta_y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.zeta_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_ref_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_ref_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_ref_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_ref_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_ref_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_ref_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.alpha_VSP2_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.omega_VSP1_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.omega_VSP2_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.alpha_VSP1_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_BT_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_VSP1_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.u_dot_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.u_dot_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.v_dot_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.v_dot_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.r_dot_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.r_dot_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.b_x_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.b_x_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.b_y_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.b_y_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.b_psi_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.b_psi_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_VSP2_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_N_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_N_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_X_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_X_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_Y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_Y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.psi_tilde_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.psi_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_tilde_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_tidle_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_tidle_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_tilde_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_tilde_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_tilde_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.NIVeriStandSignalProbe_DWORK1, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 57; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.NIVeriStandSignalProbe_DWORK3, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.NIVeriStandSignalProbe_DWORK3");
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
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator1_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator1_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator1_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator1_CSTATE_g[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator1_CSTATE_g[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator1_CSTATE_g[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator3_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator3_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator3_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator_CSTATE_l[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator_CSTATE_l[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator_CSTATE_l[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator2_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator2_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator2_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator2_CSTATE_e[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator2_CSTATE_e[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_X.Integrator2_CSTATE_e[0], 2,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_psi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_psi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_psi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_psi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_psi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_ref_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_ref_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_ref_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.omega_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.omega_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_BT_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_VSP1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_dot_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_dot_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_dot_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_x_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_y_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_psi_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_VSP2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_N_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_X_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_Y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_tilde_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_tilde_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_tidle_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_tilde_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_tilde_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_tilde_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.NIVeriStandSignalProbe_DWORK2, 0,
      discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading,
      0, discStates[idx++], 10, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading, 0,
      discStates[idx++], 10, 0);
    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_x_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_psi_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_psi_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_x_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_psi_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_x_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_x_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_psi_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_psi_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_x_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_ref_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_ref_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_ref_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_BT_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_dot_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_dot_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_dot_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_x_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_y_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_psi_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_N_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_X_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_Y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_tilde_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_tilde_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_tidle_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_tilde_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_tilde_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_tilde_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.NIVeriStandSignalProbe_DWORK1,
        count, discStates[idx++], 20, 0);
    }

    for (count = 0; count < 57; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.NIVeriStandSignalProbe_DWORK3,
        count, discStates[idx++], 21, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_DP_basic
