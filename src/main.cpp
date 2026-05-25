#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(BumsMenuLayer, MenuLayer) {
    void onMoreGames(CCObject* sender) {
        FLAlertLayer::create(
            "Bums!",
            "Bums! This mod makes frame perfects WAY easier! fuck you salto",
            "OK"
        )->show();
    }
};

class $modify(BumsPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;

        auto label = CCLabelBMFont::create("Bums! Active", "chatFont.fnt");
        label->setPosition({ 55.f, 10.f });
        label->setScale(0.6f);
        label->setOpacity(180);
        label->setColor({ 255, 200, 50 });
        label->setZOrder(100);
        label->setID("bums-label"_spr);
        this->addChild(label);

        return true;
    }
};
