#ifndef API_GAMEPLAY_SAWMILL_H_
#define API_GAMEPLAY_SAWMILL_H_

#include "gameplay/building.h"

class Sawmill : public Building {

public:
	Sawmill(float x, float y);

protected:
	void DefineTexture() override;

};

#endif
