#pragma once


// CClockHelpDlg 대화 상자입니다.

class CClockHelpDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CClockHelpDlg)

public:
	CClockHelpDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CClockHelpDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HELP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
