#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include "tinyfiledialogs/tinyfiledialogs.h"
#include "nano_signal_slot.hpp"

#include "Walnut/Layer.h"

Nano::Signal<void(std::filesystem::path)> GamePathProvidedSignal;

class LocatorLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Locator");
		ImGui::Text("Please provide the location of GZDoom.exe...");
		if (ImGui::Button("Find...", ImVec2(100, 32)))
		{
			//TODO: open file dialog..
			std::string pathstring = tinyfd_openFileDialog("Find Game", "", 0, NULL, NULL, 0);
			std::filesystem::path path(pathstring);

			//TODO: push a signal that indicates that gzdoom has been found at the provided path
			GamePathProvidedSignal.fire(path);
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

	GameLocator() 
	{
		GamePathProvidedSignal.connect<&GameLocator::HandleGameFoundSignal>(this);
	}
	GameLocator(const GameLocator& Other) = delete;

	void AutoDetect();
	void ManuallyAddGame(ESupportedGames Game, const std::filesystem::path& GamePath);

private:
	//takes the path found by the file picker UI and applies it to the game settings
	void HandleGameFoundSignal(std::filesystem::path NewGamePath)
	{
		GamePath = NewGamePath;
		std::string WeGotHere;
	}


	std::filesystem::path GamePath;

};