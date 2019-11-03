// HoobyCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "5_1.h"
#include "HoobyCtrl.h"
#include "afxdialogex.h"
#include "5_1View.h"
#include "MainFrm.h"


// CHoobyCtrl 대화 상자입니다.

IMPLEMENT_DYNAMIC(CHoobyCtrl, CDialogEx)

CHoobyCtrl::CHoobyCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_strName(_T(""))
{

}

CHoobyCtrl::~CHoobyCtrl()
{
}

void CHoobyCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_HOBBY, m_listHobby);
	DDX_Control(pDX, IDC_COMBO_SEX, m_cbSex);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
}


BEGIN_MESSAGE_MAP(CHoobyCtrl, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_SEX, &CHoobyCtrl::OnSelchangeComboSex)
	ON_COMMAND(IDC_RADIO_MALE, &CHoobyCtrl::OnRadioMale)
	ON_COMMAND(IDC_RADIO_FEMALE, &CHoobyCtrl::OnRadioFemale)
	ON_LBN_SELCHANGE(IDC_LIST_HOBBY, &CHoobyCtrl::OnSelchangeListHobby)
	ON_BN_CLICKED(IDC_CHECK_FISHING, &CHoobyCtrl::OnClickedCheckFishing)
	ON_BN_CLICKED(IDC_CHECK_READING, &CHoobyCtrl::OnClickedCheckReading)
	ON_BN_CLICKED(IDC_CHECK_SPORTS, &CHoobyCtrl::OnClickedCheckSports)
	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CHoobyCtrl::OnClickedButtonResult)
END_MESSAGE_MAP()


// CHoobyCtrl 메시지 처리기입니다.


BOOL CHoobyCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_listHobby.AddString(_T("독서"));
	m_listHobby.AddString(_T("낚시"));
	m_listHobby.AddString(_T("운동"));
	m_cbSex.SetCurSel(0);
	SetDlgItemText(IDC_EDIT_NAME, _T(""));
	((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(true);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CHoobyCtrl::OnSelchangeComboSex()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int tmp = m_cbSex.GetCurSel();
	if (tmp == 0) {
		((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(true);
		((CButton*)GetDlgItem(IDC_RADIO_FEMALE))->SetCheck(false);
		m_bSex = true;
	}
	else {
		((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(false);
		((CButton*)GetDlgItem(IDC_RADIO_FEMALE))->SetCheck(true);
		m_bSex = false;
	}
}


void CHoobyCtrl::OnRadioMale()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_cbSex.SetCurSel(0);
	((CButton*)GetDlgItem(IDC_RADIO_FEMALE))->SetCheck(false);
	m_bSex = true;
}


void CHoobyCtrl::OnRadioFemale()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_cbSex.SetCurSel(1);
	((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(false);
	m_bSex = false;
}


void CHoobyCtrl::OnSelchangeListHobby()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int tmp = m_listHobby.GetCurSel();
	switch (tmp) {
	case 0:
		if (m_bChecked[0]) {
			((CButton*)GetDlgItem(IDC_CHECK_READING))->SetCheck(false);
			m_bChecked[0] = false;
		}
		else {
			((CButton*)GetDlgItem(IDC_CHECK_READING))->SetCheck(true);
			m_bChecked[0] = true;
		}
		break;
	case 1:
		if (m_bChecked[1]) {
			((CButton*)GetDlgItem(IDC_CHECK_FISHING))->SetCheck(false);
			m_bChecked[1] = false;
		}
		else {
			((CButton*)GetDlgItem(IDC_CHECK_FISHING))->SetCheck(true);
			m_bChecked[1] = true;
		}
		break;
	case 2:
		if (m_bChecked[2]) {
			((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->SetCheck(false);
			m_bChecked[2] = false;
		}
		else {
			((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->SetCheck(true);
			m_bChecked[2] = true;
		}
		break;
	}
}


void CHoobyCtrl::OnClickedCheckFishing()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[1]) {
		m_listHobby.SetSel(1, 0);
		((CButton*)GetDlgItem(IDC_CHECK_FISHING))->SetCheck(false);
		m_bChecked[1] = false;
	}
	else {
		m_listHobby.SetSel(1);
		((CButton*)GetDlgItem(IDC_CHECK_FISHING))->SetCheck(true);
		m_bChecked[1] = true;
	}
}


void CHoobyCtrl::OnClickedCheckReading()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[0]) {
		m_listHobby.SetSel(0, 0);
		((CButton*)GetDlgItem(IDC_CHECK_READING))->SetCheck(false);
		m_bChecked[0] = false;
	}
	else {
		m_listHobby.SetSel(0);
		((CButton*)GetDlgItem(IDC_CHECK_READING))->SetCheck(true);
		m_bChecked[0] = true;
	}
}


void CHoobyCtrl::OnClickedCheckSports()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[2]) {
		m_listHobby.SetSel(2, 0);
		((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->SetCheck(false);
		m_bChecked[2] = false;
	}
	else {
		m_listHobby.SetSel(2);
		((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->SetCheck(true);
		m_bChecked[2] = true;
	}
}


void CHoobyCtrl::OnClickedButtonResult()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMy5_1View *pView = (CMy5_1View *)pFrame->GetActiveView();
	UpdateData(true);

	pView->m_strName = _T("이름 : ");
	pView->m_strSex = _T("성별 : ");
	pView->m_strHobby = _T("내가 선택한 취미 :");

	pView->m_strName += m_strName;
	if (m_bSex) {
		pView->m_strSex += _T("남자");
	}
	else {
		pView->m_strSex += _T("여자");
	}
	for (int i = 0; i < 3; i++) {
		CString tmp;
		if (m_bChecked[i]) {
			m_listHobby.GetText(i, tmp);
			pView->m_strHobby += _T(" ") + tmp;
		}
	}
	pView->Invalidate();
}
