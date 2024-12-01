#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
    void playerDestroyed(bool isPlayer2) {
        bool isEnabled = Mod::get()->getSettingValue<bool>("enabled");

        if (isEnabled) {
            PlayerObject::playerDestroyed(isPlayer2);

            auto playLayer = PlayLayer::get();
            if (playLayer) {
                playLayer->onQuit();
            }
            return;
        }

        PlayerObject::playerDestroyed(isPlayer2);
    }
};