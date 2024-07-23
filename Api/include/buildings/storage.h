#ifndef API_GAMEPLAY_STORAGE_H_
#define API_GAMEPLAY_STORAGE_H_

#include "gameplay/building.h"

class Storage : public Building {

public:
	Storage(float x, float y);

protected:
	void DefineTexture() override;

};

#endif
