#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow) {
	static LPTSTR szAppName = "EasyText";		//������ Ŭ�����̸�
	static LPTSTR szTitleName = "20151654P1_1"; // Ÿ��Ʋ�ٿ� ��µ� ���ڿ�

	HWND hwnd;		 	 //������ �ڵ�
	MSG msg;			     //�޼��� ����ü
	WNDCLASSEX WndClass; //������ Ŭ���� ����ü


						 //1. ������ Ŭ���� ����ü WndClass�� ���� ä�� ������ Ŭ������ ����Ѵ�.
	WndClass.cbSize = sizeof(WNDCLASSEX);				       //����ü ũ��
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS; //Ŭ���� ��Ÿ��
	WndClass.lpfnWndProc = WndProc;							   //������ ���ν���
	WndClass.cbClsExtra = 0;									   //������Ŭ���� �����Ϳ���
	WndClass.cbWndExtra = 0;									   //�������� �����Ϳ���
	WndClass.hInstance = hInstance;							   // �ν��Ͻ� �ڵ�
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);      //������ �ڵ�
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		   //Ŀ�� �ڵ�
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //��� �귯�� �ڵ�
	WndClass.lpszMenuName = NULL;								   //�޴� �̸�
	WndClass.lpszClassName = szAppName;							   //������ Ŭ���� �̸�
	WndClass.hIconSm = 0;									   //�⺻���� ���� ������

															   //������ Ŭ������ ����Ѵ�
	RegisterClassEx(&WndClass);

	//2. ������ �����츦 �����Ѵ�.
	hwnd = CreateWindow(	  //������ ���� API �Լ�
		szAppName,			  //��ϵ� ������ Ŭ���� �̸�
		szTitleName,		      //Ÿ��Ʋ �ٿ� ��µ� ���ڿ�
		WS_OVERLAPPEDWINDOW,  //������ ��Ÿ��
		CW_USEDEFAULT,		  //������ ���� ����� X��ǥ
		CW_USEDEFAULT,		  //������ ���� ����� Y��ǥ
		CW_USEDEFAULT,		  //�������� �ʺ�
		CW_USEDEFAULT,		  //�������� ����
		NULL,				  //�θ� �������� �ڵ�
		NULL,				  //�޴� �Ǵ� �ڽ� �������� �ڵ�
		hInstance,			  //���ø����̼� �ν��Ͻ� �ڵ�
		NULL				      //������ ���� �������� �ּ� 
	);

	//������ �����츦 ȭ�鿡 ǥ���Ѵ�.
	ShowWindow(hwnd, nCmdShow); //ȭ���� ���̰ų� ���������
	UpdateWindow(hwnd);         //�ܰ� ��ħ

								//3. �޽��� ť�κ��� �޽����� �޾ƿ� �޽����� �ش� ������ ���ν����� ������.
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg); //�޽����� �����Ѵ�
		DispatchMessage(&msg);  //�޽����� �ش� ������ ���ν��� �Լ��� ������.
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC hdc;                                         //����̽� ���ؽ�Ʈ �ڵ�
	RECT rect;									     //RECT ����ü
	PAINTSTRUCT ps;								     //����Ʈ ����ü
	POINT MousePoint;    //���콺 ����Ʈ ����ü


	LPTSTR szMsg1 = "I love window Programming";     //�����쿡 ��µ� ���ڿ�
	LPTSTR szMsg2 = "Ű���尡 ���������ϴ�.";        //Ű���带 �������� ��µ� ���ڿ�
	LPTSTR szMsg3 = "Ű���尡 ���������ϴ�.";		 //Ű���带 �������� ��µ� ���ڿ�
	LPTSTR szMsg4 = "���콺�� ���������ϴ�.";
	LPTSTR szMsg5 = "���콺�� �̵����Դϴ�.";
	LPTSTR szMsg6 = new char[10];


	//���콺 ��ǥ ���
	MousePoint.x = LOWORD(lParam);
	MousePoint.y = HIWORD(lParam);


	switch (message) {
	case WM_CREATE: //������ ���� �޽����� �� ���
		break;

	case WM_PAINT: //ȭ�鿡 ��� �޽����� �� ���
		hdc = BeginPaint(hwnd, &ps); //DC����
		TextOut(hdc, 10, 10, szMsg1, strlen(szMsg1));
		EndPaint(hwnd, &ps);
		break;

	case WM_KEYDOWN: //Ű���� ��ư�� ���� ���
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg2, strlen(szMsg2), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_KEYUP: //Ű���� ��ư�� ������ ���
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg3, strlen(szMsg3), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_LBUTTONDBLCLK: //���콺�� ���� Ŭ���� ���
		MessageBox(hwnd, "���콺 ����Ŭ��", "���콺 �޽���", MB_OK | MB_ICONASTERISK);
		break;

	case WM_LBUTTONDOWN: //���콺�� ���� ���
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg4, strlen(szMsg4), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		wsprintf(szMsg6, "X: %ld, Y: %ld", MousePoint.x, MousePoint.y);
		TextOut(hdc, MousePoint.x, MousePoint.y, szMsg6, strlen(szMsg6));
		ReleaseDC(hwnd, hdc);
		break;

	case WM_LBUTTONUP: //���콺�� �����
		InvalidateRect(hwnd, NULL, TRUE);
		break;

	case WM_MOUSEMOVE: //���콺�� �̵��ϴ� ���
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg5, strlen(szMsg5), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_DESTROY: //���α׷� ���� �޽����� �� ���
		PostQuitMessage(0);
		break;

	default: //�� ���� �޽����� �� ���
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}
