#ifndef BULK_ITEM_H
#define BULK_ITEM_H

    #include "Item_base.h"

    class Bulk_item;

    /* discount kicks in when a specified number of copies of same book are
     * sold, the discount is expressed as a fraction used to reduce the normal price.
     */
    class Bulk_item : public Item_base
    {
    public:
        double net_price(size_t n) const;
    private:
        size_t min_qty;         /* minimum purchase for discount to apply. */
        double discount;        /* fractional discount to apply */
    };

#endif  /* BULK_ITEM_H */
