
#include "gameplay/npc.h"

#include <iostream>
#include <random>

#include "sfml_vec2f.h"
#include "tree/leaf.h"
#include "AI/path_finder.h"

using namespace behaviour_tree;

Woodsman::Woodsman(float x, float y, float linear_speed, TileMap& tilemap) : Walker(x, y, linear_speed), tilemap_(tilemap)
{
	DefineTexture();

	rect_.setPosition(shape_.getGlobalBounds().getPosition());
	rect_.setSize(shape_.getGlobalBounds().getSize());

	InitiateBehaviours();

}

Woodsman::~Woodsman()
{
	std::cout << "What happens Woodsman ?" << std::endl;
}

Woodsman::Woodsman(const Woodsman& w) : Walker(w), tilemap_(w.tilemap_)
{
	stamina_ = w.stamina_;
	InitiateBehaviours();
}

void Woodsman::DefineTexture()
{
	shape_.setTexture(ResourceManager::Get().GetNpcTexture(ResourceManager::ResourceNPC::kWoodsMan));
}

void Woodsman::InitiateBehaviours()
{
	stamina_ = 30;

	Path p = Pathfinder::CalculatePath(tilemap_.GetWalkables(), LastDestination(), getPosition(), 64);
	set_path(p);

	Leaf* check_stamina = new Leaf("check stamina", [this]()
		{

			std::cout << "Check Stamina : " << stamina_ << std::endl;

			if (stamina_ >= 0)
				return Status::kSuccess;
			else
				return Status::kFailure;

		}
	);

	Leaf* seek_wood = new Leaf("seek", [this]()
		{
			return SeekWood();
		}
	);

	Leaf* gather_wood = new Leaf("gather", [this]()
		{
			return GatherWood();
		}
	);

	Leaf* back_home = new Leaf("back", [this]()
		{
			return BackHome();
		}
	);

	Leaf* refill_stamina = new Leaf("check stamina", [this]()
		{
			stamina_ = PickNewStamina();
			std::cout << "Refill Stamina : " << stamina_ << std::endl;
			return Status::kFailure;
		}
	);

	std::unique_ptr<Selector> main_select = std::make_unique<Selector>();

	Sequence* gather_sequence = new Sequence();
	Sequence* home_sequence = new Sequence();

	main_select->Add(gather_sequence);
	main_select->Add(home_sequence);

	gather_sequence->Add(check_stamina);
	gather_sequence->Add(seek_wood);
	gather_sequence->Add(gather_wood);

	home_sequence->Add(back_home);
	home_sequence->Add(refill_stamina);

	tree_.Attach(main_select);

}

void Woodsman::Tick()
{
	// -------------------------------------
	Walker::Tick();
	// -------------------------------------
	tree_.Tick();
}

Status Woodsman::SeekWood()
{
	sf::Vector2f closestTree = tilemap_.GetClosestTree(getPosition());

	if (squaredMagnitude(closestTree - path_.FinalDestination()) > std::numeric_limits<float>::epsilon())
	{
		std::cout << "Recalculate path" << std::endl;
		Path p = Pathfinder::CalculatePath(tilemap_.GetWalkables(), LastDestination(), closestTree, 64);
		set_path(p);

		// - - - - - - - - - - - - - - -
		stamina_ -= p.GetSteps().size();

	}

	if (!path_.IsAvailable())
	{
		std::cout << "Path not available" << std::endl;
		return Status::kFailure;
	}

	float sq_mag = squaredMagnitude(getPosition() - path_.FinalDestination());
	if (sq_mag < std::numeric_limits<float>::epsilon())
	{
		std::cout << "Arrived !!!!!!" << std::endl;
		return Status::kSuccess;
	}
	else
	{
		//std::cout << "Not arrived yet" << std::endl;
		return Status::kRunning;
	}

}


Status Woodsman::GatherWood()
{

	if (tilemap_.GatherTree(getPosition()))
	{
		std::cout << "Cutting trees" << std::endl;
		return Status::kSuccess;
	}

	//std::cout << "not Cutting trees" << std::endl;
	return Status::kFailure;

}

Status Woodsman::BackHome()
{

	sf::Vector2f homePosition = sf::Vector2f(0, 0);

	if (squaredMagnitude(homePosition - path_.FinalDestination()) > std::numeric_limits<float>::epsilon())
	{
		Path p = Pathfinder::CalculatePath(tilemap_.GetWalkables(), LastDestination(), homePosition, 64);
		set_path(p);
	}

	if (!path_.IsAvailable())
	{
		std::cout << "Path not available" << std::endl;
		return Status::kFailure;
	}

	if (squaredMagnitude(getPosition() - path_.FinalDestination()) < std::numeric_limits<float>::epsilon())
	{
		std::cout << "Arrived at home !!!!!!" << std::endl;
		return Status::kSuccess;
	}
	else
	{
		std::cout << "Not arrived yet at home" << std::endl;
		return Status::kRunning;
	}

}

int Woodsman::PickNewStamina()
{

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> int_distribution(20, 30); // distribution in range [1, 6]

	return int_distribution(rng);

}