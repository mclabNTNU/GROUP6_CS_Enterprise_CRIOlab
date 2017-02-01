#ifndef NIRT_MODEL_INFO_H
#define NIRT_MODEL_INFO_H
#include "NIVERISTAND_API.h"
#if defined (VXWORKS) || defined (kNIOSLinux)
# define CRITICAL_SECTION              HANDLE

void InitializeCriticalSection(CRITICAL_SECTION *CriticalSection);
HANDLE CreateSemaphore(long lpSemaphoreAttributes, long lInitialCount, long
  lMaximumCount, char* lpName);
void EnterCriticalSection(CRITICAL_SECTION *CriticalSection);
void WaitForSingleObject(HANDLE hHandle, long dwMilliseconds);
void LeaveCriticalSection(CRITICAL_SECTION *CriticalSection);
void ReleaseSemaphore(HANDLE hSemaphore, long lReleaseCount, long
                      lpPreviousCount);
void DeleteCriticalSection(CRITICAL_SECTION *CriticalSection);
void CloseHandle(HANDLE hObject);

#endif

typedef struct {
  HANDLE flipCriticalSection;
  uint_T copyTaskBitfield;

  // inCriticalSection keeps track of how many entries the TCL has into the critical section
  // presumably, it should only have <= 1, and if it ever goes above that, we will error out.
  // the critical section is acquired BEFORE the call to MdlOutputs, inCriticalSection is incremented AFTER.
  // the critical section is released AFTER the call to MdlUpdate, inCriticalSection is decremented BEFORE.
  // this allows us to use the flag to know when it is valid to probe.
  uint_T inCriticalSection;
} _SITexportglobals;

#define BLOCKIO_SIG                    0
#define EXTIO_SIG                      1

// for virtual signals, addr is offset into virtualmap array that contains indices in NI_Signal
// array corresponding to the non-virtual signals that compose the virtual signal.
// currently unused
#define VIRTUAL_SIG                    2
#define EXT_IN                         0
#define EXT_OUT                        1
#if defined(__cplusplus)

extern "C" {

#endif

  // defined in NIVeriStand_main.c
  void SetSITErrorMessage(char *ErrMsg, int Error);

#if defined(__cplusplus)

}
#endif
#endif
