#pragma once
#include "afxcmn.h"


// CRatioDlg ��ȭ �����Դϴ�.

class CRatioDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRatioDlg)

public:
	CRatioDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRatioDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RATIO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
