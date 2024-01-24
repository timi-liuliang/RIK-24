#include <engine/core/main/module.h>

namespace Echo
{
	void registerGameModules()
	{
		REGISTER_MODULE(MiniSlamModule)
		REGISTER_MODULE(OrbSlam3Module)
	}
}
