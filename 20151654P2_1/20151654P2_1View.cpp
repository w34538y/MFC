
// 20151654P2_1View.cpp : CMy20151654P2_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20151654P2_1.h"
#endif

#include "20151654P2_1Doc.h"
#include "20151654P2_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151654P2_1View

IMPLEMENT_DYNCREATE(CMy20151654P2_1View, CView)

BEGIN_MESSAGE_MAP(CMy20151654P2_1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20151654P2_1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
//	ON_WM_RBUTTONUP()
//	ON_WM_SIZE()
ON_WM_SIZE()
ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
ON_WM_KEYDOWN()
ON_WM_MOUSEMOVE()
ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy20151654P2_1View ����/�Ҹ�

CMy20151654P2_1View::CMy20151654P2_1View() //������ �Լ�
	: m_strWindowSize(_T("")) //�ڵ� �ʱ�ȭ
	, m_strOutput(_T(""))
	, m_bDrag(false)
	, m_ptMouseMove(0)
	, m_strPointText(_T(""))
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20151654P2_1View::~CMy20151654P2_1View() //�Ҹ��� �Լ�
{
}

BOOL CMy20151654P2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20151654P2_1View �׸���

void CMy20151654P2_1View::OnDraw(CDC* pDC)
{
	CMy20151654P2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	//������ ũ�⸦ ��Ÿ���� ���ڿ��� ������ �������(10, 10)�� ���
	pDC->TextOut(10, 10, m_strWindowSize);
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strOutput, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	pDC->TextOut(m_ptMouseMove.x, m_ptMouseMove.y, m_strPointText);
}


// CMy20151654P2_1View �μ�


void CMy20151654P2_1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20151654P2_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20151654P2_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20151654P2_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

//void CMy20151654P2_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
//{
//	ClientToScreen(&point);
//	OnContextMenu(this, point);
//}

void CMy20151654P2_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20151654P2_1View ����

#ifdef _DEBUG
void CMy20151654P2_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654P2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654P2_1Doc* CMy20151654P2_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654P2_1Doc)));
	return (CMy20151654P2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654P2_1View �޽��� ó����


void CMy20151654P2_1View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	//������ ũ�Ⱑ ����� �� ������ ũ�⸦ ��Ÿ���� ���ڿ� ����
	m_strWindowSize.Format(_T("������ ũ��� ���� %d ���� %d�Դϴ�."), cx, cy);
	//ȭ�� ����
	Invalidate(); //OnDraw�Լ� ȣ��
}


void CMy20151654P2_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_bDrag = TRUE;
	m_strOutput = _T("���� ���콺 ��ư�� �������ϴ�.");
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMy20151654P2_1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_strOutput = _T("������ ���콺 ��ư�� �������ϴ�.");
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


void CMy20151654P2_1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_strOutput = _T("Ű���� ��ư�� �������ϴ�.");
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy20151654P2_1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_ptMouseMove = point; //��üġȯ, ��ü ����
	m_strPointText.Format(_T("X: %d, Y: %d"), m_ptMouseMove.x, m_ptMouseMove.y);


	if (m_bDrag == TRUE) {
		m_strOutput = _T("�巡�� �ϴ� ��");
	}
	else {
		m_strOutput = _T("���콺 �̵� ��");
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMy20151654P2_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_bDrag = FALSE;
	CView::OnLButtonUp(nFlags, point);
}
