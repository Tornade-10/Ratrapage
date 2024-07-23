#ifndef API_GAMEPLAY_WOODS_MAN_H
#define API_GAMEPLAY_WOODS_MAN_H

#include "Walker.h"
#include "tree/tree.h"
#include "tilemap//Tilemap.h"

class Woodsman : public Walker
{
private:
	TileMap& tilemap_;

	behaviour_tree::Tree tree_;

	int stamina_ = 0;

public:
	Woodsman(float x, float y, float linear_speed, TileMap& tilemap);
	~Woodsman() override;
	Woodsman(const Woodsman& w);

	void DefineTexture() override;

	void InitiateBehaviours();
	void Tick();

	behaviour_tree::Status SeekWood();
	behaviour_tree::Status GatherWood();
	behaviour_tree::Status BackHome();

	int PickNewStamina();
};

#endif // WOODS_MAN_H