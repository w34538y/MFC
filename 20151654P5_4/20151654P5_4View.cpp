
// 20151654P5_4View.cpp : CMy20151654P5_4View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20151654P5_4.h"
#endif

#include "20151654P5_4Doc.h"
#include "20151654P5_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151654P5_4View

IMPLEMENT_DYNCREATE(CMy20151654P5_4View, CView)

BEGIN_MESSAGE_MAP(CMy20151654P5_4View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20151654P5_4View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy20151654P5_4View ����/�Ҹ�

CMy20151654P5_4View::CMy20151654P5_4View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20151654P5_4View::~CMy20151654P5_4View()
{
}

BOOL CMy20151654P5_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20151654P5_4View �׸���

void CMy20151654P5_4View::OnDraw(CDC* /*pDC*/)
{
	CMy20151654P5_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy20151654P5_4View �μ�


void CMy20151654P5_4View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20151654P5_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20151654P5_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20151654P5_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy20151654P5_4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20151654P5_4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20151654P5_4View ����

#ifdef _DEBUG
void CMy20151654P5_4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654P5_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654P5_4Doc* CMy20151654P5_4View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654P5_4Doc)));
	return (CMy20151654P5_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654P5_4View �޽��� ó����
