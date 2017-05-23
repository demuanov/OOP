#include "stdafx.h"
#include "Creator.h"

void main()
{
	Container < Shape > figures;

	try
	{
		int type;
		for (int i = 0; i < 25; i++)
		{
			type = rand() % 5 + 0;
			figures.add_last(figure(type));
		}

		std::cout << "Figures count: " << Shape::getcount() << std::endl;

		figures.terminator();

		std::cout << "Figures count: " << Shape::getcount() << std::endl;
	}
	catch (char const * error)
	{
		std::cout << error << std::endl;
	}


}