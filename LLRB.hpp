#include <cstddef>
#include <cstdio>
#include <sys/types.h>

namespace MyLLRB {
	//Define the class LLRB tree, including the Node class and operates.
	template<class KEYType, class VALUEType> class LLRB {
	private:
		class Node;
		bool rooted;
		Node * Nil = nullptr;
		Node * root = nullptr;

	public:
		long int Element_num;
		LLRB();
		void insert(KEYType key, VALUEType value);
		long int size();
		void Delall(Node * ptr);
		void CleartheTree();
	};
	//Define inner class Node
	template<class KEYType, class VALUEType>
	class LLRB<KEYType,VALUEType>::Node{
		friend class LLRB;
	public:
		KEYType key;
		VALUEType value;
		bool color;
		bool nil;
		Node * left, * right;
	
		Node(const LLRB&);		//Providing outer class premission.
		void InitNil();			//Init the Nil node
		void InitNode(KEYType key, VALUEType value, bool color);
		void leftrotate(Node * last);
		void rightrotate(Node * last);
		void split4nodes();
		void adjust(Node * last);
	};
	template<class KEYType, class VALUEType>		//Init nodes' ptr
	LLRB<KEYType,VALUEType>::Node::Node(const LLRB& llrb) {
		this->right = llrb.Nil;
		this->left = llrb.Nil;
	}
	template<class KEYType, class VALUEType>
	void LLRB<KEYType,VALUEType>::Node::InitNil() {	//Init nil node
		this->color = 0;
		this->key = (KEYType)0;
		this->value = (VALUEType)0;
		this->nil = true;
		this->left = this;
		this->right = this;
	}
	template<class KEYType, class VALUEType>		//Init other nodes
	void LLRB<KEYType,VALUEType>::Node::InitNode(KEYType key, VALUEType value, bool color) {
		this->color = color;
		this->key = key;
		this->value = value;
		this->nil = false;
	}
	template<class KEYType, class VALUEType>		//Left rotate operate & adjust color
	void LLRB<KEYType,VALUEType>::Node::leftrotate(Node * last){
		if(last->left == this){
			last->left = this->right;
			this->right = last->left->left;
			last->left->left = this;
			last->left->color = 0;
			this->color = 1;
		}
		else{
			last->right = this->right;
			this->right = last->right->left;
			last->right->left = this;
			last->right->color = 0;
			this->color = 1;
		}
	}
	template<class KEYType, class VALUEType>		//Right rotate operate & adjust color
	void LLRB<KEYType,VALUEType>::Node::rightrotate(Node * last){
		if(last->left == this){
			last->left = this->left;
			this->left = last->left->right;
			last->left->right = this;
			this->color = 1;
			last->left->color = 0;
		}
		else{
			last->right = this->left;
			this->left = last->right->right;
			last->right->right = this;
			this->color = 1;
			last->right->color = 0;
		}
	}
	template<class KEYType, class VALUEType>		//Split 4-nodes
	void LLRB<KEYType,VALUEType>::Node::split4nodes(){
		this->right->color = 0;
		this->left->color = 0;
		this->color = 1;
	}
	template<class KEYType, class VALUEType>
	void LLRB<KEYType,VALUEType>::Node::adjust(Node * last){
		if(this->left->color && this->right->color){
			this->split4nodes();
		}
		if(this->left->color && this->left->left->color){
			Node * tmp = this->left;
			this->rightrotate(last);
			tmp->split4nodes();
		}
		else if(this->left->color && this->left->right->color){
			this->left->leftrotate(this);
			Node * tmp = this->left;
			this->rightrotate(last);
			tmp->split4nodes();
		}
		if(this->right->color){
			this->leftrotate(last);
		}
	}
	


	template<class KEYType, class VALUEType>		//construct function of LLRB tree
	LLRB<KEYType,VALUEType>::LLRB(){
		rooted = 0;
		Element_num = 0;
		Nil = new Node(*this);
		Nil->InitNil();
		root = new Node(*this);
	}
	template<class KEYType, class VALUEType>		//insert a element to LLRB tree
	void LLRB<KEYType,VALUEType>::insert(KEYType key,VALUEType value) {
			if (!this->rooted) {
				this->root->key = key;
				this->root->value = value;
				this->root->color = 0;
				this->rooted = 1;
				++ Element_num;
				return;
			}
			Node * current = this->root;
			Node * last = nullptr;
			if(current->left->color && current->right->color){
				current->left->color = 0;
				current->right->color = 0;
			}
			else if(current->right->color){
				this->root = current->right;
				current->right = this->root->left;
				this->root->left = current;
				current->color = 1;
				this->root->color = 0;
				current = this->root;
			}
			while(current->nil!=1){
				last = current;
				if(current->value == value){
					current->value = value;
					current->key = key;
					return;
				}
				else if(current->value>value){
					current = current->left;
				}
				else{
					current = current->right;
				}
				current->adjust(last);
				current = last;
				if(current->value>value){
					current = current->left;
				}
				else{
					current = current->right;
				}
			}
			Node * node = new Node(*this);
			node->InitNode(key, value, 1);
			if(value > last->value){
				last->right = node;
			}
			else{
				last->left = node;
			}
			++ Element_num;
			//test
			// std::printf("%d", this->root->right->value);
		}

	template<class KEYType, class VALUEType>		//insert a element to LLRB tree
	long int LLRB<KEYType,VALUEType>::size(){
		return Element_num;
	}

	template<class KEYType, class VALUEType>
	void LLRB<KEYType,VALUEType>::Delall(Node * ptr){
		if(ptr->nil){
			return;
		}
		Delall(ptr->left);
		if(!ptr->left->nil){
			delete ptr->left;
			--Element_num;
		}
		Delall(ptr->right);
		if(!ptr->right->nil){
			delete ptr->right;
			--Element_num;
		}
	}

	template<class KEYType, class VALUEType>		//insert a element to LLRB tree
	void LLRB<KEYType,VALUEType>::CleartheTree(){
		this->Delall(this->root);
        this->rooted = 0;
        this->root->value = (VALUEType)0;
        this->root->key = (KEYType)0;
        this->Element_num = 0;
	}

}
