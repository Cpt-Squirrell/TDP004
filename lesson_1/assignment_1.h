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
