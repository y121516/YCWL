#include <Windows.h>
#include "LoadStringW.hpp"
#include "resource.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE /*hPrevInstance*/, _In_ LPWSTR /*lpCmdLine*/, _In_ int /*nCmdShow*/) {
	using std::wstring;
	using YunaComputer::Windows::LoadStringW;

	wstring title{ LoadStringW(hInstance, IDS_APP_TITLE) };
	wstring text{ LoadStringW(hInstance, IDC_LOADSTRINGW) };
	::MessageBoxW(nullptr, text.c_str(), title.c_str(), MB_OK);

	return 0;
}
