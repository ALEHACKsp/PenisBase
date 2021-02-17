#include "Game.hpp"
#include "Invoker.hpp"

namespace Big
{
	GameVariables::GameVariables():
		m_GameState(Signature("48 85 C9 74 4B 83 3D").Scan().Add(7).Rip().As<decltype(m_GameState)>()),
		m_FrameCount(Signature("F3 0F 10 0D ? ? ? ? 44 89 6B 08").Scan().Add(4).Rip().Sub(8).As<decltype(m_GameState)>()),
		m_GameWindow(FindWindowA("grcWindow", "Grand Theft Auto V")),
		m_Swapchain(Signature("48 8B 0D ? ? ? ? 48 8D 55 A0 48 8B 01").Scan().Add(3).Rip().As<decltype(m_Swapchain)&>()),
		m_NativeRegistrations(Signature("48 83 EC 20 48 8D 0D ? ? ? ? E8 ? ? ? ? 0F B7 15 ? ? ? ? 33 FF").Scan().Add(7).Rip().As<decltype(m_NativeRegistrations)>()),
		m_GlobalBase(Signature("4C 8D 4D 08 48 8D 15 ? ? ? ? 4C 8B C0").Scan().Add(7).Rip().As<decltype(m_GlobalBase)>()),
		m_RockstarACBypassBetta(Signature("4C 8D 05 ? ? ? ? 0F B7 C1").Scan().As<decltype(m_RockstarACBypassBetta)>())
	{
		auto sig = Signature("48 83 EC 60 48 8D 0D ? ? ? ? E8").Scan().Sub(17);
		m_GameBuild = sig.Add(265 + 3).Rip().As<decltype(m_GameBuild)>();
	}

	void GameVariables::PostInit()
	{
	}

	GameFunctions::GameFunctions():
		m_IsDlcPresent(Signature("48 89 5C 24 ? 57 48 83 EC 20 81 F9 ? ? ? ? 75 08 8A 05 ? ? ? ? EB 6B 81 F9 ? ? ? ? 75 40 E8 ? ? ? ? 33 DB 85 C0 75 2F 8B C8 E8 ? ? ? ? 48 8B C8 48 8B F8 E8 ? ? ? ? 84 C0 74 0D 8D 53 0C 48 8B CF E8 ? ? ? ? EB 0E B9 ? ? ? ? E8 ? ? ? ? EB 02 8A C3 84 C0 EB 20 81 F9 ? ? ? ? 75 07 E8 ? ? ? ? EB 14 8B D1 48 8B 0D ? ? ? ? E8 ? ? ? ? 48 85 C0 0F 95 C0 48 8B 5C 24 ? 48 83 C4 20 5F C3").Scan().As<decltype(m_IsDlcPresent)>()),
		m_WndProc(Signature("48 8B 0D ? ? ? ? 48 8D 55 EF FF 15").Scan().Sub(853).As<decltype(m_WndProc)>()),
		m_GetEventData(Signature("48 85 C0 74 14 4C 8B 10").Scan().Sub(28).As<decltype(m_GetEventData)>()),
		m_GetLabelText(Signature("75 ? E8 ? ? ? ? 8B 0D ? ? ? ? 65 48 8B 04 25 ? ? ? ? BA ? ? ? ? 48 8B 04 C8 8B 0C 02 D1 E9").Scan().Sub(19).As<decltype(m_GetLabelText)>())
	{
	}
}
