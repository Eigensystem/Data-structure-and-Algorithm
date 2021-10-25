#include <cstddef>
#include <sys/types.h>

namespace MyFibheap {
	template<typename KEYType, typename VALUEType> class Fibheap{
	private:
		class Node;
		Node * Nil = nullptr;
		Node * Max = nullptr;
	
	public:
		int node_num;
		Fibheap();
		void insert(KEYType key, VALUEType value);
		VALUEType extract_max();
		VALUEType showmax();
		void heap_consolidate();
	};

	//Define inner class Node
	template<typename KEYType, typename VALUEType>
	class Fibheap<KEYType,VALUEType>::Node{
		friend class Fibheap;
	public:
		KEYType key;
		VALUEType value;
		int degree;
		bool mark;
		bool nil;
		Node * left;
		Node * right;
		Node * parent;
		Node * child;

		Node(const Fibheap&);
		void InitNil();
		void dellink();
		void linktoroot(Fibheap&);
		void InitNode(KEYType key, VALUEType value, Node * left, Node * right, Node * parent, Node * child);
	};

	template<typename KEYType, typename VALUEType>
	Fibheap<KEYType,VALUEType>::Fibheap(){
		this->node_num = 0;
		this->Nil = new Node(*this);
		this->Nil->InitNil();
		this->Max = this->Nil;
	}

	template<typename KEYType, typename VALUEType>
	Fibheap<KEYType,VALUEType>::Node::Node(const Fibheap& fibheap){
		this->nil = 0;
		this->mark = 0;
		this->degree = 0;
		this->left = fibheap.Nil;
		this->right = fibheap.Nil;
		this->parent = fibheap.Nil;
		this->child = fibheap.Nil;
	}
	template<typename KEYType, typename VALUEType>
	void Fibheap<KEYType,VALUEType>::Node::InitNil(){
		this->nil = 1;
		this->left = this;
		this->right = this;
		this->parent = this;
		this->child = this;
	}
	template<typename KEYType, typename VALUEType>
	void Fibheap<KEYType,VALUEType>::Node::InitNode(KEYType key, VALUEType value, Node * left, 
													Node * right, Node * parent, Node * child){
		this->key = key;
		this->value = value;
		this->left = left;
		this->right = right;
		this->parent = parent;
		this->child = child;
	}
	template<typename KEYType, typename VALUEType>
	void Fibheap<KEYType,VALUEType>::Node::dellink(){
		this->left->right = this->right;
		this->right->left = this->left;
	}
	template<typename KEYType, typename VALUEType>
	void Fibheap<KEYType,VALUEType>::Node::linktoroot(Fibheap& fibheap){
		fibheap.Max->right->left  = this;
		this->right = fibheap.Max->right;
		fibheap.Max->right = this;
		this->left = fibheap.Max;
		this->parent = fibheap.Nil;
	}

	template<typename KEYType, typename VALUEType>
	VALUEType Fibheap<KEYType,VALUEType>::showmax(){
		if(this->Max == this->Nil){
			return (VALUEType)NULL;
		}
		else{
			return this->Max->value;
		}
	}

	template<typename KEYType, typename VALUEType>
	void Fibheap<KEYType,VALUEType>::insert(KEYType key, VALUEType value){
		Node * node = new Node(*this);
		if(this->Max == this->Nil){
			node->InitNode(key, value, node, node, this->Nil, this->Nil);
			this->Max = node;
		}
		else{
			node->InitNode(key, value, this->Max, this->Max->right, this->Nil, this->Nil);
			this->Max->right->left = node;			//Add new node to the right hand of the Max node
			this->Max->right = node;
			if(this->Max->key < key){
				this->Max = node;
			}
		}
		++this->node_num;
	}

	template<typename KEYType, typename VALUEType>
	void Fibheap<KEYType,VALUEType>::heap_consolidate(){
		
	}

	template<typename KEYType, typename VALUEType>
	VALUEType Fibheap<KEYType,VALUEType>::extract_max(){
		VALUEType value;
		if(this->Max == this->Nil){
			return (VALUEType)NULL;
		}
		else if(node_num == 1){
			value = this->Max->value;
			delete this->Max;
			--node_num;
			this->Max = this->Nil;
		}
		else{
			Node ptr = this->Max->child;
			do{
				ptr.linktoroot(*this);
				ptr = ptr.right;
			}while (ptr!=this->Max->child);
			value = this->Max->value;
			Node * tmp = this->Max;
			this->Max = this->Max->right;
			tmp->dellink();
			delete tmp;
			this->heap_consolidate();
		}
		--this->node_num;
		return value;
	}
}