
// 20151654P5_1_2_3View.cpp : CMy20151654P5_1_2_3View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20151654P5_1_2_3.h"
#endif

#include "20151654P5_1_2_3Doc.h"
#include "20151654P5_1_2_3View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151654P5_1_2_3View

IMPLEMENT_DYNCREATE(CMy20151654P5_1_2_3View, CView)

BEGIN_MESSAGE_MAP(CMy20151654P5_1_2_3View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20151654P5_1_2_3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_LINE, &CMy20151654P5_1_2_3View::OnLine)
	ON_COMMAND(ID_ELLIPSE, &CMy20151654P5_1_2_3View::OnEllipse)
	ON_COMMAND(ID_POLYGON, &CMy20151654P5_1_2_3View::OnPolygon)
	ON_COMMAND(ID_LINE_COLOR, &CMy20151654P5_1_2_3View::OnLineColor)
	ON_COMMAND(ID_FACE_COLOR, &CMy20151654P5_1_2_3View::OnFaceColor)
	ON_COMMAND(ID_BDIAGONAL, &CMy20151654P5_1_2_3View::OnBdiagonal)
	ON_COMMAND(ID_CROSS, &CMy20151654P5_1_2_3View::OnCross)
	ON_COMMAND(ID_VERTICAL, &CMy20151654P5_1_2_3View::OnVertical)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CMy20151654P5_1_2_3View::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_ELLIPSE, &CMy20151654P5_1_2_3View::OnUpdateEllipse)
	ON_UPDATE_COMMAND_UI(ID_POLYGON, &CMy20151654P5_1_2_3View::OnUpdatePolygon)
	ON_WM_MOUSEMOVE()
//	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy20151654P5_1_2_3View 생성/소멸

CMy20151654P5_1_2_3View::CMy20151654P5_1_2_3View()
	: m_nDrawMode(0)
	, m_nHAtchStyle(0)
	, m_ptStart(0)
	, m_ptPrev(0)
	, m_bFirst(false)
	, m_bLButtonDown(false)
	, m_bContextMenu(false)
	, m_bHatch(false)
	, m_nCount(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_nDrawMode = LINE_MODE;
	m_bContextMenu = true;
	m_bFirst = true;
	m_bLButtonDown = false;
	m_nCount = 0;
	for (int i = 0; i < 50; i++)
		m_ptData[i] = 0;
	m_bHatch = false;
	m_nHAtchStyle = HS_CROSS;
	m_colorPen = RGB(0, 0, 0);
	m_colorBrush = RGB(255, 255, 255);


}

CMy20151654P5_1_2_3View::~CMy20151654P5_1_2_3View()
{
}

BOOL CMy20151654P5_1_2_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20151654P5_1_2_3View 그리기

void CMy20151654P5_1_2_3View::OnDraw(CDC* pDC)
{
	CMy20151654P5_1_2_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CPen pen, *oldpen;
	pen.CreatePen(PS_SOLID, 1, m_colorPen);
	oldpen = pDC->SelectObject(&pen);
	pDC->SetROP2(R2_COPYPEN);
	CBrush brush, *oldbrush;
	if (m_bHatch)
		brush.CreateHatchBrush(m_nHAtchStyle, m_colorBrush);
	else
		brush.CreateSolidBrush(m_colorBrush);
	oldbrush = pDC->SelectObject(&brush);

	switch (m_nDrawMode) {
	case LINE_MODE:
		pDC->MoveTo(m_ptStart);
		pDC->LineTo(m_ptPrev);
		break;
	case ELLIPSE_MODE:
		pDC->Ellipse(m_ptStart.x, m_ptStart.y, m_ptPrev.x, m_ptPrev.y);
		break;
	case POLYGON_MODE:
		pDC->Polygon(m_ptData, m_nCount);
		break;
	}
	pDC->SelectObject(oldpen);
	pDC->SelectObject(oldbrush);
	pen.DeleteObject();
	brush.DeleteObject();
}


// CMy20151654P5_1_2_3View 인쇄


void CMy20151654P5_1_2_3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20151654P5_1_2_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20151654P5_1_2_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20151654P5_1_2_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy20151654P5_1_2_3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20151654P5_1_2_3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	if (m_bContextMenu == true) {
		theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
	}
	m_bContextMenu = true;
#endif
}


// CMy20151654P5_1_2_3View 진단

#ifdef _DEBUG
void CMy20151654P5_1_2_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654P5_1_2_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654P5_1_2_3Doc* CMy20151654P5_1_2_3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654P5_1_2_3Doc)));
	return (CMy20151654P5_1_2_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654P5_1_2_3View 메시지 처리기


void CMy20151654P5_1_2_3View::OnLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = LINE_MODE;

	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();

	pFrame->m_wndStatusBar.SetWindowText(_T("직선 그리기"));
}


void CMy20151654P5_1_2_3View::OnEllipse()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = ELLIPSE_MODE;

	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();

	pFrame->m_wndStatusBar.SetWindowText(_T("원 그리기"));
}


void CMy20151654P5_1_2_3View::OnPolygon()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = POLYGON_MODE;

	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();

	pFrame->m_wndStatusBar.SetWindowText(_T("다각형 그리기"));
}


void CMy20151654P5_1_2_3View::OnLineColor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog dlgColor;
	if (dlgColor.DoModal() == IDOK) {
		m_colorPen = dlgColor.GetColor();
	}
	Invalidate(true);
}


void CMy20151654P5_1_2_3View::OnFaceColor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog dlgColor;
	if (dlgColor.DoModal() == IDOK) {
		m_colorBrush = dlgColor.GetColor();
	}
	m_bHatch = false;
	Invalidate(true);
	
}


void CMy20151654P5_1_2_3View::OnBdiagonal()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nHAtchStyle = HS_BDIAGONAL;
	m_bHatch = true;
	Invalidate(true);
}


void CMy20151654P5_1_2_3View::OnCross()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nHAtchStyle = HS_CROSS;
	m_bHatch = true;
	Invalidate(true);
}


void CMy20151654P5_1_2_3View::OnVertical()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nHAtchStyle = HS_VERTICAL;
	m_bHatch = true;
	Invalidate(true);
}


void CMy20151654P5_1_2_3View::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_nDrawMode == LINE_MODE ? 1 : 0);
}



void CMy20151654P5_1_2_3View::OnUpdateEllipse(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_nDrawMode == ELLIPSE_MODE ? 1 : 0);
}


void CMy20151654P5_1_2_3View::OnUpdatePolygon(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_nDrawMode == POLYGON_MODE ? 1 : 0);
}


void CMy20151654P5_1_2_3View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CPen pen, *oldpen;
	pen.CreatePen(PS_SOLID, 1, m_colorPen);
	oldpen = dc.SelectObject(&pen);

	dc.SetROP2(R2_NOTXORPEN);

	CBrush brush, *oldbrush;
	if (m_bHatch)
		brush.CreateHatchBrush(m_nHAtchStyle, m_colorBrush);
	else
		brush.CreateSolidBrush(m_colorBrush);
	oldbrush = dc.SelectObject(&brush);

	switch (m_nDrawMode) {
	case LINE_MODE:
		if (m_bLButtonDown) {
			dc.MoveTo(m_ptStart);
			dc.LineTo(m_ptPrev);
			dc.MoveTo(m_ptStart);
			dc.LineTo(point);
			m_ptPrev = point;
		}
		break;

	case ELLIPSE_MODE:
		if (m_bLButtonDown) {
			dc.Ellipse(m_ptStart.x, m_ptStart.y, m_ptPrev.x, m_ptPrev.y);
			dc.Ellipse(m_ptStart.x, m_ptStart.y, point.x, point.y);
			m_ptPrev = point;
		}
		break;

	case POLYGON_MODE:
		if (!m_bFirst) {
			dc.MoveTo(m_ptStart);
			dc.LineTo(m_ptPrev);
			dc.MoveTo(m_ptStart);
			dc.LineTo(point);
			m_ptPrev = point;
		}
		break;

	}
	dc.SelectObject(oldpen);
	dc.SelectObject(oldbrush);
	pen.DeleteObject();
	brush.DeleteObject();

	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();

	CString strPoint;
	strPoint.Format(_T("마우스 위치 x: %d, y: %d"), point.x, point.y);

	pFrame->m_wndStatusBar.SetPaneText(1, strPoint);
	CView::OnMouseMove(nFlags, point);
}


//void CMy20151654P5_1_2_3View::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//
//	CView::OnLButtonDblClk(nFlags, point);
//}


void CMy20151654P5_1_2_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bFirst) {
		m_ptStart = m_ptPrev = 0;
		m_bLButtonDown = false;
		m_bFirst = true;
		m_nCount = 0;
		for (int i = 0; i < 50; i++)
			m_ptData[i] = 0;
		Invalidate();
	}

	switch (m_nDrawMode) {
	case LINE_MODE:
	case ELLIPSE_MODE:
		m_bLButtonDown = true;
		m_ptStart = m_ptPrev = point;
		m_bFirst = false;
		break;
	case POLYGON_MODE:
		if (m_bFirst == true)
			m_bFirst = false;
		m_ptStart = m_ptPrev = point;
		m_ptData[m_nCount] = point;
		m_nCount++;
		break;
	}

	RECT rectClient;
	SetCapture();
	GetClientRect(&rectClient);
	ClientToScreen(&rectClient);
	::ClipCursor(&rectClient);

	CView::OnLButtonDown(nFlags, point);
}


void CMy20151654P5_1_2_3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bLButtonDown) {
		if (m_nDrawMode == LINE_MODE || m_nDrawMode == ELLIPSE_MODE) {
			m_bLButtonDown = false;
			m_bFirst = true;
			ReleaseCapture();
			::ClipCursor(NULL);
			Invalidate(true);
		}
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMy20151654P5_1_2_3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_nDrawMode == POLYGON_MODE) {
		if (!m_bFirst) {
			m_bContextMenu = FALSE;
			m_ptData[m_nCount] = point;
			m_nCount++;
			m_bFirst = true;
			ReleaseCapture();
			::ClipCursor(NULL);
			Invalidate(TRUE);
		}
	}

	CView::OnRButtonDown(nFlags, point);
}
