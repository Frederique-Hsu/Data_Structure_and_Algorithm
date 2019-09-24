#include "ScreenPtr.h"
#include "Screen.h"

ScrPtr::ScrPtr(Screen* p) : sp(p), use(1)
{
}

ScrPtr::~ScrPtr()
{
    delete sp;
}

ScreenPtr::ScreenPtr(Screen* p) : ptr(new ScrPtr(p))
{
}

ScreenPtr::ScreenPtr(const ScreenPtr& orig) : ptr(orig.ptr)
{
    /* copy members and increment the use count */
    ++(ptr->use);
}

ScreenPtr& ScreenPtr::operator=(const ScreenPtr &orig)
{
    ++(orig.ptr->use);
    if (--(ptr->use) == 0)
    {
        delete ptr;
    }
    ptr = orig.ptr;
    return *this;
}

ScreenPtr::~ScreenPtr()
{
    /* if use count goes to zero, delete the ScrPtr* object */
    if (--(ptr->use) == 0)
    {
        delete ptr;
    }
}

Screen& ScreenPtr::operator*()
{
    return *(ptr->sp);
}

Screen* ScreenPtr::operator->()
{
    return ptr->sp;
}

const Screen& ScreenPtr::operator*() const
{
    return *(ptr->sp);
}

const Screen* ScreenPtr::operator->() const
{
    return ptr->sp;
}
