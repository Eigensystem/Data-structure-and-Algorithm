#include <iostream>
#include <typeinfo>
#include "LLRB.hpp"

namespace Myset{
    template<class Type> class set{
        MyLLRB::LLRB<Type, Type> * llrb_tree;
    public:
        set(){
            llrb_tree = new MyLLRB::LLRB<Type, Type>;
        }
        bool empty() const;
        long int size() const;
        void clear();
        void insert(const Type&value);
        int erase(const Type&value);
        int count(const Type&value);
    };

    template<class Type>
    bool set<Type>::empty() const{
        if(this->llrb_tree->Element_num){
            return false;
        }
        else{
            return true;
        }
    }

    template<class Type>
    long int set<Type>::size() const{
        return this->llrb_tree->Element_num;
    }

    template<class Type>
    void set<Type>::insert(const Type&value){
        this->llrb_tree->insert(value, value);
    }

    template<class Type>
    void set<Type>::clear(){
        this->llrb_tree->CleartheTree();
    }

    // template<class Type>
    // int set<Type>::count(const Type&value){
        
    // }
}
