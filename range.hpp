#include <iostream>
#include <string>

#pragma once

namespace itertools{
    class range{
        int _start, _end ;
        public:
            range(int s, int e): _start(s),_end(e){}
        class iterator{
            private:
		        int curr;

            public:

            iterator(int c)
                : curr(c) {
            }
            int operator*() const {
                return curr;
            }

            // ++i;
            iterator& operator++() {
                ++curr;
                return *this;
            }
            const iterator operator++(int) {
                iterator tmp= *this;
                ++curr;
                return tmp;
		    }

            bool operator==(const iterator& r) const {
                return curr == r.curr;
            }

            bool operator!=(const iterator& r) const {
                return curr != r.curr;
            }
        };  // END OF CLASS ITERATOR

        iterator begin() {
		return iterator{_start};
	    }
	
	    iterator end() {
		return iterator{_end};
	    }
    };
}