#include "meApplication.h"

namespace me
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0)
	{

	}
	Application::~Application()
	{

	}

	void Application::Intialize(HWND hwnd)
	{
		mHwnd = hwnd;	// 내 멤버변수 핸들에 윈도우 핸들 저장
		mHdc = GetDC(hwnd);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		mSpeed += 0.01f;
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		// 파랑 브러쉬 생성
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));

		// 파랑 브러쉬 DC에 선택, 흰색 브러쉬 oldbrush에 저장
		HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, brush);

		Rectangle(mHdc, 100+mSpeed, 100, 200+mSpeed, 200);

		// 흰색 브러쉬 다시 선택
		(HBRUSH)SelectObject(mHdc, oldbrush);

		// 파랑 브러쉬 삭제
		DeleteObject(brush);

		HPEN redPen = CreatePen(PS_DOT, 2, RGB(125, 20, 100));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

		Ellipse(mHdc, 200, 200, 300, 300);

		SelectObject(mHdc, oldPen);
		DeleteObject(redPen);

		TCHAR str[20];
		wsprintf(str, TEXT("score : %d"), 10);
		TextOut(mHdc, 500+mSpeed, 500, str, lstrlen(str));
	}
}