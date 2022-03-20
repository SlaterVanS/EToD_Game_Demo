#pragma once


#ifdef ETOD_PLATFORM_WINDOWS

extern ETOD::Application* ETOD::CreateApplication();

int main(int argc,char** argv)
{
	ETOD::Log::Init();
	ETOD_CORE_WARN("��ʼ����־ϵͳ! ");
	ETOD_INFO(" EToD Engine ���������! ");

	ETOD_PROFILE_BEGIN_SESSION("Startup", "EToDProfile-Startup.json");
	auto app = ETOD::CreateApplication();
	ETOD_PROFILE_END_SESSION();

	ETOD_PROFILE_BEGIN_SESSION("Runtime", "EToDProfile-Runtime.json");
	app->Run();
	ETOD_PROFILE_END_SESSION();

	ETOD_PROFILE_BEGIN_SESSION("Startup", "EToDProfile-Shutdown.json");
	delete app;
	ETOD_PROFILE_END_SESSION();
}

#endif