#include "XmlMinification.h"
/*
    Description:Function removes spaces from start and end of the string
    Input:string
    Output:string
    Time Complexity: O(N)
    Space Complexity: O(N)
*/
std::string removeSpaces(std::string& str)
{
    std::string newString;
    int firstNonSpace = 0;
    int LastNonSpace = str.size() - 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (isspace(str[i]))
        {
            firstNonSpace++;
        }
        else
        {
            break;
        }
    }
    for (int i = str.size() - 1; i > 0; i--)
    {
        if (isspace(str[i]))
        {
            LastNonSpace--;
        }
        else
        {
            break;
        }
    }
    for (int i = firstNonSpace; i <= LastNonSpace; i++)
    {
        newString += str[i];
    }
    return newString;
}
/*
    Description:Minify XML
    Input:string
    Output:string
    Time Complexity: O(N)
    Space Complexity: O(N)
*/
std::string minifcation(const std::string& xml)
{
    std::string minifiedXML;
    std::string temp = "";
    int i = 0;
    while (i < xml.size())
    {
        if (xml[i] == '<')
        {
            while (i < xml.size())
            {
                if (xml[i] != '>')
                {
                    temp += xml[i];
                }
                else
                {
                    break;
                }
                i++;
            }
            temp += '>';
            temp = removeSpaces(temp);
            i++;
            minifiedXML += temp;
            temp = "";
        }
        else
        {
            while (i < xml.size())
            {
                if (xml[i] != '<')
                {
                    temp += xml[i];
                }
                else
                {
                    break;
                }
                i++;
            }
            temp = removeSpaces(temp);
            minifiedXML += temp;
            temp = "";
        }
    }
    return minifiedXML;
}