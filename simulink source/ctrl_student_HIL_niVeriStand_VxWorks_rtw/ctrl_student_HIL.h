/*
 * ctrl_student_HIL.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.392
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Apr 07 16:40:01 2017
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

/* Block signals for system '<S24>/MATLAB Function1' */
typedef struct {
  real_T R_T[9];                       /* '<S24>/MATLAB Function1' */
} B_MATLABFunction1_ctrl_studen_T;

/* Block signals for system '<S41>/MATLAB Function1' */
typedef struct {
  real_T SwitchSignal_Out;             /* '<S41>/MATLAB Function1' */
} B_MATLABFunction1_ctrl_stud_k_T;

/* Block signals for system '<S10>/Force Allocation1' */
typedef struct {
  real_T f_vspx1;                      /* '<S10>/Force Allocation1' */
  real_T f_vspx2;                      /* '<S10>/Force Allocation1' */
  real_T f_vspy1;                      /* '<S10>/Force Allocation1' */
  real_T f_vspy2;                      /* '<S10>/Force Allocation1' */
} B_ForceAllocation1_ctrl_stude_T;

/* Block signals for system '<S10>/Force2Control' */
typedef struct {
  real_T u_vsp1;                       /* '<S10>/Force2Control' */
  real_T u_vsp2;                       /* '<S10>/Force2Control' */
  real_T alpha1;                       /* '<S10>/Force2Control' */
  real_T alpha2;                       /* '<S10>/Force2Control' */
} B_Force2Control_ctrl_student__T;

/* Block signals (auto storage) */
typedef struct {
  real_T reset;                        /* '<Root>/reset' */
  real_T NoisePowPos;                  /* '<Root>/NoisePowPos' */
  real_T WhiteNoise;                   /* '<S76>/White Noise' */
  real_T WhiteNoise_e;                 /* '<S77>/White Noise' */
  real_T NoisePowHead;                 /* '<Root>/NoisePowHead' */
  real_T WhiteNoise_m;                 /* '<S75>/White Noise' */
  real_T X_ship;                       /* '<S12>/X_ship' */
  real_T Y_ship;                       /* '<S12>/Y_ship' */
  real_T PSI_ship;                     /* '<S12>/PSI_ship' */
  real_T Memory;                       /* '<S8>/Memory' */
  real_T TmpSignalConversionAteta_realIn[3];
  real_T Hold[3];                      /* '<S71>/Hold' */
  real_T NoiseEnable;                  /* '<Root>/NoiseEnable' */
  real_T Switch[3];                    /* '<S6>/Switch' */
  real_T TmpSignalConversionAteta_hatInp[3];
  real_T dropOutTolerance;             /* '<Root>/dropOutTolerance' */
  real_T res_ship;                     /* '<S12>/res_ship' */
  real_T TmpSignalConversionAtResidualIn[2];
  real_T Sum1[3];                      /* '<Root>/Sum1' */
  real_T ControllerGainK2;             /* '<Root>/ControllerGainK2' */
  real_T Gain[9];                      /* '<S26>/Gain' */
  real_T Integrator;                   /* '<S41>/Integrator' */
  real_T IC;                           /* '<S37>/IC' */
  real_T Integrator_m;                 /* '<S48>/Integrator' */
  real_T Memory2;                      /* '<S50>/Memory2' */
  real_T Memory1[2];                   /* '<S50>/Memory1' */
  real_T Sum[2];                       /* '<S47>/Sum' */
  real_T Switch_j[2];                  /* '<S20>/Switch' */
  real_T Product[3];                   /* '<S25>/Product' */
  real_T IC_n;                         /* '<S38>/IC' */
  real_T nuHat[3];                     /* '<S59>/nuHat' */
  real_T Sum_g[3];                     /* '<S23>/Sum' */
  real_T Kz_2[3];                      /* '<S32>/K*z_2' */
  real_T ControllerGainK1;             /* '<Root>/ControllerGainK1' */
  real_T Malpha_dott[3];               /* '<S32>/M*alpha_dott' */
  real_T Kz_1[3];                      /* '<S32>/K*z_1' */
  real_T Sum2[3];                      /* '<S32>/Sum2' */
  real_T Switch2[3];                   /* '<S22>/Switch2' */
  real_T L2_continuous;                /* '<S14>/L2_continuous' */
  real_T CurrentModeSelector;          /* '<S14>/CurrentModeSelector' */
  real_T PosXRight;                    /* '<S14>/PosXRight' */
  real_T PosYRight;                    /* '<S14>/PosYRight' */
  real_T R2_continuous;                /* '<S14>/R2_continuous' */
  real_T PosXLeft;                     /* '<S14>/PosXLeft' */
  real_T PosYLeft;                     /* '<S14>/PosYLeft' */
  real_T L1;                           /* '<S14>/L1' */
  real_T R1;                           /* '<S14>/R1' */
  real_T ArrowDown;                    /* '<S14>/ArrowDown' */
  real_T ArrowUp;                      /* '<S14>/ArrowUp' */
  real_T ArrowLeft;                    /* '<S14>/ArrowLeft' */
  real_T ArrowRight;                   /* '<S14>/ArrowRight' */
  real_T Select;                       /* '<S14>/Select' */
  real_T JoysticControllerSwitch;      /* '<Root>/JoysticControllerSwitch' */
  real_T Switch2_g[3];                 /* '<Root>/Switch2' */
  real_T sf1;                          /* '<Root>/sf1' */
  real_T Memory_m[3];                  /* '<S11>/Memory' */
  real_T biasOffset;                   /* '<Root>/biasOffset' */
  real_T IC1[3];                       /* '<S57>/IC1' */
  real_T Switch1;                      /* '<S20>/Switch1' */
  real_T sf2;                          /* '<Root>/sf2' */
  real_T sf3;                          /* '<Root>/sf3' */
  real_T Delay[3];                     /* '<S59>/Delay' */
  real_T Switch3[3];                   /* '<Root>/Switch3' */
  real_T SZ_ResetKill;                 /* '<Root>/SZ_ResetKill' */
  real_T SZ_Owerwrite;                 /* '<Root>/SZ_Owerwrite' */
  real_T TurnOffomega1;                /* '<S18>/TurnOffomega1' */
  real_T TurnOffomega2;                /* '<S18>/TurnOffomega2' */
  real_T Memory_o;                     /* '<S50>/Memory' */
  real_T Sum_j;                        /* '<S61>/Sum' */
  real_T Switch3_l;                    /* '<S67>/Switch3' */
  real_T IC_i[3];                      /* '<S59>/IC' */
  real_T Memory_j[3];                  /* '<Root>/Memory' */
  real_T Sum2_a;                       /* '<Root>/Sum2' */
  real_T TurnOffomega1_m;              /* '<S10>/TurnOffomega1' */
  real_T TurnOffomega2_d;              /* '<S10>/TurnOffomega2' */
  real_T Switch_b;                     /* '<S10>/Switch' */
  real_T Switch1_k;                    /* '<S10>/Switch1' */
  real_T Sum_n;                        /* '<S10>/Sum' */
  real_T Sum1_n;                       /* '<S10>/Sum1' */
  real_T Memory_n;                     /* '<S16>/Memory' */
  real_T y_in;                         /* '<S13>/y_in' */
  real_T psi_in;                       /* '<S13>/psi_in' */
  real_T u_in;                         /* '<S13>/u_in' */
  real_T x_in;                         /* '<S13>/x_in' */
  real_T r_in;                         /* '<S13>/r_in' */
  real_T v_in;                         /* '<S13>/v_in' */
  real_T u_BT;                         /* '<S18>/Full thrust allocation' */
  real_T u_VSP;                        /* '<S18>/Full thrust allocation' */
  real_T alpha_VSP;                    /* '<S18>/Full thrust allocation' */
  real_T omega_VSP;                    /* '<S18>/Full thrust allocation' */
  real_T kill_signal;                  /* '<S16>/MATLAB Function' */
  real_T nu_dot[3];                    /* '<S15>/kinetics' */
  real_T eta_dot[3];                   /* '<S15>/kinematics' */
  real_T tau_surge;                    /* '<S14>/Contoller_Map1' */
  real_T tau_sway;                     /* '<S14>/Contoller_Map1' */
  real_T tau_yaw;                      /* '<S14>/Contoller_Map1' */
  real_T posOut[3];                    /* '<S11>/dropOutDetect' */
  real_T dropout;                      /* '<S11>/dropOutDetect' */
  real_T tauAct[3];                    /* '<S10>/actForces1' */
  real_T deg_out;                      /* '<S8>/Deg2Rad' */
  real_T output[3];                    /* '<S71>/MATLAB Function1' */
  real_T count;                        /* '<S70>/MATLAB Function' */
  real_T nu[3];                        /* '<Root>/MATLAB Function1' */
  real_T etaHatDot[3];                 /* '<S61>/etaHatDot' */
  real_T bHatDot[3];                   /* '<S57>/bHatDot' */
  real_T s_dot;                        /* '<S48>/UpdateLaw' */
  real_T U_s;                          /* '<S48>/UpdateLaw' */
  real_T SwitchSignal;                 /* '<S50>/MATLAB Function1' */
  real_T N;                            /* '<S50>/MATLAB Function1' */
  real_T SwitchSignal_out;             /* '<S50>/MATLAB Function' */
  real_T N_out;                        /* '<S50>/MATLAB Function' */
  real_T U;                            /* '<S50>/MATLAB Function' */
  real_T s_out;                        /* '<S50>/MATLAB Function' */
  real_T init_time[2];                 /* '<S50>/MATLAB Function' */
  real_T flag;                         /* '<S50>/MATLAB Function' */
  real_T s_dot_l;                      /* '<S41>/UpdateLaw' */
  real_T pd[2];                        /* '<S43>/MATLAB Function' */
  real_T s_out_j;                      /* '<S39>/CheckS&getU' */
  real_T Switch_d;                     /* '<S39>/CheckS&getU' */
  real_T M[9];                         /* '<S32>/MATLAB Function1' */
  boolean_T fault;                     /* '<S98>/control limit checking' */
  B_Force2Control_ctrl_student__T sf_Force2Control_m;/* '<S18>/Force2Control' */
  B_ForceAllocation1_ctrl_stude_T sf_ForceAllocation1_o;/* '<S18>/Force Allocation1' */
  B_Force2Control_ctrl_student__T sf_Force2Control;/* '<S10>/Force2Control' */
  B_ForceAllocation1_ctrl_stude_T sf_ForceAllocation1;/* '<S10>/Force Allocation1' */
  B_MATLABFunction1_ctrl_stud_k_T sf_MATLABFunction1_p;/* '<S48>/MATLAB Function1' */
  B_MATLABFunction1_ctrl_stud_k_T sf_MATLABFunction1_m;/* '<S41>/MATLAB Function1' */
  B_MATLABFunction1_ctrl_studen_T sf_RTransposed;/* '<S25>/R Transposed' */
  B_MATLABFunction1_ctrl_studen_T sf_MATLABFunction1_pa;/* '<S24>/MATLAB Function1' */
} B_ctrl_student_HIL_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[3];              /* '<S59>/Delay' */
  real_T reset_DWORK1;                 /* '<Root>/reset' */
  real_T counter_PreviousInput;        /* '<S70>/counter' */
  real_T NoisePowPos_DWORK1;           /* '<Root>/NoisePowPos' */
  real_T NextOutput;                   /* '<S76>/White Noise' */
  real_T NextOutput_c;                 /* '<S77>/White Noise' */
  real_T NoisePowHead_DWORK1;          /* '<Root>/NoisePowHead' */
  real_T NextOutput_p;                 /* '<S75>/White Noise' */
  real_T X_ship_DWORK1;                /* '<S12>/X_ship' */
  real_T Y_ship_DWORK1;                /* '<S12>/Y_ship' */
  real_T PSI_ship_DWORK1;              /* '<S12>/PSI_ship' */
  real_T Memory_PreviousInput;         /* '<S8>/Memory' */
  real_T Hold_PreviousInput[3];        /* '<S71>/Hold' */
  real_T NoiseEnable_DWORK1;           /* '<Root>/NoiseEnable' */
  real_T eta_hat_DWORK1[3];            /* '<Root>/eta_hat' */
  real_T dropOutTolerance_DWORK1;      /* '<Root>/dropOutTolerance' */
  real_T res_ship_DWORK1;              /* '<S12>/res_ship' */
  real_T Residual_DWORK1[2];           /* '<Root>/Residual' */
  real_T eta_tilde_DWORK1[3];          /* '<Root>/eta_tilde' */
  real_T eta_noise_DWORK1[3];          /* '<Root>/eta_noise' */
  real_T ControllerGainK2_DWORK1;      /* '<Root>/ControllerGainK2' */
  real_T Memory_PreviousInput_f;       /* '<S37>/Memory' */
  real_T IC_FirstOutputTime;           /* '<S37>/IC' */
  real_T Memory_PreviousInput_m;       /* '<S38>/Memory' */
  real_T Memory2_PreviousInput;        /* '<S50>/Memory2' */
  real_T Memory1_PreviousInput[2];     /* '<S50>/Memory1' */
  real_T IC_FirstOutputTime_p;         /* '<S38>/IC' */
  real_T ControllerGainK1_DWORK1;      /* '<Root>/ControllerGainK1' */
  real_T L2_continuous_DWORK1;         /* '<S14>/L2_continuous' */
  real_T CurrentModeSelector_DWORK1;   /* '<S14>/CurrentModeSelector' */
  real_T CurrentMode_DWORK1;           /* '<S14>/Current Mode ' */
  real_T PosXRight_DWORK1;             /* '<S14>/PosXRight' */
  real_T PosYRight_DWORK1;             /* '<S14>/PosYRight' */
  real_T R2_continuous_DWORK1;         /* '<S14>/R2_continuous' */
  real_T tau_yaw_DWORK1;               /* '<S14>/tau_yaw' */
  real_T tau_x_DWORK1;                 /* '<S14>/tau_x' */
  real_T tau_y_DWORK1;                 /* '<S14>/tau_y' */
  real_T PosXLeft_DWORK1;              /* '<S14>/PosXLeft' */
  real_T PosYLeft_DWORK1;              /* '<S14>/PosYLeft' */
  real_T L1_DWORK1;                    /* '<S14>/L1' */
  real_T R1_DWORK1;                    /* '<S14>/R1' */
  real_T ArrowDown_DWORK1;             /* '<S14>/ArrowDown' */
  real_T ArrowUp_DWORK1;               /* '<S14>/ArrowUp' */
  real_T ArrowLeft_DWORK1;             /* '<S14>/ArrowLeft' */
  real_T ArrowRight_DWORK1;            /* '<S14>/ArrowRight' */
  real_T Select_DWORK1;                /* '<S14>/Select' */
  real_T JoysticControllerSwitch_DWORK1;/* '<Root>/JoysticControllerSwitch' */
  real_T Tau_pre_DWORK1[3];            /* '<Root>/Tau_pre' */
  real_T Tau_post_DWORK1[3];           /* '<Root>/Tau_post' */
  real_T P_d_DWORK1[2];                /* '<Root>/P_d' */
  real_T sf1_DWORK1;                   /* '<Root>/sf1' */
  real_T Memory_PreviousInput_d[3];    /* '<S11>/Memory' */
  real_T dropoutFlag_DWORK1;           /* '<Root>/dropoutFlag' */
  real_T biasOffset_DWORK1;            /* '<Root>/biasOffset' */
  real_T IC1_FirstOutputTime;          /* '<S57>/IC1' */
  real_T Bias_DWORK1[3];               /* '<Root>/Bias' */
  real_T S_DWORK1;                     /* '<Root>/S' */
  real_T sf2_DWORK1;                   /* '<Root>/sf2' */
  real_T nu_hat_DWORK1[3];             /* '<Root>/nu_hat ' */
  real_T sf3_DWORK1;                   /* '<Root>/sf3' */
  real_T delay2_DWORK1[3];             /* '<Root>/delay2' */
  real_T delay1_DWORK1[3];             /* '<Root>/delay1' */
  real_T SZ_ResetKill_DWORK1;          /* '<Root>/SZ_ResetKill' */
  real_T SZ_Owerwrite_DWORK1;          /* '<Root>/SZ_Owerwrite' */
  real_T X_d_DWORK1;                   /* '<S17>/X_d' */
  real_T N_d_DWORK1;                   /* '<S17>/N_d' */
  real_T Y_d_DWORK1;                   /* '<S17>/Y_d' */
  real_T psi_0_DWORK1;                 /* '<S17>/psi_0 ' */
  real_T x_0_DWORK1;                   /* '<S17>/x_0' */
  real_T y_0_DWORK1;                   /* '<S17>/y_0' */
  real_T integratorresetmodel_DWORK1;  /* '<S17>/integrator reset model' */
  real_T TurnOffomega1_DWORK1;         /* '<S18>/TurnOffomega1' */
  real_T TurnOffomega2_DWORK1;         /* '<S18>/TurnOffomega2' */
  real_T controlinputuexceedsbounds_DWOR;/* '<S98>/control input u exceeds bounds' */
  real_T alpha_VSP1_DWORK1;            /* '<S100>/alpha_VSP1' */
  real_T alpha_VSP2_DWORK1;            /* '<S100>/alpha_VSP2' */
  real_T omega_VSP1_DWORK1;            /* '<S100>/omega_VSP1' */
  real_T omega_VSP2_DWORK1;            /* '<S100>/omega_VSP2' */
  real_T u_BT_DWORK1;                  /* '<S100>/u_BT' */
  real_T u_VSP1_DWORK1;                /* '<S100>/u_VSP1' */
  real_T u_VSP2_DWORK1;                /* '<S100>/u_VSP2' */
  real_T Memory_PreviousInput_p;       /* '<S50>/Memory' */
  real_T IC_FirstOutputTime_n;         /* '<S59>/IC' */
  real_T Memory_PreviousInput_n[3];    /* '<Root>/Memory' */
  real_T eta_real_DWORK1[3];           /* '<S8>/eta_real' */
  real_T u_BT_DWORK1_n;                /* '<S10>/u_BT' */
  real_T TurnOffomega1_DWORK1_j;       /* '<S10>/TurnOffomega1' */
  real_T TurnOffomega2_DWORK1_k;       /* '<S10>/TurnOffomega2' */
  real_T u_VSP1_DWORK1_h;              /* '<S10>/u_VSP1' */
  real_T u_VSP2_DWORK1_c;              /* '<S10>/u_VSP2' */
  real_T alpha_VSP1_DWORK1_i;          /* '<S10>/alpha_VSP1' */
  real_T alpha_VSP2_DWORK1_k;          /* '<S10>/alpha_VSP2' */
  real_T omega_VSP1_DWORK1_d;          /* '<S10>/omega_VSP1' */
  real_T omega_VSP2_DWORK1_m;          /* '<S10>/omega_VSP2' */
  real_T f_bt_DWORK1;                  /* '<S10>/f_bt' */
  real_T f_vspx_DWORK1;                /* '<S10>/f_vspx' */
  real_T f_vspy_DWORK1;                /* '<S10>/ f_vspy' */
  real_T Memory_PreviousInput_e;       /* '<S16>/Memory' */
  real_T y_in_DWORK1;                  /* '<S13>/y_in' */
  real_T psi_in_DWORK1;                /* '<S13>/psi_in' */
  real_T u_in_DWORK1;                  /* '<S13>/u_in' */
  real_T u_real_DWORK1;                /* '<S13>/u_real  ' */
  real_T x_in_DWORK1;                  /* '<S13>/x_in' */
  real_T r_in_DWORK1;                  /* '<S13>/r_in' */
  real_T v_in_DWORK1;                  /* '<S13>/v_in' */
  struct {
    void *LoggedData;
  } Eta_dss_PWORK;                     /* '<S1>/Eta_dss' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<S1>/To Workspace3' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S19>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S19>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S19>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S22>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_d;                     /* '<S32>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_j;                    /* '<S32>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_k;                    /* '<S32>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_b;                    /* '<S32>/Scope3' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_e;                    /* '<S20>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_m;                    /* '<S20>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_d;                    /* '<S37>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S37>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK_db;                    /* '<S43>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_d;                    /* '<S38>/Scope1' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_bj;                   /* '<S38>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_k;                    /* '<S47>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_s_PWORK;                     /* '<S47>/Scope_ s' */

  struct {
    void *LoggedData;
  } Scope_s_inn_PWORK;                 /* '<S47>/Scope_s_inn' */

  struct {
    void *LoggedData;
  } Scope_switch_PWORK;                /* '<S47>/Scope_switch' */

  struct {
    void *LoggedData;
  } Flag_PWORK;                        /* '<S50>/Flag' */

  struct {
    void *LoggedData;
  } SwitchSig_PWORK;                   /* '<S50>/SwitchSig' */

  struct {
    void *LoggedData;
  } U_scope_PWORK;                     /* '<S50>/U_scope ' */

  int32_T NIVeriStandSignalProbe_DWORK2;/* '<Root>/NIVeriStandSignalProbe' */
  uint32_T RandSeed;                   /* '<S76>/White Noise' */
  uint32_T RandSeed_j;                 /* '<S77>/White Noise' */
  uint32_T RandSeed_c;                 /* '<S75>/White Noise' */
  struct {
    int_T IcNeedsLoading;
  } etaHat1_IWORK;                     /* '<S67>/etaHat1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S15>/Integrator' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK;                 /* '<S15>/Integrator1' */

  uint8_T reset_DWORK2[17];            /* '<Root>/reset' */
  uint8_T NoisePowPos_DWORK2[17];      /* '<Root>/NoisePowPos' */
  uint8_T NoisePowHead_DWORK2[17];     /* '<Root>/NoisePowHead' */
  uint8_T X_ship_DWORK2[17];           /* '<S12>/X_ship' */
  uint8_T Y_ship_DWORK2[17];           /* '<S12>/Y_ship' */
  uint8_T PSI_ship_DWORK2[17];         /* '<S12>/PSI_ship' */
  uint8_T NoiseEnable_DWORK2[17];      /* '<Root>/NoiseEnable' */
  uint8_T eta_hat_DWORK2[17];          /* '<Root>/eta_hat' */
  uint8_T dropOutTolerance_DWORK2[17]; /* '<Root>/dropOutTolerance' */
  uint8_T res_ship_DWORK2[17];         /* '<S12>/res_ship' */
  uint8_T Residual_DWORK2[17];         /* '<Root>/Residual' */
  uint8_T eta_tilde_DWORK2[17];        /* '<Root>/eta_tilde' */
  uint8_T eta_noise_DWORK2[17];        /* '<Root>/eta_noise' */
  uint8_T ControllerGainK2_DWORK2[17]; /* '<Root>/ControllerGainK2' */
  uint8_T ControllerGainK1_DWORK2[17]; /* '<Root>/ControllerGainK1' */
  uint8_T L2_continuous_DWORK2[17];    /* '<S14>/L2_continuous' */
  uint8_T CurrentModeSelector_DWORK2[17];/* '<S14>/CurrentModeSelector' */
  uint8_T CurrentMode_DWORK2[17];      /* '<S14>/Current Mode ' */
  uint8_T PosXRight_DWORK2[17];        /* '<S14>/PosXRight' */
  uint8_T PosYRight_DWORK2[17];        /* '<S14>/PosYRight' */
  uint8_T R2_continuous_DWORK2[17];    /* '<S14>/R2_continuous' */
  uint8_T tau_yaw_DWORK2[17];          /* '<S14>/tau_yaw' */
  uint8_T tau_x_DWORK2[17];            /* '<S14>/tau_x' */
  uint8_T tau_y_DWORK2[17];            /* '<S14>/tau_y' */
  uint8_T PosXLeft_DWORK2[17];         /* '<S14>/PosXLeft' */
  uint8_T PosYLeft_DWORK2[17];         /* '<S14>/PosYLeft' */
  uint8_T L1_DWORK2[17];               /* '<S14>/L1' */
  uint8_T R1_DWORK2[17];               /* '<S14>/R1' */
  uint8_T ArrowDown_DWORK2[17];        /* '<S14>/ArrowDown' */
  uint8_T ArrowUp_DWORK2[17];          /* '<S14>/ArrowUp' */
  uint8_T ArrowLeft_DWORK2[17];        /* '<S14>/ArrowLeft' */
  uint8_T ArrowRight_DWORK2[17];       /* '<S14>/ArrowRight' */
  uint8_T Select_DWORK2[17];           /* '<S14>/Select' */
  uint8_T JoysticControllerSwitch_DWORK2[17];/* '<Root>/JoysticControllerSwitch' */
  uint8_T Tau_pre_DWORK2[17];          /* '<Root>/Tau_pre' */
  uint8_T Tau_post_DWORK2[17];         /* '<Root>/Tau_post' */
  uint8_T P_d_DWORK2[17];              /* '<Root>/P_d' */
  uint8_T sf1_DWORK2[17];              /* '<Root>/sf1' */
  uint8_T dropoutFlag_DWORK2[17];      /* '<Root>/dropoutFlag' */
  uint8_T biasOffset_DWORK2[17];       /* '<Root>/biasOffset' */
  uint8_T Bias_DWORK2[17];             /* '<Root>/Bias' */
  uint8_T S_DWORK2[17];                /* '<Root>/S' */
  uint8_T sf2_DWORK2[17];              /* '<Root>/sf2' */
  uint8_T nu_hat_DWORK2[17];           /* '<Root>/nu_hat ' */
  uint8_T sf3_DWORK2[17];              /* '<Root>/sf3' */
  uint8_T delay2_DWORK2[17];           /* '<Root>/delay2' */
  uint8_T delay1_DWORK2[17];           /* '<Root>/delay1' */
  uint8_T SZ_ResetKill_DWORK2[17];     /* '<Root>/SZ_ResetKill' */
  uint8_T SZ_Owerwrite_DWORK2[17];     /* '<Root>/SZ_Owerwrite' */
  uint8_T X_d_DWORK2[17];              /* '<S17>/X_d' */
  uint8_T N_d_DWORK2[17];              /* '<S17>/N_d' */
  uint8_T Y_d_DWORK2[17];              /* '<S17>/Y_d' */
  uint8_T psi_0_DWORK2[17];            /* '<S17>/psi_0 ' */
  uint8_T x_0_DWORK2[17];              /* '<S17>/x_0' */
  uint8_T y_0_DWORK2[17];              /* '<S17>/y_0' */
  uint8_T integratorresetmodel_DWORK2[17];/* '<S17>/integrator reset model' */
  uint8_T TurnOffomega1_DWORK2[17];    /* '<S18>/TurnOffomega1' */
  uint8_T TurnOffomega2_DWORK2[17];    /* '<S18>/TurnOffomega2' */
  uint8_T controlinputuexceedsbounds_DW_g[17];/* '<S98>/control input u exceeds bounds' */
  uint8_T alpha_VSP1_DWORK2[17];       /* '<S100>/alpha_VSP1' */
  uint8_T alpha_VSP2_DWORK2[17];       /* '<S100>/alpha_VSP2' */
  uint8_T omega_VSP1_DWORK2[17];       /* '<S100>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2[17];       /* '<S100>/omega_VSP2' */
  uint8_T u_BT_DWORK2[17];             /* '<S100>/u_BT' */
  uint8_T u_VSP1_DWORK2[17];           /* '<S100>/u_VSP1' */
  uint8_T u_VSP2_DWORK2[17];           /* '<S100>/u_VSP2' */
  uint8_T eta_real_DWORK2[17];         /* '<S8>/eta_real' */
  uint8_T u_BT_DWORK2_a[17];           /* '<S10>/u_BT' */
  uint8_T TurnOffomega1_DWORK2_j[17];  /* '<S10>/TurnOffomega1' */
  uint8_T TurnOffomega2_DWORK2_a[17];  /* '<S10>/TurnOffomega2' */
  uint8_T u_VSP1_DWORK2_j[17];         /* '<S10>/u_VSP1' */
  uint8_T u_VSP2_DWORK2_j[17];         /* '<S10>/u_VSP2' */
  uint8_T alpha_VSP1_DWORK2_b[17];     /* '<S10>/alpha_VSP1' */
  uint8_T alpha_VSP2_DWORK2_f[17];     /* '<S10>/alpha_VSP2' */
  uint8_T omega_VSP1_DWORK2_b[17];     /* '<S10>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2_n[17];     /* '<S10>/omega_VSP2' */
  uint8_T f_bt_DWORK2[17];             /* '<S10>/f_bt' */
  uint8_T f_vspx_DWORK2[17];           /* '<S10>/f_vspx' */
  uint8_T f_vspy_DWORK2[17];           /* '<S10>/ f_vspy' */
  uint8_T y_in_DWORK2[17];             /* '<S13>/y_in' */
  uint8_T psi_in_DWORK2[17];           /* '<S13>/psi_in' */
  uint8_T u_in_DWORK2[17];             /* '<S13>/u_in' */
  uint8_T u_real_DWORK2[17];           /* '<S13>/u_real  ' */
  uint8_T x_in_DWORK2[17];             /* '<S13>/x_in' */
  uint8_T r_in_DWORK2[17];             /* '<S13>/r_in' */
  uint8_T v_in_DWORK2[17];             /* '<S13>/v_in' */
  uint8_T NIVeriStandSignalProbe_DWORK1[17];/* '<Root>/NIVeriStandSignalProbe' */
  uint8_T NIVeriStandSignalProbe_DWORK3[60];/* '<Root>/NIVeriStandSignalProbe' */
} DW_ctrl_student_HIL_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T etaHat_CSTATE;                /* '<S61>/etaHat' */
  real_T etaHat2_CSTATE;               /* '<S61>/etaHat2' */
  real_T Integrator_CSTATE;            /* '<S41>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S48>/Integrator' */
  real_T nuHat_CSTATE[3];              /* '<S59>/nuHat' */
  real_T bHat_CSTATE[3];               /* '<S57>/bHat' */
  real_T Integrator_CSTATE_o[3];       /* '<Root>/Integrator' */
  real_T etaHat1_CSTATE;               /* '<S67>/etaHat1' */
  real_T Integrator_CSTATE_b[3];       /* '<S15>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S15>/Integrator1' */
} X_ctrl_student_HIL_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T etaHat_CSTATE;                /* '<S61>/etaHat' */
  real_T etaHat2_CSTATE;               /* '<S61>/etaHat2' */
  real_T Integrator_CSTATE;            /* '<S41>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S48>/Integrator' */
  real_T nuHat_CSTATE[3];              /* '<S59>/nuHat' */
  real_T bHat_CSTATE[3];               /* '<S57>/bHat' */
  real_T Integrator_CSTATE_o[3];       /* '<Root>/Integrator' */
  real_T etaHat1_CSTATE;               /* '<S67>/etaHat1' */
  real_T Integrator_CSTATE_b[3];       /* '<S15>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S15>/Integrator1' */
} XDot_ctrl_student_HIL_T;

/* State disabled  */
typedef struct {
  boolean_T etaHat_CSTATE;             /* '<S61>/etaHat' */
  boolean_T etaHat2_CSTATE;            /* '<S61>/etaHat2' */
  boolean_T Integrator_CSTATE;         /* '<S41>/Integrator' */
  boolean_T Integrator_CSTATE_f;       /* '<S48>/Integrator' */
  boolean_T nuHat_CSTATE[3];           /* '<S59>/nuHat' */
  boolean_T bHat_CSTATE[3];            /* '<S57>/bHat' */
  boolean_T Integrator_CSTATE_o[3];    /* '<Root>/Integrator' */
  boolean_T etaHat1_CSTATE;            /* '<S67>/etaHat1' */
  boolean_T Integrator_CSTATE_b[3];    /* '<S15>/Integrator' */
  boolean_T Integrator1_CSTATE[3];     /* '<S15>/Integrator1' */
} XDis_ctrl_student_HIL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState etaHat_Reset_ZCE;         /* '<S61>/etaHat' */
  ZCSigState etaHat2_Reset_ZCE;        /* '<S61>/etaHat2' */
  ZCSigState Integrator_Reset_ZCE;     /* '<S41>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_c;   /* '<S48>/Integrator' */
  ZCSigState etaHat1_Reset_ZCE;        /* '<S67>/etaHat1' */
  ZCSigState Integrator_Reset_ZCE_p;   /* '<S15>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE;    /* '<S15>/Integrator1' */
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
                                        * Referenced by: '<S20>/SwitchSignalFromFile'
                                        */
  real_T Elipscenter_radi[4];          /* Variable: Elipscenter_radi
                                        * Referenced by: '<S40>/Elipscenter_radi'
                                        */
  real_T K[2];                         /* Variable: K
                                        * Referenced by: '<Root>/K'
                                        */
  real_T K1[9];                        /* Variable: K1
                                        * Referenced by:
                                        *   '<S2>/Constant1'
                                        *   '<S26>/Kp '
                                        */
  real_T K2[9];                        /* Variable: K2
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T LAW;                          /* Variable: LAW
                                        * Referenced by:
                                        *   '<S41>/TASK'
                                        *   '<S48>/TASK'
                                        */
  real_T T_initialDP;                  /* Variable: T_initialDP
                                        * Referenced by: '<S50>/Constant1'
                                        */
  real_T U_ref;                        /* Variable: U_ref
                                        * Referenced by:
                                        *   '<S39>/Constant'
                                        *   '<S50>/Constant'
                                        */
  real_T eta_dot_ini[3];               /* Variable: eta_dot_ini
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T l1[9];                        /* Variable: l1
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T l2[9];                        /* Variable: l2
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T l3[9];                        /* Variable: l3
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T lim[4];                       /* Variable: lim
                                        * Referenced by: '<Root>/Lim'
                                        */
  real_T lim_2[4];                     /* Variable: lim_2
                                        * Referenced by: '<Root>/Lim2'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T mu;                           /* Variable: mu
                                        * Referenced by:
                                        *   '<S41>/mu '
                                        *   '<S48>/mu '
                                        */
  real_T pd[4];                        /* Variable: pd
                                        * Referenced by: '<S47>/Desired Position'
                                        */
  real_T Ramp_X0;                      /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S81>/Constant1'
                                        */
  real_T Ramp_slope;                   /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S81>/Step'
                                        */
  real_T Ramp_start;                   /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S81>/Constant'
                                        *   '<S81>/Step'
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
                                        * Referenced by: '<S61>/etaHat'
                                        */
  real_T etaHat2_IC;                   /* Expression: 0
                                        * Referenced by: '<S61>/etaHat2'
                                        */
  real_T Stepsize_Value;               /* Expression: 0.01
                                        * Referenced by: '<S6>/Step size'
                                        */
  real_T counter_X0;                   /* Expression: 0
                                        * Referenced by: '<S70>/counter'
                                        */
  real_T Constant_Value;               /* Expression: 100
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
                                        * Referenced by: '<S76>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S76>/White Noise'
                                        */
  real_T WhiteNoise_Seed;              /* Expression: 9024
                                        * Referenced by: '<S76>/White Noise'
                                        */
  real_T WhiteNoise_Mean_h;            /* Expression: 0
                                        * Referenced by: '<S77>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_d;          /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S77>/White Noise'
                                        */
  real_T WhiteNoise_Seed_b;            /* Expression: 123
                                        * Referenced by: '<S77>/White Noise'
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
                                        * Referenced by: '<S75>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_g;          /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S75>/White Noise'
                                        */
  real_T WhiteNoise_Seed_l;            /* Expression: 9025
                                        * Referenced by: '<S75>/White Noise'
                                        */
  real_T X_ship_P1;                    /* Expression: width
                                        * Referenced by: '<S12>/X_ship'
                                        */
  real_T X_ship_P2;                    /* Expression: dtype
                                        * Referenced by: '<S12>/X_ship'
                                        */
  real_T X_ship_P3;                    /* Expression: portnum
                                        * Referenced by: '<S12>/X_ship'
                                        */
  real_T X_ship_P4;                    /* Expression: stime
                                        * Referenced by: '<S12>/X_ship'
                                        */
  real_T X_ship_P5;                    /* Expression: stype
                                        * Referenced by: '<S12>/X_ship'
                                        */
  real_T X_ship_P6;                    /* Expression: btype
                                        * Referenced by: '<S12>/X_ship'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/1000
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Y_ship_P1;                    /* Expression: width
                                        * Referenced by: '<S12>/Y_ship'
                                        */
  real_T Y_ship_P2;                    /* Expression: dtype
                                        * Referenced by: '<S12>/Y_ship'
                                        */
  real_T Y_ship_P3;                    /* Expression: portnum
                                        * Referenced by: '<S12>/Y_ship'
                                        */
  real_T Y_ship_P4;                    /* Expression: stime
                                        * Referenced by: '<S12>/Y_ship'
                                        */
  real_T Y_ship_P5;                    /* Expression: stype
                                        * Referenced by: '<S12>/Y_ship'
                                        */
  real_T Y_ship_P6;                    /* Expression: btype
                                        * Referenced by: '<S12>/Y_ship'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T PSI_ship_P1;                  /* Expression: width
                                        * Referenced by: '<S12>/PSI_ship'
                                        */
  real_T PSI_ship_P2;                  /* Expression: dtype
                                        * Referenced by: '<S12>/PSI_ship'
                                        */
  real_T PSI_ship_P3;                  /* Expression: portnum
                                        * Referenced by: '<S12>/PSI_ship'
                                        */
  real_T PSI_ship_P4;                  /* Expression: stime
                                        * Referenced by: '<S12>/PSI_ship'
                                        */
  real_T PSI_ship_P5;                  /* Expression: stype
                                        * Referenced by: '<S12>/PSI_ship'
                                        */
  real_T PSI_ship_P6;                  /* Expression: btype
                                        * Referenced by: '<S12>/PSI_ship'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S8>/Memory'
                                        */
  real_T Hold_X0;                      /* Expression: 0
                                        * Referenced by: '<S71>/Hold'
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
  real_T res_ship_P1;                  /* Expression: width
                                        * Referenced by: '<S12>/res_ship'
                                        */
  real_T res_ship_P2;                  /* Expression: dtype
                                        * Referenced by: '<S12>/res_ship'
                                        */
  real_T res_ship_P3;                  /* Expression: portnum
                                        * Referenced by: '<S12>/res_ship'
                                        */
  real_T res_ship_P4;                  /* Expression: stime
                                        * Referenced by: '<S12>/res_ship'
                                        */
  real_T res_ship_P5;                  /* Expression: stype
                                        * Referenced by: '<S12>/res_ship'
                                        */
  real_T res_ship_P6;                  /* Expression: btype
                                        * Referenced by: '<S12>/res_ship'
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
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Memory_X0_n;                  /* Expression: 0
                                        * Referenced by: '<S37>/Memory'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S41>/Integrator'
                                        */
  real_T IC_Value;                     /* Expression: 0
                                        * Referenced by: '<S37>/IC'
                                        */
  real_T Memory_X0_l;                  /* Expression: 0
                                        * Referenced by: '<S38>/Memory'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S48>/Integrator'
                                        */
  real_T Memory2_X0;                   /* Expression: 1
                                        * Referenced by: '<S50>/Memory2'
                                        */
  real_T Memory1_X0[2];                /* Expression: [0,0]
                                        * Referenced by: '<S50>/Memory1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S20>/Switch'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S49>/Constant2'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S20>/Switch3'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T IC_Value_e;                   /* Expression: 0
                                        * Referenced by: '<S38>/IC'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<S20>/Switch4'
                                        */
  real_T nuHat_IC[3];                  /* Expression: [0;0;0]
                                        * Referenced by: '<S59>/nuHat'
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
                                        * Referenced by: '<S20>/Switch5'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S47>/Constant1'
                                        */
  real_T Constant2_Value_f;            /* Expression: 0
                                        * Referenced by: '<S47>/Constant2'
                                        */
  real_T Switch6_Threshold;            /* Expression: 0
                                        * Referenced by: '<S20>/Switch6'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S47>/Constant3'
                                        */
  real_T Switch7_Threshold;            /* Expression: 0
                                        * Referenced by: '<S20>/Switch7'
                                        */
  real_T Constant1_Value_d;            /* Expression: 1
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Constant_Value_d[3];          /* Expression: [0;0;0]
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S22>/Switch2'
                                        */
  real_T L2_continuous_P1;             /* Expression: width
                                        * Referenced by: '<S14>/L2_continuous'
                                        */
  real_T L2_continuous_P2;             /* Expression: dtype
                                        * Referenced by: '<S14>/L2_continuous'
                                        */
  real_T L2_continuous_P3;             /* Expression: portnum
                                        * Referenced by: '<S14>/L2_continuous'
                                        */
  real_T L2_continuous_P4;             /* Expression: stime
                                        * Referenced by: '<S14>/L2_continuous'
                                        */
  real_T L2_continuous_P5;             /* Expression: stype
                                        * Referenced by: '<S14>/L2_continuous'
                                        */
  real_T L2_continuous_P6;             /* Expression: btype
                                        * Referenced by: '<S14>/L2_continuous'
                                        */
  real_T CurrentModeSelector_P1;       /* Expression: width
                                        * Referenced by: '<S14>/CurrentModeSelector'
                                        */
  real_T CurrentModeSelector_P2;       /* Expression: dtype
                                        * Referenced by: '<S14>/CurrentModeSelector'
                                        */
  real_T CurrentModeSelector_P3;       /* Expression: portnum
                                        * Referenced by: '<S14>/CurrentModeSelector'
                                        */
  real_T CurrentModeSelector_P4;       /* Expression: stime
                                        * Referenced by: '<S14>/CurrentModeSelector'
                                        */
  real_T CurrentModeSelector_P5;       /* Expression: stype
                                        * Referenced by: '<S14>/CurrentModeSelector'
                                        */
  real_T CurrentModeSelector_P6;       /* Expression: btype
                                        * Referenced by: '<S14>/CurrentModeSelector'
                                        */
  real_T CurrentMode_P1;               /* Expression: width
                                        * Referenced by: '<S14>/Current Mode '
                                        */
  real_T CurrentMode_P2;               /* Expression: dtype
                                        * Referenced by: '<S14>/Current Mode '
                                        */
  real_T CurrentMode_P3;               /* Expression: portnum
                                        * Referenced by: '<S14>/Current Mode '
                                        */
  real_T CurrentMode_P4;               /* Expression: stime
                                        * Referenced by: '<S14>/Current Mode '
                                        */
  real_T CurrentMode_P5;               /* Expression: stype
                                        * Referenced by: '<S14>/Current Mode '
                                        */
  real_T CurrentMode_P6;               /* Expression: btype
                                        * Referenced by: '<S14>/Current Mode '
                                        */
  real_T PosXRight_P1;                 /* Expression: width
                                        * Referenced by: '<S14>/PosXRight'
                                        */
  real_T PosXRight_P2;                 /* Expression: dtype
                                        * Referenced by: '<S14>/PosXRight'
                                        */
  real_T PosXRight_P3;                 /* Expression: portnum
                                        * Referenced by: '<S14>/PosXRight'
                                        */
  real_T PosXRight_P4;                 /* Expression: stime
                                        * Referenced by: '<S14>/PosXRight'
                                        */
  real_T PosXRight_P5;                 /* Expression: stype
                                        * Referenced by: '<S14>/PosXRight'
                                        */
  real_T PosXRight_P6;                 /* Expression: btype
                                        * Referenced by: '<S14>/PosXRight'
                                        */
  real_T Max_Global_Forces_Value[4];   /* Expression:  [2*1.165 4*(1.165*0.8) 4*(1.165*0.8)*0.4575 2.629]
                                        * Referenced by: '<S14>/Max_Global_Forces'
                                        */
  real_T DeadZone_Start;               /* Expression: -0.05
                                        * Referenced by: '<S14>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 0.05
                                        * Referenced by: '<S14>/Dead Zone'
                                        */
  real_T PosYRight_P1;                 /* Expression: width
                                        * Referenced by: '<S14>/PosYRight'
                                        */
  real_T PosYRight_P2;                 /* Expression: dtype
                                        * Referenced by: '<S14>/PosYRight'
                                        */
  real_T PosYRight_P3;                 /* Expression: portnum
                                        * Referenced by: '<S14>/PosYRight'
                                        */
  real_T PosYRight_P4;                 /* Expression: stime
                                        * Referenced by: '<S14>/PosYRight'
                                        */
  real_T PosYRight_P5;                 /* Expression: stype
                                        * Referenced by: '<S14>/PosYRight'
                                        */
  real_T PosYRight_P6;                 /* Expression: btype
                                        * Referenced by: '<S14>/PosYRight'
                                        */
  real_T DeadZone1_Start;              /* Expression: -0.05
                                        * Referenced by: '<S14>/Dead Zone1'
                                        */
  real_T DeadZone1_End;                /* Expression: 0.05
                                        * Referenced by: '<S14>/Dead Zone1'
                                        */
  real_T R2_continuous_P1;             /* Expression: width
                                        * Referenced by: '<S14>/R2_continuous'
                                        */
  real_T R2_continuous_P2;             /* Expression: dtype
                                        * Referenced by: '<S14>/R2_continuous'
                                        */
  real_T R2_continuous_P3;             /* Expression: portnum
                                        * Referenced by: '<S14>/R2_continuous'
                                        */
  real_T R2_continuous_P4;             /* Expression: stime
                                        * Referenced by: '<S14>/R2_continuous'
                                        */
  real_T R2_continuous_P5;             /* Expression: stype
                                        * Referenced by: '<S14>/R2_continuous'
                                        */
  real_T R2_continuous_P6;             /* Expression: btype
                                        * Referenced by: '<S14>/R2_continuous'
                                        */
  real_T Gain_Gain_ps;                 /* Expression: 0.5
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T DeadZone2_Start;              /* Expression: -0.05
                                        * Referenced by: '<S14>/Dead Zone2'
                                        */
  real_T DeadZone2_End;                /* Expression: 0.05
                                        * Referenced by: '<S14>/Dead Zone2'
                                        */
  real_T tau_yaw_P1;                   /* Expression: width
                                        * Referenced by: '<S14>/tau_yaw'
                                        */
  real_T tau_yaw_P2;                   /* Expression: dtype
                                        * Referenced by: '<S14>/tau_yaw'
                                        */
  real_T tau_yaw_P3;                   /* Expression: portnum
                                        * Referenced by: '<S14>/tau_yaw'
                                        */
  real_T tau_yaw_P4;                   /* Expression: stime
                                        * Referenced by: '<S14>/tau_yaw'
                                        */
  real_T tau_yaw_P5;                   /* Expression: stype
                                        * Referenced by: '<S14>/tau_yaw'
                                        */
  real_T tau_yaw_P6;                   /* Expression: btype
                                        * Referenced by: '<S14>/tau_yaw'
                                        */
  real_T tau_x_P1;                     /* Expression: width
                                        * Referenced by: '<S14>/tau_x'
                                        */
  real_T tau_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S14>/tau_x'
                                        */
  real_T tau_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S14>/tau_x'
                                        */
  real_T tau_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S14>/tau_x'
                                        */
  real_T tau_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S14>/tau_x'
                                        */
  real_T tau_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S14>/tau_x'
                                        */
  real_T tau_y_P1;                     /* Expression: width
                                        * Referenced by: '<S14>/tau_y'
                                        */
  real_T tau_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S14>/tau_y'
                                        */
  real_T tau_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S14>/tau_y'
                                        */
  real_T tau_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S14>/tau_y'
                                        */
  real_T tau_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S14>/tau_y'
                                        */
  real_T tau_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S14>/tau_y'
                                        */
  real_T PosXLeft_P1;                  /* Expression: width
                                        * Referenced by: '<S14>/PosXLeft'
                                        */
  real_T PosXLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<S14>/PosXLeft'
                                        */
  real_T PosXLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<S14>/PosXLeft'
                                        */
  real_T PosXLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<S14>/PosXLeft'
                                        */
  real_T PosXLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<S14>/PosXLeft'
                                        */
  real_T PosXLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<S14>/PosXLeft'
                                        */
  real_T PosYLeft_P1;                  /* Expression: width
                                        * Referenced by: '<S14>/PosYLeft'
                                        */
  real_T PosYLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<S14>/PosYLeft'
                                        */
  real_T PosYLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<S14>/PosYLeft'
                                        */
  real_T PosYLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<S14>/PosYLeft'
                                        */
  real_T PosYLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<S14>/PosYLeft'
                                        */
  real_T PosYLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<S14>/PosYLeft'
                                        */
  real_T L1_P1;                        /* Expression: width
                                        * Referenced by: '<S14>/L1'
                                        */
  real_T L1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S14>/L1'
                                        */
  real_T L1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S14>/L1'
                                        */
  real_T L1_P4;                        /* Expression: stime
                                        * Referenced by: '<S14>/L1'
                                        */
  real_T L1_P5;                        /* Expression: stype
                                        * Referenced by: '<S14>/L1'
                                        */
  real_T L1_P6;                        /* Expression: btype
                                        * Referenced by: '<S14>/L1'
                                        */
  real_T R1_P1;                        /* Expression: width
                                        * Referenced by: '<S14>/R1'
                                        */
  real_T R1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S14>/R1'
                                        */
  real_T R1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S14>/R1'
                                        */
  real_T R1_P4;                        /* Expression: stime
                                        * Referenced by: '<S14>/R1'
                                        */
  real_T R1_P5;                        /* Expression: stype
                                        * Referenced by: '<S14>/R1'
                                        */
  real_T R1_P6;                        /* Expression: btype
                                        * Referenced by: '<S14>/R1'
                                        */
  real_T ArrowDown_P1;                 /* Expression: width
                                        * Referenced by: '<S14>/ArrowDown'
                                        */
  real_T ArrowDown_P2;                 /* Expression: dtype
                                        * Referenced by: '<S14>/ArrowDown'
                                        */
  real_T ArrowDown_P3;                 /* Expression: portnum
                                        * Referenced by: '<S14>/ArrowDown'
                                        */
  real_T ArrowDown_P4;                 /* Expression: stime
                                        * Referenced by: '<S14>/ArrowDown'
                                        */
  real_T ArrowDown_P5;                 /* Expression: stype
                                        * Referenced by: '<S14>/ArrowDown'
                                        */
  real_T ArrowDown_P6;                 /* Expression: btype
                                        * Referenced by: '<S14>/ArrowDown'
                                        */
  real_T ArrowUp_P1;                   /* Expression: width
                                        * Referenced by: '<S14>/ArrowUp'
                                        */
  real_T ArrowUp_P2;                   /* Expression: dtype
                                        * Referenced by: '<S14>/ArrowUp'
                                        */
  real_T ArrowUp_P3;                   /* Expression: portnum
                                        * Referenced by: '<S14>/ArrowUp'
                                        */
  real_T ArrowUp_P4;                   /* Expression: stime
                                        * Referenced by: '<S14>/ArrowUp'
                                        */
  real_T ArrowUp_P5;                   /* Expression: stype
                                        * Referenced by: '<S14>/ArrowUp'
                                        */
  real_T ArrowUp_P6;                   /* Expression: btype
                                        * Referenced by: '<S14>/ArrowUp'
                                        */
  real_T ArrowLeft_P1;                 /* Expression: width
                                        * Referenced by: '<S14>/ArrowLeft'
                                        */
  real_T ArrowLeft_P2;                 /* Expression: dtype
                                        * Referenced by: '<S14>/ArrowLeft'
                                        */
  real_T ArrowLeft_P3;                 /* Expression: portnum
                                        * Referenced by: '<S14>/ArrowLeft'
                                        */
  real_T ArrowLeft_P4;                 /* Expression: stime
                                        * Referenced by: '<S14>/ArrowLeft'
                                        */
  real_T ArrowLeft_P5;                 /* Expression: stype
                                        * Referenced by: '<S14>/ArrowLeft'
                                        */
  real_T ArrowLeft_P6;                 /* Expression: btype
                                        * Referenced by: '<S14>/ArrowLeft'
                                        */
  real_T ArrowRight_P1;                /* Expression: width
                                        * Referenced by: '<S14>/ArrowRight'
                                        */
  real_T ArrowRight_P2;                /* Expression: dtype
                                        * Referenced by: '<S14>/ArrowRight'
                                        */
  real_T ArrowRight_P3;                /* Expression: portnum
                                        * Referenced by: '<S14>/ArrowRight'
                                        */
  real_T ArrowRight_P4;                /* Expression: stime
                                        * Referenced by: '<S14>/ArrowRight'
                                        */
  real_T ArrowRight_P5;                /* Expression: stype
                                        * Referenced by: '<S14>/ArrowRight'
                                        */
  real_T ArrowRight_P6;                /* Expression: btype
                                        * Referenced by: '<S14>/ArrowRight'
                                        */
  real_T Select_P1;                    /* Expression: width
                                        * Referenced by: '<S14>/Select'
                                        */
  real_T Select_P2;                    /* Expression: dtype
                                        * Referenced by: '<S14>/Select'
                                        */
  real_T Select_P3;                    /* Expression: portnum
                                        * Referenced by: '<S14>/Select'
                                        */
  real_T Select_P4;                    /* Expression: stime
                                        * Referenced by: '<S14>/Select'
                                        */
  real_T Select_P5;                    /* Expression: stype
                                        * Referenced by: '<S14>/Select'
                                        */
  real_T Select_P6;                    /* Expression: btype
                                        * Referenced by: '<S14>/Select'
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
  real_T Constant1_Value_i;            /* Expression: 3
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Actuator_Sat_Forces_Value[2]; /* Expression:  [1.165*2 2.629]
                                        * Referenced by: '<S10>/Actuator_Sat_Forces'
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
  real_T Memory_X0_n2[3];              /* Expression: [0;0;0]
                                        * Referenced by: '<S11>/Memory'
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
  real_T bHat_IC;                      /* Expression: 0
                                        * Referenced by: '<S57>/bHat'
                                        */
  real_T Constant_Value_e[3];          /* Expression: [1;1;1]
                                        * Referenced by: '<S57>/Constant'
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
  real_T IC1_Value[3];                 /* Expression: [0;0;0]
                                        * Referenced by: '<S57>/IC1'
                                        */
  real_T Bias_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/Bias'
                                        */
  real_T Bias_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/Bias'
                                        */
  real_T Bias_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/Bias'
                                        */
  real_T Bias_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/Bias'
                                        */
  real_T Bias_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/Bias'
                                        */
  real_T Bias_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/Bias'
                                        */
  real_T Switch1_Threshold_m;          /* Expression: 0
                                        * Referenced by: '<S20>/Switch1'
                                        */
  real_T S_P1;                         /* Expression: width
                                        * Referenced by: '<Root>/S'
                                        */
  real_T S_P2;                         /* Expression: dtype
                                        * Referenced by: '<Root>/S'
                                        */
  real_T S_P3;                         /* Expression: portnum
                                        * Referenced by: '<Root>/S'
                                        */
  real_T S_P4;                         /* Expression: stime
                                        * Referenced by: '<Root>/S'
                                        */
  real_T S_P5;                         /* Expression: stype
                                        * Referenced by: '<Root>/S'
                                        */
  real_T S_P6;                         /* Expression: btype
                                        * Referenced by: '<Root>/S'
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
  real_T nu_hat_P1;                    /* Expression: width
                                        * Referenced by: '<Root>/nu_hat '
                                        */
  real_T nu_hat_P2;                    /* Expression: dtype
                                        * Referenced by: '<Root>/nu_hat '
                                        */
  real_T nu_hat_P3;                    /* Expression: portnum
                                        * Referenced by: '<Root>/nu_hat '
                                        */
  real_T nu_hat_P4;                    /* Expression: stime
                                        * Referenced by: '<Root>/nu_hat '
                                        */
  real_T nu_hat_P5;                    /* Expression: stype
                                        * Referenced by: '<Root>/nu_hat '
                                        */
  real_T nu_hat_P6;                    /* Expression: btype
                                        * Referenced by: '<Root>/nu_hat '
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
  real_T Delay_InitialCondition[3];    /* Expression: [0,0,0]'
                                        * Referenced by: '<S59>/Delay'
                                        */
  real_T delay2_P1;                    /* Expression: width
                                        * Referenced by: '<Root>/delay2'
                                        */
  real_T delay2_P2;                    /* Expression: dtype
                                        * Referenced by: '<Root>/delay2'
                                        */
  real_T delay2_P3;                    /* Expression: portnum
                                        * Referenced by: '<Root>/delay2'
                                        */
  real_T delay2_P4;                    /* Expression: stime
                                        * Referenced by: '<Root>/delay2'
                                        */
  real_T delay2_P5;                    /* Expression: stype
                                        * Referenced by: '<Root>/delay2'
                                        */
  real_T delay2_P6;                    /* Expression: btype
                                        * Referenced by: '<Root>/delay2'
                                        */
  real_T Integrator_IC_g;              /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Switch3_Threshold_a;          /* Expression: 0
                                        * Referenced by: '<Root>/Switch3'
                                        */
  real_T delay1_P1;                    /* Expression: width
                                        * Referenced by: '<Root>/delay1'
                                        */
  real_T delay1_P2;                    /* Expression: dtype
                                        * Referenced by: '<Root>/delay1'
                                        */
  real_T delay1_P3;                    /* Expression: portnum
                                        * Referenced by: '<Root>/delay1'
                                        */
  real_T delay1_P4;                    /* Expression: stime
                                        * Referenced by: '<Root>/delay1'
                                        */
  real_T delay1_P5;                    /* Expression: stype
                                        * Referenced by: '<Root>/delay1'
                                        */
  real_T delay1_P6;                    /* Expression: btype
                                        * Referenced by: '<Root>/delay1'
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
  real_T X_d_P1;                       /* Expression: width
                                        * Referenced by: '<S17>/X_d'
                                        */
  real_T X_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S17>/X_d'
                                        */
  real_T X_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S17>/X_d'
                                        */
  real_T X_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S17>/X_d'
                                        */
  real_T X_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S17>/X_d'
                                        */
  real_T X_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S17>/X_d'
                                        */
  real_T N_d_P1;                       /* Expression: width
                                        * Referenced by: '<S17>/N_d'
                                        */
  real_T N_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S17>/N_d'
                                        */
  real_T N_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S17>/N_d'
                                        */
  real_T N_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S17>/N_d'
                                        */
  real_T N_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S17>/N_d'
                                        */
  real_T N_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S17>/N_d'
                                        */
  real_T Y_d_P1;                       /* Expression: width
                                        * Referenced by: '<S17>/Y_d'
                                        */
  real_T Y_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S17>/Y_d'
                                        */
  real_T Y_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S17>/Y_d'
                                        */
  real_T Y_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S17>/Y_d'
                                        */
  real_T Y_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S17>/Y_d'
                                        */
  real_T Y_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S17>/Y_d'
                                        */
  real_T psi_0_P1;                     /* Expression: width
                                        * Referenced by: '<S17>/psi_0 '
                                        */
  real_T psi_0_P2;                     /* Expression: dtype
                                        * Referenced by: '<S17>/psi_0 '
                                        */
  real_T psi_0_P3;                     /* Expression: portnum
                                        * Referenced by: '<S17>/psi_0 '
                                        */
  real_T psi_0_P4;                     /* Expression: stime
                                        * Referenced by: '<S17>/psi_0 '
                                        */
  real_T psi_0_P5;                     /* Expression: stype
                                        * Referenced by: '<S17>/psi_0 '
                                        */
  real_T psi_0_P6;                     /* Expression: btype
                                        * Referenced by: '<S17>/psi_0 '
                                        */
  real_T x_0_P1;                       /* Expression: width
                                        * Referenced by: '<S17>/x_0'
                                        */
  real_T x_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<S17>/x_0'
                                        */
  real_T x_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<S17>/x_0'
                                        */
  real_T x_0_P4;                       /* Expression: stime
                                        * Referenced by: '<S17>/x_0'
                                        */
  real_T x_0_P5;                       /* Expression: stype
                                        * Referenced by: '<S17>/x_0'
                                        */
  real_T x_0_P6;                       /* Expression: btype
                                        * Referenced by: '<S17>/x_0'
                                        */
  real_T y_0_P1;                       /* Expression: width
                                        * Referenced by: '<S17>/y_0'
                                        */
  real_T y_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<S17>/y_0'
                                        */
  real_T y_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<S17>/y_0'
                                        */
  real_T y_0_P4;                       /* Expression: stime
                                        * Referenced by: '<S17>/y_0'
                                        */
  real_T y_0_P5;                       /* Expression: stype
                                        * Referenced by: '<S17>/y_0'
                                        */
  real_T y_0_P6;                       /* Expression: btype
                                        * Referenced by: '<S17>/y_0'
                                        */
  real_T integratorresetmodel_P1;      /* Expression: width
                                        * Referenced by: '<S17>/integrator reset model'
                                        */
  real_T integratorresetmodel_P2;      /* Expression: dtype
                                        * Referenced by: '<S17>/integrator reset model'
                                        */
  real_T integratorresetmodel_P3;      /* Expression: portnum
                                        * Referenced by: '<S17>/integrator reset model'
                                        */
  real_T integratorresetmodel_P4;      /* Expression: stime
                                        * Referenced by: '<S17>/integrator reset model'
                                        */
  real_T integratorresetmodel_P5;      /* Expression: stype
                                        * Referenced by: '<S17>/integrator reset model'
                                        */
  real_T integratorresetmodel_P6;      /* Expression: btype
                                        * Referenced by: '<S17>/integrator reset model'
                                        */
  real_T TurnOffomega1_P1;             /* Expression: width
                                        * Referenced by: '<S18>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P2;             /* Expression: dtype
                                        * Referenced by: '<S18>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P3;             /* Expression: portnum
                                        * Referenced by: '<S18>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P4;             /* Expression: stime
                                        * Referenced by: '<S18>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P5;             /* Expression: stype
                                        * Referenced by: '<S18>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P6;             /* Expression: btype
                                        * Referenced by: '<S18>/TurnOffomega1'
                                        */
  real_T TurnOffomega2_P1;             /* Expression: width
                                        * Referenced by: '<S18>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P2;             /* Expression: dtype
                                        * Referenced by: '<S18>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P3;             /* Expression: portnum
                                        * Referenced by: '<S18>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P4;             /* Expression: stime
                                        * Referenced by: '<S18>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P5;             /* Expression: stype
                                        * Referenced by: '<S18>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P6;             /* Expression: btype
                                        * Referenced by: '<S18>/TurnOffomega2'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T controlinputuexceedsbounds_P1;/* Expression: width
                                        * Referenced by: '<S98>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P2;/* Expression: dtype
                                        * Referenced by: '<S98>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P3;/* Expression: portnum
                                        * Referenced by: '<S98>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P4;/* Expression: stime
                                        * Referenced by: '<S98>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P5;/* Expression: stype
                                        * Referenced by: '<S98>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P6;/* Expression: btype
                                        * Referenced by: '<S98>/control input u exceeds bounds'
                                        */
  real_T alpha_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S100>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S100>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S100>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S100>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S100>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S100>/alpha_VSP1'
                                        */
  real_T alpha_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S100>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S100>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S100>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S100>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S100>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S100>/alpha_VSP2'
                                        */
  real_T omega_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S100>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S100>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S100>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S100>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S100>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S100>/omega_VSP1'
                                        */
  real_T omega_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S100>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S100>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S100>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S100>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S100>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S100>/omega_VSP2'
                                        */
  real_T u_BT_P1;                      /* Expression: width
                                        * Referenced by: '<S100>/u_BT'
                                        */
  real_T u_BT_P2;                      /* Expression: dtype
                                        * Referenced by: '<S100>/u_BT'
                                        */
  real_T u_BT_P3;                      /* Expression: portnum
                                        * Referenced by: '<S100>/u_BT'
                                        */
  real_T u_BT_P4;                      /* Expression: stime
                                        * Referenced by: '<S100>/u_BT'
                                        */
  real_T u_BT_P5;                      /* Expression: stype
                                        * Referenced by: '<S100>/u_BT'
                                        */
  real_T u_BT_P6;                      /* Expression: btype
                                        * Referenced by: '<S100>/u_BT'
                                        */
  real_T u_VSP1_P1;                    /* Expression: width
                                        * Referenced by: '<S100>/u_VSP1'
                                        */
  real_T u_VSP1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S100>/u_VSP1'
                                        */
  real_T u_VSP1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S100>/u_VSP1'
                                        */
  real_T u_VSP1_P4;                    /* Expression: stime
                                        * Referenced by: '<S100>/u_VSP1'
                                        */
  real_T u_VSP1_P5;                    /* Expression: stype
                                        * Referenced by: '<S100>/u_VSP1'
                                        */
  real_T u_VSP1_P6;                    /* Expression: btype
                                        * Referenced by: '<S100>/u_VSP1'
                                        */
  real_T u_VSP2_P1;                    /* Expression: width
                                        * Referenced by: '<S100>/u_VSP2'
                                        */
  real_T u_VSP2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S100>/u_VSP2'
                                        */
  real_T u_VSP2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S100>/u_VSP2'
                                        */
  real_T u_VSP2_P4;                    /* Expression: stime
                                        * Referenced by: '<S100>/u_VSP2'
                                        */
  real_T u_VSP2_P5;                    /* Expression: stype
                                        * Referenced by: '<S100>/u_VSP2'
                                        */
  real_T u_VSP2_P6;                    /* Expression: btype
                                        * Referenced by: '<S100>/u_VSP2'
                                        */
  real_T Actuator_Sat_Forces_Value_n[2];/* Expression:  [1.165*2 2.629]
                                         * Referenced by: '<S18>/Actuator_Sat_Forces'
                                         */
  real_T Gain_Gain_j;                  /* Expression: -1
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: -1
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real_T Memory_X0_j;                  /* Expression: 1
                                        * Referenced by: '<S50>/Memory'
                                        */
  real_T Constant1_Value_f;            /* Expression: 2*pi
                                        * Referenced by: '<S67>/Constant1'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S67>/Constant'
                                        */
  real_T Switch3_Threshold_d;          /* Expression: 0
                                        * Referenced by: '<S67>/Switch3'
                                        */
  real_T IC_Value_f[3];                /* Expression: [0;0;0]
                                        * Referenced by: '<S59>/IC'
                                        */
  real_T Memory_X0_p;                  /* Expression: [0]
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T eta_real_P1;                  /* Expression: width
                                        * Referenced by: '<S8>/eta_real'
                                        */
  real_T eta_real_P2;                  /* Expression: dtype
                                        * Referenced by: '<S8>/eta_real'
                                        */
  real_T eta_real_P3;                  /* Expression: portnum
                                        * Referenced by: '<S8>/eta_real'
                                        */
  real_T eta_real_P4;                  /* Expression: stime
                                        * Referenced by: '<S8>/eta_real'
                                        */
  real_T eta_real_P5;                  /* Expression: stype
                                        * Referenced by: '<S8>/eta_real'
                                        */
  real_T eta_real_P6;                  /* Expression: btype
                                        * Referenced by: '<S8>/eta_real'
                                        */
  real_T Constant2_Value_o;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T u_BT_P1_f;                    /* Expression: width
                                        * Referenced by: '<S10>/u_BT'
                                        */
  real_T u_BT_P2_m;                    /* Expression: dtype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  real_T u_BT_P3_n;                    /* Expression: portnum
                                        * Referenced by: '<S10>/u_BT'
                                        */
  real_T u_BT_P4_a;                    /* Expression: stime
                                        * Referenced by: '<S10>/u_BT'
                                        */
  real_T u_BT_P5_d;                    /* Expression: stype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  real_T u_BT_P6_n;                    /* Expression: btype
                                        * Referenced by: '<S10>/u_BT'
                                        */
  real_T TurnOffomega1_P1_o;           /* Expression: width
                                        * Referenced by: '<S10>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P2_g;           /* Expression: dtype
                                        * Referenced by: '<S10>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P3_i;           /* Expression: portnum
                                        * Referenced by: '<S10>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P4_c;           /* Expression: stime
                                        * Referenced by: '<S10>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P5_c;           /* Expression: stype
                                        * Referenced by: '<S10>/TurnOffomega1'
                                        */
  real_T TurnOffomega1_P6_o;           /* Expression: btype
                                        * Referenced by: '<S10>/TurnOffomega1'
                                        */
  real_T TurnOffomega2_P1_o;           /* Expression: width
                                        * Referenced by: '<S10>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P2_p;           /* Expression: dtype
                                        * Referenced by: '<S10>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P3_g;           /* Expression: portnum
                                        * Referenced by: '<S10>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P4_e;           /* Expression: stime
                                        * Referenced by: '<S10>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P5_f;           /* Expression: stype
                                        * Referenced by: '<S10>/TurnOffomega2'
                                        */
  real_T TurnOffomega2_P6_l;           /* Expression: btype
                                        * Referenced by: '<S10>/TurnOffomega2'
                                        */
  real_T u_VSP1_P1_m;                  /* Expression: width
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  real_T u_VSP1_P2_o;                  /* Expression: dtype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  real_T u_VSP1_P3_i;                  /* Expression: portnum
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  real_T u_VSP1_P4_h;                  /* Expression: stime
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  real_T u_VSP1_P5_n;                  /* Expression: stype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  real_T u_VSP1_P6_a;                  /* Expression: btype
                                        * Referenced by: '<S10>/u_VSP1'
                                        */
  real_T u_VSP2_P1_h;                  /* Expression: width
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  real_T u_VSP2_P2_l;                  /* Expression: dtype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  real_T u_VSP2_P3_d;                  /* Expression: portnum
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  real_T u_VSP2_P4_l;                  /* Expression: stime
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  real_T u_VSP2_P5_c;                  /* Expression: stype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  real_T u_VSP2_P6_o;                  /* Expression: btype
                                        * Referenced by: '<S10>/u_VSP2'
                                        */
  real_T alpha_VSP1_P1_a;              /* Expression: width
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2_g;              /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3_f;              /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4_o;              /* Expression: stime
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5_o;              /* Expression: stype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6_c;              /* Expression: btype
                                        * Referenced by: '<S10>/alpha_VSP1'
                                        */
  real_T alpha_VSP2_P1_l;              /* Expression: width
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2_h;              /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3_n;              /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4_f;              /* Expression: stime
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5_p;              /* Expression: stype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6_m;              /* Expression: btype
                                        * Referenced by: '<S10>/alpha_VSP2'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S81>/Step'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.3
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<S10>/Switch'
                                        */
  real_T omega_VSP1_P1_b;              /* Expression: width
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2_a;              /* Expression: dtype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3_d;              /* Expression: portnum
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4_f;              /* Expression: stime
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5_f;              /* Expression: stype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6_o;              /* Expression: btype
                                        * Referenced by: '<S10>/omega_VSP1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Switch1_Threshold_o;          /* Expression: 0
                                        * Referenced by: '<S10>/Switch1'
                                        */
  real_T omega_VSP2_P1_h;              /* Expression: width
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2_n;              /* Expression: dtype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3_j;              /* Expression: portnum
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4_c;              /* Expression: stime
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5_c;              /* Expression: stype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6_k;              /* Expression: btype
                                        * Referenced by: '<S10>/omega_VSP2'
                                        */
  real_T Constant3_Value_i;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T f_bt_P1;                      /* Expression: width
                                        * Referenced by: '<S10>/f_bt'
                                        */
  real_T f_bt_P2;                      /* Expression: dtype
                                        * Referenced by: '<S10>/f_bt'
                                        */
  real_T f_bt_P3;                      /* Expression: portnum
                                        * Referenced by: '<S10>/f_bt'
                                        */
  real_T f_bt_P4;                      /* Expression: stime
                                        * Referenced by: '<S10>/f_bt'
                                        */
  real_T f_bt_P5;                      /* Expression: stype
                                        * Referenced by: '<S10>/f_bt'
                                        */
  real_T f_bt_P6;                      /* Expression: btype
                                        * Referenced by: '<S10>/f_bt'
                                        */
  real_T f_vspx_P1;                    /* Expression: width
                                        * Referenced by: '<S10>/f_vspx'
                                        */
  real_T f_vspx_P2;                    /* Expression: dtype
                                        * Referenced by: '<S10>/f_vspx'
                                        */
  real_T f_vspx_P3;                    /* Expression: portnum
                                        * Referenced by: '<S10>/f_vspx'
                                        */
  real_T f_vspx_P4;                    /* Expression: stime
                                        * Referenced by: '<S10>/f_vspx'
                                        */
  real_T f_vspx_P5;                    /* Expression: stype
                                        * Referenced by: '<S10>/f_vspx'
                                        */
  real_T f_vspx_P6;                    /* Expression: btype
                                        * Referenced by: '<S10>/f_vspx'
                                        */
  real_T f_vspy_P1;                    /* Expression: width
                                        * Referenced by: '<S10>/ f_vspy'
                                        */
  real_T f_vspy_P2;                    /* Expression: dtype
                                        * Referenced by: '<S10>/ f_vspy'
                                        */
  real_T f_vspy_P3;                    /* Expression: portnum
                                        * Referenced by: '<S10>/ f_vspy'
                                        */
  real_T f_vspy_P4;                    /* Expression: stime
                                        * Referenced by: '<S10>/ f_vspy'
                                        */
  real_T f_vspy_P5;                    /* Expression: stype
                                        * Referenced by: '<S10>/ f_vspy'
                                        */
  real_T f_vspy_P6;                    /* Expression: btype
                                        * Referenced by: '<S10>/ f_vspy'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S16>/Switch'
                                        */
  real_T Memory_X0_i;                  /* Expression: 0
                                        * Referenced by: '<S16>/Memory'
                                        */
  real_T y_in_P1;                      /* Expression: width
                                        * Referenced by: '<S13>/y_in'
                                        */
  real_T y_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<S13>/y_in'
                                        */
  real_T y_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<S13>/y_in'
                                        */
  real_T y_in_P4;                      /* Expression: stime
                                        * Referenced by: '<S13>/y_in'
                                        */
  real_T y_in_P5;                      /* Expression: stype
                                        * Referenced by: '<S13>/y_in'
                                        */
  real_T y_in_P6;                      /* Expression: btype
                                        * Referenced by: '<S13>/y_in'
                                        */
  real_T psi_in_P1;                    /* Expression: width
                                        * Referenced by: '<S13>/psi_in'
                                        */
  real_T psi_in_P2;                    /* Expression: dtype
                                        * Referenced by: '<S13>/psi_in'
                                        */
  real_T psi_in_P3;                    /* Expression: portnum
                                        * Referenced by: '<S13>/psi_in'
                                        */
  real_T psi_in_P4;                    /* Expression: stime
                                        * Referenced by: '<S13>/psi_in'
                                        */
  real_T psi_in_P5;                    /* Expression: stype
                                        * Referenced by: '<S13>/psi_in'
                                        */
  real_T psi_in_P6;                    /* Expression: btype
                                        * Referenced by: '<S13>/psi_in'
                                        */
  real_T u_in_P1;                      /* Expression: width
                                        * Referenced by: '<S13>/u_in'
                                        */
  real_T u_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<S13>/u_in'
                                        */
  real_T u_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<S13>/u_in'
                                        */
  real_T u_in_P4;                      /* Expression: stime
                                        * Referenced by: '<S13>/u_in'
                                        */
  real_T u_in_P5;                      /* Expression: stype
                                        * Referenced by: '<S13>/u_in'
                                        */
  real_T u_in_P6;                      /* Expression: btype
                                        * Referenced by: '<S13>/u_in'
                                        */
  real_T u_real_P1;                    /* Expression: width
                                        * Referenced by: '<S13>/u_real  '
                                        */
  real_T u_real_P2;                    /* Expression: dtype
                                        * Referenced by: '<S13>/u_real  '
                                        */
  real_T u_real_P3;                    /* Expression: portnum
                                        * Referenced by: '<S13>/u_real  '
                                        */
  real_T u_real_P4;                    /* Expression: stime
                                        * Referenced by: '<S13>/u_real  '
                                        */
  real_T u_real_P5;                    /* Expression: stype
                                        * Referenced by: '<S13>/u_real  '
                                        */
  real_T u_real_P6;                    /* Expression: btype
                                        * Referenced by: '<S13>/u_real  '
                                        */
  real_T x_in_P1;                      /* Expression: width
                                        * Referenced by: '<S13>/x_in'
                                        */
  real_T x_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<S13>/x_in'
                                        */
  real_T x_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<S13>/x_in'
                                        */
  real_T x_in_P4;                      /* Expression: stime
                                        * Referenced by: '<S13>/x_in'
                                        */
  real_T x_in_P5;                      /* Expression: stype
                                        * Referenced by: '<S13>/x_in'
                                        */
  real_T x_in_P6;                      /* Expression: btype
                                        * Referenced by: '<S13>/x_in'
                                        */
  real_T r_in_P1;                      /* Expression: width
                                        * Referenced by: '<S13>/r_in'
                                        */
  real_T r_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<S13>/r_in'
                                        */
  real_T r_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<S13>/r_in'
                                        */
  real_T r_in_P4;                      /* Expression: stime
                                        * Referenced by: '<S13>/r_in'
                                        */
  real_T r_in_P5;                      /* Expression: stype
                                        * Referenced by: '<S13>/r_in'
                                        */
  real_T r_in_P6;                      /* Expression: btype
                                        * Referenced by: '<S13>/r_in'
                                        */
  real_T v_in_P1;                      /* Expression: width
                                        * Referenced by: '<S13>/v_in'
                                        */
  real_T v_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<S13>/v_in'
                                        */
  real_T v_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<S13>/v_in'
                                        */
  real_T v_in_P4;                      /* Expression: stime
                                        * Referenced by: '<S13>/v_in'
                                        */
  real_T v_in_P5;                      /* Expression: stype
                                        * Referenced by: '<S13>/v_in'
                                        */
  real_T v_in_P6;                      /* Expression: btype
                                        * Referenced by: '<S13>/v_in'
                                        */
  real_T NIVeriStandSignalProbe_P1;    /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S59>/Delay'
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
    real_T odeY[20];
    real_T odeF[3][20];
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
 * '<S5>'   : 'ctrl_student_HIL/MATLAB Function1'
 * '<S6>'   : 'ctrl_student_HIL/Noise generator'
 * '<S7>'   : 'ctrl_student_HIL/ObserverGain'
 * '<S8>'   : 'ctrl_student_HIL/Position'
 * '<S9>'   : 'ctrl_student_HIL/Rad2Deg'
 * '<S10>'  : 'ctrl_student_HIL/ThrustAllocationAndSaturation'
 * '<S11>'  : 'ctrl_student_HIL/dropoutdet'
 * '<S12>'  : 'ctrl_student_HIL/from enterprise'
 * '<S13>'  : 'ctrl_student_HIL/from model'
 * '<S14>'  : 'ctrl_student_HIL/joystick'
 * '<S15>'  : 'ctrl_student_HIL/physics_model'
 * '<S16>'  : 'ctrl_student_HIL/safety zone '
 * '<S17>'  : 'ctrl_student_HIL/tau to CSE mocell (only use for HIL testing)'
 * '<S18>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)'
 * '<S19>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1'
 * '<S20>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization'
 * '<S21>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization'
 * '<S22>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Controller'
 * '<S23>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization '
 * '<S24>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s'
 * '<S25>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1'
 * '<S26>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /alpha 1'
 * '<S27>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function'
 * '<S28>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/MATLAB Function1'
 * '<S29>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /V_1s/Rotation Matrix'
 * '<S30>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/R Transposed'
 * '<S31>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Control parameterization/BacksteppingParameterization /Z_1/Rotation Matrix'
 * '<S32>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Controller/Controller'
 * '<S33>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function'
 * '<S34>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Controller/Controller/MATLAB Function1'
 * '<S35>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Controller/Controller/alpha_1dott'
 * '<S36>'  : 'ctrl_student_HIL/ControllerAndParanetrization/Controller1/Controller/Controller/alpha_1dott/MATLAB Function'
 * '<S37>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips'
 * '<S38>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight'
 * '<S39>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Check_s'
 * '<S40>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization '
 * '<S41>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator'
 * '<S42>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Check_s/CheckS&getU'
 * '<S43>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization /Subsystem'
 * '<S44>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/Path parametization /Subsystem/MATLAB Function'
 * '<S45>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/MATLAB Function1'
 * '<S46>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Ellips/parameter generator/UpdateLaw'
 * '<S47>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization '
 * '<S48>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator'
 * '<S49>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Eta_ds'
 * '<S50>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem'
 * '<S51>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Eta_ds/MATLAB Function'
 * '<S52>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Eta_ds/MATLAB Function1'
 * '<S53>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function'
 * '<S54>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/Path parametization /Subsystem/MATLAB Function1'
 * '<S55>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/MATLAB Function1'
 * '<S56>'  : 'ctrl_student_HIL/ControllerAndParanetrization/PathParameterization/PathGenerization_Straight/parameter generator/UpdateLaw'
 * '<S57>'  : 'ctrl_student_HIL/DPObserver1/Bias'
 * '<S58>'  : 'ctrl_student_HIL/DPObserver1/D'
 * '<S59>'  : 'ctrl_student_HIL/DPObserver1/Subsystem'
 * '<S60>'  : 'ctrl_student_HIL/DPObserver1/calcR(psi) '
 * '<S61>'  : 'ctrl_student_HIL/DPObserver1/etaHat'
 * '<S62>'  : 'ctrl_student_HIL/DPObserver1/Bias/bHatDot'
 * '<S63>'  : 'ctrl_student_HIL/DPObserver1/Subsystem/M'
 * '<S64>'  : 'ctrl_student_HIL/DPObserver1/Subsystem/MATLAB Function'
 * '<S65>'  : 'ctrl_student_HIL/DPObserver1/Subsystem/nuHatDot'
 * '<S66>'  : 'ctrl_student_HIL/DPObserver1/etaHat/MATLAB Function'
 * '<S67>'  : 'ctrl_student_HIL/DPObserver1/etaHat/Subsystem'
 * '<S68>'  : 'ctrl_student_HIL/DPObserver1/etaHat/etaHatDot'
 * '<S69>'  : 'ctrl_student_HIL/DPObserver1/etaHat/Subsystem/MATLAB Function1'
 * '<S70>'  : 'ctrl_student_HIL/Noise generator/Downsample	signal'
 * '<S71>'  : 'ctrl_student_HIL/Noise generator/Sample & hold'
 * '<S72>'  : 'ctrl_student_HIL/Noise generator/noise generator'
 * '<S73>'  : 'ctrl_student_HIL/Noise generator/Downsample	signal/MATLAB Function'
 * '<S74>'  : 'ctrl_student_HIL/Noise generator/Sample & hold/MATLAB Function1'
 * '<S75>'  : 'ctrl_student_HIL/Noise generator/noise generator/Band-limited white noise psi'
 * '<S76>'  : 'ctrl_student_HIL/Noise generator/noise generator/Band-limited white noise x'
 * '<S77>'  : 'ctrl_student_HIL/Noise generator/noise generator/Band-limited white noise y'
 * '<S78>'  : 'ctrl_student_HIL/Position/Deg2Rad'
 * '<S79>'  : 'ctrl_student_HIL/ThrustAllocationAndSaturation/Force Allocation1'
 * '<S80>'  : 'ctrl_student_HIL/ThrustAllocationAndSaturation/Force2Control'
 * '<S81>'  : 'ctrl_student_HIL/ThrustAllocationAndSaturation/Ramp'
 * '<S82>'  : 'ctrl_student_HIL/ThrustAllocationAndSaturation/actForces1'
 * '<S83>'  : 'ctrl_student_HIL/dropoutdet/dropOutDetect'
 * '<S84>'  : 'ctrl_student_HIL/joystick/Contoller_Map1'
 * '<S85>'  : 'ctrl_student_HIL/joystick/Sel_Control_Mode'
 * '<S86>'  : 'ctrl_student_HIL/physics_model/kinematics'
 * '<S87>'  : 'ctrl_student_HIL/physics_model/kinetics'
 * '<S88>'  : 'ctrl_student_HIL/safety zone /KillSwitch'
 * '<S89>'  : 'ctrl_student_HIL/safety zone /MATLAB Function'
 * '<S90>'  : 'ctrl_student_HIL/safety zone /MATLAB Function1'
 * '<S91>'  : 'ctrl_student_HIL/safety zone /Safety Act'
 * '<S92>'  : 'ctrl_student_HIL/safety zone /safety check'
 * '<S93>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/Force Allocation1'
 * '<S94>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/Force2Control'
 * '<S95>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/Full thrust allocation'
 * '<S96>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/Limited allocation: VSP only  in surge and BT only in yaw'
 * '<S97>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/Ramp'
 * '<S98>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/To thruster of real ship'
 * '<S99>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/To thruster of real ship/control limit checking'
 * '<S100>' : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/To thruster of real ship/u'
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
