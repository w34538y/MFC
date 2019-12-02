
// 20151654P10_2View.cpp : CMy20151654P10_2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20151654P10_2.h"
#endif

#include "20151654P10_2Doc.h"
#include "20151654P10_2View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151654P10_2View

IMPLEMENT_DYNCREATE(CMy20151654P10_2View, CView)

BEGIN_MESSAGE_MAP(CMy20151654P10_2View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20151654P10_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy20151654P10_2View ����/�Ҹ�

CMy20151654P10_2View::CMy20151654P10_2View()
	: m_nCount(0)
	, m_ptFollow(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20151654P10_2View::~CMy20151654P10_2View()
{
}

BOOL CMy20151654P10_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20151654P10_2View �׸���

void CMy20151654P10_2View::OnDraw(CDC* pDC)
{
	CMy20151654P10_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	if (m_nCount < 5) {
		pDC->TextOut(m_ptFollow.x + 10, m_ptFollow.y + 10, pDoc->m_strDept);
		pDC->TextOut(m_ptFollow.x + 10, m_ptFollow.y + 30, pDoc->m_strName);
		pDC->TextOut(m_ptFollow.x + 10, m_ptFollow.y + 50, pDoc->m_strSex);
		pDC->TextOut(m_ptFollow.x + 10, m_ptFollow.y + 70, pDoc->m_strHobby);
	}
	for (int i = 0; i < m_nCount; i++) {
		pDC->TextOut(m_ptFixate[i].x + 10, m_ptFixate[i].y + 10, pDoc->m_strDept);
		pDC->TextOut(m_ptFixate[i].x + 10, m_ptFixate[i].y + 30, pDoc->m_strName);
		pDC->TextOut(m_ptFixate[i].x + 10, m_ptFixate[i].y + 50, pDoc->m_strSex);
		pDC->TextOut(m_ptFixate[i].x + 10, m_ptFixate[i].y + 70, pDoc->m_strHobby);
	}

}


// CMy20151654P10_2View �μ�


void CMy20151654P10_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20151654P10_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20151654P10_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20151654P10_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy20151654P10_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20151654P10_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20151654P10_2View ����

#ifdef _DEBUG
void CMy20151654P10_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654P10_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654P10_2Doc* CMy20151654P10_2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654P10_2Doc)));
	return (CMy20151654P10_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654P10_2View �޽��� ó����


void CMy20151654P10_2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_ptFollow = point;
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


void CMy20151654P10_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20151654P10_2Doc* pDoc = (CMy20151654P10_2Doc*)pFrame->GetActiveDocument();

	if (!pDoc->m_strName.IsEmpty()) {
		if (m_nCount < 5) {
			m_ptFixate[m_nCount] = point;
			m_nCount++;
		}
		else {
			AfxMessageBox(_T("���ڴ� �ټ��������� ����� �� �ֽ��ϴ�."));
		}
	}
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMy20151654P10_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20151654P10_2Doc* pDoc = (CMy20151654P10_2Doc*)pFrame->GetActiveDocument();

	if (!pDoc->m_strName.IsEmpty()) {
		if (m_nCount > 0)
			m_nCount--;
		else
			if (AfxMessageBox(_T("��� ������ �����ϰڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES) {
				pDoc->m_strName.Empty();
				pDoc->m_strDept.Empty();
				pDoc->m_strSex.Empty();
				pDoc->m_strHobby.Empty();
			}
	}
	else
		MessageBox(_T("������ ������ �����ϴ�."));
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}
