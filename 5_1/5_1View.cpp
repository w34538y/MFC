
// 5_1View.cpp : CMy5_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "5_1.h"
#endif

#include "5_1Doc.h"
#include "5_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy5_1View

IMPLEMENT_DYNCREATE(CMy5_1View, CView)

BEGIN_MESSAGE_MAP(CMy5_1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy5_1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy5_1View ����/�Ҹ�

CMy5_1View::CMy5_1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy5_1View::~CMy5_1View()
{
}

BOOL CMy5_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy5_1View �׸���

void CMy5_1View::OnDraw(CDC* pDC)
{
	CMy5_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOut(20, 20, m_strName);
	pDC->TextOut(20, 50, m_strSex);
	pDC->TextOut(20, 80, m_strHobby);
}


// CMy5_1View �μ�


void CMy5_1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy5_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy5_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy5_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy5_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy5_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy5_1View ����

#ifdef _DEBUG
void CMy5_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy5_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy5_1Doc* CMy5_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy5_1Doc)));
	return (CMy5_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy5_1View �޽��� ó����
