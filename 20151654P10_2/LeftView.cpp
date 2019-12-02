// LeftView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "20151654P10_2.h"
#include "LeftView.h"
#include "MainFrm.h"
#include "20151654P10_2Doc.h"
#include "20151654P10_2View.h"


// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CFormView)

CLeftView::CLeftView()
	: CFormView(IDD_FORMVIEW)
	, m_strDept(_T(""))
	, m_strName(_T(""))
	, m_nSex(0)
{

}

CLeftView::~CLeftView()
{
}

void CLeftView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_DEPT, m_strDept);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
}

BEGIN_MESSAGE_MAP(CLeftView, CFormView)
	ON_COMMAND(IDC_RADIO_MALE, &CLeftView::OnRadioMale)
	ON_COMMAND(IDC_RADIO_FEMALE, &CLeftView::OnRadioFemale)
	ON_BN_CLICKED(IDC_CHECK_READING, &CLeftView::OnClickedCheckReading)
	ON_BN_CLICKED(IDC_CHECK_SPORTS, &CLeftView::OnClickedCheckSports)
	ON_BN_CLICKED(IDC_CHECK_FISHING, &CLeftView::OnClickedCheckFishing)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CLeftView::OnClickedButtonOk)
END_MESSAGE_MAP()


// CLeftView �����Դϴ�.

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftView �޽��� ó�����Դϴ�.


void CLeftView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	((CComboBox*)GetDlgItem(IDC_COMBO_DEPT))->SetCurSel(2);
	((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(1);
	m_nSex = 0;
	m_bHobby[0] = m_bHobby[1] = m_bHobby[2] = FALSE;
}


void CLeftView::OnRadioMale()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSex = 0;
}


void CLeftView::OnRadioFemale()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSex = 1;
}


void CLeftView::OnClickedCheckReading()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bHobby[0] = !m_bHobby[0];
}


void CLeftView::OnClickedCheckSports()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bHobby[1] = !m_bHobby[1];
}


void CLeftView::OnClickedCheckFishing()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bHobby[2] = !m_bHobby[2];
}


void CLeftView::OnClickedButtonOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20151654P10_2Doc* pDoc = (CMy20151654P10_2Doc*)pFrame->GetActiveDocument();

	pDoc->m_strHobby.Empty();

	if (m_strName.IsEmpty()) {
		AfxMessageBox(_T("�̸��� �Է��ϼ���."));
	}
	else {
		pDoc->m_strDept = m_strDept;
		pDoc->m_strName = m_strName;
		if (m_nSex == 0)
			pDoc->m_strSex = _T("����");
		else
			pDoc->m_strSex = _T("����");
		if (m_bHobby[0])
			pDoc->m_strHobby = _T("����");
		if (m_bHobby[1])
			pDoc->m_strHobby = _T("�");
		if (m_bHobby[2])
			pDoc->m_strHobby = _T("����");
	}
	UpdateData(FALSE);
}
