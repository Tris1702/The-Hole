//
// Created by phuonghoa on 26/10/2020.
//
#pragma once
#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
using namespace sf;
using namespace std;
class Ttexture {
private:
    vector < Texture> texture;
public:
    Ttexture();
    ~Ttexture();

public:
    void pushTexture(string s);
    Texture *getTexture(int num);
};