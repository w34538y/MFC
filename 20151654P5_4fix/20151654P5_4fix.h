
// 20151654P5_4fix.h : 20151654P5_4fix ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy20151654P5_4fixApp:
// �� Ŭ������ ������ ���ؼ��� 20151654P5_4fix.cpp�� �����Ͻʽÿ�.
//

class CMy20151654P5_4fixApp : public CWinAppEx
{
public:
	CMy20151654P5_4fixApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy20151654P5_4fixApp theApp;
