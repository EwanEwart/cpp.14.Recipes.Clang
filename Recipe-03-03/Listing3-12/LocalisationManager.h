#pragma once

#include <array>
#include <cinttypes>
#include <string>
#include <unordered_map>

namespace Localisation
{
	using StringID = int32_t;

	enum class Languages
	{
		EN_US,
		EN_GB,
		Number
	};

	const StringID STRING_COLOUR{ 0 };

	class Manager
	{
	private:
		using Strings = std::unordered_map<StringID, std::string>;
		using StringPacks = std::array<Strings, static_cast<size_t>(Languages::Number)>;

		StringPacks m_StringPacks;
		Strings* m_CurrentStringPack{ nullptr };

		uint32_t m_LanguageIndex;

	public:
		Manager();

		void SetLanguage(Languages language);

		std::string GetString(StringID stringId) const;
	};
}
