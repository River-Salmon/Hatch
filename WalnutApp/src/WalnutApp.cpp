#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"
#include "GameLocator/GameLocator.h"

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
		if (ImGui::Button("PLAY", ImVec2(600, 200)))
		{
			//Launch Game...
		}
		ImGui::End();
	}
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "HELL HATCH";

	//TODO: restart via steam

	//TODO: Steam init

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<FriendsLayer>();
	app->PushLayer<SessionLayer>();
	app->PushLayer<LogLayer>();
	app->PushLayer<PlayLayer>();

	std::unique_ptr<GameLocator> Locator = std::make_unique<GameLocator>();

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
		if (ImGui::BeginMenu("Games"))
		{
			if (ImGui::MenuItem("Manage..."))
			{
				app->PushLayer<LocatorLayer>();
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