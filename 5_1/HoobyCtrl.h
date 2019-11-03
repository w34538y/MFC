#pragma once
#include "afxwin.h"


// CHoobyCtrl 대화 상자입니다.

class CHoobyCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CHoobyCtrl)

public:
	CHoobyCtrl(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CHoobyCtrl();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listHobby;
	CComboBox m_cbSex;
	CString m_strName;
	virtual BOOL OnInitDialog();
	bool m_bSex = true;
	bool m_bChecked[3] = { false, false, false };
	afx_msg void OnSelchangeComboSex();
	afx_msg void OnRadioMale();
	afx_msg void OnRadioFemale();
	afx_msg void OnSelchangeListHobby();
	afx_msg void OnClickedCheckFishing();
	afx_msg void OnClickedCheckReading();
	afx_msg void OnClickedCheckSports();
	afx_msg void OnClickedButtonResult();
};
