#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using std::cin, std::cout, std::numeric_limits, std::streamsize;

int main(int argc, char** argv)
{
    int integer{};
    float floating{};
    std::string text{}; 
    char character{};
    
    std::cout << "Skriv in ett heltal: ";
    std::cin >> integer;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cout << "Du skev in talet: " << integer << std::endl;

    std::cout << "Skriv in fem heltal: ";
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
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    std::cout << "Skriv in ett flyttal: " << std::flush;
    std::cin >> floating;
    std::cout << std::fixed << std::setprecision(3) << "Du skrev in flyttalet: " << floating << std::endl;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::cout << "Skriv in ett heltal och ett flyttal: ";
    std::cin >> integer;
    std::cin >> floating;
    std::cout << "Du skrev in heltalet:" << std::setw(10) << integer << std::endl; // TODO: Must add whitespace to fill out
    std::cout << "Du skrev in flyttalet:" << std::setw(9) << floating << std::endl; // TODO: --||--
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::cout << "Skriv in ett flyttal och ett heltal: ";
    std::cin >> floating;
    std::cin >> integer;
    std::cout << "Du skrev in heltalet:" << std::setw(10) << std::setfill('-') << integer << std::endl; // TODO: Must add hyphens to fill out
    std::cout << "Du skrev in flyttalet:" << std::setw(9) << std::setfill('-') << floating << std::endl; // TODO: --||--
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
    std::cin >> integer;
    std::cin >> text;
    std::cout << "Du skrev in talet |" << integer << "| och strängen |" << text << "|." << std::endl;

    std::cout << "Skriv in en sträng och ett flyttal: ";
    std::cin >> text;
    std::cin >> floating;
    std::cout << "Du skrev in \"" << floating << "\" och \"" << text << "\"." << std::endl;  
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::cout << "Skriv in en hel rad med text: ";
    std::getline(std::cin, text);
    std::cout << "Du skrev in textraden: \'" << text << "\'" << std::endl;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::cout << "Skriv in en textrad som slutar med ett negativt heltal: ";
    std::getline(std::cin, text, '-');
    std::cin >> integer;
    std::cout << "Du skrev in textraden: '" << text << "' och heltalet '-" << integer << "'" << std::endl;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return 0;
}

