HRESULT __stdcall DwmEnableMMCSS(BOOL fEnableMMCSS) // true | false 
{
  int v1; // r8d
  int v3; // eax
  unsigned int v4; // ebx
  int v6; // [rsp+30h] [rbp-28h] BYREF
  _DWORD v7[4]; // [rsp+38h] [rbp-20h] BYREF

  v6 = 0;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 ) // 1..0
    McGenEventWrite_EtwEventWriteTransfer(
      (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      (unsigned int)ApiEnableMMCSS_Start,
      v1,
      1);
  v7[0] = 1073741869;
  v7[1] = fEnableMMCSS;
  v3 = CApiPortClient::SendRequest((CApiPortClient *)&g_PortClient, v7, 8, &v6, nullptr, 0);
  v4 = v3;
  if ( v3 < 0 )
    DoStackCaptureDirect(v3, 0x25u);
  else
    v4 = v6;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 )
    McTemplateU0q_EtwEventWriteTransfer(Microsoft_Windows_Dwm_Api_Provider_Context, ApiEnableMMCSS_Stop, v4);
  return MilToDwmError(v4);
}
