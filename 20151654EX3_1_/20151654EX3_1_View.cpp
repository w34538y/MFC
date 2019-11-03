
// 20151654EX3_1_View.cpp : CMy20151654EX3_1_View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy20151654EX3_1_View ����/�Ҹ�

CMy20151654EX3_1_View::CMy20151654EX3_1_View()
	: m_strStopWatch(_T("00: 00. 00"))
	, m_nCount(0)
	, m_nMinute(0)
	, m_nSecond(0)
	, m_nMSec(0)
	, m_bStopWatchRun(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20151654EX3_1_View::~CMy20151654EX3_1_View()
{
}

BOOL CMy20151654EX3_1_View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20151654EX3_1_View �׸���

void CMy20151654EX3_1_View::OnDraw(CDC* pDC)
{
	CMy20151654EX3_1_Doc* pDoc = GetDocument();
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
	for (int i = 0; i < m_nCount; i++)
	{
		pDC->TextOut(10, 10 + (i * 20), m_strRecord[i]);
	}
}


// CMy20151654EX3_1_View �μ�

BOOL CMy20151654EX3_1_View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20151654EX3_1_View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20151654EX3_1_View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy20151654EX3_1_View ����

#ifdef _DEBUG
void CMy20151654EX3_1_View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654EX3_1_View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654EX3_1_Doc* CMy20151654EX3_1_View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654EX3_1_Doc)));
	return (CMy20151654EX3_1_Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654EX3_1_View �޽��� ó����


void CMy20151654EX3_1_View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (!m_bStopWatchRun) {
		if (AfxMessageBox(_T("�ʱ�ȭ �Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES) {
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
