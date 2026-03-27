__int64 __fastcall SymCryptEntropyAccumulatorDpcRoutine(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v4; // r9
  unsigned int v5; // esi
  unsigned __int64 v6; // rdx
  _OWORD *v7; // rdi
  __int64 v8; // rcx
  __int64 v9; // r8
  __int64 v10; // rcx
  unsigned __int64 v11; // rcx
  __int64 result; // rax

  v4 = a3;
  v5 = 768000;
  v6 = (a3 - 1024) >> 10;
  v7 = (_OWORD *)(a2 + ((unsigned __int64)(((a3 - 1024) & 0x400) != 0) << 7));
  v8 = 0;
  while ( *((_QWORD *)v7 + v8) != -1 && *((_QWORD *)v7 + v8) != 0 )
  {
    if ( (unsigned __int64)++v8 >= 0x10 )
      goto LABEL_6;
  }
  v5 = 0;
  ++*(_QWORD *)(a2 + 328);
LABEL_6:
  v9 = *(_QWORD *)(a2 + 336);
  if ( v9 )
  {
    if ( g_SymCryptEntropyAccumulatorConfig == 2 )
    {
      v10 = 2 * (*(_QWORD *)(a2 + 344) + 8 * v6);
      *(_OWORD *)(v9 + 8 * v10) = *v7;
      *(_OWORD *)(v9 + 8 * v10 + 16) = v7[1];
      *(_OWORD *)(v9 + 8 * v10 + 32) = v7[2];
      *(_OWORD *)(v9 + 8 * v10 + 48) = v7[3];
      *(_OWORD *)(v9 + 8 * v10 + 64) = v7[4];
      *(_OWORD *)(v9 + 8 * v10 + 80) = v7[5];
      *(_OWORD *)(v9 + 8 * v10 + 96) = v7[6];
      *(_OWORD *)(v9 + 8 * v10 + 112) = v7[7];
      if ( v4 >= *(_QWORD *)(a2 + 344) )
      {
        qword_1C0003070 = 0x1C00015E1LL;
        qword_1C0003068 = 0x1C00015F4LL;
        g_SymCryptEntropyAccumulatorLoggingState = 0x1C0001602LL;
        *(_QWORD *)(a2 + 336) = 0;
        qword_1C0003078 = 0;
        qword_1C0003088 = 0x1C0001620LL;
        qword_1C0003090 = 0x1C000162ELL;
        ExQueueWorkItem((PWORK_QUEUE_ITEM)&qword_1C0003078, DelayedWorkQueue);
      }
    }
    else if ( g_SymCryptEntropyAccumulatorConfig == 1 )
    {
      v11 = *(_QWORD *)(a2 + 344);
      *(_QWORD *)(a2 + 336) = 0;
      SymCryptWipeAsm(v9, 16 * (v11 + 8 * (v11 >> 10)));
    }
  }
  if ( g_SymCryptCallbackEntropyAccumulatorProvideEntropy )
    g_SymCryptCallbackEntropyAccumulatorProvideEntropy(v7, 128, v5, v4);
  result = SymCryptWipeAsm(v7, 128);
  *(_BYTE *)(a2 + 360) = 0;
  return result;
}
