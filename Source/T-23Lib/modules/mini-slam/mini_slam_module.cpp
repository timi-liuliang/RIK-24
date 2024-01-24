#include <assert.h>
#include "mini_slam_module.h"
#include "mini-slam/features/descriptor_matcher.h"

namespace Echo
{
	DECLARE_MODULE(MiniSlamModule, __FILE__)

	MiniSlamModule::MiniSlamModule()
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

	MiniSlamModule::~MiniSlamModule()
	{
	}

	MiniSlamModule* MiniSlamModule::instance()
	{
		static MiniSlamModule* inst = EchoNew(MiniSlamModule);
		return inst;
	}

	void MiniSlamModule::bindMethods()
	{
	}

	void MiniSlamModule::registerTypes()
	{

	}
}
