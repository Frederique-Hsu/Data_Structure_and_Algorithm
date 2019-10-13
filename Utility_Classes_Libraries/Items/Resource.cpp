#include "Resource.h"

Resource::Resource(params p) : r(allocate(p))
{
}

Resource::~Resource()
{
    release(r);
}

resource_type* Resource::allocate(params p)
{

}

void Resource::release(resource_type* p)
{

}
