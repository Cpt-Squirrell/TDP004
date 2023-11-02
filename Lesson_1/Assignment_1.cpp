#include <string>
using std::string;

int iterator = 0;
for (string rowContent = paper.readRow(iterator);
    rowContent != "" && iterator <= paper.getRows();
    iterator++);

if (iterator <= paper.getRows())
    paper.writeRow(iterator, content);