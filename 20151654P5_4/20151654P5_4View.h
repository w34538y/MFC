
// 20151654P5_4View.h : CMy20151654P5_4View Ŭ������ �������̽�
//

#pragma once


class CMy20151654P5_4View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy20151654P5_4View();
	DECLARE_DYNCREATE(CMy20151654P5_4View)

// Ư���Դϴ�.
public:
	CMy20151654P5_4Doc* GetDocument() const;

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
	virtual ~CMy20151654P5_4View();
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
};

#ifndef _DEBUG  // 20151654P5_4View.cpp�� ����� ����
inline CMy20151654P5_4Doc* CMy20151654P5_4View::GetDocument() const
   { return reinterpret_cast<CMy20151654P5_4Doc*>(m_pDocument); }
#endif

