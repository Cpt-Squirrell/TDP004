#include <iostream>
#include <iomanip>

using std::cout, std::cin, std::endl, std::flush;

float calculateVAT(float originalPrice, float tax)
{
    return originalPrice * tax;
}

float calculatePriceVAT(float originalPrice, float tax)
{
    return originalPrice + calculateVAT(originalPrice, tax);
}

int main(int argc, char* argv[])
{
    cout << std::setw(12) << std::setprecision(2) << std::fixed;

    cout << "INMATNINGSDEL\n"
         << "============";
    
    float firstPrice = -1.00f;
    while (firstPrice < 0.00f) {
        cout << "Mata in första pris: " << flush;
        cin >> firstPrice;
        if (firstPrice < 0.00f)
            cout << "Första pris måste vara minst 0 kronor!" << endl;
    }

    float lastPrice = 100001.00f;
    while (lastPrice > 100000.00f || lastPrice < firstPrice) {
        cout << "Mata in sista pris: " << flush;
        cin >> lastPrice;
        if (lastPrice > 100000.00f || lastPrice < firstPrice)
            cout << "Sista pris måste vara större än första pris och mindre än 100 000 kronor!" << endl;
    }
    
    float stepLength = 0.00f;
    while (stepLength < 0.01f) {
        cout << "Mata in steglängd: " << flush;
        cin >> stepLength;    
        if (stepLength < 0.01f)
            cout << "Steglängden kan inte vara kortare än 0.01!" << endl;
    }

    float tax = -1.00f;
    while (tax < 0.00f) {
        cout << "Mata in momsprocent: " << flush;
        cin >> tax;
        if (tax < 0.00f)
            cout << "Momsprocenten måste vara minst 0% (detta är ingen välfärd)!" << endl;
    }
    tax *= 0.01; // Make tax into 0.0 - 1.0 interval
    
    cout << "MOMSTABELLEN\n"
         << "============\n";

    cout << "\tPris\tMoms\tPris med moms\n"
         << std::setfill('-') << "\t\t\t"
         << std::setfill(' ') << endl;
    
    for (float price = firstPrice; price - lastPrice <= 0.001f; price += stepLength)
    {
        cout << '\t' << price << '\t' << calculateVAT(price, tax) << '\t' << calculatePriceVAT(price, tax) << endl;
    }
    
    return 0;
}