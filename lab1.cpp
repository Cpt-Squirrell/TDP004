#include <iostream>
#include <iomanip>
#include <string>

// Skriv ett program som hämtar data från tangentbordet enligt exemplen som följer. Det som syns på
// skärmen när man kör programmet skall stämma till fullo överens med det som står i exemplen. Detta
// gäller även antal blanktecken mellan ord och tal.


using namespace std; //Usch! Dålig praxis. ye

//antar dem att vi ska använda std::string eller char pekare?
//Std::string

//intressant att dem föredrar {} initiering
// Det är det moderna sättet att initiera. Är mycker mer typsäkert. yes


int main(int argc, char** argv)
{
    /*
        --Skriv in ett heltal: 10
        --Du skrev in talet: 10
        --Skriv in fem heltal: 12 30 27 13 11
        --Du skrev in talen: 12, 30, 27, 13, 11
        Skriv in ett flyttal: 15.20
        Du skrev in flyttalet: 15.200
        Skriv in ett heltal och ett flyttal: 67 3.141592
        Du skrev in heltalet: 67
        Du skrev in flyttalet: 3.142
        Skriv in ett flyttal och ett heltal: 3.141592 54
        Du skrev in heltalet:--------54
        Du skrev in flyttalet:----3.142
        Skriv in ett tecken: T
        Du skrev in tecknet: T
        Skriv in en sträng: Kalle
        Strängen 'Kalle' har 5 tecken.
        Skriv in ett heltal och en sträng: -5 Nisse
        Du skrev in talet |-5| och strängen |Nisse|.
        Skriv in en sträng och ett flyttal: Ria 1.2
        Du skrev in "1.200" och "Ria".
        Skriv in en hel rad med text: Bä, bä vita lamm har du
        Du skrev in textraden: 'Bä, bä vita lamm har du'
        Skriv in en textrad som slutar med ett negativt heltal: Det är kallt, -10
        Du skrev in textraden: 'Det är kallt, ' och heltalet '-10'
    */
    
    // Man får enbart använda en enda deklaration av varje datatyp.
    //hur funkar det att mata in fem heltal, vektor eller loop, vi får inte använda loopar
    // En whitespace-delad sträng som man läser in med flera cin's. Tydligen kan man göra så.

    int integer{};
    float floating{};
    std::string text{}; 
    
    
    std::cout << "Skriv in ett heltal: ";
    std::cin >> integer;
    std::cout << "Du skev in talet: " << integer << std::endl;

    std::cout << "Skriv in fem heltal: ";
    //så vi sparar allt i text
    std::cin >> integer;
    text += std::to_string(integer) + ", ";
    std::cin >> integer;
    text += std::to_string(integer) + ", ";
    std::cin >> integer;
    text += std::to_string(integer) + ", ";
    std::cin >> integer;
    text += std::to_string(integer) + ", ";
    std::cin >> integer;
    text += std::to_string(integer);
    std::cout << "Du skrev in talen: " << text << std::endl;
    
    std::cout << "Skriv in ett flyttal: " << std::endl;
    std::cin >> floating;
    std::cout << "Du skrev in flyttalet: " << floating << std::endl;

    std::cout << "Skriv in ett heltal och ett flyttal: ";
    std::cin >> integer;
    std::cin >> floating;
    std::cout << "Du skrev in heltalet: " << integer << std::endl; // TODO: Must add whitespace to fill out
    //std::setw(10) << std::setfill('-') << std::setprecision(4)
    std::cout << "Du skrev in flyttalet: " << floating << std::endl; // TODO: --||--
//hmm vet inte exakta parametrarna, w ska nog vara 10, fill med streck. Denna ska ha whitespaces
// Vilket bibliotek finns detta i? iomanip antagligen? tror jag. Aldrig använt iomanip. inget jag har använt själv, men det typ ja, som angivet i pdfen, ändrar utmatningen
    //precision vet jag inte
    //jag äter nu så blir lite halvt afk men jag kollar
    // Jag tar och åker hem och hoppar på hemdatorn istället.
    //glöm inte pusha till gitlab Ah yes! :)
    std::cout << "Skriv in ett flyttal och ett heltal: ";
    std::cin >> floating;
    std::cin >> integer;
    std::cout << "Du skrev in heltalet: " << integer << std::endl; // TODO: Must add hyphens to fill out
    std::cout << "Du skrev in flyttalet: " << floating << std::endl; // TODO: --||--


    return 0;
}

