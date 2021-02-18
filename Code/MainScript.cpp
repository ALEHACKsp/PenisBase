#include "MainScript.hpp"
#include "ScriptCallback.hpp"
#include "Lists.hpp"
#include "Natives.hpp"
#include "Timer.hpp"
#include "Translation.hpp"
#include "CustomText.hpp"
#include "UI/UIManager.hpp"
#include "UI/BoolOption.hpp"
#include "UI/ChooseOption.hpp"
#include "UI/NumberOption.hpp"
#include "UI/RegularOption.hpp"
#include "UI/SubOption.hpp"
#include "UI/RegularSubmenu.hpp"
#include "UI/PlayerSubmenu.hpp"

namespace Big
{
	enum Submenu : std::uint32_t
	{
		SubmenuHome,
		SubmenuSettings,
		SubmenuSettingsHeader,
		SubmenuSettingsHeaderStaticBackground,
		SubmenuSettingsHeaderGradientBackground,
		SubmenuSettingsHeaderText,
		SubmenuSettingsSubmenuBar,
		SubmenuSettingsOption,
		SubmenuSettingsFooter,
		SubmenuSettingsDescription,
		SubmenuSettingsInput,
		SubmenuSettingsLanguage,
		SubmenuSelectedPlayer,
		SubmenuPlayerList,
		SubmenuTest
	};

	bool MainScript::IsInitialized()
	{
		return m_Initialized;
	}

	ScriptType MainScript::GetType()
	{
		return ScriptType::Game;
	}

	void MainScript::Initialize()
	{
		m_Initialized = true;
		using namespace UserInterface;

		
		

		g_CustomText->AddText(CONSTEXPR_JOAAT("HUD_JOINING"), "Isn't " BIGBASE_NAME " the fucking best?");
		g_CustomText->AddText(CONSTEXPR_JOAAT("HUD_TRANSP"), "Isn't " BIGBASE_NAME " the fucking best?");

		g_UiManager->AddSubmenu<RegularSubmenu>("Home", SubmenuHome, [](RegularSubmenu* sub)
		{
			sub->AddOption<SubOption>("Players", nullptr, SubmenuPlayerList);
			sub->AddOption<SubOption>("Settings", nullptr, SubmenuSettings);
			sub->AddOption<RegularOption>("Simulate 10M shark card", "Unload the menu.", []
			{
					int jew = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1500000000, 2999999999);
					int ucbestsourceofcheats = 10000000;
					UNK3::_NETWORK_SHOP_BEGIN_SERVICE_2(&jew, 1474183246, 312105838, 1445302971, ucbestsourceofcheats, 4);
					UNK3::_NETWORK_SHOP_CHECKOUT_START(jew);
					NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(ucbestsourceofcheats);
					
					int iVar0;
					char rockstaraward[30], totalearned[23];
					"MP0_MPPLY_TOTAL_EVC";
					sprintf(rockstaraward, "MP0_MONEY_EARN_ROCKSTAR_AWARD");
					sprintf(totalearned, "MP0_MPPLY_TOTAL_EARNED");
					STATS::STAT_GET_INT(CONSTEXPR_JOAAT("MP0_MONEY_EARN_ROCKSTAR_AWARD"), &iVar0, -1);
					STATS::STAT_SET_INT(CONSTEXPR_JOAAT("MP0_MONEY_EARN_ROCKSTAR_AWARD"), iVar0 + ucbestsourceofcheats, 1);
					STATS::STAT_GET_INT(CONSTEXPR_JOAAT("MP0_MPPLY_TOTAL_EARNED"), &iVar0, -1);
					STATS::STAT_SET_INT(CONSTEXPR_JOAAT("MP0_MPPLY_TOTAL_EARNED"), iVar0 + ucbestsourceofcheats, 1);
			});

			sub->AddOption<RegularOption>("Unload", "Unload the menu.", []
			{
				g_Running = false;
			});
		});


		g_UiManager->AddSubmenu<RegularSubmenu>("Players", SubmenuPlayerList, [](RegularSubmenu* sub)
		{
			for (std::uint32_t i = 0; i < 32; ++i)
			{
				if (auto ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))
				{
					sub->AddOption<SubOption>(PLAYER::GET_PLAYER_NAME(i), nullptr, SubmenuSelectedPlayer, [=]
					{
						g_SelectedPlayer = i;
					});
				}
			}
		});

		g_UiManager->AddSubmenu<PlayerSubmenu>(&g_SelectedPlayer, SubmenuSelectedPlayer, [](PlayerSubmenu* sub)
		{
			sub;
		});
	}

	void MainScript::Destroy()
	{
		g_UiManager.reset();
	}

	void MainScript::Tick()
	{
		g_UiManager->OnTick();
		UNK3::DISABLE_ARXAN(); //Call it before any internal native that is protected
		UNK3::DISABLE_ROCKSTAR_AC_THIS_FRAME(); //Works online too
		PENIS::SET_CUSTOM_FPS(20.f);
		PENIS::GIVE_BIG_PP();
		//PENIS:: for our custom natives
	}
}
