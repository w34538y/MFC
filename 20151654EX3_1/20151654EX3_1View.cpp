
// 20151654EX3_1View.cpp : CMy20151654EX3_1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20151654EX3_1.h"
#endif

#include "20151654EX3_1Doc.h"
#include "20151654EX3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151654EX3_1View

IMPLEMENT_DYNCREATE(CMy20151654EX3_1View, CView)

BEGIN_MESSAGE_MAP(CMy20151654EX3_1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20151654EX3_1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy20151654EX3_1View 생성/소멸

CMy20151654EX3_1View::CMy20151654EX3_1View()
	: m_strStopWatch(_T("00: 00. 00"))
	, m_nCount(0)
	, m_nMinute(0)
	, m_nSecond(0)
	, m_nMSec(0)
	, m_bStopWatchRun(false)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20151654EX3_1View::~CMy20151654EX3_1View()
{
}

BOOL CMy20151654EX3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20151654EX3_1View 그리기

void CMy20151654EX3_1View::OnDraw(CDC* pDC)
{
	CMy20151654EX3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CFont big_font;
	big_font.CreateFont(100, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("굴림체"));
	CClientDC dc(this);

	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strStopWatch, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	int y = 10;
	pDC->TextOut(10, y, m_strRecord[40]);
	y += 20;
	
}


// CMy20151654EX3_1View 인쇄


void CMy20151654EX3_1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20151654EX3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20151654EX3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20151654EX3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy20151654EX3_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20151654EX3_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20151654EX3_1View 진단

#ifdef _DEBUG
void CMy20151654EX3_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654EX3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654EX3_1Doc* CMy20151654EX3_1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654EX3_1Doc)));
	return (CMy20151654EX3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654EX3_1View 메시지 처리기


void CMy20151654EX3_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bStopWatchRun == false) {
		SetTimer(1, 10, NULL);
		m_bStopWatchRun = true;
	}
	if (m_bStopWatchRun == true) {
		KillTimer(0);
		m_bStopWatchRun = false;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy20151654EX3_1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	m_nMSec++;
	if (m_nMSec >= 100) {
		m_nSecond++;
		m_nMSec = 0;
	}
	if (m_nSecond >= 60) {
		m_nMinute++;
		m_nSecond = 0;
	}
	m_strStopWatch.Format(_T("%02d: %02d. %02d"), m_nMinute, m_nSecond, m_nMSec);
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy20151654EX3_1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch(nChar) {
		case VK_SPACE:
			m_strRecord[40] = m_strStopWatch;
			m_nCount++;
	}
	if (m_nCount == 40) {
		if (!m_bStopWatchRun) {
			m_nCount = 0;
		}
	}
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy20151654EX3_1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (!m_bStopWatchRun) {
		if (AfxMessageBox(_T("초기화 하시겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES) {
			m_nCount = 0;
			m_nMinute = 0;
			m_nSecond = 0;
			m_nMSec = 0;
		}
	}
	CView::OnRButtonDown(nFlags, point);
}
