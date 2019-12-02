
// 20151654P10_2View.h : CMy20151654P10_2View Ŭ������ �������̽�
//

#pragma once
#include "atltypes.h"
class CMy20151654P10_2Doc;


class CMy20151654P10_2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy20151654P10_2View();
	DECLARE_DYNCREATE(CMy20151654P10_2View)

// Ư���Դϴ�.
public:
	CMy20151654P10_2Doc* GetDocument() const;

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
	virtual ~CMy20151654P10_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CPoint m_ptFixate[5];
	int m_nCount;
	CPoint m_ptFollow;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 20151654P10_2View.cpp�� ����� ����
inline CMy20151654P10_2Doc* CMy20151654P10_2View::GetDocument() const
   { return reinterpret_cast<CMy20151654P10_2Doc*>(m_pDocument); }
#endif

