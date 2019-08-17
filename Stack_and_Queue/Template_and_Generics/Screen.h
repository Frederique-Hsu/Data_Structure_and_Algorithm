#pragma once

#include <string>

template<int hi, int wid>
class Screen
{
public:
	Screen() : screen(hi * wid, '#'), cursor(0), height(0), width(0)
	{
	}
private:
	std::string screen;
	std::string::size_type cursor;
	std::string::size_type height;
	std::string::size_type width;
};