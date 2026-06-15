#pragma once

#include "GameObject.h"

class Collectible : public GameObject
{
public:

    virtual void collect() = 0;

    bool isCollected() const { return collected; }

protected:

    bool collected = false;
};