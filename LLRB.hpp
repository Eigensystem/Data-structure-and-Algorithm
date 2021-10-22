#include <cstddef>
#include <cstdio>
#include <sys/types.h>
#include <iostream>

namespace MyLLRB {
	//Define the class LLRB tree, including the Node class and operates.
	template<class KEYType, class VALUEType> class LLRB {
	private:
		class Node;
		bool rooted;
		Node * Nil = nullptr;

	public:
		Node * root = nullptr;
		long int Element_num;
		LLRB();
		void insert(KEYType key, VALUEType value, Node * current, Node * last);
		long int size();
		void Delall(Node * ptr);
		void CleartheTree();
		int Delstart(KEYType key);
		int Delmin(Node * current, Node * last, Node * delnode);
		int Del(KEYType key, Node * current, Node * last);
		void Showall(Node * current, int start);
		void fixroot();
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
		bool adjust(Node * last);
		void colordown();
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
		bool tmp;
		if(last->left == this){
			last->left = this->right;
			this->right = last->left->left;
			last->left->left = this;
			tmp = last->left->color;
			last->left->color = this->color;
			this->color = tmp;
		}
		else{
			last->right = this->right;
			this->right = last->right->left;
			last->right->left = this;
			tmp = last->right->color;
			last->right->color = this->color;
			this->color = tmp;
		}
	}
	template<class KEYType, class VALUEType>		//Right rotate operate & adjust color
	void LLRB<KEYType,VALUEType>::Node::rightrotate(Node * last){
		bool tmp;
		if(last->left == this){
			last->left = this->left;
			this->left = last->left->right;
			last->left->right = this;
			tmp = this->color;
			this->color = last->left->color;
			last->left->color = tmp;
		}
		else{
			last->right = this->left;
			this->left = last->right->right;
			last->right->right = this;
			tmp = this->color;
			this->color = last->right->color;
			last->right->color = tmp;
		}
	}
	template<class KEYType, class VALUEType>		//Split 4-nodes
	void LLRB<KEYType,VALUEType>::Node::split4nodes(){
		this->right->color = 0;
		this->left->color = 0;
		this->color = 1;
	}
	template<class KEYType, class VALUEType>
	bool LLRB<KEYType,VALUEType>::Node::adjust(Node * last){
		int flag = 0;
		if(this->left->color && this->right->color){
			this->split4nodes();
		}
		if(this->left->color && this->left->left->color){
			Node * tmp = this->left;
			this->rightrotate(last);
			tmp->split4nodes();
			flag = 1;
		}
		if(this->right->color){
			this->leftrotate(last);
			flag = 1;
		}
		return flag;
	}

	template<class KEYType, class VALUEType>
	void LLRB<KEYType,VALUEType>::Node::colordown(){
		this->color = 0;
		this->left->color = 1;
		this->right->color = 1;
	}
	


	template<class KEYType, class VALUEType>		//construct function of LLRB tree
	LLRB<KEYType,VALUEType>::LLRB(){
		rooted = 0;
		Element_num = 0;
		Nil = new Node(*this);
		Nil->InitNil();
		root = new Node(*this);
	}

	template<class KEYType, class VALUEType>
	void LLRB<KEYType,VALUEType>::fixroot(){
		Node * current;
		current = this->root;
		if(this->root->left->color && this->root->left->left->color){
			this->root = current->left;
			current->left = this->root->right;
			this->root->right = current;
			this->root->color = 0;
			this->root->left->color = 0;
		}
		else if(current->left->color && current->right->color){
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
	}

	template<class KEYType, class VALUEType>		//insert a element to LLRB tree
	void LLRB<KEYType,VALUEType>::insert(KEYType key, VALUEType value, Node * current, Node * last) {
		if (!this->rooted) {
			this->root->InitNode(key, value, 0);
			this->rooted = 1;
			++ Element_num;
			return;
		}
		if(current->nil){
			current = new Node(*this);
			current->InitNode(key, value, 1);
			if(key > last->key){
				last->right = current;
			}
			else{
				last->left = current;
			}
			++ Element_num;
			return;
		}
		else if(current->key > key){
			insert(key, value, current->left, current);
		}
		else if(current->key < key){
			insert(key, value, current->right, current);
		}
		else{
			current->value = value;
		}
		if(current == this->root){
			fixroot();
		}
		else{
			current->adjust(last);
		}
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

	template<class KEYType, class VALUEType>
	void LLRB<KEYType,VALUEType>::Showall(Node * current, int start){
		if(current->nil){
			return;
		}
		std::cout<< start << " Key: "<< current->key << "   " << "Value: " << current->value << "   Color :" << current->color << std::endl;
		++start;
		Showall(current->left, start);
		Showall(current->right, start);
	}

	template<class KEYType, class VALUEType>		//insert a element to LLRB tree
	void LLRB<KEYType,VALUEType>::CleartheTree(){
		this->Delall(this->root);
        this->rooted = 0;
        this->root->value = (VALUEType)0;
        this->root->key = (KEYType)0;
        this->Element_num = 0;
	}

	template<class KEYType, class VALUEType>
	int LLRB<KEYType,VALUEType>::Delstart(KEYType key){
		int r;
		if(!rooted){
			return 0;
		}
		Node * current = this->root;
		if(key > current->key){
			if(current->left->color){
				this->root = current->left;
				current->left = this->root->right;
				this->root->right = current;
				current->color = 1;
				this->root->color = 0;
				r = Del(key, current, this->root);
			}
			else if(!current->right->color && !current->right->left->color){
				current->colordown();
				this->Nil->color = 0;
				r = Del(key, current->right, this->root);
			}
			else{
				r = Del(key, current->right, this->root);
			}
		}
		else if(key < current->key){
			if(current->right->color){
				this->root = current->right;
				current->right = this->root->left;
				this->root->left = current;
				this->root->color = 0;
				current->color = 1;
				r = Del(key, current, this->root);
			}
			else if(!current->left->color && !current->left->left->color){
				current->colordown();
				this->Nil->color = 0;
				r = Del(key, current->left, this->root);
			}
			else{
				r = Del(key, current->left, this->root);
			}
		}
		else{											//key == root.key
			Node * delnode;
			if(current->right->nil && !current->left->nil){
				this->root = current->right;
				this->root->color = 0;
				delete current;
				--this->Element_num;
				return 1;
			}
			else if(current->right->nil && current->left->nil){
				delete current;
				this->root = Nil;
				this->rooted = 0;
				return 1;
			}
			else{
				delnode = current;
				if(!current->right->left->color){
					current->colordown();
					this->Nil->color = 0;
				}
				r = Delmin(current->right, current, delnode);
			}
		}
		this->fixroot();
		--this->Element_num;
		return r;
	}

	template<class KEYType, class VALUEType>
	int LLRB<KEYType,VALUEType>::Delmin(Node * current, Node * last, Node * delnode){
		if(current->left->nil){
			delnode->key = current->key;
			delnode->value = current->value;
			delete current;
			return 1;
			//fixup here
		}
		else{
			current->adjust(last);
			if(!current->left->color && !current->left->left->color){
				current->colordown();
				this->Nil->color = 0;
			}
			int r = Delmin(current->left, current, delnode);
			current->adjust(last);
			return r;
		}
	}

	template<class KEYType, class VALUEType>
	int LLRB<KEYType,VALUEType>::Del(KEYType key, Node * current, Node * last){
		int r;
		Node * delnode, * tmp;
		if(current->nil){
			return 0;
		}
		if(current->key == key && current->right->nil && !current->left->nil){	//current is going to be deleted & right child is nil
			current->rightrotate(last);
			delete current;
			return 1;
		}
		else if(current->key == key && current->right->nil && current->left->nil){
			delete current;
			return 1;
		}
		else{
			current->adjust(last);
			if(current->key == key){											//current is going to be deleted & right child is not nil
				delnode = current;												//to find the min node in the right child tree
				if(!current->right->left->color){
					current->colordown();
					this->Nil->color = 0;
				}
				r = Delmin(current->right, current, delnode);
			}
			else{																//current is not to going be deleted
				if(current->key < key){											//search for the element to be deleted
					if(current->left->color){
						tmp = current->left;
						current->rightrotate(last);
						r = Del(key, current, tmp);
					}
					else if(!current->right->color && !current->right->left->color){
						current->colordown();
						this->Nil->color = 0;
						r = Del(key, current->right, current);
					}
					else{
						r = Del(key, current->right, current);
					}
				}
				else{
					if(!current->left->color && !current->left->left->color){
						current->colordown();
						this->Nil->color = 0;
						r = Del(key, current->left, current);
					}
					else{
						r = Del(key, current->left, current);
					}
				}
			}			
		}
		current->adjust(last);
		return r;		
	}
}
