#include <string>
#include "assignment_1.h"
using std::string;


bool writeFirstLine()
{
    Paper paper{};
    string userInput;

    int iterator = 0;
    for (string rowContent = paper.read(iterator);
        rowContent != "" && iterator <= paper.getHeight();
        iterator++);

    if (iterator <= paper.getHeight()) {
        paper.write(iterator, userInput);
        return true;
    } else return false;
}