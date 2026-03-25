_int64 __fastcall wil::details_abi::SemaphoreValue::TryGetPointer(
        const unsigned __int16 *a1,
        void **a2,
        __int64 a3,
        bool *a4)
{
  unsigned __int64 v4; // rdi
  int ValueInternal; // eax
  unsigned int v7; // r8d
  int v8; // ebx
  char *v10; // [rsp+28h] [rbp-10h]
  int v11; // [rsp+30h] [rbp-8h]
  wil::details::in1diag5 *retaddr; // [rsp+38h] [rbp+0h]
  unsigned __int64 v13; // [rsp+48h] [rbp+10h] BYREF

  *a2 = nullptr;
  v4 = 0;
  v13 = 0;
  ValueInternal = wil::details_abi::SemaphoreValue::TryGetValueInternal(a1, (bool)a2, &v13, a4);
  v8 = ValueInternal;
  if ( ValueInternal >= 0 )
  {
    v4 = v13;
    v8 = 0;
  }
  else
  {
    LODWORD(v10) = ValueInternal;
    wil::details::in1diag5::Return_Hr(
      retaddr,
      (void *)0x62,
      v7,
      "wil::details_abi::SemaphoreValue::TryGetValue",
      "TryGetValueInternal(name, (sizeof(T) > sizeof(unsigned long)), &value64, retrieved)",
      v10,
      v11);
  }
  if ( v8 >= 0 )
  {
    *a2 = (void *)(4 * v4);
    return 0;
  }
  else
  {
    LODWORD(v10) = v8;
    wil::details::in1diag5::Return_Hr(
      retaddr,
      (void *)0x6B,
      v7,
      "wil::details_abi::SemaphoreValue::TryGetPointer",
      "TryGetValue(name, &value)",
      v10,
      v11);
    return (unsigned int)v8;
  }
}
