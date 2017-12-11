#include "filter.h"
#include "ImageCollection.h"
#include <Windows.h>
#include <thread>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using namespace Service;
using namespace Service::Imaging;

Filter::Filter(ImageCollection* collection)
{
	this->collection = collection;

	SYSTEM_INFO info;
	GetSystemInfo(&info);
	cores = (short)info.dwNumberOfProcessors;
}


void Filter::SegmentationBySettedThreshold(short iso_surface)
{
	collection->SegmentationMark = SettedThreshold;
	Image *images = collection->GetImages();
	short count = collection->GetCount();
	short rows = images[0].Rows;
	short columns = images[0].Columns;

	for (short k = 0; k < count; ++k)
	{
		for (short j = 0; j < rows; ++j)
		{
			for (short i = 0; i < columns; ++i)
			{
				if (images[k].Data[j][i] > iso_surface)
					images[k].Data[j][i] = 1;

				else
					images[k].Data[j][i] = 0;
			}
		}
	}
}

