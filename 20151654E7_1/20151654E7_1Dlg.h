
// 20151654E7_1Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"

typedef struct Product
{
	CString strCategory;
	CString strTitle;
	CString strYear;
	CString strGrade;
};


// CMy20151654E7_1Dlg ��ȭ ����
class CMy20151654E7_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy20151654E7_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20151654E7_1_DIALOG };
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
//	afx_msg void OnTvnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult);
	CTreeCtrl m_treeCtrl;
	CListCtrl m_listCtrl;
	CString m_CbRate;
	CString m_EdYear;
	CString m_EdTitle;
	HTREEITEM m_hRoot;
	HTREEITEM m_hMovie;
	HTREEITEM m_hDrama;
	Product m_productInfo[50];
	int m_nCount;
	int m_nSelectedItem;
	HTREEITEM m_hSelectedNode;
	afx_msg void OnItemchangedListControl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnClickedButtonInsert();
	afx_msg void OnClickedButtonUpdate();
	afx_msg void OnSelchangeComboRate();
};
