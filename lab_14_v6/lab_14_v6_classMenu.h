#pragma once

class Menu
{
public:
	Menu(std::vector<std::string> _Lines)
	{
		m_Lines = _Lines;
	}

	~Menu() {}

	void Print()
	{
		for (auto& line : m_Lines) {
			std::cout << line << std::endl;
		}
	}

private:
	std::vector<std::string> m_Lines;
};
