__int64 __fastcall DXCoreAdapter::QueryState(
  v62 = a2;
  v44 = a3;
  v45 = a1;
  v46 = a1;
  v8 = a6;
  v9 = 0;
  if ( !a6 )
  {
    wil::details::in1diag3::_Throw_Hr(
      retaddr,
      (void *)0x258,
      (unsigned int)"onecore\\windows\\directx\\dxcore\\dll\\dxcore.cpp",
      (const char *)0x80004003LL,
      v39);
    goto LABEL_44;
  }
  memset_0(a6, 0, Size);
  v10 = retaddr;
  if ( *(_DWORD *)(a1 + 240) != 3 )
  {
LABEL_44:
    wil::details::in1diag3::_Throw_Hr(
      v10,
      (void *)0x25B,
      (unsigned int)"onecore\\windows\\directx\\dxcore\\dll\\dxcore.cpp",
      (const char *)0x887A0005LL,
      v39);
    goto LABEL_45;
  }
  v11 = v62;
  v12 = retaddr;
  if ( v62 > 1 )
  {
LABEL_45:
    wil::details::in1diag3::_Throw_Hr(
      v12,
      (void *)0x25F,
      (unsigned int)"onecore\\windows\\directx\\dxcore\\dll\\dxcore.cpp",
      (const char *)0x887A0001LL,
      v39);
LABEL_46:
    v37 = wil::verify_hresult<long>(2147942487LL);
    wil::details::in1diag3::Throw_Hr(retaddr, (void *)0x289, v38, (const char *)v37, v39);
    goto LABEL_47;
  }
  if ( !v62 )
  {
    v22 = retaddr;
    if ( *(_DWORD *)(a1 + 240) == 3 )
    {
      v23 = retaddr;
      if ( Size )
      {
        v24 = 0;
        v40 = 0;
        v53 = 4;
        v51[0] = *(_DWORD *)(a1 + 16);
        v51[1] = 11;
        v52 = &v40;
        v25 = NtGdiDdDDIQueryAdapterInfo(v51);
        v26 = v25;
        if ( v25 >= 0 )
          v24 = v40 != 0;
        else
          RecordJournal(v25, "QAI for KMTQAITYPE_CHECKDRIVERUPDATESTATUS failed.", 1);
        v27 = (const char *)(unsigned int)v26;
        LODWORD(v27) = v26 | 0x10000000;
        if ( v26 >= 0 )
          v27 = nullptr;
        v28 = retaddr;
        if ( (int)v27 >= 0 )
        {
          *(_BYTE *)v8 = v24;
          v11 = v62;
          goto LABEL_25;
        }
LABEL_53:
        wil::details::in1diag3::_Throw_Hr(
          v28,
          (void *)0x26E,
          (unsigned int)"onecore\\windows\\directx\\dxcore\\dll\\dxcore.cpp",
          v27,
          v39);
        __debugbreak();
        JUMPOUT(0x180009E84LL);
      }
LABEL_52:
      wil::details::in1diag3::_Throw_Hr(
        v23,
        (void *)0x26B,
        (unsigned int)"onecore\\windows\\directx\\dxcore\\dll\\dxcore.cpp",
        (const char *)0x80070057LL,
        v39);
      goto LABEL_53;
    }
LABEL_51:
    wil::details::in1diag3::_Throw_Hr(
      v22,
      (void *)0x269,
      (unsigned int)"onecore\\windows\\directx\\dxcore\\dll\\dxcore.cpp",
      (const char *)0x887A0005LL,
      v39);
    goto LABEL_52;
  }
  if ( v62 != 1 )
    goto LABEL_46;
  v13 = retaddr;
  if ( !a4 )
  {
LABEL_47:
    wil::details::in1diag3::_Throw_Hr(
      v13,
      (void *)0x277,
      (unsigned int)"onecore\\windows\\directx\\dxcore\\dll\\dxcore.cpp",
      (const char *)0x80004003LL,
      v39);
    goto LABEL_48;
  }
  v14 = retaddr;
  if ( v44 < 8 )
  {
LABEL_48:
    wil::details::in1diag3::_Throw_Hr(
      v14,
      (void *)0x278,
      (unsigned int)"onecore\\windows\\directx\\dxcore\\dll\\dxcore.cpp",
      (const char *)0x80070057LL,
      v39);
    goto LABEL_49;
  }
  v15 = retaddr;
  if ( Size < 0x20 )
  {
LABEL_49:
    wil::details::in1diag3::_Throw_Hr(
      v15,
      (void *)0x279,
      (unsigned int)"onecore\\windows\\directx\\dxcore\\dll\\dxcore.cpp",
      (const char *)0x80070057LL,
      v39);
    goto LABEL_50;
  }
  v16 = a4[1];
  v17 = retaddr;
  if ( v16 > 1 )
  {
LABEL_50:
    wil::details::in1diag3::_Throw_Hr(
      v17,
      (void *)0x27F,
      (unsigned int)"onecore\\windows\\directx\\dxcore\\dll\\dxcore.cpp",
      (const char *)0x80070057LL,
      v39);
    goto LABEL_51;
  }
  v18 = *a4;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  DWORD2(v54) = *(_DWORD *)(a1 + 16);
  LODWORD(v57) = v18;
  HIDWORD(v54) = v16;
  v19 = NtGdiDdDDIQueryVideoMemoryInfo(&v54);
  v20 = v19;
  if ( v19 < 0 )
  {
    RecordJournal(v19, "NtGdiDdDDIQueryVideoMemoryInfo failed.", 1);
  }
  else
  {
    *(_OWORD *)v8 = v55;
    v8[2] = *((_QWORD *)&v56 + 1);
    v8[3] = v56;
  }
  v21 = v20;
  v9 = v20 | 0x10000000;
  if ( v21 >= 0 )
    v9 = 0;
LABEL_25:
  LogTelemetryAPIResult("QueryState", v9, (void *)a1, nullptr);
  if ( v9 >= 0 && dword_180032000 )
  {
    v58 = a1 + 400;
    v59 = 0;
    v29 = _Mtx_lock((_Mtx_t)(a1 + 400));
    if ( v29 )
      std::_Throw_C_error(v29);
    v59 = 1;
    v32 = *(_DWORD **)(v46 + 488);
    v33 = *(_DWORD **)(a1 + 480);
    if ( v33 == v32 )
      goto LABEL_35;
    do
    {
      if ( *v33 == v11 )
        break;
      ++v33;
    }
    while ( v33 != v32 );
    if ( v33 == v32 )
    {
LABEL_35:
      if ( (unsigned int)dword_180032000 > 5
        && (qword_180032010 & 0x400000000000LL) != 0
        && (qword_180032018 & 0x400000000000LL) == qword_180032018 )
      {
        v60 = Uuid;
        v47 = a1;
        v41 = v9;
        v48 = *(_QWORD *)(a1 + 20);
        v42 = v11;
        v49 = &v60;
        v43 = 1;
        v50 = 2197815296LL;
        _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteTransfer_EventWriteTransfer(_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),_GUID const *,_GUID const *>::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>>(
          (_DWORD)v32,
          (unsigned int)&unk_180028F3C,
          v30,
          v31,
          (__int64)&v50,
          (__int64)&v43,
          (__int64)&v49,
          (__int64)&v42,
          (__int64)&v48,
          (__int64)&v41,
          (__int64)&v47);
      }
      v34 = *(unsigned int **)(a1 + 488);
      if ( *(unsigned int **)(a1 + 496) == v34 )
      {
        std::vector<enum DXCoreAdapterState>::_Emplace_reallocate<enum DXCoreAdapterState const &>(a1 + 480, v34, &v62);
      }
      else
      {
        *v34 = v11;
        *(_QWORD *)(a1 + 488) += 4LL;
      }
    }
    v35 = _Mtx_unlock((_Mtx_t)(a1 + 400));
    if ( v35 )
      std::_Throw_C_error(v35);
  }
  return (unsigned int)v9;
}
