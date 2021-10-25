#include <cstddef>
#include <math.h>
#include <sys/types.h>
#include <cmath>

namespace MyFibheap {
	template<typename KEYType, typename VALUEType> class Fibheap{
	private:
		class Node;
		Node * Nil = nullptr;
		Node * Max = nullptr;
	
	public:
		int node_num;
		Fibheap();
		~Fibheap();
		void insert(KEYType key, VALUEType value);
		VALUEType extract_max();
		VALUEType showmax();
		int calcu_size();
		void heap_consolidate();
		void heap_insert(Node * insertee, Node * inserter);
	};

	//Define inner class Node
	template<typename KEYType, typename VALUEType>
	class Fibheap<KEYType,VALUEType>::Node{
		friend class Fibheap;
	public:
		KEYType key;
		VALUEType value;
		int degree;
		bool nil;
		bool mark;
		Node * left;
		Node * right;
		Node * parent;
		Node * child;

		Node(const Fibheap&);
		void InitNil();
		void delall(Fibheap&);
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
	Fibheap<KEYType,VALUEType>::~Fibheap(){
		if(this->Max != this->Nil){
			Node * current = this->Max;
			do{
				current->delall(*this);
				Node * tmp = current->right;
				delete current;
				current = tmp;
			}while(current == this->Max);
		}
		delete this->Nil;
		this->Max = nullptr;
		this->node_num = 0;
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
	void Fibheap<KEYType,VALUEType>::Node::delall(Fibheap& fibheap){
		if(this->child == fibheap.Nil){
			return;
		}
		else{
			Node * current = this->child;
			do{
				current->delall(fibheap);
				Node * tmp = current->right;
				delete current;
				current = tmp;
			}while(current != this->child);
		}
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
	int Fibheap<KEYType,VALUEType>::calcu_size(){
		int num = this->node_num;
		double size = (sqrt(5) + 1)/2;
		return log(num)/log(size);
	}
	template<typename KEYType, typename VALUEType>
	void Fibheap<KEYType,VALUEType>::heap_insert(Node * insertee, Node * inserter){
		inserter->dellink();
		++insertee->degree;
		if(insertee->child == this->Nil){
			insertee->child = inserter;
			inserter->parent = insertee;
			inserter->left = inserter;
			inserter->right = inserter;
		}
		else{
			Node * linknode = insertee->child;
			inserter->left = linknode;
			inserter->right = linknode->right;
			linknode->right->left = inserter;
			linknode->right = inserter;
			inserter->parent = insertee;
		}
	}
	template<typename KEYType, typename VALUEType>
	void Fibheap<KEYType,VALUEType>::heap_consolidate(){
		int size = calcu_size()+1;
		Node * consolidate_arr[size];
		for(int i=0; i<size; i++){
			consolidate_arr[i] = this->Nil;
		}
		Node * current = this->Max;
		do{
			int index = current->degree;
			while(consolidate_arr[index]!=this->Nil){
				if(consolidate_arr[index]->key > current->key){
					this->heap_insert(consolidate_arr[index], current);
					current = consolidate_arr[index];
				}
				else{
					this->heap_insert(current, consolidate_arr[index]);
				}
				consolidate_arr[index] = this->Nil;
				index = current->degree;
			}
			consolidate_arr[index] = current;
			current = current->right;
		}while(current!=this->Max);
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
			if(this->Max->degree){
				Node * ptr = this->Max->child;
				do{
					Node * tmp = ptr->right;
					ptr->linktoroot(*this);
					ptr = tmp;
				}while (ptr!=this->Max->child);
			}
			value = this->Max->value;
			Node * tmp = this->Max;
			this->Max = this->Max->right;
			tmp->dellink();
			delete tmp;
			Node * current = this->Max;
			KEYType key = current->key;
			tmp = nullptr;
			do{
				if(current->key > key){
					tmp = current;
					key = current->key;
				}
				current = current->right;
			}while(current!=this->Max);
			if(tmp){
				this->Max = tmp;
			}
			this->heap_consolidate();
		}
		--this->node_num;
		return value;
	}
}