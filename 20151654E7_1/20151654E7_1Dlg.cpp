
// 20151654E7_1Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "20151654E7_1.h"
#include "20151654E7_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMy20151654E7_1Dlg 대화 상자



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


// CMy20151654E7_1Dlg 메시지 처리기

BOOL CMy20151654E7_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_hRoot = m_treeCtrl.InsertItem(_T("영상물"), 0, TVI_LAST);
	m_hMovie = m_treeCtrl.InsertItem(_T("영화"), m_hRoot, TVI_LAST);
	m_hDrama = m_treeCtrl.InsertItem(_T("드라마"), m_hRoot, TVI_LAST);

	LPWSTR list[3] = { _T("작품명"),_T("제작년도"),_T("등급") };
	int nWidth[3] = { 190,80,150 };

	for (int i = 0; i < 3; i++) {
		m_listCtrl.InsertColumn(i, list[i], LVCFMT_CENTER, nWidth[i]);
	}

	m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_nSelectedItem = -1;
	m_treeCtrl.Expand(m_hRoot, TVE_EXPAND);
	m_listCtrl.DeleteAllItems();
	UpdateData(false);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMy20151654E7_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMy20151654E7_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CMy20151654E7_1Dlg::OnTvnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	*pResult = 0;
//}


void CMy20151654E7_1Dlg::OnItemchangedListControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	if (AfxMessageBox(_T("정말로 삭제하시겠습니까? "), MB_YESNO | MB_ICONQUESTION) == IDYES) {
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
			AfxMessageBox(_T("아이템을 선택하지 않았습니다."));
		}
	}
	UpdateData(false);
}


void CMy20151654E7_1Dlg::OnClickedButtonInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	bool tf = true;
	int idxD = 0, idxM = 0;
	UpdateData(true);
	if (!m_EdTitle.IsEmpty() && !m_EdYear.IsEmpty() && !m_CbRate.IsEmpty()) {
		if (m_hSelectedNode == m_hRoot) {
			AfxMessageBox(_T("작품 장르를 선택해주세요."));
			tf = false;
		}

		for (int i = 0; i < m_nCount; i++) {
			if (m_EdTitle == m_productInfo[i].strTitle) {
				AfxMessageBox(_T("중복된 작품이 있습니다."));
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int tm = -1;
	bool tf = true;
	UpdateData(true);
	for (int i = 0; i < m_nCount; i++) {
		if (m_listCtrl.GetItemText(m_nSelectedItem, 0) == m_productInfo[i].strTitle) {
			tm = i;
		}
		if ((m_EdTitle == m_productInfo[i].strTitle) && !(tm == i)) {
			AfxMessageBox(_T("중복된 작품이 있습니다."));
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CComboBox*)GetDlgItem(IDC_COMBO_RATE))->GetLBText(((CComboBox*)GetDlgItem(IDC_COMBO_RATE))->GetCurSel(), m_CbRate);
}
