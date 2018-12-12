#pragma once

#include <Windows.h>
#include <string_view>

namespace YunaComputer::Windows {

	// �ԋp�l�� std::wstring_view.data() ���k���I�[����Ă��邱�Ƃ����҂��Ȃ��ł��������B
	// ����� String Table ���\�[�X���k���I�[�ł���ƕۏ؂���Ă��Ȃ����߂̐����ł��B
	// (�������� std::wstring_view.data() �̓k���I�[�̕ۏ؂�����܂���B)
	// �k���I�[���ꂽ�����񂪕K�v�Ȏ��� std::wstring �ɕϊ����Ă��������B
	auto LoadStringW(::HINSTANCE hInstance, ::UINT uID) {
		::LPCWSTR s;
		auto len = ::LoadStringW(hInstance, uID, reinterpret_cast<::LPWSTR>(&s), 0);
		return len > 0 ? std::wstring_view(s, static_cast<std::size_t>(len)) : std::wstring_view{};
	}

}
