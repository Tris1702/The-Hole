//
// Created by phuonghoa on 26/10/2020.
//

#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class Player
{
private:
    Sprite player;
    Sprite heart[4];
    float deltatime;
    IntRect uvRect;

public:
    RectangleShape boder;
    void setPlayerTexture(Texture &texture);
    void Update(int col,int num, float time,bool faceright,int level);
    void setPosition(int level);
    void updateHeart(int tt, Texture &texture);
    void move(float i, float j);
    void die();
    void setPosition(Vector2f tmp);
    RectangleShape setBoder();
public:
    Sprite getPlayer();
    Sprite getHeart(int tt);
    bool colliderect(vector<RectangleShape> rect);
    bool colliderect(RectangleShape rect2);

public:
    Player();
    ~Player();
};
