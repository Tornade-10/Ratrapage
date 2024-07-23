#ifndef API_TREE_H
#define API_TREE_H

#include <memory>

#include "node.h"

#include "tree/leaf.h"
#include "tree/selector.h"
#include "tree/sequence.h"

namespace behaviour_tree
{
	class Tree
	{
		std::unique_ptr<Node> root_;

	public:

		void Tick();

		void Attach(std::unique_ptr<Leaf>& node);
		void Attach(std::unique_ptr<Sequence>& node);
		void Attach(std::unique_ptr<Selector>& node);

	};

}

#endif