#pragma once


// CTextOutCtrl ��ȭ �����Դϴ�.

class CTextOutCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CTextOutCtrl)

public:
	CTextOutCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTextOutCtrl();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TEXTOUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonTextout();
	afx_msg void OnClickedButtonColor();
	afx_msg void OnClickedButtonFont();
};
