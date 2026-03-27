NTSTATUS SymCryptEntropyAccumulatorReadConfig()
{
  NTSTATUS result; // eax
  void *KeyHandle; // [rsp+20h] [rbp-60h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+28h] [rbp-58h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+58h] [rbp-28h] BYREF
  struct _UNICODE_STRING ValueName; // [rsp+68h] [rbp-18h] BYREF

  memset(&ObjectAttributes.Attributes + 1, 0, 20);
  KeyHandle = nullptr;
  *(&ObjectAttributes.Length + 1) = 0;
  DestinationString = 0;
  ValueName = 0;
  RtlInitUnicodeString(&DestinationString, L"\\Registry\\Machine\\SYSTEM\\RNG\\EntropyAccumulator");
  RtlInitUnicodeString(&ValueName, L"Config");
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 1600;
  result = ZwOpenKey(&KeyHandle, 0x3001Fu, &ObjectAttributes);
  if ( result >= 0 )
    result = ZwDeleteValueKey(KeyHandle, &ValueName);
  if ( KeyHandle )
    result = ZwClose(KeyHandle);
  g_SymCryptEntropyAccumulatorConfig = -1073735789;
  return result;
}
