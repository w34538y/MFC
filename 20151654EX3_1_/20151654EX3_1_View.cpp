
// 20151654EX3_1_View.cpp : CMy20151654EX3_1_View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20151654EX3_1_.h"
#endif

#include "20151654EX3_1_Doc.h"
#include "20151654EX3_1_View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151654EX3_1_View

IMPLEMENT_DYNCREATE(CMy20151654EX3_1_View, CView)

BEGIN_MESSAGE_MAP(CMy20151654EX3_1_View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy20151654EX3_1_View 생성/소멸

CMy20151654EX3_1_View::CMy20151654EX3_1_View()
	: m_strStopWatch(_T("00: 00. 00"))
	, m_nCount(0)
	, m_nMinute(0)
	, m_nSecond(0)
	, m_nMSec(0)
	, m_bStopWatchRun(false)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20151654EX3_1_View::~CMy20151654EX3_1_View()
{
}

BOOL CMy20151654EX3_1_View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20151654EX3_1_View 그리기

void CMy20151654EX3_1_View::OnDraw(CDC* pDC)
{
	CMy20151654EX3_1_Doc* pDoc = GetDocument();
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
	for (int i = 0; i < m_nCount; i++)
	{
		pDC->TextOut(10, 10 + (i * 20), m_strRecord[i]);
	}
}


// CMy20151654EX3_1_View 인쇄

BOOL CMy20151654EX3_1_View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20151654EX3_1_View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20151654EX3_1_View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy20151654EX3_1_View 진단

#ifdef _DEBUG
void CMy20151654EX3_1_View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654EX3_1_View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654EX3_1_Doc* CMy20151654EX3_1_View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654EX3_1_Doc)));
	return (CMy20151654EX3_1_Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654EX3_1_View 메시지 처리기


void CMy20151654EX3_1_View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (!m_bStopWatchRun) {
		SetTimer(0, 10, NULL);
		m_bStopWatchRun = true;
	}
	else{
		KillTimer(0);		
		m_bStopWatchRun = false;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy20151654EX3_1_View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (!m_bStopWatchRun) {
		if (AfxMessageBox(_T("초기화 하시겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES) {
			KillTimer(0);
			m_strStopWatch = _T("00: 00. 00");
			m_nCount = 0;
			m_nMinute = 0;
			m_nSecond = 0;
			m_nMSec = 0;
			for (int i = 0; i < 40; i++)
			{
				m_strRecord[i] = _T("");
			}
		}
	}
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


void CMy20151654EX3_1_View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bStopWatchRun)
	{
		if (nChar == VK_SPACE)
		{
			if (m_nCount == 40)
			{
				for (int i = 0; i < 40; i++)
				{
					m_strRecord[i] = _T("");
					m_nCount = 0;
				}
			}
			m_strRecord[m_nCount] = m_strStopWatch;
			m_nCount++;
		}
	}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy20151654EX3_1_View::OnTimer(UINT_PTR nIDEvent)
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
