#ifndef BG_BRIGHT_WARRIOR_CONTROLLER_COMPONENT_H__
#define BG_BRIGHT_WARRIOR_CONTROLLER_COMPONENT_H__

#include "ControllerComponent.h"

class BG_BrightWarriorControllerComponent : public BG_ControllerComponent
{
public:
	BG_BrightWarriorControllerComponent();

	void OnTick(float deltaTime) HKV_OVERRIDE;

private:
	void SetOwner(VisTypedEngineObject_cl *newOwner) HKV_OVERRIDE;


	V_DECLARE_SERIAL_DLLEXP(BG_BrightWarriorControllerComponent, BG_PLUGIN_IMPEXP);
	V_DECLARE_VARTABLE(BG_BrightWarriorControllerComponent, BG_PLUGIN_IMPEXP);
};

namespace BG_BrightWarriorControllerState
{
	class Idling : public BG_ControllerStateBase
	{
		void OnTick(BG_ControllerComponent *controller, float deltaTime) HKV_OVERRIDE;

		char const *GetName() const HKV_OVERRIDE { return "BrightWarrior::Idling"; }
	};

	class Moving : public BG_ControllerState::Moving
	{
		void OnTick(BG_ControllerComponent *controller, float deltaTime) HKV_OVERRIDE;

		char const *GetName() const HKV_OVERRIDE { return "BrightWarrior::Moving"; }
	};
}

#endif

//TODO: ovo treba da se refaktorise i da se prebace sve zajedniceke funkcije sa DarkWarriorController u nadklasu
// za sad su iste, bukvalno :D