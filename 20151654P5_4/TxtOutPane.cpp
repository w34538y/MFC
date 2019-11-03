// TxtOutPane.cpp : 구현 파일입니다.
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



// CTxtOutPane 메시지 처리기입니다.




int CTxtOutPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if (!m_ctrlTextOut.Create(IDD_DIALOG_TEXTOUT, this){
		TRACE0("문자열 출력 윈도우를 만들지 못했습니다 \n");
		return -1;
	}
	m_ctrlTextOut.ShowWindow(SW_SHOW);
	return 0;
}


void CTxtOutPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_ctrlTextOut.GetSafeHwnd()) {
		m_ctrlTextOut.MoveWindow(0, 0, cx, 0);
		m_ctrlTextOut.SetFocus();
	}
}
