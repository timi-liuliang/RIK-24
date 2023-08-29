#pragma once

#include "engine/core/main/module.h"

namespace Echo
{
	class MapModule : public Module
	{
		ECHO_SINGLETON_CLASS(MapModule, Module)

	public:
		MapModule();
		virtual ~MapModule();

		// instance
		static MapModule* instance();

		// register all types of the module
		virtual void registerTypes() override;

	protected:
	};
}
