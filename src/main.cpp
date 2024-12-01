#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
    void playerDestroyed(bool isPlayer2) {
        PlayerObject::playerDestroyed(isPlayer2);
        if (Mod::get()->getSettingValue<bool>("enabled")) {
            if (auto playLayer = PlayLayer::get()) {
                return playLayer->onQuit();
            }
        }
    }
};
