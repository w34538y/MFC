
// 20151654P5_1_2_3.h : 20151654P5_1_2_3 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy20151654P5_1_2_3App:
// �� Ŭ������ ������ ���ؼ��� 20151654P5_1_2_3.cpp�� �����Ͻʽÿ�.
//

class CMy20151654P5_1_2_3App : public CWinAppEx
{
public:
	CMy20151654P5_1_2_3App();


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

extern CMy20151654P5_1_2_3App theApp;
