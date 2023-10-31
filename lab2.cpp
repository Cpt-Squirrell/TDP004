#include <iostream>
#include <string>
#include <iomanip>
#include <type_traits>

using std::string, std::cout, std::cin, std::endl, std::flush;

float getInput(string variableName, float minValue = -100.0f, float maxValue = 100000.00f)
{
    float number{};
    do {
        cout << "Mata in " << variableName << ": ";
        cin >> number;
        if(number < maxValue)
            cout << "FEL: "<< variableName <<" måste vara minst " << minValue;
    } while (number >= maxValue || number <= minValue);
    return number;
}

void generateList(float firstPrice, float lastPrice, float stepLength, float momsPercentage)
{
    cout << "\tPris\tMoms\tPris med moms\n-----------------------------------" << endl;
    
    //Generate formated generated tax list
    for(float price = firstPrice ;price <= lastPrice; price += stepLength)
    {
        cout << "\t" << price <<"\t" << price <<"\t" << price << endl;
    }
}

int main(int argc, char* argv[])
{


    cout << "INMATNINGSDEL\n============" << endl;
    float firstPrice{       getInput("första pris")};
    float lastPrice{        getInput("sista pris")};
    float stepLength{       getInput("steglängd")};
    float momsPercentage{   getInput("momsprocent")};
    
    cout << "MOMSTABELLEN\n============" << endl;
    generateList(firstPrice, lastPrice, stepLength, momsPercentage);
    cout << endl;
    
    return 0;
}