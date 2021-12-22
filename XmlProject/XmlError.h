#ifndef _XML_ERROR_
#define _XML_ERROR_

#include <string>

class XmlError
{
private:
	int row;
	int col;
	std::string errorMsg;

public:
	XmlError(int row = 0, int col = 0, std::string errorMsg = "");
	
	int getRow() const;
	void setRow(int row);

	int getCol() const;
	void setCol(int col);

	std::string getErrorMsg() const;
	void setErrorMsg(std::string errorMsg);
};

#endif /* _XML_ERROR_ */
