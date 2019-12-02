// RatioDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "20151654P8_1.h"
#include "RatioDlg.h"
#include "afxdialogex.h"
#include "20151654P8_1Dlg.h"

// CRatioDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRatioDlg, CDialogEx)

CRatioDlg::CRatioDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_RATIO, pParent)
	, m_bSameRatio(false)
	, m_nCurHScale(0)
	, m_nCurVScale(0)
	, m_niHori(0)
	, m_niVerti(0)
{

}

CRatioDlg::~CRatioDlg()
{
}

void CRatioDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_VERTICAL, m_nVertical);
	DDX_Control(pDX, IDC_SLIDER_HORIZONTAL, m_nHorizontal);
	DDX_Text(pDX, IDC_EDIT_HORIZONTAL, m_niHori);
	DDX_Text(pDX, IDC_EDIT_HORIZONTAL, m_niVerti);
}


BEGIN_MESSAGE_MAP(CRatioDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_CHECK_SAME_RATIO, &CRatioDlg::OnClickedCheckSameRatio)
END_MESSAGE_MAP()


// CRatioDlg �޽��� ó�����Դϴ�.


BOOL CRatioDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	((CButton*)GetDlgItem(IDC_CHECK_SAME_RATIO))->SetCheck(TRUE);
	m_niHori = m_niVerti = 50;
	m_nHorizontal.SetRange(0, 100);
	m_nVertical.SetRange(0, 100);
	m_nHorizontal.SetPos(50);
	m_nVertical.SetPos(50);
	m_bSameRatio = true;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CRatioDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMy20151654P8_1Dlg* pMainDlg = (CMy20151654P8_1Dlg*)AfxGetMainWnd();

	m_nCurHScale = m_nHorizontal.GetPos();
	m_nCurVScale = m_nVertical.GetPos();

	if (m_bSameRatio)
	{
		if (pScrollBar->GetSafeHwnd() == m_nHorizontal.m_hWnd)
		{
			m_nCurVScale = m_nCurHScale;
			m_niVerti = m_niHori = m_nCurHScale;
			m_nVertical.SetPos(m_nCurHScale);
		}
		else if (pScrollBar->GetSafeHwnd() == m_nVertical.m_hWnd)
		{
			m_nCurHScale = m_nCurVScale;
			m_niVerti = m_niHori = m_nCurVScale;
			m_nHorizontal.SetPos(m_nCurVScale);
		}
		else
			return;
	}
	else
	{
		if (pScrollBar->GetSafeHwnd() == m_nHorizontal.m_hWnd)
			m_niHori = m_nCurHScale;
		else if (pScrollBar->GetSafeHwnd() == m_nVertical.m_hWnd)
			m_niVerti = m_nCurVScale;
		else
			return;
	}
	pMainDlg->UpdateDrawing();

	UpdateData(FALSE);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CRatioDlg::OnClickedCheckSameRatio()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMy20151654P8_1Dlg* pMainDlg = (CMy20151654P8_1Dlg*)AfxGetMainWnd();

	if (((CButton*)GetDlgItem(IDC_CHECK_SAME_RATIO))->GetCheck() == true)
	{
		m_bSameRatio = true;
		if (m_nCurHScale > m_nCurVScale)
		{
			m_nVertical.SetPos(m_nCurHScale);
			m_niVerti = m_nCurHScale;
		}
		else
		{
			m_nHorizontal.SetPos(m_nCurVScale);
			m_niHori = m_nCurVScale;
		}
	}
	else
	{
		m_bSameRatio = false;
	}
	UpdateData(FALSE);
	pMainDlg->UpdateDrawing();
}
