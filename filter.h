#pragma once

#include <vector>
#include "ImageCollection.h"

using namespace std;

namespace Service
{
	namespace Imaging
	{

		class Filter
		{
		public:
			//CreateFilters class constructor
			Filter(ImageCollection*);

			//Binary segmentation function
			void SegmentationBySettedThreshold(short iso_surface);

		private:
			ImageCollection* collection;
			short cores;
		};
	}
}
