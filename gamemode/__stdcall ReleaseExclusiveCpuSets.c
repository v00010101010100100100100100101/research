HRESULT __stdcall ReleaseExclusiveCpuSets()
{
  HANDLE CurrentProcess; // rax
  bool *v1; // r8
  int IsProcessStronglyNamed; // eax
  CallerIdentity *v3; // rcx
  bool *v4; // r8
  HRESULT v5; // ebx
  DWORD CurrentProcessId; // eax
  HANDLE v7; // rdi
  signed int LastError; // eax
  int v9; // ebx
  int v10; // eax
  int pcbData; // [rsp+38h] [rbp-39h]
  char v13; // [rsp+48h] [rbp-29h] BYREF
  unsigned __int16 v14; // [rsp+49h] [rbp-28h] BYREF
  int v15; // [rsp+4Ch] [rbp-25h] BYREF
  int pvData; // [rsp+50h] [rbp-21h] BYREF
  DWORD v17; // [rsp+54h] [rbp-1Dh] BYREF
  HRESULT v18; // [rsp+58h] [rbp-19h] BYREF
  __int128 v19; // [rsp+60h] [rbp-11h] BYREF
  __int128 v20; // [rsp+70h] [rbp-1h]
  __int64 v21; // [rsp+80h] [rbp+Fh]
  char v22[32]; // [rsp+88h] [rbp+17h] BYREF
  HRESULT *v23; // [rsp+A8h] [rbp+37h]
  __int64 v24; // [rsp+B0h] [rbp+3Fh]

  v21 = 0;
  v19 = 0;
  v13 = 0;
  v20 = 0;
  CurrentProcess = GetCurrentProcess();
  IsProcessStronglyNamed = ARI::ProcessToken::SysAppId::IsProcessStronglyNamed(CurrentProcess, &v13, v1);
  v5 = IsProcessStronglyNamed;
  if ( IsProcessStronglyNamed > 0 )
    v5 = (unsigned __int16)IsProcessStronglyNamed | 0x80070000;
  if ( v5 >= 0 )
  {
    LOBYTE(v14) = 0;
    v5 = CallerIdentity::CheckCallerCapability(v3, &v14, v4);
    if ( v5 < 0 || v13 && (_BYTE)v14 )
    {
      if ( v5 >= 0 )
      {
        v15 = 0;
        RtlGetDeviceFamilyInfoEnum(0, &v15, 0);
        if ( v15 == 5 )
        {
          v5 = -2147467263;
        }
        else
        {
          pvData = 0;
          v17 = 4;
          if ( RegGetValueW(
                 HKEY_LOCAL_MACHINE,
                 L"Software\\Policies\\Microsoft\\Windows\\GameDVR",
                 L"AllowAutoGameMode",
                 0x18u,
                 nullptr,
                 &pvData,
                 &v17)
            || pvData )
          {
            CurrentProcessId = GetCurrentProcessId();
            v7 = OpenProcess(0x1000u, 0, CurrentProcessId);
            if ( v7 )
            {
              RmGameModeInitializeResourceRequest(&v19);
              v19 = 6u;
              HIDWORD(v20) = HIDWORD(v20) & 0xFFFFFFE0 | 0x10;
              *(_QWORD *)&v20 = 0x3200000002LL;
              DWORD2(v20) = 30;
              v9 = RmGameModeRegisterProcess(v7, &v19, 0);
              if ( v9 == -1073740008 )
              {
                RmGameModeUnregisterProcess(v7);
                v9 = RmGameModeRegisterProcess(v7, &v19, 0);
              }
              CloseHandle(v7);
              v10 = v9;
              v5 = v9 | 0x10000000;
              if ( v10 >= 0 )
                v5 = 0;
            }
            else
            {
              LastError = GetLastError();
              v5 = LastError;
              if ( LastError > 0 )
                v5 = (unsigned __int16)LastError | 0x80070000;
            }
          }
          else
          {
            v5 = -2147019873;
          }
        }
      }
    }
    else
    {
      v5 = -2147024891;
    }
  }
  if ( (unsigned int)dword_18000E000 > 4 )
  {
    v18 = v5;
    v23 = &v18;
    v24 = 4;
    tlgWriteTransfer_EventWriteTransfer(&dword_18000E000, &unk_18000B080, 0, 0, 3, v22, pcbData);
  }
  return v5;
}
