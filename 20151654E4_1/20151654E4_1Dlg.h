
// 20151654E4_1Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CMy20151654E4_1Dlg ��ȭ ����
class CMy20151654E4_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy20151654E4_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20151654E4_1_DIALOG };
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
	afx_msg void OnCbnSelchangeComboMove();
	CListBox m_listLeft;
	CListBox m_listRight;
	CComboBox m_cbMove;
	CString m_strResult;
	afx_msg void OnClickedButtonPurchase();
};
