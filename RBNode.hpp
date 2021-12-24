
#ifndef RBNODE_HPP
#define RBNODE_HPP

namespace ft
{


	enum _Rb_tree_color 
	{
		red = false, black = true 
	};

	template <class T>
	struct RBNode
	{
		public:
			typedef T		value_type;
			value_type		value;
			RBNode 			*left;
			RBNode			*parent;
			RBNode 			*right;
			bool			color;

			RBNode()
			{
				left = 0;
				right = 0;
			}
	};
}

#endif