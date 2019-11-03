// TextOutPane.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "20151654P5_4fix.h"
#include "TextOutPane.h"


// CTextOutPane

IMPLEMENT_DYNAMIC(CTextOutPane, CDockablePane)

CTextOutPane::CTextOutPane()
{

}

CTextOutPane::~CTextOutPane()
{
}


BEGIN_MESSAGE_MAP(CTextOutPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CTextOutPane �޽��� ó�����Դϴ�.




int CTextOutPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if (!m_ctrlTextOut.Create(IDD_DIALOG_TEXTOUT, this)) {
		TRACE0("���ڿ� ��� �����츦 ������ ���߽��ϴ�. \n");
		return -1;
	}
	m_ctrlTextOut.ShowWindow(SW_SHOW);
	return 0;
}


void CTextOutPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlTextOut.GetSafeHwnd()) {
		m_ctrlTextOut.MoveWindow(0, 0, cx, cy);
		m_ctrlTextOut.SetFocus();
	}
}
