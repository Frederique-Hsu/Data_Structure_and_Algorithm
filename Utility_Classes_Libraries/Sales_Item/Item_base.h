#ifndef ITEM_BASE_H
#define ITEM_BASE_H

    #include <iostream>
    #include <string>
    using namespace std;

    class Item_base;

    /* Item sold at an undiscounted price
     * derived classes will define various discount strategies.
     */
    class Item_base
    {
    public:
        Item_base(const string& book = "", double sales_price = 0.00);
        virtual ~Item_base();
    public:
        string book() const;
        virtual double net_price(size_t n) const;
    private:
        string isbn;    /* identifier for the item */
    protected:
        double price;   /* normal, undiscounted price */
    };

    void print_total(ostream& os, const Item_base& item, size_t n);


#endif  /* ITEM_BASE_H */
