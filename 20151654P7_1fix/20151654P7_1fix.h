
// 20151654P7_1fix.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMy20151654P7_1fixApp:
// �� Ŭ������ ������ ���ؼ��� 20151654P7_1fix.cpp�� �����Ͻʽÿ�.
//

class CMy20151654P7_1fixApp : public CWinApp
{
public:
	CMy20151654P7_1fixApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMy20151654P7_1fixApp theApp;