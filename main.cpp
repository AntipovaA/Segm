#include <string>
#include <conio.h>
#include <thread>
#include <map>

#include "ApplicationFactory.h"
#include "filter.h"

using namespace std;
using namespace Service;
using namespace Service::Imaging;

int main(int argc, char *argv[])
{
	//Load tomography slices
	ApplicationFactory::Initializer(argv);
	ImageCollection *collection = ApplicationFactory::GetImageCollection();

	short iso_surface = 120;

	Filter *filter = new Filter(collection);
	filter->SegmentationBySettedThreshold(iso_surface);

	cout << "Segmentation have been finished!\n";
	getch();
	return 0;
}
