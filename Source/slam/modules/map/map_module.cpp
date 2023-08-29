#include <assert.h>
#include "map_module.h"
#include "features/features2d.h"
#include "matcher/descriptor_matcher.h"

namespace Echo
{
	DECLARE_MODULE(MapModule, __FILE__)

	MapModule::MapModule()
	{
		Features2D ORBFeatures1;
		ORBFeatures1.detect("D:/test1.jpeg", Features2D::CV_ORB, 250);
		//ORBFeatures1.debugShow();

		Features2D ORBFeatures2;
		ORBFeatures2.detect("D:/test2.jpeg", Features2D::CV_ORB, 250);

		DescriptorMatcher matcher;
		matcher.match(ORBFeatures1, ORBFeatures2);
		matcher.debugShow();
	}

	MapModule::~MapModule()
	{
	}

	MapModule* MapModule::instance()
	{
		static MapModule* inst = EchoNew(MapModule);
		return inst;
	}

	void MapModule::bindMethods()
	{
	}

	void MapModule::registerTypes()
	{

	}
}
