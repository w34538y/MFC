
// 20151654EX3_1View.cpp : CMy20151654EX3_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
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

// CMy20151654EX3_1View ����/�Ҹ�

CMy20151654EX3_1View::CMy20151654EX3_1View()
	: m_strStopWatch(_T("00: 00. 00"))
	, m_nCount(0)
	, m_nMinute(0)
	, m_nSecond(0)
	, m_nMSec(0)
	, m_bStopWatchRun(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20151654EX3_1View::~CMy20151654EX3_1View()
{
}

BOOL CMy20151654EX3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20151654EX3_1View �׸���

void CMy20151654EX3_1View::OnDraw(CDC* pDC)
{
	CMy20151654EX3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CFont big_font;
	big_font.CreateFont(100, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("����ü"));
	CClientDC dc(this);

	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strStopWatch, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	int y = 10;
	pDC->TextOut(10, y, m_strRecord[40]);
	y += 20;
	
}


// CMy20151654EX3_1View �μ�


void CMy20151654EX3_1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20151654EX3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20151654EX3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20151654EX3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


// CMy20151654EX3_1View ����

#ifdef _DEBUG
void CMy20151654EX3_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654EX3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654EX3_1Doc* CMy20151654EX3_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654EX3_1Doc)));
	return (CMy20151654EX3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654EX3_1View �޽��� ó����


void CMy20151654EX3_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (!m_bStopWatchRun) {
		if (AfxMessageBox(_T("�ʱ�ȭ �Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES) {
			m_nCount = 0;
			m_nMinute = 0;
			m_nSecond = 0;
			m_nMSec = 0;
		}
	}
	CView::OnRButtonDown(nFlags, point);
}
