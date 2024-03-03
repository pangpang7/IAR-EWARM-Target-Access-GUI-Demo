/**************************************************************
*
* This file contains the API for the Target Access Client SDK
*
* Note: When monitoring ITM events, ports 0-16 are reserved
*       by IAR Systems which may result in undefined behavior
*       if used by client applications
*
* Copyright 2018 IAR Systems AB
*
**************************************************************/

#pragma once

#include "TargetAccessClientErrorCodes.h"

#include <stdint.h>

typedef int64_t TargetAccessAddr;

#if defined(_WIN32)
  #if !defined(EXTFUN)
    #define EXTFUN __declspec(dllexport)
  #endif
#else
  #define EXTFUN
#endif

#ifdef __cplusplus
extern "C"
{
#endif

  struct ITMEvent
  {
    uint8_t portId;
    uint64_t timeStamp;
    uint32_t dataLength;
    uint8_t data[4];
  };

  struct ITMListenerStatus
  {
    uint8_t listening; // 1 if ITM listening is active, 0 otherwise
    uint32_t channels; // Current bit mask used to filter which ITM events are collected
    uint32_t bufferCapacity; // The maximum size of the event buffer
    uint32_t bufferSize; // The current size of the event buffer
  };

  int EXTFUN TargetAccessInitialize(const char *serverName);
  int EXTFUN TargetAccessInitializeWithPort(const char *serverName, uint16_t port);

  int EXTFUN TargetAccessShutdown();

  int EXTFUN TargetAccessGetClientProtocolVersion();
  int EXTFUN TargetAccessGetServerProtocolVersion();

  int EXTFUN TargetAccessReadTargetMemoryZone(const char *zoneName, TargetAccessAddr address, unsigned char *buffer, uint16_t numBytes);
  int EXTFUN TargetAccessReadTargetMemory(TargetAccessAddr address, unsigned char *buffer, uint16_t numBytes);

  int EXTFUN TargetAccessWriteTargetMemoryZone(const char *zoneName, TargetAccessAddr address, const unsigned char *buffer, uint16_t numBytes);
  int EXTFUN TargetAccessWriteTargetMemory(TargetAccessAddr address, const unsigned char *buffer, uint16_t numBytes);

  int EXTFUN TargetAccessConfigureItmListener(uint32_t channels, uint32_t bufferCapacity);
  int EXTFUN TargetAccessGetItmListenerStatus(ITMListenerStatus *status);
  int EXTFUN TargetAccessStartItmListener();
  int EXTFUN TargetAccessStopItmListener();
  int EXTFUN TargetAccessReadItmEvent(ITMEvent *itmEvent, bool *isValid);

  size_t EXTFUN TargetAccessGetLastErrorMsg(char *errorMsg, size_t bufSize);

#ifdef __cplusplus
}
#endif
