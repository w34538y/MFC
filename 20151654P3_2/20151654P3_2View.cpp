
// 20151654P3_2View.cpp : CMy20151654P3_2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20151654P3_2.h"
#endif

#include "20151654P3_2Doc.h"
#include "20151654P3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151654P3_2View

IMPLEMENT_DYNCREATE(CMy20151654P3_2View, CView)

BEGIN_MESSAGE_MAP(CMy20151654P3_2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_LBUTTONDBLCLK()
//ON_WM_LBUTTONDBLCLK()
ON_WM_CREATE()
ON_WM_DESTROY()
ON_WM_TIMER()
ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy20151654P3_2View 생성/소멸

CMy20151654P3_2View::CMy20151654P3_2View()
	: m_bTimerRun(false)
	, m_bTimerType(true)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20151654P3_2View::~CMy20151654P3_2View()
{
}

BOOL CMy20151654P3_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20151654P3_2View 그리기

void CMy20151654P3_2View::OnDraw(CDC* pDC)
{
	CMy20151654P3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CRect rect;
	GetClientRect(&rect); // 윈도우 클라이언트 영역을 얻는다
	//윈도우의 중앙에 타이머를 출력 
	pDC->DrawText(m_strTimer, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CMy20151654P3_2View 인쇄

BOOL CMy20151654P3_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20151654P3_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20151654P3_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy20151654P3_2View 진단

#ifdef _DEBUG
void CMy20151654P3_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654P3_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654P3_2Doc* CMy20151654P3_2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654P3_2Doc)));
	return (CMy20151654P3_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654P3_2View 메시지 처리기


//void CMy20151654P3_2View::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//
//	CView::OnLButtonDblClk(nFlags, point);
//}


//void CMy20151654P3_2View::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//
//	CView::OnLButtonDblClk(nFlags, point);
//}


int CMy20151654P3_2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	SetTimer(0, 1000, NULL); // wm_timer 호출
	m_bTimerRun = true; // 타이머 동작 on 


	return 0;
}


void CMy20151654P3_2View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	AfxMessageBox(_T("윈도우가 종료되었습니다."), MB_YESNO | MB_ICONWARNING);
}


void CMy20151654P3_2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int hour;
	CString str;
	CTime timer;                    //타이머 변수 선언
	timer = CTime::GetCurrentTime(); //현재 시간을 얻음

	if (m_bTimerType) {
		m_strTimer.Format(_T("현재는 %d년 %d월 %d일 %d시 %d분 %d초"),
			timer.GetYear(), timer.GetMonth(), timer.GetDay(),
			timer.GetHour(), timer.GetMinute(), timer.GetSecond());
	}
	else {
		hour = timer.GetHour();
		if (hour >= 12) {
			str = _T("PM");
			if (hour >= 13)
				hour = hour - 12;
		}
		else {
			str = _T("AM");
		}
		m_strTimer.Format(_T("지금은 %s %d시 %d분 %d초"), str, hour, timer.GetMinute(), timer.GetSecond());
	}
	Invalidate(); // ondraw() 함수 자동호출

	CView::OnTimer(nIDEvent);
}


void CMy20151654P3_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bTimerType) {//현재상태는 년월일시분초
		if (AfxMessageBox(_T("시, 분, 초 형태로 표시하시겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES) {
			m_bTimerType = false; //시분초 형태로
		}
			
	}
	else {
		if (AfxMessageBox(_T("년, 월, 일  형태로 표시하시겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES) {
			m_bTimerType = true; //년월일 형태로s
		}
			
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy20151654P3_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bTimerRun == false) {
		if (AfxMessageBox(_T("디지털 시계를 동작시키겠습니까? "), MB_YESNO | MB_ICONQUESTION) == IDYES) {
			SetTimer(0, 1000, NULL);
			m_bTimerRun = true;

		}
	}
	else {
		if (AfxMessageBox(_T("정말로 디지털 시계를 멈추시겠습니까? "), MB_YESNO | MB_ICONQUESTION) == IDYES) {
			KillTimer(0); //타이머 해제
			m_bTimerRun = false;
		}
	}

	CView::OnRButtonDown(nFlags, point);
}
