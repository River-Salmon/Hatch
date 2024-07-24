#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"

class FriendsLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Friends");
		ImGui::End();
	}
};

class SessionLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Session");
		ImGui::End();
	}
};

class LogLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Log");
		ImGui::End();
	}
};

class PlayLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Play");
		ImGui::End();
	}
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "HELL HATCH";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<FriendsLayer>();
	app->PushLayer<SessionLayer>();
	app->PushLayer<LogLayer>();
	app->PushLayer<PlayLayer>();
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Mods"))
		{
			if (ImGui::MenuItem("Manage..."))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Multiplayer"))
		{
			if (ImGui::MenuItem("View Friends"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}