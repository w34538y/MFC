
// 20151654EX3_1_View.h : CMy20151654EX3_1_View Ŭ������ �������̽�
//

#pragma once


class CMy20151654EX3_1_View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy20151654EX3_1_View();
	DECLARE_DYNCREATE(CMy20151654EX3_1_View)

// Ư���Դϴ�.
public:
	CMy20151654EX3_1_Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMy20151654EX3_1_View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_strStopWatch;
	CString m_strRecord[40];
	int m_nCount;
	int m_nMinute;
	int m_nSecond;
	int m_nMSec;
	bool m_bStopWatchRun;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 20151654EX3_1_View.cpp�� ����� ����
inline CMy20151654EX3_1_Doc* CMy20151654EX3_1_View::GetDocument() const
   { return reinterpret_cast<CMy20151654EX3_1_Doc*>(m_pDocument); }
#endif

