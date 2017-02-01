/*
 * ctrl_DP_basic.h
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
#ifndef RTW_HEADER_ctrl_DP_basic_h_
#define RTW_HEADER_ctrl_DP_basic_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ctrl_DP_basic_COMMON_INCLUDES_
# define ctrl_DP_basic_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_DP_basic_COMMON_INCLUDES_ */

#include "ctrl_DP_basic_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define ctrl_DP_basic_rtModel          RT_MODEL_ctrl_DP_basic_T

/* Block signals for system '<S22>/MATLAB Function' */
typedef struct {
  real_T K_p[9];                       /* '<S22>/MATLAB Function' */
} B_MATLABFunction_ctrl_DP_basi_T;

/* Block signals for system '<S22>/MATLAB Function1' */
typedef struct {
  real_T K_i[9];                       /* '<S22>/MATLAB Function1' */
} B_MATLABFunction1_ctrl_DP_bas_T;

/* Block signals for system '<S22>/MATLAB Function2' */
typedef struct {
  real_T K_d[9];                       /* '<S22>/MATLAB Function2' */
} B_MATLABFunction2_ctrl_DP_bas_T;

/* Block signals (auto storage) */
typedef struct {
  real_T K_p_x;                        /* '<S22>/K_p_x' */
  real_T K_p_y;                        /* '<S22>/K_p_y' */
  real_T K_p_psi;                      /* '<S22>/K_p_psi' */
  real_T K_i_psi;                      /* '<S22>/K_i_psi' */
  real_T K_i_x;                        /* '<S22>/K_i_x' */
  real_T K_i_y;                        /* '<S22>/K_i_y' */
  real_T K_d_psi;                      /* '<S22>/K_d_psi' */
  real_T K_d_x;                        /* '<S22>/K_d_x' */
  real_T K_d_y;                        /* '<S22>/K_d_y' */
  real_T x;                            /* '<Root>/x' */
  real_T y;                            /* '<Root>/y' */
  real_T psi;                          /* '<Root>/psi' */
  real_T reset;                        /* '<S5>/reset' */
  real_T w_d_x;                        /* '<S23>/w_d_x' */
  real_T w_d_y;                        /* '<S23>/w_d_y' */
  real_T w_d_psi;                      /* '<S23>/w_d_psi' */
  real_T zeta_psi;                     /* '<S23>/zeta_psi' */
  real_T zeta_x;                       /* '<S23>/zeta_x' */
  real_T zeta_y;                       /* '<S23>/zeta_y' */
  real_T psi_ref;                      /* '<S5>/psi_ref' */
  real_T x_ref;                        /* '<S5>/x_ref' */
  real_T y_ref;                        /* '<S5>/y_ref' */
  real_T Integrator1[3];               /* '<S15>/Integrator1' */
  real_T Sum;                          /* '<S16>/Sum' */
  real_T regulationerror[3];           /* '<S10>/Sum2' */
  real_T TmpSignalConversionAtMatrixMult[3];/* '<S10>/Transposed rotation  matrix in yaw1' */
  real_T Integrator1_g[3];             /* '<S6>/Integrator1' */
  real_T Integrator3[3];               /* '<S15>/Integrator3' */
  real_T Sum4[3];                      /* '<S10>/Sum4' */
  real_T Sum3[3];                      /* '<S10>/Sum3' */
  real_T Integrator[3];                /* '<S6>/Integrator' */
  real_T Sum_f;                        /* '<S38>/Sum' */
  real_T Integrator2[3];               /* '<S6>/Integrator2' */
  real_T M1[3];                        /* '<S6>/M^-1' */
  real_T MatrixMultiply[3];            /* '<S15>/Matrix Multiply' */
  real_T Sum5[3];                      /* '<S15>/Sum5' */
  real_T MatrixMultiply1[3];           /* '<S6>/Matrix Multiply1' */
  real_T Sum1[3];                      /* '<S6>/Sum1' */
  real_T Row3;                         /* '<S21>/Row3' */
  real_T Row1;                         /* '<S21>/Row1' */
  real_T Row2;                         /* '<S21>/Row2' */
  real_T u_BT;                         /* '<Root>/Thrust allocation' */
  real_T u_VSP;                        /* '<Root>/Thrust allocation' */
  real_T alpha_VSP;                    /* '<Root>/Thrust allocation' */
  real_T omega_VSP;                    /* '<Root>/Thrust allocation' */
  B_MATLABFunction2_ctrl_DP_bas_T sf_MATLABFunction2_p;/* '<S24>/MATLAB Function2' */
  B_MATLABFunction1_ctrl_DP_bas_T sf_MATLABFunction1_c;/* '<S24>/MATLAB Function1' */
  B_MATLABFunction_ctrl_DP_basi_T sf_MATLABFunction_l;/* '<S24>/MATLAB Function' */
  B_MATLABFunction2_ctrl_DP_bas_T sf_MATLABFunction2;/* '<S22>/MATLAB Function2' */
  B_MATLABFunction1_ctrl_DP_bas_T sf_MATLABFunction1;/* '<S22>/MATLAB Function1' */
  B_MATLABFunction_ctrl_DP_basi_T sf_MATLABFunction;/* '<S22>/MATLAB Function' */
} B_ctrl_DP_basic_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T K_p_x_DWORK1;                 /* '<S22>/K_p_x' */
  real_T K_p_y_DWORK1;                 /* '<S22>/K_p_y' */
  real_T K_p_psi_DWORK1;               /* '<S22>/K_p_psi' */
  real_T K_i_psi_DWORK1;               /* '<S22>/K_i_psi' */
  real_T K_i_x_DWORK1;                 /* '<S22>/K_i_x' */
  real_T K_i_y_DWORK1;                 /* '<S22>/K_i_y' */
  real_T K_d_psi_DWORK1;               /* '<S22>/K_d_psi' */
  real_T K_d_x_DWORK1;                 /* '<S22>/K_d_x' */
  real_T K_d_y_DWORK1;                 /* '<S22>/K_d_y' */
  real_T x_DWORK1;                     /* '<Root>/x' */
  real_T y_DWORK1;                     /* '<Root>/y' */
  real_T psi_DWORK1;                   /* '<Root>/psi' */
  real_T reset_DWORK1;                 /* '<S5>/reset' */
  real_T w_d_x_DWORK1;                 /* '<S23>/w_d_x' */
  real_T w_d_y_DWORK1;                 /* '<S23>/w_d_y' */
  real_T w_d_psi_DWORK1;               /* '<S23>/w_d_psi' */
  real_T zeta_psi_DWORK1;              /* '<S23>/zeta_psi' */
  real_T zeta_x_DWORK1;                /* '<S23>/zeta_x' */
  real_T zeta_y_DWORK1;                /* '<S23>/zeta_y' */
  real_T psi_ref_DWORK1;               /* '<S5>/psi_ref' */
  real_T x_ref_DWORK1;                 /* '<S5>/x_ref' */
  real_T y_ref_DWORK1;                 /* '<S5>/y_ref' */
  real_T alpha_VSP2_DWORK1;            /* '<Root>/alpha_VSP2' */
  real_T omega_VSP1_DWORK1;            /* '<Root>/omega_VSP1' */
  real_T omega_VSP2_DWORK1;            /* '<Root>/omega_VSP2' */
  real_T alpha_VSP1_DWORK1;            /* '<Root>/alpha_VSP1' */
  real_T u_BT_DWORK1;                  /* '<Root>/u_BT' */
  real_T u_VSP1_DWORK1;                /* '<Root>/u_VSP1' */
  real_T x_hat_DWORK1;                 /* '<S41>/x_hat' */
  real_T y_hat_DWORK1;                 /* '<S41>/y_hat' */
  real_T psi_hat_DWORK1;               /* '<S41>/psi_hat' */
  real_T u_hat_DWORK1;                 /* '<S43>/u_hat' */
  real_T v_hat_DWORK1;                 /* '<S43>/v_hat' */
  real_T r_hat_DWORK1;                 /* '<S43>/r_hat' */
  real_T u_dot_hat_DWORK1;             /* '<S42>/u_dot_hat' */
  real_T v_dot_hat_DWORK1;             /* '<S42>/v_dot_hat' */
  real_T r_dot_hat_DWORK1;             /* '<S42>/r_dot_hat' */
  real_T b_x_hat_DWORK1;               /* '<S40>/b_x_hat' */
  real_T b_y_hat_DWORK1;               /* '<S40>/b_y_hat' */
  real_T b_psi_hat_DWORK1;             /* '<S40>/b_psi_hat' */
  real_T u_VSP2_DWORK1;                /* '<Root>/u_VSP2' */
  real_T tau_N_DWORK1;                 /* '<S2>/tau_N' */
  real_T tau_X_DWORK1;                 /* '<S2>/tau_X' */
  real_T tau_Y_DWORK1;                 /* '<S2>/tau_Y' */
  real_T psi_tilde_DWORK1;             /* '<S2>/psi_tilde' */
  real_T x_tilde_DWORK1;               /* '<S2>/x_tilde' */
  real_T y_tidle_DWORK1;               /* '<S2>/y_tidle' */
  real_T r_tilde_DWORK1;               /* '<S2>/r_tilde' */
  real_T u_tilde_DWORK1;               /* '<S2>/u_tilde' */
  real_T v_tilde_DWORK1;               /* '<S2>/v_tilde' */
  real_T x_d_DWORK1;                   /* '<S4>/x_d' */
  real_T y_d_DWORK1;                   /* '<S4>/y_d' */
  real_T psi_d_DWORK1;                 /* '<S4>/psi_d' */
  real_T r_d_DWORK1;                   /* '<S4>/r_d' */
  real_T u_d_DWORK1;                   /* '<S4>/u_d' */
  real_T v_d_DWORK1;                   /* '<S4>/v_d' */
  int32_T NIVeriStandSignalProbe_DWORK2;/* '<Root>/NIVeriStandSignalProbe' */
  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK;                 /* '<S15>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S6>/Integrator' */

  uint8_T K_p_x_DWORK2[14];            /* '<S22>/K_p_x' */
  uint8_T K_p_y_DWORK2[14];            /* '<S22>/K_p_y' */
  uint8_T K_p_psi_DWORK2[14];          /* '<S22>/K_p_psi' */
  uint8_T K_i_psi_DWORK2[14];          /* '<S22>/K_i_psi' */
  uint8_T K_i_x_DWORK2[14];            /* '<S22>/K_i_x' */
  uint8_T K_i_y_DWORK2[14];            /* '<S22>/K_i_y' */
  uint8_T K_d_psi_DWORK2[14];          /* '<S22>/K_d_psi' */
  uint8_T K_d_x_DWORK2[14];            /* '<S22>/K_d_x' */
  uint8_T K_d_y_DWORK2[14];            /* '<S22>/K_d_y' */
  uint8_T x_DWORK2[14];                /* '<Root>/x' */
  uint8_T y_DWORK2[14];                /* '<Root>/y' */
  uint8_T psi_DWORK2[14];              /* '<Root>/psi' */
  uint8_T reset_DWORK2[14];            /* '<S5>/reset' */
  uint8_T w_d_x_DWORK2[14];            /* '<S23>/w_d_x' */
  uint8_T w_d_y_DWORK2[14];            /* '<S23>/w_d_y' */
  uint8_T w_d_psi_DWORK2[14];          /* '<S23>/w_d_psi' */
  uint8_T zeta_psi_DWORK2[14];         /* '<S23>/zeta_psi' */
  uint8_T zeta_x_DWORK2[14];           /* '<S23>/zeta_x' */
  uint8_T zeta_y_DWORK2[14];           /* '<S23>/zeta_y' */
  uint8_T psi_ref_DWORK2[14];          /* '<S5>/psi_ref' */
  uint8_T x_ref_DWORK2[14];            /* '<S5>/x_ref' */
  uint8_T y_ref_DWORK2[14];            /* '<S5>/y_ref' */
  uint8_T alpha_VSP2_DWORK2[14];       /* '<Root>/alpha_VSP2' */
  uint8_T omega_VSP1_DWORK2[14];       /* '<Root>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2[14];       /* '<Root>/omega_VSP2' */
  uint8_T alpha_VSP1_DWORK2[14];       /* '<Root>/alpha_VSP1' */
  uint8_T u_BT_DWORK2[14];             /* '<Root>/u_BT' */
  uint8_T u_VSP1_DWORK2[14];           /* '<Root>/u_VSP1' */
  uint8_T x_hat_DWORK2[14];            /* '<S41>/x_hat' */
  uint8_T y_hat_DWORK2[14];            /* '<S41>/y_hat' */
  uint8_T psi_hat_DWORK2[14];          /* '<S41>/psi_hat' */
  uint8_T u_hat_DWORK2[14];            /* '<S43>/u_hat' */
  uint8_T v_hat_DWORK2[14];            /* '<S43>/v_hat' */
  uint8_T r_hat_DWORK2[14];            /* '<S43>/r_hat' */
  uint8_T u_dot_hat_DWORK2[14];        /* '<S42>/u_dot_hat' */
  uint8_T v_dot_hat_DWORK2[14];        /* '<S42>/v_dot_hat' */
  uint8_T r_dot_hat_DWORK2[14];        /* '<S42>/r_dot_hat' */
  uint8_T b_x_hat_DWORK2[14];          /* '<S40>/b_x_hat' */
  uint8_T b_y_hat_DWORK2[14];          /* '<S40>/b_y_hat' */
  uint8_T b_psi_hat_DWORK2[14];        /* '<S40>/b_psi_hat' */
  uint8_T u_VSP2_DWORK2[14];           /* '<Root>/u_VSP2' */
  uint8_T tau_N_DWORK2[14];            /* '<S2>/tau_N' */
  uint8_T tau_X_DWORK2[14];            /* '<S2>/tau_X' */
  uint8_T tau_Y_DWORK2[14];            /* '<S2>/tau_Y' */
  uint8_T psi_tilde_DWORK2[14];        /* '<S2>/psi_tilde' */
  uint8_T x_tilde_DWORK2[14];          /* '<S2>/x_tilde' */
  uint8_T y_tidle_DWORK2[14];          /* '<S2>/y_tidle' */
  uint8_T r_tilde_DWORK2[14];          /* '<S2>/r_tilde' */
  uint8_T u_tilde_DWORK2[14];          /* '<S2>/u_tilde' */
  uint8_T v_tilde_DWORK2[14];          /* '<S2>/v_tilde' */
  uint8_T x_d_DWORK2[14];              /* '<S4>/x_d' */
  uint8_T y_d_DWORK2[14];              /* '<S4>/y_d' */
  uint8_T psi_d_DWORK2[14];            /* '<S4>/psi_d' */
  uint8_T r_d_DWORK2[14];              /* '<S4>/r_d' */
  uint8_T u_d_DWORK2[14];              /* '<S4>/u_d' */
  uint8_T v_d_DWORK2[14];              /* '<S4>/v_d' */
  uint8_T NIVeriStandSignalProbe_DWORK1[14];/* '<Root>/NIVeriStandSignalProbe' */
  uint8_T NIVeriStandSignalProbe_DWORK3[57];/* '<Root>/NIVeriStandSignalProbe' */
} DW_ctrl_DP_basic_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S15>/Integrator1' */
  real_T Integrator_CSTATE[3];         /* '<S10>/Integrator' */
  real_T Integrator1_CSTATE_g[3];      /* '<S6>/Integrator1' */
  real_T Integrator3_CSTATE[3];        /* '<S15>/Integrator3' */
  real_T Integrator_CSTATE_l[3];       /* '<S6>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S6>/Integrator2' */
  real_T Integrator2_CSTATE_e[3];      /* '<S15>/Integrator2' */
} X_ctrl_DP_basic_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S15>/Integrator1' */
  real_T Integrator_CSTATE[3];         /* '<S10>/Integrator' */
  real_T Integrator1_CSTATE_g[3];      /* '<S6>/Integrator1' */
  real_T Integrator3_CSTATE[3];        /* '<S15>/Integrator3' */
  real_T Integrator_CSTATE_l[3];       /* '<S6>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S6>/Integrator2' */
  real_T Integrator2_CSTATE_e[3];      /* '<S15>/Integrator2' */
} XDot_ctrl_DP_basic_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE[3];     /* '<S15>/Integrator1' */
  boolean_T Integrator_CSTATE[3];      /* '<S10>/Integrator' */
  boolean_T Integrator1_CSTATE_g[3];   /* '<S6>/Integrator1' */
  boolean_T Integrator3_CSTATE[3];     /* '<S15>/Integrator3' */
  boolean_T Integrator_CSTATE_l[3];    /* '<S6>/Integrator' */
  boolean_T Integrator2_CSTATE[3];     /* '<S6>/Integrator2' */
  boolean_T Integrator2_CSTATE_e[3];   /* '<S15>/Integrator2' */
} XDis_ctrl_DP_basic_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator1_Reset_ZCE;    /* '<S15>/Integrator1' */
  ZCSigState Integrator_Reset_ZCE;     /* '<S10>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE_e;  /* '<S6>/Integrator1' */
  ZCSigState Integrator3_Reset_ZCE;    /* '<S15>/Integrator3' */
  ZCSigState Integrator_Reset_ZCE_n;   /* '<S6>/Integrator' */
  ZCSigState Integrator2_Reset_ZCE;    /* '<S6>/Integrator2' */
  ZCSigState Integrator2_Reset_ZCE_m;  /* '<S15>/Integrator2' */
} PrevZCX_ctrl_DP_basic_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_DP_basic_B
#define BlockIO                        B_ctrl_DP_basic_T
#define rtX                            ctrl_DP_basic_X
#define ContinuousStates               X_ctrl_DP_basic_T
#define rtXdot                         ctrl_DP_basic_XDot
#define StateDerivatives               XDot_ctrl_DP_basic_T
#define tXdis                          ctrl_DP_basic_XDis
#define StateDisabled                  XDis_ctrl_DP_basic_T
#define rtP                            ctrl_DP_basic_P
#define Parameters                     P_ctrl_DP_basic_T
#define rtDWork                        ctrl_DP_basic_DW
#define D_Work                         DW_ctrl_DP_basic_T
#define rtPrevZCSigState               ctrl_DP_basic_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_DP_basic_T

/* Parameters (auto storage) */
struct P_ctrl_DP_basic_T_ {
  real_T K_p_x_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  real_T K_p_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  real_T K_p_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  real_T K_p_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  real_T K_p_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  real_T K_p_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  real_T K_p_y_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  real_T K_p_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  real_T K_p_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  real_T K_p_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  real_T K_p_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  real_T K_p_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  real_T K_p_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  real_T K_p_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  real_T K_p_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  real_T K_p_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  real_T K_p_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  real_T K_p_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  real_T K_i_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  real_T K_i_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  real_T K_i_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  real_T K_i_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  real_T K_i_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  real_T K_i_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  real_T K_i_x_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  real_T K_i_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  real_T K_i_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  real_T K_i_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  real_T K_i_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  real_T K_i_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  real_T K_i_y_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  real_T K_i_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  real_T K_i_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  real_T K_i_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  real_T K_i_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  real_T K_i_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  real_T K_d_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  real_T K_d_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  real_T K_d_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  real_T K_d_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  real_T K_d_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  real_T K_d_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  real_T K_d_x_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  real_T K_d_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  real_T K_d_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  real_T K_d_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  real_T K_d_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  real_T K_d_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  real_T K_d_y_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  real_T K_d_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  real_T K_d_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  real_T K_d_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  real_T K_d_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  real_T K_d_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  real_T x_P1;                         /* Expression: width
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P2;                         /* Expression: dtype
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P3;                         /* Expression: portnum
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P4;                         /* Expression: stime
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P5;                         /* Expression: stype
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P6;                         /* Expression: btype
                                        * Referenced by: '<Root>/x'
                                        */
  real_T y_P1;                         /* Expression: width
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P2;                         /* Expression: dtype
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P3;                         /* Expression: portnum
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P4;                         /* Expression: stime
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P5;                         /* Expression: stype
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P6;                         /* Expression: btype
                                        * Referenced by: '<Root>/y'
                                        */
  real_T psi_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1e10
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1e10
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: pi
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T reset_P1;                     /* Expression: width
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P2;                     /* Expression: dtype
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P3;                     /* Expression: portnum
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P4;                     /* Expression: stime
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P5;                     /* Expression: stype
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P6;                     /* Expression: btype
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant8'
                                        */
  real_T w_d_x_P1;                     /* Expression: width
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  real_T w_d_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  real_T w_d_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  real_T w_d_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  real_T w_d_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  real_T w_d_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  real_T w_d_y_P1;                     /* Expression: width
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  real_T w_d_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  real_T w_d_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  real_T w_d_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  real_T w_d_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  real_T w_d_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  real_T w_d_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  real_T w_d_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  real_T w_d_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  real_T w_d_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  real_T w_d_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  real_T w_d_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  real_T zeta_psi_P1;                  /* Expression: width
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  real_T zeta_psi_P2;                  /* Expression: dtype
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  real_T zeta_psi_P3;                  /* Expression: portnum
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  real_T zeta_psi_P4;                  /* Expression: stime
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  real_T zeta_psi_P5;                  /* Expression: stype
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  real_T zeta_psi_P6;                  /* Expression: btype
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  real_T zeta_x_P1;                    /* Expression: width
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  real_T zeta_x_P2;                    /* Expression: dtype
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  real_T zeta_x_P3;                    /* Expression: portnum
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  real_T zeta_x_P4;                    /* Expression: stime
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  real_T zeta_x_P5;                    /* Expression: stype
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  real_T zeta_x_P6;                    /* Expression: btype
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  real_T zeta_y_P1;                    /* Expression: width
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  real_T zeta_y_P2;                    /* Expression: dtype
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  real_T zeta_y_P3;                    /* Expression: portnum
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  real_T zeta_y_P4;                    /* Expression: stime
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  real_T zeta_y_P5;                    /* Expression: stype
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  real_T zeta_y_P6;                    /* Expression: btype
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  real_T psi_ref_P1;                   /* Expression: width
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  real_T psi_ref_P2;                   /* Expression: dtype
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  real_T psi_ref_P3;                   /* Expression: portnum
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  real_T psi_ref_P4;                   /* Expression: stime
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  real_T psi_ref_P5;                   /* Expression: stype
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  real_T psi_ref_P6;                   /* Expression: btype
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  real_T x_ref_P1;                     /* Expression: width
                                        * Referenced by: '<S5>/x_ref'
                                        */
  real_T x_ref_P2;                     /* Expression: dtype
                                        * Referenced by: '<S5>/x_ref'
                                        */
  real_T x_ref_P3;                     /* Expression: portnum
                                        * Referenced by: '<S5>/x_ref'
                                        */
  real_T x_ref_P4;                     /* Expression: stime
                                        * Referenced by: '<S5>/x_ref'
                                        */
  real_T x_ref_P5;                     /* Expression: stype
                                        * Referenced by: '<S5>/x_ref'
                                        */
  real_T x_ref_P6;                     /* Expression: btype
                                        * Referenced by: '<S5>/x_ref'
                                        */
  real_T y_ref_P1;                     /* Expression: width
                                        * Referenced by: '<S5>/y_ref'
                                        */
  real_T y_ref_P2;                     /* Expression: dtype
                                        * Referenced by: '<S5>/y_ref'
                                        */
  real_T y_ref_P3;                     /* Expression: portnum
                                        * Referenced by: '<S5>/y_ref'
                                        */
  real_T y_ref_P4;                     /* Expression: stime
                                        * Referenced by: '<S5>/y_ref'
                                        */
  real_T y_ref_P5;                     /* Expression: stype
                                        * Referenced by: '<S5>/y_ref'
                                        */
  real_T y_ref_P6;                     /* Expression: btype
                                        * Referenced by: '<S5>/y_ref'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 1e10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -1e10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Gain_Gain_j;                  /* Expression: pi
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 2*pi
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 1e10
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -1e10
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Gain_Gain_g;                  /* Expression: pi
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Constant_Value_p;             /* Expression: 2*pi
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Integrator1_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S15>/Integrator3'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T alpha_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<Root>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/alpha_VSP2'
                                        */
  real_T omega_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<Root>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/omega_VSP1'
                                        */
  real_T omega_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<Root>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/omega_VSP2'
                                        */
  real_T alpha_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<Root>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/alpha_VSP1'
                                        */
  real_T u_BT_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/u_BT'
                                        */
  real_T u_BT_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/u_BT'
                                        */
  real_T u_BT_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/u_BT'
                                        */
  real_T u_BT_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/u_BT'
                                        */
  real_T u_BT_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/u_BT'
                                        */
  real_T u_BT_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/u_BT'
                                        */
  real_T u_VSP1_P1;                    /* Expression: width
                                        * Referenced by: '<Root>/u_VSP1'
                                        */
  real_T u_VSP1_P2;                    /* Expression: dtype
                                        * Referenced by: '<Root>/u_VSP1'
                                        */
  real_T u_VSP1_P3;                    /* Expression: portnum
                                        * Referenced by: '<Root>/u_VSP1'
                                        */
  real_T u_VSP1_P4;                    /* Expression: stime
                                        * Referenced by: '<Root>/u_VSP1'
                                        */
  real_T u_VSP1_P5;                    /* Expression: stype
                                        * Referenced by: '<Root>/u_VSP1'
                                        */
  real_T u_VSP1_P6;                    /* Expression: btype
                                        * Referenced by: '<Root>/u_VSP1'
                                        */
  real_T x_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S41>/x_hat'
                                        */
  real_T x_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S41>/x_hat'
                                        */
  real_T x_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S41>/x_hat'
                                        */
  real_T x_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S41>/x_hat'
                                        */
  real_T x_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S41>/x_hat'
                                        */
  real_T x_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S41>/x_hat'
                                        */
  real_T y_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S41>/y_hat'
                                        */
  real_T y_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S41>/y_hat'
                                        */
  real_T y_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S41>/y_hat'
                                        */
  real_T y_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S41>/y_hat'
                                        */
  real_T y_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S41>/y_hat'
                                        */
  real_T y_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S41>/y_hat'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1e10
                                        * Referenced by: '<S38>/Saturation'
                                        */
  real_T Saturation_LowerSat_cz;       /* Expression: -1e10
                                        * Referenced by: '<S38>/Saturation'
                                        */
  real_T Gain_Gain_d;                  /* Expression: pi
                                        * Referenced by: '<S38>/Gain'
                                        */
  real_T Constant_Value_p4;            /* Expression: 2*pi
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T psi_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  real_T psi_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  real_T psi_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  real_T psi_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  real_T psi_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  real_T psi_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  real_T u_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S43>/u_hat'
                                        */
  real_T u_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S43>/u_hat'
                                        */
  real_T u_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S43>/u_hat'
                                        */
  real_T u_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S43>/u_hat'
                                        */
  real_T u_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S43>/u_hat'
                                        */
  real_T u_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S43>/u_hat'
                                        */
  real_T v_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S43>/v_hat'
                                        */
  real_T v_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S43>/v_hat'
                                        */
  real_T v_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S43>/v_hat'
                                        */
  real_T v_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S43>/v_hat'
                                        */
  real_T v_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S43>/v_hat'
                                        */
  real_T v_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S43>/v_hat'
                                        */
  real_T r_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S43>/r_hat'
                                        */
  real_T r_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S43>/r_hat'
                                        */
  real_T r_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S43>/r_hat'
                                        */
  real_T r_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S43>/r_hat'
                                        */
  real_T r_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S43>/r_hat'
                                        */
  real_T r_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S43>/r_hat'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 1e10
                                        * Referenced by: '<S39>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: -1e10
                                        * Referenced by: '<S39>/Saturation'
                                        */
  real_T Gain_Gain_h;                  /* Expression: pi
                                        * Referenced by: '<S39>/Gain'
                                        */
  real_T Constant_Value_i;             /* Expression: 2*pi
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Integrator2_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  real_T M1_Gain[9];                   /* Expression: M^-1
                                        * Referenced by: '<S6>/M^-1'
                                        */
  real_T u_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  real_T u_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  real_T u_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  real_T u_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  real_T u_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  real_T u_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  real_T v_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  real_T v_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  real_T v_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  real_T v_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  real_T v_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  real_T v_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  real_T r_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  real_T r_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  real_T r_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  real_T r_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  real_T r_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  real_T r_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  real_T b_x_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  real_T b_x_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  real_T b_x_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  real_T b_x_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  real_T b_x_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  real_T b_x_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  real_T b_y_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  real_T b_y_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  real_T b_y_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  real_T b_y_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  real_T b_y_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  real_T b_y_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  real_T b_psi_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  real_T b_psi_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  real_T b_psi_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  real_T b_psi_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  real_T b_psi_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  real_T b_psi_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  real_T u_VSP2_P1;                    /* Expression: width
                                        * Referenced by: '<Root>/u_VSP2'
                                        */
  real_T u_VSP2_P2;                    /* Expression: dtype
                                        * Referenced by: '<Root>/u_VSP2'
                                        */
  real_T u_VSP2_P3;                    /* Expression: portnum
                                        * Referenced by: '<Root>/u_VSP2'
                                        */
  real_T u_VSP2_P4;                    /* Expression: stime
                                        * Referenced by: '<Root>/u_VSP2'
                                        */
  real_T u_VSP2_P5;                    /* Expression: stype
                                        * Referenced by: '<Root>/u_VSP2'
                                        */
  real_T u_VSP2_P6;                    /* Expression: btype
                                        * Referenced by: '<Root>/u_VSP2'
                                        */
  real_T Integrator2_IC_h;             /* Expression: 0
                                        * Referenced by: '<S15>/Integrator2'
                                        */
  real_T Constant_Value_k;             /* Expression: 50
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 50
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 50
                                        * Referenced by: '<S24>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant5'
                                        */
  real_T tau_N_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/tau_N'
                                        */
  real_T tau_N_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/tau_N'
                                        */
  real_T tau_N_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/tau_N'
                                        */
  real_T tau_N_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/tau_N'
                                        */
  real_T tau_N_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/tau_N'
                                        */
  real_T tau_N_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/tau_N'
                                        */
  real_T tau_X_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/tau_X'
                                        */
  real_T tau_X_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/tau_X'
                                        */
  real_T tau_X_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/tau_X'
                                        */
  real_T tau_X_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/tau_X'
                                        */
  real_T tau_X_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/tau_X'
                                        */
  real_T tau_X_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/tau_X'
                                        */
  real_T tau_Y_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  real_T tau_Y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  real_T tau_Y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  real_T tau_Y_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  real_T tau_Y_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  real_T tau_Y_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  real_T psi_tilde_P1;                 /* Expression: width
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  real_T psi_tilde_P2;                 /* Expression: dtype
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  real_T psi_tilde_P3;                 /* Expression: portnum
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  real_T psi_tilde_P4;                 /* Expression: stime
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  real_T psi_tilde_P5;                 /* Expression: stype
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  real_T psi_tilde_P6;                 /* Expression: btype
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  real_T x_tilde_P1;                   /* Expression: width
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  real_T x_tilde_P2;                   /* Expression: dtype
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  real_T x_tilde_P3;                   /* Expression: portnum
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  real_T x_tilde_P4;                   /* Expression: stime
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  real_T x_tilde_P5;                   /* Expression: stype
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  real_T x_tilde_P6;                   /* Expression: btype
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  real_T y_tidle_P1;                   /* Expression: width
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  real_T y_tidle_P2;                   /* Expression: dtype
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  real_T y_tidle_P3;                   /* Expression: portnum
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  real_T y_tidle_P4;                   /* Expression: stime
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  real_T y_tidle_P5;                   /* Expression: stype
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  real_T y_tidle_P6;                   /* Expression: btype
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  real_T r_tilde_P1;                   /* Expression: width
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  real_T r_tilde_P2;                   /* Expression: dtype
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  real_T r_tilde_P3;                   /* Expression: portnum
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  real_T r_tilde_P4;                   /* Expression: stime
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  real_T r_tilde_P5;                   /* Expression: stype
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  real_T r_tilde_P6;                   /* Expression: btype
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  real_T u_tilde_P1;                   /* Expression: width
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  real_T u_tilde_P2;                   /* Expression: dtype
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  real_T u_tilde_P3;                   /* Expression: portnum
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  real_T u_tilde_P4;                   /* Expression: stime
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  real_T u_tilde_P5;                   /* Expression: stype
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  real_T u_tilde_P6;                   /* Expression: btype
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  real_T v_tilde_P1;                   /* Expression: width
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  real_T v_tilde_P2;                   /* Expression: dtype
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  real_T v_tilde_P3;                   /* Expression: portnum
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  real_T v_tilde_P4;                   /* Expression: stime
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  real_T v_tilde_P5;                   /* Expression: stype
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  real_T v_tilde_P6;                   /* Expression: btype
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  real_T x_d_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/x_d'
                                        */
  real_T x_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/x_d'
                                        */
  real_T x_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/x_d'
                                        */
  real_T x_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/x_d'
                                        */
  real_T x_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/x_d'
                                        */
  real_T x_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/x_d'
                                        */
  real_T y_d_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/y_d'
                                        */
  real_T y_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/y_d'
                                        */
  real_T y_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/y_d'
                                        */
  real_T y_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/y_d'
                                        */
  real_T y_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/y_d'
                                        */
  real_T y_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/y_d'
                                        */
  real_T psi_d_P1;                     /* Expression: width
                                        * Referenced by: '<S4>/psi_d'
                                        */
  real_T psi_d_P2;                     /* Expression: dtype
                                        * Referenced by: '<S4>/psi_d'
                                        */
  real_T psi_d_P3;                     /* Expression: portnum
                                        * Referenced by: '<S4>/psi_d'
                                        */
  real_T psi_d_P4;                     /* Expression: stime
                                        * Referenced by: '<S4>/psi_d'
                                        */
  real_T psi_d_P5;                     /* Expression: stype
                                        * Referenced by: '<S4>/psi_d'
                                        */
  real_T psi_d_P6;                     /* Expression: btype
                                        * Referenced by: '<S4>/psi_d'
                                        */
  real_T r_d_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/r_d'
                                        */
  real_T r_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/r_d'
                                        */
  real_T r_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/r_d'
                                        */
  real_T r_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/r_d'
                                        */
  real_T r_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/r_d'
                                        */
  real_T r_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/r_d'
                                        */
  real_T u_d_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/u_d'
                                        */
  real_T u_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/u_d'
                                        */
  real_T u_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/u_d'
                                        */
  real_T u_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/u_d'
                                        */
  real_T u_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/u_d'
                                        */
  real_T u_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/u_d'
                                        */
  real_T v_d_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/v_d'
                                        */
  real_T v_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/v_d'
                                        */
  real_T v_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/v_d'
                                        */
  real_T v_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/v_d'
                                        */
  real_T v_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/v_d'
                                        */
  real_T v_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/v_d'
                                        */
  real_T NIVeriStandSignalProbe_P1;    /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_DP_basic_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[21];
    real_T odeF[4][21];
    ODE4_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_ctrl_DP_basic_T ctrl_DP_basic_P;

/* Block signals (auto storage) */
extern B_ctrl_DP_basic_T ctrl_DP_basic_B;

/* Continuous states (auto storage) */
extern X_ctrl_DP_basic_T ctrl_DP_basic_X;

/* Block states (auto storage) */
extern DW_ctrl_DP_basic_T ctrl_DP_basic_DW;

/* Model entry point functions */
extern void ctrl_DP_basic_initialize(void);
extern void ctrl_DP_basic_output(void);
extern void ctrl_DP_basic_update(void);
extern void ctrl_DP_basic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_DP_basic_T *const ctrl_DP_basic_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ctrl_DP_basic'
 * '<S1>'   : 'ctrl_DP_basic/Control'
 * '<S2>'   : 'ctrl_DP_basic/Control output'
 * '<S3>'   : 'ctrl_DP_basic/Guidance'
 * '<S4>'   : 'ctrl_DP_basic/Guidance output'
 * '<S5>'   : 'ctrl_DP_basic/Input'
 * '<S6>'   : 'ctrl_DP_basic/Nonlinear Passisve Observer'
 * '<S7>'   : 'ctrl_DP_basic/Observer output '
 * '<S8>'   : 'ctrl_DP_basic/Thrust allocation'
 * '<S9>'   : 'ctrl_DP_basic/u_2_tau'
 * '<S10>'  : 'ctrl_DP_basic/Control/DP Controller'
 * '<S11>'  : 'ctrl_DP_basic/Control/DP Controller/Transposed rotation  matrix in yaw1'
 * '<S12>'  : 'ctrl_DP_basic/Control/DP Controller/Transposed rotation  matrix in yaw2'
 * '<S13>'  : 'ctrl_DP_basic/Control/DP Controller/[-inf inf] to [-pi pi]'
 * '<S14>'  : 'ctrl_DP_basic/Control/DP Controller/[-inf inf] to [-pi pi]1'
 * '<S15>'  : 'ctrl_DP_basic/Guidance/Reference model'
 * '<S16>'  : 'ctrl_DP_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1'
 * '<S17>'  : 'ctrl_DP_basic/Guidance/Reference model/w_d*w_d'
 * '<S18>'  : 'ctrl_DP_basic/Guidance/Reference model/w_d*w_d1'
 * '<S19>'  : 'ctrl_DP_basic/Guidance/Reference model/w_d^-2'
 * '<S20>'  : 'ctrl_DP_basic/Guidance/Reference model/w_d^3'
 * '<S21>'  : 'ctrl_DP_basic/Guidance output/Transposed rotation  matrix in yaw2'
 * '<S22>'  : 'ctrl_DP_basic/Input/Control Gains'
 * '<S23>'  : 'ctrl_DP_basic/Input/Guidance gains'
 * '<S24>'  : 'ctrl_DP_basic/Input/Observer Gains'
 * '<S25>'  : 'ctrl_DP_basic/Input/Control Gains/MATLAB Function'
 * '<S26>'  : 'ctrl_DP_basic/Input/Control Gains/MATLAB Function1'
 * '<S27>'  : 'ctrl_DP_basic/Input/Control Gains/MATLAB Function2'
 * '<S28>'  : 'ctrl_DP_basic/Input/Guidance gains/diag'
 * '<S29>'  : 'ctrl_DP_basic/Input/Guidance gains/diag1'
 * '<S30>'  : 'ctrl_DP_basic/Input/Observer Gains/MATLAB Function'
 * '<S31>'  : 'ctrl_DP_basic/Input/Observer Gains/MATLAB Function1'
 * '<S32>'  : 'ctrl_DP_basic/Input/Observer Gains/MATLAB Function2'
 * '<S33>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/C(nu)*nu'
 * '<S34>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/D(nu)*nu'
 * '<S35>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/Rotation matrix in yaw 1'
 * '<S36>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/Transpose Rotation Matrix'
 * '<S37>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/Transpose Rotation matrix'
 * '<S38>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]'
 * '<S39>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1'
 * '<S40>'  : 'ctrl_DP_basic/Observer output /b_hat output'
 * '<S41>'  : 'ctrl_DP_basic/Observer output /eta_hat output'
 * '<S42>'  : 'ctrl_DP_basic/Observer output /nu_dot_hat output'
 * '<S43>'  : 'ctrl_DP_basic/Observer output /nu_hat output'
 * '<S44>'  : 'ctrl_DP_basic/u_2_tau/Thruster configuration matrix'
 * '<S45>'  : 'ctrl_DP_basic/u_2_tau/Thruster mapping'
 * '<S46>'  : 'ctrl_DP_basic/u_2_tau/Thruster mapping/Bow thruster'
 * '<S47>'  : 'ctrl_DP_basic/u_2_tau/Thruster mapping/VSP'
 */
#endif                                 /* RTW_HEADER_ctrl_DP_basic_h_ */

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#define NI_SIT_PARAMS
#ifdef NI_ROOTMODEL_ctrl_DP_basic
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

P_ctrl_DP_basic_T rtParameter[NUMST+!TID01EQ];
P_ctrl_DP_basic_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

P_ctrl_DP_basic_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

extern int tid;
extern P_ctrl_DP_basic_T* param_lookup[NUMST][2];

#else

extern P_ctrl_DP_basic_T rtParameter[];

#endif
#endif

#ifdef MULTITASKING
#define ctrl_DP_basic_P                (*param_lookup[tid][READSIDE])
#else
#define ctrl_DP_basic_P                rtParameter[READSIDE]
#endif
#endif
#endif
