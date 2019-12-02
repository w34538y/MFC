#pragma once
#include "afxcmn.h"


// CRatioDlg 대화 상자입니다.

class CRatioDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRatioDlg)

public:
	CRatioDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CRatioDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RATIO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	bool m_bSameRatio;
	int m_nCurHScale;
	int m_nCurVScale;
	CSliderCtrl m_nVertical;
	CSliderCtrl m_nHorizontal;
	int m_niHori;
	int m_niVerti;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnClickedCheckSameRatio();
};
