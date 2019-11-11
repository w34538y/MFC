#pragma once
#include "afxcmn.h"


// CColorDlg ��ȭ �����Դϴ�.

class CColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CColorDlg)

public:
	CColorDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CColorDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COLOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_sliderRed;
	CSliderCtrl m_sliderGreen;
	CSliderCtrl m_sliderBlue;
	int m_nRed;
	int m_nGreen;
	int m_nBlue;
	COLORREF m_colorObject;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
