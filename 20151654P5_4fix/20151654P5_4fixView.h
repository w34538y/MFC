
// 20151654P5_4fixView.h : CMy20151654P5_4fixView Ŭ������ �������̽�
//

#pragma once
#include "atltypes.h"


class CMy20151654P5_4fixView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy20151654P5_4fixView();
	DECLARE_DYNCREATE(CMy20151654P5_4fixView)

// Ư���Դϴ�.
public:
	CMy20151654P5_4fixDoc* GetDocument() const;

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
	virtual ~CMy20151654P5_4fixView();
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
	CString m_strOutput;
	int m_nTextWidth;
	int m_nTextHeight;
	CPoint m_ptPosition;
	COLORREF m_colorText;
	bool m_bFont;
	LOGFONT m_logFont;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // 20151654P5_4fixView.cpp�� ����� ����
inline CMy20151654P5_4fixDoc* CMy20151654P5_4fixView::GetDocument() const
   { return reinterpret_cast<CMy20151654P5_4fixDoc*>(m_pDocument); }
#endif

