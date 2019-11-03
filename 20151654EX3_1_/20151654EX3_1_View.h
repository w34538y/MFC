
// 20151654EX3_1_View.h : CMy20151654EX3_1_View 클래스의 인터페이스
//

#pragma once


class CMy20151654EX3_1_View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy20151654EX3_1_View();
	DECLARE_DYNCREATE(CMy20151654EX3_1_View)

// 특성입니다.
public:
	CMy20151654EX3_1_Doc* GetDocument() const;

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
	virtual ~CMy20151654EX3_1_View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // 20151654EX3_1_View.cpp의 디버그 버전
inline CMy20151654EX3_1_Doc* CMy20151654EX3_1_View::GetDocument() const
   { return reinterpret_cast<CMy20151654EX3_1_Doc*>(m_pDocument); }
#endif

