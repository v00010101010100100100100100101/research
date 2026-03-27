void __fastcall __noreturn SymCryptFatalEnvWindowsKernelmodeWin8_1nLater(ULONG_PTR BugCheckParameter1)
{
  KeBugCheckEx(0x171u, (unsigned int)BugCheckParameter1, 0, 0, 0);
}
