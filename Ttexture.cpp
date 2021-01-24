//
// Created by phuonghoa on 26/10/2020.
//

#include "Ttexture.h"
using namespace sf;
Ttexture::Ttexture() = default;
Ttexture::~Ttexture()=default;
Texture *Ttexture::getTexture(int num)
{
    return &this->texture[num];
}
void Ttexture::pushTexture(string s)
{
    Texture texturetmp;
    texturetmp.loadFromFile(s);
    this->texture.push_back(texturetmp);
}
