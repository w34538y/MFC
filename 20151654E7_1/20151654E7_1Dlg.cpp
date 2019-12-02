
// 20151654E7_1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "20151654E7_1.h"
#include "20151654E7_1Dlg.h"
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


// CMy20151654E7_1Dlg ��ȭ ����



CMy20151654E7_1Dlg::CMy20151654E7_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY20151654E7_1_DIALOG, pParent)
	, m_CbRate(_T(""))
	, m_EdYear(_T(""))
	, m_EdTitle(_T(""))
	, m_nCount(0)
	, m_nSelectedItem(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy20151654E7_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_CONTROL, m_treeCtrl);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_listCtrl);
	DDX_CBString(pDX, IDC_COMBO_RATE, m_CbRate);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_EdYear);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_EdTitle);
}

BEGIN_MESSAGE_MAP(CMy20151654E7_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_CONTROL, &CMy20151654E7_1Dlg::OnTvnSelchangedTreeControl)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CONTROL, &CMy20151654E7_1Dlg::OnItemchangedListControl)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_CONTROL, &CMy20151654E7_1Dlg::OnSelchangedTreeControl)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMy20151654E7_1Dlg::OnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CMy20151654E7_1Dlg::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CMy20151654E7_1Dlg::OnClickedButtonUpdate)
	ON_CBN_SELCHANGE(IDC_COMBO_RATE, &CMy20151654E7_1Dlg::OnSelchangeComboRate)
END_MESSAGE_MAP()


// CMy20151654E7_1Dlg �޽��� ó����

BOOL CMy20151654E7_1Dlg::OnInitDialog()
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
	m_hRoot = m_treeCtrl.InsertItem(_T("����"), 0, TVI_LAST);
	m_hMovie = m_treeCtrl.InsertItem(_T("��ȭ"), m_hRoot, TVI_LAST);
	m_hDrama = m_treeCtrl.InsertItem(_T("���"), m_hRoot, TVI_LAST);

	LPWSTR list[3] = { _T("��ǰ��"),_T("���۳⵵"),_T("���") };
	int nWidth[3] = { 190,80,150 };

	for (int i = 0; i < 3; i++) {
		m_listCtrl.InsertColumn(i, list[i], LVCFMT_CENTER, nWidth[i]);
	}

	m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_nSelectedItem = -1;
	m_treeCtrl.Expand(m_hRoot, TVE_EXPAND);
	m_listCtrl.DeleteAllItems();
	UpdateData(false);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMy20151654E7_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy20151654E7_1Dlg::OnPaint()
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
HCURSOR CMy20151654E7_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CMy20151654E7_1Dlg::OnTvnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
//	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//	*pResult = 0;
//}


void CMy20151654E7_1Dlg::OnItemchangedListControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nSelectedItem = pNMLV->iItem;

	m_EdTitle = m_listCtrl.GetItemText(m_nSelectedItem, 0);
	m_EdYear = m_listCtrl.GetItemText(m_nSelectedItem, 1);
	m_CbRate = m_listCtrl.GetItemText(m_nSelectedItem, 2);

	UpdateData(false);

	*pResult = 0;
}


void CMy20151654E7_1Dlg::OnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int tm = -1, idxT, idxD, idxM;;
	m_hSelectedNode = pNMTreeView->itemNew.hItem;
	m_EdTitle.Empty();
	m_EdYear.Empty();
	m_CbRate.Empty();
	UpdateData(FALSE);

	m_listCtrl.DeleteAllItems();

	if (m_hSelectedNode == m_hRoot) {
		idxT = 0;
		for (int i = 0; i < m_nCount; i++) {
			if (!m_productInfo[i].strTitle.IsEmpty()) {
				m_listCtrl.InsertItem(idxT, m_productInfo[i].strTitle);
				m_listCtrl.SetItem(idxT, 1, LVIF_TEXT, m_productInfo[i].strYear, NULL, NULL, NULL, NULL);
				m_listCtrl.SetItem(idxT, 2, LVIF_TEXT, m_productInfo[i].strGrade, NULL, NULL, NULL, NULL);
				++idxT;
			}
		}
	}
	if (m_hSelectedNode == m_hMovie) {
		idxM = 0;
		for (int i = 0; i < m_nCount; i++) {
			if (m_productInfo[i].strCategory == m_treeCtrl.GetItemText(m_hMovie)) {
				m_listCtrl.InsertItem(idxM, m_productInfo[i].strTitle);
				m_listCtrl.SetItem(idxM, 1, LVIF_TEXT, m_productInfo[i].strYear, NULL, NULL, NULL, NULL);
				m_listCtrl.SetItem(idxM, 2, LVIF_TEXT, m_productInfo[i].strGrade, NULL, NULL, NULL, NULL);
				++idxM;
			}
		}
	}
	if (m_hSelectedNode == m_hDrama) {
		idxD = 0;
		for (int i = 0; i < m_nCount; i++) {
			if (m_productInfo[i].strCategory == m_treeCtrl.GetItemText(m_hDrama)) {
				m_listCtrl.InsertItem(idxD, m_productInfo[i].strTitle);
				m_listCtrl.SetItem(idxD, 1, LVIF_TEXT, m_productInfo[i].strYear, NULL, NULL, NULL, NULL);
				m_listCtrl.SetItem(idxD, 2, LVIF_TEXT, m_productInfo[i].strGrade, NULL, NULL, NULL, NULL);
				++idxD;
			}
		}
	}

	*pResult = 0;
}


void CMy20151654E7_1Dlg::OnClickedButtonDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
	if (AfxMessageBox(_T("������ �����Ͻðڽ��ϱ�? "), MB_YESNO | MB_ICONQUESTION) == IDYES) {
		if (m_nSelectedItem >= 0) {
			CString t;
			t = m_listCtrl.GetItemText(m_nSelectedItem, 0);
			m_listCtrl.DeleteItem(m_nSelectedItem);

			for (int i = 0; i < m_nCount; i++) {
				if (m_productInfo[i].strTitle == t) {
					m_productInfo[i].strCategory = _T("");
					m_productInfo[i].strTitle = _T("");
				}
			}
			m_EdTitle.Empty();
			m_EdYear.Empty();
			m_CbRate.Empty();
		}
		else {
			AfxMessageBox(_T("�������� �������� �ʾҽ��ϴ�."));
		}
	}
	UpdateData(false);
}


void CMy20151654E7_1Dlg::OnClickedButtonInsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	bool tf = true;
	int idxD = 0, idxM = 0;
	UpdateData(true);
	if (!m_EdTitle.IsEmpty() && !m_EdYear.IsEmpty() && !m_CbRate.IsEmpty()) {
		if (m_hSelectedNode == m_hRoot) {
			AfxMessageBox(_T("��ǰ �帣�� �������ּ���."));
			tf = false;
		}

		for (int i = 0; i < m_nCount; i++) {
			if (m_EdTitle == m_productInfo[i].strTitle) {
				AfxMessageBox(_T("�ߺ��� ��ǰ�� �ֽ��ϴ�."));
				tf = false;
			}
		}
		if (tf == true) {
			m_productInfo[m_nCount].strCategory = m_treeCtrl.GetItemText(m_hSelectedNode);
			m_productInfo[m_nCount].strTitle = m_EdTitle;
			m_productInfo[m_nCount].strYear = m_EdYear;
			m_productInfo[m_nCount].strGrade = m_CbRate;

			if (m_treeCtrl.GetItemText(m_hSelectedNode) == m_treeCtrl.GetItemText(m_hDrama)) {
				m_listCtrl.InsertItem(idxD, m_productInfo[m_nCount].strTitle);
				m_listCtrl.SetItem(idxD, 1, LVIF_TEXT, m_productInfo[m_nCount].strYear, NULL, NULL, NULL, NULL);
				m_listCtrl.SetItem(idxD, 2, LVIF_TEXT, m_productInfo[m_nCount].strGrade, NULL, NULL, NULL, NULL);
				++m_nCount;
				++idxD;
			}
			else if (m_treeCtrl.GetItemText(m_hSelectedNode) == m_treeCtrl.GetItemText(m_hMovie)) {
				m_listCtrl.InsertItem(idxM, m_productInfo[m_nCount].strTitle);
				m_listCtrl.SetItem(idxM, 1, LVIF_TEXT, m_productInfo[m_nCount].strYear, NULL, NULL, NULL, NULL);
				m_listCtrl.SetItem(idxM, 2, LVIF_TEXT, m_productInfo[m_nCount].strGrade, NULL, NULL, NULL, NULL);
				++m_nCount;
				++idxM;
			}
		}
		m_EdTitle.Empty();
		m_EdYear.Empty();
		m_CbRate.Empty();

		UpdateData(false);
	}
}


void CMy20151654E7_1Dlg::OnClickedButtonUpdate()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int tm = -1;
	bool tf = true;
	UpdateData(true);
	for (int i = 0; i < m_nCount; i++) {
		if (m_listCtrl.GetItemText(m_nSelectedItem, 0) == m_productInfo[i].strTitle) {
			tm = i;
		}
		if ((m_EdTitle == m_productInfo[i].strTitle) && !(tm == i)) {
			AfxMessageBox(_T("�ߺ��� ��ǰ�� �ֽ��ϴ�."));
			tf = false;
		}
	}
	if (tf == true) {
		m_productInfo[tm].strCategory = m_treeCtrl.GetItemText(m_hSelectedNode);
		m_productInfo[tm].strTitle = m_EdTitle;
		m_productInfo[tm].strYear = m_EdYear;
		m_productInfo[tm].strGrade = m_CbRate;

		m_listCtrl.SetItem(tm, 0, LVIF_TEXT, m_productInfo[tm].strTitle, 0, 0, 0, 0);
		m_listCtrl.SetItem(tm, 1, LVIF_TEXT, m_productInfo[tm].strYear, 0, 0, 0, 0);
		m_listCtrl.SetItem(tm, 2, LVIF_TEXT, m_productInfo[tm].strGrade, 0, 0, 0, 0);

		m_EdTitle.Empty();
		m_EdYear.Empty();
		m_CbRate.Empty();
	}

	UpdateData(false);
}



void CMy20151654E7_1Dlg::OnSelchangeComboRate()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	((CComboBox*)GetDlgItem(IDC_COMBO_RATE))->GetLBText(((CComboBox*)GetDlgItem(IDC_COMBO_RATE))->GetCurSel(), m_CbRate);
}
