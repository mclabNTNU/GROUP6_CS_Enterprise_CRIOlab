/*
 * CSEI_tau.c
 *
 * Code generation for model "CSEI_tau".
 *
 * Model version              : 1.154
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Mar 08 19:35:06 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "CSEI_tau.h"
#include "CSEI_tau_private.h"

/* Block signals (auto storage) */
B_CSEI_tau_T CSEI_tau_B;

/* Continuous states */
X_CSEI_tau_T CSEI_tau_X;

/* Block states (auto storage) */
DW_CSEI_tau_T CSEI_tau_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_CSEI_tau_T CSEI_tau_PrevZCX;

/* Real-time model */
RT_MODEL_CSEI_tau_T CSEI_tau_M_;
RT_MODEL_CSEI_tau_T *const CSEI_tau_M = &CSEI_tau_M_;

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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  CSEI_tau_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  CSEI_tau_output();
  CSEI_tau_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  CSEI_tau_output();
  CSEI_tau_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  CSEI_tau_output();
  CSEI_tau_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void CSEI_tau_output(void)
{
  real_T c_13;
  real_T c_23;
  real_T tmp[9];
  int32_T i;
  real_T tmp_0[9];
  real_T tmp_1[9];
  real_T tmp_2[3];
  if (rtmIsMajorTimeStep(CSEI_tau_M)) {
    /* set solver stop time */
    if (!(CSEI_tau_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&CSEI_tau_M->solverInfo,
                            ((CSEI_tau_M->Timing.clockTickH0 + 1) *
        CSEI_tau_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&CSEI_tau_M->solverInfo,
                            ((CSEI_tau_M->Timing.clockTick0 + 1) *
        CSEI_tau_M->Timing.stepSize0 + CSEI_tau_M->Timing.clockTickH0 *
        CSEI_tau_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(CSEI_tau_M)) {
    CSEI_tau_M->Timing.t[0] = rtsiGetT(&CSEI_tau_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(CSEI_tau_M)) {
    /* Memory: '<S2>/Memory3' */
    CSEI_tau_B.Memory3 = CSEI_tau_DW.Memory3_PreviousInput;

    /* Memory: '<S2>/Memory4' */
    CSEI_tau_B.Memory4 = CSEI_tau_DW.Memory4_PreviousInput;

    /* Memory: '<S2>/Memory5' */
    CSEI_tau_B.Memory5 = CSEI_tau_DW.Memory5_PreviousInput;
  }

  /* Integrator: '<Root>/Integrator1' */
  if (rtmIsMajorTimeStep(CSEI_tau_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &CSEI_tau_PrevZCX.Integrator1_Reset_ZCE,
                       CSEI_tau_B.integrator_reset);

    /* evaluate zero-crossings */
    if (zcEvent || CSEI_tau_DW.Integrator1_IWORK.IcNeedsLoading) {
      CSEI_tau_X.Integrator1_CSTATE[0] = CSEI_tau_B.Memory3;
      CSEI_tau_X.Integrator1_CSTATE[1] = CSEI_tau_B.Memory4;
      CSEI_tau_X.Integrator1_CSTATE[2] = CSEI_tau_B.Memory5;
    }
  }

  CSEI_tau_B.Integrator1[0] = CSEI_tau_X.Integrator1_CSTATE[0];
  CSEI_tau_B.Integrator1[1] = CSEI_tau_X.Integrator1_CSTATE[1];
  CSEI_tau_B.Integrator1[2] = CSEI_tau_X.Integrator1_CSTATE[2];

  /* Integrator: '<Root>/Integrator' */
  if (rtmIsMajorTimeStep(CSEI_tau_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &CSEI_tau_PrevZCX.Integrator_Reset_ZCE,
                       CSEI_tau_B.integrator_reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      CSEI_tau_X.Integrator_CSTATE[0] = (CSEI_tau_P.Integrator_IC[0]);
      CSEI_tau_X.Integrator_CSTATE[1] = (CSEI_tau_P.Integrator_IC[1]);
      CSEI_tau_X.Integrator_CSTATE[2] = (CSEI_tau_P.Integrator_IC[2]);
    }
  }

  CSEI_tau_B.Integrator[0] = CSEI_tau_X.Integrator_CSTATE[0];
  CSEI_tau_B.Integrator[1] = CSEI_tau_X.Integrator_CSTATE[1];
  CSEI_tau_B.Integrator[2] = CSEI_tau_X.Integrator_CSTATE[2];
  if (rtmIsMajorTimeStep(CSEI_tau_M)) {
  }

  /* MATLAB Function: '<Root>/kinematics' */
  /* MATLAB Function 'kinematics': '<S3>:1' */
  /* '<S3>:1:3' */
  /* '<S3>:1:5' */
  /* '<S3>:1:9' */
  tmp[0] = cos(CSEI_tau_B.Integrator1[2]);
  tmp[3] = -sin(CSEI_tau_B.Integrator1[2]);
  tmp[6] = 0.0;
  tmp[1] = sin(CSEI_tau_B.Integrator1[2]);
  tmp[4] = cos(CSEI_tau_B.Integrator1[2]);
  tmp[7] = 0.0;
  tmp[2] = 0.0;
  tmp[5] = 0.0;
  tmp[8] = 1.0;
  for (i = 0; i < 3; i++) {
    CSEI_tau_B.eta_dot[i] = 0.0;
    CSEI_tau_B.eta_dot[i] += tmp[i] * CSEI_tau_B.Integrator[0];
    CSEI_tau_B.eta_dot[i] += tmp[i + 3] * CSEI_tau_B.Integrator[1];
    CSEI_tau_B.eta_dot[i] += tmp[i + 6] * CSEI_tau_B.Integrator[2];
  }

  /* End of MATLAB Function: '<Root>/kinematics' */
  if (rtmIsMajorTimeStep(CSEI_tau_M)) {
    /* Memory: '<S6>/Memory' */
    CSEI_tau_B.Memory = CSEI_tau_DW.Memory_PreviousInput;

    /* Memory: '<S6>/Memory1' */
    CSEI_tau_B.Memory1 = CSEI_tau_DW.Memory1_PreviousInput;

    /* Memory: '<S6>/Memory2' */
    CSEI_tau_B.Memory2 = CSEI_tau_DW.Memory2_PreviousInput;
  }

  /* MATLAB Function: '<Root>/kinetics' incorporates:
   *  SignalConversion: '<S4>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'kinetics': '<S4>:1' */
  /* '<S4>:1:3' */
  /* '<S4>:1:4' */
  /* '<S4>:1:5' */
  /* '<S4>:1:7' */
  /* % MATRICES */
  /*  x_g  =  0.0460; % Table B.1 */
  /* % Added mass */
  /*  Table B.1 */
  /*  Table B.1 guestimate */
  /*  Table B.1 */
  /* % Total mass matrix */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S4>:1:31' */
  /* '<S4>:1:35' */
  /*  Y_r */
  /*  Y_rr */
  /*  Y_rv, Y_vr */
  /* '<S4>:1:41' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /* % Correolis matrix */
  /* '<S4>:1:48' */
  c_13 = -15.79 * CSEI_tau_B.Integrator[1] - 0.55462499999999992 *
    CSEI_tau_B.Integrator[2];

  /* '<S4>:1:49' */
  c_23 = 16.79 * CSEI_tau_B.Integrator[0];

  /* '<S4>:1:50' */
  /* % Assembly of the damping matrix */
  /* '<S4>:1:55' */
  /* '<S4>:1:56' */
  /* '<S4>:1:57' */
  /*  using abs(r) */
  /* '<S4>:1:59' */
  /* '<S4>:1:60' */
  /* '<S4>:1:61' */
  /* '<S4>:1:63' */
  /* % CALCULATION */
  /* '<S4>:1:70' */
  tmp_0[0] = 0.0;
  tmp_0[3] = 0.0;
  tmp_0[6] = c_13;
  tmp_0[1] = 0.0;
  tmp_0[4] = 0.0;
  tmp_0[7] = c_23;
  tmp_0[2] = -c_13;
  tmp_0[5] = -c_23;
  tmp_0[8] = 0.0;
  tmp_1[0] = (0.6555 - 0.3545 * CSEI_tau_B.Integrator[0]) -
    CSEI_tau_B.Integrator[0] * CSEI_tau_B.Integrator[0] * -3.787;
  tmp_1[3] = (-0.0 - -2.443 * CSEI_tau_B.Integrator[1]) - CSEI_tau_B.Integrator
    [1] * CSEI_tau_B.Integrator[1] * 0.0;
  tmp_1[6] = 0.0;
  tmp_1[1] = 0.0;
  tmp_1[4] = ((1.33 - -2.776 * CSEI_tau_B.Integrator[1]) -
              CSEI_tau_B.Integrator[1] * CSEI_tau_B.Integrator[1] * -64.91) -
    -0.805 * fabs(CSEI_tau_B.Integrator[2]);
  tmp_1[7] = ((7.25 - -3.45 * fabs(CSEI_tau_B.Integrator[2])) -
              CSEI_tau_B.Integrator[2] * CSEI_tau_B.Integrator[2] * 0.0) -
    -0.845 * fabs(CSEI_tau_B.Integrator[1]);
  tmp_1[2] = 0.0;
  tmp_1[5] = ((-0.0 - -0.2088 * CSEI_tau_B.Integrator[1]) -
              CSEI_tau_B.Integrator[1] * CSEI_tau_B.Integrator[1] * 0.0) - 0.13 *
    fabs(CSEI_tau_B.Integrator[2]);
  tmp_1[8] = ((1.9 - -0.75 * fabs(CSEI_tau_B.Integrator[2])) -
              CSEI_tau_B.Integrator[2] * CSEI_tau_B.Integrator[2] * 0.0) - 0.08 *
    fabs(CSEI_tau_B.Integrator[1]);
  for (i = 0; i < 3; i++) {
    tmp[3 * i] = tmp_0[3 * i] + tmp_1[3 * i];
    tmp[1 + 3 * i] = tmp_0[3 * i + 1] + tmp_1[3 * i + 1];
    tmp[2 + 3 * i] = tmp_0[3 * i + 2] + tmp_1[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    tmp_2[i] = tmp[i + 6] * CSEI_tau_B.Integrator[2] + (tmp[i + 3] *
      CSEI_tau_B.Integrator[1] + tmp[i] * CSEI_tau_B.Integrator[0]);
  }

  CSEI_tau_B.nu_dot[0] = CSEI_tau_B.Memory - tmp_2[0];
  CSEI_tau_B.nu_dot[1] = (CSEI_tau_B.Memory1 - tmp_2[1]) - CSEI_tau_B.nu_dot[0] *
    0.0;
  CSEI_tau_B.nu_dot[2] = ((CSEI_tau_B.Memory2 - tmp_2[2]) - CSEI_tau_B.nu_dot[0]
    * 0.0) - CSEI_tau_B.nu_dot[1] * 0.035125079164027864;
  CSEI_tau_B.nu_dot[2] /= 2.7405187529686508;
  CSEI_tau_B.nu_dot[0] -= CSEI_tau_B.nu_dot[2] * 0.0;
  CSEI_tau_B.nu_dot[1] -= CSEI_tau_B.nu_dot[2] * 0.55462499999999992;
  CSEI_tau_B.nu_dot[1] /= 15.79;
  CSEI_tau_B.nu_dot[0] -= CSEI_tau_B.nu_dot[1] * 0.0;
  CSEI_tau_B.nu_dot[0] /= 16.79;

  /* End of MATLAB Function: '<Root>/kinetics' */
  if (rtmIsMajorTimeStep(CSEI_tau_M)) {
  }
}

/* Model update function */
void CSEI_tau_update(void)
{
  if (rtmIsMajorTimeStep(CSEI_tau_M)) {
    /* Update for Memory: '<S2>/Memory3' */
    CSEI_tau_DW.Memory3_PreviousInput = CSEI_tau_B.x_0;

    /* Update for Memory: '<S2>/Memory4' */
    CSEI_tau_DW.Memory4_PreviousInput = CSEI_tau_B.y_0;

    /* Update for Memory: '<S2>/Memory5' */
    CSEI_tau_DW.Memory5_PreviousInput = CSEI_tau_B.psi_0;
  }

  /* Update for Integrator: '<Root>/Integrator1' */
  CSEI_tau_DW.Integrator1_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(CSEI_tau_M)) {
    /* Update for Memory: '<S6>/Memory' */
    CSEI_tau_DW.Memory_PreviousInput = CSEI_tau_B.X;

    /* Update for Memory: '<S6>/Memory1' */
    CSEI_tau_DW.Memory1_PreviousInput = CSEI_tau_B.Y;

    /* Update for Memory: '<S6>/Memory2' */
    CSEI_tau_DW.Memory2_PreviousInput = CSEI_tau_B.N;
  }

  if (rtmIsMajorTimeStep(CSEI_tau_M)) {
    rt_ertODEUpdateContinuousStates(&CSEI_tau_M->solverInfo);
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
  if (!(++CSEI_tau_M->Timing.clockTick0)) {
    ++CSEI_tau_M->Timing.clockTickH0;
  }

  CSEI_tau_M->Timing.t[0] = rtsiGetSolverStopTime(&CSEI_tau_M->solverInfo);

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
    if (!(++CSEI_tau_M->Timing.clockTick1)) {
      ++CSEI_tau_M->Timing.clockTickH1;
    }

    CSEI_tau_M->Timing.t[1] = CSEI_tau_M->Timing.clockTick1 *
      CSEI_tau_M->Timing.stepSize1 + CSEI_tau_M->Timing.clockTickH1 *
      CSEI_tau_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void CSEI_tau_derivatives(void)
{
  /* Derivatives for Integrator: '<Root>/Integrator1' */
  {
    ((XDot_CSEI_tau_T *) CSEI_tau_M->ModelData.derivs)->Integrator1_CSTATE[0] =
      CSEI_tau_B.eta_dot[0];
    ((XDot_CSEI_tau_T *) CSEI_tau_M->ModelData.derivs)->Integrator1_CSTATE[1] =
      CSEI_tau_B.eta_dot[1];
    ((XDot_CSEI_tau_T *) CSEI_tau_M->ModelData.derivs)->Integrator1_CSTATE[2] =
      CSEI_tau_B.eta_dot[2];
  }

  /* Derivatives for Integrator: '<Root>/Integrator' */
  {
    ((XDot_CSEI_tau_T *) CSEI_tau_M->ModelData.derivs)->Integrator_CSTATE[0] =
      CSEI_tau_B.nu_dot[0];
    ((XDot_CSEI_tau_T *) CSEI_tau_M->ModelData.derivs)->Integrator_CSTATE[1] =
      CSEI_tau_B.nu_dot[1];
    ((XDot_CSEI_tau_T *) CSEI_tau_M->ModelData.derivs)->Integrator_CSTATE[2] =
      CSEI_tau_B.nu_dot[2];
  }
}

/* Model initialize function */
void CSEI_tau_initialize(void)
{
  CSEI_tau_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  CSEI_tau_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Memory: '<S2>/Memory3' */
  CSEI_tau_DW.Memory3_PreviousInput = CSEI_tau_P.Memory3_X0;

  /* InitializeConditions for Memory: '<S2>/Memory4' */
  CSEI_tau_DW.Memory4_PreviousInput = CSEI_tau_P.Memory4_X0;

  /* InitializeConditions for Memory: '<S2>/Memory5' */
  CSEI_tau_DW.Memory5_PreviousInput = CSEI_tau_P.Memory5_X0;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  if (rtmIsFirstInitCond(CSEI_tau_M)) {
    CSEI_tau_X.Integrator1_CSTATE[0] = 0.0;
    CSEI_tau_X.Integrator1_CSTATE[1] = 0.0;
    CSEI_tau_X.Integrator1_CSTATE[2] = 0.0;
  }

  CSEI_tau_DW.Integrator1_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  CSEI_tau_X.Integrator_CSTATE[0] = (CSEI_tau_P.Integrator_IC[0]);
  CSEI_tau_X.Integrator_CSTATE[1] = (CSEI_tau_P.Integrator_IC[1]);
  CSEI_tau_X.Integrator_CSTATE[2] = (CSEI_tau_P.Integrator_IC[2]);

  /* InitializeConditions for Memory: '<S6>/Memory' */
  CSEI_tau_DW.Memory_PreviousInput = CSEI_tau_P.Memory_X0;

  /* InitializeConditions for Memory: '<S6>/Memory1' */
  CSEI_tau_DW.Memory1_PreviousInput = CSEI_tau_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S6>/Memory2' */
  CSEI_tau_DW.Memory2_PreviousInput = CSEI_tau_P.Memory2_X0;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(CSEI_tau_M)) {
    rtmSetFirstInitCond(CSEI_tau_M, 0);
  }
}

/* Model terminate function */
void CSEI_tau_terminate(void)
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
  CSEI_tau_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  CSEI_tau_update();
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
  CSEI_tau_initialize();
}

void MdlTerminate(void)
{
  CSEI_tau_terminate();
}

/* Registration function */
RT_MODEL_CSEI_tau_T *CSEI_tau(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)CSEI_tau_M, 0,
                sizeof(RT_MODEL_CSEI_tau_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&CSEI_tau_M->solverInfo,
                          &CSEI_tau_M->Timing.simTimeStep);
    rtsiSetTPtr(&CSEI_tau_M->solverInfo, &rtmGetTPtr(CSEI_tau_M));
    rtsiSetStepSizePtr(&CSEI_tau_M->solverInfo, &CSEI_tau_M->Timing.stepSize0);
    rtsiSetdXPtr(&CSEI_tau_M->solverInfo, &CSEI_tau_M->ModelData.derivs);
    rtsiSetContStatesPtr(&CSEI_tau_M->solverInfo, (real_T **)
                         &CSEI_tau_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&CSEI_tau_M->solverInfo,
      &CSEI_tau_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&CSEI_tau_M->solverInfo, (&rtmGetErrorStatus
      (CSEI_tau_M)));
    rtsiSetRTModelPtr(&CSEI_tau_M->solverInfo, CSEI_tau_M);
  }

  rtsiSetSimTimeStep(&CSEI_tau_M->solverInfo, MAJOR_TIME_STEP);
  CSEI_tau_M->ModelData.intgData.y = CSEI_tau_M->ModelData.odeY;
  CSEI_tau_M->ModelData.intgData.f[0] = CSEI_tau_M->ModelData.odeF[0];
  CSEI_tau_M->ModelData.intgData.f[1] = CSEI_tau_M->ModelData.odeF[1];
  CSEI_tau_M->ModelData.intgData.f[2] = CSEI_tau_M->ModelData.odeF[2];
  CSEI_tau_M->ModelData.intgData.f[3] = CSEI_tau_M->ModelData.odeF[3];
  CSEI_tau_M->ModelData.contStates = ((real_T *) &CSEI_tau_X);
  rtsiSetSolverData(&CSEI_tau_M->solverInfo, (void *)
                    &CSEI_tau_M->ModelData.intgData);
  rtsiSetSolverName(&CSEI_tau_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = CSEI_tau_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    CSEI_tau_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    CSEI_tau_M->Timing.sampleTimes = (&CSEI_tau_M->Timing.sampleTimesArray[0]);
    CSEI_tau_M->Timing.offsetTimes = (&CSEI_tau_M->Timing.offsetTimesArray[0]);

    /* task periods */
    CSEI_tau_M->Timing.sampleTimes[0] = (0.0);
    CSEI_tau_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    CSEI_tau_M->Timing.offsetTimes[0] = (0.0);
    CSEI_tau_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(CSEI_tau_M, &CSEI_tau_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = CSEI_tau_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    CSEI_tau_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(CSEI_tau_M, -1);
  CSEI_tau_M->Timing.stepSize0 = 0.01;
  CSEI_tau_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(CSEI_tau_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    CSEI_tau_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(CSEI_tau_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(CSEI_tau_M->rtwLogInfo, (NULL));
    rtliSetLogT(CSEI_tau_M->rtwLogInfo, "tout");
    rtliSetLogX(CSEI_tau_M->rtwLogInfo, "");
    rtliSetLogXFinal(CSEI_tau_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(CSEI_tau_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(CSEI_tau_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(CSEI_tau_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(CSEI_tau_M->rtwLogInfo, 1);
    rtliSetLogY(CSEI_tau_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(CSEI_tau_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(CSEI_tau_M->rtwLogInfo, (NULL));
  }

  CSEI_tau_M->solverInfoPtr = (&CSEI_tau_M->solverInfo);
  CSEI_tau_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&CSEI_tau_M->solverInfo, 0.01);
  rtsiSetSolverMode(&CSEI_tau_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  CSEI_tau_M->ModelData.blockIO = ((void *) &CSEI_tau_B);
  (void) memset(((void *) &CSEI_tau_B), 0,
                sizeof(B_CSEI_tau_T));

  /* parameters */
  CSEI_tau_M->ModelData.defaultParam = ((real_T *)&CSEI_tau_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &CSEI_tau_X;
    CSEI_tau_M->ModelData.contStates = (x);
    (void) memset((void *)&CSEI_tau_X, 0,
                  sizeof(X_CSEI_tau_T));
  }

  /* states (dwork) */
  CSEI_tau_M->ModelData.dwork = ((void *) &CSEI_tau_DW);
  (void) memset((void *)&CSEI_tau_DW, 0,
                sizeof(DW_CSEI_tau_T));

  /* Initialize Sizes */
  CSEI_tau_M->Sizes.numContStates = (6);/* Number of continuous states */
  CSEI_tau_M->Sizes.numY = (0);        /* Number of model outputs */
  CSEI_tau_M->Sizes.numU = (0);        /* Number of model inputs */
  CSEI_tau_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  CSEI_tau_M->Sizes.numSampTimes = (2);/* Number of sample times */
  CSEI_tau_M->Sizes.numBlocks = (26);  /* Number of blocks */
  CSEI_tau_M->Sizes.numBlockIO = (17); /* Number of block outputs */
  CSEI_tau_M->Sizes.numBlockPrms = (87);/* Sum of parameter "widths" */
  return CSEI_tau_M;
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
#ifdef NI_ROOTMODEL_CSEI_tau
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern CSEI_tau_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // integrator_reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&CSEI_tau_B.integrator_reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // eta_0/psi_0
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&CSEI_tau_B.psi_0, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // eta_0/x_0
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&CSEI_tau_B.x_0, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // eta_0/y_0
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&CSEI_tau_B.y_0, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // tau/X
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&CSEI_tau_B.X, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // tau/Y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&CSEI_tau_B.Y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // tau/N
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&CSEI_tau_B.N, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 7;
}

double ni_extout[6];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // eta/x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSEI_tau_B.Integrator1,0,17,0);
  } else {
    index += 1;
  }

  // eta/y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSEI_tau_B.Integrator1,1,17,0);
  } else {
    index += 1;
  }

  // eta/psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSEI_tau_B.Integrator1,2,17,0);
  } else {
    index += 1;
  }

  // nu/u: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSEI_tau_B.Integrator,0,17,0);
  } else {
    index += 1;
  }

  // nu/v: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSEI_tau_B.Integrator,1,17,0);
  } else {
    index += 1;
  }

  // nu/r: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&CSEI_tau_B.Integrator,2,17,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 6;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // eta/x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSEI_tau_B.Integrator1,0,17,0);

  // eta/y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSEI_tau_B.Integrator1,1,17,0);

  // eta/psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSEI_tau_B.Integrator1,2,17,0);

  // nu/u: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSEI_tau_B.Integrator,0,17,0);

  // nu/v: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSEI_tau_B.Integrator,1,17,0);

  // nu/r: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&CSEI_tau_B.Integrator,2,17,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "csei_tau/eta_0/Memory3/X0", offsetof(P_CSEI_tau_T, Memory3_X0), 27, 1, 2,
    0, 0 },

  { 1, "csei_tau/eta_0/Memory4/X0", offsetof(P_CSEI_tau_T, Memory4_X0), 27, 1, 2,
    2, 0 },

  { 2, "csei_tau/eta_0/Memory5/X0", offsetof(P_CSEI_tau_T, Memory5_X0), 27, 1, 2,
    4, 0 },

  { 3, "csei_tau/Integrator/InitialCondition", offsetof(P_CSEI_tau_T,
    Integrator_IC), 28, 3, 2, 6, 0 },

  { 4, "csei_tau/tau/Memory/X0", offsetof(P_CSEI_tau_T, Memory_X0), 27, 1, 2, 8,
    0 },

  { 5, "csei_tau/tau/Memory1/X0", offsetof(P_CSEI_tau_T, Memory1_X0), 27, 1, 2,
    10, 0 },

  { 6, "csei_tau/tau/Memory2/X0", offsetof(P_CSEI_tau_T, Memory2_X0), 27, 1, 2,
    12, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 7;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  3, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "csei_tau/integrator_reset", 0, "", offsetof(B_CSEI_tau_T,
    integrator_reset)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "csei_tau/eta_0/Memory3", 0, "", offsetof(B_CSEI_tau_T, Memory3)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "csei_tau/eta_0/Memory4", 0, "", offsetof(B_CSEI_tau_T, Memory4)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "csei_tau/eta_0/Memory5", 0, "", offsetof(B_CSEI_tau_T, Memory5)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "csei_tau/Integrator1", 0, "(1,1)", offsetof(B_CSEI_tau_T, Integrator1)+0*
    sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 8, 0 },

  { 5, "csei_tau/Integrator1", 0, "(1,2)", offsetof(B_CSEI_tau_T, Integrator1)+1*
    sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 10, 0 },

  { 6, "csei_tau/Integrator1", 0, "(1,3)", offsetof(B_CSEI_tau_T, Integrator1)+2*
    sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 12, 0 },

  { 7, "csei_tau/Integrator", 0, "(1,1)", offsetof(B_CSEI_tau_T, Integrator)+0*
    sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 14, 0 },

  { 8, "csei_tau/Integrator", 0, "(1,2)", offsetof(B_CSEI_tau_T, Integrator)+1*
    sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 16, 0 },

  { 9, "csei_tau/Integrator", 0, "(1,3)", offsetof(B_CSEI_tau_T, Integrator)+2*
    sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 18, 0 },

  { 10, "csei_tau/eta_0/psi_0", 0, "", offsetof(B_CSEI_tau_T, psi_0)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 20, 0 },

  { 11, "csei_tau/eta_0/x_0", 0, "", offsetof(B_CSEI_tau_T, x_0)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 22, 0 },

  { 12, "csei_tau/eta_0/y_0", 0, "", offsetof(B_CSEI_tau_T, y_0)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 24, 0 },

  { 13, "csei_tau/tau/Memory", 0, "", offsetof(B_CSEI_tau_T, Memory)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 26, 0 },

  { 14, "csei_tau/tau/Memory1", 0, "", offsetof(B_CSEI_tau_T, Memory1)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 28, 0 },

  { 15, "csei_tau/tau/Memory2", 0, "", offsetof(B_CSEI_tau_T, Memory2)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 30, 0 },

  { 16, "csei_tau/tau/X", 0, "", offsetof(B_CSEI_tau_T, X)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 32, 0 },

  { 17, "csei_tau/tau/Y", 0, "", offsetof(B_CSEI_tau_T, Y)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 34, 0 },

  { 18, "csei_tau/tau/N", 0, "", offsetof(B_CSEI_tau_T, N)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 36, 0 },

  { 19, "csei_tau/kinetics", 0, "nu_dot(1,1)", offsetof(B_CSEI_tau_T, nu_dot)+0*
    sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 38, 0 },

  { 20, "csei_tau/kinetics", 0, "nu_dot(1,2)", offsetof(B_CSEI_tau_T, nu_dot)+1*
    sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 40, 0 },

  { 21, "csei_tau/kinetics", 0, "nu_dot(1,3)", offsetof(B_CSEI_tau_T, nu_dot)+2*
    sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 42, 0 },

  { 22, "csei_tau/kinematics", 0, "eta_dot(1,1)", offsetof(B_CSEI_tau_T, eta_dot)
    +0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 44, 0 },

  { 23, "csei_tau/kinematics", 0, "eta_dot(1,2)", offsetof(B_CSEI_tau_T, eta_dot)
    +1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 46, 0 },

  { 24, "csei_tau/kinematics", 0, "eta_dot(1,3)", offsetof(B_CSEI_tau_T, eta_dot)
    +2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 48, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 25;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 13;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "integrator_reset", 0, EXT_IN, 1, 1, 1 },

  { 1, "eta_0/psi_0", 1, EXT_IN, 1, 1, 1 },

  { 2, "eta_0/x_0", 1, EXT_IN, 1, 1, 1 },

  { 3, "eta_0/y_0", 1, EXT_IN, 1, 1, 1 },

  { 4, "tau/X", 1, EXT_IN, 1, 1, 1 },

  { 5, "tau/Y", 1, EXT_IN, 1, 1, 1 },

  { 6, "tau/N", 1, EXT_IN, 1, 1, 1 },

  { 0, "eta/x", 0, EXT_OUT, 1, 1, 1 },

  { 1, "eta/y", 0, EXT_OUT, 1, 1, 1 },

  { 2, "eta/psi", 0, EXT_OUT, 1, 1, 1 },

  { 3, "nu/u", 0, EXT_OUT, 1, 1, 1 },

  { 4, "nu/v", 0, EXT_OUT, 1, 1, 1 },

  { 5, "nu/r", 0, EXT_OUT, 1, 1, 1 },

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
  "csei_tau";
static char* NI_CompiledModelVersion = "1.154";
static char* NI_CompiledModelDateTime = "Tue Mar 08 19:35:06 2016";
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
   The undef allows us to access the real CSEI_tau_P
   In the rest of the code CSEI_tau_P is redefine to be the read-side
   of rtParameter.
 */
#undef CSEI_tau_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &CSEI_tau_P, sizeof(P_CSEI_tau_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka CSEI_tau_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_CSEI_tau_T));
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
             (P_CSEI_tau_T));
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
               (P_CSEI_tau_T));

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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_CSEI_tau_T));
    WriteSideDirtyFlag = 0;
    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_CSEI_tau_T));
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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_CSEI_tau_T));
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
      *numContStates = 6;
      *numDiscStates = 137;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_X.Integrator1_CSTATE[0],
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_X.Integrator1_CSTATE[0],
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_X.Integrator1_CSTATE[0],
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_X.Integrator_CSTATE[0],
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_X.Integrator_CSTATE[0],
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_X.Integrator_CSTATE[0],
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&CSEI_tau_DW.integrator_reset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&CSEI_tau_DW.integrator_reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.Memory3_PreviousInput,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.Memory4_PreviousInput,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.Memory4_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.Memory5_PreviousInput,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.Memory5_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.u_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.u_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.v_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.v_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.r_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.r_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.psi_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.psi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.x_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.y_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.y_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.Memory_PreviousInput,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.Memory1_PreviousInput,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.Memory2_PreviousInput,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.X_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.Y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.Y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.N_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.N_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&CSEI_tau_DW.Integrator1_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&CSEI_tau_DW.Integrator1_IWORK.IcNeedsLoading");
    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&CSEI_tau_DW.integrator_reset_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&CSEI_tau_DW.integrator_reset_DWORK2");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.x_DWORK2, count, 18,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.x_DWORK2");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.y_DWORK2, count, 18,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.y_DWORK2");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.psi_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.psi_DWORK2");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.u_DWORK2, count, 18,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.u_DWORK2");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.v_DWORK2, count, 18,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.v_DWORK2");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.r_DWORK2, count, 18,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.r_DWORK2");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.psi_0_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.x_0_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.x_0_DWORK2");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.y_0_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.y_0_DWORK2");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.X_DWORK2, count, 18,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.X_DWORK2");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.Y_DWORK2, count, 18,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.Y_DWORK2");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&CSEI_tau_DW.N_DWORK2, count, 18,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&CSEI_tau_DW.N_DWORK2");
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
    NIRT_SetValueByDataType(&CSEI_tau_X.Integrator1_CSTATE[0], 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_X.Integrator1_CSTATE[0], 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_X.Integrator1_CSTATE[0], 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_X.Integrator_CSTATE[0], 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_X.Integrator_CSTATE[0], 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_X.Integrator_CSTATE[0], 2, contStates[idx
      ++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&CSEI_tau_DW.integrator_reset_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.Memory3_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.Memory4_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.Memory5_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.psi_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.u_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.v_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.r_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.psi_0_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.x_0_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.y_0_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.Memory_PreviousInput, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.Memory1_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.Memory2_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.X_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.Y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.N_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&CSEI_tau_DW.Integrator1_IWORK.IcNeedsLoading, 0,
      discStates[idx++], 10, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.integrator_reset_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.x_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.y_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.psi_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.u_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.v_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.r_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.psi_0_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.x_0_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.y_0_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.X_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.Y_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&CSEI_tau_DW.N_DWORK2, count, discStates[idx++],
        18, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_CSEI_tau
