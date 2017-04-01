/*
 * ctrl_student_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.258
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sat Apr 01 15:41:16 2017
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
  int_T nXc = 11;
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
 *    '<S19>/MATLAB Function1'
 *    '<S20>/R Transposed'
 */
void ctrl_student_HI_MATLABFunction1(const real_T rtu_R[9],
  B_MATLABFunction1_ctrl_studen_T *localB)
{
  int32_T i;

  /* MATLAB Function 'ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1': '<S23>:1' */
  /* '<S23>:1:3' */
  for (i = 0; i < 3; i++) {
    localB->R_T[3 * i] = rtu_R[i];
    localB->R_T[1 + 3 * i] = rtu_R[i + 3];
    localB->R_T[2 + 3 * i] = rtu_R[i + 6];
  }
}

/*
 * Output and update for atomic system:
 *    '<S36>/MATLAB Function1'
 *    '<S43>/MATLAB Function1'
 */
void ctrl_student__MATLABFunction1_m(real_T rtu_SwitchSignal_In,
  B_MATLABFunction1_ctrl_stud_k_T *localB)
{
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/MATLAB Function1': '<S40>:1' */
  if (rtu_SwitchSignal_In == 0.0) {
    /* '<S40>:1:3' */
    /* '<S40>:1:4' */
    localB->SwitchSignal_Out = 1.0;
  } else {
    /* '<S40>:1:6' */
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

/* Model output function */
void ctrl_student_HIL_output(void)
{
  /* local block i/o variables */
  real_T rtb_R_g[9];
  real_T rtb_R_c[9];
  real_T rtb_Memory;
  real_T rtb_Memory_b;
  real_T x_dss;
  real_T y_dss;
  real_T S_T[9];
  real_T y[9];
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  real_T rtb_Switch[3];
  real_T rtb_Switch5;
  real_T rtb_U_ss;
  real_T rtb_Product2_o[9];
  real_T rtb_M[9];
  int32_T i;
  static const real_T tmp[9] = { 16.79, 0.0, 0.0, 0.0, 24.79,
    0.55462499999999992, 0.0, 0.55462499999999992, 2.76 };

  real_T tmp_0[3];
  real_T S_T_0[3];
  real_T rtb_Product2_i[3];
  real_T tmp_1[3];
  real_T S_T_1[3];
  real_T tmp_2[9];
  real_T tmp_3[9];
  real_T rtb_DesPosOut;
  real_T rtb_eta_dss_idx_1;
  real_T rtb_eta_dss_idx_0;
  real_T rtb_pd_s_idx_0;
  real_T rtb_pd_s_idx_1;
  real_T rtb_eta_ds_idx_2;
  real_T rtb_eta_dss_idx_2;
  real_T rtb_DesPosOut_idx_0;
  real_T rtb_DesPosOut_idx_1;
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

  /* Integrator: '<S55>/etaHat' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.etaHat_Reset_ZCE,
                       ctrl_student_HIL_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.etaHat_CSTATE[0] = (ctrl_student_HIL_P.etaHat_IC[0]);
      ctrl_student_HIL_X.etaHat_CSTATE[1] = (ctrl_student_HIL_P.etaHat_IC[1]);
      ctrl_student_HIL_X.etaHat_CSTATE[2] = (ctrl_student_HIL_P.etaHat_IC[2]);
    }
  }

  ctrl_student_HIL_B.etaHat[0] = ctrl_student_HIL_X.etaHat_CSTATE[0];
  ctrl_student_HIL_B.etaHat[1] = ctrl_student_HIL_X.etaHat_CSTATE[1];
  ctrl_student_HIL_B.etaHat[2] = ctrl_student_HIL_X.etaHat_CSTATE[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Sum: '<Root>/Sum1' */
  ctrl_student_HIL_B.Sum1[0] = ctrl_student_HIL_B.x_in -
    ctrl_student_HIL_B.etaHat[0];
  ctrl_student_HIL_B.Sum1[1] = ctrl_student_HIL_B.y_in -
    ctrl_student_HIL_B.etaHat[1];
  ctrl_student_HIL_B.Sum1[2] = ctrl_student_HIL_B.psi_in -
    ctrl_student_HIL_B.etaHat[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* MATLAB Function: '<S63>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<S7>/Step size'
     *  Memory: '<S63>/counter'
     */
    /* MATLAB Function 'Noise generator/Downsample	signal/MATLAB Function': '<S66>:1' */
    /* '<S66>:1:3' */
    if ((ctrl_student_HIL_DW.counter_PreviousInput + 1.0) *
        ctrl_student_HIL_P.Stepsize_Value >= 1.0 /
        ctrl_student_HIL_P.Constant_Value) {
      /* '<S66>:1:4' */
      /* '<S66>:1:5' */
      ctrl_student_HIL_B.count = 0.0;
    } else {
      /* '<S66>:1:7' */
      ctrl_student_HIL_B.count = ctrl_student_HIL_DW.counter_PreviousInput + 1.0;
    }

    /* End of MATLAB Function: '<S63>/MATLAB Function' */
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S69>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise = ctrl_student_HIL_DW.NextOutput;

    /* RandomNumber: '<S70>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_e = ctrl_student_HIL_DW.NextOutput_c;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S68>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_m = ctrl_student_HIL_DW.NextOutput_p;

    /* Memory: '<S64>/Hold' */
    ctrl_student_HIL_B.Hold[0] = ctrl_student_HIL_DW.Hold_PreviousInput[0];
    ctrl_student_HIL_B.Hold[1] = ctrl_student_HIL_DW.Hold_PreviousInput[1];
    ctrl_student_HIL_B.Hold[2] = ctrl_student_HIL_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S64>/MATLAB Function1' incorporates:
   *  Constant: '<S7>/Step size'
   *  Product: '<S68>/Divide'
   *  Product: '<S68>/Product'
   *  Product: '<S69>/Divide'
   *  Product: '<S69>/Product'
   *  Product: '<S70>/Divide'
   *  Product: '<S70>/Product'
   *  Sqrt: '<S68>/Sqrt'
   *  Sqrt: '<S69>/Sqrt'
   *  Sqrt: '<S70>/Sqrt'
   *  Sum: '<S7>/Sum'
   */
  /* MATLAB Function 'Noise generator/Sample & hold/MATLAB Function1': '<S67>:1' */
  if (ctrl_student_HIL_B.count == 0.0) {
    /* '<S67>:1:4' */
    /* '<S67>:1:5' */
    ctrl_student_HIL_B.output[0] = sqrt(ctrl_student_HIL_B.NoisePowPos /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise +
      ctrl_student_HIL_B.x_in;
    ctrl_student_HIL_B.output[1] = sqrt(ctrl_student_HIL_B.NoisePowPos /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise_e +
      ctrl_student_HIL_B.y_in;
    ctrl_student_HIL_B.output[2] = sqrt(ctrl_student_HIL_B.NoisePowHead /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise_m +
      ctrl_student_HIL_B.psi_in;
  } else {
    /* '<S67>:1:7' */
    ctrl_student_HIL_B.output[0] = ctrl_student_HIL_B.Hold[0];
    ctrl_student_HIL_B.output[1] = ctrl_student_HIL_B.Hold[1];
    ctrl_student_HIL_B.output[2] = ctrl_student_HIL_B.Hold[2];
  }

  /* End of MATLAB Function: '<S64>/MATLAB Function1' */

  /* Switch: '<S7>/Switch' */
  if (ctrl_student_HIL_B.NoiseEnable != 0.0) {
    rtb_Switch[0] = ctrl_student_HIL_B.output[0];
    rtb_Switch[1] = ctrl_student_HIL_B.output[1];
    rtb_Switch[2] = ctrl_student_HIL_B.output[2];
  } else {
    rtb_Switch[0] = ctrl_student_HIL_B.x_in;
    rtb_Switch[1] = ctrl_student_HIL_B.y_in;
    rtb_Switch[2] = ctrl_student_HIL_B.psi_in;
  }

  /* End of Switch: '<S7>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S6>/Memory2' */
    ctrl_student_HIL_B.Memory2 = ctrl_student_HIL_DW.Memory2_PreviousInput;

    /* Memory: '<S6>/Memory1' */
    ctrl_student_HIL_B.Memory1 = ctrl_student_HIL_DW.Memory1_PreviousInput;

    /* Memory: '<S6>/Memory' */
    ctrl_student_HIL_B.Memory = ctrl_student_HIL_DW.Memory_PreviousInput;
  }

  /* MATLAB Function: '<S6>/MATLAB Function' */
  /* MATLAB Function 'Dropout_simulator/MATLAB Function': '<S62>:1' */
  /* '<S62>:1:2' */
  ctrl_student_HIL_B.X_out = -1.0;

  /* '<S62>:1:3' */
  ctrl_student_HIL_B.Y_out = -1.0;

  /* '<S62>:1:4' */
  ctrl_student_HIL_B.Yaw_out = -1.0;
  switch ((int32_T)ctrl_student_HIL_B.Dropout_signaINl) {
   case 0:
    /* '<S62>:1:9' */
    ctrl_student_HIL_B.X_out = rtb_Switch[0];

    /* '<S62>:1:10' */
    ctrl_student_HIL_B.Y_out = rtb_Switch[1];

    /* '<S62>:1:11' */
    ctrl_student_HIL_B.Yaw_out = rtb_Switch[2];
    break;

   case 1:
    /* '<S62>:1:14' */
    ctrl_student_HIL_B.X_out = ctrl_student_HIL_B.Memory2;

    /* '<S62>:1:15' */
    ctrl_student_HIL_B.Y_out = ctrl_student_HIL_B.Memory1;

    /* '<S62>:1:16' */
    ctrl_student_HIL_B.Yaw_out = ctrl_student_HIL_B.Memory;
    break;
  }

  /* End of MATLAB Function: '<S6>/MATLAB Function' */

  /* SignalConversion: '<Root>/TmpSignal ConversionAteta_noiseInport1' */
  ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI[0] =
    ctrl_student_HIL_B.X_out;
  ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI[1] =
    ctrl_student_HIL_B.Y_out;
  ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI[2] =
    ctrl_student_HIL_B.Yaw_out;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Product: '<S2>/Product2' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  for (i = 0; i < 9; i++) {
    rtb_Product2_o[i] = ctrl_student_HIL_B.ControllerGainK2 *
      ctrl_student_HIL_P.K2[i];
  }

  /* End of Product: '<S2>/Product2' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Gain: '<S21>/Gain' incorporates:
     *  Constant: '<S21>/Kp '
     */
    for (i = 0; i < 9; i++) {
      ctrl_student_HIL_B.Gain[i] = ctrl_student_HIL_P.Gain_Gain *
        ctrl_student_HIL_P.K1[i];
    }

    /* End of Gain: '<S21>/Gain' */
  }

  /* MATLAB Function: '<S20>/Rotation Matrix' */
  /* MATLAB Function 'ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Rotation Matrix': '<S26>:1' */
  /* '<S26>:1:3' */
  rtb_R_g[0] = cos(ctrl_student_HIL_B.etaHat[2]);
  rtb_R_g[3] = -sin(ctrl_student_HIL_B.etaHat[2]);
  rtb_R_g[6] = 0.0;
  rtb_R_g[1] = sin(ctrl_student_HIL_B.etaHat[2]);
  rtb_R_g[4] = cos(ctrl_student_HIL_B.etaHat[2]);
  rtb_R_g[7] = 0.0;
  rtb_R_g[2] = 0.0;
  rtb_R_g[5] = 0.0;
  rtb_R_g[8] = 1.0;

  /* MATLAB Function: '<S20>/R Transposed' */
  ctrl_student_HI_MATLABFunction1(rtb_R_g, &ctrl_student_HIL_B.sf_RTransposed);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S32>/Memory' */
    rtb_Memory = ctrl_student_HIL_DW.Memory_PreviousInput_f;

    /* MATLAB Function: '<S36>/MATLAB Function1' */
    ctrl_student__MATLABFunction1_m(rtb_Memory,
      &ctrl_student_HIL_B.sf_MATLABFunction1_m);
  }

  /* Integrator: '<S36>/Integrator' */
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

  /* MATLAB Function: '<S34>/CheckS&getU' */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Check_s/CheckS&getU': '<S37>:1' */
  if (ctrl_student_HIL_B.Integrator >= 1.0) {
    /* '<S37>:1:3' */
    /* '<S37>:1:4' */
    ctrl_student_HIL_B.s_out_j = 0.0;

    /* '<S37>:1:5' */
    ctrl_student_HIL_B.Switch_d = 0.0;
  } else {
    /* '<S37>:1:7' */
    ctrl_student_HIL_B.s_out_j = ctrl_student_HIL_B.Integrator;

    /* '<S37>:1:8' */
    ctrl_student_HIL_B.Switch_d = 1.0;
  }

  /* InitialCondition: '<S32>/IC' incorporates:
   *  Constant: '<S34>/Constant'
   *  MATLAB Function: '<S34>/CheckS&getU'
   */
  /* '<S37>:1:11' */
  /* U scaled again for the ellipsoidal case */
  if ((ctrl_student_HIL_DW.IC_FirstOutputTime == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC_FirstOutputTime == ctrl_student_HIL_M->Timing.t[0]))
  {
    ctrl_student_HIL_DW.IC_FirstOutputTime = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC = ctrl_student_HIL_P.IC_Value;
  } else {
    ctrl_student_HIL_B.IC = ctrl_student_HIL_P.U_ref / 2.0;
  }

  /* End of InitialCondition: '<S32>/IC' */

  /* MATLAB Function: '<S38>/MATLAB Function' incorporates:
   *  Constant: '<S35>/Elipscenter_radi'
   */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization /Subsystem/MATLAB Function': '<S39>:1' */
  /* '<S39>:1:2' */
  ctrl_student_HIL_B.pd[0] = 0.0;
  ctrl_student_HIL_B.pd[1] = 0.0;

  /* '<S39>:1:4' */
  /* '<S39>:1:5' */
  /* '<S39>:1:7' */
  ctrl_student_HIL_B.pd[0] = cos(6.2831853071795862 * ctrl_student_HIL_B.s_out_j)
    * ctrl_student_HIL_P.Elipscenter_radi[2] +
    ctrl_student_HIL_P.Elipscenter_radi[0];

  /* '<S39>:1:8' */
  ctrl_student_HIL_B.pd[1] = sin(6.2831853071795862 * ctrl_student_HIL_B.s_out_j)
    * ctrl_student_HIL_P.Elipscenter_radi[3] +
    ctrl_student_HIL_P.Elipscenter_radi[1];

  /* '<S39>:1:10' */
  rtb_pd_s_idx_0 = -6.2831853071795862 * ctrl_student_HIL_P.Elipscenter_radi[2] *
    sin(6.2831853071795862 * ctrl_student_HIL_B.s_out_j);

  /* '<S39>:1:11' */
  rtb_pd_s_idx_1 = 6.2831853071795862 * ctrl_student_HIL_P.Elipscenter_radi[3] *
    cos(6.2831853071795862 * ctrl_student_HIL_B.s_out_j);

  /* '<S39>:1:13' */
  /* '<S39>:1:14' */
  /* '<S39>:1:15' */
  x_dss = -39.478417604357432 * ctrl_student_HIL_P.Elipscenter_radi[2] * cos
    (6.2831853071795862 * ctrl_student_HIL_B.s_out_j);

  /* '<S39>:1:16' */
  y_dss = -39.478417604357432 * ctrl_student_HIL_P.Elipscenter_radi[3] * sin
    (6.2831853071795862 * ctrl_student_HIL_B.s_out_j);

  /* '<S39>:1:17' */
  /* '<S39>:1:18' */
  /* '<S39>:1:19' */
  rtb_eta_ds_idx_2 = (rtb_pd_s_idx_0 * y_dss - x_dss * rtb_pd_s_idx_1) /
    (rtb_pd_s_idx_0 * rtb_pd_s_idx_0 + rtb_pd_s_idx_1 * rtb_pd_s_idx_1);

  /* '<S39>:1:20' */
  rtb_eta_dss_idx_0 = x_dss;

  /* '<S39>:1:21' */
  rtb_eta_dss_idx_1 = y_dss;

  /* '<S39>:1:23' */
  /* '<S39>:1:24' */
  /* '<S39>:1:25' */
  /* '<S39>:1:26' */
  rtb_Switch5 = rtb_pd_s_idx_0 * rtb_pd_s_idx_0 + rtb_pd_s_idx_1 *
    rtb_pd_s_idx_1;

  /* '<S39>:1:27' */
  rtb_eta_dss_idx_2 = (-248.05021344239853 *
                       ctrl_student_HIL_P.Elipscenter_radi[3] * cos
                       (6.2831853071795862 * ctrl_student_HIL_B.s_out_j) *
                       rtb_pd_s_idx_0 - 248.05021344239853 *
                       ctrl_student_HIL_P.Elipscenter_radi[2] * sin
                       (6.2831853071795862 * ctrl_student_HIL_B.s_out_j) *
                       rtb_pd_s_idx_1) / (rtb_pd_s_idx_0 * rtb_pd_s_idx_0 +
    rtb_pd_s_idx_1 * rtb_pd_s_idx_1) + -((2.0 * rtb_pd_s_idx_0 * x_dss + 2.0 *
    rtb_pd_s_idx_1 * y_dss) * (rtb_pd_s_idx_0 * y_dss - rtb_pd_s_idx_1 * x_dss))
    / (rtb_Switch5 * rtb_Switch5);

  /* '<S39>:1:28' */
  rtb_U_ss = (-rtb_pd_s_idx_0 * x_dss - rtb_pd_s_idx_1 * y_dss) *
    ctrl_student_HIL_B.IC / rt_powd_snf(rtb_pd_s_idx_0 * rtb_pd_s_idx_0 +
    rtb_pd_s_idx_1 * rtb_pd_s_idx_1, 1.5);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S33>/Memory' */
    rtb_Memory_b = ctrl_student_HIL_DW.Memory_PreviousInput_m;

    /* MATLAB Function: '<S43>/MATLAB Function1' */
    ctrl_student__MATLABFunction1_m(rtb_Memory_b,
      &ctrl_student_HIL_B.sf_MATLABFunction1_p);
  }

  /* Integrator: '<S43>/Integrator' */
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
    /* Memory: '<S45>/Memory' */
    ctrl_student_HIL_B.Memory_o = ctrl_student_HIL_DW.Memory_PreviousInput_p;

    /* Memory: '<S45>/Memory1' */
    ctrl_student_HIL_B.Memory1_m[0] =
      ctrl_student_HIL_DW.Memory1_PreviousInput_p[0];
    ctrl_student_HIL_B.Memory1_m[1] =
      ctrl_student_HIL_DW.Memory1_PreviousInput_p[1];
  }

  /* MATLAB Function: '<S45>/MATLAB Function' incorporates:
   *  Constant: '<S42>/Desired Position'
   *  Constant: '<S45>/Constant'
   *  Constant: '<S45>/Constant1'
   */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function': '<S48>:1' */
  /* '<S48>:1:3' */
  /* '<S48>:1:5' */
  ctrl_student_HIL_B.init_time[0] = ctrl_student_HIL_B.Memory1_m[0] + 1.0;

  /* '<S48>:1:6' */
  ctrl_student_HIL_B.init_time[1] = ctrl_student_HIL_B.Memory1_m[1];
  if (ctrl_student_HIL_B.Memory1_m[0] + 1.0 < ctrl_student_HIL_P.T_initialDP) {
    /* '<S48>:1:11' */
    /*  DP for N_iterations */
    /* '<S48>:1:12' */
    x_dss = ctrl_student_HIL_B.Memory_o;

    /* '<S48>:1:13' */
    i = (int32_T)ctrl_student_HIL_B.Memory_o;
    rtb_InitPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
    rtb_InitPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

    /* '<S48>:1:14' */
    i = (int32_T)(ctrl_student_HIL_B.Memory_o + 1.0);
    rtb_DesPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
    rtb_DesPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

    /* '<S48>:1:15' */
    ctrl_student_HIL_B.SwitchSignal_out = 1.0;

    /* '<S48>:1:16' */
    y_dss = 0.0;

    /* '<S48>:1:17' */
    i = 1;

    /* '<S48>:1:18' */
    ctrl_student_HIL_B.flag = 1.0;
  } else if (ctrl_student_HIL_B.Memory_o == 1.0) {
    /* '<S48>:1:21' */
    /*  if we are at final stretch */
    if (ctrl_student_HIL_B.Integrator_m >= 0.9999) {
      /* '<S48>:1:22' */
      /* '<S48>:1:23' */
      x_dss = ctrl_student_HIL_B.Memory_o;

      /* '<S48>:1:24' */
      i = (int32_T)ctrl_student_HIL_B.Memory_o;
      rtb_InitPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
      rtb_InitPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

      /* '<S48>:1:25' */
      i = (int32_T)(ctrl_student_HIL_B.Memory_o + 1.0);
      rtb_DesPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
      rtb_DesPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

      /* '<S48>:1:26' */
      ctrl_student_HIL_B.SwitchSignal_out = 1.0;

      /* '<S48>:1:27' */
      y_dss = 1.0;

      /* '<S48>:1:28' */
      i = 1;

      /* '<S48>:1:29' */
      ctrl_student_HIL_B.flag = 2.0;
    } else {
      /* '<S48>:1:32' */
      x_dss = ctrl_student_HIL_B.Memory_o;

      /* '<S48>:1:33' */
      i = (int32_T)ctrl_student_HIL_B.Memory_o;
      rtb_InitPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
      rtb_InitPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

      /* '<S48>:1:34' */
      i = (int32_T)(ctrl_student_HIL_B.Memory_o + 1.0);
      rtb_DesPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
      rtb_DesPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

      /* '<S48>:1:35' */
      ctrl_student_HIL_B.SwitchSignal_out = 1.0;

      /* '<S48>:1:36' */
      y_dss = ctrl_student_HIL_B.Integrator_m;

      /* '<S48>:1:37' */
      i = 0;

      /* '<S48>:1:38' */
      ctrl_student_HIL_B.flag = 3.0;
    }
  } else if (ctrl_student_HIL_B.Integrator_m >= 0.9999) {
    /* '<S48>:1:42' */
    if (ctrl_student_HIL_B.Memory_o + 1.0 == 1.0) {
      /* '<S48>:1:43' */
      /* '<S48>:1:44' */
      ctrl_student_HIL_B.SwitchSignal_out = 0.0;

      /* '<S48>:1:45' */
      ctrl_student_HIL_B.flag = 40.0;
    } else {
      /* '<S48>:1:47' */
      ctrl_student_HIL_B.SwitchSignal_out = 0.0;

      /* '<S48>:1:48' */
      ctrl_student_HIL_B.flag = 50.0;
    }

    /* '<S48>:1:50' */
    x_dss = ctrl_student_HIL_B.Memory_o + 1.0;

    /* '<S48>:1:51' */
    i = (int32_T)(ctrl_student_HIL_B.Memory_o + 1.0);
    rtb_InitPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
    rtb_InitPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

    /* '<S48>:1:52' */
    i = (int32_T)((ctrl_student_HIL_B.Memory_o + 1.0) + 1.0);
    rtb_DesPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
    rtb_DesPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

    /* '<S48>:1:53' */
    y_dss = 1.0;

    /* '<S48>:1:54' */
    i = 0;
  } else {
    if (ctrl_student_HIL_B.Memory1_m[1] == 0.0) {
      /* '<S48>:1:57' */
      /* '<S48>:1:58' */
      ctrl_student_HIL_B.init_time[1] = 1.0;

      /* '<S48>:1:59' */
      ctrl_student_HIL_B.SwitchSignal_out = 0.0;

      /* '<S48>:1:60' */
      ctrl_student_HIL_B.flag = 5.75;
    } else {
      /* '<S48>:1:62' */
      ctrl_student_HIL_B.SwitchSignal_out = 1.0;

      /* '<S48>:1:63' */
      ctrl_student_HIL_B.flag = 5.25;
    }

    /* '<S48>:1:65' */
    x_dss = ctrl_student_HIL_B.Memory_o;

    /* '<S48>:1:66' */
    i = (int32_T)ctrl_student_HIL_B.Memory_o;
    rtb_InitPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
    rtb_InitPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

    /* '<S48>:1:67' */
    i = (int32_T)(ctrl_student_HIL_B.Memory_o + 1.0);
    rtb_DesPosOut_idx_0 = ctrl_student_HIL_P.pd[(i - 1) << 1];
    rtb_DesPosOut_idx_1 = ctrl_student_HIL_P.pd[((i - 1) << 1) + 1];

    /* '<S48>:1:68' */
    y_dss = ctrl_student_HIL_B.Integrator_m;

    /* '<S48>:1:69' */
    i = 0;
  }

  if (i == 1) {
    /* '<S48>:1:75' */
    /* '<S48>:1:76' */
    ctrl_student_HIL_B.U = 0.0;
  } else {
    /* '<S48>:1:78' */
    ctrl_student_HIL_B.U = (sin(6.2831853071795862 * y_dss - 1.5707963267948966)
      + 1.01) * ctrl_student_HIL_P.U_ref;
  }

  ctrl_student_HIL_B.N_out = x_dss;
  ctrl_student_HIL_B.s_out = y_dss;

  /* End of MATLAB Function: '<S45>/MATLAB Function' */

  /* Sum: '<S42>/Sum1' */
  rtb_DesPosOut_idx_0 -= rtb_InitPosOut_idx_0;
  rtb_DesPosOut = rtb_DesPosOut_idx_1 - rtb_InitPosOut_idx_1;

  /* Sum: '<S42>/Sum' incorporates:
   *  Product: '<S42>/Product'
   */
  ctrl_student_HIL_B.Sum[0] = rtb_DesPosOut_idx_0 * ctrl_student_HIL_B.s_out +
    rtb_InitPosOut_idx_0;
  ctrl_student_HIL_B.Sum[1] = rtb_DesPosOut * ctrl_student_HIL_B.s_out +
    rtb_InitPosOut_idx_1;

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/SwitchSignalFromFile'
   */
  if (ctrl_student_HIL_P.DesiredPath > ctrl_student_HIL_P.Switch_Threshold) {
    ctrl_student_HIL_B.Switch[0] = ctrl_student_HIL_B.pd[0];
    ctrl_student_HIL_B.Switch[1] = ctrl_student_HIL_B.pd[1];
  } else {
    ctrl_student_HIL_B.Switch[0] = ctrl_student_HIL_B.Sum[0];
    ctrl_student_HIL_B.Switch[1] = ctrl_student_HIL_B.Sum[1];
  }

  /* End of Switch: '<S15>/Switch' */

  /* Sum: '<S20>/Sum' incorporates:
   *  Product: '<S20>/Product'
   */
  rtb_DesPosOut_idx_1 = ctrl_student_HIL_B.etaHat[0] -
    ctrl_student_HIL_B.Switch[0];
  rtb_InitPosOut_idx_0 = ctrl_student_HIL_B.etaHat[1] -
    ctrl_student_HIL_B.Switch[1];
  rtb_InitPosOut_idx_1 = ctrl_student_HIL_B.etaHat[2] -
    ctrl_student_HIL_B.etaHat[2];

  /* Product: '<S20>/Product' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Product[i] = 0.0;
    ctrl_student_HIL_B.Product[i] += ctrl_student_HIL_B.sf_RTransposed.R_T[i] *
      rtb_DesPosOut_idx_1;
    ctrl_student_HIL_B.Product[i] += ctrl_student_HIL_B.sf_RTransposed.R_T[i + 3]
      * rtb_InitPosOut_idx_0;
    ctrl_student_HIL_B.Product[i] += ctrl_student_HIL_B.sf_RTransposed.R_T[i + 6]
      * rtb_InitPosOut_idx_1;
  }

  /* Switch: '<S15>/Switch3' incorporates:
   *  Constant: '<S15>/SwitchSignalFromFile'
   *  Constant: '<S44>/Constant'
   *  Constant: '<S44>/Constant1'
   *  MATLAB Function: '<S38>/MATLAB Function'
   *  MATLAB Function: '<S44>/MATLAB Function'
   */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Eta_ds/MATLAB Function': '<S46>:1' */
  /* '<S46>:1:3' */
  if (ctrl_student_HIL_P.DesiredPath > ctrl_student_HIL_P.Switch3_Threshold) {
    rtb_DesPosOut_idx_1 = rtb_pd_s_idx_0;
    rtb_InitPosOut_idx_0 = rtb_pd_s_idx_1;
    rtb_InitPosOut_idx_1 = rtb_eta_ds_idx_2;
  } else {
    rtb_DesPosOut_idx_1 = rtb_DesPosOut_idx_0;
    rtb_InitPosOut_idx_0 = rtb_DesPosOut;
    rtb_InitPosOut_idx_1 = (rtb_DesPosOut_idx_0 *
      ctrl_student_HIL_P.Constant1_Value - rtb_DesPosOut *
      ctrl_student_HIL_P.Constant_Value_k) / (rtb_DesPosOut * rtb_DesPosOut +
      rtb_DesPosOut_idx_0 * rtb_DesPosOut_idx_0);
  }

  /* End of Switch: '<S15>/Switch3' */

  /* MATLAB Function: '<S19>/Rotation Matrix' */
  /* MATLAB Function 'ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function': '<S22>:1' */
  /* '<S22>:1:3' */
  /* MATLAB Function 'ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix': '<S24>:1' */
  /* '<S24>:1:3' */
  rtb_R_c[0] = cos(ctrl_student_HIL_B.etaHat[2]);
  rtb_R_c[3] = -sin(ctrl_student_HIL_B.etaHat[2]);
  rtb_R_c[6] = 0.0;
  rtb_R_c[1] = sin(ctrl_student_HIL_B.etaHat[2]);
  rtb_R_c[4] = cos(ctrl_student_HIL_B.etaHat[2]);
  rtb_R_c[7] = 0.0;
  rtb_R_c[2] = 0.0;
  rtb_R_c[5] = 0.0;
  rtb_R_c[8] = 1.0;

  /* MATLAB Function: '<S19>/MATLAB Function1' */
  ctrl_student_HI_MATLABFunction1(rtb_R_c,
    &ctrl_student_HIL_B.sf_MATLABFunction1_pa);

  /* Product: '<S19>/Product' incorporates:
   *  MATLAB Function: '<S19>/MATLAB Function'
   *  Product: '<S19>/Product1'
   */
  for (i = 0; i < 3; i++) {
    tmp_0[i] = ctrl_student_HIL_B.sf_MATLABFunction1_pa.R_T[3 * i + 2] *
      ctrl_student_HIL_B.Product[2] +
      (ctrl_student_HIL_B.sf_MATLABFunction1_pa.R_T[3 * i + 1] *
       ctrl_student_HIL_B.Product[1] +
       ctrl_student_HIL_B.sf_MATLABFunction1_pa.R_T[3 * i] *
       ctrl_student_HIL_B.Product[0]);
  }

  /* End of Product: '<S19>/Product' */

  /* Gain: '<S19>/Gain' incorporates:
   *  Product: '<S19>/Product1'
   */
  y_dss = ((tmp_0[0] * rtb_DesPosOut_idx_1 + tmp_0[1] * rtb_InitPosOut_idx_0) +
           tmp_0[2] * rtb_InitPosOut_idx_1) * ctrl_student_HIL_P.Gain_Gain_a;

  /* MATLAB Function: '<S36>/UpdateLaw' incorporates:
   *  Constant: '<S36>/TASK'
   *  Constant: '<S36>/mu '
   *  MATLAB Function: '<S38>/MATLAB Function'
   */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/UpdateLaw': '<S41>:1' */
  /* '<S41>:1:4' */
  rtb_Switch5 = ctrl_student_HIL_B.IC / sqrt(rtb_pd_s_idx_0 * rtb_pd_s_idx_0 +
    rtb_pd_s_idx_1 * rtb_pd_s_idx_1);
  if (ctrl_student_HIL_P.LAW == 1.0) {
    /* '<S41>:1:5' */
    /* '<S41>:1:7' */
    ctrl_student_HIL_B.s_dot_l = rtb_Switch5 - ctrl_student_HIL_P.mu * y_dss;
  } else {
    /* '<S41>:1:9' */
    ctrl_student_HIL_B.s_dot_l = rtb_Switch5 - ctrl_student_HIL_P.mu / sqrt
      (rtb_pd_s_idx_0 * rtb_pd_s_idx_0 + rtb_pd_s_idx_1 * rtb_pd_s_idx_1) *
      y_dss;
  }

  /* InitialCondition: '<S33>/IC' */
  if ((ctrl_student_HIL_DW.IC_FirstOutputTime_p == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC_FirstOutputTime_p == ctrl_student_HIL_M->Timing.t
       [0])) {
    ctrl_student_HIL_DW.IC_FirstOutputTime_p = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC_n = ctrl_student_HIL_P.IC_Value_e;
  } else {
    ctrl_student_HIL_B.IC_n = ctrl_student_HIL_B.U;
  }

  /* End of InitialCondition: '<S33>/IC' */

  /* MATLAB Function: '<S43>/UpdateLaw' incorporates:
   *  Constant: '<S43>/TASK'
   *  Constant: '<S43>/mu '
   *  SignalConversion: '<S50>/TmpSignal ConversionAt SFunction Inport5'
   */
  /* MATLAB Function 'ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/UpdateLaw': '<S50>:1' */
  /* '<S50>:1:4' */
  x_dss = ctrl_student_HIL_B.IC_n / sqrt(rtb_DesPosOut_idx_0 *
    rtb_DesPosOut_idx_0 + rtb_DesPosOut * rtb_DesPosOut);
  if (ctrl_student_HIL_P.LAW == 1.0) {
    /* '<S50>:1:5' */
    /* '<S50>:1:7' */
    ctrl_student_HIL_B.s_dot = x_dss - ctrl_student_HIL_P.mu * y_dss;
  } else {
    /* '<S50>:1:9' */
    ctrl_student_HIL_B.s_dot = x_dss - ctrl_student_HIL_P.mu / sqrt
      (rtb_DesPosOut_idx_0 * rtb_DesPosOut_idx_0 + rtb_DesPosOut * rtb_DesPosOut)
      * y_dss;
  }

  ctrl_student_HIL_B.U_s = x_dss;

  /* End of MATLAB Function: '<S43>/UpdateLaw' */

  /* Switch: '<S15>/Switch4' incorporates:
   *  Constant: '<S15>/SwitchSignalFromFile'
   *  MATLAB Function: '<S36>/UpdateLaw'
   */
  if (ctrl_student_HIL_P.DesiredPath > ctrl_student_HIL_P.Switch4_Threshold) {
    y_dss = rtb_Switch5;
  } else {
    y_dss = ctrl_student_HIL_B.U_s;
  }

  /* End of Switch: '<S15>/Switch4' */

  /* Product: '<S21>/Product' incorporates:
   *  Sum: '<S21>/Sum'
   */
  for (i = 0; i < 3; i++) {
    tmp_0[i] = ctrl_student_HIL_B.Gain[i + 6] * ctrl_student_HIL_B.Product[2] +
      (ctrl_student_HIL_B.Gain[i + 3] * ctrl_student_HIL_B.Product[1] +
       ctrl_student_HIL_B.Gain[i] * ctrl_student_HIL_B.Product[0]);
  }

  /* End of Product: '<S21>/Product' */

  /* Sum: '<S18>/Sum' incorporates:
   *  Integrator: '<S53>/nuHat'
   *  Product: '<S21>/Product1'
   *  Product: '<S21>/Product2'
   *  Sum: '<S21>/Sum'
   */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Sum_g[i] = ctrl_student_HIL_X.nuHat_CSTATE[i] -
      (((rtb_DesPosOut_idx_1 * y_dss * ctrl_student_HIL_B.sf_RTransposed.R_T[i]
         + ctrl_student_HIL_B.sf_RTransposed.R_T[i + 3] * (rtb_InitPosOut_idx_0 *
          y_dss)) + ctrl_student_HIL_B.sf_RTransposed.R_T[i + 6] *
        (rtb_InitPosOut_idx_1 * y_dss)) + tmp_0[i]);
  }

  /* End of Sum: '<S18>/Sum' */

  /* Product: '<S27>/K*z_2' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Kz_2[i] = 0.0;
    ctrl_student_HIL_B.Kz_2[i] += rtb_Product2_o[i] * ctrl_student_HIL_B.Sum_g[0];
    ctrl_student_HIL_B.Kz_2[i] += rtb_Product2_o[i + 3] *
      ctrl_student_HIL_B.Sum_g[1];
    ctrl_student_HIL_B.Kz_2[i] += rtb_Product2_o[i + 6] *
      ctrl_student_HIL_B.Sum_g[2];
  }

  /* End of Product: '<S27>/K*z_2' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* MATLAB Function: '<S27>/MATLAB Function1' incorporates:
     *  Constant: '<S27>/Constant'
     */
    /* MATLAB Function 'ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1': '<S29>:1' */
    /* % MATRICES */
    /* '<S29>:1:4' */
    /*  x_g  =  0.0460; % Table B.1 */
    /* % Added mass */
    /* '<S29>:1:8' */
    /*  Table B.1 */
    /* '<S29>:1:9' */
    /*  Table B.1 guestimate */
    /* '<S29>:1:10' */
    /*  Table B.1 */
    /* % Total mass matrix */
    /* '<S29>:1:13' */
    /* '<S29>:1:14' */
    /* '<S29>:1:15' */
    /* '<S29>:1:16' */
    /* '<S29>:1:17' */
    /* '<S29>:1:19' */
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

  /* Switch: '<S15>/Switch5' incorporates:
   *  Constant: '<S15>/SwitchSignalFromFile'
   */
  if (ctrl_student_HIL_P.DesiredPath > ctrl_student_HIL_P.Switch5_Threshold) {
    rtb_Switch5 = ctrl_student_HIL_B.s_dot_l;
  } else {
    rtb_Switch5 = ctrl_student_HIL_B.s_dot;
  }

  /* End of Switch: '<S15>/Switch5' */

  /* Switch: '<S15>/Switch7' incorporates:
   *  Constant: '<S15>/SwitchSignalFromFile'
   *  Constant: '<S42>/Constant3'
   */
  if (ctrl_student_HIL_P.DesiredPath > ctrl_student_HIL_P.Switch7_Threshold) {
    x_dss = rtb_U_ss;
  } else {
    x_dss = ctrl_student_HIL_P.Constant3_Value;
  }

  /* End of Switch: '<S15>/Switch7' */

  /* MATLAB Function: '<S30>/MATLAB Function' incorporates:
   *  Integrator: '<S53>/nuHat'
   */
  /* MATLAB Function 'ControllerAndParanetrization/Controller1/Controller/Controller/alpha_1dott/MATLAB Function': '<S31>:1' */
  /* % term 1 */
  /* '<S31>:1:3' */
  S_T[0] = 0.0;
  S_T[3] = ctrl_student_HIL_X.nuHat_CSTATE[2];
  S_T[6] = 0.0;
  S_T[1] = -ctrl_student_HIL_X.nuHat_CSTATE[2];
  S_T[4] = 0.0;
  S_T[7] = 0.0;
  S_T[2] = 0.0;
  S_T[5] = 0.0;
  S_T[8] = 0.0;

  /* '<S31>:1:5' */
  /* % term 2 */
  /* '<S31>:1:8' */
  /* % term 3 */
  /* '<S31>:1:11' */
  /* % term 4 */
  /* '<S31>:1:14' */
  /* % term 5  */
  /* '<S31>:1:17' */
  /* % summary */
  /* '<S31>:1:20' */
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
    rtb_Switch[i] = rtb_M[i + 6] * rtb_InitPosOut_idx_1 + (rtb_M[i + 3] *
      rtb_InitPosOut_idx_0 + rtb_M[i] * rtb_DesPosOut_idx_1);
  }

  for (i = 0; i < 3; i++) {
    rtb_M[3 * i] = -S_T[3 * i];
    rtb_M[1 + 3 * i] = -S_T[3 * i + 1];
    rtb_M[2 + 3 * i] = -S_T[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    S_T_0[i] = ((rtb_M[i + 3] * ctrl_student_HIL_B.Product[1] + rtb_M[i] *
                 ctrl_student_HIL_B.Product[0]) + rtb_M[i + 6] *
                ctrl_student_HIL_B.Product[2]) -
      ctrl_student_HIL_X.nuHat_CSTATE[i];
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
    rtb_Product2_i[i] = rtb_M[i + 6] * rtb_InitPosOut_idx_1 + (rtb_M[i + 3] *
      rtb_InitPosOut_idx_0 + rtb_M[i] * rtb_DesPosOut_idx_1);
  }

  /* Switch: '<S15>/Switch6' incorporates:
   *  Constant: '<S15>/SwitchSignalFromFile'
   *  Constant: '<S42>/Constant'
   *  Constant: '<S42>/Constant1'
   *  Constant: '<S42>/Constant2'
   */
  if (!(ctrl_student_HIL_P.DesiredPath > ctrl_student_HIL_P.Switch6_Threshold))
  {
    rtb_eta_dss_idx_0 = ctrl_student_HIL_P.Constant_Value_o;
    rtb_eta_dss_idx_1 = ctrl_student_HIL_P.Constant1_Value_l;
    rtb_eta_dss_idx_2 = ctrl_student_HIL_P.Constant2_Value;
  }

  /* End of Switch: '<S15>/Switch6' */

  /* MATLAB Function: '<S30>/MATLAB Function' incorporates:
   *  Product: '<S27>/M*alpha_dott'
   */
  for (i = 0; i < 3; i++) {
    tmp_0[i] = ctrl_student_HIL_B.sf_RTransposed.R_T[i + 6] * rtb_eta_dss_idx_2
      + (ctrl_student_HIL_B.sf_RTransposed.R_T[i + 3] * rtb_eta_dss_idx_1 +
         ctrl_student_HIL_B.sf_RTransposed.R_T[i] * rtb_eta_dss_idx_0);
  }

  for (i = 0; i < 3; i++) {
    tmp_1[i] = ctrl_student_HIL_B.sf_RTransposed.R_T[i + 6] *
      rtb_InitPosOut_idx_1 + (ctrl_student_HIL_B.sf_RTransposed.R_T[i + 3] *
      rtb_InitPosOut_idx_0 + ctrl_student_HIL_B.sf_RTransposed.R_T[i] *
      rtb_DesPosOut_idx_1);
  }

  for (i = 0; i < 3; i++) {
    S_T_1[i] = (((((rtb_Product2_o[i + 3] * S_T_0[1] + rtb_Product2_o[i] *
                    S_T_0[0]) + rtb_Product2_o[i + 6] * S_T_0[2]) + rtb_Switch[i]
                  * y_dss) + rtb_Product2_i[i] * rtb_Switch5) + tmp_0[i] *
                rtb_Switch5 * y_dss) + tmp_1[i] * x_dss * rtb_Switch5;
  }

  /* Product: '<S27>/M*alpha_dott' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Malpha_dott[i] = 0.0;
    ctrl_student_HIL_B.Malpha_dott[i] += ctrl_student_HIL_B.M[i] * S_T_1[0];
    ctrl_student_HIL_B.Malpha_dott[i] += ctrl_student_HIL_B.M[i + 3] * S_T_1[1];
    ctrl_student_HIL_B.Malpha_dott[i] += ctrl_student_HIL_B.M[i + 6] * S_T_1[2];
  }

  /* MATLAB Function: '<S27>/MATLAB Function' incorporates:
   *  Integrator: '<S53>/nuHat'
   */
  /* MATLAB Function 'ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function': '<S28>:1' */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S28>:1:4' */
  /* '<S28>:1:8' */
  /*  Y_r */
  /*  Y_rr */
  /*  Y_rv, Y_vr */
  /* '<S28>:1:14' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /* '<S28>:1:18' */
  /* '<S28>:1:19' */
  /* '<S28>:1:20' */
  /*  using abs(r) */
  /* '<S28>:1:23' */
  /* '<S28>:1:24' */
  /* '<S28>:1:26' */
  tmp_2[0] = (0.6555 - 0.3545 * ctrl_student_HIL_X.nuHat_CSTATE[0]) -
    ctrl_student_HIL_X.nuHat_CSTATE[0] * ctrl_student_HIL_X.nuHat_CSTATE[0] *
    -3.787;
  tmp_2[3] = 0.0;
  tmp_2[6] = 0.0;
  tmp_2[1] = 0.0;
  tmp_2[4] = ((1.33 - -2.776 * ctrl_student_HIL_X.nuHat_CSTATE[1]) -
              ctrl_student_HIL_X.nuHat_CSTATE[1] *
              ctrl_student_HIL_X.nuHat_CSTATE[1] * -64.91) - -0.805 * fabs
    (ctrl_student_HIL_X.nuHat_CSTATE[2]);
  tmp_2[7] = ((7.25 - -3.45 * fabs(ctrl_student_HIL_X.nuHat_CSTATE[2])) -
              ctrl_student_HIL_X.nuHat_CSTATE[2] *
              ctrl_student_HIL_X.nuHat_CSTATE[2] * 0.0) - -0.845 * fabs
    (ctrl_student_HIL_X.nuHat_CSTATE[1]);
  tmp_2[2] = 0.0;
  tmp_2[5] = ((-0.0 - -0.2088 * ctrl_student_HIL_X.nuHat_CSTATE[1]) -
              ctrl_student_HIL_X.nuHat_CSTATE[1] *
              ctrl_student_HIL_X.nuHat_CSTATE[1] * 0.0) - 0.13 * fabs
    (ctrl_student_HIL_X.nuHat_CSTATE[2]);
  tmp_2[8] = ((1.9 - -0.75 * fabs(ctrl_student_HIL_X.nuHat_CSTATE[2])) -
              ctrl_student_HIL_X.nuHat_CSTATE[2] *
              ctrl_student_HIL_X.nuHat_CSTATE[2] * 0.0) - 0.08 * fabs
    (ctrl_student_HIL_X.nuHat_CSTATE[1]);

  /* Product: '<S27>/K*z_1' incorporates:
   *  Integrator: '<S53>/nuHat'
   */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Kz_1[i] = 0.0;
    ctrl_student_HIL_B.Kz_1[i] += tmp_2[i] * ctrl_student_HIL_X.nuHat_CSTATE[0];
    ctrl_student_HIL_B.Kz_1[i] += tmp_2[i + 3] *
      ctrl_student_HIL_X.nuHat_CSTATE[1];
    ctrl_student_HIL_B.Kz_1[i] += tmp_2[i + 6] *
      ctrl_student_HIL_X.nuHat_CSTATE[2];
  }

  /* End of Product: '<S27>/K*z_1' */

  /* Sum: '<S27>/Sum2' incorporates:
   *  Sum: '<S27>/Sum'
   *  Sum: '<S27>/Sum1'
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

  /* Switch: '<S17>/Switch2' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S14>/Constant1'
   */
  if (ctrl_student_HIL_P.Constant1_Value_d >
      ctrl_student_HIL_P.Switch2_Threshold) {
    ctrl_student_HIL_B.Switch2[0] = ctrl_student_HIL_B.Sum2[0];
    ctrl_student_HIL_B.Switch2[1] = ctrl_student_HIL_B.Sum2[1];
    ctrl_student_HIL_B.Switch2[2] = ctrl_student_HIL_B.Sum2[2];
  } else {
    ctrl_student_HIL_B.Switch2[0] = ctrl_student_HIL_P.Constant_Value_d[0];
    ctrl_student_HIL_B.Switch2[1] = ctrl_student_HIL_P.Constant_Value_d[1];
    ctrl_student_HIL_B.Switch2[2] = ctrl_student_HIL_P.Constant_Value_d[2];
  }

  /* End of Switch: '<S17>/Switch2' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S11>/Memory1' */
    ctrl_student_HIL_B.Memory1_j = ctrl_student_HIL_DW.Memory1_PreviousInput_b;
  }

  /* MATLAB Function: '<S11>/Sel_Control_Mode' */
  /* MATLAB Function 'joystick/Sel_Control_Mode': '<S76>:1' */
  if (ctrl_student_HIL_B.Select == 1.0) {
    /* '<S76>:1:3' */
    if (ctrl_student_HIL_B.Memory1_j == 2.0) {
      /* '<S76>:1:4' */
      /* '<S76>:1:5' */
      ctrl_student_HIL_B.current_mode = 3.0;
    } else {
      /* '<S76>:1:7' */
      ctrl_student_HIL_B.current_mode = 2.0;
    }
  } else {
    /* '<S76>:1:10' */
    ctrl_student_HIL_B.current_mode = ctrl_student_HIL_B.Memory1_j;
  }

  /* End of MATLAB Function: '<S11>/Sel_Control_Mode' */

  /* DeadZone: '<S11>/Dead Zone' */
  if (ctrl_student_HIL_B.PosXRight > ctrl_student_HIL_P.DeadZone_End) {
    y_dss = ctrl_student_HIL_B.PosXRight - ctrl_student_HIL_P.DeadZone_End;
  } else if (ctrl_student_HIL_B.PosXRight >= ctrl_student_HIL_P.DeadZone_Start)
  {
    y_dss = 0.0;
  } else {
    y_dss = ctrl_student_HIL_B.PosXRight - ctrl_student_HIL_P.DeadZone_Start;
  }

  /* End of DeadZone: '<S11>/Dead Zone' */

  /* Gain: '<S11>/Gain' incorporates:
   *  Sum: '<S11>/Sum'
   */
  x_dss = (ctrl_student_HIL_B.L2_continuous - ctrl_student_HIL_B.R2_continuous) *
    ctrl_student_HIL_P.Gain_Gain_p;

  /* DeadZone: '<S11>/Dead Zone2' */
  if (x_dss > ctrl_student_HIL_P.DeadZone2_End) {
    x_dss -= ctrl_student_HIL_P.DeadZone2_End;
  } else if (x_dss >= ctrl_student_HIL_P.DeadZone2_Start) {
    x_dss = 0.0;
  } else {
    x_dss -= ctrl_student_HIL_P.DeadZone2_Start;
  }

  /* End of DeadZone: '<S11>/Dead Zone2' */

  /* MATLAB Function: '<S11>/Contoller_Map1' incorporates:
   *  Constant: '<S11>/Max_Global_Forces'
   */
  /* MATLAB Function 'joystick/Contoller_Map1': '<S75>:1' */
  if (ctrl_student_HIL_B.current_mode == 2.0) {
    /* '<S75>:1:3' */
    /* '<S75>:1:4' */
    ctrl_student_HIL_B.tau_surge = y_dss *
      ctrl_student_HIL_P.Max_Global_Forces_Value[0];

    /* '<S75>:1:5' */
    ctrl_student_HIL_B.tau_sway = 0.0;

    /* '<S75>:1:6' */
    ctrl_student_HIL_B.tau_yaw = x_dss *
      ctrl_student_HIL_P.Max_Global_Forces_Value[3];
  } else {
    /* '<S75>:1:8' */
    ctrl_student_HIL_B.tau_surge = y_dss *
      ctrl_student_HIL_P.Max_Global_Forces_Value[0];

    /* DeadZone: '<S11>/Dead Zone1' incorporates:
     *  Constant: '<S11>/Max_Global_Forces'
     */
    /* '<S75>:1:9' */
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

    /* End of DeadZone: '<S11>/Dead Zone1' */
    ctrl_student_HIL_B.tau_sway = rtb_DesPosOut_idx_1 *
      ctrl_student_HIL_P.Max_Global_Forces_Value[1];

    /* '<S75>:1:10' */
    ctrl_student_HIL_B.tau_yaw = x_dss *
      ctrl_student_HIL_P.Max_Global_Forces_Value[2];
  }

  /* End of MATLAB Function: '<S11>/Contoller_Map1' */
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

  /* MATLAB Function: '<S3>/calcR(psi) ' */
  /* MATLAB Function 'DPObserver1/calcR(psi) ': '<S54>:1' */
  /* '<S54>:1:3' */
  rtb_Product2_o[0] = cos(ctrl_student_HIL_B.Yaw_out);
  rtb_Product2_o[3] = -sin(ctrl_student_HIL_B.Yaw_out);
  rtb_Product2_o[6] = 0.0;
  rtb_Product2_o[1] = sin(ctrl_student_HIL_B.Yaw_out);
  rtb_Product2_o[4] = cos(ctrl_student_HIL_B.Yaw_out);
  rtb_Product2_o[7] = 0.0;
  rtb_Product2_o[2] = 0.0;
  rtb_Product2_o[5] = 0.0;
  rtb_Product2_o[8] = 1.0;

  /* Product: '<S12>/Product' */
  /* MATLAB Function 'safety zone /MATLAB Function1': '<S79>:1' */
  /* '<S79>:1:2' */
  for (i = 0; i < 3; i++) {
    rtb_Switch[i] = rtb_Product2_o[i + 6] * ctrl_student_HIL_B.Switch2_g[2] +
      (rtb_Product2_o[i + 3] * ctrl_student_HIL_B.Switch2_g[1] +
       rtb_Product2_o[i] * ctrl_student_HIL_B.Switch2_g[0]);
  }

  /* End of Product: '<S12>/Product' */

  /* MATLAB Function: '<S12>/safety check' incorporates:
   *  Constant: '<Root>/Lim'
   */
  /* MATLAB Function 'safety zone /safety check': '<S81>:1' */
  /* safety_sig=[0;0;0;0];%orginal safety signal */
  /* lim=[40.00;0;6.45;0];%space limitation [x_max;x_min;y_max;y_min] */
  if (ctrl_student_HIL_B.etaHat[0] >= ctrl_student_HIL_P.lim[0]) {
    /* '<S81>:1:6' */
    /* '<S81>:1:7' */
    x_dss = 1.0;

    /* '<S81>:1:8' */
    y_dss = 0.0;
  } else if (ctrl_student_HIL_B.etaHat[0] <= ctrl_student_HIL_P.lim[1]) {
    /* '<S81>:1:9' */
    /* '<S81>:1:10' */
    y_dss = 1.0;

    /* '<S81>:1:11' */
    x_dss = 0.0;
  } else {
    /* '<S81>:1:13' */
    x_dss = 0.0;

    /* '<S81>:1:14' */
    y_dss = 0.0;
  }

  if (ctrl_student_HIL_B.etaHat[1] > ctrl_student_HIL_P.lim[2]) {
    /* '<S81>:1:16' */
    /* '<S81>:1:17' */
    rtb_Switch5 = 1.0;

    /* '<S81>:1:18' */
    rtb_U_ss = 0.0;
  } else if (ctrl_student_HIL_B.etaHat[1] < ctrl_student_HIL_P.lim[3]) {
    /* '<S81>:1:19' */
    /* '<S81>:1:20' */
    rtb_U_ss = 1.0;

    /* '<S81>:1:21' */
    rtb_Switch5 = 0.0;
  } else {
    /* '<S81>:1:24' */
    rtb_Switch5 = 0.0;

    /* '<S81>:1:25' */
    rtb_U_ss = 0.0;
  }

  /* End of MATLAB Function: '<S12>/safety check' */
  /*  safety_sig_1=safety_sig(1); */
  /*  safety_sig_2=safety_sig(2); */
  /* safety_sig_3=safety_sig(3); */
  /* safety_sig_4=safety_sig(4); */

  /* MATLAB Function: '<S55>/etaHatDot' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Integrator: '<S53>/nuHat'
   *  Product: '<S8>/Product1'
   *  SignalConversion: '<S59>/TmpSignal ConversionAt SFunction Inport4'
   */
  /* MATLAB Function 'DPObserver1/etaHat/etaHatDot': '<S59>:1' */
  /* etaHatDot=zeros(3,1); */
  /* '<S59>:1:4' */
  rtb_DesPosOut_idx_1 = ctrl_student_HIL_B.X_out - ctrl_student_HIL_B.etaHat[0];
  rtb_InitPosOut_idx_0 = ctrl_student_HIL_B.Y_out - ctrl_student_HIL_B.etaHat[1];
  rtb_InitPosOut_idx_1 = ctrl_student_HIL_B.Yaw_out - ctrl_student_HIL_B.etaHat
    [2];
  for (i = 0; i < 3; i++) {
    rtb_Product2_i[i] = rtb_Product2_o[i + 6] * ctrl_student_HIL_X.nuHat_CSTATE
      [2] + (rtb_Product2_o[i + 3] * ctrl_student_HIL_X.nuHat_CSTATE[1] +
             rtb_Product2_o[i] * ctrl_student_HIL_X.nuHat_CSTATE[0]);
  }

  for (i = 0; i < 3; i++) {
    tmp_0[i] = ctrl_student_HIL_P.l1[i + 6] * ctrl_student_HIL_B.sf1 *
      rtb_InitPosOut_idx_1 + (ctrl_student_HIL_P.l1[i + 3] *
      ctrl_student_HIL_B.sf1 * rtb_InitPosOut_idx_0 + ctrl_student_HIL_B.sf1 *
      ctrl_student_HIL_P.l1[i] * rtb_DesPosOut_idx_1);
  }

  ctrl_student_HIL_B.etaHatDot[0] = rtb_Product2_i[0] + tmp_0[0];
  ctrl_student_HIL_B.etaHatDot[1] = rtb_Product2_i[1] + tmp_0[1];
  ctrl_student_HIL_B.etaHatDot[2] = rtb_Product2_i[2] + tmp_0[2];

  /* End of MATLAB Function: '<S55>/etaHatDot' */

  /* MATLAB Function: '<S12>/Safety Act' incorporates:
   *  Constant: '<Root>/K'
   */
  /* MATLAB Function 'safety zone /Safety Act': '<S80>:1' */
  /* K=[1;1];     */
  if ((x_dss == 0.0) && (y_dss == 0.0) && (rtb_Switch5 == 0.0) && (rtb_U_ss ==
       0.0)) {
    /* '<S80>:1:7' */
    /* Check to see if intervention is requiered */
    /* '<S80>:1:9' */
    i = 0;

    /* Intervention is NOT requiered */
    /* '<S80>:1:10' */
    y_dss = rtb_Switch[0];

    /* '<S80>:1:11' */
    x_dss = rtb_Switch[1];

    /* disp('Flag 0.0 All OK - No safety sig'); */
  } else {
    /* '<S80>:1:14' */
    i = 1;

    /* Intervention IS requiered */
    if ((x_dss == 1.0) || (y_dss == 1.0)) {
      /* '<S80>:1:16' */
      /* Problem in X dir */
      /* disp('Flag 1.0 Problem in x'); */
      if (rtb_Switch[0] == 0.0) {
        /* '<S80>:1:18' */
        /* Check if inputforce fore is zero or correct, (but the velocity might not be) */
        /* Perhaps a proprtional gain depending on the velocity? */
        if ((ctrl_student_HIL_B.etaHatDot[0] < 0.0) && (y_dss == 1.0)) {
          /* '<S80>:1:20' */
          /* '<S80>:1:21' */
          y_dss = ctrl_student_HIL_P.K[0] * -ctrl_student_HIL_B.etaHatDot[0];

          /* disp('Flag 1.1 (x - tau=0 - Negative vel + to low x pos -> thrust =-vel*K_1)'); */
        } else if ((ctrl_student_HIL_B.etaHatDot[0] > 0.0) && (x_dss == 1.0)) {
          /* '<S80>:1:23' */
          /* '<S80>:1:24' */
          y_dss = ctrl_student_HIL_P.K[0] * -ctrl_student_HIL_B.etaHatDot[0];

          /* disp('Flag 1.2 (x - tau=0 - Positive vel + to high x pos -> thrust =-vel*K_1)'); */
        } else {
          /* '<S80>:1:27' */
          y_dss = ctrl_student_HIL_P.K[0] * ctrl_student_HIL_B.etaHatDot[0];

          /* disp('Flag 1.3 (x - tau=0 - Positive vel + to low x pos / Negative vel + to highx pos -> keep current trust)'); */
        }

        /* thrust_out=[ThrustX;joyStick(2);joyStick(3)]; */
      } else if ((rtb_Switch[0] > 0.0) && (y_dss == 1.0)) {
        /* '<S80>:1:32' */
        /* X cord to small, but thrust right way */
        /* '<S80>:1:33' */
        y_dss = rtb_Switch[0];

        /* thrust_out=[joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 1.4 (x - Positive thrust + to low x post -> keep current trust)'); */
      } else if ((rtb_Switch[0] < 0.0) && (x_dss == 1.0)) {
        /* '<S80>:1:36' */
        /* X cord to large, but thrust right way */
        /* '<S80>:1:37' */
        y_dss = rtb_Switch[0];

        /* thrust_out=[joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 1.5 (x - Negative thrust + to high x post -> Keep current trust)'); */
      } else {
        /* '<S80>:1:41' */
        y_dss = -rtb_Switch[0];

        /* thrust_out=[-joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 1.6 (x - Negative thrust + to low x post / Positive thrust + to high x post -> reverse trust)'); */
      }

      /* If */
    } else {
      /* '<S80>:1:46' */
      y_dss = rtb_Switch[0];
    }

    /* IF   */
    if ((rtb_Switch5 == 1.0) || (rtb_U_ss == 1.0)) {
      /* '<S80>:1:49' */
      /* Problem in X dir%Problem in Y dir */
      /* disp('Flag 2.0 Problem in y'); */
      if (rtb_Switch[1] == 0.0) {
        /* '<S80>:1:51' */
        /* Check if inputforce fore is zero or correct */
        /* Perhaps a proprtional gain depending on the velocity?   */
        if ((ctrl_student_HIL_B.etaHatDot[1] > 0.0) && (rtb_Switch5 == 1.0)) {
          /* '<S80>:1:53' */
          /* '<S80>:1:54' */
          x_dss = ctrl_student_HIL_P.K[1] * -ctrl_student_HIL_B.etaHatDot[1];

          /* disp('Flag 2.1 (y - tau=0 - Negative vel + to low y pos -> thrust =-vel*K_2)'); */
        } else if ((ctrl_student_HIL_B.etaHatDot[1] < 0.0) && (rtb_U_ss == 1.0))
        {
          /* '<S80>:1:56' */
          /* '<S80>:1:57' */
          x_dss = ctrl_student_HIL_P.K[1] * -ctrl_student_HIL_B.etaHatDot[1];

          /* disp('Flag 2.2 (y - tau=0 - Positive vel + to high y pos -> thrust =-vel*K_2)'); */
        } else {
          /* '<S80>:1:60' */
          x_dss = ctrl_student_HIL_P.K[1] * ctrl_student_HIL_B.etaHatDot[1];

          /* disp('Flag 2.3 (y - tau=0 - Positive vel + to low y pos / Negative vel + to high y pos -> keep current trust)'); */
        }

        /* IF */
        /* thrust_out=[joyStick(1);ThrustY;joyStick(3)]; */
      } else if ((rtb_Switch[1] > 0.0) && (rtb_U_ss == 1.0)) {
        /* '<S80>:1:65' */
        /* Y cord to small */
        /* '<S80>:1:66' */
        x_dss = rtb_Switch[1];

        /* thrust_out=[joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 2.4 (y - Positive thrust + to low y post -> keep current trust)'); */
      } else if ((rtb_Switch[1] < 0.0) && (rtb_Switch5 == 1.0)) {
        /* '<S80>:1:70' */
        /* Y cord to large */
        /* '<S80>:1:71' */
        x_dss = rtb_Switch[1];

        /* thrust_out=[joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 2.5 (y - Negative thrust + to high y post -> Keep current trust)'); */
      } else {
        /* '<S80>:1:76' */
        x_dss = -rtb_Switch[1];

        /* thrust_out=[joyStick(1);-joyStick(2);joyStick(3)]; */
        /* disp('Flag 2.6 (y - Negative thrust + to low y post / Positive thrust + to high y post -> reverse trust)'); */
      }

      /* IF */
    } else {
      /* '<S80>:1:82' */
      x_dss = rtb_Switch[1];
    }

    /* IF */
  }

  /* Switch: '<S12>/Switch' incorporates:
   *  MATLAB Function: '<S12>/Safety Act'
   */
  /* IF */
  /* '<S80>:1:86' */
  /* Function */
  if (!(i > ctrl_student_HIL_P.Switch_Threshold_n)) {
    y_dss = rtb_Switch[0];
    x_dss = rtb_Switch[1];
  }

  rtb_eta_ds_idx_2 = rtb_Switch[2];

  /* End of Switch: '<S12>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S12>/Memory' */
    ctrl_student_HIL_B.Memory_n = ctrl_student_HIL_DW.Memory_PreviousInput_e;
  }

  /* MATLAB Function: '<S12>/KillSwitch' incorporates:
   *  Constant: '<Root>/Lim2'
   *  MATLAB Function: '<S12>/Safety Act'
   */
  /* MATLAB Function 'safety zone /KillSwitch': '<S77>:1' */
  if (ctrl_student_HIL_B.Memory_n == 1.0) {
    /* '<S77>:1:3' */
    /* '<S77>:1:4' */
    i = 1;

    /* disp('Flag 3.0 KILL - previous kill'); */
  } else {
    if (ctrl_student_HIL_B.etaHat[0] >= ctrl_student_HIL_P.lim_2[0]) {
      /* '<S77>:1:7' */
      /* '<S77>:1:9' */
      i = 1;

      /* disp('Flag 3.1 KILL - large x'); */
    } else if (ctrl_student_HIL_B.etaHat[0] <= ctrl_student_HIL_P.lim_2[1]) {
      /* '<S77>:1:11' */
      /* '<S77>:1:13' */
      i = 1;

      /* disp('Flag 3.2 KILL - small x'); */
    } else {
      /* '<S77>:1:17' */
      i = 0;
    }

    /* IF */
    if (ctrl_student_HIL_B.etaHat[1] >= ctrl_student_HIL_P.lim_2[2]) {
      /* '<S77>:1:19' */
      /* '<S77>:1:20' */
      i = 1;

      /* disp('Flag 3.3 KILL - large y'); */
    } else {
      if (ctrl_student_HIL_B.etaHat[1] <= ctrl_student_HIL_P.lim_2[3]) {
        /* '<S77>:1:22' */
        /* '<S77>:1:23' */
        i = 1;

        /* disp('Flag 3.4 KILL - small y'); */
      }
    }

    /* IF */
  }

  /*  IF */
  if (i == 1) {
    /* '<S77>:1:35' */
    /* '<S77>:1:36' */
    rtb_DesPosOut_idx_1 = 0.0;
    rtb_InitPosOut_idx_0 = 0.0;
    rtb_InitPosOut_idx_1 = 0.0;
  } else {
    /* '<S77>:1:38' */
    rtb_DesPosOut_idx_1 = y_dss;
    rtb_InitPosOut_idx_0 = x_dss;
    rtb_InitPosOut_idx_1 = rtb_Switch[2];
  }

  /* IF */
  /* Function */

  /* MATLAB Function: '<S12>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S12>/KillSwitch'
   */
  /* MATLAB Function 'safety zone /MATLAB Function': '<S78>:1' */
  if (ctrl_student_HIL_B.SZ_ResetKill == 1.0) {
    /* '<S78>:1:3' */
    /* '<S78>:1:4' */
    ctrl_student_HIL_B.kill_signal = 0.0;
  } else {
    /* '<S78>:1:6' */
    ctrl_student_HIL_B.kill_signal = i;
  }

  /* End of MATLAB Function: '<S12>/MATLAB Function' */

  /* Switch: '<S12>/Switch2' */
  if (!(ctrl_student_HIL_B.SZ_Owerwrite > ctrl_student_HIL_P.Switch2_Threshold_p))
  {
    /* Switch: '<S12>/Switch1' */
    if (ctrl_student_HIL_B.kill_signal > ctrl_student_HIL_P.Switch1_Threshold) {
      rtb_Switch[0] = rtb_DesPosOut_idx_1;
      rtb_Switch[1] = rtb_InitPosOut_idx_0;
      rtb_Switch[2] = rtb_InitPosOut_idx_1;
    } else {
      rtb_Switch[0] = y_dss;
      rtb_Switch[1] = x_dss;
      rtb_Switch[2] = rtb_eta_ds_idx_2;
    }

    /* End of Switch: '<S12>/Switch1' */
  }

  /* End of Switch: '<S12>/Switch2' */

  /* Product: '<S12>/Product1' incorporates:
   *  MATLAB Function: '<S12>/MATLAB Function1'
   */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Product1[i] = 0.0;
    ctrl_student_HIL_B.Product1[i] += rtb_Product2_o[3 * i] * rtb_Switch[0];
    ctrl_student_HIL_B.Product1[i] += rtb_Product2_o[3 * i + 1] * rtb_Switch[1];
    ctrl_student_HIL_B.Product1[i] += rtb_Product2_o[3 * i + 2] * rtb_Switch[2];
  }

  /* End of Product: '<S12>/Product1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* ToWorkspace: '<S1>/To Workspace3' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (ctrl_student_HIL_DW.ToWorkspace3_PWORK.LoggedData),
                    &ctrl_student_HIL_B.Switch[0], 0);
  }

  /* InitialCondition: '<S51>/IC1' incorporates:
   *  Constant: '<S51>/Constant'
   *  Integrator: '<S51>/bHat'
   *  Product: '<S51>/Product'
   *  Sum: '<S51>/Sum'
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

  /* End of InitialCondition: '<S51>/IC1' */

  /* MATLAB Function: '<S51>/bHatDot' incorporates:
   *  Constant: '<S8>/Constant3'
   *  Product: '<S8>/Product'
   *  SignalConversion: '<S56>/TmpSignal ConversionAt SFunction Inport2'
   */
  /* MATLAB Function 'DPObserver1/Bias/bHatDot': '<S56>:1' */
  /* '<S56>:1:3' */
  rtb_DesPosOut_idx_1 = ctrl_student_HIL_B.X_out - ctrl_student_HIL_B.etaHat[0];
  rtb_InitPosOut_idx_0 = ctrl_student_HIL_B.Y_out - ctrl_student_HIL_B.etaHat[1];
  rtb_InitPosOut_idx_1 = ctrl_student_HIL_B.Yaw_out - ctrl_student_HIL_B.etaHat
    [2];
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
  /* MATLAB Function 'DPObserver1/D': '<S52>:1' */
  /* '<S52>:1:3' */
  /* u=0;  */
  /* '<S52>:1:4' */
  /* v=0;  */
  /* '<S52>:1:5' */
  /* r=0; */
  /* '<S52>:1:7' */
  /* '<S52>:1:10' */
  /* '<S52>:1:13' */
  /* '<S52>:1:18' */
  /* '<S52>:1:21' */
  /* '<S52>:1:27' */
  /* '<S52>:1:28' */
  /* '<S52>:1:29' */
  /* '<S52>:1:30' */
  /* '<S52>:1:31' */
  /* '<S52>:1:33' */
  /* MATLAB Function 'DPObserver1/Subsystem/M': '<S57>:1' */
  /* '<S57>:1:3' */
  /* '<S57>:1:4' */
  /* MATLAB Function 'DPObserver1/Subsystem/nuHatDot': '<S58>:1' */
  /* nuHatDot=inv(M)*(-D*nuHat+transpose(R)*bHat+tau+K2*transpose(R)*L2*(eta-etaHat)); */
  /* '<S58>:1:5' */
  for (i = 0; i < 9; i++) {
    /* MATLAB Function: '<S53>/nuHatDot' incorporates:
     *  MATLAB Function: '<S53>/M'
     */
    S_T[i] = tmp[i];

    /* MATLAB Function: '<S53>/M' */
    rtb_M[i] = tmp[i];
  }

  /* End of MATLAB Function: '<S51>/bHatDot' */

  /* MATLAB Function: '<S53>/nuHatDot' */
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

  x_dss = S_T[1] / S_T[0];
  S_T[1] /= S_T[0];
  y_dss = S_T[2] / S_T[0];
  S_T[2] /= S_T[0];
  S_T[4] -= x_dss * S_T[3];
  S_T[5] -= y_dss * S_T[3];
  S_T[7] -= x_dss * S_T[6];
  S_T[8] -= y_dss * S_T[6];
  if (fabs(S_T[5]) > fabs(S_T[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    S_T[1] = y_dss;
    S_T[2] = x_dss;
    x_dss = S_T[4];
    S_T[4] = S_T[5];
    S_T[5] = x_dss;
    x_dss = S_T[7];
    S_T[7] = S_T[8];
    S_T[8] = x_dss;
  }

  rtb_Switch5 = S_T[5];
  rtb_U_ss = S_T[4];
  x_dss = S_T[5] / S_T[4];
  S_T[8] -= x_dss * S_T[7];
  x_dss = (x_dss * S_T[1] - S_T[2]) / S_T[8];
  y_dss = -(S_T[7] * x_dss + S_T[1]) / S_T[4];
  y[i] = ((1.0 - S_T[3] * y_dss) - S_T[6] * x_dss) / S_T[0];
  y[i + 1] = y_dss;
  y[i + 2] = x_dss;
  x_dss = -(rtb_Switch5 / rtb_U_ss) / S_T[8];
  y_dss = (1.0 - S_T[7] * x_dss) / S_T[4];
  y[p2] = -(S_T[3] * y_dss + S_T[6] * x_dss) / S_T[0];
  y[p2 + 1] = y_dss;
  y[p2 + 2] = x_dss;
  x_dss = 1.0 / S_T[8];
  y_dss = -S_T[7] * x_dss / S_T[4];
  y[p3] = -(S_T[3] * y_dss + S_T[6] * x_dss) / S_T[0];
  y[p3 + 1] = y_dss;
  y[p3 + 2] = x_dss;

  /* InitialCondition: '<S53>/IC' incorporates:
   *  MATLAB Function: '<S53>/nuHatDot'
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

    /* MATLAB Function: '<S53>/nuHatDot' incorporates:
     *  Constant: '<S8>/Constant2'
     *  Integrator: '<S53>/nuHat'
     *  Product: '<S8>/Product2'
     *  SignalConversion: '<S58>/TmpSignal ConversionAt SFunction Inport7'
     */
    for (i = 0; i < 3; i++) {
      tmp_2[3 * i] = -tmp_3[3 * i];
      tmp_2[1 + 3 * i] = -tmp_3[3 * i + 1];
      tmp_2[2 + 3 * i] = -tmp_3[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      tmp_0[i] = tmp_2[i + 6] * ctrl_student_HIL_X.nuHat_CSTATE[2] + (tmp_2[i +
        3] * ctrl_student_HIL_X.nuHat_CSTATE[1] + tmp_2[i] *
        ctrl_student_HIL_X.nuHat_CSTATE[0]);
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

    rtb_DesPosOut_idx_1 = ctrl_student_HIL_B.X_out - ctrl_student_HIL_B.etaHat[0];
    rtb_InitPosOut_idx_0 = ctrl_student_HIL_B.Y_out - ctrl_student_HIL_B.etaHat
      [1];
    rtb_InitPosOut_idx_1 = ctrl_student_HIL_B.Yaw_out -
      ctrl_student_HIL_B.etaHat[2];
    for (i = 0; i < 3; i++) {
      tmp_1[i] = ((rtb_M[i + 3] * rtb_InitPosOut_idx_0 + rtb_M[i] *
                   rtb_DesPosOut_idx_1) + rtb_M[i + 6] * rtb_InitPosOut_idx_1) +
        ((tmp_0[i] + rtb_Product2_i[i]) + ctrl_student_HIL_B.Product1[i]);
    }

    for (i = 0; i < 3; i++) {
      ctrl_student_HIL_B.IC_i[i] = 0.0;
      ctrl_student_HIL_B.IC_i[i] += y[i] * tmp_1[0];
      ctrl_student_HIL_B.IC_i[i] += y[i + 3] * tmp_1[1];
      ctrl_student_HIL_B.IC_i[i] += y[i + 6] * tmp_1[2];
    }
  }

  /* End of InitialCondition: '<S53>/IC' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }
}

/* Model update function */
void ctrl_student_HIL_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S63>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_B.count;

    /* Update for RandomNumber: '<S69>/White Noise' */
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S70>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_j) * ctrl_student_HIL_P.WhiteNoise_StdDev_d
      + ctrl_student_HIL_P.WhiteNoise_Mean_h;

    /* Update for RandomNumber: '<S68>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_c) * ctrl_student_HIL_P.WhiteNoise_StdDev_g
      + ctrl_student_HIL_P.WhiteNoise_Mean_f;

    /* Update for Memory: '<S64>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_B.output[0];
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_B.output[1];
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_B.output[2];

    /* Update for Memory: '<S6>/Memory2' */
    ctrl_student_HIL_DW.Memory2_PreviousInput = ctrl_student_HIL_B.X_out;

    /* Update for Memory: '<S6>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput = ctrl_student_HIL_B.Y_out;

    /* Update for Memory: '<S6>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput = ctrl_student_HIL_B.Yaw_out;

    /* Update for Memory: '<S32>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_f = ctrl_student_HIL_B.Switch_d;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S33>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_m =
      ctrl_student_HIL_B.SwitchSignal_out;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S45>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_p = ctrl_student_HIL_B.N_out;

    /* Update for Memory: '<S45>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput_p[0] =
      ctrl_student_HIL_B.init_time[0];
    ctrl_student_HIL_DW.Memory1_PreviousInput_p[1] =
      ctrl_student_HIL_B.init_time[1];

    /* Update for Memory: '<S11>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput_b =
      ctrl_student_HIL_B.current_mode;

    /* Update for Memory: '<S12>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_e = ctrl_student_HIL_B.kill_signal;
  }

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

  /* Derivatives for Integrator: '<S55>/etaHat' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->etaHat_CSTATE[0] = ctrl_student_HIL_B.etaHatDot[0];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->etaHat_CSTATE[1] = ctrl_student_HIL_B.etaHatDot[1];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->etaHat_CSTATE[2] = ctrl_student_HIL_B.etaHatDot[2];
  }

  /* Derivatives for Integrator: '<S36>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE = ctrl_student_HIL_B.s_dot_l;
  }

  /* Derivatives for Integrator: '<S43>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_f = ctrl_student_HIL_B.s_dot;
  }

  /* Derivatives for Integrator: '<S53>/nuHat' */
  _rtXdot->nuHat_CSTATE[0] = ctrl_student_HIL_B.IC_i[0];
  _rtXdot->nuHat_CSTATE[1] = ctrl_student_HIL_B.IC_i[1];
  _rtXdot->nuHat_CSTATE[2] = ctrl_student_HIL_B.IC_i[2];

  /* Derivatives for Integrator: '<S51>/bHat' */
  _rtXdot->bHat_CSTATE[0] = ctrl_student_HIL_B.bHatDot[0];
  _rtXdot->bHat_CSTATE[1] = ctrl_student_HIL_B.bHatDot[1];
  _rtXdot->bHat_CSTATE[2] = ctrl_student_HIL_B.bHatDot[2];
}

/* Model initialize function */
void ctrl_student_HIL_initialize(void)
{
  /* Start for InitialCondition: '<S32>/IC' */
  ctrl_student_HIL_B.IC = ctrl_student_HIL_P.IC_Value;
  ctrl_student_HIL_DW.IC_FirstOutputTime = (rtMinusInf);

  /* Start for InitialCondition: '<S33>/IC' */
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

  /* Start for InitialCondition: '<S51>/IC1' */
  ctrl_student_HIL_B.IC1[0] = ctrl_student_HIL_P.IC1_Value[0];
  ctrl_student_HIL_B.IC1[1] = ctrl_student_HIL_P.IC1_Value[1];
  ctrl_student_HIL_B.IC1[2] = ctrl_student_HIL_P.IC1_Value[2];
  ctrl_student_HIL_DW.IC1_FirstOutputTime = (rtMinusInf);

  /* Start for InitialCondition: '<S53>/IC' */
  ctrl_student_HIL_DW.IC_FirstOutputTime_n = (rtMinusInf);
  ctrl_student_HIL_PrevZCX.etaHat_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_c = UNINITIALIZED_ZCSIG;

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Integrator: '<S55>/etaHat' */
    ctrl_student_HIL_X.etaHat_CSTATE[0] = (ctrl_student_HIL_P.etaHat_IC[0]);
    ctrl_student_HIL_X.etaHat_CSTATE[1] = (ctrl_student_HIL_P.etaHat_IC[1]);
    ctrl_student_HIL_X.etaHat_CSTATE[2] = (ctrl_student_HIL_P.etaHat_IC[2]);

    /* InitializeConditions for Memory: '<S63>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S69>/White Noise' */
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

    /* End of InitializeConditions for RandomNumber: '<S69>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S70>/White Noise' */
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

    /* End of InitializeConditions for RandomNumber: '<S70>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S68>/White Noise' */
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

    /* End of InitializeConditions for RandomNumber: '<S68>/White Noise' */

    /* InitializeConditions for Memory: '<S64>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_P.Hold_X0;

    /* InitializeConditions for Memory: '<S6>/Memory2' */
    ctrl_student_HIL_DW.Memory2_PreviousInput = ctrl_student_HIL_P.Memory2_X0;

    /* InitializeConditions for Memory: '<S6>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput = ctrl_student_HIL_P.Memory1_X0;

    /* InitializeConditions for Memory: '<S6>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput = ctrl_student_HIL_P.Memory_X0;

    /* InitializeConditions for Memory: '<S32>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_f = ctrl_student_HIL_P.Memory_X0_n;

    /* InitializeConditions for Integrator: '<S36>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE = ctrl_student_HIL_P.Integrator_IC;

    /* InitializeConditions for Memory: '<S33>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_m = ctrl_student_HIL_P.Memory_X0_l;

    /* InitializeConditions for Integrator: '<S43>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE_f = ctrl_student_HIL_P.Integrator_IC_p;

    /* InitializeConditions for Memory: '<S45>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_p = ctrl_student_HIL_P.Memory_X0_j;

    /* InitializeConditions for Memory: '<S45>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput_p[0] =
      ctrl_student_HIL_P.Memory1_X0_p[0];
    ctrl_student_HIL_DW.Memory1_PreviousInput_p[1] =
      ctrl_student_HIL_P.Memory1_X0_p[1];

    /* InitializeConditions for Integrator: '<S53>/nuHat' */
    ctrl_student_HIL_X.nuHat_CSTATE[0] = ctrl_student_HIL_P.nuHat_IC[0];
    ctrl_student_HIL_X.nuHat_CSTATE[1] = ctrl_student_HIL_P.nuHat_IC[1];
    ctrl_student_HIL_X.nuHat_CSTATE[2] = ctrl_student_HIL_P.nuHat_IC[2];

    /* InitializeConditions for Memory: '<S11>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput_b =
      ctrl_student_HIL_P.Memory1_X0_j;

    /* InitializeConditions for Memory: '<S12>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_e = ctrl_student_HIL_P.Memory_X0_i;

    /* InitializeConditions for Integrator: '<S51>/bHat' */
    ctrl_student_HIL_X.bHat_CSTATE[0] = ctrl_student_HIL_P.bHat_IC;
    ctrl_student_HIL_X.bHat_CSTATE[1] = ctrl_student_HIL_P.bHat_IC;
    ctrl_student_HIL_X.bHat_CSTATE[2] = ctrl_student_HIL_P.bHat_IC;
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
  ctrl_student_HIL_M->Sizes.numContStates = (11);/* Number of continuous states */
  ctrl_student_HIL_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_M->Sizes.numBlocks = (261);/* Number of blocks */
  ctrl_student_HIL_M->Sizes.numBlockIO = (94);/* Number of block outputs */
  ctrl_student_HIL_M->Sizes.numBlockPrms = (456);/* Sum of parameter "widths" */
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

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 44:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 45:
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

   case 30:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 44:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 45:
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

  // y_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // psi_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.psi_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.u_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // x_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x_in, 0, data[index++], 0, 0);
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

  // Dropout_signaINl
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Dropout_signaINl, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // r_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.r_in, 0, data[index++], 0, 0);
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

  // v_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.v_in, 0, data[index++], 0, 0);
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
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 33;
}

double ni_extout[28];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // eta_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.etaHat,0,17,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.etaHat,1,17,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.etaHat,2,17,
      0);
  } else {
    index += 3;
  }

  // u_real  : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_in,0,0,0);
  } else {
    index += 1;
  }

  // eta_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,1,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,2,17,0);
  } else {
    index += 3;
  }

  // eta_noise: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI,0,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI,1,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI,2,17,0);
  } else {
    index += 3;
  }

  // Dropout_signaOUT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.Dropout_signaINl,0,0,0);
  } else {
    index += 1;
  }

  // joystick/Current Mode : Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.current_mode,0,0,0);
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
      19,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch2_g,1,
      19,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch2_g,2,
      19,0);
  } else {
    index += 3;
  }

  // Tau_post: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product1,0,
      19,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product1,1,
      19,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product1,2,
      19,0);
  } else {
    index += 3;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product1,0,
      19,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product1,2,
      19,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product1,1,
      19,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant2_Value_e,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant_Value_i,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant1_Value_h,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.reset,0,0,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 28;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // eta_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.etaHat,0,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.etaHat,1,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.etaHat,2,17,0);

  // u_real  : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_in,0,0,0);

  // eta_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,1,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,2,17,0);

  // eta_noise: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI,0,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI,1,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI,2,17,0);

  // Dropout_signaOUT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.Dropout_signaINl,0,0,0);

  // joystick/Current Mode : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.current_mode,
    0,0,0);

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
    19,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch2_g,1,
    19,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch2_g,2,
    19,0);

  // Tau_post: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product1,0,19,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product1,1,19,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product1,2,19,
    0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product1,0,19,
    0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product1,2,19,
    0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product1,1,19,
    0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant2_Value_e,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant_Value_i,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant1_Value_h,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.reset,0,0,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/SwitchSignalFromFile/Value",
    offsetof(P_ctrl_student_HIL_T, DesiredPath), 44, 1, 2, 0, 0 },

  { 1,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization /Elipscenter_radi/Value",
    offsetof(P_ctrl_student_HIL_T, Elipscenter_radi), 23, 4, 2, 2, 0 },

  { 2, "ctrl_student_hil/K/Value", offsetof(P_ctrl_student_HIL_T, K), 20, 2, 2,
    4, 0 },

  { 3, "ctrl_student_hil/ControllerGain/Constant1/Value", offsetof
    (P_ctrl_student_HIL_T, K1), 18, 9, 2, 6, 0 },

  { 4,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Kp/Value",
    offsetof(P_ctrl_student_HIL_T, K1), 18, 9, 2, 8, 0 },

  { 5, "ctrl_student_hil/ControllerGain/Constant2/Value", offsetof
    (P_ctrl_student_HIL_T, K2), 18, 9, 2, 10, 0 },

  { 6,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/TASK/Value",
    offsetof(P_ctrl_student_HIL_T, LAW), 44, 1, 2, 12, 0 },

  { 7,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/TASK/Value",
    offsetof(P_ctrl_student_HIL_T, LAW), 44, 1, 2, 14, 0 },

  { 8,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, T_initialDP), 44, 1, 2, 16, 0 },

  { 9,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Check_s/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, U_ref), 44, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, U_ref), 44, 1, 2, 20, 0 },

  { 11, "ctrl_student_hil/ObserverGain/Constant1/Value", offsetof
    (P_ctrl_student_HIL_T, l1), 18, 9, 2, 22, 0 },

  { 12, "ctrl_student_hil/ObserverGain/Constant2/Value", offsetof
    (P_ctrl_student_HIL_T, l2), 18, 9, 2, 24, 0 },

  { 13, "ctrl_student_hil/ObserverGain/Constant3/Value", offsetof
    (P_ctrl_student_HIL_T, l3), 18, 9, 2, 26, 0 },

  { 14, "ctrl_student_hil/Lim/Value", offsetof(P_ctrl_student_HIL_T, lim), 27, 4,
    2, 28, 0 },

  { 15, "ctrl_student_hil/Lim2/Value", offsetof(P_ctrl_student_HIL_T, lim_2), 27,
    4, 2, 30, 0 },

  { 16,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, m), 44, 1, 2, 32, 0 },

  { 17,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/mu/Value",
    offsetof(P_ctrl_student_HIL_T, mu), 44, 1, 2, 34, 0 },

  { 18,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/mu/Value",
    offsetof(P_ctrl_student_HIL_T, mu), 44, 1, 2, 36, 0 },

  { 19,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Desired Position/Value",
    offsetof(P_ctrl_student_HIL_T, pd), 23, 4, 2, 38, 0 },

  { 20, "ctrl_student_hil/safety zone /Switch1/Threshold", offsetof
    (P_ctrl_student_HIL_T, Switch1_Threshold), 44, 1, 2, 40, 0 },

  { 21, "ctrl_student_hil/DPObserver1/etaHat/etaHat/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, etaHat_IC), 19, 3, 2, 42, 0 },

  { 22, "ctrl_student_hil/Noise generator/Step size/Value", offsetof
    (P_ctrl_student_HIL_T, Stepsize_Value), 44, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil/Noise generator/Downsamplesignal/counter/X0", offsetof
    (P_ctrl_student_HIL_T, counter_X0), 44, 1, 2, 46, 0 },

  { 24, "ctrl_student_hil/Constant/Value", offsetof(P_ctrl_student_HIL_T,
    Constant_Value), 44, 1, 2, 48, 0 },

  { 25,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean), 44, 1, 2, 50, 0 },

  { 26,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev), 44, 1, 2, 52, 0 },

  { 27,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed), 44, 1, 2, 54, 0 },

  { 28,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_h), 44, 1, 2, 56, 0 },

  { 29,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_d), 44, 1, 2, 58, 0 },

  { 30,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_b), 44, 1, 2, 60, 0 },

  { 31,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_f), 44, 1, 2, 62, 0 },

  { 32,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_g), 44, 1, 2, 64, 0 },

  { 33,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_l), 44, 1, 2, 66, 0 },

  { 34, "ctrl_student_hil/Noise generator/Sample & hold/Hold/X0", offsetof
    (P_ctrl_student_HIL_T, Hold_X0), 44, 1, 2, 68, 0 },

  { 35, "ctrl_student_hil/Dropout_simulator/Memory2/X0", offsetof
    (P_ctrl_student_HIL_T, Memory2_X0), 44, 1, 2, 70, 0 },

  { 36, "ctrl_student_hil/Dropout_simulator/Memory1/X0", offsetof
    (P_ctrl_student_HIL_T, Memory1_X0), 44, 1, 2, 72, 0 },

  { 37, "ctrl_student_hil/Dropout_simulator/Memory/X0", offsetof
    (P_ctrl_student_HIL_T, Memory_X0), 44, 1, 2, 74, 0 },

  { 38,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain/Gain",
    offsetof(P_ctrl_student_HIL_T, Gain_Gain), 44, 1, 2, 76, 0 },

  { 39,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Memory/X0",
    offsetof(P_ctrl_student_HIL_T, Memory_X0_n), 44, 1, 2, 78, 0 },

  { 40,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/Integrator/InitialCondition",
    offsetof(P_ctrl_student_HIL_T, Integrator_IC), 44, 1, 2, 80, 0 },

  { 41,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/IC/Value",
    offsetof(P_ctrl_student_HIL_T, IC_Value), 44, 1, 2, 82, 0 },

  { 42,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Memory/X0",
    offsetof(P_ctrl_student_HIL_T, Memory_X0_l), 44, 1, 2, 84, 0 },

  { 43,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/Integrator/InitialCondition",
    offsetof(P_ctrl_student_HIL_T, Integrator_IC_p), 44, 1, 2, 86, 0 },

  { 44,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Memory/X0",
    offsetof(P_ctrl_student_HIL_T, Memory_X0_j), 44, 1, 2, 88, 0 },

  { 45,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Memory1/X0",
    offsetof(P_ctrl_student_HIL_T, Memory1_X0_p), 31, 2, 2, 90, 0 },

  { 46,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch_Threshold), 44, 1, 2, 92, 0 },

  { 47,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Eta_ds/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_k), 44, 1, 2, 94, 0 },

  { 48,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Eta_ds/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value), 44, 1, 2, 96, 0 },

  { 49,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch3/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch3_Threshold), 44, 1, 2, 98, 0 },

  { 50,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Gain/Gain",
    offsetof(P_ctrl_student_HIL_T, Gain_Gain_a), 44, 1, 2, 100, 0 },

  { 51,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/IC/Value",
    offsetof(P_ctrl_student_HIL_T, IC_Value_e), 44, 1, 2, 102, 0 },

  { 52,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch4/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch4_Threshold), 44, 1, 2, 104, 0 },

  { 53, "ctrl_student_hil/DPObserver1/Subsystem/nuHat/InitialCondition",
    offsetof(P_ctrl_student_HIL_T, nuHat_IC), 19, 3, 2, 106, 0 },

  { 54,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch5/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch5_Threshold), 44, 1, 2, 108, 0 },

  { 55,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_o), 44, 1, 2, 110, 0 },

  { 56,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value_l), 44, 1, 2, 112, 0 },

  { 57,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value), 44, 1, 2, 114, 0 },

  { 58,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch6/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch6_Threshold), 44, 1, 2, 116, 0 },

  { 59,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Constant3/Value",
    offsetof(P_ctrl_student_HIL_T, Constant3_Value), 44, 1, 2, 118, 0 },

  { 60,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch7/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch7_Threshold), 44, 1, 2, 120, 0 },

  { 61,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value_d), 44, 1, 2, 122, 0 },

  { 62,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_d), 19, 3, 2, 124, 0 },

  { 63,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Switch2/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch2_Threshold), 44, 1, 2, 126, 0 },

  { 64, "ctrl_student_hil/joystick/Memory1/X0", offsetof(P_ctrl_student_HIL_T,
    Memory1_X0_j), 44, 1, 2, 128, 0 },

  { 65, "ctrl_student_hil/joystick/Max_Global_Forces/Value", offsetof
    (P_ctrl_student_HIL_T, Max_Global_Forces_Value), 32, 4, 2, 130, 0 },

  { 66, "ctrl_student_hil/joystick/Dead Zone/LowerValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone_Start), 44, 1, 2, 132, 0 },

  { 67, "ctrl_student_hil/joystick/Dead Zone/UpperValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone_End), 44, 1, 2, 134, 0 },

  { 68, "ctrl_student_hil/joystick/Dead Zone1/LowerValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone1_Start), 44, 1, 2, 136, 0 },

  { 69, "ctrl_student_hil/joystick/Dead Zone1/UpperValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone1_End), 44, 1, 2, 138, 0 },

  { 70, "ctrl_student_hil/joystick/Gain/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain_Gain_p), 44, 1, 2, 140, 0 },

  { 71, "ctrl_student_hil/joystick/Dead Zone2/LowerValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone2_Start), 44, 1, 2, 142, 0 },

  { 72, "ctrl_student_hil/joystick/Dead Zone2/UpperValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone2_End), 44, 1, 2, 144, 0 },

  { 73, "ctrl_student_hil/Switch2/Threshold", offsetof(P_ctrl_student_HIL_T,
    Switch2_Threshold_i), 44, 1, 2, 146, 0 },

  { 74, "ctrl_student_hil/safety zone /Switch/Threshold", offsetof
    (P_ctrl_student_HIL_T, Switch_Threshold_n), 44, 1, 2, 148, 0 },

  { 75, "ctrl_student_hil/safety zone /Memory/X0", offsetof(P_ctrl_student_HIL_T,
    Memory_X0_i), 44, 1, 2, 150, 0 },

  { 76, "ctrl_student_hil/safety zone /Switch2/Threshold", offsetof
    (P_ctrl_student_HIL_T, Switch2_Threshold_p), 44, 1, 2, 152, 0 },

  { 77,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value_e), 44, 1, 2, 154, 0 },

  { 78,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_i), 44, 1, 2, 156, 0 },

  { 79,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value_h), 44, 1, 2, 158, 0 },

  { 80, "ctrl_student_hil/DPObserver1/Bias/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_e), 19, 3, 2, 160, 0 },

  { 81, "ctrl_student_hil/DPObserver1/Bias/bHat/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, bHat_IC), 44, 1, 2, 162, 0 },

  { 82, "ctrl_student_hil/DPObserver1/Bias/IC1/Value", offsetof
    (P_ctrl_student_HIL_T, IC1_Value), 19, 3, 2, 164, 0 },

  { 83, "ctrl_student_hil/DPObserver1/Subsystem/IC/Value", offsetof
    (P_ctrl_student_HIL_T, IC_Value_f), 19, 3, 2, 166, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 84;
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
  3, 3,                                /* Parameter at index 11 */
  3, 3,                                /* Parameter at index 12 */
  3, 3,                                /* Parameter at index 13 */
  4, 1,                                /* Parameter at index 14 */
  4, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  2, 2,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  3, 1,                                /* Parameter at index 21 */
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
  1, 2,                                /* Parameter at index 45 */
  1, 1,                                /* Parameter at index 46 */
  1, 1,                                /* Parameter at index 47 */
  1, 1,                                /* Parameter at index 48 */
  1, 1,                                /* Parameter at index 49 */
  1, 1,                                /* Parameter at index 50 */
  1, 1,                                /* Parameter at index 51 */
  1, 1,                                /* Parameter at index 52 */
  3, 1,                                /* Parameter at index 53 */
  1, 1,                                /* Parameter at index 54 */
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
  1, 4,                                /* Parameter at index 65 */
  1, 1,                                /* Parameter at index 66 */
  1, 1,                                /* Parameter at index 67 */
  1, 1,                                /* Parameter at index 68 */
  1, 1,                                /* Parameter at index 69 */
  1, 1,                                /* Parameter at index 70 */
  1, 1,                                /* Parameter at index 71 */
  1, 1,                                /* Parameter at index 72 */
  1, 1,                                /* Parameter at index 73 */
  1, 1,                                /* Parameter at index 74 */
  1, 1,                                /* Parameter at index 75 */
  1, 1,                                /* Parameter at index 76 */
  1, 1,                                /* Parameter at index 77 */
  1, 1,                                /* Parameter at index 78 */
  1, 1,                                /* Parameter at index 79 */
  3, 1,                                /* Parameter at index 80 */
  1, 1,                                /* Parameter at index 81 */
  3, 1,                                /* Parameter at index 82 */
  3, 1,                                /* Parameter at index 83 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student_hil/reset", 0, "", offsetof(B_ctrl_student_HIL_T, reset)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_student_hil/DPObserver1/etaHat/etaHat", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, etaHat)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 2, 0
  },

  { 2, "ctrl_student_hil/DPObserver1/etaHat/etaHat", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, etaHat)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 4, 0
  },

  { 3, "ctrl_student_hil/DPObserver1/etaHat/etaHat", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, etaHat)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 6, 0
  },

  { 4, "ctrl_student_hil/y_in", 0, "", offsetof(B_ctrl_student_HIL_T, y_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/psi_in", 0, "", offsetof(B_ctrl_student_HIL_T, psi_in)+
    0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/u_in", 0, "", offsetof(B_ctrl_student_HIL_T, u_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil/x_in", 0, "", offsetof(B_ctrl_student_HIL_T, x_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8, "ctrl_student_hil/Sum1", 0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Sum1)
    +0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 16, 0 },

  { 9, "ctrl_student_hil/Sum1", 0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Sum1)
    +1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 18, 0 },

  { 10, "ctrl_student_hil/Sum1", 0, "(1,3)", offsetof(B_ctrl_student_HIL_T, Sum1)
    +2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 20, 0 },

  { 11, "ctrl_student_hil/NoisePowPos", 0, "", offsetof(B_ctrl_student_HIL_T,
    NoisePowPos)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 24, 0 },

  { 13,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_e)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 26, 0 },

  { 14, "ctrl_student_hil/NoisePowHead", 0, "", offsetof(B_ctrl_student_HIL_T,
    NoisePowHead)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 28, 0 },

  { 15,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_m)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 30, 0 },

  { 16, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Hold)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    32, 0 },

  { 17, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, Hold)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    34, 0 },

  { 18, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, Hold)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    36, 0 },

  { 19, "ctrl_student_hil/NoiseEnable", 0, "", offsetof(B_ctrl_student_HIL_T,
    NoiseEnable)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 38, 0 },

  { 20, "ctrl_student_hil/Dropout_simulator/Memory2", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 40,
    0 },

  { 21, "ctrl_student_hil/Dropout_simulator/Memory1", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 42,
    0 },

  { 22, "ctrl_student_hil/Dropout_simulator/Memory", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 44, 0
  },

  { 23, "ctrl_student_hil/Dropout_signaINl", 0, "", offsetof
    (B_ctrl_student_HIL_T, Dropout_signaINl)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 46, 0 },

  { 24, "ctrl_student_hil/r_in", 0, "", offsetof(B_ctrl_student_HIL_T, r_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil/ControllerGainK2", 0, "", offsetof
    (B_ctrl_student_HIL_T, ControllerGainK2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 50, 0 },

  { 26,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Gain)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 52, 0 },

  { 27,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Gain)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 54, 0 },

  { 28,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Gain)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 56, 0 },

  { 29,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Gain)+3*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 58, 0 },

  { 30,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(2,2)", offsetof(B_ctrl_student_HIL_T, Gain)+4*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 60, 0 },

  { 31,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(3,2)", offsetof(B_ctrl_student_HIL_T, Gain)+5*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 62, 0 },

  { 32,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(1,3)", offsetof(B_ctrl_student_HIL_T, Gain)+6*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 64, 0 },

  { 33,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(2,3)", offsetof(B_ctrl_student_HIL_T, Gain)+7*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 66, 0 },

  { 34,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1/Gain",
    0, "(3,3)", offsetof(B_ctrl_student_HIL_T, Gain)+8*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 68, 0 },

  { 35,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/Integrator",
    0, "", offsetof(B_ctrl_student_HIL_T, Integrator)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 70, 0 },

  { 36,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/IC",
    0, "", offsetof(B_ctrl_student_HIL_T, IC)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 72, 0 },

  { 37,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/Integrator",
    0, "", offsetof(B_ctrl_student_HIL_T, Integrator_m)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 74, 0 },

  { 38,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Memory",
    0, "", offsetof(B_ctrl_student_HIL_T, Memory_o)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 76, 0 },

  { 39,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Memory1",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Memory1_m)+0*sizeof(real_T),
    BLOCKIO_SIG, 22, 1, 2, 78, 0 },

  { 40,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/Memory1",
    0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Memory1_m)+1*sizeof(real_T),
    BLOCKIO_SIG, 22, 1, 2, 80, 0 },

  { 41,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Sum",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Sum)+0*sizeof(real_T),
    BLOCKIO_SIG, 20, 1, 2, 82, 0 },

  { 42,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Sum",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Sum)+1*sizeof(real_T),
    BLOCKIO_SIG, 20, 1, 2, 84, 0 },

  { 43,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Switch)+0*sizeof(real_T),
    BLOCKIO_SIG, 20, 1, 2, 86, 0 },

  { 44,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/Switch",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Switch)+1*sizeof(real_T),
    BLOCKIO_SIG, 20, 1, 2, 88, 0 },

  { 45,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Product",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Product)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 90, 0 },

  { 46,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Product",
    0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Product)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 92, 0 },

  { 47,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Product",
    0, "(1,3)", offsetof(B_ctrl_student_HIL_T, Product)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 94, 0 },

  { 48,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/IC",
    0, "", offsetof(B_ctrl_student_HIL_T, IC_n)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 96, 0 },

  { 49,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Sum",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Sum_g)+0*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 98, 0 },

  { 50,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Sum",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Sum_g)+1*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 100, 0 },

  { 51,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Sum",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Sum_g)+2*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 102, 0 },

  { 52,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/K*z_2",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Kz_2)+0*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 104, 0 },

  { 53,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/K*z_2",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Kz_2)+1*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 106, 0 },

  { 54,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/K*z_2",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Kz_2)+2*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 108, 0 },

  { 55, "ctrl_student_hil/ControllerGainK1", 0, "", offsetof
    (B_ctrl_student_HIL_T, ControllerGainK1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 110, 0 },

  { 56,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/M*alpha_dott",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Malpha_dott)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 112, 0 },

  { 57,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/M*alpha_dott",
    0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Malpha_dott)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 114, 0 },

  { 58,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/M*alpha_dott",
    0, "(1,3)", offsetof(B_ctrl_student_HIL_T, Malpha_dott)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 116, 0 },

  { 59,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/K*z_1",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Kz_1)+0*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 118, 0 },

  { 60,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/K*z_1",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Kz_1)+1*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 120, 0 },

  { 61,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/K*z_1",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Kz_1)+2*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 122, 0 },

  { 62,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/Sum2",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Sum2)+0*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 124, 0 },

  { 63,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/Sum2",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Sum2)+1*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 126, 0 },

  { 64,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/Sum2",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Sum2)+2*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 128, 0 },

  { 65,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Switch2",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Switch2)+0*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 130, 0 },

  { 66,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Switch2",
    0, "(2,1)", offsetof(B_ctrl_student_HIL_T, Switch2)+1*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 132, 0 },

  { 67,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Switch2",
    0, "(3,1)", offsetof(B_ctrl_student_HIL_T, Switch2)+2*sizeof(real_T),
    BLOCKIO_SIG, 19, 1, 2, 134, 0 },

  { 68, "ctrl_student_hil/joystick/Memory1", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory1_j)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    136, 0 },

  { 69, "ctrl_student_hil/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    138, 0 },

  { 70, "ctrl_student_hil/joystick/Select", 0, "", offsetof(B_ctrl_student_HIL_T,
    Select)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 140, 0 },

  { 71, "ctrl_student_hil/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    142, 0 },

  { 72, "ctrl_student_hil/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    144, 0 },

  { 73, "ctrl_student_hil/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    146, 0 },

  { 74, "ctrl_student_hil/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 148,
    0 },

  { 75, "ctrl_student_hil/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 150,
    0 },

  { 76, "ctrl_student_hil/joystick/L1", 0, "", offsetof(B_ctrl_student_HIL_T, L1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 152, 0 },

  { 77, "ctrl_student_hil/joystick/R1", 0, "", offsetof(B_ctrl_student_HIL_T, R1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 154, 0 },

  { 78, "ctrl_student_hil/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    156, 0 },

  { 79, "ctrl_student_hil/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 158,
    0 },

  { 80, "ctrl_student_hil/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    160, 0 },

  { 81, "ctrl_student_hil/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    162, 0 },

  { 82, "ctrl_student_hil/JoysticControllerSwitch", 0, "", offsetof
    (B_ctrl_student_HIL_T, JoysticControllerSwitch)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 164, 0 },

  { 83, "ctrl_student_hil/Switch2", 0, "(1,1)", offsetof(B_ctrl_student_HIL_T,
    Switch2_g)+0*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 166, 0 },

  { 84, "ctrl_student_hil/Switch2", 0, "(2,1)", offsetof(B_ctrl_student_HIL_T,
    Switch2_g)+1*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 168, 0 },

  { 85, "ctrl_student_hil/Switch2", 0, "(3,1)", offsetof(B_ctrl_student_HIL_T,
    Switch2_g)+2*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 170, 0 },

  { 86, "ctrl_student_hil/sf1", 0, "", offsetof(B_ctrl_student_HIL_T, sf1)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 172, 0 },

  { 87, "ctrl_student_hil/safety zone /Memory", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory_n)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 174,
    0 },

  { 88, "ctrl_student_hil/SZ_ResetKill", 0, "", offsetof(B_ctrl_student_HIL_T,
    SZ_ResetKill)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 176, 0 },

  { 89, "ctrl_student_hil/SZ_Owerwrite", 0, "", offsetof(B_ctrl_student_HIL_T,
    SZ_Owerwrite)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 178, 0 },

  { 90, "ctrl_student_hil/safety zone /Product1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Product1)+0*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    180, 0 },

  { 91, "ctrl_student_hil/safety zone /Product1", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, Product1)+1*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    182, 0 },

  { 92, "ctrl_student_hil/safety zone /Product1", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, Product1)+2*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    184, 0 },

  { 93, "ctrl_student_hil/v_in", 0, "", offsetof(B_ctrl_student_HIL_T, v_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 186, 0 },

  { 94, "ctrl_student_hil/sf2", 0, "", offsetof(B_ctrl_student_HIL_T, sf2)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 188, 0 },

  { 95, "ctrl_student_hil/sf3", 0, "", offsetof(B_ctrl_student_HIL_T, sf3)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 190, 0 },

  { 96, "ctrl_student_hil/biasOffset", 0, "", offsetof(B_ctrl_student_HIL_T,
    biasOffset)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 192, 0 },

  { 97, "ctrl_student_hil/DPObserver1/Bias/IC1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, IC1)+0*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 194, 0
  },

  { 98, "ctrl_student_hil/DPObserver1/Bias/IC1", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, IC1)+1*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 196, 0
  },

  { 99, "ctrl_student_hil/DPObserver1/Bias/IC1", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, IC1)+2*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2, 198, 0
  },

  { 100, "ctrl_student_hil/DPObserver1/Subsystem/IC", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, IC_i)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 200, 0
  },

  { 101, "ctrl_student_hil/DPObserver1/Subsystem/IC", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, IC_i)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 202, 0
  },

  { 102, "ctrl_student_hil/DPObserver1/Subsystem/IC", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, IC_i)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 204, 0
  },

  { 103, "ctrl_student_hil/safety zone /MATLAB Function", 0, "kill_signal",
    offsetof(B_ctrl_student_HIL_T, kill_signal)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 206, 0 },

  { 104, "ctrl_student_hil/joystick/Sel_Control_Mode", 0, "current_mode",
    offsetof(B_ctrl_student_HIL_T, current_mode)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 208, 0 },

  { 105, "ctrl_student_hil/joystick/Contoller_Map1", 0, "tau_surge", offsetof
    (B_ctrl_student_HIL_T, tau_surge)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    210, 0 },

  { 106, "ctrl_student_hil/joystick/Contoller_Map1", 1, "tau_sway", offsetof
    (B_ctrl_student_HIL_T, tau_sway)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 212,
    0 },

  { 107, "ctrl_student_hil/joystick/Contoller_Map1", 2, "tau_yaw", offsetof
    (B_ctrl_student_HIL_T, tau_yaw)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 214,
    0 },

  { 108, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,1)", offsetof(B_ctrl_student_HIL_T, output)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 216, 0 },

  { 109, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,2)", offsetof(B_ctrl_student_HIL_T, output)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 218, 0 },

  { 110, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,3)", offsetof(B_ctrl_student_HIL_T, output)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 220, 0 },

  { 111, "ctrl_student_hil/Noise generator/Downsamplesignal/MATLAB Function", 0,
    "count", offsetof(B_ctrl_student_HIL_T, count)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 222, 0 },

  { 112, "ctrl_student_hil/Dropout_simulator/MATLAB Function", 0, "X_out",
    offsetof(B_ctrl_student_HIL_T, X_out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    224, 0 },

  { 113, "ctrl_student_hil/Dropout_simulator/MATLAB Function", 1, "Y_out",
    offsetof(B_ctrl_student_HIL_T, Y_out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    226, 0 },

  { 114, "ctrl_student_hil/Dropout_simulator/MATLAB Function", 2, "Yaw_out",
    offsetof(B_ctrl_student_HIL_T, Yaw_out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 228, 0 },

  { 115, "ctrl_student_hil/DPObserver1/etaHat/etaHatDot", 0, "etaHatDot(1,1)",
    offsetof(B_ctrl_student_HIL_T, etaHatDot)+0*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 230, 0 },

  { 116, "ctrl_student_hil/DPObserver1/etaHat/etaHatDot", 0, "etaHatDot(1,2)",
    offsetof(B_ctrl_student_HIL_T, etaHatDot)+1*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 232, 0 },

  { 117, "ctrl_student_hil/DPObserver1/etaHat/etaHatDot", 0, "etaHatDot(1,3)",
    offsetof(B_ctrl_student_HIL_T, etaHatDot)+2*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 234, 0 },

  { 118, "ctrl_student_hil/DPObserver1/Bias/bHatDot", 0, "bHatDot(1,1)",
    offsetof(B_ctrl_student_HIL_T, bHatDot)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 236, 0 },

  { 119, "ctrl_student_hil/DPObserver1/Bias/bHatDot", 0, "bHatDot(1,2)",
    offsetof(B_ctrl_student_HIL_T, bHatDot)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 238, 0 },

  { 120, "ctrl_student_hil/DPObserver1/Bias/bHatDot", 0, "bHatDot(1,3)",
    offsetof(B_ctrl_student_HIL_T, bHatDot)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 240, 0 },

  { 121,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/UpdateLaw",
    0, "s_dot", offsetof(B_ctrl_student_HIL_T, s_dot)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 242, 0 },

  { 122,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/UpdateLaw",
    1, "U_s", offsetof(B_ctrl_student_HIL_T, U_s)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 244, 0 },

  { 123,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    2, "SwitchSignal_out", offsetof(B_ctrl_student_HIL_T, SwitchSignal_out)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 246, 0 },

  { 124,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    3, "N_out", offsetof(B_ctrl_student_HIL_T, N_out)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 248, 0 },

  { 125,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    4, "U", offsetof(B_ctrl_student_HIL_T, U)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 250, 0 },

  { 126,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    5, "s_out", offsetof(B_ctrl_student_HIL_T, s_out)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 252, 0 },

  { 127,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    6, "init_time(1,1)", offsetof(B_ctrl_student_HIL_T, init_time)+0*sizeof
    (real_T), BLOCKIO_SIG, 22, 1, 2, 254, 0 },

  { 128,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    6, "init_time(1,2)", offsetof(B_ctrl_student_HIL_T, init_time)+1*sizeof
    (real_T), BLOCKIO_SIG, 22, 1, 2, 256, 0 },

  { 129,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function",
    7, "flag", offsetof(B_ctrl_student_HIL_T, flag)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 258, 0 },

  { 130,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/UpdateLaw",
    0, "s_dot", offsetof(B_ctrl_student_HIL_T, s_dot_l)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 260, 0 },

  { 131,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization /Subsystem/MATLAB Function",
    0, "pd(1,1)", offsetof(B_ctrl_student_HIL_T, pd)+0*sizeof(real_T),
    BLOCKIO_SIG, 22, 1, 2, 262, 0 },

  { 132,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization /Subsystem/MATLAB Function",
    0, "pd(1,2)", offsetof(B_ctrl_student_HIL_T, pd)+1*sizeof(real_T),
    BLOCKIO_SIG, 22, 1, 2, 264, 0 },

  { 133,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Check_s/CheckS&getU",
    0, "s_out", offsetof(B_ctrl_student_HIL_T, s_out_j)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 266, 0 },

  { 134,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Check_s/CheckS&getU",
    2, "Switch", offsetof(B_ctrl_student_HIL_T, Switch_d)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 268, 0 },

  { 135,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(1,1)", offsetof(B_ctrl_student_HIL_T, M)+0*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 270, 0 },

  { 136,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(2,1)", offsetof(B_ctrl_student_HIL_T, M)+1*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 272, 0 },

  { 137,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(3,1)", offsetof(B_ctrl_student_HIL_T, M)+2*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 274, 0 },

  { 138,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(1,2)", offsetof(B_ctrl_student_HIL_T, M)+3*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 276, 0 },

  { 139,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(2,2)", offsetof(B_ctrl_student_HIL_T, M)+4*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 278, 0 },

  { 140,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(3,2)", offsetof(B_ctrl_student_HIL_T, M)+5*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 280, 0 },

  { 141,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(1,3)", offsetof(B_ctrl_student_HIL_T, M)+6*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 282, 0 },

  { 142,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(2,3)", offsetof(B_ctrl_student_HIL_T, M)+7*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 284, 0 },

  { 143,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1",
    0, "M(3,3)", offsetof(B_ctrl_student_HIL_T, M)+8*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 286, 0 },

  { 144,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/MATLAB Function1",
    0, "SwitchSignal_Out", offsetof(B_ctrl_student_HIL_T,
    sf_MATLABFunction1_p.SwitchSignal_Out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 288, 0 },

  { 145,
    "ctrl_student_hil/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/MATLAB Function1",
    0, "SwitchSignal_Out", offsetof(B_ctrl_student_HIL_T,
    sf_MATLABFunction1_m.SwitchSignal_Out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 290, 0 },

  { 146,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(1,1)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+0*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 292, 0 },

  { 147,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(2,1)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+1*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 294, 0 },

  { 148,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(3,1)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+2*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 296, 0 },

  { 149,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(1,2)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+3*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 298, 0 },

  { 150,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(2,2)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+4*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 300, 0 },

  { 151,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(3,2)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+5*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 302, 0 },

  { 152,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(1,3)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+6*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 304, 0 },

  { 153,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(2,3)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+7*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 306, 0 },

  { 154,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed",
    0, "R_T(3,3)", offsetof(B_ctrl_student_HIL_T, sf_RTransposed.R_T)+8*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 308, 0 },

  { 155,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(1,1)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+0*
    sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 310, 0 },

  { 156,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(2,1)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+1*
    sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 312, 0 },

  { 157,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(3,1)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+2*
    sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 314, 0 },

  { 158,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(1,2)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+3*
    sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 316, 0 },

  { 159,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(2,2)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+4*
    sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 318, 0 },

  { 160,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(3,2)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+5*
    sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 320, 0 },

  { 161,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(1,3)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+6*
    sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 322, 0 },

  { 162,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(2,3)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+7*
    sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 324, 0 },

  { 163,
    "ctrl_student_hil/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1",
    0, "R_T(3,3)", offsetof(B_ctrl_student_HIL_T, sf_MATLABFunction1_pa.R_T)+8*
    sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 326, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 164;
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
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 51;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "reset", 0, EXT_IN, 1, 1, 1 },

  { 1, "y_in", 0, EXT_IN, 1, 1, 1 },

  { 2, "psi_in", 0, EXT_IN, 1, 1, 1 },

  { 3, "u_in", 1, EXT_IN, 1, 1, 1 },

  { 4, "x_in", 0, EXT_IN, 1, 1, 1 },

  { 5, "NoisePowPos", 0, EXT_IN, 1, 1, 1 },

  { 6, "NoisePowHead", 0, EXT_IN, 1, 1, 1 },

  { 7, "NoiseEnable", 0, EXT_IN, 1, 1, 1 },

  { 8, "Dropout_signaINl", 0, EXT_IN, 1, 1, 1 },

  { 9, "r_in", 1, EXT_IN, 1, 1, 1 },

  { 10, "ControllerGainK2", 0, EXT_IN, 1, 1, 1 },

  { 11, "ControllerGainK1", 0, EXT_IN, 1, 1, 1 },

  { 12, "joystick/L2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 13, "joystick/Select", 0, EXT_IN, 1, 1, 1 },

  { 14, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 15, "joystick/PosYRight", 0, EXT_IN, 1, 1, 1 },

  { 16, "joystick/R2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 17, "joystick/PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 18, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 19, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 20, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 21, "joystick/ArrowDown", 1, EXT_IN, 1, 1, 1 },

  { 22, "joystick/ArrowUp", 1, EXT_IN, 1, 1, 1 },

  { 23, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 24, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { 25, "JoysticControllerSwitch", 0, EXT_IN, 1, 1, 1 },

  { 26, "sf1", 0, EXT_IN, 1, 1, 1 },

  { 27, "SZ_ResetKill", 0, EXT_IN, 1, 1, 1 },

  { 28, "SZ_Owerwrite", 0, EXT_IN, 1, 1, 1 },

  { 29, "v_in", 1, EXT_IN, 1, 1, 1 },

  { 30, "sf2", 0, EXT_IN, 1, 1, 1 },

  { 31, "sf3", 0, EXT_IN, 1, 1, 1 },

  { 32, "biasOffset", 0, EXT_IN, 1, 1, 1 },

  { 0, "eta_hat", 0, EXT_OUT, 3, 3, 1 },

  { 1, "u_real  ", 1, EXT_OUT, 1, 1, 1 },

  { 2, "eta_tilde", 0, EXT_OUT, 3, 3, 1 },

  { 3, "eta_noise", 0, EXT_OUT, 3, 3, 1 },

  { 4, "Dropout_signaOUT", 0, EXT_OUT, 1, 1, 1 },

  { 5, "joystick/Current Mode ", 0, EXT_OUT, 1, 1, 1 },

  { 6, "joystick/tau_yaw", 0, EXT_OUT, 1, 1, 1 },

  { 7, "joystick/tau_x", 0, EXT_OUT, 1, 1, 1 },

  { 8, "joystick/tau_y", 0, EXT_OUT, 1, 1, 1 },

  { 9, "Tau_pre", 0, EXT_OUT, 3, 3, 1 },

  { 10, "Tau_post", 0, EXT_OUT, 3, 3, 1 },

  { 11, "tau to CSE mocell (only use for HIL testing)/X_d", 0, EXT_OUT, 1, 1, 1
  },

  { 12, "tau to CSE mocell (only use for HIL testing)/N_d", 0, EXT_OUT, 1, 1, 1
  },

  { 13, "tau to CSE mocell (only use for HIL testing)/Y_d", 0, EXT_OUT, 1, 1, 1
  },

  { 14, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 15, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1
  },

  { 16, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 17, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 0,
    EXT_OUT, 1, 1, 1 },

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
static char* NI_CompiledModelVersion = "1.258";
static char* NI_CompiledModelDateTime = "Sat Apr 01 15:41:16 2017";
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
      *numContStates = 11;
      *numDiscStates = 1054;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.etaHat_CSTATE
      [0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "etaHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.etaHat_CSTATE
      [0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "etaHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.etaHat_CSTATE
      [0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "etaHat_CSTATE");
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
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.bHat_CSTATE[0],
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "bHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.bHat_CSTATE[0],
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "bHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.bHat_CSTATE[0],
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "bHat_CSTATE");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.reset_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.reset_DWORK1");
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
      (&ctrl_student_HIL_DW.Memory2_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory1_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Dropout_signaINl_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Dropout_signaINl_DWORK1");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Dropout_signaOUT_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Dropout_signaOUT_DWORK1");
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
      (&ctrl_student_HIL_DW.Memory_PreviousInput_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory1_PreviousInput_p, 0, 22, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory1_PreviousInput_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory1_PreviousInput_p, 1, 22, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory1_PreviousInput_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC_FirstOutputTime_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC_FirstOutputTime_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ControllerGainK1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ControllerGainK1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory1_PreviousInput_b, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory1_PreviousInput_b");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK1");
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
      (&ctrl_student_HIL_DW.IC1_FirstOutputTime, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC1_FirstOutputTime");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC_FirstOutputTime_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC_FirstOutputTime_n");
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
    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.reset_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.reset_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_hat_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_hat_DWORK2");
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
        (&ctrl_student_HIL_DW.Dropout_signaINl_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Dropout_signaINl_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_noise_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_noise_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Dropout_signaOUT_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Dropout_signaOUT_DWORK2");
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
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK2");
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.etaHat_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.etaHat_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.etaHat_CSTATE[0], 2,
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.bHat_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.bHat_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.bHat_CSTATE[0], 2,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.reset_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_DWORK1, 2,
      discStates[idx++], 17, 0);
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory2_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_signaINl_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_noise_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_noise_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_noise_DWORK1, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_signaOUT_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ControllerGainK2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_f, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput_p, 0,
      discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput_p, 1,
      discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC_FirstOutputTime_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ControllerGainK1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput_b, 0,
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC1_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC_FirstOutputTime_n, 0,
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
    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.reset_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_DWORK2, count,
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_signaINl_DWORK2,
        count, discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_noise_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_signaOUT_DWORK2,
        count, discStates[idx++], 24, 0);
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2, count,
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
