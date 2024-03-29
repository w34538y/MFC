
// 20151654P5_4fixView.cpp : CMy20151654P5_4fixView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20151654P5_4fix.h"
#endif

#include "20151654P5_4fixDoc.h"
#include "20151654P5_4fixView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151654P5_4fixView

IMPLEMENT_DYNCREATE(CMy20151654P5_4fixView, CView)

BEGIN_MESSAGE_MAP(CMy20151654P5_4fixView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20151654P5_4fixView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMy20151654P5_4fixView 생성/소멸

CMy20151654P5_4fixView::CMy20151654P5_4fixView()
	: m_strOutput(_T(""))
	, m_nTextWidth(0)
	, m_nTextHeight(0)
	, m_ptPosition(0)
	, m_bFont(false)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20151654P5_4fixView::~CMy20151654P5_4fixView()
{
}

BOOL CMy20151654P5_4fixView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20151654P5_4fixView 그리기

void CMy20151654P5_4fixView::OnDraw(CDC* pDC)
{
	CMy20151654P5_4fixDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CFont *oldFont, *currentFont, newFont;

	if (m_bFont == TRUE) {
		newFont.CreateFontIndirect(&m_logFont);
		oldFont = pDC->SelectObject(&newFont);
	}
	else {
		currentFont = pDC->GetCurrentFont();
		oldFont = pDC->SelectObject(currentFont);
	}
	pDC->SetTextColor(m_colorText);

	pDC->TextOut(m_ptPosition.x, m_ptPosition.y, m_strOutput);


	CSize sizeText;
	sizeText = pDC->GetTextExtent(m_strOutput);
	m_nTextWidth = sizeText.cx;
	m_nTextHeight = sizeText.cy;

	pDC->SelectObject(oldFont);
}


// CMy20151654P5_4fixView 인쇄


void CMy20151654P5_4fixView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20151654P5_4fixView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20151654P5_4fixView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20151654P5_4fixView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy20151654P5_4fixView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20151654P5_4fixView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20151654P5_4fixView 진단

#ifdef _DEBUG
void CMy20151654P5_4fixView::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654P5_4fixView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654P5_4fixDoc* CMy20151654P5_4fixView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654P5_4fixDoc)));
	return (CMy20151654P5_4fixDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654P5_4fixView 메시지 처리기


void CMy20151654P5_4fixView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar) {
	case VK_LEFT:
		m_ptPosition.x -= 10;
		break;
	case VK_RIGHT:
		m_ptPosition.y += 10;
		break;
	case VK_UP:
		m_ptPosition.x -= 10;
		break;
	case VK_DOWN:
		m_ptPosition.y += 10;
		break;
	}
	if (m_ptPosition.x < 0) {
		m_ptPosition.x = 0;
		AfxMessageBox(_T("왼쪽으로 더 이상 이동할수 없습니다."));
	}
	if (m_ptPosition.y < 0) {
		m_ptPosition.y = 0;
		AfxMessageBox(_T("위쪽으로 더 이상 이동할수 없습니다."));
	}
	RECT rect;
	GetClientRect(&rect);
	if (m_ptPosition.x > rect.right - m_nTextWidth) {
		m_ptPosition.x = rect.right - m_nTextWidth;
		AfxMessageBox(_T("오른쪽으로 더 이상 이동할수 없습니다."));
	}
	if (m_ptPosition.y > rect.bottom - m_nTextHeight) {
		m_ptPosition = rect.bottom - m_nTextHeight;
		AfxMessageBox(_T("오른쪽으로 더 이상 이동할수 없습니다."));
	}
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->m_paneTextOut.m_ctrlTextOut.SetDlgItemInt(IDC_EDIT_X, m_ptPosition.x);
	pFrame->m_paneTextOut.m_ctrlTextOut.SetDlgItemInt(IDC_EDIT_Y, m_ptPosition.y);

	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
