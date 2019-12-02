
// 20151654P8_1Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "ObjectDlg.h"
#include "ColorDlg.h"
#include "RatioDlg.h"


// CMy20151654P8_1Dlg ��ȭ ����
class CMy20151654P8_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy20151654P8_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20151654P8_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabSelection;
	int m_nSize;
	CSpinButtonCtrl m_spinSize;
	CObjectDlg m_dlgObject;
	CColorDlg m_dlgColor;
	void UpdateDrawing();
	afx_msg void OnSelchangeTabSelection(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinSize(NMHDR *pNMHDR, LRESULT *pResult);
	CRatioDlg m_dlgRatio;
};
