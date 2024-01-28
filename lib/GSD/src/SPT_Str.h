#pragma once
#include <string>
#include <vector>

#include "GSD_Types.h"


namespace GSD::SPT
{
	class Str
	{
	public:
		static std::wstring NumToStr(const wchar_t* wpFormat, size_t nValue);
		static size_t StrToNum(const wchar_t* wpFormat, std::wstring_view wsStr);
		static std::wstring LoadANSI(const std::string_view msStr, size_t uCodePage);
		static std::string MakeANSI(const std::wstring_view wsStr, size_t uCodePage);
		static std::vector<SPT_Char_Entry> MakeCharTable(const std::string& msText);
		static std::string ParseCharTable(const std::vector<SPT_Char_Entry>& rfCharEntries);
	};
}