# Fria funktioner och medlemsfunktioner
I C++ finns det två huvudtyper av funktioner: vanliga "fria" funktioner och medlemsfunktioner.

## Fria funktioner
- En vanlig "fri" funktion är en funktion som inte är kopplad till någon specifik klass.
- Den har ingen direkt åtkomst till klassens medlemsvariabler eller medlemsfunktioner.
- Används med hjälp av funktionsanrop och är inte kopplad till en specifik objektinstans.

### Exempel
```c++
    #include <iostream>

    // En vanlig fri funktion
    int add(int a, int b) {
        return a + b;
    }

    int main() {
        int result = add(3, 5); // Anropar den fria funktionen
        std::cout << "Resultat: " << result << std::endl;
        return 0;
    }
```

## Medlemsfunktioner
- En medlemsfunktion är en funktion som är kopplad till en specifik klass och har tillgång till klassens medlemsvariabler och medlemsfunktioner.
- Den måste anropas via en objektinstans av klassen.

### Exempel
I det här andra exemplet ser man att `add()` är en medlemsfunktion av klassen `Calculator`, och den måste anropas genom att först skapa en objektinstans av klassen. Denna funktion har direkt åtkomst till klassens medlemsvariabler och kan manipulera dem. Vanliga "fria" funktioner, å andra sidan, är oberoende av klasser och har ingen åtkomst till klassens medlemsvariabler eller medlemsfunktioner.

```c++
    #include <iostream>

    class Calculator {
    public:
        int add(int a, int b) {
            return a + b;
        }
    };

    int main() {
        Calculator calc; // Skapa en objektinstans av klassen Calculator
        int result = calc.add(3, 5); // Anropar medlemsfunktionen via objektinstansen
        std::cout << "Resultat: " << result << std::endl;
        return 0;
    }
```