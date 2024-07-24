#pragma once

#include <vector>
#include <string>
#include <filesystem>

#include "Walnut/Layer.h"

class LocatorLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Locator");

		if (ImGui::Button("Find...", ImVec2(100, 32)))
		{
			//TODO: open file dialog..
		}

		ImGui::End();
	}
};

enum class ESupportedGames : int
{
	GZDoom,
	Odamex
};

class GameLocator
{
public:

	GameLocator() {}
	GameLocator(const GameLocator& Other) = delete;

	void AutoDetect();
	void ManuallyAddGame(ESupportedGames Game, const std::filesystem::path& GamePath);

private:
	std::vector<ESupportedGames> GamesToTryDetecting;
	std::unordered_map<ESupportedGames, std::filesystem::path> DetectedGames;

};