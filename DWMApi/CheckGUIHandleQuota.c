__int64 __fastcall CheckGUIHandleQuota(unsigned int a1, DWORD a2, DWORD a3)
{
  unsigned int v3; // edi
  HANDLE CurrentProcess; // rax
  DWORD GuiResources; // eax
  unsigned int v6; // ebx
  DWORD v7; // esi
  unsigned int v8; // ebx
  unsigned int Data; // [rsp+50h] [rbp+8h] BYREF
  DWORD Type; // [rsp+58h] [rbp+10h] BYREF
  DWORD cbData; // [rsp+60h] [rbp+18h] BYREF
  HKEY hKey; // [rsp+68h] [rbp+20h] BYREF

  cbData = a3;
  Type = a2;
  Data = a1;
  v3 = -2003304445;
  CurrentProcess = GetCurrentProcess();
  GuiResources = GetGuiResources(CurrentProcess, 0);
  v6 = (unsigned int)g_GUIHandleQuota;
  v7 = GuiResources;
  if ( GuiResources >= (unsigned int)g_GUIHandleQuota )
  {
    if ( !(_DWORD)g_GUIHandleQuota )
    {
      v8 = 10000;
      if ( !RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows", 0, 1u, &hKey) )
      {
        cbData = 4;
        if ( !RegQueryValueExW(hKey, off_1800222F0, nullptr, &Type, (LPBYTE)&Data, &cbData) && Type == 4 && Data )
          v8 = Data;
        RegCloseKey(hKey);
      }
      v6 = v8 - (v8 >> 3);
      LODWORD(g_GUIHandleQuota) = -2147389502;
    }
    if ( v7 >= v6 )
      return (unsigned int)-2147024882;
  }
  return v3;
}
