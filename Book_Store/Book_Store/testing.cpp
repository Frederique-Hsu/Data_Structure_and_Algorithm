#include "testing.h"
#include "../../Utility_Classes_Libraries/Sales_Item/Bulk_item.h"
#include "../../Utility_Classes_Libraries/Sales_Item/Item_base.h"

#include <iostream>
using namespace std;

void execute_test_cases()
{
    transform_derived_from_base();
}

void transform_derived_from_base()
{
    Item_base item;
    print_total(cout, item, 10);
    Item_base* p = &item;
    Bulk_item bulk;
    print_total(cout, bulk, 25);
    p = &bulk;
}