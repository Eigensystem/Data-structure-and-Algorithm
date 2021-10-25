#include "Fib_heap.hpp"

namespace Myqueue{
	template<typename Type> class priority_queue{
	public:
		MyFibheap::Fibheap<Type,Type> * fibheap;

		priority_queue();
		~priority_queue();
		void push(const Type& value);
		void pop();
		int size() const;
		Type top() const;
		bool empty();
	};

	template<typename Type>
	priority_queue<Type>::priority_queue(){
		this->fibheap = new MyFibheap::Fibheap<Type, Type>;
	}

	template<typename Type>
	priority_queue<Type>::~priority_queue(){
		delete this->fibheap;
	}

	template<typename Type>
	void priority_queue<Type>::push(const Type& value){
		this->fibheap->insert(value, value);
	}

	template<typename Type>
	int priority_queue<Type>::size() const{
		return this->fibheap->node_num;
	}

	template<typename Type>
	bool priority_queue<Type>::empty(){
		return !this->fibheap->node_num;
	}

	template<typename Type>
	Type priority_queue<Type>::top() const{
		return this->fibheap->showmax();
	}

	template<typename Type>
	void priority_queue<Type>::pop(){
		this->fibheap->extract_max();
	}
}