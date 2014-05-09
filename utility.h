#ifndef _UTILITY_H
#define _UTILITY_H

#include <string>
#include <sstream>
#include <cstdarg>

namespace util {

///////////////////////////////////////////////////////////////
//
// 一些功能函数 (by david++ 2014/05/06)
//
//////////////////////////////////////////////////////////////

//
// 字符串解析成一系列token
//
template <typename Container>
inline size_t strtok(Container& cont, const std::string& text, const std::string& delim=" ")
{
	std::string::size_type beg = 0, end = 0;
	beg = text.find_first_not_of(delim);
	while (std::string::npos != beg)
	{
		end = text.find_first_of(delim, beg);
		if (std::string::npos == end)
			end = text.length();

		typename Container::value_type value;
		std::stringstream ss;
		ss << text.substr(beg, end - beg);
		ss >> value;
		cont.insert(cont.end(), value);

		beg = text.find_first_not_of(delim, end);
	}

	return cont.size();
}

//
// 日志
//
inline void log(const char* format, ...)
{
	time_t now = time(0);
	char timetxt[64] = "";
	strftime(timetxt, sizeof(timetxt), "%Y-%m-%d %H:%M:%S", localtime(&now));

	char fmt[1024] = "";
	snprintf(fmt, sizeof(fmt), "[%s] %s\n", timetxt, format);

	va_list ap;
	va_start(ap, format);
	vprintf(fmt, ap);
	fflush(stdout);
	va_end(ap);
}

}

#endif // _UTILITY_H