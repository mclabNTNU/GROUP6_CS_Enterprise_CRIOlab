/*
 * ctrl_student_HIL_CaseC.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL_CaseC".
 *
 * Model version              : 1.207
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sat Apr 01 09:01:11 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_student_HIL_CaseC.h"
#include "ctrl_student_HIL_CaseC_private.h"

/* Block signals (auto storage) */
B_ctrl_student_HIL_CaseC_T ctrl_student_HIL_CaseC_B;

/* Continuous states */
X_ctrl_student_HIL_CaseC_T ctrl_student_HIL_CaseC_X;

/* Block states (auto storage) */
DW_ctrl_student_HIL_CaseC_T ctrl_student_HIL_CaseC_DW;

/* Real-time model */
RT_MODEL_ctrl_student_HIL_Cas_T ctrl_student_HIL_CaseC_M_;
RT_MODEL_ctrl_student_HIL_Cas_T *const ctrl_student_HIL_CaseC_M =
  &ctrl_student_HIL_CaseC_M_;

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
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_student_HIL_CaseC_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ctrl_student_HIL_CaseC_output();
  ctrl_student_HIL_CaseC_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ctrl_student_HIL_CaseC_output();
  ctrl_student_HIL_CaseC_derivatives();

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
 *    '<S7>/Sat_Chk_BT'
 *    '<S7>/Sat_Chk_VSP'
 */
void ctrl_student_HIL_Cas_Sat_Chk_BT(real_T rtu_u_inn,
  B_Sat_Chk_BT_ctrl_student_HIL_T *localB)
{
  /* MATLAB Function 'joystick/Sat_Chk_BT': '<S33>:1' */
  if ((rtu_u_inn > 1.0) || (rtu_u_inn < -1.0)) {
    /* '<S33>:1:3' */
    /* '<S33>:1:4' */
    localB->u_out = 0.0;

    /* '<S33>:1:5' */
    localB->error = true;
  } else {
    /* '<S33>:1:7' */
    localB->u_out = rtu_u_inn;

    /* '<S33>:1:8' */
    localB->error = false;
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
void ctrl_student_HIL_CaseC_output(void)
{
  /* local block i/o variables */
  real_T rtb_u_vsp;
  real_T rtb_u_bt;
  real_T rtb_Clock;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  real_T rtb_Output;
  real_T rtb_Switch[3];
  real_T rtb_DeadZone;
  real_T rtb_DeadZone1;
  real_T rtb_R[9];
  real_T rtb_M[9];
  static const real_T tmp[9] = { 16.79, 0.0, 0.0, 0.0, 15.79,
    0.55462499999999992, 0.0, 0.55462499999999992, 2.76 };

  real_T tmp_0[9];
  real_T tmp_1[3];
  real_T rtb_R_0[3];
  real_T tmp_2[3];
  real_T rtb_R_1[9];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
    /* set solver stop time */
    if (!(ctrl_student_HIL_CaseC_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_student_HIL_CaseC_M->solverInfo,
                            ((ctrl_student_HIL_CaseC_M->Timing.clockTickH0 + 1) *
        ctrl_student_HIL_CaseC_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_student_HIL_CaseC_M->solverInfo,
                            ((ctrl_student_HIL_CaseC_M->Timing.clockTick0 + 1) *
        ctrl_student_HIL_CaseC_M->Timing.stepSize0 +
        ctrl_student_HIL_CaseC_M->Timing.clockTickH0 *
        ctrl_student_HIL_CaseC_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_student_HIL_CaseC_M)) {
    ctrl_student_HIL_CaseC_M->Timing.t[0] = rtsiGetT
      (&ctrl_student_HIL_CaseC_M->solverInfo);
  }

  /* Integrator: '<S13>/etaHat' */
  ctrl_student_HIL_CaseC_B.etaHat[0] = ctrl_student_HIL_CaseC_X.etaHat_CSTATE[0];
  ctrl_student_HIL_CaseC_B.etaHat[1] = ctrl_student_HIL_CaseC_X.etaHat_CSTATE[1];
  ctrl_student_HIL_CaseC_B.etaHat[2] = ctrl_student_HIL_CaseC_X.etaHat_CSTATE[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
  }

  /* Sum: '<Root>/Sum' */
  ctrl_student_HIL_CaseC_B.Sum[0] = ctrl_student_HIL_CaseC_B.x_in -
    ctrl_student_HIL_CaseC_B.etaHat[0];
  ctrl_student_HIL_CaseC_B.Sum[1] = ctrl_student_HIL_CaseC_B.y_in -
    ctrl_student_HIL_CaseC_B.etaHat[1];
  ctrl_student_HIL_CaseC_B.Sum[2] = ctrl_student_HIL_CaseC_B.psi_in -
    ctrl_student_HIL_CaseC_B.etaHat[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
    /* MATLAB Function: '<S21>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<S5>/Step size'
     *  Memory: '<S21>/counter'
     */
    /* MATLAB Function 'Noise generator/Downsample	signal/MATLAB Function': '<S24>:1' */
    /* '<S24>:1:3' */
    if ((ctrl_student_HIL_CaseC_DW.counter_PreviousInput + 1.0) *
        ctrl_student_HIL_CaseC_P.Stepsize_Value >= 1.0 /
        ctrl_student_HIL_CaseC_P.Constant_Value) {
      /* '<S24>:1:4' */
      /* '<S24>:1:5' */
      ctrl_student_HIL_CaseC_B.count = 0.0;
    } else {
      /* '<S24>:1:7' */
      ctrl_student_HIL_CaseC_B.count =
        ctrl_student_HIL_CaseC_DW.counter_PreviousInput + 1.0;
    }

    /* End of MATLAB Function: '<S21>/MATLAB Function' */
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
    /* RandomNumber: '<S27>/White Noise' */
    ctrl_student_HIL_CaseC_B.WhiteNoise = ctrl_student_HIL_CaseC_DW.NextOutput;
  }

  /* Product: '<S28>/Divide' incorporates:
   *  Constant: '<S5>/Step size'
   */
  rtb_Clock = ctrl_student_HIL_CaseC_B.NoisePowPos /
    ctrl_student_HIL_CaseC_P.Stepsize_Value;

  /* Sqrt: '<S28>/Sqrt' */
  rtb_Clock = sqrt(rtb_Clock);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
    /* RandomNumber: '<S28>/White Noise' */
    ctrl_student_HIL_CaseC_B.WhiteNoise_e =
      ctrl_student_HIL_CaseC_DW.NextOutput_c;
  }

  /* Product: '<S28>/Product' */
  rtb_Clock *= ctrl_student_HIL_CaseC_B.WhiteNoise_e;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
    /* RandomNumber: '<S26>/White Noise' */
    ctrl_student_HIL_CaseC_B.WhiteNoise_m =
      ctrl_student_HIL_CaseC_DW.NextOutput_p;

    /* Memory: '<S22>/Hold' */
    ctrl_student_HIL_CaseC_B.Hold[0] =
      ctrl_student_HIL_CaseC_DW.Hold_PreviousInput[0];
    ctrl_student_HIL_CaseC_B.Hold[1] =
      ctrl_student_HIL_CaseC_DW.Hold_PreviousInput[1];
    ctrl_student_HIL_CaseC_B.Hold[2] =
      ctrl_student_HIL_CaseC_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S22>/MATLAB Function1' incorporates:
   *  Constant: '<S5>/Step size'
   *  Product: '<S26>/Divide'
   *  Product: '<S26>/Product'
   *  Product: '<S27>/Divide'
   *  Product: '<S27>/Product'
   *  Sqrt: '<S26>/Sqrt'
   *  Sqrt: '<S27>/Sqrt'
   *  Sum: '<S5>/Sum'
   */
  /* MATLAB Function 'Noise generator/Sample & hold/MATLAB Function1': '<S25>:1' */
  if (ctrl_student_HIL_CaseC_B.count == 0.0) {
    /* '<S25>:1:4' */
    /* '<S25>:1:5' */
    ctrl_student_HIL_CaseC_B.output[0] = sqrt
      (ctrl_student_HIL_CaseC_B.NoisePowPos /
       ctrl_student_HIL_CaseC_P.Stepsize_Value) *
      ctrl_student_HIL_CaseC_B.WhiteNoise + ctrl_student_HIL_CaseC_B.x_in;
    ctrl_student_HIL_CaseC_B.output[1] = rtb_Clock +
      ctrl_student_HIL_CaseC_B.y_in;
    ctrl_student_HIL_CaseC_B.output[2] = sqrt
      (ctrl_student_HIL_CaseC_B.NoisePowHead /
       ctrl_student_HIL_CaseC_P.Stepsize_Value) *
      ctrl_student_HIL_CaseC_B.WhiteNoise_m + ctrl_student_HIL_CaseC_B.psi_in;
  } else {
    /* '<S25>:1:7' */
    ctrl_student_HIL_CaseC_B.output[0] = ctrl_student_HIL_CaseC_B.Hold[0];
    ctrl_student_HIL_CaseC_B.output[1] = ctrl_student_HIL_CaseC_B.Hold[1];
    ctrl_student_HIL_CaseC_B.output[2] = ctrl_student_HIL_CaseC_B.Hold[2];
  }

  /* End of MATLAB Function: '<S22>/MATLAB Function1' */

  /* Switch: '<S5>/Switch' */
  if (ctrl_student_HIL_CaseC_B.NoiseEnable != 0.0) {
    rtb_Switch[0] = ctrl_student_HIL_CaseC_B.output[0];
    rtb_Switch[1] = ctrl_student_HIL_CaseC_B.output[1];
    rtb_Switch[2] = ctrl_student_HIL_CaseC_B.output[2];
  } else {
    rtb_Switch[0] = ctrl_student_HIL_CaseC_B.x_in;
    rtb_Switch[1] = ctrl_student_HIL_CaseC_B.y_in;
    rtb_Switch[2] = ctrl_student_HIL_CaseC_B.psi_in;
  }

  /* End of Switch: '<S5>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
    /* Memory: '<S4>/Memory2' */
    ctrl_student_HIL_CaseC_B.Memory2 =
      ctrl_student_HIL_CaseC_DW.Memory2_PreviousInput;

    /* Memory: '<S4>/Memory1' */
    ctrl_student_HIL_CaseC_B.Memory1 =
      ctrl_student_HIL_CaseC_DW.Memory1_PreviousInput;

    /* Memory: '<S4>/Memory' */
    ctrl_student_HIL_CaseC_B.Memory =
      ctrl_student_HIL_CaseC_DW.Memory_PreviousInput;
  }

  /* MATLAB Function: '<S4>/MATLAB Function' */
  /* MATLAB Function 'Dropout_simulator/MATLAB Function': '<S20>:1' */
  /* '<S20>:1:2' */
  ctrl_student_HIL_CaseC_B.X_out = -1.0;

  /* '<S20>:1:3' */
  ctrl_student_HIL_CaseC_B.Y_out = -1.0;

  /* '<S20>:1:4' */
  ctrl_student_HIL_CaseC_B.Yaw_out = -1.0;
  switch ((int32_T)ctrl_student_HIL_CaseC_B.Dropout_signaINl) {
   case 0:
    /* '<S20>:1:9' */
    ctrl_student_HIL_CaseC_B.X_out = rtb_Switch[0];

    /* '<S20>:1:10' */
    ctrl_student_HIL_CaseC_B.Y_out = rtb_Switch[1];

    /* '<S20>:1:11' */
    ctrl_student_HIL_CaseC_B.Yaw_out = rtb_Switch[2];
    break;

   case 1:
    /* '<S20>:1:14' */
    ctrl_student_HIL_CaseC_B.X_out = ctrl_student_HIL_CaseC_B.Memory2;

    /* '<S20>:1:15' */
    ctrl_student_HIL_CaseC_B.Y_out = ctrl_student_HIL_CaseC_B.Memory1;

    /* '<S20>:1:16' */
    ctrl_student_HIL_CaseC_B.Yaw_out = ctrl_student_HIL_CaseC_B.Memory;
    break;
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function' */

  /* SignalConversion: '<Root>/TmpSignal ConversionAteta_noiseInport1' */
  ctrl_student_HIL_CaseC_B.TmpSignalConversionAteta_noiseI[0] =
    ctrl_student_HIL_CaseC_B.X_out;
  ctrl_student_HIL_CaseC_B.TmpSignalConversionAteta_noiseI[1] =
    ctrl_student_HIL_CaseC_B.Y_out;
  ctrl_student_HIL_CaseC_B.TmpSignalConversionAteta_noiseI[2] =
    ctrl_student_HIL_CaseC_B.Yaw_out;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
    /* Memory: '<S7>/Memory1' */
    ctrl_student_HIL_CaseC_B.Memory1_j =
      ctrl_student_HIL_CaseC_DW.Memory1_PreviousInput_b;
  }

  /* MATLAB Function: '<S7>/Sel_Control_Mode' */
  /* MATLAB Function 'joystick/Sel_Control_Mode': '<S35>:1' */
  if (ctrl_student_HIL_CaseC_B.Select == 1.0) {
    /* '<S35>:1:3' */
    if (ctrl_student_HIL_CaseC_B.Memory1_j == 2.0) {
      /* '<S35>:1:4' */
      /* '<S35>:1:5' */
      ctrl_student_HIL_CaseC_B.current_mode = 3.0;
    } else {
      /* '<S35>:1:7' */
      ctrl_student_HIL_CaseC_B.current_mode = 2.0;
    }
  } else {
    /* '<S35>:1:10' */
    ctrl_student_HIL_CaseC_B.current_mode = ctrl_student_HIL_CaseC_B.Memory1_j;
  }

  /* End of MATLAB Function: '<S7>/Sel_Control_Mode' */

  /* DeadZone: '<S7>/Dead Zone' */
  if (ctrl_student_HIL_CaseC_B.PosXRight > ctrl_student_HIL_CaseC_P.DeadZone_End)
  {
    rtb_DeadZone = ctrl_student_HIL_CaseC_B.PosXRight -
      ctrl_student_HIL_CaseC_P.DeadZone_End;
  } else if (ctrl_student_HIL_CaseC_B.PosXRight >=
             ctrl_student_HIL_CaseC_P.DeadZone_Start) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone = ctrl_student_HIL_CaseC_B.PosXRight -
      ctrl_student_HIL_CaseC_P.DeadZone_Start;
  }

  /* End of DeadZone: '<S7>/Dead Zone' */

  /* DeadZone: '<S7>/Dead Zone1' */
  if (ctrl_student_HIL_CaseC_B.PosYRight >
      ctrl_student_HIL_CaseC_P.DeadZone1_End) {
    rtb_DeadZone1 = ctrl_student_HIL_CaseC_B.PosYRight -
      ctrl_student_HIL_CaseC_P.DeadZone1_End;
  } else if (ctrl_student_HIL_CaseC_B.PosYRight >=
             ctrl_student_HIL_CaseC_P.DeadZone1_Start) {
    rtb_DeadZone1 = 0.0;
  } else {
    rtb_DeadZone1 = ctrl_student_HIL_CaseC_B.PosYRight -
      ctrl_student_HIL_CaseC_P.DeadZone1_Start;
  }

  /* End of DeadZone: '<S7>/Dead Zone1' */

  /* Gain: '<S7>/Gain' incorporates:
   *  Sum: '<S7>/Sum'
   */
  rtb_Output = (ctrl_student_HIL_CaseC_B.L2_continuous -
                ctrl_student_HIL_CaseC_B.R2_continuous) *
    ctrl_student_HIL_CaseC_P.Gain_Gain;

  /* MATLAB Function: '<S7>/Contoller_Map' incorporates:
   *  Constant: '<S7>/Max_Global_Forces'
   */
  /* MATLAB Function 'joystick/Contoller_Map': '<S29>:1' */
  if (ctrl_student_HIL_CaseC_B.current_mode == 2.0) {
    /* '<S29>:1:3' */
    /* '<S29>:1:4' */
    ctrl_student_HIL_CaseC_B.tau_x = -rtb_DeadZone1 *
      ctrl_student_HIL_CaseC_P.Max_Global_Forces_Value[0];

    /* '<S29>:1:5' */
    ctrl_student_HIL_CaseC_B.tau_y = 0.0;

    /* '<S29>:1:6' */
    ctrl_student_HIL_CaseC_B.tau_yaw = rtb_DeadZone *
      ctrl_student_HIL_CaseC_P.Max_Global_Forces_Value[2];
  } else {
    /* '<S29>:1:8' */
    ctrl_student_HIL_CaseC_B.tau_x = -rtb_DeadZone1 *
      ctrl_student_HIL_CaseC_P.Max_Global_Forces_Value[0];

    /* '<S29>:1:9' */
    ctrl_student_HIL_CaseC_B.tau_y = rtb_DeadZone *
      ctrl_student_HIL_CaseC_P.Max_Global_Forces_Value[1];

    /* DeadZone: '<S7>/Dead Zone2' incorporates:
     *  Constant: '<S7>/Max_Global_Forces'
     */
    /* '<S29>:1:10' */
    if (rtb_Output > ctrl_student_HIL_CaseC_P.DeadZone2_End) {
      rtb_Output -= ctrl_student_HIL_CaseC_P.DeadZone2_End;
    } else if (rtb_Output >= ctrl_student_HIL_CaseC_P.DeadZone2_Start) {
      rtb_Output = 0.0;
    } else {
      rtb_Output -= ctrl_student_HIL_CaseC_P.DeadZone2_Start;
    }

    /* End of DeadZone: '<S7>/Dead Zone2' */
    ctrl_student_HIL_CaseC_B.tau_yaw = rtb_Output *
      ctrl_student_HIL_CaseC_P.Max_Global_Forces_Value[2];
  }

  /* End of MATLAB Function: '<S7>/Contoller_Map' */

  /* MATLAB Function: '<S7>/Force Allocation' */
  /* MATLAB Function 'joystick/Force Allocation': '<S30>:1' */
  if (ctrl_student_HIL_CaseC_B.current_mode == 2.0) {
    /* '<S30>:1:5' */
    /* '<S30>:1:6' */
    ctrl_student_HIL_CaseC_B.f_vspx = ctrl_student_HIL_CaseC_B.tau_x;

    /* '<S30>:1:7' */
    ctrl_student_HIL_CaseC_B.f_vspy = 0.0;

    /* '<S30>:1:8' */
    ctrl_student_HIL_CaseC_B.f_bt = ctrl_student_HIL_CaseC_B.tau_y;
  } else {
    /* new equations from Silas 31/1/2017, based on Matlab inversion of B matrix */
    /* '<S30>:1:11' */
    ctrl_student_HIL_CaseC_B.f_vspx = ctrl_student_HIL_CaseC_B.tau_x;

    /* '<S30>:1:12' */
    ctrl_student_HIL_CaseC_B.f_vspy = 0.3875 * ctrl_student_HIL_CaseC_B.tau_y /
      0.845 - ctrl_student_HIL_CaseC_B.tau_yaw / 0.845;

    /* '<S30>:1:13' */
    ctrl_student_HIL_CaseC_B.f_bt = ctrl_student_HIL_CaseC_B.tau_yaw / 0.845 -
      -0.4575 * ctrl_student_HIL_CaseC_B.tau_y / 0.845;
  }

  /* End of MATLAB Function: '<S7>/Force Allocation' */

  /* MATLAB Function: '<S7>/Force2Control' incorporates:
   *  Constant: '<S7>/Sat_Forces'
   */
  /* original equations from 30/1/2017 */
  /*  f_vspx=tau_x; */
  /*  f_vspy=(tau_yaw-tau_y*l_bt)/(l_vsp-l_bt); */
  /*  f_bt=tau_y-f_vspy; */
  /* tau_yaw = f_vspy*l_vsp+f_bt*l_bt */
  /* tau_y=f_vspy+f_bt */
  /* solve for f_bt and f_vspy */
  /* MATLAB Function 'joystick/Force2Control': '<S31>:1' */
  /* '<S31>:1:3' */
  rtb_u_vsp = sqrt(ctrl_student_HIL_CaseC_B.f_vspx *
                   ctrl_student_HIL_CaseC_B.f_vspx +
                   ctrl_student_HIL_CaseC_B.f_vspy *
                   ctrl_student_HIL_CaseC_B.f_vspy) /
    ctrl_student_HIL_CaseC_P.Sat_Forces_Value[0];

  /* '<S31>:1:4' */
  rtb_u_bt = ctrl_student_HIL_CaseC_B.f_bt /
    ctrl_student_HIL_CaseC_P.Sat_Forces_Value[1];

  /* '<S31>:1:5' */
  ctrl_student_HIL_CaseC_B.alpha = rt_atan2d_snf(ctrl_student_HIL_CaseC_B.f_vspy,
    ctrl_student_HIL_CaseC_B.f_vspx);

  /* MATLAB Function: '<S7>/Sat_Chk_BT' */
  ctrl_student_HIL_Cas_Sat_Chk_BT(rtb_u_bt,
    &ctrl_student_HIL_CaseC_B.sf_Sat_Chk_BT);

  /* MATLAB Function: '<S7>/Sat_Chk_VSP' */
  ctrl_student_HIL_Cas_Sat_Chk_BT(rtb_u_vsp,
    &ctrl_student_HIL_CaseC_B.sf_Sat_Chk_VSP);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
  }

  /* Clock: '<S32>/Clock' */
  rtb_Clock = ctrl_student_HIL_CaseC_M->Timing.t[0];

  /* Step: '<S32>/Step' */
  if (ctrl_student_HIL_CaseC_M->Timing.t[0] <
      ctrl_student_HIL_CaseC_P.Ramp_start) {
    rtb_DeadZone = ctrl_student_HIL_CaseC_P.Step_Y0;
  } else {
    rtb_DeadZone = ctrl_student_HIL_CaseC_P.Ramp_slope;
  }

  /* End of Step: '<S32>/Step' */

  /* Sum: '<S32>/Output' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/Constant1'
   *  Product: '<S32>/Product'
   *  Sum: '<S32>/Sum'
   */
  rtb_DeadZone = (rtb_Clock - ctrl_student_HIL_CaseC_P.Ramp_start) *
    rtb_DeadZone + ctrl_student_HIL_CaseC_P.Ramp_X0;

  /* Saturate: '<S7>/Saturation' */
  if (rtb_DeadZone > ctrl_student_HIL_CaseC_P.Saturation_UpperSat) {
    ctrl_student_HIL_CaseC_B.Saturation =
      ctrl_student_HIL_CaseC_P.Saturation_UpperSat;
  } else if (rtb_DeadZone < ctrl_student_HIL_CaseC_P.Saturation_LowerSat) {
    ctrl_student_HIL_CaseC_B.Saturation =
      ctrl_student_HIL_CaseC_P.Saturation_LowerSat;
  } else {
    ctrl_student_HIL_CaseC_B.Saturation = rtb_DeadZone;
  }

  /* End of Saturate: '<S7>/Saturation' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
  }

  /* Logic: '<S7>/Logical Operator' */
  ctrl_student_HIL_CaseC_B.LogicalOperator =
    (ctrl_student_HIL_CaseC_B.sf_Sat_Chk_VSP.error ||
     ctrl_student_HIL_CaseC_B.sf_Sat_Chk_BT.error);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
  }

  /* InitialCondition: '<S9>/IC1' incorporates:
   *  Constant: '<S9>/Constant'
   *  Integrator: '<S9>/bHat'
   *  Product: '<S9>/Product'
   *  Sum: '<S9>/Sum'
   */
  if ((ctrl_student_HIL_CaseC_DW.IC1_FirstOutputTime == (rtMinusInf)) ||
      (ctrl_student_HIL_CaseC_DW.IC1_FirstOutputTime ==
       ctrl_student_HIL_CaseC_M->Timing.t[0])) {
    ctrl_student_HIL_CaseC_DW.IC1_FirstOutputTime =
      ctrl_student_HIL_CaseC_M->Timing.t[0];
    ctrl_student_HIL_CaseC_B.IC1[0] = ctrl_student_HIL_CaseC_P.IC1_Value[0];
    ctrl_student_HIL_CaseC_B.IC1[1] = ctrl_student_HIL_CaseC_P.IC1_Value[1];
    ctrl_student_HIL_CaseC_B.IC1[2] = ctrl_student_HIL_CaseC_P.IC1_Value[2];
  } else {
    ctrl_student_HIL_CaseC_B.IC1[0] = ctrl_student_HIL_CaseC_B.biasOffset *
      ctrl_student_HIL_CaseC_P.Constant_Value_d[0] +
      ctrl_student_HIL_CaseC_X.bHat_CSTATE[0];
    ctrl_student_HIL_CaseC_B.IC1[1] = ctrl_student_HIL_CaseC_B.biasOffset *
      ctrl_student_HIL_CaseC_P.Constant_Value_d[1] +
      ctrl_student_HIL_CaseC_X.bHat_CSTATE[1];
    ctrl_student_HIL_CaseC_B.IC1[2] = ctrl_student_HIL_CaseC_B.biasOffset *
      ctrl_student_HIL_CaseC_P.Constant_Value_d[2] +
      ctrl_student_HIL_CaseC_X.bHat_CSTATE[2];
  }

  /* End of InitialCondition: '<S9>/IC1' */

  /* MATLAB Function: '<S9>/bHatDot' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Product: '<Root>/Product'
   *  SignalConversion: '<S14>/TmpSignal ConversionAt SFunction Inport2'
   */
  /* MATLAB Function 'DPObserver/Bias/bHatDot': '<S14>:1' */
  /* '<S14>:1:3' */
  rtb_DeadZone = ctrl_student_HIL_CaseC_B.X_out -
    ctrl_student_HIL_CaseC_B.etaHat[0];
  rtb_DeadZone1 = ctrl_student_HIL_CaseC_B.Y_out -
    ctrl_student_HIL_CaseC_B.etaHat[1];
  rtb_Output = ctrl_student_HIL_CaseC_B.Yaw_out -
    ctrl_student_HIL_CaseC_B.etaHat[2];
  for (r1 = 0; r1 < 3; r1++) {
    ctrl_student_HIL_CaseC_B.bHatDot[r1] = 0.0;
    ctrl_student_HIL_CaseC_B.bHatDot[r1] += ctrl_student_HIL_CaseC_B.sf3 *
      ctrl_student_HIL_CaseC_P.l3[r1] * rtb_DeadZone;
    ctrl_student_HIL_CaseC_B.bHatDot[r1] += ctrl_student_HIL_CaseC_P.l3[r1 + 3] *
      ctrl_student_HIL_CaseC_B.sf3 * rtb_DeadZone1;
    ctrl_student_HIL_CaseC_B.bHatDot[r1] += ctrl_student_HIL_CaseC_P.l3[r1 + 6] *
      ctrl_student_HIL_CaseC_B.sf3 * rtb_Output;
  }

  /* End of MATLAB Function: '<S9>/bHatDot' */

  /* InitialCondition: '<S12>/IC' incorporates:
   *  Integrator: '<S12>/nuHat'
   */
  /* bHatDot=[0;0;0]; */
  if ((ctrl_student_HIL_CaseC_DW.IC_FirstOutputTime == (rtMinusInf)) ||
      (ctrl_student_HIL_CaseC_DW.IC_FirstOutputTime ==
       ctrl_student_HIL_CaseC_M->Timing.t[0])) {
    ctrl_student_HIL_CaseC_DW.IC_FirstOutputTime =
      ctrl_student_HIL_CaseC_M->Timing.t[0];
    ctrl_student_HIL_CaseC_B.IC[0] = ctrl_student_HIL_CaseC_P.IC_Value[0];
    ctrl_student_HIL_CaseC_B.IC[1] = ctrl_student_HIL_CaseC_P.IC_Value[1];
    ctrl_student_HIL_CaseC_B.IC[2] = ctrl_student_HIL_CaseC_P.IC_Value[2];
  } else {
    ctrl_student_HIL_CaseC_B.IC[0] = ctrl_student_HIL_CaseC_X.nuHat_CSTATE[0];
    ctrl_student_HIL_CaseC_B.IC[1] = ctrl_student_HIL_CaseC_X.nuHat_CSTATE[1];
    ctrl_student_HIL_CaseC_B.IC[2] = ctrl_student_HIL_CaseC_X.nuHat_CSTATE[2];
  }

  /* End of InitialCondition: '<S12>/IC' */

  /* MATLAB Function: '<S1>/Rotation Matrix' */
  /* MATLAB Function 'DPObserver/D': '<S10>:1' */
  /* '<S10>:1:3' */
  /* u=0;  */
  /* '<S10>:1:4' */
  /* v=0;  */
  /* '<S10>:1:5' */
  /* r=0; */
  /* '<S10>:1:7' */
  /* '<S10>:1:10' */
  /* '<S10>:1:13' */
  /* '<S10>:1:18' */
  /* '<S10>:1:21' */
  /* '<S10>:1:27' */
  /* '<S10>:1:28' */
  /* '<S10>:1:29' */
  /* '<S10>:1:30' */
  /* '<S10>:1:31' */
  /* '<S10>:1:33' */
  /* MATLAB Function 'DPObserver/Rotation Matrix': '<S11>:1' */
  /* '<S11>:1:3' */
  rtb_R[0] = cos(ctrl_student_HIL_CaseC_B.Yaw_out);
  rtb_R[3] = -sin(ctrl_student_HIL_CaseC_B.Yaw_out);
  rtb_R[6] = 0.0;
  rtb_R[1] = sin(ctrl_student_HIL_CaseC_B.Yaw_out);
  rtb_R[4] = cos(ctrl_student_HIL_CaseC_B.Yaw_out);
  rtb_R[7] = 0.0;
  rtb_R[2] = 0.0;
  rtb_R[5] = 0.0;
  rtb_R[8] = 1.0;

  /* MATLAB Function: '<S12>/M' */
  memcpy(&rtb_M[0], &tmp[0], 9U * sizeof(real_T));

  /* MATLAB Function: '<S1>/D' */
  /* MATLAB Function 'DPObserver/Subsystem/M': '<S15>:1' */
  /* % MATRICES */
  /* '<S15>:1:5' */
  /*  x_g  =  0.0460; % Table B.1 */
  /* % Added mass */
  /* '<S15>:1:9' */
  /*  Table B.1 */
  /* '<S15>:1:10' */
  /*  Table B.1 guestimate */
  /* '<S15>:1:11' */
  /*  Table B.1 */
  /* % Total mass matrix */
  /* '<S15>:1:14' */
  /* '<S15>:1:15' */
  /* '<S15>:1:16' */
  /* '<S15>:1:17' */
  /* '<S15>:1:18' */
  /* '<S15>:1:19' */
  /* '<S15>:1:21' */
  /* MATLAB Function 'DPObserver/Subsystem/nuHatDot': '<S16>:1' */
  /* '<S16>:1:3' */
  rtb_R_1[0] = (0.6555 - 0.3545 * fabs(ctrl_student_HIL_CaseC_B.IC[0])) -
    ctrl_student_HIL_CaseC_B.IC[0] * ctrl_student_HIL_CaseC_B.IC[0] * -3.787;
  rtb_R_1[3] = 0.0;
  rtb_R_1[6] = 0.0;
  rtb_R_1[1] = 0.0;
  rtb_R_1[4] = ((1.33 - -2.776 * fabs(ctrl_student_HIL_CaseC_B.IC[1])) -
                ctrl_student_HIL_CaseC_B.IC[1] * ctrl_student_HIL_CaseC_B.IC[1] *
                -64.91) - -0.805 * fabs(ctrl_student_HIL_CaseC_B.IC[2]);
  rtb_R_1[7] = ((7.25 - -0.845 * fabs(ctrl_student_HIL_CaseC_B.IC[1])) - -3.45 *
                fabs(ctrl_student_HIL_CaseC_B.IC[2])) -
    ctrl_student_HIL_CaseC_B.IC[2] * ctrl_student_HIL_CaseC_B.IC[2] * 0.0;
  rtb_R_1[2] = 0.0;
  rtb_R_1[5] = ((-0.0 - -0.2088 * fabs(ctrl_student_HIL_CaseC_B.IC[1])) -
                ctrl_student_HIL_CaseC_B.IC[1] * ctrl_student_HIL_CaseC_B.IC[1] *
                0.0) - 0.13 * fabs(ctrl_student_HIL_CaseC_B.IC[2]);
  rtb_R_1[8] = ((1.9 - 0.08 * fabs(ctrl_student_HIL_CaseC_B.IC[1])) - -0.75 *
                fabs(ctrl_student_HIL_CaseC_B.IC[2])) -
    ctrl_student_HIL_CaseC_B.IC[2] * ctrl_student_HIL_CaseC_B.IC[2] * 0.0;

  /* MATLAB Function: '<S12>/nuHatDot' */
  for (r1 = 0; r1 < 3; r1++) {
    tmp_0[3 * r1] = -rtb_R_1[3 * r1];
    tmp_0[1 + 3 * r1] = -rtb_R_1[3 * r1 + 1];
    tmp_0[2 + 3 * r1] = -rtb_R_1[3 * r1 + 2];
  }

  for (r1 = 0; r1 < 3; r1++) {
    tmp_1[r1] = tmp_0[r1 + 6] * ctrl_student_HIL_CaseC_B.IC[2] + (tmp_0[r1 + 3] *
      ctrl_student_HIL_CaseC_B.IC[1] + tmp_0[r1] * ctrl_student_HIL_CaseC_B.IC[0]);
  }

  for (r1 = 0; r1 < 3; r1++) {
    rtb_R_0[r1] = rtb_R[3 * r1 + 2] * ctrl_student_HIL_CaseC_B.IC1[2] + (rtb_R[3
      * r1 + 1] * ctrl_student_HIL_CaseC_B.IC1[1] + rtb_R[3 * r1] *
      ctrl_student_HIL_CaseC_B.IC1[0]);
  }

  /* SignalConversion: '<S16>/TmpSignal ConversionAt SFunction Inport7' incorporates:
   *  MATLAB Function: '<S12>/nuHatDot'
   */
  tmp_2[0] = ctrl_student_HIL_CaseC_B.tau_x;
  tmp_2[1] = ctrl_student_HIL_CaseC_B.tau_y;
  tmp_2[2] = ctrl_student_HIL_CaseC_B.tau_yaw;

  /* MATLAB Function: '<S12>/nuHatDot' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Product: '<Root>/Product2'
   *  SignalConversion: '<S16>/TmpSignal ConversionAt SFunction Inport8'
   */
  for (r1 = 0; r1 < 3; r1++) {
    for (r2 = 0; r2 < 3; r2++) {
      rtb_R_1[r1 + 3 * r2] = 0.0;
      rtb_R_1[r1 + 3 * r2] += ctrl_student_HIL_CaseC_P.l2[3 * r2] *
        ctrl_student_HIL_CaseC_B.sf2 * rtb_R[3 * r1];
      rtb_R_1[r1 + 3 * r2] += ctrl_student_HIL_CaseC_P.l2[3 * r2 + 1] *
        ctrl_student_HIL_CaseC_B.sf2 * rtb_R[3 * r1 + 1];
      rtb_R_1[r1 + 3 * r2] += ctrl_student_HIL_CaseC_P.l2[3 * r2 + 2] *
        ctrl_student_HIL_CaseC_B.sf2 * rtb_R[3 * r1 + 2];
    }
  }

  rtb_DeadZone = ctrl_student_HIL_CaseC_B.X_out -
    ctrl_student_HIL_CaseC_B.etaHat[0];
  rtb_DeadZone1 = ctrl_student_HIL_CaseC_B.Y_out -
    ctrl_student_HIL_CaseC_B.etaHat[1];
  rtb_Output = ctrl_student_HIL_CaseC_B.Yaw_out -
    ctrl_student_HIL_CaseC_B.etaHat[2];
  for (r1 = 0; r1 < 3; r1++) {
    rtb_Switch[r1] = ((rtb_R_1[r1 + 3] * rtb_DeadZone1 + rtb_R_1[r1] *
                       rtb_DeadZone) + rtb_R_1[r1 + 6] * rtb_Output) +
      ((tmp_1[r1] + rtb_R_0[r1]) + tmp_2[r1]);
  }

  memcpy(&rtb_R_1[0], &rtb_M[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  rtb_DeadZone = rtb_M[0];
  if (rtb_M[1] > rtb_M[0]) {
    rtb_DeadZone = rtb_M[1];
    r1 = 1;
    r2 = 0;
  }

  if (rtb_M[2] > rtb_DeadZone) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  rtb_R_1[r2] = rtb_M[r2] / rtb_M[r1];
  rtb_R_1[r3] /= rtb_R_1[r1];
  rtb_R_1[3 + r2] -= rtb_R_1[3 + r1] * rtb_R_1[r2];
  rtb_R_1[3 + r3] -= rtb_R_1[3 + r1] * rtb_R_1[r3];
  rtb_R_1[6 + r2] -= rtb_R_1[6 + r1] * rtb_R_1[r2];
  rtb_R_1[6 + r3] -= rtb_R_1[6 + r1] * rtb_R_1[r3];
  if (fabs(rtb_R_1[3 + r3]) > fabs(rtb_R_1[3 + r2])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  rtb_R_1[3 + r3] /= rtb_R_1[3 + r2];
  rtb_R_1[6 + r3] -= rtb_R_1[3 + r3] * rtb_R_1[6 + r2];
  ctrl_student_HIL_CaseC_B.nuHatDot[0] = rtb_Switch[r1];
  ctrl_student_HIL_CaseC_B.nuHatDot[1] = rtb_Switch[r2] -
    ctrl_student_HIL_CaseC_B.nuHatDot[0] * rtb_R_1[r2];
  ctrl_student_HIL_CaseC_B.nuHatDot[2] = (rtb_Switch[r3] -
    ctrl_student_HIL_CaseC_B.nuHatDot[0] * rtb_R_1[r3]) - rtb_R_1[3 + r3] *
    ctrl_student_HIL_CaseC_B.nuHatDot[1];
  ctrl_student_HIL_CaseC_B.nuHatDot[2] /= rtb_R_1[6 + r3];
  ctrl_student_HIL_CaseC_B.nuHatDot[0] -= rtb_R_1[6 + r1] *
    ctrl_student_HIL_CaseC_B.nuHatDot[2];
  ctrl_student_HIL_CaseC_B.nuHatDot[1] -= rtb_R_1[6 + r2] *
    ctrl_student_HIL_CaseC_B.nuHatDot[2];
  ctrl_student_HIL_CaseC_B.nuHatDot[1] /= rtb_R_1[3 + r2];
  ctrl_student_HIL_CaseC_B.nuHatDot[0] -= rtb_R_1[3 + r1] *
    ctrl_student_HIL_CaseC_B.nuHatDot[1];
  ctrl_student_HIL_CaseC_B.nuHatDot[0] /= rtb_R_1[r1];

  /* MATLAB Function: '<S13>/etaHatDot' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Product: '<Root>/Product1'
   *  SignalConversion: '<S17>/TmpSignal ConversionAt SFunction Inport4'
   */
  /* MATLAB Function 'DPObserver/etaHat/etaHatDot': '<S17>:1' */
  /* etaHatDot=zeros(3,1); */
  /* '<S17>:1:4' */
  rtb_DeadZone = ctrl_student_HIL_CaseC_B.X_out -
    ctrl_student_HIL_CaseC_B.etaHat[0];
  rtb_DeadZone1 = ctrl_student_HIL_CaseC_B.Y_out -
    ctrl_student_HIL_CaseC_B.etaHat[1];
  rtb_Output = ctrl_student_HIL_CaseC_B.Yaw_out -
    ctrl_student_HIL_CaseC_B.etaHat[2];
  for (r1 = 0; r1 < 3; r1++) {
    rtb_R_0[r1] = rtb_R[r1 + 6] * ctrl_student_HIL_CaseC_B.IC[2] + (rtb_R[r1 + 3]
      * ctrl_student_HIL_CaseC_B.IC[1] + rtb_R[r1] *
      ctrl_student_HIL_CaseC_B.IC[0]);
  }

  for (r1 = 0; r1 < 3; r1++) {
    tmp_1[r1] = ctrl_student_HIL_CaseC_P.l1[r1 + 6] *
      ctrl_student_HIL_CaseC_B.sf1 * rtb_Output +
      (ctrl_student_HIL_CaseC_P.l1[r1 + 3] * ctrl_student_HIL_CaseC_B.sf1 *
       rtb_DeadZone1 + ctrl_student_HIL_CaseC_B.sf1 *
       ctrl_student_HIL_CaseC_P.l1[r1] * rtb_DeadZone);
  }

  ctrl_student_HIL_CaseC_B.etaHatDot[0] = rtb_R_0[0] + tmp_1[0];
  ctrl_student_HIL_CaseC_B.etaHatDot[1] = rtb_R_0[1] + tmp_1[1];
  ctrl_student_HIL_CaseC_B.etaHatDot[2] = rtb_R_0[2] + tmp_1[2];

  /* End of MATLAB Function: '<S13>/etaHatDot' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
  }
}

/* Model update function */
void ctrl_student_HIL_CaseC_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
    /* Update for Memory: '<S21>/counter' */
    ctrl_student_HIL_CaseC_DW.counter_PreviousInput =
      ctrl_student_HIL_CaseC_B.count;

    /* Update for RandomNumber: '<S27>/White Noise' */
    ctrl_student_HIL_CaseC_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_CaseC_DW.RandSeed) *
      ctrl_student_HIL_CaseC_P.WhiteNoise_StdDev +
      ctrl_student_HIL_CaseC_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S28>/White Noise' */
    ctrl_student_HIL_CaseC_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_CaseC_DW.RandSeed_j) *
      ctrl_student_HIL_CaseC_P.WhiteNoise_StdDev_d +
      ctrl_student_HIL_CaseC_P.WhiteNoise_Mean_h;

    /* Update for RandomNumber: '<S26>/White Noise' */
    ctrl_student_HIL_CaseC_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_CaseC_DW.RandSeed_c) *
      ctrl_student_HIL_CaseC_P.WhiteNoise_StdDev_g +
      ctrl_student_HIL_CaseC_P.WhiteNoise_Mean_f;

    /* Update for Memory: '<S22>/Hold' */
    ctrl_student_HIL_CaseC_DW.Hold_PreviousInput[0] =
      ctrl_student_HIL_CaseC_B.output[0];
    ctrl_student_HIL_CaseC_DW.Hold_PreviousInput[1] =
      ctrl_student_HIL_CaseC_B.output[1];
    ctrl_student_HIL_CaseC_DW.Hold_PreviousInput[2] =
      ctrl_student_HIL_CaseC_B.output[2];

    /* Update for Memory: '<S4>/Memory2' */
    ctrl_student_HIL_CaseC_DW.Memory2_PreviousInput =
      ctrl_student_HIL_CaseC_B.X_out;

    /* Update for Memory: '<S4>/Memory1' */
    ctrl_student_HIL_CaseC_DW.Memory1_PreviousInput =
      ctrl_student_HIL_CaseC_B.Y_out;

    /* Update for Memory: '<S4>/Memory' */
    ctrl_student_HIL_CaseC_DW.Memory_PreviousInput =
      ctrl_student_HIL_CaseC_B.Yaw_out;

    /* Update for Memory: '<S7>/Memory1' */
    ctrl_student_HIL_CaseC_DW.Memory1_PreviousInput_b =
      ctrl_student_HIL_CaseC_B.current_mode;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_CaseC_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_student_HIL_CaseC_M->solverInfo);
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
  if (!(++ctrl_student_HIL_CaseC_M->Timing.clockTick0)) {
    ++ctrl_student_HIL_CaseC_M->Timing.clockTickH0;
  }

  ctrl_student_HIL_CaseC_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ctrl_student_HIL_CaseC_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_student_HIL_CaseC_M->Timing.clockTick1)) {
      ++ctrl_student_HIL_CaseC_M->Timing.clockTickH1;
    }

    ctrl_student_HIL_CaseC_M->Timing.t[1] =
      ctrl_student_HIL_CaseC_M->Timing.clockTick1 *
      ctrl_student_HIL_CaseC_M->Timing.stepSize1 +
      ctrl_student_HIL_CaseC_M->Timing.clockTickH1 *
      ctrl_student_HIL_CaseC_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_student_HIL_CaseC_derivatives(void)
{
  XDot_ctrl_student_HIL_CaseC_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_student_HIL_CaseC_T *)
             ctrl_student_HIL_CaseC_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S13>/etaHat' */
  _rtXdot->etaHat_CSTATE[0] = ctrl_student_HIL_CaseC_B.etaHatDot[0];
  _rtXdot->etaHat_CSTATE[1] = ctrl_student_HIL_CaseC_B.etaHatDot[1];
  _rtXdot->etaHat_CSTATE[2] = ctrl_student_HIL_CaseC_B.etaHatDot[2];

  /* Derivatives for Integrator: '<S9>/bHat' */
  _rtXdot->bHat_CSTATE[0] = ctrl_student_HIL_CaseC_B.bHatDot[0];
  _rtXdot->bHat_CSTATE[1] = ctrl_student_HIL_CaseC_B.bHatDot[1];
  _rtXdot->bHat_CSTATE[2] = ctrl_student_HIL_CaseC_B.bHatDot[2];

  /* Derivatives for Integrator: '<S12>/nuHat' */
  _rtXdot->nuHat_CSTATE[0] = ctrl_student_HIL_CaseC_B.nuHatDot[0];
  _rtXdot->nuHat_CSTATE[1] = ctrl_student_HIL_CaseC_B.nuHatDot[1];
  _rtXdot->nuHat_CSTATE[2] = ctrl_student_HIL_CaseC_B.nuHatDot[2];
}

/* Model initialize function */
void ctrl_student_HIL_CaseC_initialize(void)
{
  /* Start for InitialCondition: '<S9>/IC1' */
  ctrl_student_HIL_CaseC_B.IC1[0] = ctrl_student_HIL_CaseC_P.IC1_Value[0];
  ctrl_student_HIL_CaseC_B.IC1[1] = ctrl_student_HIL_CaseC_P.IC1_Value[1];
  ctrl_student_HIL_CaseC_B.IC1[2] = ctrl_student_HIL_CaseC_P.IC1_Value[2];
  ctrl_student_HIL_CaseC_DW.IC1_FirstOutputTime = (rtMinusInf);

  /* Start for InitialCondition: '<S12>/IC' */
  ctrl_student_HIL_CaseC_B.IC[0] = ctrl_student_HIL_CaseC_P.IC_Value[0];
  ctrl_student_HIL_CaseC_B.IC[1] = ctrl_student_HIL_CaseC_P.IC_Value[1];
  ctrl_student_HIL_CaseC_B.IC[2] = ctrl_student_HIL_CaseC_P.IC_Value[2];
  ctrl_student_HIL_CaseC_DW.IC_FirstOutputTime = (rtMinusInf);

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Integrator: '<S13>/etaHat' */
    ctrl_student_HIL_CaseC_X.etaHat_CSTATE[0] =
      ctrl_student_HIL_CaseC_P.eta_dot_ini[0];
    ctrl_student_HIL_CaseC_X.etaHat_CSTATE[1] =
      ctrl_student_HIL_CaseC_P.eta_dot_ini[1];
    ctrl_student_HIL_CaseC_X.etaHat_CSTATE[2] =
      ctrl_student_HIL_CaseC_P.eta_dot_ini[2];

    /* InitializeConditions for Memory: '<S21>/counter' */
    ctrl_student_HIL_CaseC_DW.counter_PreviousInput =
      ctrl_student_HIL_CaseC_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S27>/White Noise' */
    tmp = floor(ctrl_student_HIL_CaseC_P.WhiteNoise_Seed);
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

    ctrl_student_HIL_CaseC_DW.RandSeed = tseed;
    ctrl_student_HIL_CaseC_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_CaseC_DW.RandSeed) *
      ctrl_student_HIL_CaseC_P.WhiteNoise_StdDev +
      ctrl_student_HIL_CaseC_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S27>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S28>/White Noise' */
    tmp = floor(ctrl_student_HIL_CaseC_P.WhiteNoise_Seed_b);
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

    ctrl_student_HIL_CaseC_DW.RandSeed_j = tseed;
    ctrl_student_HIL_CaseC_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_CaseC_DW.RandSeed_j) *
      ctrl_student_HIL_CaseC_P.WhiteNoise_StdDev_d +
      ctrl_student_HIL_CaseC_P.WhiteNoise_Mean_h;

    /* End of InitializeConditions for RandomNumber: '<S28>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S26>/White Noise' */
    tmp = floor(ctrl_student_HIL_CaseC_P.WhiteNoise_Seed_l);
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

    ctrl_student_HIL_CaseC_DW.RandSeed_c = tseed;
    ctrl_student_HIL_CaseC_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_CaseC_DW.RandSeed_c) *
      ctrl_student_HIL_CaseC_P.WhiteNoise_StdDev_g +
      ctrl_student_HIL_CaseC_P.WhiteNoise_Mean_f;

    /* End of InitializeConditions for RandomNumber: '<S26>/White Noise' */

    /* InitializeConditions for Memory: '<S22>/Hold' */
    ctrl_student_HIL_CaseC_DW.Hold_PreviousInput[0] =
      ctrl_student_HIL_CaseC_P.Hold_X0;
    ctrl_student_HIL_CaseC_DW.Hold_PreviousInput[1] =
      ctrl_student_HIL_CaseC_P.Hold_X0;
    ctrl_student_HIL_CaseC_DW.Hold_PreviousInput[2] =
      ctrl_student_HIL_CaseC_P.Hold_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    ctrl_student_HIL_CaseC_DW.Memory2_PreviousInput =
      ctrl_student_HIL_CaseC_P.Memory2_X0;

    /* InitializeConditions for Memory: '<S4>/Memory1' */
    ctrl_student_HIL_CaseC_DW.Memory1_PreviousInput =
      ctrl_student_HIL_CaseC_P.Memory1_X0;

    /* InitializeConditions for Memory: '<S4>/Memory' */
    ctrl_student_HIL_CaseC_DW.Memory_PreviousInput =
      ctrl_student_HIL_CaseC_P.Memory_X0;

    /* InitializeConditions for Memory: '<S7>/Memory1' */
    ctrl_student_HIL_CaseC_DW.Memory1_PreviousInput_b =
      ctrl_student_HIL_CaseC_P.Memory1_X0_j;

    /* InitializeConditions for Integrator: '<S9>/bHat' */
    ctrl_student_HIL_CaseC_X.bHat_CSTATE[0] = ctrl_student_HIL_CaseC_P.bHat_IC;
    ctrl_student_HIL_CaseC_X.bHat_CSTATE[1] = ctrl_student_HIL_CaseC_P.bHat_IC;
    ctrl_student_HIL_CaseC_X.bHat_CSTATE[2] = ctrl_student_HIL_CaseC_P.bHat_IC;

    /* InitializeConditions for Integrator: '<S12>/nuHat' */
    ctrl_student_HIL_CaseC_X.nuHat_CSTATE[0] =
      ctrl_student_HIL_CaseC_P.nuHat_IC[0];
    ctrl_student_HIL_CaseC_X.nuHat_CSTATE[1] =
      ctrl_student_HIL_CaseC_P.nuHat_IC[1];
    ctrl_student_HIL_CaseC_X.nuHat_CSTATE[2] =
      ctrl_student_HIL_CaseC_P.nuHat_IC[2];
  }
}

/* Model terminate function */
void ctrl_student_HIL_CaseC_terminate(void)
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
  ctrl_student_HIL_CaseC_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_student_HIL_CaseC_update();
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
  ctrl_student_HIL_CaseC_initialize();
}

void MdlTerminate(void)
{
  ctrl_student_HIL_CaseC_terminate();
}

/* Registration function */
RT_MODEL_ctrl_student_HIL_Cas_T *ctrl_student_HIL_CaseC(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_student_HIL_CaseC_M, 0,
                sizeof(RT_MODEL_ctrl_student_HIL_Cas_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_student_HIL_CaseC_M->solverInfo,
                          &ctrl_student_HIL_CaseC_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_student_HIL_CaseC_M->solverInfo, &rtmGetTPtr
                (ctrl_student_HIL_CaseC_M));
    rtsiSetStepSizePtr(&ctrl_student_HIL_CaseC_M->solverInfo,
                       &ctrl_student_HIL_CaseC_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_student_HIL_CaseC_M->solverInfo,
                 &ctrl_student_HIL_CaseC_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_student_HIL_CaseC_M->solverInfo, (real_T **)
                         &ctrl_student_HIL_CaseC_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_student_HIL_CaseC_M->solverInfo,
      &ctrl_student_HIL_CaseC_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_student_HIL_CaseC_M->solverInfo,
                          (&rtmGetErrorStatus(ctrl_student_HIL_CaseC_M)));
    rtsiSetRTModelPtr(&ctrl_student_HIL_CaseC_M->solverInfo,
                      ctrl_student_HIL_CaseC_M);
  }

  rtsiSetSimTimeStep(&ctrl_student_HIL_CaseC_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_student_HIL_CaseC_M->ModelData.intgData.y =
    ctrl_student_HIL_CaseC_M->ModelData.odeY;
  ctrl_student_HIL_CaseC_M->ModelData.intgData.f[0] =
    ctrl_student_HIL_CaseC_M->ModelData.odeF[0];
  ctrl_student_HIL_CaseC_M->ModelData.intgData.f[1] =
    ctrl_student_HIL_CaseC_M->ModelData.odeF[1];
  ctrl_student_HIL_CaseC_M->ModelData.intgData.f[2] =
    ctrl_student_HIL_CaseC_M->ModelData.odeF[2];
  ctrl_student_HIL_CaseC_M->ModelData.contStates = ((real_T *)
    &ctrl_student_HIL_CaseC_X);
  rtsiSetSolverData(&ctrl_student_HIL_CaseC_M->solverInfo, (void *)
                    &ctrl_student_HIL_CaseC_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_student_HIL_CaseC_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_student_HIL_CaseC_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_student_HIL_CaseC_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_student_HIL_CaseC_M->Timing.sampleTimes =
      (&ctrl_student_HIL_CaseC_M->Timing.sampleTimesArray[0]);
    ctrl_student_HIL_CaseC_M->Timing.offsetTimes =
      (&ctrl_student_HIL_CaseC_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_student_HIL_CaseC_M->Timing.sampleTimes[0] = (0.0);
    ctrl_student_HIL_CaseC_M->Timing.sampleTimes[1] = (0.2);

    /* task offsets */
    ctrl_student_HIL_CaseC_M->Timing.offsetTimes[0] = (0.0);
    ctrl_student_HIL_CaseC_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_student_HIL_CaseC_M, &ctrl_student_HIL_CaseC_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = ctrl_student_HIL_CaseC_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_student_HIL_CaseC_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_student_HIL_CaseC_M, -1);
  ctrl_student_HIL_CaseC_M->Timing.stepSize0 = 0.2;
  ctrl_student_HIL_CaseC_M->Timing.stepSize1 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_student_HIL_CaseC_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_student_HIL_CaseC_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_student_HIL_CaseC_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_student_HIL_CaseC_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_student_HIL_CaseC_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_student_HIL_CaseC_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_student_HIL_CaseC_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_student_HIL_CaseC_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_student_HIL_CaseC_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_student_HIL_CaseC_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_student_HIL_CaseC_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_student_HIL_CaseC_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_student_HIL_CaseC_M->rtwLogInfo, (NULL));
  }

  ctrl_student_HIL_CaseC_M->solverInfoPtr =
    (&ctrl_student_HIL_CaseC_M->solverInfo);
  ctrl_student_HIL_CaseC_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&ctrl_student_HIL_CaseC_M->solverInfo, 0.2);
  rtsiSetSolverMode(&ctrl_student_HIL_CaseC_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_student_HIL_CaseC_M->ModelData.blockIO = ((void *)
    &ctrl_student_HIL_CaseC_B);
  (void) memset(((void *) &ctrl_student_HIL_CaseC_B), 0,
                sizeof(B_ctrl_student_HIL_CaseC_T));

  /* parameters */
  ctrl_student_HIL_CaseC_M->ModelData.defaultParam = ((real_T *)
    &ctrl_student_HIL_CaseC_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_student_HIL_CaseC_X;
    ctrl_student_HIL_CaseC_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_student_HIL_CaseC_X, 0,
                  sizeof(X_ctrl_student_HIL_CaseC_T));
  }

  /* states (dwork) */
  ctrl_student_HIL_CaseC_M->ModelData.dwork = ((void *)
    &ctrl_student_HIL_CaseC_DW);
  (void) memset((void *)&ctrl_student_HIL_CaseC_DW, 0,
                sizeof(DW_ctrl_student_HIL_CaseC_T));

  /* Initialize Sizes */
  ctrl_student_HIL_CaseC_M->Sizes.numContStates = (9);/* Number of continuous states */
  ctrl_student_HIL_CaseC_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_CaseC_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_CaseC_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_CaseC_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_CaseC_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_CaseC_M->Sizes.numBlocks = (147);/* Number of blocks */
  ctrl_student_HIL_CaseC_M->Sizes.numBlockIO = (63);/* Number of block outputs */
  ctrl_student_HIL_CaseC_M->Sizes.numBlockPrms = (421);/* Sum of parameter "widths" */
  return ctrl_student_HIL_CaseC_M;
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
#ifdef NI_ROOTMODEL_ctrl_student_HIL_CaseC
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 21:
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
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 21:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

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

extern ctrl_student_HIL_CaseC_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // y_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.y_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // psi_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.psi_in, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // u_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.u_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // x_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.x_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // NoisePowPos
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.NoisePowPos, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // NoisePowHead
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.NoisePowHead, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // NoiseEnable
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.NoiseEnable, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // Dropout_signaINl
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.Dropout_signaINl, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // r_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.r_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // sf1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.sf1, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // v_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.v_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // sf2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.sf2, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // sf3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.sf3, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // biasOffset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.biasOffset, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.reset, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/L2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.L2_continuous, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/Select
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.Select, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.PosXRight, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.PosYRight, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/R2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.R2_continuous, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.PosXLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.PosYLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/L1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.L1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/R1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.R1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowDown
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.ArrowDown, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowUp
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.ArrowUp, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.ArrowLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_B.ArrowRight, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 28;
}

double ni_extout[33];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // eta_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.etaHat,0,18,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.etaHat,1,18,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.etaHat,2,18,0);
  } else {
    index += 3;
  }

  // u_real  : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.u_in,
      0,0,0);
  } else {
    index += 1;
  }

  // eta_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.Sum,0,
      18,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.Sum,1,
      18,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.Sum,2,
      18,0);
  } else {
    index += 3;
  }

  // eta_noise: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.TmpSignalConversionAteta_noiseI,0,18,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.TmpSignalConversionAteta_noiseI,1,18,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.TmpSignalConversionAteta_noiseI,2,18,0);
  } else {
    index += 3;
  }

  // Dropout_signaOUT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.Dropout_signaINl,0,0,0);
  } else {
    index += 1;
  }

  // joystick/u_BT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.sf_Sat_Chk_BT.u_out,0,0,0);
  } else {
    index += 1;
  }

  // joystick/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.sf_Sat_Chk_VSP.u_out,0,0,0);
  } else {
    index += 1;
  }

  // joystick/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.sf_Sat_Chk_VSP.u_out,0,0,0);
  } else {
    index += 1;
  }

  // joystick/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.alpha,
      0,0,0);
  } else {
    index += 1;
  }

  // joystick/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.alpha,
      0,0,0);
  } else {
    index += 1;
  }

  // joystick/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.Saturation,0,0,0);
  } else {
    index += 1;
  }

  // joystick/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.Saturation,0,0,0);
  } else {
    index += 1;
  }

  // joystick/Current Mode : Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.current_mode,0,0,0);
  } else {
    index += 1;
  }

  // joystick/Error State Flag: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.LogicalOperator,0,8,0);
  } else {
    index += 1;
  }

  // joystick/f_vspx: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.f_vspx,0,0,0);
  } else {
    index += 1;
  }

  // joystick/f_vspy: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.f_vspy,0,0,0);
  } else {
    index += 1;
  }

  // joystick/f_bt: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.f_bt,
      0,0,0);
  } else {
    index += 1;
  }

  // joystick/tau_yaw: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.tau_yaw,0,0,0);
  } else {
    index += 1;
  }

  // joystick/tau_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.tau_x,
      0,0,0);
  } else {
    index += 1;
  }

  // joystick/tau_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.tau_y,
      0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.tau_x,
      0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_B.tau_yaw,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.tau_y,
      0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_P.Constant2_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_P.Constant_Value_i,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_P.Constant1_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.reset,
      0,0,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 33;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // eta_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.etaHat,
    0,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.etaHat,
    1,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.etaHat,
    2,18,0);

  // u_real  : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.u_in,0,
    0,0);

  // eta_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.Sum,0,
    18,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.Sum,1,
    18,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.Sum,2,
    18,0);

  // eta_noise: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_B.TmpSignalConversionAteta_noiseI,0,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_B.TmpSignalConversionAteta_noiseI,1,18,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_B.TmpSignalConversionAteta_noiseI,2,18,0);

  // Dropout_signaOUT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_B.Dropout_signaINl,0,0,0);

  // joystick/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_B.sf_Sat_Chk_BT.u_out,0,0,0);

  // joystick/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_B.sf_Sat_Chk_VSP.u_out,0,0,0);

  // joystick/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_B.sf_Sat_Chk_VSP.u_out,0,0,0);

  // joystick/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.alpha,0,
    0,0);

  // joystick/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.alpha,0,
    0,0);

  // joystick/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_B.Saturation,0,0,0);

  // joystick/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_B.Saturation,0,0,0);

  // joystick/Current Mode : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_B.current_mode,0,0,0);

  // joystick/Error State Flag: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_B.LogicalOperator,0,8,0);

  // joystick/f_vspx: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.f_vspx,
    0,0,0);

  // joystick/f_vspy: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.f_vspy,
    0,0,0);

  // joystick/f_bt: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.f_bt,0,
    0,0);

  // joystick/tau_yaw: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.tau_yaw,
    0,0,0);

  // joystick/tau_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.tau_x,0,
    0,0);

  // joystick/tau_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.tau_y,0,
    0,0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.tau_x,0,
    0,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.tau_yaw,
    0,0,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.tau_y,0,
    0,0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_P.Constant2_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_P.Constant_Value_i,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_CaseC_P.Constant1_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_CaseC_B.reset,0,
    0,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_student_hil_casec/DPObserver/Subsystem/K2/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, K2), 17, 9, 2, 0, 0 },

  { 1, "ctrl_student_hil_casec/DPObserver/etaHat/etaHat/InitialCondition",
    offsetof(P_ctrl_student_HIL_CaseC_T, eta_dot_ini), 25, 3, 2, 2, 0 },

  { 2, "ctrl_student_hil_casec/Constant1/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, l1), 17, 9, 2, 4, 0 },

  { 3, "ctrl_student_hil_casec/Constant2/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, l2), 17, 9, 2, 6, 0 },

  { 4, "ctrl_student_hil_casec/Constant3/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, l3), 17, 9, 2, 8, 0 },

  { 5, "ctrl_student_hil_casec/joystick/Ramp/Constant1/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, Ramp_X0), 37, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil_casec/joystick/Ramp/Step/After", offsetof
    (P_ctrl_student_HIL_CaseC_T, Ramp_slope), 37, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil_casec/joystick/Ramp/Constant/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, Ramp_start), 37, 1, 2, 14, 0 },

  { 8, "ctrl_student_hil_casec/joystick/Ramp/Step/Time", offsetof
    (P_ctrl_student_HIL_CaseC_T, Ramp_start), 37, 1, 2, 16, 0 },

  { 9, "ctrl_student_hil_casec/Noise generator/Step size/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, Stepsize_Value), 37, 1, 2, 18, 0 },

  { 10, "ctrl_student_hil_casec/Noise generator/Downsamplesignal/counter/X0",
    offsetof(P_ctrl_student_HIL_CaseC_T, counter_X0), 37, 1, 2, 20, 0 },

  { 11, "ctrl_student_hil_casec/Constant/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, Constant_Value), 37, 1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_CaseC_T, WhiteNoise_Mean), 37, 1, 2, 24, 0 },

  { 13,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_CaseC_T, WhiteNoise_StdDev), 37, 1, 2, 26, 0 },

  { 14,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_CaseC_T, WhiteNoise_Seed), 37, 1, 2, 28, 0 },

  { 15,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_CaseC_T, WhiteNoise_Mean_h), 37, 1, 2, 30, 0 },

  { 16,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_CaseC_T, WhiteNoise_StdDev_d), 37, 1, 2, 32, 0 },

  { 17,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_CaseC_T, WhiteNoise_Seed_b), 37, 1, 2, 34, 0 },

  { 18,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_CaseC_T, WhiteNoise_Mean_f), 37, 1, 2, 36, 0 },

  { 19,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_CaseC_T, WhiteNoise_StdDev_g), 37, 1, 2, 38, 0 },

  { 20,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_CaseC_T, WhiteNoise_Seed_l), 37, 1, 2, 40, 0 },

  { 21, "ctrl_student_hil_casec/Noise generator/Sample & hold/Hold/X0", offsetof
    (P_ctrl_student_HIL_CaseC_T, Hold_X0), 37, 1, 2, 42, 0 },

  { 22, "ctrl_student_hil_casec/Dropout_simulator/Memory2/X0", offsetof
    (P_ctrl_student_HIL_CaseC_T, Memory2_X0), 37, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil_casec/Dropout_simulator/Memory1/X0", offsetof
    (P_ctrl_student_HIL_CaseC_T, Memory1_X0), 37, 1, 2, 46, 0 },

  { 24, "ctrl_student_hil_casec/Dropout_simulator/Memory/X0", offsetof
    (P_ctrl_student_HIL_CaseC_T, Memory_X0), 37, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil_casec/joystick/Memory1/X0", offsetof
    (P_ctrl_student_HIL_CaseC_T, Memory1_X0_j), 37, 1, 2, 50, 0 },

  { 26, "ctrl_student_hil_casec/joystick/Dead Zone/LowerValue", offsetof
    (P_ctrl_student_HIL_CaseC_T, DeadZone_Start), 37, 1, 2, 52, 0 },

  { 27, "ctrl_student_hil_casec/joystick/Dead Zone/UpperValue", offsetof
    (P_ctrl_student_HIL_CaseC_T, DeadZone_End), 37, 1, 2, 54, 0 },

  { 28, "ctrl_student_hil_casec/joystick/Dead Zone1/LowerValue", offsetof
    (P_ctrl_student_HIL_CaseC_T, DeadZone1_Start), 37, 1, 2, 56, 0 },

  { 29, "ctrl_student_hil_casec/joystick/Dead Zone1/UpperValue", offsetof
    (P_ctrl_student_HIL_CaseC_T, DeadZone1_End), 37, 1, 2, 58, 0 },

  { 30, "ctrl_student_hil_casec/joystick/Gain/Gain", offsetof
    (P_ctrl_student_HIL_CaseC_T, Gain_Gain), 37, 1, 2, 60, 0 },

  { 31, "ctrl_student_hil_casec/joystick/Dead Zone2/LowerValue", offsetof
    (P_ctrl_student_HIL_CaseC_T, DeadZone2_Start), 37, 1, 2, 62, 0 },

  { 32, "ctrl_student_hil_casec/joystick/Dead Zone2/UpperValue", offsetof
    (P_ctrl_student_HIL_CaseC_T, DeadZone2_End), 37, 1, 2, 64, 0 },

  { 33, "ctrl_student_hil_casec/joystick/Max_Global_Forces/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, Max_Global_Forces_Value), 26, 3, 2, 66, 0 },

  { 34, "ctrl_student_hil_casec/joystick/Sat_Forces/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, Sat_Forces_Value), 27, 2, 2, 68, 0 },

  { 35, "ctrl_student_hil_casec/joystick/Ramp/Step/Before", offsetof
    (P_ctrl_student_HIL_CaseC_T, Step_Y0), 37, 1, 2, 70, 0 },

  { 36, "ctrl_student_hil_casec/joystick/Saturation/UpperLimit", offsetof
    (P_ctrl_student_HIL_CaseC_T, Saturation_UpperSat), 37, 1, 2, 72, 0 },

  { 37, "ctrl_student_hil_casec/joystick/Saturation/LowerLimit", offsetof
    (P_ctrl_student_HIL_CaseC_T, Saturation_LowerSat), 37, 1, 2, 74, 0 },

  { 38,
    "ctrl_student_hil_casec/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_student_HIL_CaseC_T, Constant2_Value), 37, 1, 2, 76, 0 },

  { 39,
    "ctrl_student_hil_casec/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_student_HIL_CaseC_T, Constant_Value_i), 37, 1, 2, 78, 0 },

  { 40,
    "ctrl_student_hil_casec/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_CaseC_T, Constant1_Value), 37, 1, 2, 80, 0 },

  { 41, "ctrl_student_hil_casec/DPObserver/Bias/Constant/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, Constant_Value_d), 25, 3, 2, 82, 0 },

  { 42, "ctrl_student_hil_casec/DPObserver/Bias/bHat/InitialCondition", offsetof
    (P_ctrl_student_HIL_CaseC_T, bHat_IC), 37, 1, 2, 84, 0 },

  { 43, "ctrl_student_hil_casec/DPObserver/Bias/IC1/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, IC1_Value), 25, 3, 2, 86, 0 },

  { 44, "ctrl_student_hil_casec/DPObserver/Subsystem/nuHat/InitialCondition",
    offsetof(P_ctrl_student_HIL_CaseC_T, nuHat_IC), 25, 3, 2, 88, 0 },

  { 45, "ctrl_student_hil_casec/DPObserver/Subsystem/IC/Value", offsetof
    (P_ctrl_student_HIL_CaseC_T, IC_Value), 25, 3, 2, 90, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 46;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  3, 3,                                /* Parameter at index 0 */
  3, 1,                                /* Parameter at index 1 */
  3, 3,                                /* Parameter at index 2 */
  3, 3,                                /* Parameter at index 3 */
  3, 3,                                /* Parameter at index 4 */
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
  1, 1,                                /* Parameter at index 32 */
  1, 3,                                /* Parameter at index 33 */
  1, 2,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
  1, 1,                                /* Parameter at index 36 */
  1, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
  1, 1,                                /* Parameter at index 39 */
  1, 1,                                /* Parameter at index 40 */
  3, 1,                                /* Parameter at index 41 */
  1, 1,                                /* Parameter at index 42 */
  3, 1,                                /* Parameter at index 43 */
  3, 1,                                /* Parameter at index 44 */
  3, 1,                                /* Parameter at index 45 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student_hil_casec/DPObserver/etaHat/etaHat", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_CaseC_T, etaHat)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 1, "ctrl_student_hil_casec/DPObserver/etaHat/etaHat", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_CaseC_T, etaHat)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    2, 0 },

  { 2, "ctrl_student_hil_casec/DPObserver/etaHat/etaHat", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_CaseC_T, etaHat)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    4, 0 },

  { 3, "ctrl_student_hil_casec/y_in", 0, "", offsetof(B_ctrl_student_HIL_CaseC_T,
    y_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil_casec/psi_in", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, psi_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    8, 0 },

  { 5, "ctrl_student_hil_casec/u_in", 0, "", offsetof(B_ctrl_student_HIL_CaseC_T,
    u_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil_casec/x_in", 0, "", offsetof(B_ctrl_student_HIL_CaseC_T,
    x_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil_casec/Sum", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_CaseC_T, Sum)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    14, 0 },

  { 8, "ctrl_student_hil_casec/Sum", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_CaseC_T, Sum)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    16, 0 },

  { 9, "ctrl_student_hil_casec/Sum", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_CaseC_T, Sum)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    18, 0 },

  { 10, "ctrl_student_hil_casec/NoisePowPos", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, NoisePowPos)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 20, 0 },

  { 11,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise x/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_CaseC_T, WhiteNoise)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise y/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_CaseC_T, WhiteNoise_e)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 24, 0 },

  { 13, "ctrl_student_hil_casec/NoisePowHead", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, NoisePowHead)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 26, 0 },

  { 14,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise psi/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_CaseC_T, WhiteNoise_m)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 28, 0 },

  { 15, "ctrl_student_hil_casec/Noise generator/Sample & hold/Hold", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_CaseC_T, Hold)+0*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 30, 0 },

  { 16, "ctrl_student_hil_casec/Noise generator/Sample & hold/Hold", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_CaseC_T, Hold)+1*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 32, 0 },

  { 17, "ctrl_student_hil_casec/Noise generator/Sample & hold/Hold", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_CaseC_T, Hold)+2*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 34, 0 },

  { 18, "ctrl_student_hil_casec/NoiseEnable", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, NoiseEnable)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 36, 0 },

  { 19, "ctrl_student_hil_casec/Dropout_simulator/Memory2", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, Memory2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    38, 0 },

  { 20, "ctrl_student_hil_casec/Dropout_simulator/Memory1", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, Memory1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    40, 0 },

  { 21, "ctrl_student_hil_casec/Dropout_simulator/Memory", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, Memory)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    42, 0 },

  { 22, "ctrl_student_hil_casec/Dropout_signaINl", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, Dropout_signaINl)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil_casec/r_in", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, r_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    46, 0 },

  { 24, "ctrl_student_hil_casec/sf1", 0, "", offsetof(B_ctrl_student_HIL_CaseC_T,
    sf1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil_casec/v_in", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, v_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    50, 0 },

  { 26, "ctrl_student_hil_casec/sf2", 0, "", offsetof(B_ctrl_student_HIL_CaseC_T,
    sf2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 52, 0 },

  { 27, "ctrl_student_hil_casec/sf3", 0, "", offsetof(B_ctrl_student_HIL_CaseC_T,
    sf3)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 54, 0 },

  { 28, "ctrl_student_hil_casec/biasOffset", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, biasOffset)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 56, 0 },

  { 29, "ctrl_student_hil_casec/reset", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, reset)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    58, 0 },

  { 30, "ctrl_student_hil_casec/joystick/Memory1", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, Memory1_j)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 60, 0 },

  { 31, "ctrl_student_hil_casec/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 62, 0 },

  { 32, "ctrl_student_hil_casec/joystick/Select", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, Select)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    64, 0 },

  { 33, "ctrl_student_hil_casec/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 66, 0 },

  { 34, "ctrl_student_hil_casec/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 68, 0 },

  { 35, "ctrl_student_hil_casec/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 70, 0 },

  { 36, "ctrl_student_hil_casec/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 72, 0 },

  { 37, "ctrl_student_hil_casec/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 74, 0 },

  { 38, "ctrl_student_hil_casec/joystick/Saturation", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, Saturation)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 76, 0 },

  { 39, "ctrl_student_hil_casec/joystick/L1", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, L1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 78,
    0 },

  { 40, "ctrl_student_hil_casec/joystick/R1", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, R1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 80,
    0 },

  { 41, "ctrl_student_hil_casec/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 82, 0 },

  { 42, "ctrl_student_hil_casec/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    84, 0 },

  { 43, "ctrl_student_hil_casec/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 86, 0 },

  { 44, "ctrl_student_hil_casec/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 88, 0 },

  { 45, "ctrl_student_hil_casec/DPObserver/Bias/IC1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_CaseC_T, IC1)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    90, 0 },

  { 46, "ctrl_student_hil_casec/DPObserver/Bias/IC1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_CaseC_T, IC1)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    92, 0 },

  { 47, "ctrl_student_hil_casec/DPObserver/Bias/IC1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_CaseC_T, IC1)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    94, 0 },

  { 48, "ctrl_student_hil_casec/DPObserver/Subsystem/IC", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_CaseC_T, IC)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 96,
    0 },

  { 49, "ctrl_student_hil_casec/DPObserver/Subsystem/IC", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_CaseC_T, IC)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 98,
    0 },

  { 50, "ctrl_student_hil_casec/DPObserver/Subsystem/IC", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_CaseC_T, IC)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    100, 0 },

  { 51, "ctrl_student_hil_casec/joystick/Sel_Control_Mode", 0, "current_mode",
    offsetof(B_ctrl_student_HIL_CaseC_T, current_mode)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 102, 0 },

  { 52, "ctrl_student_hil_casec/joystick/Force2Control", 1, "alpha", offsetof
    (B_ctrl_student_HIL_CaseC_T, alpha)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    104, 0 },

  { 53, "ctrl_student_hil_casec/joystick/Force Allocation", 0, "f_vspx",
    offsetof(B_ctrl_student_HIL_CaseC_T, f_vspx)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 106, 0 },

  { 54, "ctrl_student_hil_casec/joystick/Force Allocation", 1, "f_vspy",
    offsetof(B_ctrl_student_HIL_CaseC_T, f_vspy)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 108, 0 },

  { 55, "ctrl_student_hil_casec/joystick/Force Allocation", 2, "f_bt", offsetof
    (B_ctrl_student_HIL_CaseC_T, f_bt)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    110, 0 },

  { 56, "ctrl_student_hil_casec/joystick/Contoller_Map", 0, "tau_x", offsetof
    (B_ctrl_student_HIL_CaseC_T, tau_x)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    112, 0 },

  { 57, "ctrl_student_hil_casec/joystick/Contoller_Map", 1, "tau_y", offsetof
    (B_ctrl_student_HIL_CaseC_T, tau_y)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    114, 0 },

  { 58, "ctrl_student_hil_casec/joystick/Contoller_Map", 2, "tau_yaw", offsetof
    (B_ctrl_student_HIL_CaseC_T, tau_yaw)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    116, 0 },

  { 59, "ctrl_student_hil_casec/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,1)", offsetof(B_ctrl_student_HIL_CaseC_T, output)+0*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 118, 0 },

  { 60, "ctrl_student_hil_casec/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,2)", offsetof(B_ctrl_student_HIL_CaseC_T, output)+1*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 120, 0 },

  { 61, "ctrl_student_hil_casec/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,3)", offsetof(B_ctrl_student_HIL_CaseC_T, output)+2*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 122, 0 },

  { 62,
    "ctrl_student_hil_casec/Noise generator/Downsamplesignal/MATLAB Function", 0,
    "count", offsetof(B_ctrl_student_HIL_CaseC_T, count)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 124, 0 },

  { 63, "ctrl_student_hil_casec/Dropout_simulator/MATLAB Function", 0, "X_out",
    offsetof(B_ctrl_student_HIL_CaseC_T, X_out)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 126, 0 },

  { 64, "ctrl_student_hil_casec/Dropout_simulator/MATLAB Function", 1, "Y_out",
    offsetof(B_ctrl_student_HIL_CaseC_T, Y_out)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 128, 0 },

  { 65, "ctrl_student_hil_casec/Dropout_simulator/MATLAB Function", 2, "Yaw_out",
    offsetof(B_ctrl_student_HIL_CaseC_T, Yaw_out)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 130, 0 },

  { 66, "ctrl_student_hil_casec/DPObserver/etaHat/etaHatDot", 0,
    "etaHatDot(1,1)", offsetof(B_ctrl_student_HIL_CaseC_T, etaHatDot)+0*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 132, 0 },

  { 67, "ctrl_student_hil_casec/DPObserver/etaHat/etaHatDot", 0,
    "etaHatDot(1,2)", offsetof(B_ctrl_student_HIL_CaseC_T, etaHatDot)+1*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 134, 0 },

  { 68, "ctrl_student_hil_casec/DPObserver/etaHat/etaHatDot", 0,
    "etaHatDot(1,3)", offsetof(B_ctrl_student_HIL_CaseC_T, etaHatDot)+2*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 136, 0 },

  { 69, "ctrl_student_hil_casec/DPObserver/Subsystem/nuHatDot", 0,
    "nuHatDot(1,1)", offsetof(B_ctrl_student_HIL_CaseC_T, nuHatDot)+0*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 138, 0 },

  { 70, "ctrl_student_hil_casec/DPObserver/Subsystem/nuHatDot", 0,
    "nuHatDot(1,2)", offsetof(B_ctrl_student_HIL_CaseC_T, nuHatDot)+1*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 140, 0 },

  { 71, "ctrl_student_hil_casec/DPObserver/Subsystem/nuHatDot", 0,
    "nuHatDot(1,3)", offsetof(B_ctrl_student_HIL_CaseC_T, nuHatDot)+2*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 142, 0 },

  { 72, "ctrl_student_hil_casec/DPObserver/Bias/bHatDot", 0, "bHatDot(1,1)",
    offsetof(B_ctrl_student_HIL_CaseC_T, bHatDot)+0*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 144, 0 },

  { 73, "ctrl_student_hil_casec/DPObserver/Bias/bHatDot", 0, "bHatDot(1,2)",
    offsetof(B_ctrl_student_HIL_CaseC_T, bHatDot)+1*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 146, 0 },

  { 74, "ctrl_student_hil_casec/DPObserver/Bias/bHatDot", 0, "bHatDot(1,3)",
    offsetof(B_ctrl_student_HIL_CaseC_T, bHatDot)+2*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 148, 0 },

  { 75, "ctrl_student_hil_casec/joystick/Logical Operator", 0, "", offsetof
    (B_ctrl_student_HIL_CaseC_T, LogicalOperator)+0*sizeof(boolean_T),
    BLOCKIO_SIG, 8, 1, 2, 150, 0 },

  { 76, "ctrl_student_hil_casec/joystick/Sat_Chk_VSP", 0, "u_out", offsetof
    (B_ctrl_student_HIL_CaseC_T, sf_Sat_Chk_VSP.u_out)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 152, 0 },

  { 77, "ctrl_student_hil_casec/joystick/Sat_Chk_VSP", 1, "error", offsetof
    (B_ctrl_student_HIL_CaseC_T, sf_Sat_Chk_VSP.error)+0*sizeof(boolean_T),
    BLOCKIO_SIG, 8, 1, 2, 154, 0 },

  { 78, "ctrl_student_hil_casec/joystick/Sat_Chk_BT", 0, "u_out", offsetof
    (B_ctrl_student_HIL_CaseC_T, sf_Sat_Chk_BT.u_out)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 156, 0 },

  { 79, "ctrl_student_hil_casec/joystick/Sat_Chk_BT", 1, "error", offsetof
    (B_ctrl_student_HIL_CaseC_T, sf_Sat_Chk_BT.error)+0*sizeof(boolean_T),
    BLOCKIO_SIG, 8, 1, 2, 158, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 80;
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
  1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 55;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "y_in", 0, EXT_IN, 1, 1, 1 },

  { 1, "psi_in", 0, EXT_IN, 1, 1, 1 },

  { 2, "u_in", 1, EXT_IN, 1, 1, 1 },

  { 3, "x_in", 0, EXT_IN, 1, 1, 1 },

  { 4, "NoisePowPos", 0, EXT_IN, 1, 1, 1 },

  { 5, "NoisePowHead", 0, EXT_IN, 1, 1, 1 },

  { 6, "NoiseEnable", 0, EXT_IN, 1, 1, 1 },

  { 7, "Dropout_signaINl", 0, EXT_IN, 1, 1, 1 },

  { 8, "r_in", 1, EXT_IN, 1, 1, 1 },

  { 9, "sf1", 0, EXT_IN, 1, 1, 1 },

  { 10, "v_in", 1, EXT_IN, 1, 1, 1 },

  { 11, "sf2", 0, EXT_IN, 1, 1, 1 },

  { 12, "sf3", 0, EXT_IN, 1, 1, 1 },

  { 13, "biasOffset", 0, EXT_IN, 1, 1, 1 },

  { 14, "reset", 1, EXT_IN, 1, 1, 1 },

  { 15, "joystick/L2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 16, "joystick/Select", 0, EXT_IN, 1, 1, 1 },

  { 17, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 18, "joystick/PosYRight", 0, EXT_IN, 1, 1, 1 },

  { 19, "joystick/R2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 20, "joystick/PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 21, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 22, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 23, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 24, "joystick/ArrowDown", 1, EXT_IN, 1, 1, 1 },

  { 25, "joystick/ArrowUp", 1, EXT_IN, 1, 1, 1 },

  { 26, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 27, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { 0, "eta_hat", 0, EXT_OUT, 3, 3, 1 },

  { 1, "u_real  ", 1, EXT_OUT, 1, 1, 1 },

  { 2, "eta_tilde", 0, EXT_OUT, 3, 3, 1 },

  { 3, "eta_noise", 0, EXT_OUT, 3, 3, 1 },

  { 4, "Dropout_signaOUT", 0, EXT_OUT, 1, 1, 1 },

  { 5, "joystick/u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 6, "joystick/u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 7, "joystick/u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 8, "joystick/alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 9, "joystick/alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 10, "joystick/omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 11, "joystick/omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 12, "joystick/Current Mode ", 0, EXT_OUT, 1, 1, 1 },

  { 13, "joystick/Error State Flag", 0, EXT_OUT, 1, 1, 1 },

  { 14, "joystick/f_vspx", 0, EXT_OUT, 1, 1, 1 },

  { 15, "joystick/f_vspy", 0, EXT_OUT, 1, 1, 1 },

  { 16, "joystick/f_bt", 0, EXT_OUT, 1, 1, 1 },

  { 17, "joystick/tau_yaw", 0, EXT_OUT, 1, 1, 1 },

  { 18, "joystick/tau_x", 0, EXT_OUT, 1, 1, 1 },

  { 19, "joystick/tau_y", 0, EXT_OUT, 1, 1, 1 },

  { 20, "tau to CSE mocell (only use for HIL testing)/X_d", 0, EXT_OUT, 1, 1, 1
  },

  { 21, "tau to CSE mocell (only use for HIL testing)/N_d", 0, EXT_OUT, 1, 1, 1
  },

  { 22, "tau to CSE mocell (only use for HIL testing)/Y_d", 0, EXT_OUT, 1, 1, 1
  },

  { 23, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 24, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1
  },

  { 25, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 26, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 1,
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
  { 0, 0.2, 0 }
};

int NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_student_hil_casec";
static char* NI_CompiledModelVersion = "1.207";
static char* NI_CompiledModelDateTime = "Sat Apr 01 09:01:11 2017";
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
   The undef allows us to access the real ctrl_student_HIL_CaseC_P
   In the rest of the code ctrl_student_HIL_CaseC_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_student_HIL_CaseC_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_student_HIL_CaseC_P, sizeof
         (P_ctrl_student_HIL_CaseC_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_student_HIL_CaseC_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_student_HIL_CaseC_T));
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
             (P_ctrl_student_HIL_CaseC_T));
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
               (P_ctrl_student_HIL_CaseC_T));

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
           (P_ctrl_student_HIL_CaseC_T));
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
           (P_ctrl_student_HIL_CaseC_T));
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
           (P_ctrl_student_HIL_CaseC_T));
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
      *numContStates = 9;
      *numDiscStates = 1432;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_X.etaHat_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "etaHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_X.etaHat_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "etaHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_X.etaHat_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "etaHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_X.bHat_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "bHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_X.bHat_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "bHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_X.bHat_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "bHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_X.nuHat_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "nuHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_X.nuHat_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "nuHat_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_X.nuHat_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "nuHat_CSTATE");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.eta_hat_DWORK1, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.eta_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.eta_hat_DWORK1, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.eta_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.eta_hat_DWORK1, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.eta_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.y_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.y_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.psi_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.u_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.u_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.u_real_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.u_real_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.x_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.x_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.eta_tilde_DWORK1, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.eta_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.eta_tilde_DWORK1, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.eta_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.eta_tilde_DWORK1, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.eta_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.NoisePowPos_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.NoisePowPos_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.NextOutput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.NextOutput_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.NextOutput_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.NoisePowHead_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.NoisePowHead_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.NextOutput_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.NextOutput_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.Hold_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.Hold_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.Hold_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.NoiseEnable_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.NoiseEnable_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.Memory2_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.Memory1_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.Memory_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.Dropout_signaINl_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.Dropout_signaINl_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.eta_noise_DWORK1, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.eta_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.eta_noise_DWORK1, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.eta_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.eta_noise_DWORK1, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.eta_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.r_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.r_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.Dropout_signaOUT_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.Dropout_signaOUT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.sf1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.sf1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.v_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.v_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.sf2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.sf2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.sf3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.sf3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.biasOffset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.biasOffset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.reset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.Memory1_PreviousInput_b, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.Memory1_PreviousInput_b");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.Select_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.Select_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.PosXRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.PosXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.PosYRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.PosYRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.u_BT_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.u_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.u_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.alpha_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.alpha_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.PosXLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.PosYLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.omega_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.omega_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.L1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.L1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.CurrentMode_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.CurrentMode_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.R1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.R1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.ErrorStateFlag_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.ErrorStateFlag_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.ArrowDown_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.ArrowDown_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.f_vspx_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.f_vspx_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.ArrowUp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.f_vspy_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.f_vspy_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.ArrowLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.ArrowLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.f_bt_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.f_bt_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.ArrowRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.ArrowRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.tau_yaw_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.tau_yaw_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.tau_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.tau_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.tau_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.tau_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.X_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.X_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.N_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.N_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.Y_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.Y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.psi_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.psi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.x_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.y_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.y_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.integratorresetmodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.integratorresetmodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.IC1_FirstOutputTime, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.IC1_FirstOutputTime");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.IC_FirstOutputTime, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.IC_FirstOutputTime");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.RandSeed, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.RandSeed_j, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.RandSeed_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.RandSeed_c, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_CaseC_DW.RandSeed_c");
    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.eta_hat_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.eta_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.y_in_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.y_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.psi_in_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.psi_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.u_in_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.u_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.u_real_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.u_real_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.x_in_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.x_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.eta_tilde_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.eta_tilde_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.NoisePowPos_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.NoisePowPos_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.NoisePowHead_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.NoisePowHead_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.NoiseEnable_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.NoiseEnable_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.Dropout_signaINl_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.Dropout_signaINl_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.eta_noise_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.eta_noise_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.r_in_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.r_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.Dropout_signaOUT_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.Dropout_signaOUT_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.sf1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.sf1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.v_in_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.v_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.sf2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.sf2_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.sf3_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.sf3_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.biasOffset_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.biasOffset_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.reset_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.reset_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.L2_continuous_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.Select_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.Select_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.PosXRight_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.PosYRight_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.R2_continuous_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.u_BT_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.u_VSP1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.u_VSP2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.alpha_VSP1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.alpha_VSP2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.PosXLeft_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.PosYLeft_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.omega_VSP1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.omega_VSP2_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.L1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.L1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.CurrentMode_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.CurrentMode_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.R1_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.R1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.ErrorStateFlag_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.ErrorStateFlag_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.ArrowDown_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.f_vspx_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.f_vspx_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.ArrowUp_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.f_vspy_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.f_vspy_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.ArrowLeft_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.ArrowLeft_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.f_bt_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.f_bt_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.ArrowRight_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.ArrowRight_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.tau_yaw_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.tau_yaw_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.tau_x_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.tau_x_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.tau_y_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.tau_y_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.X_d_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.X_d_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.N_d_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.N_d_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.Y_d_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.Y_d_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.psi_0_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.x_0_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.x_0_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.y_0_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.y_0_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.integratorresetmodel_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.NIVeriStandSignalProbe_DWORK1, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 66; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.NIVeriStandSignalProbe_DWORK3, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_CaseC_DW.NIVeriStandSignalProbe_DWORK3");
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_X.etaHat_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_X.etaHat_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_X.etaHat_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_X.bHat_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_X.bHat_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_X.bHat_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_X.nuHat_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_X.nuHat_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_X.nuHat_CSTATE[0], 2,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.eta_hat_DWORK1, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.eta_hat_DWORK1, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.eta_hat_DWORK1, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.y_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.psi_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.u_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.u_real_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.x_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.eta_tilde_DWORK1, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.eta_tilde_DWORK1, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.eta_tilde_DWORK1, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.NoisePowPos_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.NextOutput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.NextOutput_c, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.NoisePowHead_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.NextOutput_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Hold_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Hold_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Hold_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.NoiseEnable_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Memory2_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Memory1_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Dropout_signaINl_DWORK1,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.eta_noise_DWORK1, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.eta_noise_DWORK1, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.eta_noise_DWORK1, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.r_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Dropout_signaOUT_DWORK1,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.sf1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.v_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.sf2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.sf3_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.biasOffset_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.reset_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Memory1_PreviousInput_b,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Select_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.PosXRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.PosYRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.u_BT_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.u_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.u_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.alpha_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.alpha_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.PosXLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.PosYLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.omega_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.omega_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.L1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.CurrentMode_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.R1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.ErrorStateFlag_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.ArrowDown_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.f_vspx_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.ArrowUp_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.f_vspy_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.ArrowLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.f_bt_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.ArrowRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.tau_yaw_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.tau_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.tau_y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.X_d_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.N_d_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Y_d_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.psi_0_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.x_0_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.y_0_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.integratorresetmodel_DWORK1, 0, discStates[idx
       ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.IC1_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.IC_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_CaseC_DW.NIVeriStandSignalProbe_DWORK2, 0,
       discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.RandSeed, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.RandSeed_j, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.RandSeed_c, 0,
      discStates[idx++], 7, 0);
    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.eta_hat_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.y_in_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.psi_in_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.u_in_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.u_real_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.x_in_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.eta_tilde_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.NoisePowPos_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.NoisePowHead_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.NoiseEnable_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Dropout_signaINl_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.eta_noise_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.r_in_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Dropout_signaOUT_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.sf1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.v_in_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.sf2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.sf3_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.biasOffset_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.reset_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.L2_continuous_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Select_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.PosXRight_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.PosYRight_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.R2_continuous_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.u_BT_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.alpha_VSP1_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.alpha_VSP2_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.omega_VSP1_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.omega_VSP2_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.L1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.CurrentMode_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.R1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.ErrorStateFlag_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.f_vspx_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.f_vspy_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.ArrowLeft_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.f_bt_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.ArrowRight_DWORK2,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.tau_yaw_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.tau_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.tau_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.X_d_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.N_d_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.Y_d_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.psi_0_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.x_0_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_CaseC_DW.y_0_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.integratorresetmodel_DWORK2, count,
         discStates[idx++], 19, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.NIVeriStandSignalProbe_DWORK1, count,
         discStates[idx++], 19, 0);
    }

    for (count = 0; count < 66; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_CaseC_DW.NIVeriStandSignalProbe_DWORK3, count,
         discStates[idx++], 20, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student_HIL_CaseC
