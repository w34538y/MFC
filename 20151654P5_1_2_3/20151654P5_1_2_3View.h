
// 20151654P5_1_2_3View.h : CMy20151654P5_1_2_3View Ŭ������ �������̽�
//
#include "atltypes.h"
enum DRAW_MODE { LINE_MODE, ELLIPSE_MODE, POLYGON_MODE, BEZIER_MODE };
#pragma once


class CMy20151654P5_1_2_3View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy20151654P5_1_2_3View();
	DECLARE_DYNCREATE(CMy20151654P5_1_2_3View)

// Ư���Դϴ�.
public:
	CMy20151654P5_1_2_3Doc* GetDocument() const;

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
	virtual ~CMy20151654P5_1_2_3View();
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
	afx_msg void OnLine();
	afx_msg void OnEllipse();
	afx_msg void OnPolygon();
	afx_msg void OnLineColor();
	afx_msg void OnFaceColor();
	afx_msg void OnBdiagonal();
	afx_msg void OnCross();
	afx_msg void OnVertical();
	int m_nDrawMode;
	int m_nHAtchStyle;
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEllipse(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePolygon(CCmdUI *pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_ptStart;
	CPoint m_ptPrev;
	bool m_bFirst;
	bool m_bLButtonDown;
	bool m_bContextMenu;
	bool m_bHatch;
	CPoint m_ptData[50];
	int m_nCount;
	COLORREF m_colorPen;
	COLORREF m_colorBrush;
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBezier();
//	afx_msg void OnUpdateBdiagonal(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBezier(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // 20151654P5_1_2_3View.cpp�� ����� ����
inline CMy20151654P5_1_2_3Doc* CMy20151654P5_1_2_3View::GetDocument() const
   { return reinterpret_cast<CMy20151654P5_1_2_3Doc*>(m_pDocument); }
#endif

