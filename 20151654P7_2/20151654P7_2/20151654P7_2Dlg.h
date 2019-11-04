
// 20151654P7_2Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CMy20151654P7_2Dlg ��ȭ ����
class CMy20151654P7_2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy20151654P7_2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20151654P7_2_DIALOG };
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
	CTreeCtrl m_treeControl;
	CString m_strNodeText;
	CString m_strSelectedNode;
	HTREEITEM m_hRoot;
	HTREEITEM m_hSelectedNode;
	afx_msg void OnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedButtonInsert();
	afx_msg void OnClickedButtonModify();
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnClickedCheckExpand();
	bool m_bChecked;
};
