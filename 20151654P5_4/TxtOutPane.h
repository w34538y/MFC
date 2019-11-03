#pragma once
#include "TextOutCtrl.h"


// CTxtOutPane

class CTxtOutPane : public CDockablePane
{
	DECLARE_DYNAMIC(CTxtOutPane)

public:
	CTxtOutPane();
	virtual ~CTxtOutPane();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CTextOutCtrl m_ctrlTextOut;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


