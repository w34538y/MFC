// LeftView.cpp : 구현 파일입니다.
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


// CLeftView 진단입니다.

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


// CLeftView 메시지 처리기입니다.


void CLeftView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	((CComboBox*)GetDlgItem(IDC_COMBO_DEPT))->SetCurSel(2);
	((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(1);
	m_nSex = 0;
	m_bHobby[0] = m_bHobby[1] = m_bHobby[2] = FALSE;
}


void CLeftView::OnRadioMale()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSex = 0;
}


void CLeftView::OnRadioFemale()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSex = 1;
}


void CLeftView::OnClickedCheckReading()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bHobby[0] = !m_bHobby[0];
}


void CLeftView::OnClickedCheckSports()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bHobby[1] = !m_bHobby[1];
}


void CLeftView::OnClickedCheckFishing()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bHobby[2] = !m_bHobby[2];
}


void CLeftView::OnClickedButtonOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20151654P10_2Doc* pDoc = (CMy20151654P10_2Doc*)pFrame->GetActiveDocument();

	pDoc->m_strHobby.Empty();

	if (m_strName.IsEmpty()) {
		AfxMessageBox(_T("이름을 입력하세요."));
	}
	else {
		pDoc->m_strDept = m_strDept;
		pDoc->m_strName = m_strName;
		if (m_nSex == 0)
			pDoc->m_strSex = _T("남자");
		else
			pDoc->m_strSex = _T("여자");
		if (m_bHobby[0])
			pDoc->m_strHobby = _T("독서");
		if (m_bHobby[1])
			pDoc->m_strHobby = _T("운동");
		if (m_bHobby[2])
			pDoc->m_strHobby = _T("낚시");
	}
	UpdateData(FALSE);
}
