#include <iostream>
#include <iomanip>

// Komplettering: Använd filändelserna .h/.cc för era filer.
//klar.

// Komplettering: Utskriften följer inte det givna körexemplet. Formateringen är inte korrekt. (använd inte 'tab', formatera med det vi lärt er i kursen istället.)
//klar.

// Komplettering: loopen för felhantering av inmatning är inte okej. Att artificiellt sätta värdet till något ogiltigt för att tvinga loopen att köra ett första varv är inte bra. Då finns det ett bättre val av loop att använda.
//klar.

// Komplettering: momsprocenten får vara maximalt 100.
//klar.

using namespace std;

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
    cout << setw(12) << setprecision(2) << fixed;
    cout << "INMATNINGSDEL\n" << setw(12) << setfill('=') << "=" << endl << setfill(' ');
    
    float firstPrice{};
    float lastPrice{};
    float stepLength{};
    float tax{};

    do {
        cout << "Mata in första pris: " << flush;
        cin >> firstPrice;
        if (firstPrice < 0.00f)
            cout << "Första pris måste vara minst 0 kronor!" << endl;
        else
            break;
    } while(true);

    do {
        cout << "Mata in sista pris: " << flush;
        cin >> lastPrice;
        if (lastPrice > 100000.00f || lastPrice <= firstPrice)
            cout << "Sista pris måste vara större än första pris och mindre än 100 000 kronor!" << endl;
        else
            break;
    } while(true);
    
    do {
        cout << "Mata in steglängd: " << flush;
        cin >> stepLength;    
        if (stepLength < 0.01f)
            cout << "Steglängden kan inte vara kortare än 0.01!" << endl;
        else
            break;
    } while(true);

    do {
        cout << "Mata in momsprocent: " << flush;
        cin >> tax;
        if (tax < 0.00f)
            cout << "Momsprocenten måste vara minst 0% (detta är ingen välfärd)!" << endl;
        else if(tax > 100.00f)
            cout << "Momsprocenten måste vara högst 100% !" << endl;
        else
            break;
    } while(true);

    tax *= 0.01; // Make tax into 0.0 - 1.0 interval
    
    cout << "MOMSTABELLEN\n" << setw(12) << setfill('=') << "=" << endl << setfill(' ');
    cout << setw(12) << "Pris"<<setw(14) <<"Moms"<<setw(21) <<"Pris med moms" << endl;
    cout << setw(48) << setfill('-') << " " << endl << setfill(' ');
    
    int iterator = 0;
    for (float price = firstPrice; price - lastPrice <= 0.001f; price = firstPrice + stepLength * (iterator++))
    {
        cout << setw(12) << price << setw(14) << calculateVAT(price, tax) << setw(21) << calculatePriceVAT(price, tax) << endl;
    }
    
    return 0;
}
