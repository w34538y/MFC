// TxtOutPane.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "20151654P5_4.h"
#include "TxtOutPane.h"


// CTxtOutPane

IMPLEMENT_DYNAMIC(CTxtOutPane, CDockablePane)

CTxtOutPane::CTxtOutPane()
{

}

CTxtOutPane::~CTxtOutPane()
{
}


BEGIN_MESSAGE_MAP(CTxtOutPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CTxtOutPane �޽��� ó�����Դϴ�.




int CTxtOutPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if (!m_ctrlTextOut.Create(IDD_DIALOG_TEXTOUT, this){
		TRACE0("���ڿ� ��� �����츦 ������ ���߽��ϴ� \n");
		return -1;
	}
	m_ctrlTextOut.ShowWindow(SW_SHOW);
	return 0;
}


void CTxtOutPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlTextOut.GetSafeHwnd()) {
		m_ctrlTextOut.MoveWindow(0, 0, cx, 0);
		m_ctrlTextOut.SetFocus();
	}
}
