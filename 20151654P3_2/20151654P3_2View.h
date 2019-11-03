
// 20151654P3_2View.h : CMy20151654P3_2View 클래스의 인터페이스
//

#pragma once


class CMy20151654P3_2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy20151654P3_2View();
	DECLARE_DYNCREATE(CMy20151654P3_2View)

// 특성입니다.
public:
	CMy20151654P3_2Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy20151654P3_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	bool m_bTimerRun;
	bool m_bTimerType;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_strTimer;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 20151654P3_2View.cpp의 디버그 버전
inline CMy20151654P3_2Doc* CMy20151654P3_2View::GetDocument() const
   { return reinterpret_cast<CMy20151654P3_2Doc*>(m_pDocument); }
#endif

