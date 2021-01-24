//
// Created by phuonghoa on 26/10/2020.
//

#include "Player.h"
#include<iostream>
using namespace std;
void Player::setPlayerTexture(Texture &texture)
{
    this->player.setTexture(texture);
    this->deltatime=0;
    this->uvRect.left=0;
    this->uvRect.top=0;
    this->uvRect.width=texture.getSize().x/24;
    this->uvRect.height=texture.getSize().y;
    this->player.setTextureRect(this->uvRect);
}
Sprite Player::getPlayer()
{
    return this->player;
}
void Player::Update(int col, int num, float time, bool faceright,int level)
{
    this->deltatime+=time;
    int noPic=col+deltatime;
    if (noPic>num)
    {
        deltatime=0;
        noPic=col;
    }
    int hs;
    if (level>=1 && level<=20) hs=3;
    if (level>=21 && level<=40) hs=2.8;
    if (level>=41 && level<=60) hs=2.5;
    if (level>=61 && level<=80) hs=2.3;
    if (level>=81 && level<=100) hs=1.8;
    this->uvRect.left=this->uvRect.width * int(noPic);
    Vector2f tmp=Vector2f (this->player.getTextureRect().width/2,this->player.getTextureRect().height/2) ;
    this->player.setOrigin(tmp.x,tmp.y);
    if (!faceright)
    {
        this->player.setScale(Vector2f(-hs*1.0,hs*1.0));
    }
    else
    {
        this->player.setScale(Vector2f(hs*1.0,hs*1.0));
    }
    this->player.setTextureRect(this->uvRect);
}
void Player::updateHeart(int tt, Texture &texture)
{
    this->heart[tt].setTexture(texture);
    this->heart[tt].setTextureRect(IntRect(0,0,texture.getSize().x,texture.getSize().y));
    this->heart[tt].setScale(2,2);
    if (tt==1) this->heart[tt].setPosition(10,20);
    if (tt==2) this->heart[tt].setPosition(50,20);
    if (tt==3) this->heart[tt].setPosition(90,20);
}
Sprite Player::getHeart(int tt)
{
    return this->heart[tt];
}
Player::Player(){}
Player::~Player() {}
void Player::setPosition(int level)
{
    int kt;
    if (level>=1 && level<=20) kt=5;
    if (level>=21 && level<=40) kt=6;
    if (level>=41 && level<=60) kt=7;
    if (level>=61 && level<=80) kt=8;
    if (level>=81 && level<=100) kt=9;
//    this->player.setPosition(Vector2f(200/level,200/level));//?
//    this->player.setOrigin(sq.getOrigin());
//    cout<<sq.getOrigin().x<<' '<<sq.getOrigin().y<<endl;
    this->player.setPosition(200.0 + 400.0/kt/2,200.0+ 400.0/kt/2);
}
void Player::move(float i, float j)
{
    this->player.move(i,j);
}
bool Player::colliderect(vector<RectangleShape> rect)
{
    RectangleShape rect1;
    rect1.setSize(Vector2f(this->player.getTextureRect().width/2,this->player.getTextureRect().height/2));
    rect1.setPosition(this->player.getPosition());
    for(int i=0;i<rect.size();i++)
    {
        RectangleShape rect2=rect[i];

        double distX = (rect1.getPosition().x + (rect1.getSize().x/2)) - (rect2.getPosition().x + (rect2.getSize().x)/2);
        if (distX < 0)
            distX = -distX;

        double distW = (rect1.getSize().x + rect2.getSize().x)/2;

        int distY =(rect1.getPosition().y + (rect1.getSize().y/2)) - (rect2.getPosition().y + (rect2.getSize().y)/2);
        if(distY < 0)
            distY = -distY;

        int distH = (rect1.getSize().y + rect2.getSize().y)/2;

        if (distX <= distW && distY <= distH) return 1;
    }
    return 0;
}
bool Player::colliderect(RectangleShape rect2)
{
    RectangleShape rect1;
    rect1.setSize(Vector2f(this->player.getTextureRect().height/2,this->player.getTextureRect().width/2));
    rect1.setPosition(this->player.getPosition());
    double distX = (rect1.getPosition().x + (rect1.getSize().x/2)) - (rect2.getPosition().x + (rect2.getSize().x)/2);
    if (distX < 0)
        distX = -distX;

    double distW = (rect1.getSize().x + rect2.getSize().x)/2;

    int distY =(rect1.getPosition().y + (rect1.getSize().y/2)) - (rect2.getPosition().y + (rect2.getSize().y)/2);
    if(distY < 0)
        distY = -distY;

    int distH = (rect1.getSize().y + rect2.getSize().y)/2;

    if (distX <= distW && distY <= distH) return 1;
    return 0;
}
void Player::setPosition(Vector2f tmp)
{
    this->player.setScale(5,5);
    this->player.setPosition(tmp);
}
RectangleShape Player::setBoder()
{
    boder.setSize(Vector2f(100,100));
    boder.setPosition(this->player.getPosition());
    boder.setFillColor(Color::Black);
    boder.setOutlineThickness(3);
    boder.setOutlineColor(Color::Yellow);
    return boder;
}