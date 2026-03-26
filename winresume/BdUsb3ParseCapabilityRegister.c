__int64 __fastcall BdUsb3ParseCapabilityRegister(__int64 a1)
{
  unsigned __int8 v2; // bl
  __int64 v3; // rdx
  __int64 (__fastcall *v4)(__int64); // rax
  unsigned int v5; // eax
  int v6; // r14d
  int v7; // ebx
  unsigned int v8; // edi
  unsigned int v9; // esi
  char *v10; // rcx
  unsigned int (__fastcall *v11)(__int64); // rax
  __int64 v12; // rcx
  unsigned int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // edi
  unsigned int v16; // eax
  int v17; // r15d
  int v18; // edi
  int v19; // r14d
  unsigned int v20; // ebx
  unsigned __int64 v21; // rcx
  unsigned int v22; // eax
  unsigned int v23; // eax

  v2 = qword_5402E8(*(_QWORD *)(a1 + 16));
  KdUsb_printf("XHCI Version %x.%x  Capability Registers Length %d\n");
  v3 = *(_QWORD *)(a1 + 16);
  v4 = qword_5402E8;
  *(_QWORD *)(a1 + 24) = v3 + v2;
  v5 = v4(v3 + 4);
  v6 = (unsigned __int8)v5;
  v7 = (v5 >> 8) & 0x3FF;
  v8 = HIBYTE(v5);
  KdUsb_printf("NumberOfDeviceSlots %d NumberOfInterrupters %d NumberOfPorts %d\n");
  v9 = 0;
  if ( !v6 )
  {
    v10 = "Invalid number of device slots %d\n";
LABEL_26:
    KdUsb_printf(v10);
    return (unsigned int)-1073741811;
  }
  *(_DWORD *)(a1 + 64) = v6;
  if ( !v7 )
  {
    v10 = "Invalid number of interrupters %d\n";
    goto LABEL_26;
  }
  *(_DWORD *)(a1 + 68) = v7;
  if ( !v8 )
  {
    v10 = "Invalid number of ports %d\n";
    goto LABEL_26;
  }
  v11 = (unsigned int (__fastcall *)(__int64))qword_5402E8;
  v12 = *(_QWORD *)(a1 + 16) + 8LL;
  *(_DWORD *)(a1 + 72) = v8;
  *(_DWORD *)(a1 + 76) = 1 << ((v11(v12) >> 4) & 0xF);
  KdUsb_printf("IsochSchedulingThreshold %d EventRingSegmentTableMax %d\n");
  KdUsb_printf("ScratchpadRestore %d MaxScratchpadBuffers %d\n");
  v13 = qword_5402E8(*(_QWORD *)(a1 + 16) + 12LL);
  v14 = (unsigned __int8)v13;
  v15 = HIWORD(v13);
  *(_DWORD *)(a1 + 80) = __PAIR32__(HIWORD(v13), (unsigned __int8)v13);
  KdUsb_printf("U1DeviceExitLatency 0x%x U2DeviceExitLatency 0x%x\n");
  if ( v14 > 0xA )
  {
    v10 = "Invalid U1DeviceExitLatency\n";
    goto LABEL_26;
  }
  if ( v15 > 0x7FF )
  {
    v10 = "Invalid U2DeviceExitLatency\n";
    goto LABEL_26;
  }
  v16 = qword_5402E8(*(_QWORD *)(a1 + 16) + 16LL);
  v17 = (v16 >> 2) & 1;
  v18 = v16 & 1;
  v19 = (v16 >> 3) & 1;
  v20 = v16;
  KdUsb_printf("AddressingCapability %d BwNegotiationCapability %d ContextSize %d PortPowerControl %d\n");
  if ( !v18 )
  {
    v10 = "Only 64-bit addressing is supported\n";
    goto LABEL_26;
  }
  *(_DWORD *)(a1 + 84) = v17;
  *(_DWORD *)(a1 + 88) = v19;
  KdUsb_printf("PortIndicators %d LightHCResetCapability %d LatencyToleranceMessagingCapability %d NoSecondarySidSupport %d\n");
  KdUsb_printf("MaximumPrimaryStreamArraySize %d XhciExtendedCapabilitiesPointer 0x%x\n");
  if ( !((unsigned __int16)v20 >> 12) )
  {
    v10 = "Invalid MaxPSASize (0)\n";
    goto LABEL_26;
  }
  if ( (unsigned __int16)((unsigned __int16)v20 >> 12) > 7u )
  {
    KdUsb_printf("Setting MaxPSASize to 7 from %d\n");
    v20 = v20 & 0xFFFF0FFF | 0x7000;
  }
  *(_DWORD *)(a1 + 92) = (2 << ((v20 >> 12) & 0xF)) - 1;
  KdUsb_printf("Supported Number Of Streams %d\n");
  if ( !HIWORD(v20) || (v21 = 4 * ((unsigned __int64)v20 >> 16), v21 >= *(unsigned int *)(a1 + 8)) )
  {
    v10 = "Invalid Extended Capabilites Pointer %d\n";
    goto LABEL_26;
  }
  *(_QWORD *)(a1 + 48) = v21 + *(_QWORD *)(a1 + 16);
  KdUsb_printf("ExtendedCapabilityRegisters 0x%p\n");
  v22 = qword_5402E8(*(_QWORD *)(a1 + 16) + 20LL);
  if ( !v22 )
  {
    v10 = "Invalid DoorbellOffset 0x%x\n";
    goto LABEL_26;
  }
  *(_QWORD *)(a1 + 40) = *(_QWORD *)(a1 + 16) + v22;
  KdUsb_printf("DoorbellRegisters 0x%p DoorbellOffset 0x%x\n");
  v23 = qword_5402E8(*(_QWORD *)(a1 + 16) + 24LL);
  if ( !v23 )
  {
    v10 = "Invalid RuntimeRegisterSpaceOffset 0x%x\n";
    goto LABEL_26;
  }
  *(_QWORD *)(a1 + 32) = *(_QWORD *)(a1 + 16) + v23;
  KdUsb_printf("RuntimeRegisters 0x%p RuntimeRegisterSpaceOffset 0x%x\n");
  if ( (unsigned int)qword_5402E8(*(_QWORD *)(a1 + 24) + 8LL) != 1 )
  {
    v10 = "Unsupported xhciPageSize 0x%x\n";
    goto LABEL_26;
  }
  return v9;
}
