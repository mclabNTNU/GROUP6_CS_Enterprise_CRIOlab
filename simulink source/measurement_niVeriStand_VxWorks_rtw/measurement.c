/*
 * measurement.c
 *
 * Code generation for model "measurement".
 *
 * Model version              : 1.9
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Dec 16 16:08:37 2015
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "measurement.h"
#include "measurement_private.h"

/* Block signals (auto storage) */
B_measurement_T measurement_B;

/* Block states (auto storage) */
DW_measurement_T measurement_DW;

/* Real-time model */
RT_MODEL_measurement_T measurement_M_;
RT_MODEL_measurement_T *const measurement_M = &measurement_M_;
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

/* Model output function */
static void measurement_output(void)
{
  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Step size'
   *  Memory: '<S1>/counter'
   */
  /* MATLAB Function 'Downsample	signal/MATLAB Function': '<S6>:1' */
  /* '<S6>:1:3' */
  if ((measurement_DW.counter_PreviousInput + 1.0) *
      measurement_P.Stepsize_Value >= 1.0 / measurement_B.Samplingfrequency) {
    /* '<S6>:1:4' */
    /* '<S6>:1:5' */
    measurement_B.count = 0.0;
  } else {
    /* '<S6>:1:7' */
    measurement_B.count = measurement_DW.counter_PreviousInput + 1.0;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Step size'
   *  Memory: '<S2>/Hold'
   *  Product: '<S10>/Divide'
   *  Product: '<S10>/Product'
   *  Product: '<S8>/Divide'
   *  Product: '<S8>/Product'
   *  Product: '<S9>/Divide'
   *  Product: '<S9>/Product'
   *  RandomNumber: '<S10>/White Noise'
   *  RandomNumber: '<S8>/White Noise'
   *  RandomNumber: '<S9>/White Noise'
   *  Sqrt: '<S10>/Sqrt'
   *  Sqrt: '<S8>/Sqrt'
   *  Sqrt: '<S9>/Sqrt'
   *  Sum: '<Root>/Sum'
   */
  /* MATLAB Function 'Sample & hold/MATLAB Function1': '<S7>:1' */
  if (measurement_B.count == 0.0) {
    /* '<S7>:1:4' */
    /* '<S7>:1:5' */
    measurement_B.output[0] = sqrt(measurement_B.Noisepowerposition /
      measurement_P.Stepsize_Value) * measurement_DW.NextOutput +
      measurement_B.x;
    measurement_B.output[1] = sqrt(measurement_B.Noisepowerposition /
      measurement_P.Stepsize_Value) * measurement_DW.NextOutput_n +
      measurement_B.y;
    measurement_B.output[2] = sqrt(measurement_B.Noisepowerheading /
      measurement_P.Stepsize_Value) * measurement_DW.NextOutput_c +
      measurement_B.psi;
  } else {
    /* '<S7>:1:7' */
    measurement_B.output[0] = measurement_DW.Hold_PreviousInput[0];
    measurement_B.output[1] = measurement_DW.Hold_PreviousInput[1];
    measurement_B.output[2] = measurement_DW.Hold_PreviousInput[2];
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function1' */

  /* Switch: '<Root>/Switch' */
  if (measurement_B.enable != 0.0) {
    measurement_B.Switch[0] = measurement_B.output[0];
  } else {
    measurement_B.Switch[0] = measurement_B.x;
  }

  if (measurement_B.enable != 0.0) {
    measurement_B.Switch[1] = measurement_B.output[1];
  } else {
    measurement_B.Switch[1] = measurement_B.y;
  }

  if (measurement_B.enable != 0.0) {
    measurement_B.Switch[2] = measurement_B.output[2];
  } else {
    measurement_B.Switch[2] = measurement_B.psi;
  }

  /* End of Switch: '<Root>/Switch' */
}

/* Model update function */
static void measurement_update(void)
{
  /* Update for Memory: '<S1>/counter' */
  measurement_DW.counter_PreviousInput = measurement_B.count;

  /* Update for RandomNumber: '<S9>/White Noise' */
  measurement_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&measurement_DW.RandSeed) * measurement_P.WhiteNoise_StdDev +
    measurement_P.WhiteNoise_Mean;

  /* Update for RandomNumber: '<S10>/White Noise' */
  measurement_DW.NextOutput_n = rt_nrand_Upu32_Yd_f_pw_snf
    (&measurement_DW.RandSeed_c) * measurement_P.WhiteNoise_StdDev_k +
    measurement_P.WhiteNoise_Mean_a;

  /* Update for RandomNumber: '<S8>/White Noise' */
  measurement_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
    (&measurement_DW.RandSeed_g) * measurement_P.WhiteNoise_StdDev_ko +
    measurement_P.WhiteNoise_Mean_n;

  /* Update for Memory: '<S2>/Hold' */
  measurement_DW.Hold_PreviousInput[0] = measurement_B.output[0];
  measurement_DW.Hold_PreviousInput[1] = measurement_B.output[1];
  measurement_DW.Hold_PreviousInput[2] = measurement_B.output[2];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++measurement_M->Timing.clockTick0)) {
    ++measurement_M->Timing.clockTickH0;
  }

  measurement_M->Timing.t[0] = measurement_M->Timing.clockTick0 *
    measurement_M->Timing.stepSize0 + measurement_M->Timing.clockTickH0 *
    measurement_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void measurement_initialize(void)
{
  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* Start for RandomNumber: '<S9>/White Noise' */
    tmp = floor(measurement_P.WhiteNoise_Seed);
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

    measurement_DW.RandSeed = tseed;
    measurement_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&measurement_DW.RandSeed) * measurement_P.WhiteNoise_StdDev +
      measurement_P.WhiteNoise_Mean;

    /* End of Start for RandomNumber: '<S9>/White Noise' */

    /* Start for RandomNumber: '<S10>/White Noise' */
    tmp = floor(measurement_P.WhiteNoise_Seed_k);
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

    measurement_DW.RandSeed_c = tseed;
    measurement_DW.NextOutput_n = rt_nrand_Upu32_Yd_f_pw_snf
      (&measurement_DW.RandSeed_c) * measurement_P.WhiteNoise_StdDev_k +
      measurement_P.WhiteNoise_Mean_a;

    /* End of Start for RandomNumber: '<S10>/White Noise' */

    /* Start for RandomNumber: '<S8>/White Noise' */
    tmp = floor(measurement_P.WhiteNoise_Seed_j);
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

    measurement_DW.RandSeed_g = tseed;
    measurement_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&measurement_DW.RandSeed_g) * measurement_P.WhiteNoise_StdDev_ko +
      measurement_P.WhiteNoise_Mean_n;

    /* End of Start for RandomNumber: '<S8>/White Noise' */
  }

  /* InitializeConditions for Memory: '<S1>/counter' */
  measurement_DW.counter_PreviousInput = measurement_P.counter_X0;

  /* InitializeConditions for Memory: '<S2>/Hold' */
  measurement_DW.Hold_PreviousInput[0] = measurement_P.Hold_X0;
  measurement_DW.Hold_PreviousInput[1] = measurement_P.Hold_X0;
  measurement_DW.Hold_PreviousInput[2] = measurement_P.Hold_X0;
}

/* Model terminate function */
void measurement_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  measurement_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  measurement_update();
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
  measurement_initialize();
}

void MdlTerminate(void)
{
  measurement_terminate();
}

/* Registration function */
RT_MODEL_measurement_T *measurement(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)measurement_M, 0,
                sizeof(RT_MODEL_measurement_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = measurement_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    measurement_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    measurement_M->Timing.sampleTimes = (&measurement_M->
      Timing.sampleTimesArray[0]);
    measurement_M->Timing.offsetTimes = (&measurement_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    measurement_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    measurement_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(measurement_M, &measurement_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = measurement_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    measurement_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(measurement_M, -1);
  measurement_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    measurement_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(measurement_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(measurement_M->rtwLogInfo, (NULL));
    rtliSetLogT(measurement_M->rtwLogInfo, "tout");
    rtliSetLogX(measurement_M->rtwLogInfo, "");
    rtliSetLogXFinal(measurement_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(measurement_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(measurement_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(measurement_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(measurement_M->rtwLogInfo, 1);
    rtliSetLogY(measurement_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(measurement_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(measurement_M->rtwLogInfo, (NULL));
  }

  measurement_M->solverInfoPtr = (&measurement_M->solverInfo);
  measurement_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&measurement_M->solverInfo, 0.01);
  rtsiSetSolverMode(&measurement_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  measurement_M->ModelData.blockIO = ((void *) &measurement_B);
  (void) memset(((void *) &measurement_B), 0,
                sizeof(B_measurement_T));

  /* parameters */
  measurement_M->ModelData.defaultParam = ((real_T *)&measurement_P);

  /* states (dwork) */
  measurement_M->ModelData.dwork = ((void *) &measurement_DW);
  (void) memset((void *)&measurement_DW, 0,
                sizeof(DW_measurement_T));

  /* Initialize Sizes */
  measurement_M->Sizes.numContStates = (0);/* Number of continuous states */
  measurement_M->Sizes.numY = (0);     /* Number of model outputs */
  measurement_M->Sizes.numU = (0);     /* Number of model inputs */
  measurement_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  measurement_M->Sizes.numSampTimes = (1);/* Number of sample times */
  measurement_M->Sizes.numBlocks = (31);/* Number of blocks */
  measurement_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  measurement_M->Sizes.numBlockPrms = (72);/* Sum of parameter "widths" */
  return measurement_M;
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
#ifdef NI_ROOTMODEL_measurement
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

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern measurement_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // Noise power position
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.Noisepowerposition, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Sampling frequency
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.Samplingfrequency, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Noise power heading
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.Noisepowerheading, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // pose/x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // pose/psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // pose/y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // enable
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.enable, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 7;
}

double ni_extout[3];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // pose measured/x_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&measurement_B.Switch,0,18,0);
  } else {
    index += 1;
  }

  // pose measured/y_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&measurement_B.Switch,1,18,0);
  } else {
    index += 1;
  }

  // pose measured/psi_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&measurement_B.Switch,2,18,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 3;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // pose measured/x_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&measurement_B.Switch,0,18,0);

  // pose measured/y_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&measurement_B.Switch,1,18,0);

  // pose measured/psi_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&measurement_B.Switch,2,18,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "measurement/Downsamplesignal/counter/X0", offsetof(P_measurement_T,
    counter_X0), 23, 1, 2, 0, 0 },

  { 1, "measurement/Step size/Value", offsetof(P_measurement_T, Stepsize_Value),
    23, 1, 2, 2, 0 },

  { 2, "measurement/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_measurement_T, WhiteNoise_Mean), 23, 1, 2, 4, 0 },

  { 3,
    "measurement/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_measurement_T, WhiteNoise_StdDev), 23, 1, 2, 6, 0 },

  { 4, "measurement/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_measurement_T, WhiteNoise_Seed), 23, 1, 2, 8, 0 },

  { 5, "measurement/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_measurement_T, WhiteNoise_Mean_a), 23, 1, 2, 10, 0 },

  { 6,
    "measurement/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_measurement_T, WhiteNoise_StdDev_k), 23, 1, 2, 12, 0 },

  { 7, "measurement/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_measurement_T, WhiteNoise_Seed_k), 23, 1, 2, 14, 0 },

  { 8,
    "measurement/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_measurement_T, WhiteNoise_Mean_n), 23, 1, 2, 16, 0 },

  { 9,
    "measurement/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_measurement_T, WhiteNoise_StdDev_ko), 23, 1, 2, 18, 0 },

  { 10,
    "measurement/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_measurement_T, WhiteNoise_Seed_j), 23, 1, 2, 20, 0 },

  { 11, "measurement/Sample & hold/Hold/X0", offsetof(P_measurement_T, Hold_X0),
    23, 1, 2, 22, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 12;
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
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "measurement/Noise power position", 0, "", offsetof(B_measurement_T,
    Noisepowerposition)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "measurement/Sampling frequency", 0, "", offsetof(B_measurement_T,
    Samplingfrequency)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "measurement/Noise power heading", 0, "", offsetof(B_measurement_T,
    Noisepowerheading)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "measurement/pose/x", 0, "", offsetof(B_measurement_T, x)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "measurement/pose/psi", 0, "", offsetof(B_measurement_T, psi)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "measurement/pose/y", 0, "", offsetof(B_measurement_T, y)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "measurement/enable", 0, "", offsetof(B_measurement_T, enable)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "measurement/Switch", 0, "(1,1)", offsetof(B_measurement_T, Switch)+0*
    sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 14, 0 },

  { 8, "measurement/Switch", 0, "(1,2)", offsetof(B_measurement_T, Switch)+1*
    sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 16, 0 },

  { 9, "measurement/Switch", 0, "(1,3)", offsetof(B_measurement_T, Switch)+2*
    sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 18, 0 },

  { 10, "measurement/Sample & hold/MATLAB Function1", 0, "output(1,1)", offsetof
    (B_measurement_T, output)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 20, 0 },

  { 11, "measurement/Sample & hold/MATLAB Function1", 0, "output(1,2)", offsetof
    (B_measurement_T, output)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 22, 0 },

  { 12, "measurement/Sample & hold/MATLAB Function1", 0, "output(1,3)", offsetof
    (B_measurement_T, output)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 24, 0 },

  { 13, "measurement/Downsamplesignal/MATLAB Function", 0, "count", offsetof
    (B_measurement_T, count)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 26, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 14;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 10;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "Noise power position", 0, EXT_IN, 1, 1, 1 },

  { 1, "Sampling frequency", 0, EXT_IN, 1, 1, 1 },

  { 2, "Noise power heading", 0, EXT_IN, 1, 1, 1 },

  { 3, "pose/x", 0, EXT_IN, 1, 1, 1 },

  { 4, "pose/psi", 0, EXT_IN, 1, 1, 1 },

  { 5, "pose/y", 0, EXT_IN, 1, 1, 1 },

  { 6, "enable", 0, EXT_IN, 1, 1, 1 },

  { 0, "pose measured/x_m", 0, EXT_OUT, 1, 1, 1 },

  { 1, "pose measured/y_m", 0, EXT_OUT, 1, 1, 1 },

  { 2, "pose measured/psi_m", 0, EXT_OUT, 1, 1, 1 },

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
  "measurement";
static char* NI_CompiledModelVersion = "1.9";
static char* NI_CompiledModelDateTime = "Wed Dec 16 16:08:37 2015";
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
   The undef allows us to access the real measurement_P
   In the rest of the code measurement_P is redefine to be the read-side
   of rtParameter.
 */
#undef measurement_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &measurement_P, sizeof(P_measurement_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka measurement_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_measurement_T));
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
             (P_measurement_T));
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
               (P_measurement_T));

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
           (P_measurement_T));
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
           (P_measurement_T));
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
           (P_measurement_T));
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
      *numContStates = 0;
      *numDiscStates = 140;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&measurement_DW.Noisepowerposition_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&measurement_DW.Noisepowerposition_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&measurement_DW.Samplingfrequency_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&measurement_DW.Samplingfrequency_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&measurement_DW.Noisepowerheading_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&measurement_DW.Noisepowerheading_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&measurement_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&measurement_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.NextOutput, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.NextOutput_n, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.NextOutput_n");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.NextOutput_c, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.NextOutput_c");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.Hold_PreviousInput,
      0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.Hold_PreviousInput,
      1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.Hold_PreviousInput,
      2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.enable_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.enable_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.x_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.y_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.psi_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.RandSeed, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.RandSeed_c, 0, 7,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.RandSeed_c");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.RandSeed_g, 0, 7,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.RandSeed_g");
    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&measurement_DW.Noisepowerposition_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&measurement_DW.Noisepowerposition_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&measurement_DW.Samplingfrequency_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&measurement_DW.Samplingfrequency_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&measurement_DW.Noisepowerheading_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&measurement_DW.Noisepowerheading_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.x_DWORK2, count,
        17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.psi_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.y_DWORK2, count,
        17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.enable_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.enable_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.x_m_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.x_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.y_m_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.y_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.psi_m_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.psi_m_DWORK2");
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
  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&measurement_DW.Noisepowerposition_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&measurement_DW.Samplingfrequency_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&measurement_DW.Noisepowerheading_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&measurement_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&measurement_DW.NextOutput, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&measurement_DW.NextOutput_n, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&measurement_DW.NextOutput_c, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&measurement_DW.x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&measurement_DW.psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&measurement_DW.y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&measurement_DW.Hold_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&measurement_DW.Hold_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&measurement_DW.Hold_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&measurement_DW.enable_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&measurement_DW.x_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&measurement_DW.y_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&measurement_DW.psi_m_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&measurement_DW.RandSeed, 0, discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&measurement_DW.RandSeed_c, 0, discStates[idx++], 7,
      0);
    NIRT_SetValueByDataType(&measurement_DW.RandSeed_g, 0, discStates[idx++], 7,
      0);
    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.Noisepowerposition_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.Samplingfrequency_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.Noisepowerheading_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.x_DWORK2, count, discStates[idx++],
        17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.psi_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.y_DWORK2, count, discStates[idx++],
        17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.enable_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.x_m_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.y_m_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.psi_m_DWORK2, count,
        discStates[idx++], 17, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_measurement
