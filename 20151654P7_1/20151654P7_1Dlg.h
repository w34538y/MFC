
// 20151654P7_1Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CMy20151654P7_1Dlg ��ȭ ����
class CMy20151654P7_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy20151654P7_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20151654P7_1_DIALOG };
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
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_listStudent;
	CString m_strSelectedItem;
	CString m_strName;
//	CString m_strID;
	CString m_strDept;
	CString m_strID;
	afx_msg void OnBnClickedButtonInsert();
};
