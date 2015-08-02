#include "UnknownFigure.h"

void UnknownFigure::read(DataProvider &provider) {
	int params_num = provider.rdInt();
	for (int i = 0; i < params_num; ++i) {
		params.push_back(provider.rdDouble());
	}
}

