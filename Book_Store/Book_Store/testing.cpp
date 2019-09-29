#include "testing.h"
#include "../../Utility_Classes_Libraries/Items/Bulk_item.h"
#include "../../Utility_Classes_Libraries/Items/Sales_item.h"
#include "../../Utility_Classes_Libraries/Items/Basket.h"

#include <iostream>
#include <set>
using namespace std;

void execute_test_cases()
{
    transform_derived_from_base();
    cout << "\n" << endl;

    convert_base_with_derived();
    cout << "\n" << endl;

    instantiate();
    cout << "\n" << endl;

    call_virtual_destructor();
    cout << "\n" << endl;

    utilize_associative_container_comparison();
}

void transform_derived_from_base()
{
    Item_base item;
    print_total(cout, item, 10);
    Item_base* p = &item;
    Bulk_item bulk;
    print_total(cout, bulk, 25);
    p = &bulk;
    print_total(cout, *p, 100);
}

void convert_base_with_derived()
{
    Bulk_item bulk("978-7-5612-1135-9", 28.00, 30, 0.20);

    /* call the copy constructor "Item_base::Item_base(const Item_base& orig)" */
    Item_base item(bulk);   /* bulk is "sliced down" to its Item_base portion */

    /* call the assign constructor "Item_base::operator=(const Item_base& orig)" */
    item = bulk;            /* bulk is also "sliced down" to its Item_base portion */

    Item_base base;
    // Bulk_item* bulkPtr = &base;     /* Error: cannot convert base to derived */
    // Bulk_item& bulkRef = base;      /* Error: cannot convert base to derived */
    // bulk = base;                    /* Error: cannot convert base to derived */
    Item_base* itemPtr = &bulk;     /* OK: dynamic type is Bulk_item */
    cout << "The total price: " << itemPtr->net_price(25) << endl;
}

void instantiate()
{
    Bulk_item bulk("978-7-121-28108-2", 45.00, 5, 0.15);
    cout << "This book's ISBN: " << bulk.book() << endl;

    Bulk_item* bulkPtr = &bulk;
    Item_base* itemPtr = &bulk;
    bulkPtr->discount_policy();
    /* Error: itemPtr has type Item_base*, it cannot access
     * Bulk_item::discount_policy()
     */
    // itemPtr->discount_policy();

    /* Disc_item is an abstract class,
     * cannot define a Disc_item object.
    Disc_item discounted;
     */
}

void call_virtual_destructor()
{
    Item_base* itemPtr = new Item_base("978-7-121-28108-2", 45.00);
    delete itemPtr;     /* OK: destructor for Item_base called */

    itemPtr = new Bulk_item("978-7-03-019483-1", 27.00, 50, 0.25);
    delete itemPtr;     /* OK: destructor for Bulk_item called */
}

void save_objects_into_container()
{
    multiset<Item_base> basket;
    Item_base base;
    Bulk_item bulk;
    basket.insert(base);        /* OK: add copy of base to basket */
    basket.insert(bulk);        /* OK: but bulk sliced down to its base part */
}

void utilize_associative_container_comparison()
{
    multiset<Sales_item, Comp> items(compare);

    Basket cart;
    cart.add_item(Sales_item(Bulk_item("978-7-03-019483-1", 27.00, 50, 0.25)));
    cart.add_item(Sales_item(Bulk_item("978-7-121-28108-2", 45.00, 5, 0.15)));
    cart.add_item(Sales_item(Item_base("978-7-121-28108-2", 45.00)));
    cart.add_item(Sales_item(Bulk_item("978-7-5612-1135-9", 28.00, 30, 0.20)));

    cout << cart.size(Sales_item(Item_base("978-7-121-28108-2"))) << endl;
    cout << "The total price is: " << cart.total() << endl;
}
