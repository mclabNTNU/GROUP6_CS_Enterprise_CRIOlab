/*
 * ctrl_student_HIL.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.339
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Apr 06 16:23:57 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_student_HIL_h_
#define RTW_HEADER_ctrl_student_HIL_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef ctrl_student_HIL_COMMON_INCLUDES_
# define ctrl_student_HIL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_student_HIL_COMMON_INCLUDES_ */

#include "ctrl_student_HIL_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"

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

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
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

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
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
#define ctrl_student_HIL_rtModel       RT_MODEL_ctrl_student_HIL_T

/* Block signals for system '<S23>/MATLAB Function1' */
typedef struct {
  real_T R_T[9];                       /* '<S23>/MATLAB Function1' */
} B_MATLABFunction1_ctrl_studen_T;

/* Block signals for system '<S23>/Rotation Matrix' */
typedef struct {
  real_T R[9];                         /* '<S23>/Rotation Matrix' */
} B_RotationMatrix_ctrl_student_T;

/* Block signals for system '<S40>/MATLAB Function1' */
typedef struct {
  real_T SwitchSignal_Out;             /* '<S40>/MATLAB Function1' */
} B_MATLABFunction1_ctrl_stud_k_T;

/* Block signals (auto storage) */
typedef struct {
  real_T reset;                        /* '<Root>/reset' */
  real_T X_ship;                       /* '<S11>/X_ship' */
  real_T Y_ship;                       /* '<S11>/Y_ship' */
  real_T PSI_ship;                     /* '<S11>/PSI_ship' */
  real_T res_ship;                     /* '<S11>/res_ship' */
  real_T Memory;                       /* '<S7>/Memory' */
  real_T Sum;                          /* '<S60>/Sum' */
  real_T Switch3;                      /* '<S65>/Switch3' */
  real_T TmpSignalConversionAteta_hatInp[3];/* '<Root>/DPObserver1' */
  real_T dropOutTolerance;             /* '<Root>/dropOutTolerance' */
  real_T TmpSignalConversionAtResidualIn[2];
  real_T TmpSignalConversionAteta_realIn[3];
  real_T Sum1[3];                      /* '<Root>/Sum1' */
  real_T NoisePowPos;                  /* '<Root>/NoisePowPos' */
  real_T WhiteNoise;                   /* '<S74>/White Noise' */
  real_T WhiteNoise_e;                 /* '<S75>/White Noise' */
  real_T NoisePowHead;                 /* '<Root>/NoisePowHead' */
  real_T WhiteNoise_m;                 /* '<S73>/White Noise' */
  real_T Hold[3];                      /* '<S69>/Hold' */
  real_T NoiseEnable;                  /* '<Root>/NoiseEnable' */
  real_T Switch[3];                    /* '<S5>/Switch' */
  real_T ControllerGainK2;             /* '<Root>/ControllerGainK2' */
  real_T Gain[9];                      /* '<S25>/Gain' */
  real_T Integrator;                   /* '<S40>/Integrator' */
  real_T IC;                           /* '<S36>/IC' */
  real_T Integrator_m;                 /* '<S47>/Integrator' */
  real_T Memory2;                      /* '<S49>/Memory2' */
  real_T Memory1[2];                   /* '<S49>/Memory1' */
  real_T Sum_a[2];                     /* '<S46>/Sum' */
  real_T Switch_j[2];                  /* '<S19>/Switch' */
  real_T Product[3];                   /* '<S24>/Product' */
  real_T IC_n;                         /* '<S37>/IC' */
  real_T nuHat[3];                     /* '<S58>/nuHat' */
  real_T Sum_g[3];                     /* '<S22>/Sum' */
  real_T Kz_2[3];                      /* '<S31>/K*z_2' */
  real_T ControllerGainK1;             /* '<Root>/ControllerGainK1' */
  real_T Malpha_dott[3];               /* '<S31>/M*alpha_dott' */
  real_T Kz_1[3];                      /* '<S31>/K*z_1' */
  real_T Sum2[3];                      /* '<S31>/Sum2' */
  real_T Switch2[3];                   /* '<S21>/Switch2' */
  real_T L2_continuous;                /* '<S13>/L2_continuous' */
  real_T Select;                       /* '<S13>/Select' */
  real_T PosXRight;                    /* '<S13>/PosXRight' */
  real_T PosYRight;                    /* '<S13>/PosYRight' */
  real_T R2_continuous;                /* '<S13>/R2_continuous' */
  real_T PosXLeft;                     /* '<S13>/PosXLeft' */
  real_T PosYLeft;                     /* '<S13>/PosYLeft' */
  real_T L1;                           /* '<S13>/L1' */
  real_T R1;                           /* '<S13>/R1' */
  real_T ArrowDown;                    /* '<S13>/ArrowDown' */
  real_T ArrowUp;                      /* '<S13>/ArrowUp' */
  real_T ArrowLeft;                    /* '<S13>/ArrowLeft' */
  real_T ArrowRight;                   /* '<S13>/ArrowRight' */
  real_T JoysticControllerSwitch;      /* '<Root>/JoysticControllerSwitch' */
  real_T Switch2_g[3];                 /* '<Root>/Switch2' */
  real_T Memory_m[3];                  /* '<S10>/Memory' */
  real_T Sum2_a;                       /* '<Root>/Sum2' */
  real_T sf1;                          /* '<Root>/sf1' */
  real_T Memory_n;                     /* '<S15>/Memory' */
  real_T SZ_ResetKill;                 /* '<Root>/SZ_ResetKill' */
  real_T SZ_Owerwrite;                 /* '<Root>/SZ_Owerwrite' */
  real_T sf2;                          /* '<Root>/sf2' */
  real_T sf3;                          /* '<Root>/sf3' */
  real_T biasOffset;                   /* '<Root>/biasOffset' */
  real_T Memory_o;                     /* '<S49>/Memory' */
  real_T IC1[3];                       /* '<S56>/IC1' */
  real_T IC_i[3];                      /* '<S58>/IC' */
  real_T TurnOffomega1;                /* '<S9>/TurnOffomega1' */
  real_T TurnOffomega2;                /* '<S9>/TurnOffomega2' */
  real_T Switch_b;                     /* '<S9>/Switch' */
  real_T Switch1;                      /* '<S9>/Switch1' */
  real_T Sum_n;                        /* '<S9>/Sum' */
  real_T Sum1_n;                       /* '<S9>/Sum1' */
  real_T y_in;                         /* '<S12>/y_in' */
  real_T psi_in;                       /* '<S12>/psi_in' */
  real_T u_in;                         /* '<S12>/u_in' */
  real_T x_in;                         /* '<S12>/x_in' */
  real_T r_in;                         /* '<S12>/r_in' */
  real_T v_in;                         /* '<S12>/v_in' */
  real_T u_BT;                         /* '<S17>/Full thrust allocation' */
  real_T u_VSP;                        /* '<S17>/Full thrust allocation' */
  real_T alpha_VSP;                    /* '<S17>/Full thrust allocation' */
  real_T omega_VSP;                    /* '<S17>/Full thrust allocation' */
  real_T kill_signal;                  /* '<S15>/MATLAB Function' */
  real_T nu_dot[3];                    /* '<S14>/kinetics' */
  real_T eta_dot[3];                   /* '<S14>/kinematics' */
  real_T tau_surge;                    /* '<S13>/Contoller_Map1' */
  real_T tau_sway;                     /* '<S13>/Contoller_Map1' */
  real_T tau_yaw;                      /* '<S13>/Contoller_Map1' */
  real_T posOut[3];                    /* '<S10>/dropOutDetect' */
  real_T dropout;                      /* '<S10>/dropOutDetect' */
  real_T tauAct[3];                    /* '<S9>/actForces1' */
  real_T u_vsp1;                       /* '<S9>/Force2Control' */
  real_T u_vsp2;                       /* '<S9>/Force2Control' */
  real_T alpha1;                       /* '<S9>/Force2Control' */
  real_T alpha2;                       /* '<S9>/Force2Control' */
  real_T deg_out;                      /* '<S7>/Deg2Rad' */
  real_T output[3];                    /* '<S69>/MATLAB Function1' */
  real_T count;                        /* '<S68>/MATLAB Function' */
  real_T etaHatDot[3];                 /* '<S60>/etaHatDot' */
  real_T bHatDot[3];                   /* '<S56>/bHatDot' */
  real_T s_dot;                        /* '<S47>/UpdateLaw' */
  real_T U_s;                          /* '<S47>/UpdateLaw' */
  real_T SwitchSignal;                 /* '<S49>/MATLAB Function1' */
  real_T N;                            /* '<S49>/MATLAB Function1' */
  real_T SwitchSignal_out;             /* '<S49>/MATLAB Function' */
  real_T N_out;                        /* '<S49>/MATLAB Function' */
  real_T U;                            /* '<S49>/MATLAB Function' */
  real_T s_out;                        /* '<S49>/MATLAB Function' */
  real_T init_time[2];                 /* '<S49>/MATLAB Function' */
  real_T flag;                         /* '<S49>/MATLAB Function' */
  real_T s_dot_l;                      /* '<S40>/UpdateLaw' */
  real_T pd[2];                        /* '<S42>/MATLAB Function' */
  real_T s_out_j;                      /* '<S38>/CheckS&getU' */
  real_T Switch_d;                     /* '<S38>/CheckS&getU' */
  real_T M[9];                         /* '<S31>/MATLAB Function1' */
  boolean_T fault;                     /* '<S93>/control limit checking' */
  B_MATLABFunction1_ctrl_stud_k_T sf_MATLABFunction1_p;/* '<S47>/MATLAB Function1' */
  B_MATLABFunction1_ctrl_stud_k_T sf_MATLABFunction1_m;/* '<S40>/MATLAB Function1' */
  B_RotationMatrix_ctrl_student_T sf_RotationMatrix;/* '<S24>/Rotation Matrix' */
  B_MATLABFunction1_ctrl_studen_T sf_RTransposed;/* '<S24>/R Transposed' */
  B_RotationMatrix_ctrl_student_T sf_RotationMatrix_j;/* '<S23>/Rotation Matrix' */
  B_MATLABFunction1_ctrl_studen_T sf_MATLABFunction1_pa;/* '<S23>/MATLAB Function1' */
} B_ctrl_student_HIL_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T reset_DWORK1;                 /* '<Root>/reset' */
  real_T X_ship_DWORK1;                /* '<S11>/X_ship' */
  real_T Y_ship_DWORK1;                /* '<S11>/Y_ship' */
  real_T PSI_ship_DWORK1;              /* '<S11>/PSI_ship' */
  real_T res_ship_DWORK1;              /* '<S11>/res_ship' */
  real_T Memory_PreviousInput;         /* '<S7>/Memory' */
  real_T eta_hat_DWORK1[3];            /* '<Root>/eta_hat' */
  real_T dropOutTolerance_DWORK1;      /* '<Root>/dropOutTolerance' */
  real_T Residual_DWORK1[2];           /* '<Root>/Residual' */
  real_T eta_tilde_DWORK1[3];          /* '<Root>/eta_tilde' */
  real_T counter_PreviousInput;        /* '<S68>/counter' */
  real_T NoisePowPos_DWORK1;           /* '<Root>/NoisePowPos' */
  real_T NextOutput;                   /* '<S74>/White Noise' */
  real_T NextOutput_c;                 /* '<S75>/White Noise' */
  real_T NoisePowHead_DWORK1;          /* '<Root>/NoisePowHead' */
  real_T NextOutput_p;                 /* '<S73>/White Noise' */
  real_T Hold_PreviousInput[3];        /* '<S69>/Hold' */
  real_T NoiseEnable_DWORK1;           /* '<Root>/NoiseEnable' */
  real_T eta_noise_DWORK1[3];          /* '<Root>/eta_noise' */
  real_T ControllerGainK2_DWORK1;      /* '<Root>/ControllerGainK2' */
  real_T Memory_PreviousInput_f;       /* '<S36>/Memory' */
  real_T IC_FirstOutputTime;           /* '<S36>/IC' */
  real_T Memory_PreviousInput_m;       /* '<S37>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S49>/Memory2' */
  real_T Memory1_PreviousInput[2];     /* '<S49>/Memory1' */
  real_T IC_FirstOutputTime_p;         /* '<S37>/IC' */
  real_T ControllerGainK1_DWORK1;      /* '<Root>/ControllerGainK1' */
  real_T L2_continuous_DWORK1;         /* '<S13>/L2_continuous' */
  real_T Select_DWORK1;                /* '<S13>/Select' */
  real_T CurrentMode_DWORK1;           /* '<S13>/Current Mode ' */
  real_T PosXRight_DWORK1;             /* '<S13>/PosXRight' */
  real_T PosYRight_DWORK1;             /* '<S13>/PosYRight' */
  real_T R2_continuous_DWORK1;         /* '<S13>/R2_continuous' */
  real_T tau_yaw_DWORK1;               /* '<S13>/tau_yaw' */
  real_T tau_x_DWORK1;                 /* '<S13>/tau_x' */
  real_T tau_y_DWORK1;                 /* '<S13>/tau_y' */
  real_T PosXLeft_DWORK1;              /* '<S13>/PosXLeft' */
  real_T PosYLeft_DWORK1;              /* '<S13>/PosYLeft' */
  real_T L1_DWORK1;                    /* '<S13>/L1' */
  real_T R1_DWORK1;                    /* '<S13>/R1' */
  real_T ArrowDown_DWORK1;             /* '<S13>/ArrowDown' */
  real_T ArrowUp_DWORK1;               /* '<S13>/ArrowUp' */
  real_T ArrowLeft_DWORK1;             /* '<S13>/ArrowLeft' */
  real_T ArrowRight_DWORK1;            /* '<S13>/ArrowRight' */
  real_T JoysticControllerSwitch_DWORK1;/* '<Root>/JoysticControllerSwitch' */
  real_T Tau_pre_DWORK1[3];            /* '<Root>/Tau_pre' */
  real_T Memory_PreviousInput_d[3];    /* '<S10>/Memory' */
  real_T sf1_DWORK1;                   /* '<Root>/sf1' */
  real_T Memory_PreviousInput_e;       /* '<S15>/Memory' */
  real_T SZ_ResetKill_DWORK1;          /* '<Root>/SZ_ResetKill' */
  real_T SZ_Owerwrite_DWORK1;          /* '<Root>/SZ_Owerwrite' */
  real_T Tau_post_DWORK1[3];           /* '<Root>/Tau_post' */
  real_T P_d_DWORK1[2];                /* '<Root>/P_d' */
  real_T dropoutFlag_DWORK1;           /* '<Root>/dropoutFlag' */
  real_T sf2_DWORK1;                   /* '<Root>/sf2' */
  real_T sf3_DWORK1;                   /* '<Root>/sf3' */
  real_T biasOffset_DWORK1;            /* '<Root>/biasOffset' */
  real_T X_d_DWORK1;                   /* '<S16>/X_d' */
  real_T N_d_DWORK1;                   /* '<S16>/N_d' */
  real_T Y_d_DWORK1;                   /* '<S16>/Y_d' */
  real_T psi_0_DWORK1;                 /* '<S16>/psi_0 ' */
  real_T x_0_DWORK1;                   /* '<S16>/x_0' */
  real_T y_0_DWORK1;                   /* '<S16>/y_0' */
  real_T integratorresetmodel_DWORK1;  /* '<S16>/integrator reset model' */
  real_T Memory_PreviousInput_p;       /* '<S49>/Memory' */
  real_T IC1_FirstOutputTime;          /* '<S56>/IC1' */
  real_T IC_FirstOutputTime_n;         /* '<S58>/IC' */
  real_T eta_real_DWORK1[3];           /* '<S7>/eta_real' */
  real_T u_BT_DWORK1;                  /* '<S9>/u_BT' */
  real_T TurnOffomega1_DWORK1;         /* '<S9>/TurnOffomega1' */
  real_T TurnOffomega2_DWORK1;         /* '<S9>/TurnOffomega2' */
  real_T u_VSP1_DWORK1;                /* '<S9>/u_VSP1' */
  real_T u_VSP2_DWORK1;                /* '<S9>/u_VSP2' */
  real_T alpha_VSP1_DWORK1;            /* '<S9>/alpha_VSP1' */
  real_T alpha_VSP2_DWORK1;            /* '<S9>/alpha_VSP2' */
  real_T omega_VSP1_DWORK1;            /* '<S9>/omega_VSP1' */
  real_T omega_VSP2_DWORK1;            /* '<S9>/omega_VSP2' */
  real_T f_bt_DWORK1;                  /* '<S9>/f_bt' */
  real_T f_vspx_DWORK1;                /* '<S9>/f_vspx' */
  real_T f_vspy_DWORK1;                /* '<S9>/ f_vspy' */
  real_T y_in_DWORK1;                  /* '<S12>/y_in' */
  real_T psi_in_DWORK1;                /* '<S12>/psi_in' */
  real_T u_in_DWORK1;                  /* '<S12>/u_in' */
  real_T u_real_DWORK1;                /* '<S12>/u_real  ' */
  real_T x_in_DWORK1;                  /* '<S12>/x_in' */
  real_T r_in_DWORK1;                  /* '<S12>/r_in' */
  real_T v_in_DWORK1;                  /* '<S12>/v_in' */
  real_T controlinputuexceedsbounds_DWOR;/* '<S93>/control input u exceeds bounds' */
  real_T alpha_VSP1_DWORK1_o;          /* '<S95>/alpha_VSP1' */
  real_T alpha_VSP2_DWORK1_a;          /* '<S95>/alpha_VSP2' */
  real_T omega_VSP1_DWORK1_b;          /* '<S95>/omega_VSP1' */
  real_T omega_VSP2_DWORK1_c;          /* '<S95>/omega_VSP2' */
  real_T u_BT_DWORK1_j;                /* '<S95>/u_BT' */
  real_T u_VSP1_DWORK1_o;              /* '<S95>/u_VSP1' */
  real_T u_VSP2_DWORK1_o;              /* '<S95>/u_VSP2' */
  struct {
    void *LoggedData;
  } Eta_dss_PWORK;                     /* '<S1>/Eta_dss' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<S1>/To Workspace3' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S18>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S18>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S18>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S21>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_d;                     /* '<S31>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_j;                    /* '<S31>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_k;                    /* '<S31>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_b;                    /* '<S31>/Scope3' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_e;                    /* '<S19>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_m;                    /* '<S19>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_d;                    /* '<S36>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S36>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK_db;                    /* '<S42>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_d;                    /* '<S37>/Scope1' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_bj;                   /* '<S37>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_k;                    /* '<S46>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_s_PWORK;                     /* '<S46>/Scope_ s' */

  struct {
    void *LoggedData;
  } Scope_s_inn_PWORK;                 /* '<S46>/Scope_s_inn' */

  struct {
    void *LoggedData;
  } Scope_switch_PWORK;                /* '<S46>/Scope_switch' */

  struct {
    void *LoggedData;
  } Flag_PWORK;                        /* '<S49>/Flag' */

  struct {
    void *LoggedData;
  } SwitchSig_PWORK;                   /* '<S49>/SwitchSig' */

  struct {
    void *LoggedData;
  } U_scope_PWORK;                     /* '<S49>/U_scope ' */

  int32_T NIVeriStandSignalProbe_DWORK2;/* '<Root>/NIVeriStandSignalProbe' */
  uint32_T RandSeed;                   /* '<S74>/White Noise' */
  uint32_T RandSeed_j;                 /* '<S75>/White Noise' */
  uint32_T RandSeed_c;                 /* '<S73>/White Noise' */
  struct {
    int_T IcNeedsLoading;
  } etaHat1_IWORK;                     /* '<S65>/etaHat1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK;                 /* '<S14>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S14>/Integrator' */

  uint8_T reset_DWORK2[17];            /* '<Root>/reset' */
  uint8_T X_ship_DWORK2[17];           /* '<S11>/X_ship' */
  uint8_T Y_ship_DWORK2[17];           /* '<S11>/Y_ship' */
  uint8_T PSI_ship_DWORK2[17];         /* '<S11>/PSI_ship' */
  uint8_T res_ship_DWORK2[17];         /* '<S11>/res_ship' */
  uint8_T eta_hat_DWORK2[17];          /* '<Root>/eta_hat' */
  uint8_T dropOutTolerance_DWORK2[17]; /* '<Root>/dropOutTolerance' */
  uint8_T Residual_DWORK2[17];         /* '<Root>/Residual' */
  uint8_T eta_tilde_DWORK2[17];        /* '<Root>/eta_tilde' */
  uint8_T NoisePowPos_DWORK2[17];      /* '<Root>/NoisePowPos' */
  uint8_T NoisePowHead_DWORK2[17];     /* '<Root>/NoisePowHead' */
  uint8_T NoiseEnable_DWORK2[17];      /* '<Root>/NoiseEnable' */
  uint8_T eta_noise_DWORK2[17];        /* '<Root>/eta_noise' */
  uint8_T ControllerGainK2_DWORK2[17]; /* '<Root>/ControllerGainK2' */
  uint8_T ControllerGainK1_DWORK2[17]; /* '<Root>/ControllerGainK1' */
  uint8_T L2_continuous_DWORK2[17];    /* '<S13>/L2_continuous' */
  uint8_T Select_DWORK2[17];           /* '<S13>/Select' */
  uint8_T CurrentMode_DWORK2[17];      /* '<S13>/Current Mode ' */
  uint8_T PosXRight_DWORK2[17];        /* '<S13>/PosXRight' */
  uint8_T PosYRight_DWORK2[17];        /* '<S13>/PosYRight' */
  uint8_T R2_continuous_DWORK2[17];    /* '<S13>/R2_continuous' */
  uint8_T tau_yaw_DWORK2[17];          /* '<S13>/tau_yaw' */
  uint8_T tau_x_DWORK2[17];            /* '<S13>/tau_x' */
  uint8_T tau_y_DWORK2[17];            /* '<S13>/tau_y' */
  uint8_T PosXLeft_DWORK2[17];         /* '<S13>/PosXLeft' */
  uint8_T PosYLeft_DWORK2[17];         /* '<S13>/PosYLeft' */
  uint8_T L1_DWORK2[17];               /* '<S13>/L1' */
  uint8_T R1_DWORK2[17];               /* '<S13>/R1' */
  uint8_T ArrowDown_DWORK2[17];        /* '<S13>/ArrowDown' */
  uint8_T ArrowUp_DWORK2[17];          /* '<S13>/ArrowUp' */
  uint8_T ArrowLeft_DWORK2[17];        /* '<S13>/ArrowLeft' */
  uint8_T ArrowRight_DWORK2[17];       /* '<S13>/ArrowRight' */
  uint8_T JoysticControllerSwitch_DWORK2[17];/* '<Root>/JoysticControllerSwitch' */
  uint8_T Tau_pre_DWORK2[17];          /* '<Root>/Tau_pre' */
  uint8_T sf1_DWORK2[17];              /* '<Root>/sf1' */
  uint8_T SZ_ResetKill_DWORK2[17];     /* '<Root>/SZ_ResetKill' */
  uint8_T SZ_Owerwrite_DWORK2[17];     /* '<Root>/SZ_Owerwrite' */
  uint8_T Tau_post_DWORK2[17];         /* '<Root>/Tau_post' */
  uint8_T P_d_DWORK2[17];              /* '<Root>/P_d' */
  uint8_T dropoutFlag_DWORK2[17];      /* '<Root>/dropoutFlag' */
  uint8_T sf2_DWORK2[17];              /* '<Root>/sf2' */
  uint8_T sf3_DWORK2[17];              /* '<Root>/sf3' */
  uint8_T biasOffset_DWORK2[17];       /* '<Root>/biasOffset' */
  uint8_T X_d_DWORK2[17];              /* '<S16>/X_d' */
  uint8_T N_d_DWORK2[17];              /* '<S16>/N_d' */
  uint8_T Y_d_DWORK2[17];              /* '<S16>/Y_d' */
  uint8_T psi_0_DWORK2[17];            /* '<S16>/psi_0 ' */
  uint8_T x_0_DWORK2[17];              /* '<S16>/x_0' */
  uint8_T y_0_DWORK2[17];              /* '<S16>/y_0' */
  uint8_T integratorresetmodel_DWORK2[17];/* '<S16>/integrator reset model' */
  uint8_T eta_real_DWORK2[17];         /* '<S7>/eta_real' */
  uint8_T u_BT_DWORK2[17];             /* '<S9>/u_BT' */
  uint8_T TurnOffomega1_DWORK2[17];    /* '<S9>/TurnOffomega1' */
  uint8_T TurnOffomega2_DWORK2[17];    /* '<S9>/TurnOffomega2' */
  uint8_T u_VSP1_DWORK2[17];           /* '<S9>/u_VSP1' */
  uint8_T u_VSP2_DWORK2[17];           /* '<S9>/u_VSP2' */
  uint8_T alpha_VSP1_DWORK2[17];       /* '<S9>/alpha_VSP1' */
  uint8_T alpha_VSP2_DWORK2[17];       /* '<S9>/alpha_VSP2' */
  uint8_T omega_VSP1_DWORK2[17];       /* '<S9>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2[17];       /* '<S9>/omega_VSP2' */
  uint8_T f_bt_DWORK2[17];             /* '<S9>/f_bt' */
  uint8_T f_vspx_DWORK2[17];           /* '<S9>/f_vspx' */
  uint8_T f_vspy_DWORK2[17];           /* '<S9>/ f_vspy' */
  uint8_T y_in_DWORK2[17];             /* '<S12>/y_in' */
  uint8_T psi_in_DWORK2[17];           /* '<S12>/psi_in' */
  uint8_T u_in_DWORK2[17];             /* '<S12>/u_in' */
  uint8_T u_real_DWORK2[17];           /* '<S12>/u_real  ' */
  uint8_T x_in_DWORK2[17];             /* '<S12>/x_in' */
  uint8_T r_in_DWORK2[17];             /* '<S12>/r_in' */
  uint8_T v_in_DWORK2[17];             /* '<S12>/v_in' */
  uint8_T controlinputuexceedsbounds_DW_g[17];/* '<S93>/control input u exceeds bounds' */
  uint8_T alpha_VSP1_DWORK2_i[17];     /* '<S95>/alpha_VSP1' */
  uint8_T alpha_VSP2_DWORK2_k[17];     /* '<S95>/alpha_VSP2' */
  uint8_T omega_VSP1_DWORK2_h[17];     /* '<S95>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2_f[17];     /* '<S95>/omega_VSP2' */
  uint8_T u_BT_DWORK2_k[17];           /* '<S95>/u_BT' */
  uint8_T u_VSP1_DWORK2_f[17];         /* '<S95>/u_VSP1' */
  uint8_T u_VSP2_DWORK2_b[17];         /* '<S95>/u_VSP2' */
  uint8_T NIVeriStandSignalProbe_DWORK1[17];/* '<Root>/NIVeriStandSignalProbe' */
  uint8_T NIVeriStandSignalProbe_DWORK3[60];/* '<Root>/NIVeriStandSignalProbe' */
} DW_ctrl_student_HIL_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T etaHat_CSTATE;                /* '<S60>/etaHat' */
  real_T etaHat2_CSTATE;               /* '<S60>/etaHat2' */
  real_T etaHat1_CSTATE;               /* '<S65>/etaHat1' */
  real_T Integrator_CSTATE;            /* '<S40>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S47>/Integrator' */
  real_T nuHat_CSTATE[3];              /* '<S58>/nuHat' */
  real_T Integrator1_CSTATE[3];        /* '<S14>/Integrator1' */
  real_T bHat_CSTATE[3];               /* '<S56>/bHat' */
  real_T Integrator_CSTATE_b[3];       /* '<S14>/Integrator' */
} X_ctrl_student_HIL_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T etaHat_CSTATE;                /* '<S60>/etaHat' */
  real_T etaHat2_CSTATE;               /* '<S60>/etaHat2' */
  real_T etaHat1_CSTATE;               /* '<S65>/etaHat1' */
  real_T Integrator_CSTATE;            /* '<S40>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S47>/Integrator' */
  real_T nuHat_CSTATE[3];              /* '<S58>/nuHat' */
  real_T Integrator1_CSTATE[3];        /* '<S14>/Integrator1' */
  real_T bHat_CSTATE[3];               /* '<S56>/bHat' */
  real_T Integrator_CSTATE_b[3];       /* '<S14>/Integrator' */
} XDot_ctrl_student_HIL_T;

/* State disabled  */
typedef struct {
  boolean_T etaHat_CSTATE;             /* '<S60>/etaHat' */
  boolean_T etaHat2_CSTATE;            /* '<S60>/etaHat2' */
  boolean_T etaHat1_CSTATE;            /* '<S65>/etaHat1' */
  boolean_T Integrator_CSTATE;         /* '<S40>/Integrator' */
  boolean_T Integrator_CSTATE_f;       /* '<S47>/Integrator' */
  boolean_T nuHat_CSTATE[3];           /* '<S58>/nuHat' */
  boolean_T Integrator1_CSTATE[3];     /* '<S14>/Integrator1' */
  boolean_T bHat_CSTATE[3];            /* '<S56>/bHat' */
  boolean_T Integrator_CSTATE_b[3];    /* '<S14>/Integrator' */
} XDis_ctrl_student_HIL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState etaHat_Reset_ZCE;         /* '<S60>/etaHat' */
  ZCSigState etaHat2_Reset_ZCE;        /* '<S60>/etaHat2' */
  ZCSigState etaHat1_Reset_ZCE;        /* '<S65>/etaHat1' */
  ZCSigState Integrator_Reset_ZCE;     /* '<S40>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_c;   /* '<S47>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE;    /* '<S14>/Integrator1' */
  ZCSigState Integrator_Reset_ZCE_p;   /* '<S14>/Integrator' */
} PrevZCX_ctrl_student_HIL_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_student_HIL_B
#define BlockIO                        B_ctrl_student_HIL_T
#define rtX                            ctrl_student_HIL_X
#define ContinuousStates               X_ctrl_student_HIL_T
#define rtXdot                         ctrl_student_HIL_XDot
#define StateDerivatives               XDot_ctrl_student_HIL_T
#define tXdis                          ctrl_student_HIL_XDis
#define StateDisabled                  XDis_ctrl_student_HIL_T
#define rtP                            ctrl_student_HIL_P
#define Parameters                     P_ctrl_student_HIL_T
#define rtDWork                        ctrl_student_HIL_DW
#define D_Work                         DW_ctrl_student_HIL_T
#define rtPrevZCSigState               ctrl_student_HIL_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_student_HIL_T

/* Parameters (auto storage) */
struct P_ctrl_student_HIL_T_ {
  real_T DesiredPath;                  /* Variable: DesiredPath
                                        * Referenced by: '<S19>/SwitchSignalFromFile'
                                        */
  real_T Elipscenter_radi[4];          /* Variable: Elipscenter_radi
                                        * Referenced by: '<S39>/Elipscenter_radi'
                                        */
  real_T K[2];                         /* Variable: K
                                        * Referenced by: '<Root>/K'
                                        */
  real_T K1[9];                        /* Variable: K1
                                        * Referenced by:
                                        *   '<S2>/Constant1'
                                        *   '<S25>/Kp '
                                        */
  real_T K2[9];                        /* Variable: K2
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T LAW;                          /* Variable: LAW
                                        * Referenced by:
                                        *   '<S40>/TASK'
                                        *   '<S47>/TASK'
                                        */
  real_T T_initialDP;                  /* Variable: T_initialDP
                                        * Referenced by: '<S49>/Constant1'
                                        */
  real_T U_ref;                        /* Variable: U_ref
                                        * Referenced by:
                                        *   '<S38>/Constant'
                                        *   '<S49>/Constant'
                                        */
  real_T eta_dot_ini[3];               /* Variable: eta_dot_ini
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T l1[9];                        /* Variable: l1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T l2[9];                        /* Variable: l2
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T l3[9];                        /* Variable: l3
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real_T lim[4];                       /* Variable: lim
                                        * Referenced by: '<Root>/Lim'
                                        */
  real_T lim_2[4];                     /* Variable: lim_2
                                        * Referenced by: '<Root>/Lim2'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T mu;                           /* Variable: mu
                                        * Referenced by:
                                        *   '<S40>/mu '
                                        *   '<S47>/mu '
                                        */
  real_T pd[4];                        /* Variable: pd
                                        * Referenced by: '<S46>/Desired Position'
                                        */
  real_T Ramp_X0;                      /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S79>/Constant1'
                                        */
  real_T Ramp_slope;                   /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S79>/Step'
                                        */
  real_T Ramp_start;                   /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S79>/Constant'
                                        *   '<S79>/Step'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S15>/Switch1'
                                        */
  real_T reset_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/reset'
                                        */
  real_T reset_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/reset'
                                        */
  real_T reset_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/reset'
                                        */
  real_T reset_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/reset'
                                        */
  real_T reset_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/reset'
                                        */
  real_T reset_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/reset'
                                        */
  real_T etaHat_IC;                    /* Expression: 0
                                        * Referenced by: '<S60>/etaHat'
                                        */
  real_T etaHat2_IC;                   /* Expression: 0
                                        * Referenced by: '<S60>/etaHat2'
                                        */
  real_T X_ship_P1;                    /* Expression: width
                                        * Referenced by: '<S11>/X_ship'
                                        */
  real_T X_ship_P2;                    /* Expression: dtype
                                        * Referenced by: '<S11>/X_ship'
                                        */
  real_T X_ship_P3;                    /* Expression: portnum
                                        * Referenced by: '<S11>/X_ship'
                                        */
  real_T X_ship_P4;                    /* Expression: stime
                                        * Referenced by: '<S11>/X_ship'
                                        */
  real_T X_ship_P5;                    /* Expression: stype
                                        * Referenced by: '<S11>/X_ship'
                                        */
  real_T X_ship_P6;                    /* Expression: btype
                                        * Referenced by: '<S11>/X_ship'
                                        */
  real_T Y_ship_P1;                    /* Expression: width
                                        * Referenced by: '<S11>/Y_ship'
                                        */
  real_T Y_ship_P2;                    /* Expression: dtype
                                        * Referenced by: '<S11>/Y_ship'
                                        */
  real_T Y_ship_P3;                    /* Expression: portnum
                                        * Referenced by: '<S11>/Y_ship'
                                        */
  real_T Y_ship_P4;                    /* Expression: stime
                                        * Referenced by: '<S11>/Y_ship'
                                        */
  real_T Y_ship_P5;                    /* Expression: stype
                                        * Referenced by: '<S11>/Y_ship'
                                        */
  real_T Y_ship_P6;                    /* Expression: btype
                                        * Referenced by: '<S11>/Y_ship'
                                        */
  real_T PSI_ship_P1;                  /* Expression: width
                                        * Referenced by: '<S11>/PSI_ship'
                                        */
  real_T PSI_ship_P2;                  /* Expression: dtype
                                        * Referenced by: '<S11>/PSI_ship'
                                        */
  real_T PSI_ship_P3;                  /* Expression: portnum
                                        * Referenced by: '<S11>/PSI_ship'
                                        */
  real_T PSI_ship_P4;                  /* Expression: stime
                                        * Referenced by: '<S11>/PSI_ship'
                                        */
  real_T PSI_ship_P5;                  /* Expression: stype
                                        * Referenced by: '<S11>/PSI_ship'
                                        */
  real_T PSI_ship_P6;                  /* Expression: btype
                                        * Referenced by: '<S11>/PSI_ship'
                                        */
  real_T res_ship_P1;                  /* Expression: width
                                        * Referenced by: '<S11>/res_ship'
                                        */
  real_T res_ship_P2;                  /* Expression: dtype
                                        * Referenced by: '<S11>/res_ship'
                                        */
  real_T res_ship_P3;                  /* Expression: portnum
                                        * Referenced by: '<S11>/res_ship'
                                        */
  real_T res_ship_P4;                  /* Expression: stime
                                        * Referenced by: '<S11>/res_ship'
                                        */
  real_T res_ship_P5;                  /* Expression: stype
                                        * Referenced by: '<S11>/res_ship'
                                        */
  real_T res_ship_P6;                  /* Expression: btype
                                        * Referenced by: '<S11>/res_ship'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S7>/Memory'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S65>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S65>/Constant1'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S65>/Switch3'
                                        */
  real_T eta_hat_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  real_T eta_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  real_T eta_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  real_T eta_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  real_T eta_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  real_T eta_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  real_T dropOutTolerance_P1;          /* Expression: width
                                        * Referenced by: '<Root>/dropOutTolerance'
                                        */
  real_T dropOutTolerance_P2;          /* Expression: dtype
                                        * Referenced by: '<Root>/dropOutTolerance'
                                        */
  real_T dropOutTolerance_P3;          /* Expression: portnum
                                        * Referenced by: '<Root>/dropOutTolerance'
                                        */
  real_T dropOutTolerance_P4;          /* Expression: stime
                                        * Referenced by: '<Root>/dropOutTolerance'
                                        */
  real_T dropOutTolerance_P5;          /* Expression: stype
                                        * Referenced by: '<Root>/dropOutTolerance'
                                        */
  real_T dropOutTolerance_P6;          /* Expression: btype
                                        * Referenced by: '<Root>/dropOutTolerance'
                                        */
  real_T Residual_P1;                  /* Expression: width
                                        * Referenced by: '<Root>/Residual'
                                        */
  real_T Residual_P2;                  /* Expression: dtype
                                        * Referenced by: '<Root>/Residual'
                                        */
  real_T Residual_P3;                  /* Expression: portnum
                                        * Referenced by: '<Root>/Residual'
                                        */
  real_T Residual_P4;                  /* Expression: stime
                                        * Referenced by: '<Root>/Residual'
                                        */
  real_T Residual_P5;                  /* Expression: stype
                                        * Referenced by: '<Root>/Residual'
                                        */
  real_T Residual_P6;                  /* Expression: btype
                                        * Referenced by: '<Root>/Residual'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/1000
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T eta_tilde_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/eta_tilde'
                                        */
  real_T eta_tilde_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_tilde'
                                        */
  real_T eta_tilde_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_tilde'
                                        */
  real_T eta_tilde_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/eta_tilde'
                                        */
  real_T eta_tilde_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_tilde'
                                        */
  real_T eta_tilde_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_tilde'
                                        */
  real_T Stepsize_Value;               /* Expression: 0.01
                                        * Referenced by: '<S5>/Step size'
                                        */
  real_T counter_X0;                   /* Expression: 0
                                        * Referenced by: '<S68>/counter'
                                        */
  real_T Constant_Value_d;             /* Expression: 100
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T NoisePowPos_P1;               /* Expression: width
                                        * Referenced by: '<Root>/NoisePowPos'
                                        */
  real_T NoisePowPos_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/NoisePowPos'
                                        */
  real_T NoisePowPos_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/NoisePowPos'
                                        */
  real_T NoisePowPos_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/NoisePowPos'
                                        */
  real_T NoisePowPos_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/NoisePowPos'
                                        */
  real_T NoisePowPos_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/NoisePowPos'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S74>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S74>/White Noise'
                                        */
  real_T WhiteNoise_Seed;              /* Expression: 9024
                                        * Referenced by: '<S74>/White Noise'
                                        */
  real_T WhiteNoise_Mean_h;            /* Expression: 0
                                        * Referenced by: '<S75>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_d;          /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S75>/White Noise'
                                        */
  real_T WhiteNoise_Seed_b;            /* Expression: 123
                                        * Referenced by: '<S75>/White Noise'
                                        */
  real_T NoisePowHead_P1;              /* Expression: width
                                        * Referenced by: '<Root>/NoisePowHead'
                                        */
  real_T NoisePowHead_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/NoisePowHead'
                                        */
  real_T NoisePowHead_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/NoisePowHead'
                                        */
  real_T NoisePowHead_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/NoisePowHead'
                                        */
  real_T NoisePowHead_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/NoisePowHead'
                                        */
  real_T NoisePowHead_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/NoisePowHead'
                                        */
  real_T WhiteNoise_Mean_f;            /* Expression: 0
                                        * Referenced by: '<S73>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_g;          /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S73>/White Noise'
                                        */
  real_T WhiteNoise_Seed_l;            /* Expression: 9025
                                        * Referenced by: '<S73>/White Noise'
                                        */
  real_T Hold_X0;                      /* Expression: 0
                                        * Referenced by: '<S69>/Hold'
                                        */
  real_T NoiseEnable_P1;               /* Expression: width
                                        * Referenced by: '<Root>/NoiseEnable'
                                        */
  real_T NoiseEnable_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/NoiseEnable'
                                        */
  real_T NoiseEnable_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/NoiseEnable'
                                        */
  real_T NoiseEnable_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/NoiseEnable'
                                        */
  real_T NoiseEnable_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/NoiseEnable'
                                        */
  real_T NoiseEnable_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/NoiseEnable'
                                        */
  real_T eta_noise_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/eta_noise'
                                        */
  real_T eta_noise_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_noise'
                                        */
  real_T eta_noise_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_noise'
                                        */
  real_T eta_noise_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/eta_noise'
                                        */
  real_T eta_noise_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_noise'
                                        */
  real_T eta_noise_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_noise'
                                        */
  real_T ControllerGainK2_P1;          /* Expression: width
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  real_T ControllerGainK2_P2;          /* Expression: dtype
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  real_T ControllerGainK2_P3;          /* Expression: portnum
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  real_T ControllerGainK2_P4;          /* Expression: stime
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  real_T ControllerGainK2_P5;          /* Expression: stype
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  real_T ControllerGainK2_P6;          /* Expression: btype
                                        * Referenced by: '<Root>/ControllerGainK2'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T Memory_X0_n;                  /* Expression: 0
                                        * Referenced by: '<S36>/Memory'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S40>/Integrator'
                                        */
  real_T IC_Value;                     /* Expression: 0
                                        * Referenced by: '<S36>/IC'
                                        */
  real_T Memory_X0_l;                  /* Expression: 0
                                        * Referenced by: '<S37>/Memory'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S47>/Integrator'
                                        */
  real_T Memory2_X0;                   /* Expression: 1
                                        * Referenced by: '<S49>/Memory2'
                                        */
  real_T Memory1_X0[2];                /* Expression: [0,0]
                                        * Referenced by: '<S49>/Memory1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S19>/Switch'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S48>/Constant1'
                                        */
  real_T Switch3_Threshold_e;          /* Expression: 0
                                        * Referenced by: '<S19>/Switch3'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T IC_Value_e;                   /* Expression: 0
                                        * Referenced by: '<S37>/IC'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<S19>/Switch4'
                                        */
  real_T nuHat_IC[3];                  /* Expression: [0;0;0]
                                        * Referenced by: '<S58>/nuHat'
                                        */
  real_T ControllerGainK1_P1;          /* Expression: width
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  real_T ControllerGainK1_P2;          /* Expression: dtype
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  real_T ControllerGainK1_P3;          /* Expression: portnum
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  real_T ControllerGainK1_P4;          /* Expression: stime
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  real_T ControllerGainK1_P5;          /* Expression: stype
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  real_T ControllerGainK1_P6;          /* Expression: btype
                                        * Referenced by: '<Root>/ControllerGainK1'
                                        */
  real_T Switch5_Threshold;            /* Expression: 0
                                        * Referenced by: '<S19>/Switch5'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S46>/Constant'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S46>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S46>/Constant2'
                                        */
  real_T Switch6_Threshold;            /* Expression: 0
                                        * Referenced by: '<S19>/Switch6'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S46>/Constant3'
                                        */
  real_T Switch7_Threshold;            /* Expression: 0
                                        * Referenced by: '<S19>/Switch7'
                                        */
  real_T Constant1_Value_d;            /* Expression: 1
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Constant_Value_dg[3];         /* Expression: [0;0;0]
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S21>/Switch2'
                                        */
  real_T L2_continuous_P1;             /* Expression: width
                                        * Referenced by: '<S13>/L2_continuous'
                                        */
  real_T L2_continuous_P2;             /* Expression: dtype
                                        * Referenced by: '<S13>/L2_continuous'
                                        */
  real_T L2_continuous_P3;             /* Expression: portnum
                                        * Referenced by: '<S13>/L2_continuous'
                                        */
  real_T L2_continuous_P4;             /* Expression: stime
                                        * Referenced by: '<S13>/L2_continuous'
                                        */
  real_T L2_continuous_P5;             /* Expression: stype
                                        * Referenced by: '<S13>/L2_continuous'
                                        */
  real_T L2_continuous_P6;             /* Expression: btype
                                        * Referenced by: '<S13>/L2_continuous'
                                        */
  real_T Select_P1;                    /* Expression: width
                                        * Referenced by: '<S13>/Select'
                                        */
  real_T Select_P2;                    /* Expression: dtype
                                        * Referenced by: '<S13>/Select'
                                        */
  real_T Select_P3;                    /* Expression: portnum
                                        * Referenced by: '<S13>/Select'
                                        */
  real_T Select_P4;                    /* Expression: stime
                                        * Referenced by: '<S13>/Select'
                                        */
  real_T Select_P5;                    /* Expression: stype
                                        * Referenced by: '<S13>/Select'
                                        */
  real_T Select_P6;                    /* Expression: btype
                                        * Referenced by: '<S13>/Select'
                                        */
  real_T CurrentMode_P1;               /* Expression: width
                                        * Referenced by: '<S13>/Current Mode '
                                        */
  real_T CurrentMode_P2;               /* Expression: dtype
                                        * Referenced by: '<S13>/Current Mode '
                                        */
  real_T CurrentMode_P3;               /* Expression: portnum
                                        * Referenced by: '<S13>/Current Mode '
                                        */
  real_T CurrentMode_P4;               /* Expression: stime
                                        * Referenced by: '<S13>/Current Mode '
                                        */
  real_T CurrentMode_P5;               /* Expression: stype
                                        * Referenced by: '<S13>/Current Mode '
                                        */
  real_T CurrentMode_P6;               /* Expression: btype
                                        * Referenced by: '<S13>/Current Mode '
                                        */
  real_T PosXRight_P1;                 /* Expression: width
                                        * Referenced by: '<S13>/PosXRight'
                                        */
  real_T PosXRight_P2;                 /* Expression: dtype
                                        * Referenced by: '<S13>/PosXRight'
                                        */
  real_T PosXRight_P3;                 /* Expression: portnum
                                        * Referenced by: '<S13>/PosXRight'
                                        */
  real_T PosXRight_P4;                 /* Expression: stime
                                        * Referenced by: '<S13>/PosXRight'
                                        */
  real_T PosXRight_P5;                 /* Expression: stype
                                        * Referenced by: '<S13>/PosXRight'
                                        */
  real_T PosXRight_P6;                 /* Expression: btype
                                        * Referenced by: '<S13>/PosXRight'
                                        */
  real_T Max_Global_Forces_Value[4];   /* Expression:  [2*1.165 4*(1.165*0.8) 4*(1.165*0.8)*0.4575 2.629]
                                        * Referenced by: '<S13>/Max_Global_Forces'
                                        */
  real_T DeadZone_Start;               /* Expression: -0.05
                                        * Referenced by: '<S13>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 0.05
                                        * Referenced by: '<S13>/Dead Zone'
                                        */
  real_T PosYRight_P1;                 /* Expression: width
                                        * Referenced by: '<S13>/PosYRight'
                                        */
  real_T PosYRight_P2;                 /* Expression: dtype
                                        * Referenced by: '<S13>/PosYRight'
                                        */
  real_T PosYRight_P3;                 /* Expression: portnum
                                        * Referenced by: '<S13>/PosYRight'
                                        */
  real_T PosYRight_P4;                 /* Expression: stime
                                        * Referenced by: '<S13>/PosYRight'
                                        */
  real_T PosYRight_P5;                 /* Expression: stype
                                        * Referenced by: '<S13>/PosYRight'
                                        */
  real_T PosYRight_P6;                 /* Expression: btype
                                        * Referenced by: '<S13>/PosYRight'
                                        */
  real_T DeadZone1_Start;              /* Expression: -0.05
                                        * Referenced by: '<S13>/Dead Zone1'
                                        */
  real_T DeadZone1_End;                /* Expression: 0.05
                                        * Referenced by: '<S13>/Dead Zone1'
                                        */
  real_T R2_continuous_P1;             /* Expression: width
                                        * Referenced by: '<S13>/R2_continuous'
                                        */
  real_T R2_continuous_P2;             /* Expression: dtype
                                        * Referenced by: '<S13>/R2_continuous'
                                        */
  real_T R2_continuous_P3;             /* Expression: portnum
                                        * Referenced by: '<S13>/R2_continuous'
                                        */
  real_T R2_continuous_P4;             /* Expression: stime
                                        * Referenced by: '<S13>/R2_continuous'
                                        */
  real_T R2_continuous_P5;             /* Expression: stype
                                        * Referenced by: '<S13>/R2_continuous'
                                        */
  real_T R2_continuous_P6;             /* Expression: btype
                                        * Referenced by: '<S13>/R2_continuous'
                                        */
  real_T Gain_Gain_ps;                 /* Expression: 0.5
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T DeadZone2_Start;              /* Expression: -0.05
                                        * Referenced by: '<S13>/Dead Zone2'
                                        */
  real_T DeadZone2_End;                /* Expression: 0.05
                                        * Referenced by: '<S13>/Dead Zone2'
                                        */
  real_T tau_yaw_P1;                   /* Expression: width
                                        * Referenced by: '<S13>/tau_yaw'
                                        */
  real_T tau_yaw_P2;                   /* Expression: dtype
                                        * Referenced by: '<S13>/tau_yaw'
                                        */
  real_T tau_yaw_P3;                   /* Expression: portnum
                                        * Referenced by: '<S13>/tau_yaw'
                                        */
  real_T tau_yaw_P4;                   /* Expression: stime
                                        * Referenced by: '<S13>/tau_yaw'
                                        */
  real_T tau_yaw_P5;                   /* Expression: stype
                                        * Referenced by: '<S13>/tau_yaw'
                                        */
  real_T tau_yaw_P6;                   /* Expression: btype
                                        * Referenced by: '<S13>/tau_yaw'
                                        */
  real_T tau_x_P1;                     /* Expression: width
                                        * Referenced by: '<S13>/tau_x'
                                        */
  real_T tau_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S13>/tau_x'
                                        */
  real_T tau_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S13>/tau_x'
                                        */
  real_T tau_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S13>/tau_x'
                                        */
  real_T tau_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S13>/tau_x'
                                        */
  real_T tau_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S13>/tau_x'
                                        */
  real_T tau_y_P1;                     /* Expression: width
                                        * Referenced by: '<S13>/tau_y'
                                        */
  real_T tau_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S13>/tau_y'
                                        */
  real_T tau_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S13>/tau_y'
                                        */
  real_T tau_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S13>/tau_y'
                                        */
  real_T tau_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S13>/tau_y'
                                        */
  real_T tau_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S13>/tau_y'
                                        */
  real_T PosXLeft_P1;                  /* Expression: width
                                        * Referenced by: '<S13>/PosXLeft'
                                        */
  real_T PosXLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<S13>/PosXLeft'
                                        */
  real_T PosXLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<S13>/PosXLeft'
                                        */
  real_T PosXLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<S13>/PosXLeft'
                                        */
  real_T PosXLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<S13>/PosXLeft'
                                        */
  real_T PosXLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<S13>/PosXLeft'
                                        */
  real_T PosYLeft_P1;                  /* Expression: width
                                        * Referenced by: '<S13>/PosYLeft'
                                        */
  real_T PosYLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<S13>/PosYLeft'
                                        */
  real_T PosYLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<S13>/PosYLeft'
                                        */
  real_T PosYLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<S13>/PosYLeft'
                                        */
  real_T PosYLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<S13>/PosYLeft'
                                        */
  real_T PosYLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<S13>/PosYLeft'
                                        */
  real_T L1_P1;                        /* Expression: width
                                        * Referenced by: '<S13>/L1'
                                        */
  real_T L1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S13>/L1'
                                        */
  real_T L1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S13>/L1'
                                        */
  real_T L1_P4;                        /* Expression: stime
                                        * Referenced by: '<S13>/L1'
                                        */
  real_T L1_P5;                        /* Expression: stype
                                        * Referenced by: '<S13>/L1'
                                        */
  real_T L1_P6;                        /* Expression: btype
                                        * Referenced by: '<S13>/L1'
                                        */
  real_T R1_P1;                        /* Expression: width
                                        * Referenced by: '<S13>/R1'
                                        */
  real_T R1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S13>/R1'
                                        */
  real_T R1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S13>/R1'
                                        */
  real_T R1_P4;                        /* Expression: stime
                                        * Referenced by: '<S13>/R1'
                                        */
  real_T R1_P5;                        /* Expression: stype
                                        * Referenced by: '<S13>/R1'
                                        */
  real_T R1_P6;                        /* Expression: btype
                                        * Referenced by: '<S13>/R1'
                                        */
  real_T ArrowDown_P1;                 /* Expression: width
                                        * Referenced by: '<S13>/ArrowDown'
                                        */
  real_T ArrowDown_P2;                 /* Expression: dtype
                                        * Referenced by: '<S13>/ArrowDown'
                                        */
  real_T ArrowDown_P3;                 /* Expression: portnum
                                        * Referenced by: '<S13>/ArrowDown'
                                        */
  real_T ArrowDown_P4;                 /* Expression: stime
                                        * Referenced by: '<S13>/ArrowDown'
                                        */
  real_T ArrowDown_P5;                 /* Expression: stype
                                        * Referenced by: '<S13>/ArrowDown'
                                        */
  real_T ArrowDown_P6;                 /* Expression: btype
                                        * Referenced by: '<S13>/ArrowDown'
                                        */
  real_T ArrowUp_P1;                   /* Expression: width
                                        * Referenced by: '<S13>/ArrowUp'
                                        */
  real_T ArrowUp_P2;                   /* Expression: dtype
                                        * Referenced by: '<S13>/ArrowUp'
                                        */
  real_T ArrowUp_P3;                   /* Expression: portnum
                                        * Referenced by: '<S13>/ArrowUp'
                                        */
  real_T ArrowUp_P4;                   /* Expression: stime
                                        * Referenced by: '<S13>/ArrowUp'
                                        */
  real_T ArrowUp_P5;                   /* Expression: stype
                                        * Referenced by: '<S13>/ArrowUp'
                                        */
  real_T ArrowUp_P6;                   /* Expression: btype
                                        * Referenced by: '<S13>/ArrowUp'
                                        */
  real_T ArrowLeft_P1;                 /* Expression: width
                                        * Referenced by: '<S13>/ArrowLeft'
                                        */
  real_T ArrowLeft_P2;                 /* Expression: dtype
                                        * Referenced by: '<S13>/ArrowLeft'
                                        */
  real_T ArrowLeft_P3;                 /* Expression: portnum
                                        * Referenced by: '<S13>/ArrowLeft'
                                        */
  real_T ArrowLeft_P4;                 /* Expression: stime
                                        * Referenced by: '<S13>/ArrowLeft'
                                        */
  real_T ArrowLeft_P5;                 /* Expression: stype
                                        * Referenced by: '<S13>/ArrowLeft'
                                        */
  real_T ArrowLeft_P6;                 /* Expression: btype
                                        * Referenced by: '<S13>/ArrowLeft'
                                        */
  real_T ArrowRight_P1;                /* Expression: width
                                        * Referenced by: '<S13>/ArrowRight'
                                        */
  real_T ArrowRight_P2;                /* Expression: dtype
                                        * Referenced by: '<S13>/ArrowRight'
                                        */
  real_T ArrowRight_P3;                /* Expression: portnum
                                        * Referenced by: '<S13>/ArrowRight'
                                        */
  real_T ArrowRight_P4;                /* Expression: stime
                                        * Referenced by: '<S13>/ArrowRight'
                                        */
  real_T ArrowRight_P5;                /* Expression: stype
                                        * Referenced by: '<S13>/ArrowRight'
                                        */
  real_T ArrowRight_P6;                /* Expression: btype
                                        * Referenced by: '<S13>/ArrowRight'
                                        */
  real_T JoysticControllerSwitch_P1;   /* Expression: width
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  real_T JoysticControllerSwitch_P2;   /* Expression: dtype
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  real_T JoysticControllerSwitch_P3;   /* Expression: portnum
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  real_T JoysticControllerSwitch_P4;   /* Expression: stime
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  real_T JoysticControllerSwitch_P5;   /* Expression: stype
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  real_T JoysticControllerSwitch_P6;   /* Expression: btype
                                        * Referenced by: '<Root>/JoysticControllerSwitch'
                                        */
  real_T Switch2_Threshold_i;          /* Expression: 0
                                        * Referenced by: '<Root>/Switch2'
                                        */
  real_T Tau_pre_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/Tau_pre'
                                        */
  real_T Tau_pre_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/Tau_pre'
                                        */
  real_T Tau_pre_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/Tau_pre'
                                        */
  real_T Tau_pre_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/Tau_pre'
                                        */
  real_T Tau_pre_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/Tau_pre'
                                        */
  real_T Tau_pre_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/Tau_pre'
                                        */
  real_T Memory_X0_n2;                 /* Expression: 0
                                        * Referenced by: '<S10>/Memory'
                                        */
  real_T Switch3_Threshold_a;          /* Expression: 0
                                        * Referenced by: '<Root>/Switch3'
                                        */
  real_T sf1_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/sf1'
                                        */
  real_T sf1_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/sf1'
                                        */
  real_T sf1_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/sf1'
                                        */
  real_T sf1_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/sf1'
                                        */
  real_T sf1_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/sf1'
                                        */
  real_T sf1_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/sf1'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S15>/Switch'
                                        */
  real_T Memory_X0_i;                  /* Expression: 0
                                        * Referenced by: '<S15>/Memory'
                                        */
  real_T SZ_ResetKill_P1;              /* Expression: width
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  real_T SZ_ResetKill_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  real_T SZ_ResetKill_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  real_T SZ_ResetKill_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  real_T SZ_ResetKill_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  real_T SZ_ResetKill_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/SZ_ResetKill'
                                        */
  real_T SZ_Owerwrite_P1;              /* Expression: width
                                        * Referenced by: '<Root>/SZ_Owerwrite'
                                        */
  real_T SZ_Owerwrite_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/SZ_Owerwrite'
                                        */
  real_T SZ_Owerwrite_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/SZ_Owerwrite'
                                        */
  real_T SZ_Owerwrite_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/SZ_Owerwrite'
                                        */
  real_T SZ_Owerwrite_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/SZ_Owerwrite'
                                        */
  real_T SZ_Owerwrite_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/SZ_Owerwrite'
                                        */
  real_T Switch2_Threshold_p;          /* Expression: 0
                                        * Referenced by: '<S15>/Switch2'
                                        */
  real_T Constant1_Value_i;            /* Expression: 3
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Switch1_Threshold_l;          /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Actuator_Sat_Forces_Value[2]; /* Expression:  [1.165*2 2.629]
                                        * Referenced by: '<S9>/Actuator_Sat_Forces'
                                        */
  real_T Tau_post_P1;                  /* Expression: width
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  real_T Tau_post_P2;                  /* Expression: dtype
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  real_T Tau_post_P3;                  /* Expression: portnum
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  real_T Tau_post_P4;                  /* Expression: stime
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  real_T Tau_post_P5;                  /* Expression: stype
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  real_T Tau_post_P6;                  /* Expression: btype
                                        * Referenced by: '<Root>/Tau_post'
                                        */
  real_T P_d_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/P_d'
                                        */
  real_T P_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/P_d'
                                        */
  real_T P_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/P_d'
                                        */
  real_T P_d_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/P_d'
                                        */
  real_T P_d_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/P_d'
                                        */
  real_T P_d_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/P_d'
                                        */
  real_T dropoutFlag_P1;               /* Expression: width
                                        * Referenced by: '<Root>/dropoutFlag'
                                        */
  real_T dropoutFlag_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/dropoutFlag'
                                        */
  real_T dropoutFlag_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/dropoutFlag'
                                        */
  real_T dropoutFlag_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/dropoutFlag'
                                        */
  real_T dropoutFlag_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/dropoutFlag'
                                        */
  real_T dropoutFlag_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/dropoutFlag'
                                        */
  real_T sf2_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/sf2'
                                        */
  real_T sf2_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/sf2'
                                        */
  real_T sf2_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/sf2'
                                        */
  real_T sf2_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/sf2'
                                        */
  real_T sf2_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/sf2'
                                        */
  real_T sf2_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/sf2'
                                        */
  real_T sf3_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/sf3'
                                        */
  real_T sf3_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/sf3'
                                        */
  real_T sf3_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/sf3'
                                        */
  real_T sf3_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/sf3'
                                        */
  real_T sf3_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/sf3'
                                        */
  real_T sf3_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/sf3'
                                        */
  real_T biasOffset_P1;                /* Expression: width
                                        * Referenced by: '<Root>/biasOffset'
                                        */
  real_T biasOffset_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/biasOffset'
                                        */
  real_T biasOffset_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/biasOffset'
                                        */
  real_T biasOffset_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/biasOffset'
                                        */
  real_T biasOffset_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/biasOffset'
                                        */
  real_T biasOffset_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/biasOffset'
                                        */
  real_T X_d_P1;                       /* Expression: width
                                        * Referenced by: '<S16>/X_d'
                                        */
  real_T X_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S16>/X_d'
                                        */
  real_T X_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S16>/X_d'
                                        */
  real_T X_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S16>/X_d'
                                        */
  real_T X_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S16>/X_d'
                                        */
  real_T X_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S16>/X_d'
                                        */
  real_T N_d_P1;                       /* Expression: width
                                        * Referenced by: '<S16>/N_d'
                                        */
  real_T N_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S16>/N_d'
                                        */
  real_T N_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S16>/N_d'
                                        */
  real_T N_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S16>/N_d'
                                        */
  real_T N_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S16>/N_d'
                                        */
  real_T N_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S16>/N_d'
                                        */
  real_T Y_d_P1;                       /* Expression: width
                                        * Referenced by: '<S16>/Y_d'
                                        */
  real_T Y_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S16>/Y_d'
                                        */
  real_T Y_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S16>/Y_d'
                                        */
  real_T Y_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S16>/Y_d'
                                        */
  real_T Y_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S16>/Y_d'
                                        */
  real_T Y_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S16>/Y_d'
                                        */
  real_T psi_0_P1;                     /* Expression: width
                                        * Referenced by: '<S16>/psi_0 '
                                        */
  real_T psi_0_P2;                     /* Expression: dtype
                                        * Referenced by: '<S16>/psi_0 '
                                        */
  real_T psi_0_P3;                     /* Expression: portnum
                                        * Referenced by: '<S16>/psi_0 '
                                        */
  real_T psi_0_P4;                     /* Expression: stime
                                        * Referenced by: '<S16>/psi_0 '
                                        */
  real_T psi_0_P5;                     /* Expression: stype
                                        * Referenced by: '<S16>/psi_0 '
                                        */
  real_T psi_0_P6;                     /* Expression: btype
                                        * Referenced by: '<S16>/psi_0 '
                                        */
  real_T x_0_P1;                       /* Expression: width
                                        * Referenced by: '<S16>/x_0'
                                        */
  real_T x_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<S16>/x_0'
                                        */
  real_T x_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<S16>/x_0'
                                        */
  real_T x_0_P4;                       /* Expression: stime
                                        * Referenced by: '<S16>/x_0'
                                        */
  real_T x_0_P5;                       /* Expression: stype
                                        * Referenced by: '<S16>/x_0'
                                        */
  real_T x_0_P6;                       /* Expression: btype
                                        * Referenced by: '<S16>/x_0'
                                        */
  real_T y_0_P1;                       /* Expression: width
                                        * Referenced by: '<S16>/y_0'
                                        */
  real_T y_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<S16>/y_0'
                                        */
  real_T y_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<S16>/y_0'
                                        */
  real_T y_0_P4;                       /* Expression: stime
                                        * Referenced by: '<S16>/y_0'
                                        */
  real_T y_0_P5;                       /* Expression: stype
                                        * Referenced by: '<S16>/y_0'
                                        */
  real_T y_0_P6;                       /* Expression: btype
                                        * Referenced by: '<S16>/y_0'
                                        */
  real_T integratorresetmodel_P1;      /* Expression: width
                                        * Referenced by: '<S16>/integrator reset model'
                                        */
  real_T integratorresetmodel_P2;      /* Expression: dtype
                                        * Referenced by: '<S16>/integrator reset model'
                                        */
  real_T integratorresetmodel_P3;      /* Expression: portnum
                                        * Referenced by: '<S16>/integrator reset model'
                                        */
  real_T integratorresetmodel_P4;      /* Expression: stime
                                        * Referenced by: '<S16>/integrator reset model'
                                        */
  real_T integratorresetmodel_P5;      /* Expression: stype
                                        * Referenced by: '<S16>/integrator reset model'
                                        */
  real_T integratorresetmodel_P6;      /* Expression: btype
                                        * Referenced by: '<S16>/integrator reset model'
                                        */
  real_T Memory_X0_j;                  /* Expression: 1
                                        * Referenced by: '<S49>/Memory'
                                        */
  real_T Constant_Value_e[3];          /* Expression: [1;1;1]
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T bHat_IC;                      /* Expression: 0
                                        * Referenced by: '<S56>/bHat'
                                        */
  real_T IC1_Value[3];                 /* Expression: [0;0;0]
                                        * Referenced by: '<S56>/IC1'
                                        */
  real_T IC_Value_f[3];                /* Expression: [0;0;0]
                                        * Referenced by: '<S58>/IC'
                                        */
  real_T eta_real_P1;                  /* Expression: width
                                        * Referenced by: '<S7>/eta_real'
                                        */
  real_T eta_real_P2;                  /* Expression: dtype
                                        * Referenced by: '<S7>/eta_real'
                                        */
  real_T eta_real_P3;                  /* Expression: portnum
                                        * Referenced by: '<S7>/eta_real'
                                        */
  real_T eta_real_P4;                  /* Expression: stime
                                        * Referenced by: '<S7>/eta_real'
                                        */
  real_T eta_real_P5;                  /* Expression: stype
                                        * Referenced by: '<S7>/eta_real'
                                        */
  real_T eta_real_P6;                  /* Expression: btype
                                        * Referenced by: '<S7>/eta_real'
                                        */
  real_T Constant2_Value_o;            /* Expression: 0
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T u_BT_P1;                      /* Expression: width
                                        * Referenced by: '<S9>/u_BT'
                                        */
  real_T u_BT_P2;                      /* Expression: dtype
                                        * Referenced by: '<S9>/u_BT'
                                        */
  real_T u_BT_P3;                      /* Expression: portnum
                                        * Referenced by: '<S9>/u_BT'
                                        */
  real_T u_BT_P4;                      /* Expression: stime
                                        * Referenced by: '<S9>/u_BT'
                                        */
  real_T u_BT_P5;                      /* Expression: stype
                                        * Referenced by: '<S9>/u_BT'
                                        */
  real_T u_BT_P6;                      /* Expression: btype
                                        * Referenced by: '<S9>/u_BT'
                                        */
  real_T TurnOffomega1_P1;             /* Expression: width
                                        * Referenced by: '<S9>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P2;             /* Expression: dtype
                                        * Referenced by: '<S9>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P3;             /* Expression: portnum
                                        * Referenced by: '<S9>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P4;             /* Expression: stime
                                        * Referenced by: '<S9>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P5;             /* Expression: stype
                                        * Referenced by: '<S9>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P6;             /* Expression: btype
                                        * Referenced by: '<S9>/TurnOffomega1'
                                        */
  real_T TurnOffomega2_P1;             /* Expression: width
                                        * Referenced by: '<S9>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P2;             /* Expression: dtype
                                        * Referenced by: '<S9>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P3;             /* Expression: portnum
                                        * Referenced by: '<S9>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P4;             /* Expression: stime
                                        * Referenced by: '<S9>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P5;             /* Expression: stype
                                        * Referenced by: '<S9>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P6;             /* Expression: btype
                                        * Referenced by: '<S9>/TurnOffomega2'
                                        */
  real_T u_VSP1_P1;                    /* Expression: width
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  real_T u_VSP1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  real_T u_VSP1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  real_T u_VSP1_P4;                    /* Expression: stime
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  real_T u_VSP1_P5;                    /* Expression: stype
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  real_T u_VSP1_P6;                    /* Expression: btype
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  real_T u_VSP2_P1;                    /* Expression: width
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  real_T u_VSP2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  real_T u_VSP2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  real_T u_VSP2_P4;                    /* Expression: stime
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  real_T u_VSP2_P5;                    /* Expression: stype
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  real_T u_VSP2_P6;                    /* Expression: btype
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  real_T alpha_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  real_T alpha_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  real_T Constant_Value_ks;            /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S79>/Step'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<S9>/Switch'
                                        */
  real_T omega_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Switch1_Threshold_o;          /* Expression: 0
                                        * Referenced by: '<S9>/Switch1'
                                        */
  real_T omega_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  real_T Constant3_Value_i;            /* Expression: 0
                                        * Referenced by: '<S9>/Constant3'
                                        */
  real_T f_bt_P1;                      /* Expression: width
                                        * Referenced by: '<S9>/f_bt'
                                        */
  real_T f_bt_P2;                      /* Expression: dtype
                                        * Referenced by: '<S9>/f_bt'
                                        */
  real_T f_bt_P3;                      /* Expression: portnum
                                        * Referenced by: '<S9>/f_bt'
                                        */
  real_T f_bt_P4;                      /* Expression: stime
                                        * Referenced by: '<S9>/f_bt'
                                        */
  real_T f_bt_P5;                      /* Expression: stype
                                        * Referenced by: '<S9>/f_bt'
                                        */
  real_T f_bt_P6;                      /* Expression: btype
                                        * Referenced by: '<S9>/f_bt'
                                        */
  real_T f_vspx_P1;                    /* Expression: width
                                        * Referenced by: '<S9>/f_vspx'
                                        */
  real_T f_vspx_P2;                    /* Expression: dtype
                                        * Referenced by: '<S9>/f_vspx'
                                        */
  real_T f_vspx_P3;                    /* Expression: portnum
                                        * Referenced by: '<S9>/f_vspx'
                                        */
  real_T f_vspx_P4;                    /* Expression: stime
                                        * Referenced by: '<S9>/f_vspx'
                                        */
  real_T f_vspx_P5;                    /* Expression: stype
                                        * Referenced by: '<S9>/f_vspx'
                                        */
  real_T f_vspx_P6;                    /* Expression: btype
                                        * Referenced by: '<S9>/f_vspx'
                                        */
  real_T f_vspy_P1;                    /* Expression: width
                                        * Referenced by: '<S9>/ f_vspy'
                                        */
  real_T f_vspy_P2;                    /* Expression: dtype
                                        * Referenced by: '<S9>/ f_vspy'
                                        */
  real_T f_vspy_P3;                    /* Expression: portnum
                                        * Referenced by: '<S9>/ f_vspy'
                                        */
  real_T f_vspy_P4;                    /* Expression: stime
                                        * Referenced by: '<S9>/ f_vspy'
                                        */
  real_T f_vspy_P5;                    /* Expression: stype
                                        * Referenced by: '<S9>/ f_vspy'
                                        */
  real_T f_vspy_P6;                    /* Expression: btype
                                        * Referenced by: '<S9>/ f_vspy'
                                        */
  real_T y_in_P1;                      /* Expression: width
                                        * Referenced by: '<S12>/y_in'
                                        */
  real_T y_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<S12>/y_in'
                                        */
  real_T y_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<S12>/y_in'
                                        */
  real_T y_in_P4;                      /* Expression: stime
                                        * Referenced by: '<S12>/y_in'
                                        */
  real_T y_in_P5;                      /* Expression: stype
                                        * Referenced by: '<S12>/y_in'
                                        */
  real_T y_in_P6;                      /* Expression: btype
                                        * Referenced by: '<S12>/y_in'
                                        */
  real_T psi_in_P1;                    /* Expression: width
                                        * Referenced by: '<S12>/psi_in'
                                        */
  real_T psi_in_P2;                    /* Expression: dtype
                                        * Referenced by: '<S12>/psi_in'
                                        */
  real_T psi_in_P3;                    /* Expression: portnum
                                        * Referenced by: '<S12>/psi_in'
                                        */
  real_T psi_in_P4;                    /* Expression: stime
                                        * Referenced by: '<S12>/psi_in'
                                        */
  real_T psi_in_P5;                    /* Expression: stype
                                        * Referenced by: '<S12>/psi_in'
                                        */
  real_T psi_in_P6;                    /* Expression: btype
                                        * Referenced by: '<S12>/psi_in'
                                        */
  real_T u_in_P1;                      /* Expression: width
                                        * Referenced by: '<S12>/u_in'
                                        */
  real_T u_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<S12>/u_in'
                                        */
  real_T u_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<S12>/u_in'
                                        */
  real_T u_in_P4;                      /* Expression: stime
                                        * Referenced by: '<S12>/u_in'
                                        */
  real_T u_in_P5;                      /* Expression: stype
                                        * Referenced by: '<S12>/u_in'
                                        */
  real_T u_in_P6;                      /* Expression: btype
                                        * Referenced by: '<S12>/u_in'
                                        */
  real_T u_real_P1;                    /* Expression: width
                                        * Referenced by: '<S12>/u_real  '
                                        */
  real_T u_real_P2;                    /* Expression: dtype
                                        * Referenced by: '<S12>/u_real  '
                                        */
  real_T u_real_P3;                    /* Expression: portnum
                                        * Referenced by: '<S12>/u_real  '
                                        */
  real_T u_real_P4;                    /* Expression: stime
                                        * Referenced by: '<S12>/u_real  '
                                        */
  real_T u_real_P5;                    /* Expression: stype
                                        * Referenced by: '<S12>/u_real  '
                                        */
  real_T u_real_P6;                    /* Expression: btype
                                        * Referenced by: '<S12>/u_real  '
                                        */
  real_T x_in_P1;                      /* Expression: width
                                        * Referenced by: '<S12>/x_in'
                                        */
  real_T x_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<S12>/x_in'
                                        */
  real_T x_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<S12>/x_in'
                                        */
  real_T x_in_P4;                      /* Expression: stime
                                        * Referenced by: '<S12>/x_in'
                                        */
  real_T x_in_P5;                      /* Expression: stype
                                        * Referenced by: '<S12>/x_in'
                                        */
  real_T x_in_P6;                      /* Expression: btype
                                        * Referenced by: '<S12>/x_in'
                                        */
  real_T r_in_P1;                      /* Expression: width
                                        * Referenced by: '<S12>/r_in'
                                        */
  real_T r_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<S12>/r_in'
                                        */
  real_T r_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<S12>/r_in'
                                        */
  real_T r_in_P4;                      /* Expression: stime
                                        * Referenced by: '<S12>/r_in'
                                        */
  real_T r_in_P5;                      /* Expression: stype
                                        * Referenced by: '<S12>/r_in'
                                        */
  real_T r_in_P6;                      /* Expression: btype
                                        * Referenced by: '<S12>/r_in'
                                        */
  real_T v_in_P1;                      /* Expression: width
                                        * Referenced by: '<S12>/v_in'
                                        */
  real_T v_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<S12>/v_in'
                                        */
  real_T v_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<S12>/v_in'
                                        */
  real_T v_in_P4;                      /* Expression: stime
                                        * Referenced by: '<S12>/v_in'
                                        */
  real_T v_in_P5;                      /* Expression: stype
                                        * Referenced by: '<S12>/v_in'
                                        */
  real_T v_in_P6;                      /* Expression: btype
                                        * Referenced by: '<S12>/v_in'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T controlinputuexceedsbounds_P1;/* Expression: width
                                        * Referenced by: '<S93>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P2;/* Expression: dtype
                                        * Referenced by: '<S93>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P3;/* Expression: portnum
                                        * Referenced by: '<S93>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P4;/* Expression: stime
                                        * Referenced by: '<S93>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P5;/* Expression: stype
                                        * Referenced by: '<S93>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P6;/* Expression: btype
                                        * Referenced by: '<S93>/control input u exceeds bounds'
                                        */
  real_T alpha_VSP1_P1_l;              /* Expression: width
                                        * Referenced by: '<S95>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2_l;              /* Expression: dtype
                                        * Referenced by: '<S95>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3_c;              /* Expression: portnum
                                        * Referenced by: '<S95>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4_f;              /* Expression: stime
                                        * Referenced by: '<S95>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5_b;              /* Expression: stype
                                        * Referenced by: '<S95>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6_g;              /* Expression: btype
                                        * Referenced by: '<S95>/alpha_VSP1'
                                        */
  real_T alpha_VSP2_P1_e;              /* Expression: width
                                        * Referenced by: '<S95>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2_j;              /* Expression: dtype
                                        * Referenced by: '<S95>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3_l;              /* Expression: portnum
                                        * Referenced by: '<S95>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4_n;              /* Expression: stime
                                        * Referenced by: '<S95>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5_g;              /* Expression: stype
                                        * Referenced by: '<S95>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6_o;              /* Expression: btype
                                        * Referenced by: '<S95>/alpha_VSP2'
                                        */
  real_T omega_VSP1_P1_c;              /* Expression: width
                                        * Referenced by: '<S95>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2_d;              /* Expression: dtype
                                        * Referenced by: '<S95>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3_j;              /* Expression: portnum
                                        * Referenced by: '<S95>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4_e;              /* Expression: stime
                                        * Referenced by: '<S95>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5_p;              /* Expression: stype
                                        * Referenced by: '<S95>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6_d;              /* Expression: btype
                                        * Referenced by: '<S95>/omega_VSP1'
                                        */
  real_T omega_VSP2_P1_n;              /* Expression: width
                                        * Referenced by: '<S95>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2_j;              /* Expression: dtype
                                        * Referenced by: '<S95>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3_o;              /* Expression: portnum
                                        * Referenced by: '<S95>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4_i;              /* Expression: stime
                                        * Referenced by: '<S95>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5_h;              /* Expression: stype
                                        * Referenced by: '<S95>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6_k;              /* Expression: btype
                                        * Referenced by: '<S95>/omega_VSP2'
                                        */
  real_T u_BT_P1_p;                    /* Expression: width
                                        * Referenced by: '<S95>/u_BT'
                                        */
  real_T u_BT_P2_a;                    /* Expression: dtype
                                        * Referenced by: '<S95>/u_BT'
                                        */
  real_T u_BT_P3_i;                    /* Expression: portnum
                                        * Referenced by: '<S95>/u_BT'
                                        */
  real_T u_BT_P4_n;                    /* Expression: stime
                                        * Referenced by: '<S95>/u_BT'
                                        */
  real_T u_BT_P5_g;                    /* Expression: stype
                                        * Referenced by: '<S95>/u_BT'
                                        */
  real_T u_BT_P6_h;                    /* Expression: btype
                                        * Referenced by: '<S95>/u_BT'
                                        */
  real_T u_VSP1_P1_f;                  /* Expression: width
                                        * Referenced by: '<S95>/u_VSP1'
                                        */
  real_T u_VSP1_P2_o;                  /* Expression: dtype
                                        * Referenced by: '<S95>/u_VSP1'
                                        */
  real_T u_VSP1_P3_m;                  /* Expression: portnum
                                        * Referenced by: '<S95>/u_VSP1'
                                        */
  real_T u_VSP1_P4_p;                  /* Expression: stime
                                        * Referenced by: '<S95>/u_VSP1'
                                        */
  real_T u_VSP1_P5_n;                  /* Expression: stype
                                        * Referenced by: '<S95>/u_VSP1'
                                        */
  real_T u_VSP1_P6_b;                  /* Expression: btype
                                        * Referenced by: '<S95>/u_VSP1'
                                        */
  real_T u_VSP2_P1_o;                  /* Expression: width
                                        * Referenced by: '<S95>/u_VSP2'
                                        */
  real_T u_VSP2_P2_a;                  /* Expression: dtype
                                        * Referenced by: '<S95>/u_VSP2'
                                        */
  real_T u_VSP2_P3_m;                  /* Expression: portnum
                                        * Referenced by: '<S95>/u_VSP2'
                                        */
  real_T u_VSP2_P4_m;                  /* Expression: stime
                                        * Referenced by: '<S95>/u_VSP2'
                                        */
  real_T u_VSP2_P5_l;                  /* Expression: stype
                                        * Referenced by: '<S95>/u_VSP2'
                                        */
  real_T u_VSP2_P6_i;                  /* Expression: btype
                                        * Referenced by: '<S95>/u_VSP2'
                                        */
  real_T NIVeriStandSignalProbe_P1;    /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_student_HIL_T {
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
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[17];
    real_T odeF[3][17];
    ODE3_IntgData intgData;
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
    int_T numPeriodicContStates;
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
extern P_ctrl_student_HIL_T ctrl_student_HIL_P;

/* Block signals (auto storage) */
extern B_ctrl_student_HIL_T ctrl_student_HIL_B;

/* Continuous states (auto storage) */
extern X_ctrl_student_HIL_T ctrl_student_HIL_X;

/* Block states (auto storage) */
extern DW_ctrl_student_HIL_T ctrl_student_HIL_DW;

/* Model entry point functions */
extern void ctrl_student_HIL_initialize(void);
extern void ctrl_student_HIL_output(void);
extern void ctrl_student_HIL_update(void);
extern void ctrl_student_HIL_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_student_HIL_rtModel *ctrl_student_HIL(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_student_HIL_T *const ctrl_student_HIL_M;

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
 * '<Root>' : 'ctrl_student_HIL'
 * '<S1>'   : 'ctrl_student_HIL/ControllerAndParanetrization'
 * '<S2>'   : 'ctrl_student_HIL/ControllerGain'
 * '<S3>'   : 'ctrl_student_HIL/DPObserver1'
 * '<S4>'   : 'ctrl_student_HIL/MATLAB Function'
 * '<S5>'   : 'ctrl_student_HIL/Noise generator'
 * '<S6>'   : 'ctrl_student_HIL/ObserverGain'
 * '<S7>'   : 'ctrl_student_HIL/Position'
 * '<S8>'   : 'ctrl_student_HIL/Rad2Deg'
 * '<S9>'   : 'ctrl_student_HIL/ThrustAllocationAndSaturation'
 * '<S10>'  : 'ctrl_student_HIL/dropoutdet'
 * '<S11>'  : 'ctrl_student_HIL/from enterprise'
 * '<S12>'  : 'ctrl_student_HIL/from model'
 * '<S13>'  : 'ctrl_student_HIL/joystick'
 * '<S14>'  : 'ctrl_student_HIL/physics_model'
 * '<S15>'  : 'ctrl_student_HIL/safety zone '
 * '<S16>'  : 'ctrl_student_HIL/tau to CSE mocell (only use for HIL testing)'
 * '<S17>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)'
 * '<S18>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1'
 * '<S19>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization'
 * '<S20>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization'
 * '<S21>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Controller'
 * '<S22>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization '
 * '<S23>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s'
 * '<S24>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1'
 * '<S25>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1'
 * '<S26>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function'
 * '<S27>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1'
 * '<S28>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix'
 * '<S29>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed'
 * '<S30>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Rotation Matrix'
 * '<S31>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Controller/Controller'
 * '<S32>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function'
 * '<S33>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1'
 * '<S34>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Controller/Controller/alpha_1dott'
 * '<S35>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Controller/Controller/alpha_1dott/MATLAB Function'
 * '<S36>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips'
 * '<S37>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight'
 * '<S38>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Check_s'
 * '<S39>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization '
 * '<S40>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator'
 * '<S41>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Check_s/CheckS&getU'
 * '<S42>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization /Subsystem'
 * '<S43>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization /Subsystem/MATLAB Function'
 * '<S44>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/MATLAB Function1'
 * '<S45>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/UpdateLaw'
 * '<S46>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization '
 * '<S47>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator'
 * '<S48>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Eta_ds'
 * '<S49>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem'
 * '<S50>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Eta_ds/MATLAB Function'
 * '<S51>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Eta_ds/MATLAB Function1'
 * '<S52>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function'
 * '<S53>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function1'
 * '<S54>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/MATLAB Function1'
 * '<S55>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/UpdateLaw'
 * '<S56>'  : 'ctrl_student_HIL/DPObserver1/Bias'
 * '<S57>'  : 'ctrl_student_HIL/DPObserver1/D'
 * '<S58>'  : 'ctrl_student_HIL/DPObserver1/Subsystem'
 * '<S59>'  : 'ctrl_student_HIL/DPObserver1/calcR(psi) '
 * '<S60>'  : 'ctrl_student_HIL/DPObserver1/etaHat'
 * '<S61>'  : 'ctrl_student_HIL/DPObserver1/Bias/bHatDot'
 * '<S62>'  : 'ctrl_student_HIL/DPObserver1/Subsystem/M'
 * '<S63>'  : 'ctrl_student_HIL/DPObserver1/Subsystem/nuHatDot'
 * '<S64>'  : 'ctrl_student_HIL/DPObserver1/etaHat/MATLAB Function'
 * '<S65>'  : 'ctrl_student_HIL/DPObserver1/etaHat/Subsystem'
 * '<S66>'  : 'ctrl_student_HIL/DPObserver1/etaHat/etaHatDot'
 * '<S67>'  : 'ctrl_student_HIL/DPObserver1/etaHat/Subsystem/MATLAB Function1'
 * '<S68>'  : 'ctrl_student_HIL/Noise generator/Downsample	signal'
 * '<S69>'  : 'ctrl_student_HIL/Noise generator/Sample & hold'
 * '<S70>'  : 'ctrl_student_HIL/Noise generator/noise generator'
 * '<S71>'  : 'ctrl_student_HIL/Noise generator/Downsample	signal/MATLAB Function'
 * '<S72>'  : 'ctrl_student_HIL/Noise generator/Sample & hold/MATLAB Function1'
 * '<S73>'  : 'ctrl_student_HIL/Noise generator/noise generator/Band-limited white noise psi'
 * '<S74>'  : 'ctrl_student_HIL/Noise generator/noise generator/Band-limited white noise x'
 * '<S75>'  : 'ctrl_student_HIL/Noise generator/noise generator/Band-limited white noise y'
 * '<S76>'  : 'ctrl_student_HIL/Position/Deg2Rad'
 * '<S77>'  : 'ctrl_student_HIL/ThrustAllocationAndSaturation/Force Allocation1'
 * '<S78>'  : 'ctrl_student_HIL/ThrustAllocationAndSaturation/Force2Control'
 * '<S79>'  : 'ctrl_student_HIL/ThrustAllocationAndSaturation/Ramp'
 * '<S80>'  : 'ctrl_student_HIL/ThrustAllocationAndSaturation/actForces1'
 * '<S81>'  : 'ctrl_student_HIL/dropoutdet/dropOutDetect'
 * '<S82>'  : 'ctrl_student_HIL/joystick/Contoller_Map1'
 * '<S83>'  : 'ctrl_student_HIL/joystick/Sel_Control_Mode'
 * '<S84>'  : 'ctrl_student_HIL/physics_model/kinematics'
 * '<S85>'  : 'ctrl_student_HIL/physics_model/kinetics'
 * '<S86>'  : 'ctrl_student_HIL/safety zone /KillSwitch'
 * '<S87>'  : 'ctrl_student_HIL/safety zone /MATLAB Function'
 * '<S88>'  : 'ctrl_student_HIL/safety zone /MATLAB Function1'
 * '<S89>'  : 'ctrl_student_HIL/safety zone /Safety Act'
 * '<S90>'  : 'ctrl_student_HIL/safety zone /safety check'
 * '<S91>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/Full thrust allocation'
 * '<S92>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/Limited allocation: VSP only  in surge and BT only in yaw'
 * '<S93>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/To thruster of real ship'
 * '<S94>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/To thruster of real ship/control limit checking'
 * '<S95>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/To thruster of real ship/u'
 */
#endif                                 /* RTW_HEADER_ctrl_student_HIL_h_ */

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#define NI_SIT_PARAMS
#ifdef NI_ROOTMODEL_ctrl_student_HIL
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

P_ctrl_student_HIL_T rtParameter[NUMST+!TID01EQ];
P_ctrl_student_HIL_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

P_ctrl_student_HIL_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

extern int tid;
extern P_ctrl_student_HIL_T* param_lookup[NUMST][2];

#else

extern P_ctrl_student_HIL_T rtParameter[];

#endif
#endif

#ifdef MULTITASKING
#define ctrl_student_HIL_P             (*param_lookup[tid][READSIDE])
#else
#define ctrl_student_HIL_P             rtParameter[READSIDE]
#endif
#endif
#endif
