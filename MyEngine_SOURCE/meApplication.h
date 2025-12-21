#pragma once
#include "CommonInclude.h"

namespace me
{
	class Application
	{
	public:
		Application();
		~Application();

		void Intialize(HWND hwnd);
		void Run();
			
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;
	};
}
