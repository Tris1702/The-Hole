//
// Created by phuonghoa on 26/10/2020.
//
#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Menu {
private:
    Sprite backgroundmenu;
    Sprite startbutton;
    Sprite theme;
    float deltatime=0;
    IntRect uvRect3;
    Text text;
    Text title;
    Font font;
public:
    Menu(Texture &starttexture,Texture &theme,Texture &backgroundtexture, int windowX,int windowY);
    ~Menu();

public:
    Sprite getBackGround();
    Sprite getStartButton();
    Sprite getTheme();
    void update(float time);
    Text getText();
    Text getTitle();
};
