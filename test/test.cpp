#define CATCH_CONFIG_MAIN
#include <SFML/Graphics.hpp>
#include <catch.hpp>
#include <game.h>
#include <iostream>
#include <levels.h>
#include <locale>
#include <menu.h>
#include <string>
#include <vector>

TEST_CASE("LEVELS", "")
{
    SECTION("init buttons")
    {
        std::vector<levelButton> buttons = initButtons();

        CHECK(buttons.size() == 5);
        system("pause");
    }
}

TEST_CASE("GAME", "")
{
    SECTION("get symbol width")
    {
        sf::Font font;
        font.loadFromFile("source/OpenSans-Regular.ttf");

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(48);

        text.setString("test string");
        CHECK(getSymbolWidth(text) == 28);

        text.setString("123");
        CHECK(getSymbolWidth(text) == 27);

        text.setString("iij");
        CHECK(getSymbolWidth(text) == 12);

        text.setString("a");
        CHECK(getSymbolWidth(text) == 0);

        text.setString("");
        CHECK(getSymbolWidth(text) == 0);
        system("pause");
    }
    SECTION("get buttons")
    {
        std::vector<button> buttons = getButtons();

        CHECK(buttons.size() == 26);
        system("pause");
    }

    SECTION("get active button id")
    {
        std::vector<button> buttons = getButtons();

        CHECK(getActiveButtonId(200, buttons) == -1);
        CHECK(getActiveButtonId(120, buttons) == 20);
        CHECK(getActiveButtonId(100, buttons) == 12);
        CHECK(getActiveButtonId(50, buttons) == -1);
        CHECK(getActiveButtonId(1, buttons) == -1);
        CHECK(getActiveButtonId(0, buttons) == -1);
        CHECK(getActiveButtonId(-1, buttons) == -1);
        system("pause");
    }
}
