#pragma once
#include<cmath>

/////////////////////////////////////  ** BST **  /////////////////////////////////////
template<typename T>
class BST
{
public:

	BST();
	BST(const BST& src);
	~BST();

	const T& findMin() const;
	const T& findMax() const;
	bool contain(const T& item) const;
	bool isEmpty() const;

	void makeEmpty();
	void insert(const T& item);
	void remove(const T& item);


private:

	struct BinaryNode
	{
		T element_;
		BinaryNode* left_;
		BinaryNode* right_;

		BinaryNode(const T& element, BinaryNode* left, BinaryNode* right)
			: element_(element), left_(left), right_(right) {};
	};

	BinaryNode* root_;

	void insert(const T& item, BinaryNode*& node);
	void remove(const T& item, BinaryNode* node);
	BinaryNode* findMin(BinaryNode* node) const;
	BinaryNode* findMax(BinaryNode* node) const;
	bool contain(const T& item, BinaryNode* node) const;
	void makeEmpty(BinaryNode*& node);
	BinaryNode* clone(BinaryNode* node) const;
};



/////////////////////////////////////  ** BST in BST **  /////////////////////////////////////
template<typename T>
class BST_BST
{
public:
	BST_BST(const unsigned short int& elemNumb = 7); // Maximum Depth of Nested Binary Search Tree
	BST_BST(const BST_BST& src);
	~BST_BST();

	const T& findMin() const;
	const T& findMax() const;
	bool isEmpty() const;
	bool contain(const T& item) const;

	void makeEmpty();
	void insert(const T& item);
	void remove(const T& item);

private:
	struct BST_Node
	{
		struct BinaryNode
		{
			T element_;
			BinaryNode* BN_left;
			BinaryNode* BN_right;

			BinaryNode(const T& element, BinaryNode* lt, BinaryNode* rt)
				: element_(element), BN_left(lt), BN_right(rt), counter_(counter_ - 1), depth_(depth_ - 1) {}

		};
		BinaryNode* BN_root;

		T* minNode_;
		T* maxNode_;
		BST_Node* BST_left;;
		BST_Node* BST_right;

		unsigned short int counter_ = 7;			// Maximum Number of Nodes (Binary Nodes)
		short int depth_ = log2(counter_ + 1) - 1;	// Maximum Depth of Nested Binary Search Tree


		BST_Node(BinaryNode* BNroot, BST_Node* BSTleft, BST_Node* BSTright)
			: BN_root(BNroot), BST_left(BSTleft), BST_right(BSTright), minNode_(nullptr), maxNode_(nullptr) {}

		bool isFull() const;
		void insert(const T& item, BinaryNode* node);
		void remove(const T& item, BinaryNode* node);
		//BinaryNode* findMin(BinaryNode* node) const;			//**	I think it won't be necessary
		//BinaryNode* findMax(BinaryNode* node) const;			//**	I think it won't be necessary
		bool contain(const T& item, BinaryNode* node) const;
		void makeEmpty(BinaryNode*& node);
		void clone(BinaryNode* node) const;

	};
	BST_Node* BST_root;

	void insert(const T& item, BST_Node*& node);
	void remove(const T& item, BST_Node*& node);
	BST_Node* findMin(BST_Node* node) const;			//**	I think it won't be necessary
	BST_Node* findMax(BST_Node* node) const;			//**	I think it won't be necessary
	bool contain(const T& item, BST_Node* node) const;
	void makeEmpty(BST_Node*& node);
	void clone(BST_Node* node) const;
};