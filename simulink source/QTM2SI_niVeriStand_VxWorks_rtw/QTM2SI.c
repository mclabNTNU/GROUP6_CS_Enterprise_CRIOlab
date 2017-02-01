/*
 * QTM2SI.c
 *
 * Code generation for model "QTM2SI".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Feb 25 13:54:05 2015
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "QTM2SI.h"
#include "QTM2SI_private.h"

/* Block signals (auto storage) */
B_QTM2SI_T QTM2SI_B;

/* Block states (auto storage) */
DW_QTM2SI_T QTM2SI_DW;

/* Real-time model */
RT_MODEL_QTM2SI_T QTM2SI_M_;
RT_MODEL_QTM2SI_T *const QTM2SI_M = &QTM2SI_M_;
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

/* Model output function */
static void QTM2SI_output(void)
{
  real_T rtb_MathFunction;
  real_T rtb_Gain6;

  /* Gain: '<Root>/Gain' */
  QTM2SI_B.Gain = QTM2SI_P.Gain_Gain * QTM2SI_B.X;

  /* Gain: '<Root>/Gain1' */
  QTM2SI_B.Gain1 = QTM2SI_P.Gain1_Gain * QTM2SI_B.Y;

  /* Gain: '<Root>/Gain2' */
  QTM2SI_B.Gain2 = QTM2SI_P.Gain2_Gain * QTM2SI_B.Z;

  /* Gain: '<Root>/Gain3' */
  QTM2SI_B.Gain3 = QTM2SI_P.Gain3_Gain * QTM2SI_B.Roll;

  /* Gain: '<Root>/Gain4' */
  QTM2SI_B.Gain4 = QTM2SI_P.Gain4_Gain * QTM2SI_B.Pitch;

  /* Gain: '<Root>/Gain5' */
  rtb_MathFunction = QTM2SI_P.Gain5_Gain * QTM2SI_B.Yaw;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_MathFunction > QTM2SI_P.Saturation_UpperSat) {
    rtb_MathFunction = QTM2SI_P.Saturation_UpperSat;
  } else {
    if (rtb_MathFunction < QTM2SI_P.Saturation_LowerSat) {
      rtb_MathFunction = QTM2SI_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Signum: '<Root>/Sign' */
  if (rtb_MathFunction < 0.0) {
    rtb_Gain6 = -1.0;
  } else if (rtb_MathFunction > 0.0) {
    rtb_Gain6 = 1.0;
  } else if (rtb_MathFunction == 0.0) {
    rtb_Gain6 = 0.0;
  } else {
    rtb_Gain6 = rtb_MathFunction;
  }

  /* Gain: '<Root>/Gain6' incorporates:
   *  Signum: '<Root>/Sign'
   */
  rtb_Gain6 *= QTM2SI_P.Gain6_Gain;

  /* Sum: '<Root>/Sum1' */
  rtb_MathFunction += rtb_Gain6;

  /* Math: '<Root>/Math Function' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_MathFunction = rt_remd_snf(rtb_MathFunction, QTM2SI_P.Constant_Value);

  /* Sum: '<Root>/Sum' */
  QTM2SI_B.Sum = rtb_MathFunction - rtb_Gain6;
}

/* Model update function */
static void QTM2SI_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QTM2SI_M->Timing.clockTick0)) {
    ++QTM2SI_M->Timing.clockTickH0;
  }

  QTM2SI_M->Timing.t[0] = QTM2SI_M->Timing.clockTick0 *
    QTM2SI_M->Timing.stepSize0 + QTM2SI_M->Timing.clockTickH0 *
    QTM2SI_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void QTM2SI_initialize(void)
{
}

/* Model terminate function */
void QTM2SI_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  QTM2SI_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  QTM2SI_update();
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
  QTM2SI_initialize();
}

void MdlTerminate(void)
{
  QTM2SI_terminate();
}

/* Registration function */
RT_MODEL_QTM2SI_T *QTM2SI(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)QTM2SI_M, 0,
                sizeof(RT_MODEL_QTM2SI_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = QTM2SI_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    QTM2SI_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    QTM2SI_M->Timing.sampleTimes = (&QTM2SI_M->Timing.sampleTimesArray[0]);
    QTM2SI_M->Timing.offsetTimes = (&QTM2SI_M->Timing.offsetTimesArray[0]);

    /* task periods */
    QTM2SI_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    QTM2SI_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(QTM2SI_M, &QTM2SI_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = QTM2SI_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    QTM2SI_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(QTM2SI_M, -1);
  QTM2SI_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    QTM2SI_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(QTM2SI_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(QTM2SI_M->rtwLogInfo, (NULL));
    rtliSetLogT(QTM2SI_M->rtwLogInfo, "tout");
    rtliSetLogX(QTM2SI_M->rtwLogInfo, "");
    rtliSetLogXFinal(QTM2SI_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(QTM2SI_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(QTM2SI_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(QTM2SI_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(QTM2SI_M->rtwLogInfo, 1);
    rtliSetLogY(QTM2SI_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(QTM2SI_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(QTM2SI_M->rtwLogInfo, (NULL));
  }

  QTM2SI_M->solverInfoPtr = (&QTM2SI_M->solverInfo);
  QTM2SI_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&QTM2SI_M->solverInfo, 0.01);
  rtsiSetSolverMode(&QTM2SI_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  QTM2SI_M->ModelData.blockIO = ((void *) &QTM2SI_B);
  (void) memset(((void *) &QTM2SI_B), 0,
                sizeof(B_QTM2SI_T));

  /* parameters */
  QTM2SI_M->ModelData.defaultParam = ((real_T *)&QTM2SI_P);

  /* states (dwork) */
  QTM2SI_M->ModelData.dwork = ((void *) &QTM2SI_DW);
  (void) memset((void *)&QTM2SI_DW, 0,
                sizeof(DW_QTM2SI_T));

  /* Initialize Sizes */
  QTM2SI_M->Sizes.numContStates = (0); /* Number of continuous states */
  QTM2SI_M->Sizes.numY = (0);          /* Number of model outputs */
  QTM2SI_M->Sizes.numU = (0);          /* Number of model inputs */
  QTM2SI_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  QTM2SI_M->Sizes.numSampTimes = (1);  /* Number of sample times */
  QTM2SI_M->Sizes.numBlocks = (25);    /* Number of blocks */
  QTM2SI_M->Sizes.numBlockIO = (12);   /* Number of block outputs */
  QTM2SI_M->Sizes.numBlockPrms = (82); /* Sum of parameter "widths" */
  return QTM2SI_M;
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
#ifdef NI_ROOTMODEL_QTM2SI
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

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
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

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern QTM2SI_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // X
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&QTM2SI_B.X, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&QTM2SI_B.Y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Pitch
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&QTM2SI_B.Pitch, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Z
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&QTM2SI_B.Z, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Roll
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&QTM2SI_B.Roll, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Yaw
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&QTM2SI_B.Yaw, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 6;
}

double ni_extout[6];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&QTM2SI_B.Gain,0,0,0);
  } else {
    index += 1;
  }

  // y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&QTM2SI_B.Gain1,0,0,0);
  } else {
    index += 1;
  }

  // z: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&QTM2SI_B.Gain2,0,0,0);
  } else {
    index += 1;
  }

  // phi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&QTM2SI_B.Gain3,0,0,0);
  } else {
    index += 1;
  }

  // theta: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&QTM2SI_B.Gain4,0,0,0);
  } else {
    index += 1;
  }

  // psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&QTM2SI_B.Sum,0,0,0);
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

  // x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&QTM2SI_B.Gain,0,0,0);

  // y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&QTM2SI_B.Gain1,0,0,0);

  // z: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&QTM2SI_B.Gain2,0,0,0);

  // phi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&QTM2SI_B.Gain3,0,0,0);

  // theta: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&QTM2SI_B.Gain4,0,0,0);

  // psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&QTM2SI_B.Sum,0,0,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "qtm2si/Gain/Gain", offsetof(P_QTM2SI_T, Gain_Gain), 21, 1, 2, 0, 0 },

  { 1, "qtm2si/Gain1/Gain", offsetof(P_QTM2SI_T, Gain1_Gain), 21, 1, 2, 2, 0 },

  { 2, "qtm2si/Gain2/Gain", offsetof(P_QTM2SI_T, Gain2_Gain), 21, 1, 2, 4, 0 },

  { 3, "qtm2si/Gain3/Gain", offsetof(P_QTM2SI_T, Gain3_Gain), 21, 1, 2, 6, 0 },

  { 4, "qtm2si/Gain4/Gain", offsetof(P_QTM2SI_T, Gain4_Gain), 21, 1, 2, 8, 0 },

  { 5, "qtm2si/Gain5/Gain", offsetof(P_QTM2SI_T, Gain5_Gain), 21, 1, 2, 10, 0 },

  { 6, "qtm2si/Saturation/UpperLimit", offsetof(P_QTM2SI_T, Saturation_UpperSat),
    21, 1, 2, 12, 0 },

  { 7, "qtm2si/Saturation/LowerLimit", offsetof(P_QTM2SI_T, Saturation_LowerSat),
    21, 1, 2, 14, 0 },

  { 8, "qtm2si/Gain6/Gain", offsetof(P_QTM2SI_T, Gain6_Gain), 21, 1, 2, 16, 0 },

  { 9, "qtm2si/Constant/Value", offsetof(P_QTM2SI_T, Constant_Value), 21, 1, 2,
    18, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 10;
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
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "qtm2si/X", 0, "", offsetof(B_QTM2SI_T, X)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 1, "qtm2si/Gain", 0, "", offsetof(B_QTM2SI_T, Gain)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "qtm2si/Y", 0, "", offsetof(B_QTM2SI_T, Y)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 4, 0 },

  { 3, "qtm2si/Gain1", 0, "", offsetof(B_QTM2SI_T, Gain1)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "qtm2si/Pitch", 0, "", offsetof(B_QTM2SI_T, Pitch)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "qtm2si/Z", 0, "", offsetof(B_QTM2SI_T, Z)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 10, 0 },

  { 6, "qtm2si/Gain2", 0, "", offsetof(B_QTM2SI_T, Gain2)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "qtm2si/Roll", 0, "", offsetof(B_QTM2SI_T, Roll)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8, "qtm2si/Gain3", 0, "", offsetof(B_QTM2SI_T, Gain3)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 16, 0 },

  { 9, "qtm2si/Gain4", 0, "", offsetof(B_QTM2SI_T, Gain4)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 18, 0 },

  { 10, "qtm2si/Yaw", 0, "", offsetof(B_QTM2SI_T, Yaw)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 20, 0 },

  { 11, "qtm2si/Sum", 0, "", offsetof(B_QTM2SI_T, Sum)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 22, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 12;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 12;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "X", 0, EXT_IN, 1, 1, 1 },

  { 1, "Y", 0, EXT_IN, 1, 1, 1 },

  { 2, "Pitch", 0, EXT_IN, 1, 1, 1 },

  { 3, "Z", 0, EXT_IN, 1, 1, 1 },

  { 4, "Roll", 0, EXT_IN, 1, 1, 1 },

  { 5, "Yaw", 0, EXT_IN, 1, 1, 1 },

  { 0, "x", 0, EXT_OUT, 1, 1, 1 },

  { 1, "y", 0, EXT_OUT, 1, 1, 1 },

  { 2, "z", 0, EXT_OUT, 1, 1, 1 },

  { 3, "phi", 0, EXT_OUT, 1, 1, 1 },

  { 4, "theta", 0, EXT_OUT, 1, 1, 1 },

  { 5, "psi", 0, EXT_OUT, 1, 1, 1 },

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
  "qtm2si";
static char* NI_CompiledModelVersion = "1.7";
static char* NI_CompiledModelDateTime = "Wed Feb 25 13:54:05 2015";
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
   The undef allows us to access the real QTM2SI_P
   In the rest of the code QTM2SI_P is redefine to be the read-side
   of rtParameter.
 */
#undef QTM2SI_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &QTM2SI_P, sizeof(P_QTM2SI_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka QTM2SI_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_QTM2SI_T));
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
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_QTM2SI_T));
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
               (P_QTM2SI_T));

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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_QTM2SI_T));
    WriteSideDirtyFlag = 0;
    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_QTM2SI_T));
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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_QTM2SI_T));
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
      *numDiscStates = 96;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.X_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.Y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.Y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.Pitch_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.Pitch_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.Z_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.Z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.z_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.Roll_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.Roll_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.phi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.phi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.theta_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.theta_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.Yaw_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.Yaw_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.psi_DWORK1");
    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.X_DWORK2, count, 17,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.X_DWORK2");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.x_DWORK2, count, 17,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.x_DWORK2");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.Y_DWORK2, count, 17,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.Y_DWORK2");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.y_DWORK2, count, 17,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.y_DWORK2");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.Pitch_DWORK2, count,
        17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.Pitch_DWORK2");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.Z_DWORK2, count, 17,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.Z_DWORK2");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.z_DWORK2, count, 17,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.z_DWORK2");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.Roll_DWORK2, count,
        17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.Roll_DWORK2");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.phi_DWORK2, count, 17,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.phi_DWORK2");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.theta_DWORK2, count,
        17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.theta_DWORK2");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.Yaw_DWORK2, count, 17,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.Yaw_DWORK2");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&QTM2SI_DW.psi_DWORK2, count, 17,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&QTM2SI_DW.psi_DWORK2");
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
    NIRT_SetValueByDataType(&QTM2SI_DW.X_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&QTM2SI_DW.x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&QTM2SI_DW.Y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&QTM2SI_DW.y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&QTM2SI_DW.Pitch_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&QTM2SI_DW.Z_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&QTM2SI_DW.z_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&QTM2SI_DW.Roll_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&QTM2SI_DW.phi_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&QTM2SI_DW.theta_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&QTM2SI_DW.Yaw_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&QTM2SI_DW.psi_DWORK1, 0, discStates[idx++], 0, 0);
    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&QTM2SI_DW.X_DWORK2, count, discStates[idx++], 17,
        0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&QTM2SI_DW.x_DWORK2, count, discStates[idx++], 17,
        0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&QTM2SI_DW.Y_DWORK2, count, discStates[idx++], 17,
        0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&QTM2SI_DW.y_DWORK2, count, discStates[idx++], 17,
        0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&QTM2SI_DW.Pitch_DWORK2, count, discStates[idx++],
        17, 0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&QTM2SI_DW.Z_DWORK2, count, discStates[idx++], 17,
        0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&QTM2SI_DW.z_DWORK2, count, discStates[idx++], 17,
        0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&QTM2SI_DW.Roll_DWORK2, count, discStates[idx++],
        17, 0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&QTM2SI_DW.phi_DWORK2, count, discStates[idx++],
        17, 0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&QTM2SI_DW.theta_DWORK2, count, discStates[idx++],
        17, 0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&QTM2SI_DW.Yaw_DWORK2, count, discStates[idx++],
        17, 0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&QTM2SI_DW.psi_DWORK2, count, discStates[idx++],
        17, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_QTM2SI
