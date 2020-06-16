
#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace itertools{
    class plus
    {
    public:
        template <typename T>
        T operator()(T a, T b) { return a + b; }
    };
    template <typename cont, typename func = plus>
    class accumulate
    {
        cont container;
        func function;
        typedef typename cont::value_type value_type;
    public:
        accumulate(cont c , func f=plus()):container(c),function(f){}
        
        class iterator {
            typename cont::iterator start_it;
            typename cont::iterator end_it;
            typename cont::value_type sum;
            func function;
            public:
                iterator(typename cont::iterator s_it,typename cont::iterator e_it,func f):
                    start_it(s_it),end_it(e_it), sum(*s_it), function(f){}

                auto operator*() {
                    return sum;
                }

                iterator& operator++() {
                    ++start_it;
                    if(start_it!=end_it)
                        sum= function(sum,*start_it);
                    return *this;
                }

                const iterator operator++(int) {
                    iterator tmp= *this;
                    ++start_it;
                    if(start_it!=end_it)
                        sum= function(sum,*start_it);
                    return tmp;
                }

                bool operator==(const iterator& other) const {
                    return start_it == other.start_it;
                }

                bool operator!=(const iterator& other) const {
                    return start_it != other.start_it;
                }
        }; // END OF CLASS ITERATOR

        iterator begin() {
		return iterator{container.begin(),container.end(),function};
	    }
	
	    iterator end() {
		return iterator{container.end(),container.end(),function};
	    }
     };
}