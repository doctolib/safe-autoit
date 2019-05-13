#ifndef X
# define X(type, name, args...) ;
#endif

/* X(void, AU3_Init) */
X(int, AU3_error)
X(int, AU3_AutoItSetOption, LPCWSTR, int)
X(void, AU3_ClipGet, LPWSTR, int)
X(void, AU3_ClipPut, LPCWSTR)
X(int, AU3_ControlClick, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, int, int, int)
X(int, AU3_ControlClickByHandle, HWND, HWND, LPCWSTR, int, int, int)
	/*
X(void, AU3_ControlCommand, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(void, AU3_ControlCommandByHandle, HWND hWnd, HWND hCtrl, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(void, AU3_ControlListView, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(void, AU3_ControlListViewByHandle, HWND hWnd, HWND hCtrl, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(int, AU3_ControlDisable, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_ControlDisableByHandle, HWND hWnd, HWND hCtrl)
X(int, AU3_ControlEnable, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_ControlEnableByHandle, HWND hWnd, HWND hCtrl)
X(int, AU3_ControlFocus, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_ControlFocusByHandle, HWND hWnd, HWND hCtrl)
X(void, AU3_ControlGetFocus, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(void, AU3_ControlGetFocusByHandle, HWND hWnd, LPWSTR, int nBufSize)
X(HWND, AU3_ControlGetHandle, HWND hWnd, LPCWSTR)
X(void, AU3_ControlGetHandleAsText, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(int, AU3_ControlGetPos, LPCWSTR, LPCWSTR, LPCWSTR, LPRECT lpRect)
X(int, AU3_ControlGetPosByHandle, HWND hWnd, HWND hCtrl, LPRECT lpRect)
X(void, AU3_ControlGetText, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(void, AU3_ControlGetTextByHandle, HWND hWnd, HWND hCtrl, LPWSTR, int nBufSize)
X(int, AU3_ControlHide, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_ControlHideByHandle, HWND hWnd, HWND hCtrl)
X(int, AU3_ControlMove, LPCWSTR, LPCWSTR, LPCWSTR, int nX, int nY, int nWidth = -1, int nHeight = -1)
X(int, AU3_ControlMoveByHandle, HWND hWnd, HWND hCtrl, int nX, int nY, int nWidth = -1, int nHeight = -1)
X(int, AU3_ControlSend, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, int nMode = 0)
X(int, AU3_ControlSendByHandle, HWND hWnd, HWND hCtrl, LPCWSTR, int nMode = 0)
X(int, AU3_ControlSetText, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_ControlSetTextByHandle, HWND hWnd, HWND hCtrl, LPCWSTR)
X(int, AU3_ControlShow, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_ControlShowByHandle, HWND hWnd, HWND hCtrl)
X(void, AU3_ControlTreeView, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(void, AU3_ControlTreeViewByHandle, HWND hWnd, HWND hCtrl, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(void, AU3_DriveMapAdd, LPCWSTR, LPCWSTR, int nFlags, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(int, AU3_DriveMapDel, LPCWSTR)
X(void, AU3_DriveMapGet, LPCWSTR, LPWSTR, int nBufSize)
X(int, AU3_IsAdmin, void)
X(int, AU3_MouseClick, LPCWSTR, int nX = AU3_INTDEFAULT, int nY = AU3_INTDEFAULT, int nClicks = 1, int nSpeed = -1)
X(int, AU3_MouseClickDrag, LPCWSTR, int nX1, int nY1, int nX2, int nY2, int nSpeed = -1)
X(void, AU3_MouseDown, LPCWSTR)
X(int, AU3_MouseGetCursor, void)
X(void, AU3_MouseGetPos, LPPOINT lpPoint)
X(int, AU3_MouseMove, int nX, int nY, int nSpeed = -1)
X(void, AU3_MouseUp, LPCWSTR)
X(void, AU3_MouseWheel, LPCWSTR, int nClicks)
X(int, AU3_Opt, LPCWSTR, int nValue)
X(unsigned int, AU3_PixelChecksum, LPRECT lpRect, int nStep = 1)
X(int, AU3_PixelGetColor, int nX, int nY)
X(void, AU3_PixelSearch, LPRECT lpRect, int nCol, int nVar, int nStep, LPPOINT pPointResult)
X(int, AU3_ProcessClose, LPCWSTR)
X(int, AU3_ProcessExists, LPCWSTR)
X(int, AU3_ProcessSetPriority, LPCWSTR, int nPriority)
X(int, AU3_ProcessWait, LPCWSTR, int nTimeout = 0)
X(int, AU3_ProcessWaitClose, LPCWSTR, int nTimeout = 0)
X(int, AU3_Run, LPCWSTR, LPCWSTR, int nShowFlag = SW_SHOWNORMAL)
X(int, AU3_RunWait, LPCWSTR, LPCWSTR, int nShowFlag = SW_SHOWNORMAL)
X(int, AU3_RunAs, LPCWSTR, LPCWSTR, LPCWSTR, int nLogonFlag, LPCWSTR, LPCWSTR, int nShowFlag = SW_SHOWNORMAL)
X(int, AU3_RunAsWait, LPCWSTR, LPCWSTR, LPCWSTR, int nLogonFlag, LPCWSTR, LPCWSTR, int nShowFlag = SW_SHOWNORMAL)
X(void, AU3_Send, LPCWSTR, int nMode = 0)
X(int, AU3_Shutdown, int nFlags)
X(void, AU3_Sleep, int nMilliseconds)
X(int, AU3_StatusbarGetText, LPCWSTR, LPCWSTR, int nPart, LPWSTR, int nBufSize)
X(int, AU3_StatusbarGetTextByHandle, HWND hWnd, int nPart, LPWSTR, int nBufSize)
X(void, AU3_ToolTip, LPCWSTR, int nX = AU3_INTDEFAULT, int nY = AU3_INTDEFAULT)
X(int, AU3_WinActivate, LPCWSTR, LPCWSTR)
X(int, AU3_WinActivateByHandle, HWND hWnd)
X(int, AU3_WinActive, LPCWSTR, LPCWSTR)
X(int, AU3_WinActiveByHandle, HWND hWnd)
X(int, AU3_WinClose, LPCWSTR, LPCWSTR)
X(int, AU3_WinCloseByHandle, HWND hWnd)
X(int, AU3_WinExists, LPCWSTR, LPCWSTR)
X(int, AU3_WinExistsByHandle, HWND hWnd)
X(int, AU3_WinGetCaretPos, LPPOINT lpPoint)
X(void, AU3_WinGetClassList, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(void, AU3_WinGetClassListByHandle, HWND hWnd, LPWSTR, int nBufSize)
X(int, AU3_WinGetClientSize, LPCWSTR, LPCWSTR, LPRECT lpRect)
X(int, AU3_WinGetClientSizeByHandle, HWND hWnd, LPRECT lpRect)
X(HWND, AU3_WinGetHandle, LPCWSTR, LPCWSTR)
X(void, AU3_WinGetHandleAsText, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(int, AU3_WinGetPos, LPCWSTR, LPCWSTR, LPRECT lpRect)
X(int, AU3_WinGetPosByHandle, HWND hWnd, LPRECT lpRect)
X(DWORD, AU3_WinGetProcess, LPCWSTR, LPCWSTR)
X(DWORD, AU3_WinGetProcessByHandle, HWND hWnd)
X(int, AU3_WinGetState, LPCWSTR, LPCWSTR)
X(int, AU3_WinGetStateByHandle, HWND hWnd)
X(void, AU3_WinGetText, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(void, AU3_WinGetTextByHandle, HWND hWnd, LPWSTR, int nBufSize)
X(void, AU3_WinGetTitle, LPCWSTR, LPCWSTR, LPWSTR, int nBufSize)
X(void, AU3_WinGetTitleByHandle, HWND hWnd, LPWSTR, int nBufSize)
X(int, AU3_WinKill, LPCWSTR, LPCWSTR)
X(int, AU3_WinKillByHandle, HWND hWnd)
X(int, AU3_WinMenuSelectItem, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_WinMenuSelectItemByHandle, HWND hWnd, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR)
X(void, AU3_WinMinimizeAll, )
X(void, AU3_WinMinimizeAllUndo, )
X(int, AU3_WinMove, LPCWSTR, LPCWSTR, int nX, int nY, int nWidth = -1, int nHeight = -1)
X(int, AU3_WinMoveByHandle, HWND hWnd, int nX, int nY, int nWidth = -1, int nHeight = -1)
X(int, AU3_WinSetOnTop, LPCWSTR, LPCWSTR, int nFlag)
X(int, AU3_WinSetOnTopByHandle, HWND hWnd, int nFlag)
X(int, AU3_WinSetState, LPCWSTR, LPCWSTR, int nFlags)
X(int, AU3_WinSetStateByHandle, HWND hWnd, int nFlags)
X(int, AU3_WinSetTitle, LPCWSTR, LPCWSTR, LPCWSTR)
X(int, AU3_WinSetTitleByHandle, HWND hWnd, LPCWSTR)
X(int, AU3_WinSetTrans, LPCWSTR, LPCWSTR, int nTrans)
X(int, AU3_WinSetTransByHandle, HWND hWnd, int nTrans)
X(int, AU3_WinWait, LPCWSTR, LPCWSTR, int nTimeout = 0)
X(int, AU3_WinWaitByHandle, HWND hWnd, int nTimeout)
X(int, AU3_WinWaitActive, LPCWSTR, LPCWSTR, int nTimeout = 0)
X(int, AU3_WinWaitActiveByHandle, HWND hWnd, int nTimeout)
X(int, AU3_WinWaitClose, LPCWSTR, LPCWSTR, int nTimeout = 0)
X(int, AU3_WinWaitCloseByHandle, HWND hWnd, int nTimeout)
X(int, AU3_WinWaitNotActive, LPCWSTR, LPCWSTR, int nTimeout)
X(int, AU3_WinWaitNotActiveByHandle, HWND hWnd, int nTimeout = 0)
	*/