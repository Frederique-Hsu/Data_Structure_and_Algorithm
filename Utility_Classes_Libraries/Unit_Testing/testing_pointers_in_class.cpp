#include "testing_pointers_in_class.h"
#include "../Pointers_in_Class/HasPtr.h"

void testing_points_in_class()
{
    copy_assign_pointer_member();
}

void copy_assign_pointer_member()
{
#if (MANAGE_POINTER_MEMBER_BY == PLAIN_POINTER)
    int obj = 0;
    HasPtr ptr1(&obj, 42);
    HasPtr ptr2(ptr1);

    ptr1.set_int(0);
    int value2 = ptr2.get_int();
    int value1 = ptr1.get_int();

    ptr1.set_ptr_val(100);
    int ptrvalue2 = ptr2.get_ptr_val();
    int ptrvalue1 = ptr1.get_ptr_val();

    int *ip = new int(50);      /* dynamically allocated int initialized to 50 */
    HasPtr ptr(ip, 10);         /* HasPtr points to same object as ip does. */
    delete ip;                  /* object pointed to by ip has been freed. */
    ptr.set_ptr_val(0);         /* disaster: The object to which HasPtr points was freed. */
#elif (MANAGE_POINTER_MEMBER_BY == REF_COUNT_SMART_POINTER)
    int obj = 25;
    HasPtr p1(&obj, 42);
    HasPtr p2(p1);
    HasPtr p3 = p1;
#elif (MANAGE_POINTER_MEMBER_BY == VALUE_SEMATICS_POINTER)

#endif
}
