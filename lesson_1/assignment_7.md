# Encapsulation
Encapsulation handlar om att skydda klassdata från missbruk och gömma klassdata från externa aktörer. Utan encapsulation skulle annars vilken extern klass som helst kunna råka förändra någonting i klassen som egentligen inte ska gå att förändra utan att samtidigt förändra någonting annat. Vad encapsulation gör är att det tvingar användaren till att använda de rutiner som klassen implementerar vars ansvar är att se till att datan den får in är korrekt och hanterad rätt.

## Exempel på dålig encapsulation
Följande bil-klass har sin hastighet öppen för ändring och tillåter okända aktörer förändra hastigheten utan att klassen får kännedom till detta.

`car.h`:
```c++
class Car {
public:
	double speed;

	Car() : speed(0.0) {}
};
```

## Exempel på bra encapsulation
Här ser vi till att variablerna `width`, `height`, och `content` inte går att meka med utanför klassdefinitionen. Om en extern aktör vill ändra på datan måste den läsa eller skriva med hjälp av funktionerna `getWidth()` och `getHeight()`.

`paper.h` (från uppgift 1):
```c++
#include <string>
class Paper
{
	public:
    	Paper();
    	Paper(int width, int row_count);

    	int getWidth();
    	int getHeight();

    	std::string read(int row);
    	void write(int row, std::string text);

	private:
    	int width;
    	int height;
        std::string content[];
};
```