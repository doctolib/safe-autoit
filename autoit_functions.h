#ifndef X
# define X(type, name, args...) ;
#endif

// X(void, AU3_Init)
X(int, AU3_error)
X(int, AU3_AutoItSetOption, LPCWSTR, int)
X(void, AU3_ClipGet, LPWSTR, int)
X(void, AU3_ClipPut, LPCWSTR)
X(int, AU3_ControlClick, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, int, int, int)
X(int, AU3_ControlClickByHandle, HWND, HWND, LPCWSTR, int, int, int)
X(void, AU3_ControlCommand, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int)
X(void, AU3_ControlCommandByHandle, HWND, HWND, LPCWSTR, LPCWSTR, LPWSTR, int)
X(void, AU3_ControlListView, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int)
X(void, AU3_ControlListViewByHandle, HWND, HWND, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int)
X(int, AU3_ControlDisable, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_ControlDisableByHandle, HWND, HWND)
X(int, AU3_ControlEnable, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_ControlEnableByHandle, HWND, HWND)
X(int, AU3_ControlFocus, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_ControlFocusByHandle, HWND, HWND)
X(void, AU3_ControlGetFocus, LPCWSTR, LPCWSTR, LPWSTR, int)
X(void, AU3_ControlGetFocusByHandle, HWND, LPWSTR, int)
X(HWND, AU3_ControlGetHandle, HWND, LPCWSTR)
X(void, AU3_ControlGetHandleAsText, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int)
X(int, AU3_ControlGetPos, LPCWSTR, LPCWSTR, LPCWSTR, LPRECT)
X(int, AU3_ControlGetPosByHandle, HWND, HWND, LPRECT)
X(void, AU3_ControlGetText, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int)
X(void, AU3_ControlGetTextByHandle, HWND, HWND, LPWSTR, int)
X(int, AU3_ControlHide, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_ControlHideByHandle, HWND, HWND)
X(int, AU3_ControlMove, LPCWSTR, LPCWSTR, LPCWSTR, int, int, int, int)
X(int, AU3_ControlMoveByHandle, HWND, HWND, int, int, int, int)
X(int, AU3_ControlSend, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, int)
X(int, AU3_ControlSendByHandle, HWND, HWND, LPCWSTR, int)
X(int, AU3_ControlSetText, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_ControlSetTextByHandle, HWND, HWND, LPCWSTR)
X(int, AU3_ControlShow, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_ControlShowByHandle, HWND, HWND)
X(void, AU3_ControlTreeView, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int)
X(void, AU3_ControlTreeViewByHandle, HWND, HWND, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int)
X(void, AU3_DriveMapAdd, LPCWSTR, LPCWSTR, int, LPCWSTR, LPCWSTR, LPWSTR, int)
X(int, AU3_DriveMapDel, LPCWSTR)
X(void, AU3_DriveMapGet, LPCWSTR, LPWSTR, int)
X(int, AU3_IsAdmin)
X(int, AU3_MouseClick, LPCWSTR, int, int, int, int)
X(int, AU3_MouseClickDrag, LPCWSTR, int, int, int, int, int)
X(void, AU3_MouseDown, LPCWSTR)
X(int, AU3_MouseGetCursor)
X(void, AU3_MouseGetPos, LPPOINT)
X(int, AU3_MouseMove, int, int, int)
X(void, AU3_MouseUp, LPCWSTR)
X(void, AU3_MouseWheel, LPCWSTR, int)
X(int, AU3_Opt, LPCWSTR, int)
// X(unsigned int, AU3_PixelChecksum, LPRECT, int)
X(int, AU3_PixelGetColor, int, int)
X(void, AU3_PixelSearch, LPRECT, int, int, int, LPPOINT)
X(int, AU3_ProcessClose, LPCWSTR)
X(int, AU3_ProcessExists, LPCWSTR)
X(int, AU3_ProcessSetPriority, LPCWSTR, int)
X(int, AU3_ProcessWait, LPCWSTR, int)
X(int, AU3_ProcessWaitClose, LPCWSTR, int)
X(int, AU3_Run, LPCWSTR, LPCWSTR, int)
X(int, AU3_RunWait, LPCWSTR, LPCWSTR, int)
X(int, AU3_RunAs, LPCWSTR, LPCWSTR, LPCWSTR, int, LPCWSTR, LPCWSTR, int)
X(int, AU3_RunAsWait, LPCWSTR, LPCWSTR, LPCWSTR, int, LPCWSTR, LPCWSTR, int)
X(void, AU3_Send, LPCWSTR, int)
X(int, AU3_Shutdown, int)
X(void, AU3_Sleep, int)
X(int, AU3_StatusbarGetText, LPCWSTR, LPCWSTR, int, LPWSTR, int)
X(int, AU3_StatusbarGetTextByHandle, HWND, int, LPWSTR, int)
X(void, AU3_ToolTip, LPCWSTR, int, int)
X(int, AU3_WinActivate, LPCWSTR, LPCWSTR)
X(int, AU3_WinActivateByHandle, HWND)
X(int, AU3_WinActive, LPCWSTR, LPCWSTR)
X(int, AU3_WinActiveByHandle, HWND)
X(int, AU3_WinClose, LPCWSTR, LPCWSTR)
X(int, AU3_WinCloseByHandle, HWND)
X(int, AU3_WinExists, LPCWSTR, LPCWSTR)
X(int, AU3_WinExistsByHandle, HWND)
X(int, AU3_WinGetCaretPos, LPPOINT)
X(void, AU3_WinGetClassList, LPCWSTR, LPCWSTR, LPWSTR, int)
X(void, AU3_WinGetClassListByHandle, HWND, LPWSTR, int)
X(int, AU3_WinGetClientSize, LPCWSTR, LPCWSTR, LPRECT)
X(int, AU3_WinGetClientSizeByHandle, HWND, LPRECT)
X(HWND, AU3_WinGetHandle, LPCWSTR, LPCWSTR)
X(void, AU3_WinGetHandleAsText, LPCWSTR, LPCWSTR, LPWSTR, int)
X(int, AU3_WinGetPos, LPCWSTR, LPCWSTR, LPRECT)
X(int, AU3_WinGetPosByHandle, HWND, LPRECT)
X(DWORD, AU3_WinGetProcess, LPCWSTR, LPCWSTR)
X(DWORD, AU3_WinGetProcessByHandle, HWND)
X(int, AU3_WinGetState, LPCWSTR, LPCWSTR)
X(int, AU3_WinGetStateByHandle, HWND)
X(void, AU3_WinGetText, LPCWSTR, LPCWSTR, LPWSTR, int)
X(void, AU3_WinGetTextByHandle, HWND, LPWSTR, int)
X(void, AU3_WinGetTitle, LPCWSTR, LPCWSTR, LPWSTR, int)
X(void, AU3_WinGetTitleByHandle, HWND, LPWSTR, int)
X(int, AU3_WinKill, LPCWSTR, LPCWSTR)
X(int, AU3_WinKillByHandle, HWND)
X(int, AU3_WinMenuSelectItem, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_WinMenuSelectItemByHandle, HWND, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR)
X(void, AU3_WinMinimizeAll)
X(void, AU3_WinMinimizeAllUndo)
X(int, AU3_WinMove, LPCWSTR, LPCWSTR, int, int, int, int)
X(int, AU3_WinMoveByHandle, HWND, int, int, int, int)
X(int, AU3_WinSetOnTop, LPCWSTR, LPCWSTR, int)
X(int, AU3_WinSetOnTopByHandle, HWND, int)
X(int, AU3_WinSetState, LPCWSTR, LPCWSTR, int)
X(int, AU3_WinSetStateByHandle, HWND, int)
X(int, AU3_WinSetTitle, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_WinSetTitleByHandle, HWND, LPCWSTR)
X(int, AU3_WinSetTrans, LPCWSTR, LPCWSTR, int)
X(int, AU3_WinSetTransByHandle, HWND, int)
X(int, AU3_WinWait, LPCWSTR, LPCWSTR, int)
X(int, AU3_WinWaitByHandle, HWND, int)
X(int, AU3_WinWaitActive, LPCWSTR, LPCWSTR, int)
X(int, AU3_WinWaitActiveByHandle, HWND, int)
X(int, AU3_WinWaitClose, LPCWSTR, LPCWSTR, int)
X(int, AU3_WinWaitCloseByHandle, HWND, int)
X(int, AU3_WinWaitNotActive, LPCWSTR, LPCWSTR, int)
X(int, AU3_WinWaitNotActiveByHandle, HWND, int)
