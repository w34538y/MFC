// TextOutCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "20151654P5_4.h"
#include "TextOutCtrl.h"
#include "afxdialogex.h"


// CTextOutCtrl ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTextOutCtrl, CDialogEx)

CTextOutCtrl::CTextOutCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_TEXTOUT, pParent)
{

}

CTextOutCtrl::~CTextOutCtrl()
{
}

void CTextOutCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTextOutCtrl, CDialogEx)
END_MESSAGE_MAP()


// CTextOutCtrl �޽��� ó�����Դϴ�.


BOOL CTextOutCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SetDlgItemText(IDC_EDIT_COLOR, _T("000000"));
	SetDlgItemText(IDC_EDIT_FONT, _T("system"));


	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
