#pragma once

#include <Windows.h>
#include <string_view>

namespace YunaComputer::Windows {

	// 返却値の std::wstring_view.data() がヌル終端されていることを期待しないでください。
	// これは String Table リソースがヌル終端であると保証されていないための制限です。
	// (そもそも std::wstring_view.data() はヌル終端の保証がありません。)
	// ヌル終端された文字列が必要な時は std::wstring に変換してください。
	auto LoadStringW(::HINSTANCE hInstance, ::UINT uID) {
		::LPCWSTR s;
		auto len = ::LoadStringW(hInstance, uID, reinterpret_cast<::LPWSTR>(&s), 0);
		return len > 0 ? std::wstring_view(s, static_cast<std::size_t>(len)) : std::wstring_view{};
	}

}
