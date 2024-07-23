#ifndef API_LEAF_H
#define API_LEAF_H

#include <functional>
#include <iostream>
#include <string>

#include "node.h"

namespace behaviour_tree
{
	class Leaf final : public Node
	{

	private:
		//std::function<Status()> leaf_action_;
		std::string name_;

	public:
		~Leaf() override = default;
		Leaf(std::string name, const std::function<Status()>& leaf_action) : leaf_action_(leaf_action), name_(name) {};


		Status Process() override;
		void Reset() override {};

		void SetAction(const std::function<Status()>& leaf_action)
		{
			leaf_action_ = leaf_action;
		}

		std::function<Status()> leaf_action_;

	};

	inline Status Leaf::Process()
	{

		std::cout << "Leaf Process : " << name_ << std::endl;

		if (leaf_action_ != nullptr)
			return leaf_action_();
		else
			return Status::kFailure;

	}
}

#endif