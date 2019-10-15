#include "bst_in_bst.h"

/////////////////////////////////////  ** BST **  /////////////////////////////////////

/*
 *	Definition of Public Methods
 */

template<typename T>
BST<T>::BST()
	: root_(nullptr) {}

template<typename T>
BST<T>::BST(const BST& src)
{
	root_ = clone(src.root_);
}

template<typename T>
BST<T>::~BST()
{
	makeEmpty();
}

template<typename T>
const T& BST<T>::findMin() const
{
	return findMin(root_)->element_;
}

template<typename T>
const T& BST<T>::findMax() const
{
	return findMax(root_)->element_;
}

template<typename T>
bool BST<T>::contain(const T& item) const
{
	return contain(item, root_);
}

template<typename T>
bool BST<T>::isEmpty() const
{
	return root_ == nullptr;
}

template<typename T>
void BST<T>::makeEmpty()
{
	makeEmpty(root_);
}

template<typename T>
void BST<T>::insert(const T& item)
{
	insert(item, root_);
}

template<typename T>
void BST<T>::remove(const T& item)
{
	remove(item, root_);
}


/*
 *	Definition of Private Methods
 */

template<typename T>
bool BST<T>::contain(const T& item, BinaryNode* node) const
{
	if (node == nullptr)
		return false;
	if (item < node->element_)
		return contain(item, node->left_);
	else if (item > node->element_)
		return contain(item, node->right_);
	else
		return true;
}

template<typename T>
void BST<T>::insert(const T& item, BinaryNode*& node)
{
	if (node == nullptr)
		node = new BinaryNode(item, nullptr, nullptr);
	else if (item <= node->element_)
		insert(item, node->left_);
	else if (item > node->element_)
		insert(item, node->right_);
	else
		;
}

template<typename T>
void BST<T>::remove(const T& item, BinaryNode* node)
{
	if (node == nullptr)
		return;
	if (item < node->element_)
		remove(item, node->left_);
	else if (item > node->element_)
		remove(item, node->right_);
	else if (node->left_ != nullptr && node->right_ != nullptr) // node has 2 children
	{
		node->element_ = findMin(node->right_)->element_;
		remove(node->element_, node->right_);
	}
	else
	{
		BinaryNode* temp = node;
		node = (node->left_ != nullptr) ? node->left_ : node->right_;
		delete temp;
		temp = nullptr;
	}
}

template<typename T>
void BST<T>::makeEmpty(BinaryNode*& node)
{
	if (node != nullptr)
	{
		makeEmpty(node->left_);
		makeEmpty(node->right_);
		delete node;
	}
	node = nullptr;
}

template<typename T>
typename BST<T>::BinaryNode* BST<T>::findMin(BinaryNode* node) const
{
	//** RECURISVE **//

	if (node == nullptr)
		return nullptr;
	if (node->left_ == nullptr)
		return node;
	return findMin(node->left_);

	//** Iterative **//
	/*
	if (node != nullptr)
		while (node->left_ != nullptr)
			node = node->left_;
	return node;
	*/
}

template<typename T>
typename BST<T>::BinaryNode* BST<T>::findMax(BinaryNode* node) const
{
	//** Recurisve ** //

	if (node == nullptr)
		return nullptr;
	if (node->right_ == nullptr)
		return node;
	return findMax(node->right_);

	//** Iterative **//
	/*
	if (node == nullptr)
		while (node->right_ != nullptr)
			node = node->right_;
	return node;
	*/
}

template<typename T>
typename BST<T>::BinaryNode* BST<T>::clone(BinaryNode* node) const
{
	if (node == nullptr)
		return nullptr;
	else
		return new BinaryNode(node->element, clone(node->left_), clone(node->right_));
}



/////////////////////////////////////  ** BST in BST **  /////////////////////////////////////

template<typename T>
BST_BST<T>::BST_BST(const unsigned short int& elemNumb)
	: BST_root(nullptr), BST_Node::BN_root(nullptr), BST_Node::counter_(elemNumb) {}

template<typename T>
BST_BST<T>::BST_BST(const BST_BST& src)
{
	BST_root = clone(src.BST_root);
}

template<typename T>
BST_BST<T>::~BST_BST()
{
	makeEmpty();
}

template<typename T>
const T& BST_BST<T>::findMin() const
{
	return *(findMin(BST_root)->minNode_);
}

template<typename T>
const T& BST_BST<T>::findMax() const
{
	return *(findMax(BST_root)->maxNode_);
}

template<typename T>
bool BST_BST<T>::isEmpty() const
{
	return BST_root == nullptr;
}

template<typename T>
bool BST_BST<T>::contain(const T& item) const
{
	return contain(item, BST_root);
}

template<typename T>
void BST_BST<T>::makeEmpty()
{
	makeEmpty(BST_root);
}

template<typename T>
void BST_BST<T>::insert(const T& item)
{
	insert(item, BST_root);
}

template<typename T>
void BST_BST<T>::remove(const T& item)
{
	remove(item, BST_root);
}


/*
 *	Definition of Private Methods
 */

template<typename T>
void BST_BST<T>::insert(const T& item, BST_Node*& node)
{
	if (node == nullptr)
	{
		node = new BST_Node(new typename BST_BST::BinaryNode(item, nullptr, nullptr), nullptr, nullptr);
	}
	else if (node->minNode_ == nullptr && node->maxNode_ == nullptr && node->counter_ != 0 && node->depth_ != -1)
	{
		insert(item, node->BN_root);
	}
	else if (node->minNode_ != nullptr && item <= *node->minNode_ && node->counter_ != 0 && node->depth_ != -1)
	{
		insert(item, node->BST_left);
	}
	else if (node->maxNode_ != nullptr && item > * node->maxNode_ && node->counter_ != 0 && node->depth_ != -1)
	{
		insert(item, node->BST_right);
	}
	else if (node->counter_ == 0 && node->depth_ == -1 && item >= node->minNode_ && item <= node->maxNode_)
	{

	}
	else if (node->counter_ == 0 && node->depth_ == -1 && item <= node->minNode_)
	{

	}
	else if (node->counter_ == 0 && node->depth_ == -1 && item >= node->maxNode_)
	{

	}
}

/*
 *  /////////////////////////////////////  ** Nested BST_Node **  /////////////////////////////////////
 */

