#pragma once

#include "engine/core/main/module.h"

namespace Echo
{
	class MiniSlamModule : public Module
	{
		ECHO_SINGLETON_CLASS(MiniSlamModule, Module)

	public:
		MiniSlamModule();
		virtual ~MiniSlamModule();

		// instance
		static MiniSlamModule* instance();

		// register all types of the module
		virtual void registerTypes() override;

	protected:
	};
}
