/*
 * ctrl_student_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.300
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Apr 05 14:45:01 2017
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
  int_T nXc = 10;
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
void ctrl_student_HIL_output(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator1[3];
  real_T rtb_Integrator[3];
  real_T rtb_Clock;
  int32_T X;
  real_T rtb_Saturation;
  real_T rtb_K_psi;
  real_T rtb_Switch[3];
  real_T rtb_DeadZone;
  real_T rtb_switch_sig;
  real_T rtb_safety_sig_3;
  real_T rtb_safety_sig_4;
  real_T rtb_Product_j[3];
  real_T rtb_R[9];
  real_T tmp[9];
  real_T tmp_0[9];
  real_T rtb_Switch3_idx_2;
  real_T rtb_Switch3_idx_0;
  real_T rtb_Switch3_idx_1;
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

  /* Integrator: '<S7>/Integrator' */
  ctrl_student_HIL_B.Integrator = ctrl_student_HIL_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* InitialCondition: '<S7>/IC' incorporates:
     *  Constant: '<S7>/Constant'
     */
    if (ctrl_student_HIL_DW.IC_FirstOutputTime) {
      ctrl_student_HIL_DW.IC_FirstOutputTime = false;
      ctrl_student_HIL_B.IC = ctrl_student_HIL_P.IC_Value;
    } else {
      ctrl_student_HIL_B.IC = ctrl_student_HIL_P.Constant_Value;
    }

    /* End of InitialCondition: '<S7>/IC' */
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Constant: '<Root>/Constant2' */
    ctrl_student_HIL_B.Constant2[0] = ctrl_student_HIL_P.eta_dot_ini[0];
    ctrl_student_HIL_B.Constant2[1] = ctrl_student_HIL_P.eta_dot_ini[1];
    ctrl_student_HIL_B.Constant2[2] = ctrl_student_HIL_P.eta_dot_ini[2];
  }

  /* Integrator: '<S10>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_student_HIL_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_student_HIL_DW.Integrator1_IWORK.IcNeedsLoading) {
      ctrl_student_HIL_X.Integrator1_CSTATE[0] = ctrl_student_HIL_B.Constant2[0];
      ctrl_student_HIL_X.Integrator1_CSTATE[1] = ctrl_student_HIL_B.Constant2[1];
      ctrl_student_HIL_X.Integrator1_CSTATE[2] = ctrl_student_HIL_B.Constant2[2];
    }
  }

  rtb_Integrator1[0] = ctrl_student_HIL_X.Integrator1_CSTATE[0];
  rtb_Integrator1[1] = ctrl_student_HIL_X.Integrator1_CSTATE[1];
  rtb_Integrator1[2] = ctrl_student_HIL_X.Integrator1_CSTATE[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<S4>/Step size'
     *  Memory: '<S14>/counter'
     */
    /* MATLAB Function 'Noise generator/Downsample	signal/MATLAB Function': '<S17>:1' */
    /* '<S17>:1:3' */
    if ((ctrl_student_HIL_DW.counter_PreviousInput + 1.0) *
        ctrl_student_HIL_P.Stepsize_Value >= 1.0 /
        ctrl_student_HIL_P.Constant_Value_d) {
      /* '<S17>:1:4' */
      /* '<S17>:1:5' */
      ctrl_student_HIL_B.count = 0.0;
    } else {
      /* '<S17>:1:7' */
      ctrl_student_HIL_B.count = ctrl_student_HIL_DW.counter_PreviousInput + 1.0;
    }

    /* End of MATLAB Function: '<S14>/MATLAB Function' */
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S20>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise = ctrl_student_HIL_DW.NextOutput;
  }

  /* Product: '<S21>/Divide' incorporates:
   *  Constant: '<S4>/Step size'
   */
  rtb_Clock = ctrl_student_HIL_B.NoisePowPos / ctrl_student_HIL_P.Stepsize_Value;

  /* Sqrt: '<S21>/Sqrt' */
  rtb_Clock = sqrt(rtb_Clock);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S21>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_e = ctrl_student_HIL_DW.NextOutput_c;
  }

  /* Product: '<S21>/Product' */
  rtb_Clock *= ctrl_student_HIL_B.WhiteNoise_e;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S19>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_m = ctrl_student_HIL_DW.NextOutput_p;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S15>/Hold' */
    ctrl_student_HIL_B.Hold[0] = ctrl_student_HIL_DW.Hold_PreviousInput[0];
    ctrl_student_HIL_B.Hold[1] = ctrl_student_HIL_DW.Hold_PreviousInput[1];
    ctrl_student_HIL_B.Hold[2] = ctrl_student_HIL_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S15>/MATLAB Function1' incorporates:
   *  Constant: '<S4>/Step size'
   *  Product: '<S19>/Divide'
   *  Product: '<S19>/Product'
   *  Product: '<S20>/Divide'
   *  Product: '<S20>/Product'
   *  Sqrt: '<S19>/Sqrt'
   *  Sqrt: '<S20>/Sqrt'
   *  Sum: '<S4>/Sum'
   */
  /* MATLAB Function 'Noise generator/Sample & hold/MATLAB Function1': '<S18>:1' */
  if (ctrl_student_HIL_B.count == 0.0) {
    /* '<S18>:1:4' */
    /* '<S18>:1:5' */
    ctrl_student_HIL_B.output[0] = sqrt(ctrl_student_HIL_B.NoisePowPos /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise +
      ctrl_student_HIL_B.x_in;
    ctrl_student_HIL_B.output[1] = rtb_Clock + ctrl_student_HIL_B.y_in;
    ctrl_student_HIL_B.output[2] = sqrt(ctrl_student_HIL_B.NoisePowHead /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise_m +
      ctrl_student_HIL_B.psi_in;
  } else {
    /* '<S18>:1:7' */
    ctrl_student_HIL_B.output[0] = ctrl_student_HIL_B.Hold[0];
    ctrl_student_HIL_B.output[1] = ctrl_student_HIL_B.Hold[1];
    ctrl_student_HIL_B.output[2] = ctrl_student_HIL_B.Hold[2];
  }

  /* End of MATLAB Function: '<S15>/MATLAB Function1' */

  /* Switch: '<S4>/Switch' */
  if (ctrl_student_HIL_B.NoiseEnable != 0.0) {
    rtb_Switch[0] = ctrl_student_HIL_B.output[0];
    rtb_Switch[1] = ctrl_student_HIL_B.output[1];
    rtb_Switch[2] = ctrl_student_HIL_B.output[2];
  } else {
    rtb_Switch[0] = ctrl_student_HIL_B.x_in;
    rtb_Switch[1] = ctrl_student_HIL_B.y_in;
    rtb_Switch[2] = ctrl_student_HIL_B.psi_in;
  }

  /* End of Switch: '<S4>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S2>/Memory2' */
    ctrl_student_HIL_B.Memory2 = ctrl_student_HIL_DW.Memory2_PreviousInput;

    /* Memory: '<S2>/Memory1' */
    ctrl_student_HIL_B.Memory1 = ctrl_student_HIL_DW.Memory1_PreviousInput;

    /* Memory: '<S2>/Memory' */
    ctrl_student_HIL_B.Memory = ctrl_student_HIL_DW.Memory_PreviousInput;
  }

  /* MATLAB Function: '<S2>/MATLAB Function' */
  /* MATLAB Function 'Dropout_simulator/MATLAB Function': '<S13>:1' */
  /* '<S13>:1:2' */
  ctrl_student_HIL_B.X_out = -1.0;

  /* '<S13>:1:3' */
  ctrl_student_HIL_B.Y_out = -1.0;

  /* '<S13>:1:4' */
  ctrl_student_HIL_B.Yaw_out = -1.0;
  switch ((int32_T)ctrl_student_HIL_B.Dropout_signaINl) {
   case 0:
    /* '<S13>:1:9' */
    ctrl_student_HIL_B.X_out = rtb_Switch[0];

    /* '<S13>:1:10' */
    ctrl_student_HIL_B.Y_out = rtb_Switch[1];

    /* '<S13>:1:11' */
    ctrl_student_HIL_B.Yaw_out = rtb_Switch[2];
    break;

   case 1:
    /* '<S13>:1:14' */
    ctrl_student_HIL_B.X_out = ctrl_student_HIL_B.Memory2;

    /* '<S13>:1:15' */
    ctrl_student_HIL_B.Y_out = ctrl_student_HIL_B.Memory1;

    /* '<S13>:1:16' */
    ctrl_student_HIL_B.Yaw_out = ctrl_student_HIL_B.Memory;
    break;
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* SignalConversion: '<Root>/TmpSignal ConversionAteta_noiseInport1' */
  ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI[0] =
    ctrl_student_HIL_B.X_out;
  ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI[1] =
    ctrl_student_HIL_B.Y_out;
  ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI[2] =
    ctrl_student_HIL_B.Yaw_out;

  /* Switch: '<Root>/Switch3' */
  if (ctrl_student_HIL_B.Dropout_signaINl > ctrl_student_HIL_P.Switch3_Threshold)
  {
    rtb_Switch3_idx_0 = rtb_Integrator1[0];
    rtb_Switch3_idx_1 = rtb_Integrator1[1];
    rtb_Switch3_idx_2 = rtb_Integrator1[2];
  } else {
    rtb_Switch3_idx_0 = ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI[0];
    rtb_Switch3_idx_1 = ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI[1];
    rtb_Switch3_idx_2 = ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI[2];
  }

  /* End of Switch: '<Root>/Switch3' */

  /* MATLAB Function: '<S7>/k_psiSign' */
  /* MATLAB Function 'SurgeObserver/k_psiSign': '<S24>:1' */
  /* '<S24>:1:3' */
  rtb_DeadZone = cos(rtb_Switch3_idx_2) + sin(rtb_Switch3_idx_2);
  if (rtb_DeadZone < 0.0) {
    rtb_DeadZone = -1.0;
  } else if (rtb_DeadZone > 0.0) {
    rtb_DeadZone = 1.0;
  } else {
    if (rtb_DeadZone == 0.0) {
      rtb_DeadZone = 0.0;
    }
  }

  rtb_K_psi = ctrl_student_HIL_B.IC * rtb_DeadZone;

  /* End of MATLAB Function: '<S7>/k_psiSign' */

  /* Sum: '<S7>/Sum1' incorporates:
   *  Integrator: '<S7>/Integrator1'
   *  Product: '<S7>/Product'
   *  Sum: '<S7>/Sum'
   */
  ctrl_student_HIL_B.Sum1 = (rtb_Switch3_idx_0 + rtb_Switch3_idx_1) * rtb_K_psi
    + ctrl_student_HIL_X.Integrator1_CSTATE_g;

  /* Switch: '<S7>/Switch' */
  if (ctrl_student_HIL_B.Dropout_signaINl > ctrl_student_HIL_P.Switch_Threshold)
  {
    ctrl_student_HIL_B.Switch = ctrl_student_HIL_B.Integrator;
  } else {
    ctrl_student_HIL_B.Switch = ctrl_student_HIL_B.Sum1;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Sum: '<Root>/Sum1' */
  ctrl_student_HIL_B.Sum1_e = ctrl_student_HIL_B.u_in -
    ctrl_student_HIL_B.Switch;

  /* DeadZone: '<S9>/Dead Zone' */
  if (ctrl_student_HIL_B.PosXRight > ctrl_student_HIL_P.DeadZone_End) {
    rtb_DeadZone = ctrl_student_HIL_B.PosXRight -
      ctrl_student_HIL_P.DeadZone_End;
  } else if (ctrl_student_HIL_B.PosXRight >= ctrl_student_HIL_P.DeadZone_Start)
  {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone = ctrl_student_HIL_B.PosXRight -
      ctrl_student_HIL_P.DeadZone_Start;
  }

  /* End of DeadZone: '<S9>/Dead Zone' */

  /* Gain: '<S9>/Gain' incorporates:
   *  Sum: '<S9>/Sum'
   */
  rtb_Saturation = (ctrl_student_HIL_B.L2_continuous -
                    ctrl_student_HIL_B.R2_continuous) *
    ctrl_student_HIL_P.Gain_Gain;

  /* DeadZone: '<S9>/Dead Zone2' */
  if (rtb_Saturation > ctrl_student_HIL_P.DeadZone2_End) {
    rtb_Saturation -= ctrl_student_HIL_P.DeadZone2_End;
  } else if (rtb_Saturation >= ctrl_student_HIL_P.DeadZone2_Start) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation -= ctrl_student_HIL_P.DeadZone2_Start;
  }

  /* End of DeadZone: '<S9>/Dead Zone2' */

  /* MATLAB Function: '<S9>/Contoller_Map1' incorporates:
   *  Constant: '<S9>/Max_Global_Forces'
   */
  /* MATLAB Function 'joystick/Contoller_Map1': '<S29>:1' */
  if (ctrl_student_HIL_B.CurrentMode == 2.0) {
    /* '<S29>:1:3' */
    /* '<S29>:1:4' */
    ctrl_student_HIL_B.tau_surge = rtb_DeadZone *
      ctrl_student_HIL_P.Max_Global_Forces_Value[0];

    /* '<S29>:1:5' */
    ctrl_student_HIL_B.tau_sway = 0.0;

    /* '<S29>:1:6' */
    ctrl_student_HIL_B.tau_yaw = rtb_Saturation *
      ctrl_student_HIL_P.Max_Global_Forces_Value[3];
  } else {
    /* '<S29>:1:8' */
    ctrl_student_HIL_B.tau_surge = rtb_DeadZone *
      ctrl_student_HIL_P.Max_Global_Forces_Value[0];

    /* DeadZone: '<S9>/Dead Zone1' incorporates:
     *  Constant: '<S9>/Max_Global_Forces'
     */
    /* '<S29>:1:9' */
    if (ctrl_student_HIL_B.PosYRight > ctrl_student_HIL_P.DeadZone1_End) {
      rtb_DeadZone = ctrl_student_HIL_B.PosYRight -
        ctrl_student_HIL_P.DeadZone1_End;
    } else if (ctrl_student_HIL_B.PosYRight >=
               ctrl_student_HIL_P.DeadZone1_Start) {
      rtb_DeadZone = 0.0;
    } else {
      rtb_DeadZone = ctrl_student_HIL_B.PosYRight -
        ctrl_student_HIL_P.DeadZone1_Start;
    }

    /* End of DeadZone: '<S9>/Dead Zone1' */
    ctrl_student_HIL_B.tau_sway = rtb_DeadZone *
      ctrl_student_HIL_P.Max_Global_Forces_Value[1];

    /* '<S29>:1:10' */
    ctrl_student_HIL_B.tau_yaw = rtb_Saturation *
      ctrl_student_HIL_P.Max_Global_Forces_Value[2];
  }

  /* End of MATLAB Function: '<S9>/Contoller_Map1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Integrator: '<S3>/Integrator' */
  ctrl_student_HIL_B.Integrator_c = ctrl_student_HIL_X.Integrator_CSTATE_f;

  /* Switch: '<Root>/Switch2' */
  if (ctrl_student_HIL_B.Dropout_signaINl > ctrl_student_HIL_P.Switch2_Threshold)
  {
    rtb_DeadZone = ctrl_student_HIL_B.Integrator_c;
  } else {
    rtb_DeadZone = ctrl_student_HIL_B.psi_in;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* Sum: '<S5>/Sum3' */
  ctrl_student_HIL_B.Sum3 = ctrl_student_HIL_B.Psi_d - rtb_DeadZone;

  /* Sum: '<S5>/Sum5' incorporates:
   *  Constant: '<S5>/k_I'
   *  Constant: '<S5>/k_P'
   *  Integrator: '<S5>/Integrator'
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   */
  ctrl_student_HIL_B.Sum5 = ctrl_student_HIL_P.k_P_Value *
    ctrl_student_HIL_B.Sum3 + ctrl_student_HIL_X.Integrator_CSTATE_d *
    ctrl_student_HIL_P.k_I_Value;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtTau_preInport1' */
  ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp[0] =
    ctrl_student_HIL_B.tau_surge;
  ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp[1] =
    ctrl_student_HIL_B.tau_sway;

  /* Switch: '<Root>/Switch1' */
  if (ctrl_student_HIL_B.CaseSwitch > ctrl_student_HIL_P.Switch1_Threshold_j) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtTau_preInport1' */
    ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp[2] =
      ctrl_student_HIL_B.Sum5;
  } else {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtTau_preInport1' */
    ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp[2] =
      ctrl_student_HIL_B.tau_yaw;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* MATLAB Function: '<S11>/calcR(psi) ' */
  /* MATLAB Function 'safety zone /calcR(psi) ': '<S37>:1' */
  /* '<S37>:1:3' */
  rtb_R[0] = cos(rtb_Switch3_idx_2);
  rtb_R[3] = -sin(rtb_Switch3_idx_2);
  rtb_R[6] = 0.0;
  rtb_R[1] = sin(rtb_Switch3_idx_2);
  rtb_R[4] = cos(rtb_Switch3_idx_2);
  rtb_R[7] = 0.0;
  rtb_R[2] = 0.0;
  rtb_R[5] = 0.0;
  rtb_R[8] = 1.0;

  /* Product: '<S11>/Product' */
  /* MATLAB Function 'safety zone /MATLAB Function1': '<S35>:1' */
  /* '<S35>:1:2' */
  for (X = 0; X < 3; X++) {
    rtb_Product_j[X] = rtb_R[X + 6] *
      ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp[2] + (rtb_R[X + 3] *
      ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp[1] + rtb_R[X] *
      ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp[0]);
  }

  /* End of Product: '<S11>/Product' */

  /* MATLAB Function: '<S11>/safety check' incorporates:
   *  Constant: '<Root>/Lim'
   */
  /* MATLAB Function 'safety zone /safety check': '<S38>:1' */
  /* safety_sig=[0;0;0;0];%orginal safety signal */
  /* lim=[40.00;0;6.45;0];%space limitation [x_max;x_min;y_max;y_min] */
  if (rtb_Switch3_idx_0 >= ctrl_student_HIL_P.lim[0]) {
    /* '<S38>:1:6' */
    /* '<S38>:1:7' */
    rtb_DeadZone = 1.0;

    /* '<S38>:1:8' */
    rtb_Saturation = 0.0;
  } else if (rtb_Switch3_idx_0 <= ctrl_student_HIL_P.lim[1]) {
    /* '<S38>:1:9' */
    /* '<S38>:1:10' */
    rtb_Saturation = 1.0;

    /* '<S38>:1:11' */
    rtb_DeadZone = 0.0;
  } else {
    /* '<S38>:1:13' */
    rtb_DeadZone = 0.0;

    /* '<S38>:1:14' */
    rtb_Saturation = 0.0;
  }

  if (rtb_Switch3_idx_1 > ctrl_student_HIL_P.lim[2]) {
    /* '<S38>:1:16' */
    /* '<S38>:1:17' */
    rtb_safety_sig_3 = 1.0;

    /* '<S38>:1:18' */
    rtb_safety_sig_4 = 0.0;
  } else if (rtb_Switch3_idx_1 < ctrl_student_HIL_P.lim[3]) {
    /* '<S38>:1:19' */
    /* '<S38>:1:20' */
    rtb_safety_sig_4 = 1.0;

    /* '<S38>:1:21' */
    rtb_safety_sig_3 = 0.0;
  } else {
    /* '<S38>:1:24' */
    rtb_safety_sig_3 = 0.0;

    /* '<S38>:1:25' */
    rtb_safety_sig_4 = 0.0;
  }

  /* End of MATLAB Function: '<S11>/safety check' */
  /*  safety_sig_1=safety_sig(1); */
  /*  safety_sig_2=safety_sig(2); */
  /* safety_sig_3=safety_sig(3); */
  /* safety_sig_4=safety_sig(4); */

  /* Product: '<S11>/Product2' incorporates:
   *  SignalConversion: '<S11>/TmpSignal ConversionAtProduct2Inport2'
   */
  for (X = 0; X < 3; X++) {
    rtb_Switch[X] = rtb_R[X + 6] * ctrl_student_HIL_B.r_in + (rtb_R[X + 3] *
      ctrl_student_HIL_B.v_in + rtb_R[X] * ctrl_student_HIL_B.u_in);
  }

  /* End of Product: '<S11>/Product2' */

  /* MATLAB Function: '<S11>/Safety Act' incorporates:
   *  Constant: '<Root>/K'
   */
  /* MATLAB Function 'safety zone /Safety Act': '<S36>:1' */
  /* K=[1;1];     */
  if ((rtb_DeadZone == 0.0) && (rtb_Saturation == 0.0) && (rtb_safety_sig_3 ==
       0.0) && (rtb_safety_sig_4 == 0.0)) {
    /* '<S36>:1:7' */
    /* Check to see if intervention is requiered */
    /* '<S36>:1:9' */
    rtb_switch_sig = 0.0;

    /* Intervention is NOT requiered */
    /* '<S36>:1:10' */
    rtb_DeadZone = rtb_Product_j[0];

    /* '<S36>:1:11' */
    rtb_Saturation = rtb_Product_j[1];

    /* disp('Flag 0.0 All OK - No safety sig'); */
  } else {
    /* '<S36>:1:14' */
    rtb_switch_sig = 1.0;

    /* Intervention IS requiered */
    if ((rtb_DeadZone == 1.0) || (rtb_Saturation == 1.0)) {
      /* '<S36>:1:16' */
      /* Problem in X dir */
      /* disp('Flag 1.0 Problem in x'); */
      if (rtb_Product_j[0] == 0.0) {
        /* '<S36>:1:18' */
        /* Check if inputforce fore is zero or correct, (but the velocity might not be) */
        /* Perhaps a proprtional gain depending on the velocity? */
        if ((rtb_Switch[0] < 0.0) && (rtb_Saturation == 1.0)) {
          /* '<S36>:1:20' */
          /* '<S36>:1:21' */
          rtb_DeadZone = ctrl_student_HIL_P.K[0] * -rtb_Switch[0];

          /* disp('Flag 1.1 (x - tau=0 - Negative vel + to low x pos -> thrust =-vel*K_1)'); */
        } else if ((rtb_Switch[0] > 0.0) && (rtb_DeadZone == 1.0)) {
          /* '<S36>:1:23' */
          /* '<S36>:1:24' */
          rtb_DeadZone = ctrl_student_HIL_P.K[0] * -rtb_Switch[0];

          /* disp('Flag 1.2 (x - tau=0 - Positive vel + to high x pos -> thrust =-vel*K_1)'); */
        } else {
          /* '<S36>:1:27' */
          rtb_DeadZone = ctrl_student_HIL_P.K[0] * rtb_Switch[0];

          /* disp('Flag 1.3 (x - tau=0 - Positive vel + to low x pos / Negative vel + to highx pos -> keep current trust)'); */
        }

        /* thrust_out=[ThrustX;joyStick(2);joyStick(3)]; */
      } else if ((rtb_Product_j[0] > 0.0) && (rtb_Saturation == 1.0)) {
        /* '<S36>:1:32' */
        /* X cord to small, but thrust right way */
        /* '<S36>:1:33' */
        rtb_DeadZone = rtb_Product_j[0];

        /* thrust_out=[joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 1.4 (x - Positive thrust + to low x post -> keep current trust)'); */
      } else if ((rtb_Product_j[0] < 0.0) && (rtb_DeadZone == 1.0)) {
        /* '<S36>:1:36' */
        /* X cord to large, but thrust right way */
        /* '<S36>:1:37' */
        rtb_DeadZone = rtb_Product_j[0];

        /* thrust_out=[joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 1.5 (x - Negative thrust + to high x post -> Keep current trust)'); */
      } else {
        /* '<S36>:1:41' */
        rtb_DeadZone = -rtb_Product_j[0];

        /* thrust_out=[-joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 1.6 (x - Negative thrust + to low x post / Positive thrust + to high x post -> reverse trust)'); */
      }

      /* If */
    } else {
      /* '<S36>:1:46' */
      rtb_DeadZone = rtb_Product_j[0];
    }

    /* IF   */
    if ((rtb_safety_sig_3 == 1.0) || (rtb_safety_sig_4 == 1.0)) {
      /* '<S36>:1:49' */
      /* Problem in X dir%Problem in Y dir */
      /* disp('Flag 2.0 Problem in y'); */
      if (rtb_Product_j[1] == 0.0) {
        /* '<S36>:1:51' */
        /* Check if inputforce fore is zero or correct */
        /* Perhaps a proprtional gain depending on the velocity?   */
        if ((rtb_Switch[1] > 0.0) && (rtb_safety_sig_3 == 1.0)) {
          /* '<S36>:1:53' */
          /* '<S36>:1:54' */
          rtb_Saturation = ctrl_student_HIL_P.K[1] * -rtb_Switch[1];

          /* disp('Flag 2.1 (y - tau=0 - Negative vel + to low y pos -> thrust =-vel*K_2)'); */
        } else if ((rtb_Switch[1] < 0.0) && (rtb_safety_sig_4 == 1.0)) {
          /* '<S36>:1:56' */
          /* '<S36>:1:57' */
          rtb_Saturation = ctrl_student_HIL_P.K[1] * -rtb_Switch[1];

          /* disp('Flag 2.2 (y - tau=0 - Positive vel + to high y pos -> thrust =-vel*K_2)'); */
        } else {
          /* '<S36>:1:60' */
          rtb_Saturation = ctrl_student_HIL_P.K[1] * rtb_Switch[1];

          /* disp('Flag 2.3 (y - tau=0 - Positive vel + to low y pos / Negative vel + to high y pos -> keep current trust)'); */
        }

        /* IF */
        /* thrust_out=[joyStick(1);ThrustY;joyStick(3)]; */
      } else if ((rtb_Product_j[1] > 0.0) && (rtb_safety_sig_4 == 1.0)) {
        /* '<S36>:1:65' */
        /* Y cord to small */
        /* '<S36>:1:66' */
        rtb_Saturation = rtb_Product_j[1];

        /* thrust_out=[joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 2.4 (y - Positive thrust + to low y post -> keep current trust)'); */
      } else if ((rtb_Product_j[1] < 0.0) && (rtb_safety_sig_3 == 1.0)) {
        /* '<S36>:1:70' */
        /* Y cord to large */
        /* '<S36>:1:71' */
        rtb_Saturation = rtb_Product_j[1];

        /* thrust_out=[joyStick(1);joyStick(2);joyStick(3)]; */
        /* disp('Flag 2.5 (y - Negative thrust + to high y post -> Keep current trust)'); */
      } else {
        /* '<S36>:1:76' */
        rtb_Saturation = -rtb_Product_j[1];

        /* thrust_out=[joyStick(1);-joyStick(2);joyStick(3)]; */
        /* disp('Flag 2.6 (y - Negative thrust + to low y post / Positive thrust + to high y post -> reverse trust)'); */
      }

      /* IF */
    } else {
      /* '<S36>:1:82' */
      rtb_Saturation = rtb_Product_j[1];
    }

    /* IF */
  }

  /* Switch: '<S11>/Switch' incorporates:
   *  MATLAB Function: '<S11>/Safety Act'
   */
  /* IF */
  /* '<S36>:1:86' */
  /* Function */
  if (rtb_switch_sig > ctrl_student_HIL_P.Switch_Threshold_n) {
    rtb_Switch[0] = rtb_DeadZone;
    rtb_Switch[1] = rtb_Saturation;
  } else {
    rtb_Switch[0] = rtb_Product_j[0];
    rtb_Switch[1] = rtb_Product_j[1];
  }

  rtb_Switch[2] = rtb_Product_j[2];

  /* End of Switch: '<S11>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S11>/Memory' */
    ctrl_student_HIL_B.Memory_n = ctrl_student_HIL_DW.Memory_PreviousInput_e;
  }

  /* MATLAB Function: '<S11>/KillSwitch' incorporates:
   *  Constant: '<Root>/Lim2'
   *  MATLAB Function: '<S11>/Safety Act'
   */
  /* MATLAB Function 'safety zone /KillSwitch': '<S33>:1' */
  if (ctrl_student_HIL_B.Memory_n == 1.0) {
    /* '<S33>:1:3' */
    /* '<S33>:1:4' */
    X = 1;

    /* disp('Flag 3.0 KILL - previous kill'); */
  } else {
    if (rtb_Switch3_idx_0 >= ctrl_student_HIL_P.lim_2[0]) {
      /* '<S33>:1:7' */
      /* '<S33>:1:9' */
      X = 1;

      /* disp('Flag 3.1 KILL - large x'); */
    } else if (rtb_Switch3_idx_0 <= ctrl_student_HIL_P.lim_2[1]) {
      /* '<S33>:1:11' */
      /* '<S33>:1:13' */
      X = 1;

      /* disp('Flag 3.2 KILL - small x'); */
    } else {
      /* '<S33>:1:17' */
      X = 0;
    }

    /* IF */
    if (rtb_Switch3_idx_1 >= ctrl_student_HIL_P.lim_2[2]) {
      /* '<S33>:1:19' */
      /* '<S33>:1:20' */
      X = 1;

      /* disp('Flag 3.3 KILL - large y'); */
    } else {
      if (rtb_Switch3_idx_1 <= ctrl_student_HIL_P.lim_2[3]) {
        /* '<S33>:1:22' */
        /* '<S33>:1:23' */
        X = 1;

        /* disp('Flag 3.4 KILL - small y'); */
      }
    }

    /* IF */
  }

  /*  IF */
  if (X == 1) {
    /* '<S33>:1:35' */
    /* '<S33>:1:36' */
    rtb_DeadZone = 0.0;
    rtb_Switch3_idx_0 = 0.0;
    rtb_Switch3_idx_1 = 0.0;
  } else {
    /* '<S33>:1:38' */
    rtb_DeadZone = rtb_Switch[0];
    rtb_Switch3_idx_0 = rtb_Switch[1];
    rtb_Switch3_idx_1 = rtb_Product_j[2];
  }

  /* IF */
  /* Function */

  /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S11>/KillSwitch'
   */
  /* MATLAB Function 'safety zone /MATLAB Function': '<S34>:1' */
  if (ctrl_student_HIL_B.SZ_ResetKill == 1.0) {
    /* '<S34>:1:3' */
    /* '<S34>:1:4' */
    ctrl_student_HIL_B.kill_signal = 0.0;
  } else {
    /* '<S34>:1:6' */
    ctrl_student_HIL_B.kill_signal = X;
  }

  /* End of MATLAB Function: '<S11>/MATLAB Function' */

  /* Switch: '<S11>/Switch2' */
  if (!(ctrl_student_HIL_B.SZ_Owerwrite > ctrl_student_HIL_P.Switch2_Threshold_p))
  {
    /* Switch: '<S11>/Switch1' */
    if (ctrl_student_HIL_B.kill_signal > ctrl_student_HIL_P.Switch1_Threshold) {
      rtb_Product_j[0] = rtb_DeadZone;
      rtb_Product_j[1] = rtb_Switch3_idx_0;
      rtb_Product_j[2] = rtb_Switch3_idx_1;
    } else {
      rtb_Product_j[0] = rtb_Switch[0];
      rtb_Product_j[1] = rtb_Switch[1];
      rtb_Product_j[2] = rtb_Switch[2];
    }

    /* End of Switch: '<S11>/Switch1' */
  }

  /* End of Switch: '<S11>/Switch2' */

  /* Product: '<S11>/Product1' incorporates:
   *  MATLAB Function: '<S11>/MATLAB Function1'
   */
  for (X = 0; X < 3; X++) {
    rtb_Switch[X] = rtb_R[3 * X + 2] * rtb_Product_j[2] + (rtb_R[3 * X + 1] *
      rtb_Product_j[1] + rtb_R[3 * X] * rtb_Product_j[0]);
  }

  /* End of Product: '<S11>/Product1' */

  /* MATLAB Function: '<S8>/Force Allocation1' */
  /* MATLAB Function 'ThrustAllocationAndSaturation/Force Allocation1': '<S25>:1' */
  if (ctrl_student_HIL_B.CurrentMode == 2.0) {
    /* '<S25>:1:5' */
    /* 2DOF stick control */
    /* '<S25>:1:7' */
    rtb_Switch3_idx_1 = rtb_Switch[0] / 2.0;

    /* '<S25>:1:8' */
    rtb_switch_sig = rtb_Switch3_idx_1;

    /* '<S25>:1:9' */
    rtb_Switch3_idx_0 = rtb_Switch[1] / 2.0;

    /* '<S25>:1:10' */
  } else {
    /* 3 DOF stick control, no BT */
    /* '<S25>:1:13' */
    rtb_DeadZone = rtb_Switch[0] / 2.0;

    /* '<S25>:1:16' */
    rtb_Switch3_idx_0 = rtb_Switch[1] / 2.0;

    /* '<S25>:1:19' */
    rtb_Saturation = 0.5 * rtb_Switch[2] / 0.062;

    /* '<S25>:1:20' */
    /* '<S25>:1:22' */
    rtb_safety_sig_3 = rtb_Switch3_idx_0 * 0.4575 / 0.062;

    /* '<S25>:1:23' */
    /* '<S25>:1:25' */
    rtb_Switch3_idx_1 = (rtb_DeadZone + rtb_Saturation) + rtb_safety_sig_3;

    /* '<S25>:1:26' */
    rtb_switch_sig = (rtb_DeadZone + -rtb_Saturation) + -rtb_safety_sig_3;

    /* '<S25>:1:27' */
    /* '<S25>:1:28' */
  }

  /* MATLAB Function: '<S8>/Force2Control' incorporates:
   *  Constant: '<S8>/Actuator_Sat_Forces'
   *  MATLAB Function: '<S8>/Force Allocation1'
   */
  /* original equations from 30/1/2017 */
  /*  f_vspx=tau_surge; */
  /*  f_vspy=(tau_yaw-tau_sway*l_bt)/(l_vsp-l_bt); */
  /*  f_bt=tau_sway-f_vspy; */
  /* tau_yaw = f_vspy*l_vsp+f_bt*l_bt */
  /* tau_sway=f_vspy+f_bt */
  /* solve for f_bt and f_vspy */
  /* MATLAB Function 'ThrustAllocationAndSaturation/Force2Control': '<S26>:1' */
  if (ctrl_student_HIL_B.CurrentMode == 2.0) {
    /* '<S26>:1:3' */
    /* '<S26>:1:4' */
    rtb_DeadZone = sqrt(rtb_Switch3_idx_1 * rtb_Switch3_idx_1 +
                        rtb_Switch3_idx_0 * rtb_Switch3_idx_0) /
      ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0];

    /* '<S26>:1:5' */
    rtb_Saturation = rtb_DeadZone;

    /* '<S26>:1:6' */
    rtb_safety_sig_3 = rt_atan2d_snf(rtb_Switch3_idx_0, rtb_Switch3_idx_1);

    /* '<S26>:1:7' */
    ctrl_student_HIL_B.alpha2 = rtb_safety_sig_3;
  } else {
    /* '<S26>:1:9' */
    rtb_DeadZone = sqrt(rtb_Switch3_idx_1 * rtb_Switch3_idx_1 +
                        rtb_Switch3_idx_0 * rtb_Switch3_idx_0) /
      ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0];

    /* '<S26>:1:10' */
    rtb_Saturation = sqrt(rtb_switch_sig * rtb_switch_sig + rtb_Switch3_idx_0 *
                          rtb_Switch3_idx_0) /
      ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0];

    /* '<S26>:1:11' */
    rtb_safety_sig_3 = rt_atan2d_snf(rtb_Switch3_idx_0, rtb_Switch3_idx_1);

    /* '<S26>:1:12' */
    ctrl_student_HIL_B.alpha2 = rt_atan2d_snf(rtb_Switch3_idx_0, rtb_switch_sig);
  }

  if (fabs(rtb_DeadZone) > 1.0) {
    /* '<S26>:1:15' */
    /* '<S26>:1:16' */
    rtb_safety_sig_4 = 1.0 / fabs(rtb_DeadZone);

    /* '<S26>:1:17' */
  } else if (fabs(rtb_Saturation) > 1.0) {
    /* '<S26>:1:18' */
    /* '<S26>:1:19' */
    rtb_safety_sig_4 = 1.0 / fabs(rtb_Saturation);

    /* '<S26>:1:20' */
  } else {
    /* '<S26>:1:22' */
    rtb_safety_sig_4 = 1.0;

    /* '<S26>:1:23' */
  }

  /* '<S26>:1:26' */
  ctrl_student_HIL_B.u_vsp1 = rtb_DeadZone * rtb_safety_sig_4;

  /* '<S26>:1:27' */
  ctrl_student_HIL_B.u_vsp2 = rtb_Saturation * rtb_safety_sig_4;

  /* '<S26>:1:28' */
  ctrl_student_HIL_B.alpha1 = rtb_safety_sig_3;

  /* End of MATLAB Function: '<S8>/Force2Control' */

  /* MATLAB Function: '<S8>/actForces1' incorporates:
   *  Constant: '<S8>/Actuator_Sat_Forces'
   *  SignalConversion: '<S28>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'ThrustAllocationAndSaturation/actForces1': '<S28>:1' */
  /* '<S28>:1:3' */
  rtb_DeadZone = ctrl_student_HIL_B.u_vsp1 *
    ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0] * cos
    (ctrl_student_HIL_B.alpha1);

  /* '<S28>:1:4' */
  rtb_Saturation = ctrl_student_HIL_B.u_vsp2 *
    ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0] * cos
    (ctrl_student_HIL_B.alpha2);

  /* '<S28>:1:5' */
  rtb_safety_sig_3 = ctrl_student_HIL_B.u_vsp1 *
    ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0] * sin
    (ctrl_student_HIL_B.alpha1);

  /* '<S28>:1:6' */
  rtb_safety_sig_4 = ctrl_student_HIL_B.u_vsp2 *
    ctrl_student_HIL_P.Actuator_Sat_Forces_Value[0] * sin
    (ctrl_student_HIL_B.alpha2);

  /* '<S28>:1:7' */
  /* '<S28>:1:9' */
  ctrl_student_HIL_B.tauAct[0] = rtb_DeadZone + rtb_Saturation;
  ctrl_student_HIL_B.tauAct[1] = rtb_safety_sig_3 + rtb_safety_sig_4;
  ctrl_student_HIL_B.tauAct[2] = (rtb_DeadZone - rtb_Saturation) * 0.062 -
    (rtb_safety_sig_3 + rtb_safety_sig_4) * 0.4575;

  /* Sum: '<Root>/Sum' */
  ctrl_student_HIL_B.Sum = ctrl_student_HIL_B.psi_in -
    ctrl_student_HIL_B.Integrator_c;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Integrator: '<S10>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_student_HIL_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator_CSTATE_b[0] =
        (ctrl_student_HIL_P.Integrator_IC_m[0]);
      ctrl_student_HIL_X.Integrator_CSTATE_b[1] =
        (ctrl_student_HIL_P.Integrator_IC_m[1]);
      ctrl_student_HIL_X.Integrator_CSTATE_b[2] =
        (ctrl_student_HIL_P.Integrator_IC_m[2]);
    }
  }

  rtb_Integrator[0] = ctrl_student_HIL_X.Integrator_CSTATE_b[0];
  rtb_Integrator[1] = ctrl_student_HIL_X.Integrator_CSTATE_b[1];
  rtb_Integrator[2] = ctrl_student_HIL_X.Integrator_CSTATE_b[2];

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<Root>/bias'
   */
  ctrl_student_HIL_B.Sum_j = rtb_Integrator[2] + ctrl_student_HIL_P.bias_Value;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Sum: '<S7>/Sum2' incorporates:
   *  Gain: '<S7>/Gain'
   *  MATLAB Function: '<S7>/D_11(u)//M'
   *  MATLAB Function: '<S7>/Term3'
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product2'
   */
  /* MATLAB Function 'SurgeObserver/D_11(u)//M': '<S22>:1' */
  /* '<S22>:1:3' */
  /* '<S22>:1:6' */
  /* '<S22>:1:7' */
  /* MATLAB Function 'SurgeObserver/Term3': '<S23>:1' */
  /* '<S23>:1:3' */
  ctrl_student_HIL_B.Sum2 = (ctrl_student_HIL_P.Gain_Gain_d *
    ctrl_student_HIL_B.tauAct[0] - ((0.6555 - 0.3545 * fabs
    (ctrl_student_HIL_B.Sum1)) - ctrl_student_HIL_B.Sum1 *
    ctrl_student_HIL_B.Sum1 * -3.787) * ctrl_student_HIL_B.Sum1 / 16.79) - (cos
    (rtb_Switch3_idx_2) + sin(rtb_Switch3_idx_2)) * rtb_K_psi *
    ctrl_student_HIL_B.Sum1;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Clock: '<S27>/Clock' */
  rtb_Clock = ctrl_student_HIL_M->Timing.t[0];

  /* Step: '<S27>/Step' */
  if (ctrl_student_HIL_M->Timing.t[0] < ctrl_student_HIL_P.Ramp_start) {
    rtb_DeadZone = ctrl_student_HIL_P.Step_Y0;
  } else {
    rtb_DeadZone = ctrl_student_HIL_P.Ramp_slope;
  }

  /* End of Step: '<S27>/Step' */

  /* Sum: '<S27>/Output' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant1'
   *  Product: '<S27>/Product'
   *  Sum: '<S27>/Sum'
   */
  rtb_Saturation = (rtb_Clock - ctrl_student_HIL_P.Ramp_start) * rtb_DeadZone +
    ctrl_student_HIL_P.Ramp_X0;

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Saturation > ctrl_student_HIL_P.Saturation_UpperSat) {
    rtb_Saturation = ctrl_student_HIL_P.Saturation_UpperSat;
  } else {
    if (rtb_Saturation < ctrl_student_HIL_P.Saturation_LowerSat) {
      rtb_Saturation = ctrl_student_HIL_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant'
   */
  if (ctrl_student_HIL_B.TurnOffomega1 > ctrl_student_HIL_P.Switch_Threshold_k)
  {
    ctrl_student_HIL_B.Switch_i = ctrl_student_HIL_P.Constant_Value_i;
  } else {
    ctrl_student_HIL_B.Switch_i = rtb_Saturation;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  if (ctrl_student_HIL_B.TurnOffomega2 > ctrl_student_HIL_P.Switch1_Threshold_m)
  {
    ctrl_student_HIL_B.Switch1 = ctrl_student_HIL_P.Constant1_Value;
  } else {
    ctrl_student_HIL_B.Switch1 = rtb_Saturation;
  }

  /* End of Switch: '<S8>/Switch1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Sum: '<S8>/Sum' incorporates:
   *  MATLAB Function: '<S8>/Force Allocation1'
   */
  ctrl_student_HIL_B.Sum_m = rtb_Switch3_idx_1 + rtb_switch_sig;

  /* Sum: '<S8>/Sum1' incorporates:
   *  MATLAB Function: '<S8>/Force Allocation1'
   */
  ctrl_student_HIL_B.Sum1_p = rtb_Switch3_idx_0 + rtb_Switch3_idx_0;

  /* MATLAB Function: '<S10>/kinematics' */
  /* MATLAB Function 'physics_model/kinematics': '<S31>:1' */
  /* '<S31>:1:3' */
  /* '<S31>:1:5' */
  /* '<S31>:1:9' */
  tmp[0] = cos(rtb_Integrator1[2]);
  tmp[3] = -sin(rtb_Integrator1[2]);
  tmp[6] = 0.0;
  tmp[1] = sin(rtb_Integrator1[2]);
  tmp[4] = cos(rtb_Integrator1[2]);
  tmp[7] = 0.0;
  tmp[2] = 0.0;
  tmp[5] = 0.0;
  tmp[8] = 1.0;
  for (X = 0; X < 3; X++) {
    ctrl_student_HIL_B.eta_dot[X] = 0.0;
    ctrl_student_HIL_B.eta_dot[X] += tmp[X] * rtb_Integrator[0];
    ctrl_student_HIL_B.eta_dot[X] += tmp[X + 3] * rtb_Integrator[1];
    ctrl_student_HIL_B.eta_dot[X] += tmp[X + 6] * rtb_Integrator[2];
  }

  /* End of MATLAB Function: '<S10>/kinematics' */

  /* MATLAB Function: '<S10>/kinetics' */
  /* MATLAB Function 'physics_model/kinetics': '<S32>:1' */
  /* '<S32>:1:3' */
  /* '<S32>:1:4' */
  /* '<S32>:1:5' */
  /* '<S32>:1:7' */
  /* % MATRICES */
  /*  x_g  =  0.0460; % Table B.1 */
  /* % Added mass */
  /*  Table B.1 */
  /*  Table B.1 guestimate */
  /*  Table B.1 */
  /* % Total mass matrix */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S32>:1:33' */
  /* '<S32>:1:37' */
  /*  Y_r */
  /*  Y_rr */
  /*  Y_rv, Y_vr */
  /* '<S32>:1:43' */
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
  /* '<S32>:1:65' */
  /* '<S32>:1:66' */
  /* '<S32>:1:67' */
  /*  using abs(r) */
  /* '<S32>:1:70' */
  /* '<S32>:1:71' */
  /* From ItsLearning */
  /*  D    = [d_11 d_12 0 */
  /*          0    d_22 d_23 */
  /*          0    d_32 d_33]; */
  /* From Feb. 2017 lab manual. Agrees with Handbook of Marine Craft Hydro */
  /* '<S32>:1:79' */
  /* % CALCULATION */
  /* nu_dot = M\(tau-(C+D)*nu); */
  /* '<S32>:1:88' */
  tmp_0[0] = (0.6555 - 0.3545 * rtb_Integrator[0]) - rtb_Integrator[0] *
    rtb_Integrator[0] * -3.787;
  tmp_0[3] = 0.0;
  tmp_0[6] = 0.0;
  tmp_0[1] = 0.0;
  tmp_0[4] = ((1.33 - -2.776 * rtb_Integrator[1]) - rtb_Integrator[1] *
              rtb_Integrator[1] * -64.91) - -0.805 * fabs(rtb_Integrator[2]);
  tmp_0[7] = ((7.25 - -3.45 * fabs(rtb_Integrator[2])) - rtb_Integrator[2] *
              rtb_Integrator[2] * 0.0) - -0.845 * fabs(rtb_Integrator[1]);
  tmp_0[2] = 0.0;
  tmp_0[5] = ((-0.0 - -0.2088 * rtb_Integrator[1]) - rtb_Integrator[1] *
              rtb_Integrator[1] * 0.0) - 0.13 * fabs(rtb_Integrator[2]);
  tmp_0[8] = ((1.9 - -0.75 * fabs(rtb_Integrator[2])) - rtb_Integrator[2] *
              rtb_Integrator[2] * 0.0) - 0.08 * fabs(rtb_Integrator[1]);
  for (X = 0; X < 3; X++) {
    rtb_Switch[X] = tmp_0[X + 6] * rtb_Integrator[2] + (tmp_0[X + 3] *
      rtb_Integrator[1] + tmp_0[X] * rtb_Integrator[0]);
  }

  ctrl_student_HIL_B.nu_dot[0] = ctrl_student_HIL_B.tauAct[0] - rtb_Switch[0];
  ctrl_student_HIL_B.nu_dot[1] = (ctrl_student_HIL_B.tauAct[1] - rtb_Switch[1])
    - ctrl_student_HIL_B.nu_dot[0] * 0.0;
  ctrl_student_HIL_B.nu_dot[2] = ((ctrl_student_HIL_B.tauAct[2] - rtb_Switch[2])
    - ctrl_student_HIL_B.nu_dot[0] * 0.0) - ctrl_student_HIL_B.nu_dot[1] *
    0.026721040528887609;
  ctrl_student_HIL_B.nu_dot[2] /= 2.7351594526983325;
  ctrl_student_HIL_B.nu_dot[0] -= ctrl_student_HIL_B.nu_dot[2] * 0.0;
  ctrl_student_HIL_B.nu_dot[1] -= ctrl_student_HIL_B.nu_dot[2] *
    0.92962499999999992;
  ctrl_student_HIL_B.nu_dot[1] /= 34.79;
  ctrl_student_HIL_B.nu_dot[0] -= ctrl_student_HIL_B.nu_dot[1] * 0.0;
  ctrl_student_HIL_B.nu_dot[0] /= 26.79;

  /* End of MATLAB Function: '<S10>/kinetics' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }
}

/* Model update function */
void ctrl_student_HIL_update(void)
{
  /* Update for Integrator: '<S10>/Integrator1' */
  ctrl_student_HIL_DW.Integrator1_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S14>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_B.count;

    /* Update for RandomNumber: '<S20>/White Noise' */
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S21>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_j) * ctrl_student_HIL_P.WhiteNoise_StdDev_d
      + ctrl_student_HIL_P.WhiteNoise_Mean_h;

    /* Update for RandomNumber: '<S19>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_c) * ctrl_student_HIL_P.WhiteNoise_StdDev_g
      + ctrl_student_HIL_P.WhiteNoise_Mean_f;

    /* Update for Memory: '<S15>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_B.output[0];
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_B.output[1];
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_B.output[2];

    /* Update for Memory: '<S2>/Memory2' */
    ctrl_student_HIL_DW.Memory2_PreviousInput = ctrl_student_HIL_B.X_out;

    /* Update for Memory: '<S2>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput = ctrl_student_HIL_B.Y_out;

    /* Update for Memory: '<S2>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput = ctrl_student_HIL_B.Yaw_out;

    /* Update for Memory: '<S11>/Memory' */
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

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE = ctrl_student_HIL_B.nu_dot[0];

  /* Derivatives for Integrator: '<S10>/Integrator1' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE[0] = ctrl_student_HIL_B.eta_dot[0];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE[1] = ctrl_student_HIL_B.eta_dot[1];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE[2] = ctrl_student_HIL_B.eta_dot[2];
  }

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_g = ctrl_student_HIL_B.Sum2;

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = ctrl_student_HIL_B.Sum_j;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_d = ctrl_student_HIL_B.Sum3;

  /* Derivatives for Integrator: '<S10>/Integrator' */
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
  /* Start for InitialCondition: '<S7>/IC' */
  ctrl_student_HIL_B.IC = ctrl_student_HIL_P.IC_Value;
  ctrl_student_HIL_DW.IC_FirstOutputTime = true;

  /* Start for Constant: '<Root>/Constant2' */
  ctrl_student_HIL_B.Constant2[0] = ctrl_student_HIL_P.eta_dot_ini[0];
  ctrl_student_HIL_B.Constant2[1] = ctrl_student_HIL_P.eta_dot_ini[1];
  ctrl_student_HIL_B.Constant2[2] = ctrl_student_HIL_P.eta_dot_ini[2];
  ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE = ctrl_student_HIL_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S10>/Integrator1' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      ctrl_student_HIL_X.Integrator1_CSTATE[0] = 6.0;
      ctrl_student_HIL_X.Integrator1_CSTATE[1] = 5.0;
      ctrl_student_HIL_X.Integrator1_CSTATE[2] = 0.0;
    }

    ctrl_student_HIL_DW.Integrator1_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Memory: '<S14>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S20>/White Noise' */
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

    /* End of InitializeConditions for RandomNumber: '<S20>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S21>/White Noise' */
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

    /* End of InitializeConditions for RandomNumber: '<S21>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S19>/White Noise' */
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

    /* End of InitializeConditions for RandomNumber: '<S19>/White Noise' */

    /* InitializeConditions for Memory: '<S15>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_P.Hold_X0;

    /* InitializeConditions for Memory: '<S2>/Memory2' */
    ctrl_student_HIL_DW.Memory2_PreviousInput = ctrl_student_HIL_P.Memory2_X0;

    /* InitializeConditions for Memory: '<S2>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput = ctrl_student_HIL_P.Memory1_X0;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput = ctrl_student_HIL_P.Memory_X0;

    /* InitializeConditions for Integrator: '<S7>/Integrator1' */
    ctrl_student_HIL_X.Integrator1_CSTATE_g = ctrl_student_HIL_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<S3>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE_f = ctrl_student_HIL_P.Integrator_IC_e;

    /* InitializeConditions for Integrator: '<S5>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE_d = ctrl_student_HIL_P.Integrator_IC_h;

    /* InitializeConditions for Memory: '<S11>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_e = ctrl_student_HIL_P.Memory_X0_i;

    /* InitializeConditions for Integrator: '<S10>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE_b[0] =
      (ctrl_student_HIL_P.Integrator_IC_m[0]);
    ctrl_student_HIL_X.Integrator_CSTATE_b[1] =
      (ctrl_student_HIL_P.Integrator_IC_m[1]);
    ctrl_student_HIL_X.Integrator_CSTATE_b[2] =
      (ctrl_student_HIL_P.Integrator_IC_m[2]);

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
  ctrl_student_HIL_M->Sizes.numContStates = (10);/* Number of continuous states */
  ctrl_student_HIL_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_M->Sizes.numBlocks = (190);/* Number of blocks */
  ctrl_student_HIL_M->Sizes.numBlockIO = (73);/* Number of block outputs */
  ctrl_student_HIL_M->Sizes.numBlockPrms = (436);/* Sum of parameter "widths" */
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 38:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 39:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 38:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 39:
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

  // y_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // x_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // psi_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.psi_in, 0, data[index++], 0, 0);
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

  // u_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.u_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // r_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.r_in, 0, data[index++], 0, 0);
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

  // joystick/CurrentMode
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.CurrentMode, 0, data[index++], 0,
      0);
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

  // joystick/Select
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Select, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Psi_d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Psi_d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // CaseSwitch
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.CaseSwitch, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // v_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.v_in, 0, data[index++], 0, 0);
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
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 31;
}

double ni_extout[35];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // u_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,0,0,
      0);
  } else {
    index += 1;
  }

  // u_real  : Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_in,0,0,0);
  } else {
    index += 1;
  }

  // u_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1_e,0,0,
      0);
  } else {
    index += 1;
  }

  // eta_noise: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI,0,18,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI,1,18,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI,2,18,0);
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
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp,0,18,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp,1,18,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp,2,18,0);
  } else {
    index += 3;
  }

  // Tau_post: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,0,18,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,1,18,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,2,18,
      0);
  } else {
    index += 3;
  }

  // psi_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,0,38,0);
  } else {
    index += 1;
  }

  // psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.Integrator_c,0,38,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,0,18,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,2,18,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,1,18,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_P.eta_dot_ini,
      2,18,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_P.eta_dot_ini,
      0,18,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_P.eta_dot_ini,
      1,18,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.reset,0,0,0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/u_BT: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant2_Value,0,0,0);
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
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_i,0,
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
      (&ctrl_student_HIL_P.Constant3_Value,0,0,0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/f_vspx: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum_m,0,0,0);
  } else {
    index += 1;
  }

  // ThrustAllocationAndSaturation/ f_vspy: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1_p,0,0,
      0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 35;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch,0,0,0);

  // u_real  : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_in,0,0,0);

  // u_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1_e,0,0,0);

  // eta_noise: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI,0,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI,1,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_noiseI,2,18,0);

  // Dropout_signaOUT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.Dropout_signaINl,0,0,0);

  // joystick/tau_yaw: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau_yaw,0,0,0);

  // joystick/tau_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau_surge,0,0,
    0);

  // joystick/tau_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau_sway,0,0,
    0);

  // Tau_pre: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp,0,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp,1,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAtTau_preInp,2,18,0);

  // Tau_post: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,0,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,1,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,2,18,0);

  // psi_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,0,38,0);

  // psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator_c,
    0,38,0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,0,18,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,2,18,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tauAct,1,18,0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_P.eta_dot_ini,2,
    18,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_P.eta_dot_ini,0,
    18,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_P.eta_dot_ini,1,
    18,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.reset,0,0,0);

  // ThrustAllocationAndSaturation/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant2_Value,0,0,0);

  // ThrustAllocationAndSaturation/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_vsp1,0,0,0);

  // ThrustAllocationAndSaturation/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_vsp2,0,0,0);

  // ThrustAllocationAndSaturation/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha1,0,0,0);

  // ThrustAllocationAndSaturation/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha2,0,0,0);

  // ThrustAllocationAndSaturation/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_i,0,0,
    0);

  // ThrustAllocationAndSaturation/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1,0,0,0);

  // ThrustAllocationAndSaturation/f_bt: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant3_Value,0,0,0);

  // ThrustAllocationAndSaturation/f_vspx: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum_m,0,0,0);

  // ThrustAllocationAndSaturation/ f_vspy: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1_p,0,0,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_student_hil/K/Value", offsetof(P_ctrl_student_HIL_T, K), 24, 2, 2,
    0, 0 },

  { 1, "ctrl_student_hil/Constant2/Value", offsetof(P_ctrl_student_HIL_T,
    eta_dot_ini), 22, 3, 2, 2, 0 },

  { 2,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, eta_dot_ini), 22, 3, 2, 4, 0 },

  { 3, "ctrl_student_hil/Lim/Value", offsetof(P_ctrl_student_HIL_T, lim), 23, 4,
    2, 6, 0 },

  { 4, "ctrl_student_hil/Lim2/Value", offsetof(P_ctrl_student_HIL_T, lim_2), 23,
    4, 2, 8, 0 },

  { 5, "ctrl_student_hil/ThrustAllocationAndSaturation/Ramp/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Ramp_X0), 38, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/ThrustAllocationAndSaturation/Ramp/Step/After",
    offsetof(P_ctrl_student_HIL_T, Ramp_slope), 38, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil/ThrustAllocationAndSaturation/Ramp/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Ramp_start), 38, 1, 2, 14, 0 },

  { 8, "ctrl_student_hil/ThrustAllocationAndSaturation/Ramp/Step/Time", offsetof
    (P_ctrl_student_HIL_T, Ramp_start), 38, 1, 2, 16, 0 },

  { 9, "ctrl_student_hil/safety zone /Switch1/Threshold", offsetof
    (P_ctrl_student_HIL_T, Switch1_Threshold), 38, 1, 2, 18, 0 },

  { 10, "ctrl_student_hil/SurgeObserver/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC), 38, 1, 2, 20, 0 },

  { 11, "ctrl_student_hil/SurgeObserver/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value), 38, 1, 2, 22, 0 },

  { 12, "ctrl_student_hil/SurgeObserver/IC/Value", offsetof(P_ctrl_student_HIL_T,
    IC_Value), 38, 1, 2, 24, 0 },

  { 13, "ctrl_student_hil/Noise generator/Step size/Value", offsetof
    (P_ctrl_student_HIL_T, Stepsize_Value), 38, 1, 2, 26, 0 },

  { 14, "ctrl_student_hil/Noise generator/Downsamplesignal/counter/X0", offsetof
    (P_ctrl_student_HIL_T, counter_X0), 38, 1, 2, 28, 0 },

  { 15, "ctrl_student_hil/Constant/Value", offsetof(P_ctrl_student_HIL_T,
    Constant_Value_d), 38, 1, 2, 30, 0 },

  { 16,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean), 38, 1, 2, 32, 0 },

  { 17,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev), 38, 1, 2, 34, 0 },

  { 18,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed), 38, 1, 2, 36, 0 },

  { 19,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_h), 38, 1, 2, 38, 0 },

  { 20,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_d), 38, 1, 2, 40, 0 },

  { 21,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_b), 38, 1, 2, 42, 0 },

  { 22,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_f), 38, 1, 2, 44, 0 },

  { 23,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_g), 38, 1, 2, 46, 0 },

  { 24,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_l), 38, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil/Noise generator/Sample & hold/Hold/X0", offsetof
    (P_ctrl_student_HIL_T, Hold_X0), 38, 1, 2, 50, 0 },

  { 26, "ctrl_student_hil/Dropout_simulator/Memory2/X0", offsetof
    (P_ctrl_student_HIL_T, Memory2_X0), 38, 1, 2, 52, 0 },

  { 27, "ctrl_student_hil/Dropout_simulator/Memory1/X0", offsetof
    (P_ctrl_student_HIL_T, Memory1_X0), 38, 1, 2, 54, 0 },

  { 28, "ctrl_student_hil/Dropout_simulator/Memory/X0", offsetof
    (P_ctrl_student_HIL_T, Memory_X0), 38, 1, 2, 56, 0 },

  { 29, "ctrl_student_hil/Switch3/Threshold", offsetof(P_ctrl_student_HIL_T,
    Switch3_Threshold), 38, 1, 2, 58, 0 },

  { 30, "ctrl_student_hil/SurgeObserver/Integrator1/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator1_IC), 38, 1, 2, 60, 0 },

  { 31, "ctrl_student_hil/SurgeObserver/Switch/Threshold", offsetof
    (P_ctrl_student_HIL_T, Switch_Threshold), 38, 1, 2, 62, 0 },

  { 32, "ctrl_student_hil/joystick/Max_Global_Forces/Value", offsetof
    (P_ctrl_student_HIL_T, Max_Global_Forces_Value), 27, 4, 2, 64, 0 },

  { 33, "ctrl_student_hil/joystick/Dead Zone/LowerValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone_Start), 38, 1, 2, 66, 0 },

  { 34, "ctrl_student_hil/joystick/Dead Zone/UpperValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone_End), 38, 1, 2, 68, 0 },

  { 35, "ctrl_student_hil/joystick/Dead Zone1/LowerValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone1_Start), 38, 1, 2, 70, 0 },

  { 36, "ctrl_student_hil/joystick/Dead Zone1/UpperValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone1_End), 38, 1, 2, 72, 0 },

  { 37, "ctrl_student_hil/joystick/Gain/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain_Gain), 38, 1, 2, 74, 0 },

  { 38, "ctrl_student_hil/joystick/Dead Zone2/LowerValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone2_Start), 38, 1, 2, 76, 0 },

  { 39, "ctrl_student_hil/joystick/Dead Zone2/UpperValue", offsetof
    (P_ctrl_student_HIL_T, DeadZone2_End), 38, 1, 2, 78, 0 },

  { 40, "ctrl_student_hil/PIHeadingCtrl/k_P/Value", offsetof
    (P_ctrl_student_HIL_T, k_P_Value), 38, 1, 2, 80, 0 },

  { 41, "ctrl_student_hil/HeadingObserver/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC_e), 38, 1, 2, 82, 0 },

  { 42, "ctrl_student_hil/Switch2/Threshold", offsetof(P_ctrl_student_HIL_T,
    Switch2_Threshold), 38, 1, 2, 84, 0 },

  { 43, "ctrl_student_hil/PIHeadingCtrl/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC_h), 38, 1, 2, 86, 0 },

  { 44, "ctrl_student_hil/PIHeadingCtrl/k_I/Value", offsetof
    (P_ctrl_student_HIL_T, k_I_Value), 38, 1, 2, 88, 0 },

  { 45, "ctrl_student_hil/Switch1/Threshold", offsetof(P_ctrl_student_HIL_T,
    Switch1_Threshold_j), 38, 1, 2, 90, 0 },

  { 46, "ctrl_student_hil/safety zone /Switch/Threshold", offsetof
    (P_ctrl_student_HIL_T, Switch_Threshold_n), 38, 1, 2, 92, 0 },

  { 47, "ctrl_student_hil/safety zone /Memory/X0", offsetof(P_ctrl_student_HIL_T,
    Memory_X0_i), 38, 1, 2, 94, 0 },

  { 48, "ctrl_student_hil/safety zone /Switch2/Threshold", offsetof
    (P_ctrl_student_HIL_T, Switch2_Threshold_p), 38, 1, 2, 96, 0 },

  { 49,
    "ctrl_student_hil/ThrustAllocationAndSaturation/Actuator_Sat_Forces/Value",
    offsetof(P_ctrl_student_HIL_T, Actuator_Sat_Forces_Value), 28, 2, 2, 98, 0 },

  { 50, "ctrl_student_hil/physics_model/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC_m), 22, 3, 2, 100, 0 },

  { 51, "ctrl_student_hil/bias/Value", offsetof(P_ctrl_student_HIL_T, bias_Value),
    38, 1, 2, 102, 0 },

  { 52, "ctrl_student_hil/SurgeObserver/Gain/Gain", offsetof
    (P_ctrl_student_HIL_T, Gain_Gain_d), 38, 1, 2, 104, 0 },

  { 53, "ctrl_student_hil/ThrustAllocationAndSaturation/Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value), 38, 1, 2, 106, 0 },

  { 54, "ctrl_student_hil/ThrustAllocationAndSaturation/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_i), 38, 1, 2, 108, 0 },

  { 55, "ctrl_student_hil/ThrustAllocationAndSaturation/Ramp/Step/Before",
    offsetof(P_ctrl_student_HIL_T, Step_Y0), 38, 1, 2, 110, 0 },

  { 56, "ctrl_student_hil/ThrustAllocationAndSaturation/Saturation/UpperLimit",
    offsetof(P_ctrl_student_HIL_T, Saturation_UpperSat), 38, 1, 2, 112, 0 },

  { 57, "ctrl_student_hil/ThrustAllocationAndSaturation/Saturation/LowerLimit",
    offsetof(P_ctrl_student_HIL_T, Saturation_LowerSat), 38, 1, 2, 114, 0 },

  { 58, "ctrl_student_hil/ThrustAllocationAndSaturation/Switch/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch_Threshold_k), 38, 1, 2, 116, 0 },

  { 59, "ctrl_student_hil/ThrustAllocationAndSaturation/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value), 38, 1, 2, 118, 0 },

  { 60, "ctrl_student_hil/ThrustAllocationAndSaturation/Switch1/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch1_Threshold_m), 38, 1, 2, 120, 0 },

  { 61, "ctrl_student_hil/ThrustAllocationAndSaturation/Constant3/Value",
    offsetof(P_ctrl_student_HIL_T, Constant3_Value), 38, 1, 2, 122, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 62;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  2, 1,                                /* Parameter at index 0 */
  3, 1,                                /* Parameter at index 1 */
  3, 1,                                /* Parameter at index 2 */
  4, 1,                                /* Parameter at index 3 */
  4, 1,                                /* Parameter at index 4 */
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
  1, 1,                                /* Parameter at index 16 */
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
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 4,                                /* Parameter at index 32 */
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
  1, 2,                                /* Parameter at index 49 */
  3, 1,                                /* Parameter at index 50 */
  1, 1,                                /* Parameter at index 51 */
  1, 1,                                /* Parameter at index 52 */
  1, 1,                                /* Parameter at index 53 */
  1, 1,                                /* Parameter at index 54 */
  1, 1,                                /* Parameter at index 55 */
  1, 1,                                /* Parameter at index 56 */
  1, 1,                                /* Parameter at index 57 */
  1, 1,                                /* Parameter at index 58 */
  1, 1,                                /* Parameter at index 59 */
  1, 1,                                /* Parameter at index 60 */
  1, 1,                                /* Parameter at index 61 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student_hil/SurgeObserver/Integrator", 0, "", offsetof
    (B_ctrl_student_HIL_T, Integrator)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 1, "ctrl_student_hil/SurgeObserver/IC", 0, "", offsetof(B_ctrl_student_HIL_T,
    IC)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "ctrl_student_hil/reset", 0, "", offsetof(B_ctrl_student_HIL_T, reset)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/Constant2", 0, "(1,1)", offsetof(B_ctrl_student_HIL_T,
    Constant2)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil/Constant2", 0, "(1,2)", offsetof(B_ctrl_student_HIL_T,
    Constant2)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/Constant2", 0, "(1,3)", offsetof(B_ctrl_student_HIL_T,
    Constant2)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/NoisePowPos", 0, "", offsetof(B_ctrl_student_HIL_T,
    NoisePowPos)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_e)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 16, 0 },

  { 9, "ctrl_student_hil/NoisePowHead", 0, "", offsetof(B_ctrl_student_HIL_T,
    NoisePowHead)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_m)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 20, 0 },

  { 11, "ctrl_student_hil/y_in", 0, "", offsetof(B_ctrl_student_HIL_T, y_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 22, 0 },

  { 12, "ctrl_student_hil/x_in", 0, "", offsetof(B_ctrl_student_HIL_T, x_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 24, 0 },

  { 13, "ctrl_student_hil/psi_in", 0, "", offsetof(B_ctrl_student_HIL_T, psi_in)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 26, 0 },

  { 14, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Hold)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    28, 0 },

  { 15, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, Hold)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    30, 0 },

  { 16, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, Hold)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    32, 0 },

  { 17, "ctrl_student_hil/NoiseEnable", 0, "", offsetof(B_ctrl_student_HIL_T,
    NoiseEnable)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 34, 0 },

  { 18, "ctrl_student_hil/Dropout_simulator/Memory2", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 36,
    0 },

  { 19, "ctrl_student_hil/Dropout_simulator/Memory1", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 38,
    0 },

  { 20, "ctrl_student_hil/Dropout_simulator/Memory", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 40, 0
  },

  { 21, "ctrl_student_hil/Dropout_signaINl", 0, "", offsetof
    (B_ctrl_student_HIL_T, Dropout_signaINl)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 42, 0 },

  { 22, "ctrl_student_hil/SurgeObserver/Sum1", 0, "", offsetof
    (B_ctrl_student_HIL_T, Sum1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil/SurgeObserver/Switch", 0, "", offsetof
    (B_ctrl_student_HIL_T, Switch)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 46, 0
  },

  { 24, "ctrl_student_hil/u_in", 0, "", offsetof(B_ctrl_student_HIL_T, u_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil/Sum1", 0, "", offsetof(B_ctrl_student_HIL_T, Sum1_e)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 50, 0 },

  { 26, "ctrl_student_hil/r_in", 0, "", offsetof(B_ctrl_student_HIL_T, r_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 52, 0 },

  { 27, "ctrl_student_hil/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    54, 0 },

  { 28, "ctrl_student_hil/joystick/CurrentMode", 0, "", offsetof
    (B_ctrl_student_HIL_T, CurrentMode)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    56, 0 },

  { 29, "ctrl_student_hil/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 58,
    0 },

  { 30, "ctrl_student_hil/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 60,
    0 },

  { 31, "ctrl_student_hil/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    62, 0 },

  { 32, "ctrl_student_hil/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 64,
    0 },

  { 33, "ctrl_student_hil/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 66,
    0 },

  { 34, "ctrl_student_hil/joystick/L1", 0, "", offsetof(B_ctrl_student_HIL_T, L1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 68, 0 },

  { 35, "ctrl_student_hil/joystick/R1", 0, "", offsetof(B_ctrl_student_HIL_T, R1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 70, 0 },

  { 36, "ctrl_student_hil/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 72,
    0 },

  { 37, "ctrl_student_hil/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 74,
    0 },

  { 38, "ctrl_student_hil/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 76,
    0 },

  { 39, "ctrl_student_hil/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    78, 0 },

  { 40, "ctrl_student_hil/joystick/Select", 0, "", offsetof(B_ctrl_student_HIL_T,
    Select)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 80, 0 },

  { 41, "ctrl_student_hil/HeadingObserver/Integrator", 0, "", offsetof
    (B_ctrl_student_HIL_T, Integrator_c)+0*sizeof(real_T), BLOCKIO_SIG, 38, 1, 2,
    82, 0 },

  { 42, "ctrl_student_hil/Psi_d", 0, "", offsetof(B_ctrl_student_HIL_T, Psi_d)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 84, 0 },

  { 43, "ctrl_student_hil/PIHeadingCtrl/Sum3", 0, "", offsetof
    (B_ctrl_student_HIL_T, Sum3)+0*sizeof(real_T), BLOCKIO_SIG, 38, 1, 2, 86, 0
  },

  { 44, "ctrl_student_hil/PIHeadingCtrl/Sum5", 0, "", offsetof
    (B_ctrl_student_HIL_T, Sum5)+0*sizeof(real_T), BLOCKIO_SIG, 38, 1, 2, 88, 0
  },

  { 45, "ctrl_student_hil/CaseSwitch", 0, "", offsetof(B_ctrl_student_HIL_T,
    CaseSwitch)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 90, 0 },

  { 46, "ctrl_student_hil/v_in", 0, "", offsetof(B_ctrl_student_HIL_T, v_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 92, 0 },

  { 47, "ctrl_student_hil/safety zone /Memory", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory_n)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 94,
    0 },

  { 48, "ctrl_student_hil/SZ_ResetKill", 0, "", offsetof(B_ctrl_student_HIL_T,
    SZ_ResetKill)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 96, 0 },

  { 49, "ctrl_student_hil/SZ_Owerwrite", 0, "", offsetof(B_ctrl_student_HIL_T,
    SZ_Owerwrite)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 98, 0 },

  { 50, "ctrl_student_hil/Sum", 0, "", offsetof(B_ctrl_student_HIL_T, Sum)+0*
    sizeof(real_T), BLOCKIO_SIG, 38, 1, 2, 100, 0 },

  { 51, "ctrl_student_hil/HeadingObserver/Sum", 0, "", offsetof
    (B_ctrl_student_HIL_T, Sum_j)+0*sizeof(real_T), BLOCKIO_SIG, 38, 1, 2, 102,
    0 },

  { 52, "ctrl_student_hil/SurgeObserver/Sum2", 0, "", offsetof
    (B_ctrl_student_HIL_T, Sum2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 104, 0
  },

  { 53, "ctrl_student_hil/ThrustAllocationAndSaturation/TurnOffomega1", 0, "",
    offsetof(B_ctrl_student_HIL_T, TurnOffomega1)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 106, 0 },

  { 54, "ctrl_student_hil/ThrustAllocationAndSaturation/TurnOffomega2", 0, "",
    offsetof(B_ctrl_student_HIL_T, TurnOffomega2)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 108, 0 },

  { 55, "ctrl_student_hil/ThrustAllocationAndSaturation/Switch", 0, "", offsetof
    (B_ctrl_student_HIL_T, Switch_i)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 110,
    0 },

  { 56, "ctrl_student_hil/ThrustAllocationAndSaturation/Switch1", 0, "",
    offsetof(B_ctrl_student_HIL_T, Switch1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 112, 0 },

  { 57, "ctrl_student_hil/ThrustAllocationAndSaturation/Sum", 0, "", offsetof
    (B_ctrl_student_HIL_T, Sum_m)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 114, 0
  },

  { 58, "ctrl_student_hil/ThrustAllocationAndSaturation/Sum1", 0, "", offsetof
    (B_ctrl_student_HIL_T, Sum1_p)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 116,
    0 },

  { 59, "ctrl_student_hil/safety zone /MATLAB Function", 0, "kill_signal",
    offsetof(B_ctrl_student_HIL_T, kill_signal)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 118, 0 },

  { 60, "ctrl_student_hil/physics_model/kinetics", 0, "nu_dot(1,1)", offsetof
    (B_ctrl_student_HIL_T, nu_dot)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 120,
    0 },

  { 61, "ctrl_student_hil/physics_model/kinetics", 0, "nu_dot(1,2)", offsetof
    (B_ctrl_student_HIL_T, nu_dot)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 122,
    0 },

  { 62, "ctrl_student_hil/physics_model/kinetics", 0, "nu_dot(1,3)", offsetof
    (B_ctrl_student_HIL_T, nu_dot)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 124,
    0 },

  { 63, "ctrl_student_hil/physics_model/kinematics", 0, "eta_dot(1,1)", offsetof
    (B_ctrl_student_HIL_T, eta_dot)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 126,
    0 },

  { 64, "ctrl_student_hil/physics_model/kinematics", 0, "eta_dot(1,2)", offsetof
    (B_ctrl_student_HIL_T, eta_dot)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 128,
    0 },

  { 65, "ctrl_student_hil/physics_model/kinematics", 0, "eta_dot(1,3)", offsetof
    (B_ctrl_student_HIL_T, eta_dot)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 130,
    0 },

  { 66, "ctrl_student_hil/joystick/Contoller_Map1", 0, "tau_surge", offsetof
    (B_ctrl_student_HIL_T, tau_surge)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    132, 0 },

  { 67, "ctrl_student_hil/joystick/Contoller_Map1", 1, "tau_sway", offsetof
    (B_ctrl_student_HIL_T, tau_sway)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 134,
    0 },

  { 68, "ctrl_student_hil/joystick/Contoller_Map1", 2, "tau_yaw", offsetof
    (B_ctrl_student_HIL_T, tau_yaw)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 136,
    0 },

  { 69, "ctrl_student_hil/ThrustAllocationAndSaturation/actForces1", 0,
    "tauAct(1,1)", offsetof(B_ctrl_student_HIL_T, tauAct)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 138, 0 },

  { 70, "ctrl_student_hil/ThrustAllocationAndSaturation/actForces1", 0,
    "tauAct(1,2)", offsetof(B_ctrl_student_HIL_T, tauAct)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 140, 0 },

  { 71, "ctrl_student_hil/ThrustAllocationAndSaturation/actForces1", 0,
    "tauAct(1,3)", offsetof(B_ctrl_student_HIL_T, tauAct)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 142, 0 },

  { 72, "ctrl_student_hil/ThrustAllocationAndSaturation/Force2Control", 0,
    "u_vsp1", offsetof(B_ctrl_student_HIL_T, u_vsp1)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 144, 0 },

  { 73, "ctrl_student_hil/ThrustAllocationAndSaturation/Force2Control", 1,
    "u_vsp2", offsetof(B_ctrl_student_HIL_T, u_vsp2)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 146, 0 },

  { 74, "ctrl_student_hil/ThrustAllocationAndSaturation/Force2Control", 2,
    "alpha1", offsetof(B_ctrl_student_HIL_T, alpha1)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 148, 0 },

  { 75, "ctrl_student_hil/ThrustAllocationAndSaturation/Force2Control", 3,
    "alpha2", offsetof(B_ctrl_student_HIL_T, alpha2)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 150, 0 },

  { 76, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,1)", offsetof(B_ctrl_student_HIL_T, output)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 152, 0 },

  { 77, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,2)", offsetof(B_ctrl_student_HIL_T, output)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 154, 0 },

  { 78, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,3)", offsetof(B_ctrl_student_HIL_T, output)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 156, 0 },

  { 79, "ctrl_student_hil/Noise generator/Downsamplesignal/MATLAB Function", 0,
    "count", offsetof(B_ctrl_student_HIL_T, count)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 158, 0 },

  { 80, "ctrl_student_hil/Dropout_simulator/MATLAB Function", 0, "X_out",
    offsetof(B_ctrl_student_HIL_T, X_out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    160, 0 },

  { 81, "ctrl_student_hil/Dropout_simulator/MATLAB Function", 1, "Y_out",
    offsetof(B_ctrl_student_HIL_T, Y_out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    162, 0 },

  { 82, "ctrl_student_hil/Dropout_simulator/MATLAB Function", 2, "Yaw_out",
    offsetof(B_ctrl_student_HIL_T, Yaw_out)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 164, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 83;
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
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 60;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "reset", 0, EXT_IN, 1, 1, 1 },

  { 1, "NoisePowPos", 0, EXT_IN, 1, 1, 1 },

  { 2, "NoisePowHead", 0, EXT_IN, 1, 1, 1 },

  { 3, "y_in", 0, EXT_IN, 1, 1, 1 },

  { 4, "x_in", 0, EXT_IN, 1, 1, 1 },

  { 5, "psi_in", 0, EXT_IN, 1, 1, 1 },

  { 6, "NoiseEnable", 0, EXT_IN, 1, 1, 1 },

  { 7, "Dropout_signaINl", 0, EXT_IN, 1, 1, 1 },

  { 8, "u_in", 0, EXT_IN, 1, 1, 1 },

  { 9, "r_in", 0, EXT_IN, 1, 1, 1 },

  { 10, "joystick/L2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 11, "joystick/CurrentMode", 0, EXT_IN, 1, 1, 1 },

  { 12, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 13, "joystick/PosYRight", 0, EXT_IN, 1, 1, 1 },

  { 14, "joystick/R2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 15, "joystick/PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 16, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 17, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 18, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 19, "joystick/ArrowDown", 1, EXT_IN, 1, 1, 1 },

  { 20, "joystick/ArrowUp", 1, EXT_IN, 1, 1, 1 },

  { 21, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 22, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { 23, "joystick/Select", 1, EXT_IN, 1, 1, 1 },

  { 24, "Psi_d", 0, EXT_IN, 1, 1, 1 },

  { 25, "CaseSwitch", 0, EXT_IN, 1, 1, 1 },

  { 26, "v_in", 0, EXT_IN, 1, 1, 1 },

  { 27, "SZ_ResetKill", 0, EXT_IN, 1, 1, 1 },

  { 28, "SZ_Owerwrite", 0, EXT_IN, 1, 1, 1 },

  { 29, "ThrustAllocationAndSaturation/TurnOffomega1", 0, EXT_IN, 1, 1, 1 },

  { 30, "ThrustAllocationAndSaturation/TurnOffomega2", 0, EXT_IN, 1, 1, 1 },

  { 0, "u_hat", 0, EXT_OUT, 1, 1, 1 },

  { 1, "u_real  ", 0, EXT_OUT, 1, 1, 1 },

  { 2, "u_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 3, "eta_noise", 0, EXT_OUT, 3, 3, 1 },

  { 4, "Dropout_signaOUT", 0, EXT_OUT, 1, 1, 1 },

  { 5, "joystick/tau_yaw", 0, EXT_OUT, 1, 1, 1 },

  { 6, "joystick/tau_x", 0, EXT_OUT, 1, 1, 1 },

  { 7, "joystick/tau_y", 0, EXT_OUT, 1, 1, 1 },

  { 8, "Tau_pre", 0, EXT_OUT, 3, 3, 1 },

  { 9, "Tau_post", 0, EXT_OUT, 3, 3, 1 },

  { 10, "psi_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 11, "psi_hat", 0, EXT_OUT, 1, 1, 1 },

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

  { 19, "ThrustAllocationAndSaturation/u_BT", 1, EXT_OUT, 1, 1, 1 },

  { 20, "ThrustAllocationAndSaturation/u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 21, "ThrustAllocationAndSaturation/u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 22, "ThrustAllocationAndSaturation/alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 23, "ThrustAllocationAndSaturation/alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 24, "ThrustAllocationAndSaturation/omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 25, "ThrustAllocationAndSaturation/omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 26, "ThrustAllocationAndSaturation/f_bt", 1, EXT_OUT, 1, 1, 1 },

  { 27, "ThrustAllocationAndSaturation/f_vspx", 0, EXT_OUT, 1, 1, 1 },

  { 28, "ThrustAllocationAndSaturation/ f_vspy", 0, EXT_OUT, 1, 1, 1 },

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
static char* NI_CompiledModelVersion = "1.300";
static char* NI_CompiledModelDateTime = "Wed Apr 05 14:45:01 2017";
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
      *numContStates = 10;
      *numDiscStates = 1183;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE_g, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_f, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_f");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_d, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_d");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 2, 18, 0);
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_real_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_real_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.u_tilde_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.u_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_noise_DWORK1, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_noise_DWORK1, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_noise_DWORK1, 2, 18, 0);
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
      (&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L2_continuous_DWORK1");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Select_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Select_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Psi_d_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Psi_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.CaseSwitch_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.CaseSwitch_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Tau_pre_DWORK1, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Tau_pre_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Tau_pre_DWORK1, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Tau_pre_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Tau_pre_DWORK1, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Tau_pre_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK1");
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
      (&ctrl_student_HIL_DW.Tau_post_DWORK1, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Tau_post_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Tau_post_DWORK1, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Tau_post_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Tau_post_DWORK1, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Tau_post_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_tilde_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_hat_DWORK1");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope3_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope3_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope4_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope4_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope_PWORK");
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
      (&ctrl_student_HIL_DW.Integrator1_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Integrator1_IWORK.IcNeedsLoading");
    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.reset_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.reset_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NoisePowPos_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NoisePowPos_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NoisePowHead_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NoisePowHead_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_in_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NoiseEnable_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NoiseEnable_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Dropout_signaINl_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Dropout_signaINl_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_hat_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_real_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_real_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_tilde_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_tilde_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_noise_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_noise_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Dropout_signaOUT_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Dropout_signaOUT_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L2_continuous_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.CurrentMode_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.CurrentMode_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXRight_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYRight_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.R2_continuous_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_yaw_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_yaw_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_x_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_y_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXLeft_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYLeft_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowDown_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowUp_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowRight_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Select_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Select_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Psi_d_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Psi_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.CaseSwitch_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.CaseSwitch_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Tau_pre_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Tau_pre_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.SZ_ResetKill_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.SZ_ResetKill_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.SZ_Owerwrite_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.SZ_Owerwrite_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Tau_post_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Tau_post_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_tilde_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_tilde_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_hat_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_0_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.integratorresetmodel_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.TurnOffomega1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.TurnOffomega1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.TurnOffomega2_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.TurnOffomega2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP2_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.f_bt_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.f_bt_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.f_vspx_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.f_vspx_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.f_vspy_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.f_vspy_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 60; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC_FirstOutputTime, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC_FirstOutputTime");
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE_g, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_f, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_d, 0,
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 2,
      discStates[idx++], 18, 0);
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_real_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_tilde_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_noise_DWORK1, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_noise_DWORK1, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_noise_DWORK1, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_signaOUT_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0,
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Select_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Psi_d_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.CaseSwitch_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_pre_DWORK1, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_pre_DWORK1, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_pre_DWORK1, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_e, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SZ_ResetKill_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SZ_Owerwrite_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_post_DWORK1, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_post_DWORK1, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_post_DWORK1, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_tilde_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_hat_DWORK1, 0,
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope3_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope4_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2,
      0, discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_j, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_c, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_DW.Integrator1_IWORK.IcNeedsLoading, 0, discStates[idx
       ++], 10, 0);
    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.reset_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NoisePowPos_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NoisePowHead_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NoiseEnable_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_signaINl_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_real_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_tilde_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_noise_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_signaOUT_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.CurrentMode_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_yaw_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_x_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_y_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Select_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Psi_d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.CaseSwitch_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_pre_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SZ_ResetKill_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SZ_Owerwrite_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Tau_post_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_tilde_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_hat_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.TurnOffomega1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.TurnOffomega2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.f_bt_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.f_vspx_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.f_vspy_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 60; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3,
        count, discStates[idx++], 21, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC_FirstOutputTime, 0,
      discStates[idx++], 8, 0);
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student_HIL
