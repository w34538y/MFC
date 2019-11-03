
// 20151654P5_4fixView.cpp : CMy20151654P5_4fixView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20151654P5_4fixView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMy20151654P5_4fixView ����/�Ҹ�

CMy20151654P5_4fixView::CMy20151654P5_4fixView()
	: m_strOutput(_T(""))
	, m_nTextWidth(0)
	, m_nTextHeight(0)
	, m_ptPosition(0)
	, m_bFont(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20151654P5_4fixView::~CMy20151654P5_4fixView()
{
}

BOOL CMy20151654P5_4fixView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20151654P5_4fixView �׸���

void CMy20151654P5_4fixView::OnDraw(CDC* pDC)
{
	CMy20151654P5_4fixDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
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


// CMy20151654P5_4fixView �μ�


void CMy20151654P5_4fixView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20151654P5_4fixView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20151654P5_4fixView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20151654P5_4fixView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


// CMy20151654P5_4fixView ����

#ifdef _DEBUG
void CMy20151654P5_4fixView::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654P5_4fixView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654P5_4fixDoc* CMy20151654P5_4fixView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654P5_4fixDoc)));
	return (CMy20151654P5_4fixDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654P5_4fixView �޽��� ó����


void CMy20151654P5_4fixView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
		AfxMessageBox(_T("�������� �� �̻� �̵��Ҽ� �����ϴ�."));
	}
	if (m_ptPosition.y < 0) {
		m_ptPosition.y = 0;
		AfxMessageBox(_T("�������� �� �̻� �̵��Ҽ� �����ϴ�."));
	}
	RECT rect;
	GetClientRect(&rect);
	if (m_ptPosition.x > rect.right - m_nTextWidth) {
		m_ptPosition.x = rect.right - m_nTextWidth;
		AfxMessageBox(_T("���������� �� �̻� �̵��Ҽ� �����ϴ�."));
	}
	if (m_ptPosition.y > rect.bottom - m_nTextHeight) {
		m_ptPosition = rect.bottom - m_nTextHeight;
		AfxMessageBox(_T("���������� �� �̻� �̵��Ҽ� �����ϴ�."));
	}
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->m_paneTextOut.m_ctrlTextOut.SetDlgItemInt(IDC_EDIT_X, m_ptPosition.x);
	pFrame->m_paneTextOut.m_ctrlTextOut.SetDlgItemInt(IDC_EDIT_Y, m_ptPosition.y);

	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
