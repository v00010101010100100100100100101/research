void __fastcall wil::details::in1diag5::FailFast_Unexpected(
        wil::details::in1diag5 *this,
        void *a2,
        __int64 a3,
        const char *a4)
{
  void *retaddr; // [rsp+48h] [rbp+0h]

  wil::details::ReportFailure_Hr(
    this,
    2892,
    "onecore\\internal\\sdk\\inc\\wil\\opensource\\wil\\resource.h",
    "wil::mutex_t<class wil::details::unique_storage<struct wil::details::resource_policy<void *,void (__cdecl*)(void *),"
    "&void __cdecl wil::details::CloseHandle(void *),struct wistd::integral_constant<unsigned __int64,0>,void *,void *,0,"
    "std::nullptr_t> >,struct wil::err_returncode_policy>::acquire",
    "(status == WAIT_TIMEOUT) || (status == WAIT_OBJECT_0) || (status == WAIT_ABANDONED) || (bAlertable && (status == WAI"
    "T_IO_COMPLETION))",
    retaddr,
    3,
    -2147418113);
}
