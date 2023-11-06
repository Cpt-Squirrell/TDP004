#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

int main()
{
    int integer{};
    float floating{};
    std::string text{}; 
    char character{};
    
    cout << "Skriv in ett heltal: ";
    cin >> integer;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Du skev in talet: " << integer << std::endl;

    cout << "Skriv in fem heltal: ";
    cin >> integer;
    cout << "Du skrev in talen: "
         << integer << ", ";
    cin >> integer;
    cout << integer << ", ";
    cin >> integer;
    cout << integer << ", ";
    cin >> integer;
    cout << integer << ", ";
    cin >> integer;
    cout << integer << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    std::cout << "Skriv in ett flyttal: " << std::flush;
    std::cin >> floating;
    std::cout << std::fixed << std::setprecision(3) << "Du skrev in flyttalet: " << floating << std::endl;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::cout << "Skriv in ett heltal och ett flyttal: ";
    std::cin >> integer >> floating;
    std::cout << "Du skrev in heltalet:" << std::setw(10) << integer << std::endl;
    std::cout << "Du skrev in flyttalet:" << std::setw(9) << floating << std::endl;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::cout << "Skriv in ett flyttal och ett heltal: ";
    std::cin >> floating >> integer;
    std::cout << "Du skrev in heltalet:" << std::setw(10) << std::setfill('-') << integer << std::endl;
    std::cout << "Du skrev in flyttalet:" << std::setw(9) << std::setfill('-') << floating << std::endl;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    std::cout << "Skriv in ett tecken: ";
    std::cin >> character;
    std::cout << "Du skrev in tecknet: " << character << std::endl;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::cout << "Skriv in en sträng: ";
    std::cin >> text;
    std::cout << "Strängen '" << text << "' har " << text.length() << " tecken." << std::endl;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::cout << "Skriv in ett heltal och en sträng: ";
    std::cin >> integer >> text;
    std::cout << "Du skrev in talet |" << integer << "| och strängen |" << text << "|." << std::endl;

    std::cout << "Skriv in en sträng och ett flyttal: ";
    std::cin >> text >> floating;
    std::cout << "Du skrev in \"" << floating << "\" och \"" << text << "\"." << std::endl;  
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Skriv in en hel rad med text: ";
    getline(std::cin, text);
    cout << "Du skrev in textraden: \'" << text << "\'" << std::endl;

    std::cout << "Skriv in en textrad som slutar med ett negativt heltal: ";
    std::getline(std::cin, text, '-');
    std::cin >> integer;
    std::cout << "Du skrev in textraden: '" << text << "' och heltalet '-" << integer << "'" << std::endl;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return 0;
}

