#pragma once
#include <exception>
class EndOfFile
{
public:
    EndOfFile(void);
    ~EndOfFile(void);
};

class ReadError {
};

class UnknownObjectException : public std::exception {


	virtual const char* what() const throw() {
		return "Unknow object";
	}
};