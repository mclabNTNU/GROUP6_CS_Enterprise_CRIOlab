/*
 * u2pwm.c
 *
 * Code generation for model "u2pwm".
 *
 * Model version              : 1.24
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Dec 04 15:19:16 2015
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "u2pwm.h"
#include "u2pwm_private.h"

/* Block signals (auto storage) */
B_u2pwm_T u2pwm_B;

/* Block states (auto storage) */
DW_u2pwm_T u2pwm_DW;

/* Real-time model */
RT_MODEL_u2pwm_T u2pwm_M_;
RT_MODEL_u2pwm_T *const u2pwm_M = &u2pwm_M_;
real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T frac;
  uint32_T bpIndices[2];
  real_T fractions[2];
  real_T yL_1d;
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  /* Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_1d = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
  bpIdx += stride;
  return (((table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx]) -
          yL_1d) * frac + yL_1d;
}

/* Model output function */
static void u2pwm_output(void)
{
  real_T rtb_Gain2;
  real_T rtb_Product11;
  real_T rtb_Saturation3;
  real_T rtb_DLookupTable;
  real_T rtb_DLookupTable1;
  real_T rtb_DLookupTable2;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/VPS_Power_Offset'
   *  Constant: '<Root>/VPS_Power_Offset1'
   *  Gain: '<Root>/VPS_Speed_Gain'
   *  Gain: '<Root>/VPS_Speed_Gain1'
   *  Gain: '<Root>/VPS_Speed_Gain2'
   *  Saturate: '<Root>/Saturation'
   *  Saturate: '<Root>/Saturation1'
   *  Saturate: '<Root>/Saturation2'
   *  Sum: '<Root>/Sum'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<Root>/Sum2'
   */
  if (u2pwm_B.manualoverride != 0.0) {
    u2pwm_B.Switch[0] = u2pwm_B.pwm_BT;
    u2pwm_B.Switch[1] = u2pwm_B.pwm_VSP1;
    u2pwm_B.Switch[2] = u2pwm_B.pwm_VSP2;
    u2pwm_B.Switch[3] = u2pwm_B.pwm_servo1;
    u2pwm_B.Switch[4] = u2pwm_B.pwm_servo2;
    u2pwm_B.Switch[5] = u2pwm_B.pwm_servo3;
    u2pwm_B.Switch[6] = u2pwm_B.pwm_servo4;
  } else {
    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant'
     */
    rtb_Gain2 = u2pwm_B.alpha_VSP1 - u2pwm_P.Constant_Value;

    /* Saturate: '<Root>/Saturation4' */
    if (u2pwm_B.u_VSP1 > u2pwm_P.Saturation4_UpperSat) {
      rtb_Saturation3 = u2pwm_P.Saturation4_UpperSat;
    } else if (u2pwm_B.u_VSP1 < u2pwm_P.Saturation4_LowerSat) {
      rtb_Saturation3 = u2pwm_P.Saturation4_LowerSat;
    } else {
      rtb_Saturation3 = u2pwm_B.u_VSP1;
    }

    /* Gain: '<Root>/Gain4' incorporates:
     *  Saturate: '<Root>/Saturation4'
     */
    rtb_Product11 = u2pwm_P.Gain4_Gain * rtb_Saturation3;

    /* Lookup_n-D: '<Root>/2-D Lookup Table' incorporates:
     *  Gain: '<Root>/Gain'
     *  Product: '<Root>/Product'
     *  Product: '<Root>/Product5'
     *  Trigonometry: '<Root>/Trigonometric Function4'
     *  Trigonometry: '<Root>/Trigonometric Function5'
     */
    rtb_DLookupTable = look2_binlxpw(rtb_Product11 * cos(rtb_Gain2) *
      u2pwm_P.Gain_Gain, rtb_Product11 * sin(rtb_Gain2),
      u2pwm_P.DLookupTable_bp01Data, u2pwm_P.DLookupTable_bp02Data,
      u2pwm_P.DLookupTable_tableData, u2pwm_P.DLookupTable_maxIndex, 5U);

    /* Lookup_n-D: '<Root>/2-D Lookup Table1' incorporates:
     *  Gain: '<Root>/Gain1'
     *  Product: '<Root>/Product6'
     *  Product: '<Root>/Product9'
     *  Trigonometry: '<Root>/Trigonometric Function8'
     *  Trigonometry: '<Root>/Trigonometric Function9'
     */
    rtb_DLookupTable1 = look2_binlxpw(rtb_Product11 * cos(rtb_Gain2) *
      u2pwm_P.Gain1_Gain, rtb_Product11 * sin(rtb_Gain2),
      u2pwm_P.DLookupTable1_bp01Data, u2pwm_P.DLookupTable1_bp02Data,
      u2pwm_P.DLookupTable1_tableData, u2pwm_P.DLookupTable1_maxIndex, 5U);

    /* Sum: '<Root>/Sum4' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    rtb_Gain2 = u2pwm_P.Constant1_Value + u2pwm_B.alpha_VSP2;

    /* Saturate: '<Root>/Saturation3' */
    if (u2pwm_B.u_VSP2 > u2pwm_P.Saturation3_UpperSat) {
      rtb_Saturation3 = u2pwm_P.Saturation3_UpperSat;
    } else if (u2pwm_B.u_VSP2 < u2pwm_P.Saturation3_LowerSat) {
      rtb_Saturation3 = u2pwm_P.Saturation3_LowerSat;
    } else {
      rtb_Saturation3 = u2pwm_B.u_VSP2;
    }

    /* End of Saturate: '<Root>/Saturation3' */

    /* Lookup_n-D: '<Root>/2-D Lookup Table2' incorporates:
     *  Gain: '<Root>/Gain2'
     *  Product: '<Root>/Product7'
     *  Product: '<Root>/Product8'
     *  Trigonometry: '<Root>/Trigonometric Function6'
     *  Trigonometry: '<Root>/Trigonometric Function7'
     */
    rtb_DLookupTable2 = look2_binlxpw(rtb_Saturation3 * cos(rtb_Gain2) *
      u2pwm_P.Gain2_Gain, rtb_Saturation3 * sin(rtb_Gain2),
      u2pwm_P.DLookupTable2_bp01Data, u2pwm_P.DLookupTable2_bp02Data,
      u2pwm_P.DLookupTable2_tableData, u2pwm_P.DLookupTable2_maxIndex, 5U);

    /* Product: '<Root>/Product11' incorporates:
     *  Trigonometry: '<Root>/Trigonometric Function11'
     */
    rtb_Product11 = rtb_Saturation3 * sin(rtb_Gain2);

    /* Gain: '<Root>/Gain3' incorporates:
     *  Product: '<Root>/Product10'
     *  Trigonometry: '<Root>/Trigonometric Function10'
     */
    rtb_Gain2 = rtb_Saturation3 * cos(rtb_Gain2) * u2pwm_P.Gain3_Gain;

    /* Lookup_n-D: '<Root>/2-D Lookup Table3' */
    rtb_Gain2 = look2_binlxpw(rtb_Gain2, rtb_Product11,
      u2pwm_P.DLookupTable3_bp01Data, u2pwm_P.DLookupTable3_bp02Data,
      u2pwm_P.DLookupTable3_tableData, u2pwm_P.DLookupTable3_maxIndex, 5U);

    /* Saturate: '<Root>/Saturation' */
    if (u2pwm_B.u_BT > u2pwm_P.Saturation_UpperSat) {
      rtb_Saturation3 = u2pwm_P.Saturation_UpperSat;
    } else if (u2pwm_B.u_BT < u2pwm_P.Saturation_LowerSat) {
      rtb_Saturation3 = u2pwm_P.Saturation_LowerSat;
    } else {
      rtb_Saturation3 = u2pwm_B.u_BT;
    }

    u2pwm_B.Switch[0] = u2pwm_P.BT_u2pwm_gain * rtb_Saturation3 +
      u2pwm_P.BT_zero_pwm;

    /* Saturate: '<Root>/Saturation1' incorporates:
     *  Constant: '<Root>/VPS_Power_Offset1'
     *  Gain: '<Root>/VPS_Speed_Gain1'
     *  Saturate: '<Root>/Saturation'
     *  Sum: '<Root>/Sum2'
     */
    if (u2pwm_B.omega_VSP1 > u2pwm_P.Saturation1_UpperSat) {
      rtb_Saturation3 = u2pwm_P.Saturation1_UpperSat;
    } else if (u2pwm_B.omega_VSP1 < u2pwm_P.Saturation1_LowerSat) {
      rtb_Saturation3 = u2pwm_P.Saturation1_LowerSat;
    } else {
      rtb_Saturation3 = u2pwm_B.omega_VSP1;
    }

    u2pwm_B.Switch[1] = u2pwm_P.VSP_u2pwm_gain * rtb_Saturation3 +
      u2pwm_P.VSP_zero_pwm;

    /* Saturate: '<Root>/Saturation2' incorporates:
     *  Constant: '<Root>/VPS_Power_Offset'
     *  Gain: '<Root>/VPS_Speed_Gain'
     *  Saturate: '<Root>/Saturation1'
     *  Sum: '<Root>/Sum1'
     */
    if (u2pwm_B.omega_VSP2 > u2pwm_P.Saturation2_UpperSat) {
      rtb_Saturation3 = u2pwm_P.Saturation2_UpperSat;
    } else if (u2pwm_B.omega_VSP2 < u2pwm_P.Saturation2_LowerSat) {
      rtb_Saturation3 = u2pwm_P.Saturation2_LowerSat;
    } else {
      rtb_Saturation3 = u2pwm_B.omega_VSP2;
    }

    u2pwm_B.Switch[2] = u2pwm_P.VSP_u2pwm_gain * rtb_Saturation3 +
      u2pwm_P.VSP_zero_pwm;
    u2pwm_B.Switch[3] = rtb_DLookupTable;
    u2pwm_B.Switch[4] = rtb_DLookupTable1;
    u2pwm_B.Switch[5] = rtb_DLookupTable2;
    u2pwm_B.Switch[6] = rtb_Gain2;
  }

  /* End of Switch: '<Root>/Switch' */
}

/* Model update function */
static void u2pwm_update(void)
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
  if (!(++u2pwm_M->Timing.clockTick0)) {
    ++u2pwm_M->Timing.clockTickH0;
  }

  u2pwm_M->Timing.t[0] = u2pwm_M->Timing.clockTick0 * u2pwm_M->Timing.stepSize0
    + u2pwm_M->Timing.clockTickH0 * u2pwm_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void u2pwm_initialize(void)
{
}

/* Model terminate function */
void u2pwm_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  u2pwm_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  u2pwm_update();
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
  u2pwm_initialize();
}

void MdlTerminate(void)
{
  u2pwm_terminate();
}

/* Registration function */
RT_MODEL_u2pwm_T *u2pwm(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)u2pwm_M, 0,
                sizeof(RT_MODEL_u2pwm_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = u2pwm_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    u2pwm_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    u2pwm_M->Timing.sampleTimes = (&u2pwm_M->Timing.sampleTimesArray[0]);
    u2pwm_M->Timing.offsetTimes = (&u2pwm_M->Timing.offsetTimesArray[0]);

    /* task periods */
    u2pwm_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    u2pwm_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(u2pwm_M, &u2pwm_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = u2pwm_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    u2pwm_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(u2pwm_M, -1);
  u2pwm_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    u2pwm_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(u2pwm_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(u2pwm_M->rtwLogInfo, (NULL));
    rtliSetLogT(u2pwm_M->rtwLogInfo, "tout");
    rtliSetLogX(u2pwm_M->rtwLogInfo, "");
    rtliSetLogXFinal(u2pwm_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(u2pwm_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(u2pwm_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(u2pwm_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(u2pwm_M->rtwLogInfo, 1);
    rtliSetLogY(u2pwm_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(u2pwm_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(u2pwm_M->rtwLogInfo, (NULL));
  }

  u2pwm_M->solverInfoPtr = (&u2pwm_M->solverInfo);
  u2pwm_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&u2pwm_M->solverInfo, 0.01);
  rtsiSetSolverMode(&u2pwm_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  u2pwm_M->ModelData.blockIO = ((void *) &u2pwm_B);
  (void) memset(((void *) &u2pwm_B), 0,
                sizeof(B_u2pwm_T));

  /* parameters */
  u2pwm_M->ModelData.defaultParam = ((real_T *)&u2pwm_P);

  /* states (dwork) */
  u2pwm_M->ModelData.dwork = ((void *) &u2pwm_DW);
  (void) memset((void *)&u2pwm_DW, 0,
                sizeof(DW_u2pwm_T));

  /* Initialize Sizes */
  u2pwm_M->Sizes.numContStates = (0);  /* Number of continuous states */
  u2pwm_M->Sizes.numY = (0);           /* Number of model outputs */
  u2pwm_M->Sizes.numU = (0);           /* Number of model inputs */
  u2pwm_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  u2pwm_M->Sizes.numSampTimes = (1);   /* Number of sample times */
  u2pwm_M->Sizes.numBlocks = (67);     /* Number of blocks */
  u2pwm_M->Sizes.numBlockIO = (16);    /* Number of block outputs */
  u2pwm_M->Sizes.numBlockPrms = (302); /* Sum of parameter "widths" */
  return u2pwm_M;
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
#ifdef NI_ROOTMODEL_u2pwm
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 23:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern u2pwm_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // manual/pwm_BT
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_BT, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // manual/pwm_VSP1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_VSP1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // manual/pwm_VSP2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_VSP2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // manual/pwm_servo1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_servo1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // manual/pwm_servo2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_servo2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // manual/pwm_servo3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_servo3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // manual/pwm_servo4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_servo4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // manual override
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.manualoverride, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u/alpha_VSP1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_VSP1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u/u_VSP1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_VSP1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u/alpha_VSP2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_VSP2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u/u_VSP2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_VSP2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u/u_BT
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_BT, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u/omega_VSP1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.omega_VSP1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u/omega_VSP2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.omega_VSP2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 15;
}

double ni_extout[7];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // pwm/pwm_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,1,17,0);
  } else {
    index += 1;
  }

  // pwm/pwm_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,2,17,0);
  } else {
    index += 1;
  }

  // pwm/pwm_BT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,0,17,0);
  } else {
    index += 1;
  }

  // pwm/pwm_servo4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,6,17,0);
  } else {
    index += 1;
  }

  // pwm/pwm_servo3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,5,17,0);
  } else {
    index += 1;
  }

  // pwm/pwm_servo1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,3,17,0);
  } else {
    index += 1;
  }

  // pwm/pwm_servo2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,4,17,0);
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

  // pwm/pwm_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,1,17,0);

  // pwm/pwm_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,2,17,0);

  // pwm/pwm_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,0,17,0);

  // pwm/pwm_servo4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,6,17,0);

  // pwm/pwm_servo3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,5,17,0);

  // pwm/pwm_servo1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,3,17,0);

  // pwm/pwm_servo2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch,4,17,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "u2pwm/VPS_Speed_Gain1/Gain", offsetof(P_u2pwm_T, BT_u2pwm_gain), 27, 1,
    2, 0, 0 },

  { 1, "u2pwm/VPS_Power_Offset1/Value", offsetof(P_u2pwm_T, BT_zero_pwm), 27, 1,
    2, 2, 0 },

  { 2, "u2pwm/VPS_Speed_Gain/Gain", offsetof(P_u2pwm_T, VSP_u2pwm_gain), 27, 1,
    2, 4, 0 },

  { 3, "u2pwm/VPS_Speed_Gain2/Gain", offsetof(P_u2pwm_T, VSP_u2pwm_gain), 27, 1,
    2, 6, 0 },

  { 4, "u2pwm/VPS_Power_Offset/Value", offsetof(P_u2pwm_T, VSP_zero_pwm), 27, 1,
    2, 8, 0 },

  { 5, "u2pwm/Saturation/UpperLimit", offsetof(P_u2pwm_T, Saturation_UpperSat),
    27, 1, 2, 10, 0 },

  { 6, "u2pwm/Saturation/LowerLimit", offsetof(P_u2pwm_T, Saturation_LowerSat),
    27, 1, 2, 12, 0 },

  { 7, "u2pwm/Saturation1/UpperLimit", offsetof(P_u2pwm_T, Saturation1_UpperSat),
    27, 1, 2, 14, 0 },

  { 8, "u2pwm/Saturation1/LowerLimit", offsetof(P_u2pwm_T, Saturation1_LowerSat),
    27, 1, 2, 16, 0 },

  { 9, "u2pwm/Saturation2/UpperLimit", offsetof(P_u2pwm_T, Saturation2_UpperSat),
    27, 1, 2, 18, 0 },

  { 10, "u2pwm/Saturation2/LowerLimit", offsetof(P_u2pwm_T, Saturation2_LowerSat),
    27, 1, 2, 20, 0 },

  { 11, "u2pwm/Constant/Value", offsetof(P_u2pwm_T, Constant_Value), 27, 1, 2,
    22, 0 },

  { 12, "u2pwm/Saturation4/UpperLimit", offsetof(P_u2pwm_T, Saturation4_UpperSat),
    27, 1, 2, 24, 0 },

  { 13, "u2pwm/Saturation4/LowerLimit", offsetof(P_u2pwm_T, Saturation4_LowerSat),
    27, 1, 2, 26, 0 },

  { 14, "u2pwm/Gain4/Gain", offsetof(P_u2pwm_T, Gain4_Gain), 27, 1, 2, 28, 0 },

  { 15, "u2pwm/Gain/Gain", offsetof(P_u2pwm_T, Gain_Gain), 27, 1, 2, 30, 0 },

  { 16, "u2pwm/2-D Lookup Table/Table", offsetof(P_u2pwm_T,
    DLookupTable_tableData), 28, 25, 2, 32, 0 },

  { 17, "u2pwm/2-D Lookup Table/BreakpointsForDimension1", offsetof(P_u2pwm_T,
    DLookupTable_bp01Data), 29, 5, 2, 34, 0 },

  { 18, "u2pwm/2-D Lookup Table/BreakpointsForDimension2", offsetof(P_u2pwm_T,
    DLookupTable_bp02Data), 29, 5, 2, 36, 0 },

  { 19, "u2pwm/Gain1/Gain", offsetof(P_u2pwm_T, Gain1_Gain), 27, 1, 2, 38, 0 },

  { 20, "u2pwm/2-D Lookup Table1/Table", offsetof(P_u2pwm_T,
    DLookupTable1_tableData), 28, 25, 2, 40, 0 },

  { 21, "u2pwm/2-D Lookup Table1/BreakpointsForDimension1", offsetof(P_u2pwm_T,
    DLookupTable1_bp01Data), 29, 5, 2, 42, 0 },

  { 22, "u2pwm/2-D Lookup Table1/BreakpointsForDimension2", offsetof(P_u2pwm_T,
    DLookupTable1_bp02Data), 29, 5, 2, 44, 0 },

  { 23, "u2pwm/Constant1/Value", offsetof(P_u2pwm_T, Constant1_Value), 27, 1, 2,
    46, 0 },

  { 24, "u2pwm/Saturation3/UpperLimit", offsetof(P_u2pwm_T, Saturation3_UpperSat),
    27, 1, 2, 48, 0 },

  { 25, "u2pwm/Saturation3/LowerLimit", offsetof(P_u2pwm_T, Saturation3_LowerSat),
    27, 1, 2, 50, 0 },

  { 26, "u2pwm/Gain2/Gain", offsetof(P_u2pwm_T, Gain2_Gain), 27, 1, 2, 52, 0 },

  { 27, "u2pwm/2-D Lookup Table2/Table", offsetof(P_u2pwm_T,
    DLookupTable2_tableData), 28, 25, 2, 54, 0 },

  { 28, "u2pwm/2-D Lookup Table2/BreakpointsForDimension1", offsetof(P_u2pwm_T,
    DLookupTable2_bp01Data), 29, 5, 2, 56, 0 },

  { 29, "u2pwm/2-D Lookup Table2/BreakpointsForDimension2", offsetof(P_u2pwm_T,
    DLookupTable2_bp02Data), 29, 5, 2, 58, 0 },

  { 30, "u2pwm/Gain3/Gain", offsetof(P_u2pwm_T, Gain3_Gain), 27, 1, 2, 60, 0 },

  { 31, "u2pwm/2-D Lookup Table3/Table", offsetof(P_u2pwm_T,
    DLookupTable3_tableData), 28, 25, 2, 62, 0 },

  { 32, "u2pwm/2-D Lookup Table3/BreakpointsForDimension1", offsetof(P_u2pwm_T,
    DLookupTable3_bp01Data), 29, 5, 2, 64, 0 },

  { 33, "u2pwm/2-D Lookup Table3/BreakpointsForDimension2", offsetof(P_u2pwm_T,
    DLookupTable3_bp02Data), 29, 5, 2, 66, 0 },

  { 34, "u2pwm/2-D Lookup Table/maxIndex", offsetof(P_u2pwm_T,
    DLookupTable_maxIndex), 22, 2, 2, 68, 0 },

  { 35, "u2pwm/2-D Lookup Table1/maxIndex", offsetof(P_u2pwm_T,
    DLookupTable1_maxIndex), 22, 2, 2, 70, 0 },

  { 36, "u2pwm/2-D Lookup Table2/maxIndex", offsetof(P_u2pwm_T,
    DLookupTable2_maxIndex), 22, 2, 2, 72, 0 },

  { 37, "u2pwm/2-D Lookup Table3/maxIndex", offsetof(P_u2pwm_T,
    DLookupTable3_maxIndex), 22, 2, 2, 74, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 38;
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
  5, 5,                                /* Parameter at index 16 */
  1, 5,                                /* Parameter at index 17 */
  1, 5,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  5, 5,                                /* Parameter at index 20 */
  1, 5,                                /* Parameter at index 21 */
  1, 5,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  5, 5,                                /* Parameter at index 27 */
  1, 5,                                /* Parameter at index 28 */
  1, 5,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  5, 5,                                /* Parameter at index 31 */
  1, 5,                                /* Parameter at index 32 */
  1, 5,                                /* Parameter at index 33 */
  2, 1,                                /* Parameter at index 34 */
  2, 1,                                /* Parameter at index 35 */
  2, 1,                                /* Parameter at index 36 */
  2, 1,                                /* Parameter at index 37 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "u2pwm/manual/pwm_BT", 0, "", offsetof(B_u2pwm_T, pwm_BT)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "u2pwm/manual/pwm_VSP1", 0, "", offsetof(B_u2pwm_T, pwm_VSP1)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "u2pwm/manual/pwm_VSP2", 0, "", offsetof(B_u2pwm_T, pwm_VSP2)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "u2pwm/manual/pwm_servo1", 0, "", offsetof(B_u2pwm_T, pwm_servo1)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "u2pwm/manual/pwm_servo2", 0, "", offsetof(B_u2pwm_T, pwm_servo2)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "u2pwm/manual/pwm_servo3", 0, "", offsetof(B_u2pwm_T, pwm_servo3)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "u2pwm/manual/pwm_servo4", 0, "", offsetof(B_u2pwm_T, pwm_servo4)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "u2pwm/manual override", 0, "", offsetof(B_u2pwm_T, manualoverride)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8, "u2pwm/u/alpha_VSP1", 0, "", offsetof(B_u2pwm_T, alpha_VSP1)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 16, 0 },

  { 9, "u2pwm/u/u_VSP1", 0, "", offsetof(B_u2pwm_T, u_VSP1)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 18, 0 },

  { 10, "u2pwm/u/alpha_VSP2", 0, "", offsetof(B_u2pwm_T, alpha_VSP2)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 20, 0 },

  { 11, "u2pwm/u/u_VSP2", 0, "", offsetof(B_u2pwm_T, u_VSP2)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 22, 0 },

  { 12, "u2pwm/u/u_BT", 0, "", offsetof(B_u2pwm_T, u_BT)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 24, 0 },

  { 13, "u2pwm/u/omega_VSP1", 0, "", offsetof(B_u2pwm_T, omega_VSP1)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 26, 0 },

  { 14, "u2pwm/u/omega_VSP2", 0, "", offsetof(B_u2pwm_T, omega_VSP2)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 28, 0 },

  { 15, "u2pwm/Switch", 0, "(1,1)", offsetof(B_u2pwm_T, Switch)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 30, 0 },

  { 16, "u2pwm/Switch", 0, "(1,2)", offsetof(B_u2pwm_T, Switch)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 32, 0 },

  { 17, "u2pwm/Switch", 0, "(1,3)", offsetof(B_u2pwm_T, Switch)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 34, 0 },

  { 18, "u2pwm/Switch", 0, "(1,4)", offsetof(B_u2pwm_T, Switch)+3*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 36, 0 },

  { 19, "u2pwm/Switch", 0, "(1,5)", offsetof(B_u2pwm_T, Switch)+4*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 38, 0 },

  { 20, "u2pwm/Switch", 0, "(1,6)", offsetof(B_u2pwm_T, Switch)+5*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 40, 0 },

  { 21, "u2pwm/Switch", 0, "(1,7)", offsetof(B_u2pwm_T, Switch)+6*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 42, 0 },

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

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 22;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "manual/pwm_BT", 0, EXT_IN, 1, 1, 1 },

  { 1, "manual/pwm_VSP1", 0, EXT_IN, 1, 1, 1 },

  { 2, "manual/pwm_VSP2", 0, EXT_IN, 1, 1, 1 },

  { 3, "manual/pwm_servo1", 0, EXT_IN, 1, 1, 1 },

  { 4, "manual/pwm_servo2", 0, EXT_IN, 1, 1, 1 },

  { 5, "manual/pwm_servo3", 0, EXT_IN, 1, 1, 1 },

  { 6, "manual/pwm_servo4", 0, EXT_IN, 1, 1, 1 },

  { 7, "manual override", 0, EXT_IN, 1, 1, 1 },

  { 8, "u/alpha_VSP1", 0, EXT_IN, 1, 1, 1 },

  { 9, "u/u_VSP1", 0, EXT_IN, 1, 1, 1 },

  { 10, "u/alpha_VSP2", 0, EXT_IN, 1, 1, 1 },

  { 11, "u/u_VSP2", 0, EXT_IN, 1, 1, 1 },

  { 12, "u/u_BT", 0, EXT_IN, 1, 1, 1 },

  { 13, "u/omega_VSP1", 0, EXT_IN, 1, 1, 1 },

  { 14, "u/omega_VSP2", 0, EXT_IN, 1, 1, 1 },

  { 0, "pwm/pwm_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 1, "pwm/pwm_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 2, "pwm/pwm_BT", 0, EXT_OUT, 1, 1, 1 },

  { 3, "pwm/pwm_servo4", 0, EXT_OUT, 1, 1, 1 },

  { 4, "pwm/pwm_servo3", 0, EXT_OUT, 1, 1, 1 },

  { 5, "pwm/pwm_servo1", 0, EXT_OUT, 1, 1, 1 },

  { 6, "pwm/pwm_servo2", 0, EXT_OUT, 1, 1, 1 },

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
  "u2pwm";
static char* NI_CompiledModelVersion = "1.24";
static char* NI_CompiledModelDateTime = "Fri Dec 04 15:19:16 2015";
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
   The undef allows us to access the real u2pwm_P
   In the rest of the code u2pwm_P is redefine to be the read-side
   of rtParameter.
 */
#undef u2pwm_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &u2pwm_P, sizeof(P_u2pwm_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka u2pwm_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_u2pwm_T));
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
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_u2pwm_T));
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
               (P_u2pwm_T));

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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_u2pwm_T));
    WriteSideDirtyFlag = 0;
    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_u2pwm_T));
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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_u2pwm_T));
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
      *numDiscStates = 210;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_BT_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.manualoverride_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.manualoverride_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_VSP1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_VSP2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_BT_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.omega_VSP1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.omega_VSP2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_VSP1_DWORK1_g, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_VSP1_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_VSP2_DWORK1_f, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_VSP2_DWORK1_f");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_BT_DWORK1_i, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_BT_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo4_DWORK1_p, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo4_DWORK1_p");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo3_DWORK1_a, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo3_DWORK1_a");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo1_DWORK1_f, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo1_DWORK1_f");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo2_DWORK1_h, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo2_DWORK1_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&u2pwm_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&u2pwm_DW.NIVeriStandSignalProbe_DWORK2");
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_BT_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_BT_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_VSP1_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_VSP1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_VSP2_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_VSP2_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo2_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo2_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo3_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo3_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo4_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo4_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.manualoverride_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.manualoverride_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_VSP1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_VSP1_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_VSP2_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_VSP2_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_BT_DWORK2, count, 18,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.omega_VSP1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.omega_VSP2_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_VSP1_DWORK2_k,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_VSP1_DWORK2_k");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_VSP2_DWORK2_c,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_VSP2_DWORK2_c");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_BT_DWORK2_n, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_BT_DWORK2_n");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo4_DWORK2_c,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo4_DWORK2_c");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo3_DWORK2_n,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo3_DWORK2_n");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo1_DWORK2_h,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo1_DWORK2_h");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_servo2_DWORK2_e,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_servo2_DWORK2_e");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_DW.NIVeriStandSignalProbe_DWORK1, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 49; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_DW.NIVeriStandSignalProbe_DWORK3, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_DW.NIVeriStandSignalProbe_DWORK3");
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
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_BT_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_VSP1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_VSP2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.manualoverride_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_VSP1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_VSP1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_VSP2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_VSP2_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_BT_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.omega_VSP1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.omega_VSP2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_VSP1_DWORK1_g, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_VSP2_DWORK1_f, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_BT_DWORK1_i, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo4_DWORK1_p, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo3_DWORK1_a, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo1_DWORK1_f, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo2_DWORK1_h, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.NIVeriStandSignalProbe_DWORK2, 0,
      discStates[idx++], 6, 0);
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_BT_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_VSP1_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_VSP2_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo1_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo2_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo3_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo4_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.manualoverride_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_VSP1_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_VSP1_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_VSP2_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_VSP2_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_BT_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.omega_VSP1_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.omega_VSP2_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_VSP1_DWORK2_k, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_VSP2_DWORK2_c, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_BT_DWORK2_n, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo4_DWORK2_c, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo3_DWORK2_n, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo1_DWORK2_h, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_servo2_DWORK2_e, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.NIVeriStandSignalProbe_DWORK1, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 49; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.NIVeriStandSignalProbe_DWORK3, count,
        discStates[idx++], 19, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_u2pwm
