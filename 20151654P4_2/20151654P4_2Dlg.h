
// 20151654P4_2Dlg.h : 헤더 파일
//

#pragma once
#include "ClockHelpDlg.h"


// CMy20151654P4_2Dlg 대화 상자
class CMy20151654P4_2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMy20151654P4_2Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20151654P4_2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
//	CString m_strYear;
//	CString m_strMonth;
//	CString m_strDay;
//	CString m_strAMPM;
//	CString m_strMinute;
//	CString m_strSecond;
//	CString m_strHour;
	bool m_bRadioClockType;
	afx_msg void OnRadio12();
	afx_msg void OnRadio24();
	bool m_bCheckYear;
	bool m_bCheckHour;
	afx_msg void OnClickedCheckYear();
	afx_msg void OnClickedCheckHour();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_strAMPM;
	CString m_strDay;
	CString m_strHour;
	CString m_strMinute;
	CString m_strMonth;
	CString m_strSecond;
	CString m_strYear;
	bool m_bViewHelp;
	CClockHelpDlg m_dlgClockHelp;
	afx_msg void OnClickedButtonHelp();
};
