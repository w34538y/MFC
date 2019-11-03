
// 20151654P3_3View.cpp : CMy20151654P3_3View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20151654P3_3.h"
#endif

#include "20151654P3_3Doc.h"
#include "20151654P3_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151654P3_3View

IMPLEMENT_DYNCREATE(CMy20151654P3_3View, CView)

BEGIN_MESSAGE_MAP(CMy20151654P3_3View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy20151654P3_3View ����/�Ҹ�

CMy20151654P3_3View::CMy20151654P3_3View()
	: m_strOutput(_T(""))
	, m_ptLocation(0)
	, m_ptClientSize(0)
	, m_bDrag(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20151654P3_3View::~CMy20151654P3_3View()
{
}

BOOL CMy20151654P3_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20151654P3_3View �׸���

void CMy20151654P3_3View::OnDraw(CDC* pDC)
{
	CMy20151654P3_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOut(m_ptLocation.x, m_ptLocation.y, m_strOutput);
}


// CMy20151654P3_3View �μ�

BOOL CMy20151654P3_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20151654P3_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20151654P3_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy20151654P3_3View ����

#ifdef _DEBUG
void CMy20151654P3_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654P3_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654P3_3Doc* CMy20151654P3_3View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654P3_3Doc)));
	return (CMy20151654P3_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654P3_3View �޽��� ó����


//Ű������ Ű�� ������������ m_strOutput�� ����
void CMy20151654P3_3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int nCharIndex; //�Էµ� ������ ���� ���庯��
	nCharIndex = m_strOutput.GetLength();

	if (nChar == VK_BACK) //�齺���̽�Ű�� ������ 
		m_strOutput.Delete(nCharIndex - 1, 1); //�ڿ��� �ϳ��� ����
	else
		m_strOutput += (WCHAR)nChar; //�ƴϸ� �ڿ� ��� �߰� 

	//������ ����
	//Ű���� �Է� ������ ��½����� �и��Ǿ��ֱ� ������
	//���⿡���� ������ ����ϰ� ����� ondraw���� �� 
	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy20151654P3_3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (nChar) {
	case VK_LEFT:
		m_ptLocation.x--;
		break;
	case VK_RIGHT:
		m_ptLocation.x++;
		break;
	case VK_UP:
		m_ptLocation.y--;
		break;
	case VK_DOWN:
		m_ptLocation.y++;
		break;
	case VK_PRIOR:
		m_ptLocation.y -= 50;
		break;
	case VK_NEXT:
		m_ptLocation.y += 50;
		break;
	case VK_HOME:
		m_ptLocation = CPoint(0, 0);
		break;

	}

	if (m_ptLocation.x < 0) {
		m_ptLocation.x = 0;
		AfxMessageBox(_T("���̻� �������� �̵��Ҽ� �����ϴ�"));
	}
	if (m_ptLocation.y < 0) {
		m_ptLocation.y = 0;
		AfxMessageBox(_T("���̻� �������� �̵��Ҽ� �����ϴ�"));
	}
	if (m_ptLocation.x > m_ptClientSize.x) {
		m_ptLocation.x = m_ptClientSize.x;
		AfxMessageBox(_T("���̻� ���������� �̵��Ҽ� �����ϴ�"));
	}
	if (m_ptLocation.y > m_ptClientSize.y) {
		m_ptLocation.y = m_ptClientSize.y;
		AfxMessageBox(_T("���̻� �Ʒ������� �̵��Ҽ� �����ϴ�"));
	}



	Invalidate();
	

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy20151654P3_3View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	m_ptClientSize.x = cx;
	m_ptClientSize.y = cy;

	Invalidate();

}


void CMy20151654P3_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (((m_ptLocation.x + 30) >= point.x) && ((m_ptLocation.y + 30) >= point.y) && ((m_ptLocation.x - 30) <= point.x) && ((m_ptLocation.y - 30) <= point.y))
	{
		m_bDrag = true;
	}
	else
	{
		m_ptLocation = point;
	}
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMy20151654P3_3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_strOutput.IsEmpty() == false) { //���ڿ��� ����ִ��� üũ
		if (AfxMessageBox(_T("���ڸ� ��� ����ðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES) {
			m_strOutput.Empty();
		}
	}
	else {
		AfxMessageBox(_T("���ڿ��� �Է��Ͻÿ�."));
	}
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


void CMy20151654P3_3View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bDrag)
	{
		m_ptLocation = point;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMy20151654P3_3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bDrag)
	{
		m_bDrag = false;
		m_ptLocation = point;
	}
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
