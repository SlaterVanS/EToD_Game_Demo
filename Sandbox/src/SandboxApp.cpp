#include <ETOD.h>
#include <ETOD/Core/EntryPoint.h>

#include "GameLayer.h"

class Sandbox : public ETOD::Application
{
public:
	Sandbox()
	{
		PushLayer(new GameLayer());
	}

	~Sandbox()
	{
	}
};

ETOD::Application* ETOD::CreateApplication()
{
	return new Sandbox();
}