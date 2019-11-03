#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow) {
	static LPTSTR szAppName = "EasyText";		//윈도우 클래스이름
	static LPTSTR szTitleName = "20151654P1_1"; // 타이틀바에 출력될 문자열

	HWND hwnd;		 	 //윈도우 핸들
	MSG msg;			     //메세지 구조체
	WNDCLASSEX WndClass; //윈도우 클래스 구조체


						 //1. 윈도우 클래스 구조체 WndClass에 값을 채워 윈도우 클래스를 등록한다.
	WndClass.cbSize = sizeof(WNDCLASSEX);				       //구조체 크기
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS; //클래스 스타일
	WndClass.lpfnWndProc = WndProc;							   //윈도우 프로시저
	WndClass.cbClsExtra = 0;									   //윈도우클래스 데이터영역
	WndClass.cbWndExtra = 0;									   //윈도우의 데이터영역
	WndClass.hInstance = hInstance;							   // 인스턴스 핸들
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);      //아이콘 핸들
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		   //커서 핸들
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //배경 브러시 핸들
	WndClass.lpszMenuName = NULL;								   //메뉴 이름
	WndClass.lpszClassName = szAppName;							   //윈도우 클래스 이름
	WndClass.hIconSm = 0;									   //기본적인 작은 아이콘

															   //윈도우 클래스를 등록한다
	RegisterClassEx(&WndClass);

	//2. 프레임 윈도우를 생성한다.
	hwnd = CreateWindow(	  //윈도우 생성 API 함수
		szAppName,			  //등록된 윈도우 클래스 이름
		szTitleName,		      //타이틀 바에 출력될 문자열
		WS_OVERLAPPEDWINDOW,  //윈도우 스타일
		CW_USEDEFAULT,		  //윈도우 좌측 상단의 X좌표
		CW_USEDEFAULT,		  //윈도우 좌측 상단의 Y좌표
		CW_USEDEFAULT,		  //윈도우의 너비
		CW_USEDEFAULT,		  //윈도우의 높이
		NULL,				  //부모 윈도우의 핸들
		NULL,				  //메뉴 또는 자식 윈도우의 핸들
		hInstance,			  //애플리케이션 인스턴스 핸들
		NULL				      //윈도우 생성 데이터의 주소 
	);

	//프레임 윈도우를 화면에 표시한다.
	ShowWindow(hwnd, nCmdShow); //화면을 보이거나 감출수있음
	UpdateWindow(hwnd);         //외관 고침

								//3. 메시지 큐로부터 메시지를 받아와 메시지를 해당 윈도우 프로시저로 보낸다.
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg); //메시지를 번역한다
		DispatchMessage(&msg);  //메시지를 해당 윈도우 프로시저 함수로 보낸다.
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC hdc;                                         //디바이스 컨텍스트 핸들
	RECT rect;									     //RECT 구조체
	PAINTSTRUCT ps;								     //페인트 구조체
	POINT MousePoint;    //마우스 포인트 구조체


	LPTSTR szMsg1 = "I love window Programming";     //윈도우에 출력될 문자열
	LPTSTR szMsg2 = "키보드가 눌러졌습니다.";        //키보드를 눌렀을때 출력될 문자열
	LPTSTR szMsg3 = "키보드가 떼어졌습니다.";		 //키보드를 떼었을때 출력될 문자열
	LPTSTR szMsg4 = "마우스가 눌려졌습니다.";
	LPTSTR szMsg5 = "마우스가 이동중입니다.";
	LPTSTR szMsg6 = new char[10];


	//마우스 좌표 얻기
	MousePoint.x = LOWORD(lParam);
	MousePoint.y = HIWORD(lParam);


	switch (message) {
	case WM_CREATE: //윈도우 생성 메시지가 온 경우
		break;

	case WM_PAINT: //화면에 출력 메시지가 온 경우
		hdc = BeginPaint(hwnd, &ps); //DC얻어옴
		TextOut(hdc, 10, 10, szMsg1, strlen(szMsg1));
		EndPaint(hwnd, &ps);
		break;

	case WM_KEYDOWN: //키보드 버튼이 눌린 경우
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg2, strlen(szMsg2), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_KEYUP: //키보드 버튼이 떼어진 경우
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg3, strlen(szMsg3), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_LBUTTONDBLCLK: //마우스를 더블 클릭한 경우
		MessageBox(hwnd, "마우스 더블클릭", "마우스 메시지", MB_OK | MB_ICONASTERISK);
		break;

	case WM_LBUTTONDOWN: //마우스를 누른 경우
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg4, strlen(szMsg4), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		wsprintf(szMsg6, "X: %ld, Y: %ld", MousePoint.x, MousePoint.y);
		TextOut(hdc, MousePoint.x, MousePoint.y, szMsg6, strlen(szMsg6));
		ReleaseDC(hwnd, hdc);
		break;

	case WM_LBUTTONUP: //마우스를 뗀경우
		InvalidateRect(hwnd, NULL, TRUE);
		break;

	case WM_MOUSEMOVE: //마우스를 이동하는 경우
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg5, strlen(szMsg5), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_DESTROY: //프로그램 종료 메시지가 온 경우
		PostQuitMessage(0);
		break;

	default: //그 외의 메시지가 온 경우
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}
