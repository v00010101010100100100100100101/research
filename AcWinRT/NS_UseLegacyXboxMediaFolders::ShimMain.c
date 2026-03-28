__int64 __fastcall NS_UseLegacyXboxMediaFolders::ShimMain(NS_UseLegacyXboxMediaFolders *this, struct ISHIMENG *a2)
{
  __int64 result; // rax
  unsigned int v4; // ebx

  result = QuirkIsEnabled(10, a2);
  v4 = 0;
  if ( (_DWORD)result )
  {
    LOBYTE(v4) = (*(unsigned int (__fastcall **)(NS_UseLegacyXboxMediaFolders *, const wchar_t *, GUID *, __int64, __int64 (__fastcall *)(NS_UseLegacyXboxMediaFolders *__hidden, void *, struct Windows::Storage::IStorageFolder **)))(*(_QWORD *)this + 24LL))(
                   this,
                   L"Windows.Storage.KnownFolders",
                   &GUID_5a2a7520_4802_452d_9ad9_4351ada7ec35,
                   12,
                   NS_UseLegacyXboxMediaFolders::Hook_IKnownFoldersStatics_get_MediaServerDevices) != 0;
    return v4;
  }
  return result;
}
