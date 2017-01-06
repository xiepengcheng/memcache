#ifndef ITEM_H
#define ITEM_H

#include <atomic>
#include <vector>
#include <memory>
#include <iostream>
#include <time.h>

#include "hodis_slab.h"

#define ITEM_VALUE 32
#define GET_VALUE_ADDRESS(start) ((start)+(ITEM_VALUE))

class slab;

namespace hodis{

class item
{
	public:
	using Version = std::atomic<uint_fast64_t>;
        
        
        item(char* start);
        ~item();

        void set_value();
        void set_expiretime(time_t time);
        void set_slab_point(void* p);
        auto get_slab_point() -> void*;
        auto get_value() -> char*;
        auto get_expiretime() -> time_t;
	private:
        /* version number */
        Version version;
        /* timestamp LRU */
        time_t timestamp;
        /* expire time */
        time_t expiretime;
        /* belong to slab */
        void* pslab;
        /* item space key+date */
        void* value;
};

};
#endif
