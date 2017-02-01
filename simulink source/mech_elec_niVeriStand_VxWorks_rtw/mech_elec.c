/*
 * mech_elec.c
 *
 * Code generation for model "mech_elec".
 *
 * Model version              : 1.28
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Dec 16 16:25:17 2015
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "mech_elec.h"
#include "mech_elec_private.h"

/* Block signals (auto storage) */
B_mech_elec_T mech_elec_B;

/* Continuous states */
X_mech_elec_T mech_elec_X;

/* Block states (auto storage) */
DW_mech_elec_T mech_elec_DW;

/* Real-time model */
RT_MODEL_mech_elec_T mech_elec_M_;
RT_MODEL_mech_elec_T *const mech_elec_M = &mech_elec_M_;

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
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  mech_elec_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  mech_elec_output();
  mech_elec_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  mech_elec_output();
  mech_elec_derivatives();

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

/* Model output function */
void mech_elec_output(void)
{
  if (rtmIsMajorTimeStep(mech_elec_M)) {
    /* set solver stop time */
    if (!(mech_elec_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&mech_elec_M->solverInfo,
                            ((mech_elec_M->Timing.clockTickH0 + 1) *
        mech_elec_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&mech_elec_M->solverInfo,
                            ((mech_elec_M->Timing.clockTick0 + 1) *
        mech_elec_M->Timing.stepSize0 + mech_elec_M->Timing.clockTickH0 *
        mech_elec_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(mech_elec_M)) {
    mech_elec_M->Timing.t[0] = rtsiGetT(&mech_elec_M->solverInfo);
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Integrator: '<S1>/Integrator'
   *  Integrator: '<S1>/Integrator1'
   *  Integrator: '<S1>/Integrator2'
   *  Integrator: '<S1>/Integrator3'
   *  Integrator: '<S1>/Integrator4'
   *  Integrator: '<S1>/Integrator5'
   *  Integrator: '<S1>/Integrator6'
   */
  if (mech_elec_B.enable != 0.0) {
    mech_elec_B.Switch[0] = mech_elec_X.Integrator6_CSTATE;
  } else {
    mech_elec_B.Switch[0] = mech_elec_B.u_BTd;
  }

  if (mech_elec_B.enable != 0.0) {
    mech_elec_B.Switch[1] = mech_elec_X.Integrator5_CSTATE;
  } else {
    mech_elec_B.Switch[1] = mech_elec_B.omega_VSP1d;
  }

  if (mech_elec_B.enable != 0.0) {
    mech_elec_B.Switch[2] = mech_elec_X.Integrator4_CSTATE;
  } else {
    mech_elec_B.Switch[2] = mech_elec_B.omega_VSP2d;
  }

  if (mech_elec_B.enable != 0.0) {
    mech_elec_B.Switch[3] = mech_elec_X.Integrator3_CSTATE;
  } else {
    mech_elec_B.Switch[3] = mech_elec_B.u_VSP1d;
  }

  if (mech_elec_B.enable != 0.0) {
    mech_elec_B.Switch[4] = mech_elec_X.Integrator2_CSTATE;
  } else {
    mech_elec_B.Switch[4] = mech_elec_B.alpha_VSP1d;
  }

  if (mech_elec_B.enable != 0.0) {
    mech_elec_B.Switch[5] = mech_elec_X.Integrator1_CSTATE;
  } else {
    mech_elec_B.Switch[5] = mech_elec_B.u_VSP2d;
  }

  if (mech_elec_B.enable != 0.0) {
    mech_elec_B.Switch[6] = mech_elec_X.Integrator_CSTATE;
  } else {
    mech_elec_B.Switch[6] = mech_elec_B.alpha_VSP2d;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Integrator: '<S1>/Integrator'
   */
  mech_elec_B.Sum = mech_elec_B.alpha_VSP2d - mech_elec_X.Integrator_CSTATE;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Integrator: '<S1>/Integrator1'
   */
  mech_elec_B.Sum1 = mech_elec_B.u_VSP2d - mech_elec_X.Integrator1_CSTATE;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Integrator: '<S1>/Integrator2'
   */
  mech_elec_B.Sum2 = mech_elec_B.alpha_VSP1d - mech_elec_X.Integrator2_CSTATE;

  /* Sum: '<S1>/Sum3' incorporates:
   *  Integrator: '<S1>/Integrator3'
   */
  mech_elec_B.Sum3 = mech_elec_B.u_VSP1d - mech_elec_X.Integrator3_CSTATE;

  /* Sum: '<S1>/Sum4' incorporates:
   *  Integrator: '<S1>/Integrator4'
   */
  mech_elec_B.Sum4 = mech_elec_B.omega_VSP2d - mech_elec_X.Integrator4_CSTATE;

  /* Sum: '<S1>/Sum5' incorporates:
   *  Integrator: '<S1>/Integrator5'
   */
  mech_elec_B.Sum5 = mech_elec_B.omega_VSP1d - mech_elec_X.Integrator5_CSTATE;

  /* Sum: '<S1>/Sum6' incorporates:
   *  Integrator: '<S1>/Integrator6'
   */
  mech_elec_B.Sum6 = mech_elec_B.u_BTd - mech_elec_X.Integrator6_CSTATE;
  if (rtmIsMajorTimeStep(mech_elec_M)) {
  }
}

/* Model update function */
void mech_elec_update(void)
{
  if (rtmIsMajorTimeStep(mech_elec_M)) {
    rt_ertODEUpdateContinuousStates(&mech_elec_M->solverInfo);
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
  if (!(++mech_elec_M->Timing.clockTick0)) {
    ++mech_elec_M->Timing.clockTickH0;
  }

  mech_elec_M->Timing.t[0] = rtsiGetSolverStopTime(&mech_elec_M->solverInfo);

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
    if (!(++mech_elec_M->Timing.clockTick1)) {
      ++mech_elec_M->Timing.clockTickH1;
    }

    mech_elec_M->Timing.t[1] = mech_elec_M->Timing.clockTick1 *
      mech_elec_M->Timing.stepSize1 + mech_elec_M->Timing.clockTickH1 *
      mech_elec_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void mech_elec_derivatives(void)
{
  XDot_mech_elec_T *_rtXdot;
  _rtXdot = ((XDot_mech_elec_T *) mech_elec_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S1>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = mech_elec_B.Sum6;

  /* Derivatives for Integrator: '<S1>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = mech_elec_B.Sum5;

  /* Derivatives for Integrator: '<S1>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = mech_elec_B.Sum4;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = mech_elec_B.Sum3;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = mech_elec_B.Sum2;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = mech_elec_B.Sum1;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = mech_elec_B.Sum;
}

/* Model initialize function */
void mech_elec_initialize(void)
{
  /* InitializeConditions for Integrator: '<S1>/Integrator6' */
  mech_elec_X.Integrator6_CSTATE = mech_elec_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator5' */
  mech_elec_X.Integrator5_CSTATE = mech_elec_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator4' */
  mech_elec_X.Integrator4_CSTATE = mech_elec_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  mech_elec_X.Integrator3_CSTATE = mech_elec_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  mech_elec_X.Integrator2_CSTATE = mech_elec_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  mech_elec_X.Integrator1_CSTATE = mech_elec_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  mech_elec_X.Integrator_CSTATE = mech_elec_P.Integrator_IC;
}

/* Model terminate function */
void mech_elec_terminate(void)
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
  mech_elec_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  mech_elec_update();
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
  mech_elec_initialize();
}

void MdlTerminate(void)
{
  mech_elec_terminate();
}

/* Registration function */
RT_MODEL_mech_elec_T *mech_elec(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mech_elec_M, 0,
                sizeof(RT_MODEL_mech_elec_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&mech_elec_M->solverInfo,
                          &mech_elec_M->Timing.simTimeStep);
    rtsiSetTPtr(&mech_elec_M->solverInfo, &rtmGetTPtr(mech_elec_M));
    rtsiSetStepSizePtr(&mech_elec_M->solverInfo, &mech_elec_M->Timing.stepSize0);
    rtsiSetdXPtr(&mech_elec_M->solverInfo, &mech_elec_M->ModelData.derivs);
    rtsiSetContStatesPtr(&mech_elec_M->solverInfo, (real_T **)
                         &mech_elec_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&mech_elec_M->solverInfo,
      &mech_elec_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&mech_elec_M->solverInfo, (&rtmGetErrorStatus
      (mech_elec_M)));
    rtsiSetRTModelPtr(&mech_elec_M->solverInfo, mech_elec_M);
  }

  rtsiSetSimTimeStep(&mech_elec_M->solverInfo, MAJOR_TIME_STEP);
  mech_elec_M->ModelData.intgData.y = mech_elec_M->ModelData.odeY;
  mech_elec_M->ModelData.intgData.f[0] = mech_elec_M->ModelData.odeF[0];
  mech_elec_M->ModelData.intgData.f[1] = mech_elec_M->ModelData.odeF[1];
  mech_elec_M->ModelData.intgData.f[2] = mech_elec_M->ModelData.odeF[2];
  mech_elec_M->ModelData.contStates = ((real_T *) &mech_elec_X);
  rtsiSetSolverData(&mech_elec_M->solverInfo, (void *)
                    &mech_elec_M->ModelData.intgData);
  rtsiSetSolverName(&mech_elec_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = mech_elec_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mech_elec_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    mech_elec_M->Timing.sampleTimes = (&mech_elec_M->Timing.sampleTimesArray[0]);
    mech_elec_M->Timing.offsetTimes = (&mech_elec_M->Timing.offsetTimesArray[0]);

    /* task periods */
    mech_elec_M->Timing.sampleTimes[0] = (0.0);
    mech_elec_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    mech_elec_M->Timing.offsetTimes[0] = (0.0);
    mech_elec_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(mech_elec_M, &mech_elec_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = mech_elec_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mech_elec_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(mech_elec_M, -1);
  mech_elec_M->Timing.stepSize0 = 0.01;
  mech_elec_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    mech_elec_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(mech_elec_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(mech_elec_M->rtwLogInfo, (NULL));
    rtliSetLogT(mech_elec_M->rtwLogInfo, "tout");
    rtliSetLogX(mech_elec_M->rtwLogInfo, "");
    rtliSetLogXFinal(mech_elec_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(mech_elec_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(mech_elec_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(mech_elec_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(mech_elec_M->rtwLogInfo, 1);
    rtliSetLogY(mech_elec_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(mech_elec_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(mech_elec_M->rtwLogInfo, (NULL));
  }

  mech_elec_M->solverInfoPtr = (&mech_elec_M->solverInfo);
  mech_elec_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&mech_elec_M->solverInfo, 0.01);
  rtsiSetSolverMode(&mech_elec_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  mech_elec_M->ModelData.blockIO = ((void *) &mech_elec_B);
  (void) memset(((void *) &mech_elec_B), 0,
                sizeof(B_mech_elec_T));

  /* parameters */
  mech_elec_M->ModelData.defaultParam = ((real_T *)&mech_elec_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &mech_elec_X;
    mech_elec_M->ModelData.contStates = (x);
    (void) memset((void *)&mech_elec_X, 0,
                  sizeof(X_mech_elec_T));
  }

  /* states (dwork) */
  mech_elec_M->ModelData.dwork = ((void *) &mech_elec_DW);
  (void) memset((void *)&mech_elec_DW, 0,
                sizeof(DW_mech_elec_T));

  /* Initialize Sizes */
  mech_elec_M->Sizes.numContStates = (7);/* Number of continuous states */
  mech_elec_M->Sizes.numY = (0);       /* Number of model outputs */
  mech_elec_M->Sizes.numU = (0);       /* Number of model inputs */
  mech_elec_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  mech_elec_M->Sizes.numSampTimes = (2);/* Number of sample times */
  mech_elec_M->Sizes.numBlocks = (31); /* Number of blocks */
  mech_elec_M->Sizes.numBlockIO = (16);/* Number of block outputs */
  mech_elec_M->Sizes.numBlockPrms = (98);/* Sum of parameter "widths" */
  return mech_elec_M;
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
#ifdef NI_ROOTMODEL_mech_elec
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern mech_elec_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // enable
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.enable, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_d/alpha_VSP1,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.alpha_VSP1d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_d/u_VSP1,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.u_VSP1d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_d/alpha_VSP2,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.alpha_VSP2d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_d/u_VSP2,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.u_VSP2d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_d/u_BT,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.u_BTd, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_d/omega_VSP1,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.omega_VSP1d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_d/omega_VSP2,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.omega_VSP2d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 8;
}

double ni_extout[7];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // u/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,1,19,0);
  } else {
    index += 1;
  }

  // u/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,2,19,0);
  } else {
    index += 1;
  }

  // u/u_BT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,0,19,0);
  } else {
    index += 1;
  }

  // u/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,6,19,0);
  } else {
    index += 1;
  }

  // u/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,5,19,0);
  } else {
    index += 1;
  }

  // u/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,3,19,0);
  } else {
    index += 1;
  }

  // u/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,4,19,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 7;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // u/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,1,19,0);

  // u/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,2,19,0);

  // u/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,0,19,0);

  // u/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,6,19,0);

  // u/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,5,19,0);

  // u/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,3,19,0);

  // u/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch,4,19,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0,
    "mech_elec/emulate mechanical and electrical system/Integrator6/InitialCondition",
    offsetof(P_mech_elec_T, Integrator6_IC), 26, 1, 2, 0, 0 },

  { 1,
    "mech_elec/emulate mechanical and electrical system/Integrator5/InitialCondition",
    offsetof(P_mech_elec_T, Integrator5_IC), 26, 1, 2, 2, 0 },

  { 2,
    "mech_elec/emulate mechanical and electrical system/Integrator4/InitialCondition",
    offsetof(P_mech_elec_T, Integrator4_IC), 26, 1, 2, 4, 0 },

  { 3,
    "mech_elec/emulate mechanical and electrical system/Integrator3/InitialCondition",
    offsetof(P_mech_elec_T, Integrator3_IC), 26, 1, 2, 6, 0 },

  { 4,
    "mech_elec/emulate mechanical and electrical system/Integrator2/InitialCondition",
    offsetof(P_mech_elec_T, Integrator2_IC), 26, 1, 2, 8, 0 },

  { 5,
    "mech_elec/emulate mechanical and electrical system/Integrator1/InitialCondition",
    offsetof(P_mech_elec_T, Integrator1_IC), 26, 1, 2, 10, 0 },

  { 6,
    "mech_elec/emulate mechanical and electrical system/Integrator/InitialCondition",
    offsetof(P_mech_elec_T, Integrator_IC), 26, 1, 2, 12, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 7;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "mech_elec/enable", 0, "", offsetof(B_mech_elec_T, enable)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "mech_elec/u_d/alpha_VSP1,d", 0, "", offsetof(B_mech_elec_T, alpha_VSP1d)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "mech_elec/u_d/u_VSP1,d", 0, "", offsetof(B_mech_elec_T, u_VSP1d)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "mech_elec/u_d/alpha_VSP2,d", 0, "", offsetof(B_mech_elec_T, alpha_VSP2d)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "mech_elec/u_d/u_VSP2,d", 0, "", offsetof(B_mech_elec_T, u_VSP2d)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "mech_elec/u_d/u_BT,d", 0, "", offsetof(B_mech_elec_T, u_BTd)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "mech_elec/u_d/omega_VSP1,d", 0, "", offsetof(B_mech_elec_T, omega_VSP1d)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "mech_elec/u_d/omega_VSP2,d", 0, "", offsetof(B_mech_elec_T, omega_VSP2d)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8, "mech_elec/Switch", 0, "(1,1)", offsetof(B_mech_elec_T, Switch)+0*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 16, 0 },

  { 9, "mech_elec/Switch", 0, "(1,2)", offsetof(B_mech_elec_T, Switch)+1*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 18, 0 },

  { 10, "mech_elec/Switch", 0, "(1,3)", offsetof(B_mech_elec_T, Switch)+2*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 20, 0 },

  { 11, "mech_elec/Switch", 0, "(1,4)", offsetof(B_mech_elec_T, Switch)+3*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 22, 0 },

  { 12, "mech_elec/Switch", 0, "(1,5)", offsetof(B_mech_elec_T, Switch)+4*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 24, 0 },

  { 13, "mech_elec/Switch", 0, "(1,6)", offsetof(B_mech_elec_T, Switch)+5*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 26, 0 },

  { 14, "mech_elec/Switch", 0, "(1,7)", offsetof(B_mech_elec_T, Switch)+6*sizeof
    (real_T), BLOCKIO_SIG, 19, 1, 2, 28, 0 },

  { 15, "mech_elec/emulate mechanical and electrical system/Sum", 0, "",
    offsetof(B_mech_elec_T, Sum)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 30, 0 },

  { 16, "mech_elec/emulate mechanical and electrical system/Sum1", 0, "",
    offsetof(B_mech_elec_T, Sum1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 32, 0
  },

  { 17, "mech_elec/emulate mechanical and electrical system/Sum2", 0, "",
    offsetof(B_mech_elec_T, Sum2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 34, 0
  },

  { 18, "mech_elec/emulate mechanical and electrical system/Sum3", 0, "",
    offsetof(B_mech_elec_T, Sum3)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 36, 0
  },

  { 19, "mech_elec/emulate mechanical and electrical system/Sum4", 0, "",
    offsetof(B_mech_elec_T, Sum4)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 38, 0
  },

  { 20, "mech_elec/emulate mechanical and electrical system/Sum5", 0, "",
    offsetof(B_mech_elec_T, Sum5)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 40, 0
  },

  { 21, "mech_elec/emulate mechanical and electrical system/Sum6", 0, "",
    offsetof(B_mech_elec_T, Sum6)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 42, 0
  },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 22;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 15;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "enable", 0, EXT_IN, 1, 1, 1 },

  { 1, "u_d/alpha_VSP1,d", 0, EXT_IN, 1, 1, 1 },

  { 2, "u_d/u_VSP1,d", 0, EXT_IN, 1, 1, 1 },

  { 3, "u_d/alpha_VSP2,d", 0, EXT_IN, 1, 1, 1 },

  { 4, "u_d/u_VSP2,d", 0, EXT_IN, 1, 1, 1 },

  { 5, "u_d/u_BT,d", 0, EXT_IN, 1, 1, 1 },

  { 6, "u_d/omega_VSP1,d", 0, EXT_IN, 1, 1, 1 },

  { 7, "u_d/omega_VSP2,d", 0, EXT_IN, 1, 1, 1 },

  { 0, "u/omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 1, "u/omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 2, "u/u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 3, "u/alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 4, "u/u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 5, "u/u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 6, "u/alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

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
  "mech_elec";
static char* NI_CompiledModelVersion = "1.28";
static char* NI_CompiledModelDateTime = "Wed Dec 16 16:25:17 2015";
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
   The undef allows us to access the real mech_elec_P
   In the rest of the code mech_elec_P is redefine to be the read-side
   of rtParameter.
 */
#undef mech_elec_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &mech_elec_P, sizeof(P_mech_elec_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka mech_elec_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_mech_elec_T));
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
             (P_mech_elec_T));
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
               (P_mech_elec_T));

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
           (P_mech_elec_T));
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
           (P_mech_elec_T));
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
           (P_mech_elec_T));
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
      *numContStates = 7;
      *numDiscStates = 229;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&mech_elec_X.Integrator6_CSTATE, 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator6_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&mech_elec_X.Integrator5_CSTATE, 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator5_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&mech_elec_X.Integrator4_CSTATE, 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&mech_elec_X.Integrator3_CSTATE, 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&mech_elec_X.Integrator2_CSTATE, 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&mech_elec_X.Integrator1_CSTATE, 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&mech_elec_X.Integrator_CSTATE, 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.enable_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.enable_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_VSP1d_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_VSP1d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_VSP1d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_VSP1d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_VSP2d_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_VSP2d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_VSP2d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_VSP2d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_BTd_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_BTd_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.omega_VSP1d_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.omega_VSP1d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.omega_VSP2d_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.omega_VSP2d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.omega_VSP1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.omega_VSP2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_BT_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_VSP2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_VSP2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_VSP1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_VSP1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&mech_elec_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&mech_elec_DW.NIVeriStandSignalProbe_DWORK2");
    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.enable_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.enable_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_VSP1d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_VSP1d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_VSP1d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_VSP1d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_VSP2d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_VSP2d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_VSP2d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_VSP2d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_BTd_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_BTd_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.omega_VSP1d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.omega_VSP1d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.omega_VSP2d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.omega_VSP2d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.omega_VSP1_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.omega_VSP2_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_BT_DWORK2, count,
        17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_VSP2_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_VSP2_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_VSP1_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_VSP1_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&mech_elec_DW.NIVeriStandSignalProbe_DWORK1, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&mech_elec_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 53; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&mech_elec_DW.NIVeriStandSignalProbe_DWORK3, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&mech_elec_DW.NIVeriStandSignalProbe_DWORK3");
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
    NIRT_SetValueByDataType(&mech_elec_X.Integrator6_CSTATE, 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_X.Integrator5_CSTATE, 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_X.Integrator4_CSTATE, 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_X.Integrator3_CSTATE, 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_X.Integrator2_CSTATE, 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_X.Integrator1_CSTATE, 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_X.Integrator_CSTATE, 0, contStates[idx++],
      0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&mech_elec_DW.enable_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_VSP1d_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_VSP1d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_VSP2d_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_VSP2d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_BTd_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&mech_elec_DW.omega_VSP1d_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.omega_VSP2d_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.omega_VSP1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.omega_VSP2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_BT_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_VSP2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_VSP2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_VSP1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_VSP1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.NIVeriStandSignalProbe_DWORK2, 0,
      discStates[idx++], 6, 0);
    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.enable_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_VSP1d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_VSP1d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_VSP2d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_VSP2d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_BTd_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.omega_VSP1d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.omega_VSP2d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_BT_DWORK2, count, discStates[idx++],
        17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_VSP2_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_VSP1_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.NIVeriStandSignalProbe_DWORK1, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 53; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.NIVeriStandSignalProbe_DWORK3, count,
        discStates[idx++], 18, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_mech_elec
