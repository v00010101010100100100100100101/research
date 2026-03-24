_int64 __fastcall SkpInitIdkEncryption(__int64 a1, BCRYPT_ALG_HANDLE *a2, BCRYPT_KEY_HANDLE *a3)
{
  char v3; // r12
  bool v4; // bp
  UCHAR *v5; // rsi
  unsigned int v6; // edi
  __int64 SystemHeap; // rax
  int v11; // eax
  NTSTATUS v13; // ebx
  unsigned int v14; // [rsp+78h] [rbp+10h] BYREF

  v3 = 0;
  v4 = 0;
  v5 = nullptr;
  v6 = 1024;
  v14 = 1024;
  if ( a2 && a3 )
  {
    SystemHeap = SkAllocateSystemHeap(0x400u);
    v5 = (UCHAR *)SystemHeap;
    if ( SystemHeap )
    {
      v11 = SkKSGetKey(a1, SystemHeap, &v14);
      v6 = v14;
      v13 = v11;
      if ( v11 >= 0 )
      {
        if ( v14 < 0x29 || v14 < *(_DWORD *)v5 )
        {
          v13 = -1073741595;
        }
        else
        {
          v13 = BCryptOpenAlgorithmProvider(a2, L"RSA", nullptr, 1u);
          if ( v13 >= 0 )
          {
            v3 = 1;
            v13 = BCryptImportKeyPair(*a2, nullptr, L"RSAPRIVATEBLOB", a3, v5 + 16, *((_DWORD *)v5 + 2) - 8, 0);
            v4 = v13 >= 0;
          }
        }
      }
    }
    else
    {
      _InterlockedIncrement(&SkPoolAllocationsFailed);
      v6 = v14;
      v13 = -1073741670;
    }
  }
  else
  {
    v13 = -1073741811;
  }
  if ( v5 )
