#pragma once
#include "afxwin.h"


// CHobbyCtrl ��ȭ �����Դϴ�.

class CHobbyCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CHobbyCtrl)

public:
	CHobbyCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHobbyCtrl();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listHobby;
	CComboBox m_cbSex;
	CString m_strName;
	virtual BOOL OnInitDialog();
	bool m_bSex = true;
	bool m_bChecked[3] = { false, false, false };
	afx_msg void OnSelchangeComboSex();
	afx_msg void OnRadioFemale();
	afx_msg void OnRadioMale();
	afx_msg void OnSelchangeListHobby();
	afx_msg void OnClickedCheckFishing();
	afx_msg void OnClickedCheckReading();
	afx_msg void OnClickedCheckSports();
	afx_msg void OnClickedButtonResult();
};
