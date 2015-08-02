#include "ObjectFactory.h"
#include <iostream>
#include <string>
#include "Exceptions.h"
#include "BaseFigure.h"
#include "Square.h"
#include "TypesEnum.h"
#include "DataProvider.h"
#include "Arc.h"
#include "Polygon_Line.h"
#include "UnknownFigure.h"

int main()
{

	GenericObjectFactory<int, BaseFigure> figureFactory;
	figureFactory.add<Square>((int)FigureTypes::square);
	figureFactory.add<Circle>((int)FigureTypes::circle);
	figureFactory.add<Arc>((int)FigureTypes::anc);
	figureFactory.add<Polygon_Line>((int)FigureTypes::polygon_line);
	figureFactory.add<Polygon>((int)FigureTypes::polygon);


	DataProvider provider;
	WDraw drawer;
	try {
		int objects_num = provider.rdInt();

		for (int i = 0; i < objects_num; ++i) {
			int id = provider.rdInt();
			BaseFigure *figure = figureFactory.get(id)();
			std::cout << int(figure->type()) << std::endl;
			figure->read(provider);
			figure->draw(drawer);
		}

		provider.rdDouble();
	}
	catch (ReadError) {
		std::cerr << "Reading error." << std::endl;
	}
	catch (EndOfFile) {
		std::cerr << "End of file reached." << std::endl;
	}

	system("pause");
}