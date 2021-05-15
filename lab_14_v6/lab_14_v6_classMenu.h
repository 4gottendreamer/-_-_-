#pragma once

class Menu
{
public:
	Menu(std::vector<std::wstring> _Lines)
	{
		m_Lines = _Lines;
	}

	~Menu() {}

	void Print()
	{
		for (auto& line : m_Lines) {
			std::wcout << line << std::endl;
		}
	}

private:
	std::vector<std::wstring> m_Lines;
};
