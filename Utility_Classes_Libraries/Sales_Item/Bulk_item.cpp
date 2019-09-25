#include "Bulk_item.h"


double Bulk_item::net_price(size_t cnt) const
/* redefines base version so as to implement bulk purchase discount policy */
{
    /* if specified number of items are purchased, use discounted price */
    if (cnt >= min_qty)
    {
        return (cnt * (1 - discount) * price);
    }
    else
    {
        return (cnt * price);
    }
}
