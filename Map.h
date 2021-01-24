//
// Created by phuonghoa on 26/10/2020.
//
#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
using namespace std;
using namespace sf;
class Map {
private:
    vector<pair<vector<vector<bool> >,int> > sourceMap;
    vector<vector<bool> > x;
    vector<RectangleShape> hole;
    Sprite backgroundmap;
    Texture texture;
    RectangleShape fin;
public:
    Map();
    ~Map();
public:
    void setBackground(Texture &texture, RenderWindow &window);
    void setMap(int tt);
    void drawMap(RenderWindow &window, Texture &texture,bool fade);
    void createMap();
public:
    RectangleShape getFin();
    Sprite getBackgroundMap();
    vector<RectangleShape> getHole();
public:
    vector<RectangleShape> winscenc;
    vector<RectangleShape> story;
    vector<RectangleShape> tutorial;
    void createWin(Texture &texture1,Texture &texture2, Texture &texture3);
    void createStory(Texture &texture1,Texture &texture2, Texture &texture3,Texture &texture4);
    void createTuto();
};

