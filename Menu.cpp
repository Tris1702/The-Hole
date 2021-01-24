//
// Created by phuonghoa on 26/10/2020.
//
#include "Menu.h"
#include<iostream>
Menu::Menu(Texture &starttexture, Texture &theme,Texture &backgroundtexture, int windowX,int windowY)
{
    IntRect uvRect1, uvRect2;
    this->deltatime+=0.01;
    uvRect2.left=0;
    uvRect2.top=0;
    uvRect2.width=windowX;
    uvRect2.height=windowY;

    uvRect3.top=0;
    uvRect3.left=0;
    uvRect3.width=theme.getSize().x/24;
    uvRect3.height=theme.getSize().y;

    uvRect1.left=0;
    uvRect1.top=0;
    uvRect1.width=starttexture.getSize().x/2;
    uvRect1.height=starttexture.getSize().y/3;

    this->startbutton.setTexture(starttexture);
    this->startbutton.setTextureRect(uvRect1);
    this->backgroundmenu.setTexture(backgroundtexture);
    this->backgroundmenu.setTextureRect(uvRect2);
    this->theme.setTexture(theme);
    this->theme.setTextureRect(uvRect3);

    this->theme.setScale(5.0,5.0);
    this->startbutton.setScale(5.0,5.0);

    this->theme.setOrigin(-67,-60);
    this->startbutton.setOrigin(-65,-90);

    this->font.loadFromFile("../Font/fonttext.otf");
    this->text.setString("Press Space to start!");
    this->text.setFont(font);
    this->text.setCharacterSize(30);
    this->title.setString("The Hole");
    this->title.setFont(font);
    this->title.setCharacterSize(150);
    this->title.setPosition(Vector2f(60,50));
    title.setFillColor(Color::Magenta);
    text.setFillColor(Color::Black);
    text.setOrigin(-245,-560);
}
Menu::~Menu() = default;
Sprite Menu::getBackGround()
{
    return this->backgroundmenu;
}
Sprite Menu::getStartButton()
{
    return this->startbutton;
}
Sprite Menu::getTheme()
{
    return this->theme;
}
void Menu::update(float time)
{
    this->deltatime+=time;
    int noPic=0;
    if (deltatime>=17) deltatime=0;
    else noPic+=deltatime;
    uvRect3.left=uvRect3.width*int (noPic);
    this->theme.setTextureRect(uvRect3);
    if (int(deltatime)%2) text.setFillColor(Color::Black);
    else text.setFillColor(Color::Yellow);
    if (int(deltatime)%7==1) this->title.setFillColor(Color::Red);
    if (int(deltatime)%7==2) this->title.setFillColor(Color::Yellow);
    if (int(deltatime)%7==3) this->title.setFillColor(Color::Green);
    if (int(deltatime)%7==4) this->title.setFillColor(Color::Blue);
    if (int(deltatime)%7==5) this->title.setFillColor(Color::Magenta);

}
Text Menu::getText()
{
    return this->text;
}
Text Menu::getTitle()
{
    return this->title;
}