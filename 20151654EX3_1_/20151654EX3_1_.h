
// 20151654EX3_1_.h : 20151654EX3_1_ ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy20151654EX3_1_App:
// �� Ŭ������ ������ ���ؼ��� 20151654EX3_1_.cpp�� �����Ͻʽÿ�.
//

class CMy20151654EX3_1_App : public CWinApp
{
public:
	CMy20151654EX3_1_App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy20151654EX3_1_App theApp;
