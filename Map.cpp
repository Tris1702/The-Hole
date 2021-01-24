//
// Created by phuonghoa on 26/10/2020.
//

#include "Map.h"
Map::Map() = default;
Map::~Map() = default;
void Map::setMap(int tt)
{
    this->x.clear();
    this->x=this->sourceMap[tt].first;
}
void Map::drawMap(RenderWindow &window,Texture &texture,bool fade)
{
    this->texture=texture;
    this->texture.setSmooth(1);
    int kt=x.size();

    this->hole.clear();
    this->hole.resize(0);

    for(int i=0;i<this->x.size();i++)
        for(int j=0;j<this->x[i].size();j++)
        {
            RectangleShape sq;
            sq.setTexture(&this->texture);
            sq.setOutlineColor(Color(128,128,128));
            sq.setOutlineThickness(2);
            sq.setSize(Vector2f(400.0/kt,400.0/kt));
            sq.setPosition(Vector2f(200+i*sq.getSize().x,200+j*sq.getSize().y));
            if ((i==0&&j==0)||x[i][j]==0)
            {
                sq.setTextureRect(IntRect(15,15,this->texture.getSize().x,this->texture.getSize().y));
                if (fade) sq.setFillColor(Color::Black);
            }
            else
            {
                sq.setTextureRect(IntRect(15,15,this->texture.getSize().x,this->texture.getSize().y));
                sq.setFillColor(Color::Black);
                this->hole.push_back(sq);
            }
            if (i+1==x.size()&& j+1==x[0].size())
            {
                this->fin=sq;
                sq.setFillColor(Color::Red);
            }
            window.draw(sq);
        }
}
const pair<int,int> b[4]={make_pair(0,-1),make_pair(0,1),make_pair(-1,0),make_pair(1,0)};
pair<int,int> bfs(vector<vector<bool> > &xt,int kt)
{
    int ways=0,minway=1e9;
    map<pair<int,int>,bool>  dd;
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(0,0),0));
    dd[q.front().first]=1;
    pair<int,int> fin=make_pair(kt-1,kt-1);
    while (!q.empty())
    {
        pair<int,int> u=q.front().first;
        int w=q.front().second;
        q.pop();
        if (u==fin)
        {
            ways++;
            minway=min(minway,w);
            continue;
        }
        for(int i=0;i<4;i++)
        {
            pair<int,int> v=make_pair(u.first+b[i].first,u.second+b[i].second);
            if (v.first>=0&&v.first<kt && v.second>=0&&v.second<kt && xt[v.first][v.second]==0 && dd[v]==0)
            {
                dd[v] = 1;
                q.push(make_pair(v,w+1));
            }
        }
    }
    return make_pair(ways,minway);
}
void Map::createMap()
{
    for(int i=1;i<=100;i++)
    {
        int kt=0;
        if (i>=1&&i<=20) kt=5;
        if (i>=21&&i<=40) kt=6;
        if (i>=41&&i<=60) kt=7;
        if (i>=61&&i<=80) kt=8;
        if (i>=81&&i<=100) kt=9;
        vector<vector<bool> > tmpMap(kt,vector<bool> (kt));
        while (1)
        {
            for (int i = 0; i < kt; i++)
                for (int j = 0; j < kt; j++) tmpMap[i][j] = rand() % (1 - 0 + 1) + 0;
            pair<int,int> tmp = bfs(tmpMap,kt);
            int ways=tmp.first;
            int minway=tmp.second;
            if (ways > 0)
            {
                this->sourceMap.push_back(make_pair(tmpMap,minway));
                break;
            }
        }
    }
}
void Map::setBackground(Texture &texture, RenderWindow &window)
{
    this->backgroundmap.setTexture(texture);
    this->backgroundmap.setTextureRect(IntRect(50,0,texture.getSize().x, texture.getSize().y));
    this->backgroundmap.setScale(4,4);
}
Sprite Map::getBackgroundMap()
{
    return this->backgroundmap;
}

vector<RectangleShape> Map::getHole()
{
    return this->hole;
}
RectangleShape Map::getFin()
{
    return this->fin;
}
void Map::createWin(Texture &texture1, Texture &texture2, Texture &texture3)
{
    winscenc.resize(3);
    RectangleShape sq;
    //0
//    sq.setSize(Vector2f(200,300));
    sq.setTexture(&texture1);
//    sq.setTextureRect(IntRect(0,0,texture1.getSize().x,texture1.getSize().y));
    //1
    sq.setTexture(&texture2);
    //2
    sq.setTexture(&texture3);
}
void Map::createStory(Texture &texture1,Texture &texture2, Texture &texture3,Texture &texture4)
{
    story.resize(4);
    RectangleShape sq;
    //0
    sq.setTexture(&texture1);
    sq.setTextureRect(IntRect(0,0,texture1.getSize().x,texture1.getSize().y));
    sq.setPosition(10,10);
    story.push_back(sq);
    //1
    sq.setTexture(&texture2);
    sq.setTextureRect(IntRect(0,0,texture2.getSize().x,texture1.getSize().y));
    sq.setPosition(10,10);

    story.push_back(sq);

    //2
    sq.setTexture(&texture3);
    sq.setTextureRect(IntRect(0,0,texture3.getSize().x,texture1.getSize().y));
    sq.setPosition(10,10);

    story.push_back(sq);

    //3
    sq.setTexture(&texture4);
    sq.setTextureRect(IntRect(0,0,texture4.getSize().x,texture1.getSize().y));
    sq.setPosition(10,10);
    story.push_back(sq);

}
void Map::createTuto()
{
    tutorial.resize(3);
}