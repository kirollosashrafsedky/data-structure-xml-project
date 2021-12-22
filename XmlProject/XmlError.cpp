#include "XmlError.h"

XmlError::XmlError(int row, int col, std::string errorMsg) : row {row}, col {col}, errorMsg{errorMsg}
{

}

int XmlError::getRow() const
{
	return this->row;
}

void XmlError::setRow(int row)
{
	this->row = row;
}

int XmlError::getCol() const
{
	return this->col;
}

void XmlError::setCol(int col)
{
	this->col = col;
}

std::string XmlError::getErrorMsg() const
{
	return this->errorMsg;
}

void XmlError::setErrorMsg(std::string errorMsg)
{
	this->errorMsg = errorMsg;
}