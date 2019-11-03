
// 20151654P3_2View.cpp : CMy20151654P3_2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20151654P3_2.h"
#endif

#include "20151654P3_2Doc.h"
#include "20151654P3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20151654P3_2View

IMPLEMENT_DYNCREATE(CMy20151654P3_2View, CView)

BEGIN_MESSAGE_MAP(CMy20151654P3_2View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_LBUTTONDBLCLK()
//ON_WM_LBUTTONDBLCLK()
ON_WM_CREATE()
ON_WM_DESTROY()
ON_WM_TIMER()
ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy20151654P3_2View ����/�Ҹ�

CMy20151654P3_2View::CMy20151654P3_2View()
	: m_bTimerRun(false)
	, m_bTimerType(true)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20151654P3_2View::~CMy20151654P3_2View()
{
}

BOOL CMy20151654P3_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20151654P3_2View �׸���

void CMy20151654P3_2View::OnDraw(CDC* pDC)
{
	CMy20151654P3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CRect rect;
	GetClientRect(&rect); // ������ Ŭ���̾�Ʈ ������ ��´�
	//�������� �߾ӿ� Ÿ�̸Ӹ� ��� 
	pDC->DrawText(m_strTimer, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CMy20151654P3_2View �μ�

BOOL CMy20151654P3_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20151654P3_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20151654P3_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy20151654P3_2View ����

#ifdef _DEBUG
void CMy20151654P3_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20151654P3_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20151654P3_2Doc* CMy20151654P3_2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20151654P3_2Doc)));
	return (CMy20151654P3_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20151654P3_2View �޽��� ó����


//void CMy20151654P3_2View::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//
//	CView::OnLButtonDblClk(nFlags, point);
//}


//void CMy20151654P3_2View::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//
//	CView::OnLButtonDblClk(nFlags, point);
//}


int CMy20151654P3_2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	SetTimer(0, 1000, NULL); // wm_timer ȣ��
	m_bTimerRun = true; // Ÿ�̸� ���� on 


	return 0;
}


void CMy20151654P3_2View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	AfxMessageBox(_T("�����찡 ����Ǿ����ϴ�."), MB_YESNO | MB_ICONWARNING);
}


void CMy20151654P3_2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int hour;
	CString str;
	CTime timer;                    //Ÿ�̸� ���� ����
	timer = CTime::GetCurrentTime(); //���� �ð��� ����

	if (m_bTimerType) {
		m_strTimer.Format(_T("����� %d�� %d�� %d�� %d�� %d�� %d��"),
			timer.GetYear(), timer.GetMonth(), timer.GetDay(),
			timer.GetHour(), timer.GetMinute(), timer.GetSecond());
	}
	else {
		hour = timer.GetHour();
		if (hour >= 12) {
			str = _T("PM");
			if (hour >= 13)
				hour = hour - 12;
		}
		else {
			str = _T("AM");
		}
		m_strTimer.Format(_T("������ %s %d�� %d�� %d��"), str, hour, timer.GetMinute(), timer.GetSecond());
	}
	Invalidate(); // ondraw() �Լ� �ڵ�ȣ��

	CView::OnTimer(nIDEvent);
}


void CMy20151654P3_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bTimerType) {//������´� ����Ͻú���
		if (AfxMessageBox(_T("��, ��, �� ���·� ǥ���Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES) {
			m_bTimerType = false; //�ú��� ���·�
		}
			
	}
	else {
		if (AfxMessageBox(_T("��, ��, ��  ���·� ǥ���Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES) {
			m_bTimerType = true; //����� ���·�s
		}
			
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy20151654P3_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bTimerRun == false) {
		if (AfxMessageBox(_T("������ �ð踦 ���۽�Ű�ڽ��ϱ�? "), MB_YESNO | MB_ICONQUESTION) == IDYES) {
			SetTimer(0, 1000, NULL);
			m_bTimerRun = true;

		}
	}
	else {
		if (AfxMessageBox(_T("������ ������ �ð踦 ���߽ðڽ��ϱ�? "), MB_YESNO | MB_ICONQUESTION) == IDYES) {
			KillTimer(0); //Ÿ�̸� ����
			m_bTimerRun = false;
		}
	}

	CView::OnRButtonDown(nFlags, point);
}
