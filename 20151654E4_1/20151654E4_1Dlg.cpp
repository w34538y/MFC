
// 20151654E4_1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "20151654E4_1.h"
#include "20151654E4_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy20151654E4_1Dlg ��ȭ ����



CMy20151654E4_1Dlg::CMy20151654E4_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY20151654E4_1_DIALOG, pParent)
	, m_strResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy20151654E4_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_LEFT, m_listLeft);
	DDX_Control(pDX, IDC_LIST_RIGHT, m_listRight);
	DDX_Control(pDX, IDC_COMBO_MOVE, m_cbMove);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_strResult);
}

BEGIN_MESSAGE_MAP(CMy20151654E4_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_MOVE, &CMy20151654E4_1Dlg::OnCbnSelchangeComboMove)
	ON_BN_CLICKED(IDC_BUTTON_PURCHASE, &CMy20151654E4_1Dlg::OnClickedButtonPurchase)
END_MESSAGE_MAP()


// CMy20151654E4_1Dlg �޽��� ó����

BOOL CMy20151654E4_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_listLeft.AddString(_T("������"));
	m_listLeft.AddString(_T("����"));
	m_listLeft.AddString(_T("���"));
	m_listLeft.AddString(_T("�ٳ���"));
	m_listLeft.AddString(_T("����"));
	m_listLeft.AddString(_T("����"));
	m_listLeft.AddString(_T("���⸧"));
	m_listLeft.AddString(_T("����"));
	m_listLeft.AddString(_T("���"));
	m_listLeft.AddString(_T("����"));

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMy20151654E4_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMy20151654E4_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMy20151654E4_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy20151654E4_1Dlg::OnCbnSelchangeComboMove()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString listText;
	int sellNo;
	if (m_cbMove.GetCurSel() == 1)
	{
		if (!(m_listLeft.GetCurSel() == -1))
		{
			sellNo = m_listLeft.GetCurSel();
			m_listLeft.GetText(sellNo, listText);
			m_listLeft.DeleteString(sellNo);
			m_listRight.AddString(listText);
			m_listLeft.SetCurSel(sellNo);
		}
		else
		{
			AfxMessageBox(_T("���� ����Ʈ �ڽ����� �̵��� �������� �����ϼ���."), MB_ICONWARNING);
		}
	}
	else if (m_cbMove.GetCurSel() == 0)
	{
		if (!(m_listRight.GetCurSel() == -1))
		{
			sellNo = m_listRight.GetCurSel();
			m_listRight.GetText(sellNo, listText);
			m_listRight.DeleteString(sellNo);
			m_listLeft.AddString(listText);
			m_listRight.SetCurSel(sellNo);
		}
		else
		{
			AfxMessageBox(_T("������ ����Ʈ �ڽ����� �̵��� �������� �����ϼ���."), MB_ICONWARNING);
		}
	}
}


void CMy20151654E4_1Dlg::OnClickedButtonPurchase()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_strResult = _T("");
	CString tmp;
	for (int i = 0; i < m_listRight.GetCount(); i++)
	{
		m_listRight.GetText(i, tmp);
		m_strResult += tmp + _T("\r\n");
	}
	UpdateData(false);
}
