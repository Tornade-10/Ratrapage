#ifndef API_GAMEPLAY_MINE_H_
#define API_GAMEPLAY_MINE_H_

#include "gameplay/building.h"

class Mine : public Building {

public:
	Mine(float x, float y);

protected:
	void DefineTexture() override;
};

#endif
