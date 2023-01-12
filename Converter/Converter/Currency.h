#pragma once

#include <fstream>
#include <utility>
#include <string>
#include <nlohmann/json.hpp>

class Currency
{
private:
	using json = nlohmann::json;
	using rate = float;
	using date = std::string;

	json currency;

public:
	Currency() : currency(nullptr)
	{}

	Currency(json currency) : currency(currency)
	{}

	Currency(const std::string& path)
	{
		std::ifstream in(path, std::ifstream::binary);

		if (!in.is_open())
		{
			throw std::exception{ "Cannot open file!" };
		}

		in >> currency;
		in.close();
	}

	rate GetRate(const std::string& currencyName)
	{
		for (const auto& ele : currency)
		{
			if (ele["cc"] == currencyName)
			{
				return ele["rate"].get<rate>();
			}
		}
	}

	std::pair<date, rate> GetAllInfo(const std::string& currencyName)
	{
		for (const auto& ele : currency)
		{
			if (ele["cc"] == currencyName)
			{
				return std::make_pair<date, rate>(ele["exchangedate"].get<date>(), ele["rate"].get<rate>());
			}
		}
	}
};


enum class CurrencyType
{
	EUR,
	USD,
	UAN
};