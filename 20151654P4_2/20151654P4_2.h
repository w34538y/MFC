
// 20151654P4_2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMy20151654P4_2App:
// �� Ŭ������ ������ ���ؼ��� 20151654P4_2.cpp�� �����Ͻʽÿ�.
//

class CMy20151654P4_2App : public CWinApp
{
public:
	CMy20151654P4_2App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMy20151654P4_2App theApp;