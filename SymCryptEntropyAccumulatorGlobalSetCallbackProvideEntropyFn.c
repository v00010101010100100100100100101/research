char SymCryptEntropyAccumulatorGlobalSetCallbackProvideEntropyFn()
{
  if ( g_SymCryptCallbackEntropyAccumulatorProvideEntropy )
    return 0;
  g_SymCryptCallbackEntropyAccumulatorProvideEntropy = (__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD))&loc_1C00017F5;
  return 1;
}
