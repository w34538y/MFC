// HobbyCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "20151654E5_1.h"
#include "HobbyCtrl.h"
#include "afxdialogex.h"
#include "20151654E5_1View.h"
#include "MainFrm.h"


// CHobbyCtrl ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CHobbyCtrl, CDialogEx)

CHobbyCtrl::CHobbyCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_strName(_T(""))
	, m_bSex(false)
{

}

CHobbyCtrl::~CHobbyCtrl()
{
}

void CHobbyCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_HOBBY, m_listHobby);
	DDX_Control(pDX, IDC_COMBO_SEX, m_cbSex);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
}


BEGIN_MESSAGE_MAP(CHobbyCtrl, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_SEX, &CHobbyCtrl::OnSelchangeComboSex)
	ON_COMMAND(IDC_RADIO_FEMALE, &CHobbyCtrl::OnRadioFemale)
	ON_COMMAND(IDC_RADIO_MALE, &CHobbyCtrl::OnRadioMale)
	ON_LBN_SELCHANGE(IDC_LIST_HOBBY, &CHobbyCtrl::OnSelchangeListHobby)
	ON_BN_CLICKED(IDC_CHECK_FISHING, &CHobbyCtrl::OnClickedCheckFishing)
	ON_BN_CLICKED(IDC_CHECK_READING, &CHobbyCtrl::OnClickedCheckReading)
	ON_BN_CLICKED(IDC_CHECK_SPORTS, &CHobbyCtrl::OnClickedCheckSports)
	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CHobbyCtrl::OnClickedButtonResult)
END_MESSAGE_MAP()


// CHobbyCtrl �޽��� ó�����Դϴ�.


BOOL CHobbyCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_listHobby.AddString(_T("����"));
	m_listHobby.AddString(_T("����"));
	m_listHobby.AddString(_T("�"));
	m_cbSex.SetCurSel(0);
	SetDlgItemText(IDC_EDIT_NAME, _T(""));
	((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(true);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CHobbyCtrl::OnSelchangeComboSex()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int tmp = m_cbSex.GetCurSel();
	if (tmp == 0){
		((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(true);
		((CButton*)GetDlgItem(IDC_RADIO_FEMALE))->SetCheck(false);
		m_bSex = true;
	}
	else{
		((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(false);
		((CButton*)GetDlgItem(IDC_RADIO_FEMALE))->SetCheck(true);
		m_bSex = false;
	}
}


void CHobbyCtrl::OnRadioFemale()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_cbSex.SetCurSel(1);
	((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(false);
	m_bSex = false;
}


void CHobbyCtrl::OnRadioMale()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_cbSex.SetCurSel(0);
	((CButton*)GetDlgItem(IDC_RADIO_FEMALE))->SetCheck(false);
	m_bSex = true;
}


void CHobbyCtrl::OnSelchangeListHobby()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int tmp = m_listHobby.GetCurSel();
	switch (tmp){
	case 0:
		if (m_bChecked[0]){
			((CButton*)GetDlgItem(IDC_CHECK_READING))->SetCheck(false);
			m_bChecked[0] = false;
		}
		else{
			((CButton*)GetDlgItem(IDC_CHECK_READING))->SetCheck(true);
			m_bChecked[0] = true;
		}
		break;
	case 1:
		if (m_bChecked[1]){
			((CButton*)GetDlgItem(IDC_CHECK_FISHING))->SetCheck(false);
			m_bChecked[1] = false;
		}
		else{
			((CButton*)GetDlgItem(IDC_CHECK_FISHING))->SetCheck(true);
			m_bChecked[1] = true;
		}
		break;
	case 2:
		if (m_bChecked[2]){
			((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->SetCheck(false);
			m_bChecked[2] = false;
		}
		else{
			((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->SetCheck(true);
			m_bChecked[2] = true;
		}
		break;
	}
}


void CHobbyCtrl::OnClickedCheckFishing()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bChecked[1]){
		m_listHobby.SetSel(1, 0);
		((CButton*)GetDlgItem(IDC_CHECK_FISHING))->SetCheck(false);
		m_bChecked[1] = false;
	}
	else{
		m_listHobby.SetSel(1);
		((CButton*)GetDlgItem(IDC_CHECK_FISHING))->SetCheck(true);
		m_bChecked[1] = true;
	}
}


void CHobbyCtrl::OnClickedCheckReading()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bChecked[0]){
		m_listHobby.SetSel(0, 0);
		((CButton*)GetDlgItem(IDC_CHECK_READING))->SetCheck(false);
		m_bChecked[0] = false;
	}
	else{
		m_listHobby.SetSel(0);
		((CButton*)GetDlgItem(IDC_CHECK_READING))->SetCheck(true);
		m_bChecked[0] = true;
	}
}


void CHobbyCtrl::OnClickedCheckSports()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bChecked[2]){
		m_listHobby.SetSel(2, 0);
		((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->SetCheck(false);
		m_bChecked[2] = false;
	}
	else{
		m_listHobby.SetSel(2);
		((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->SetCheck(true);
		m_bChecked[2] = true;
	}
}


void CHobbyCtrl::OnClickedButtonResult()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMy20151654E5_1View *pView = (CMy20151654E5_1View *)pFrame->GetActiveView();
	UpdateData(true);

	pView->m_strName = _T("�̸� : ");
	pView->m_strSex = _T("���� : ");
	pView->m_strHobby = _T("���� ������ ��� :");

	pView->m_strName += m_strName;
	if (m_bSex){
		pView->m_strSex += _T("����");
	}
	else{
		pView->m_strSex += _T("����");
	}
	for (int i = 0; i < 3; i++){
		CString tmp;
		if (m_bChecked[i]){
			m_listHobby.GetText(i, tmp);
			pView->m_strHobby += _T(" ") + tmp;
		}
	}
	pView->Invalidate();
}
