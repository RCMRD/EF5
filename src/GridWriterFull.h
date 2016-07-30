#ifndef GRIDWRITER_H
#define GRIDWRITER_H

#include <vector>
#include "Grid.h"
#include "GridNode.h"
#include "AscGrid.h"
#include "TifGrid.h"

class GridWriterFull {
	public:
		void Initialize();
		void WriteGrid(std::vector<GridNode> *nodes, std::vector<float> *data, const char *file, bool ascii = true);
		void WriteGrid(std::vector<GridNode> *nodes, std::vector<double> *data, const char *file, bool ascii = true);
	
	private:
		FloatGrid grid;
};

#endif
