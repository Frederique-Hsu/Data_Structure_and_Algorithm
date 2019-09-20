#ifndef SALES_ITEM_H
#define SALES_ITEM_H

    #include <string>
    #include <iostream>

    using namespace std;

    class Sales_item;

    class Sales_item
    {
        friend istream& operator>>(istream& in, Sales_item& item);
        friend ostream& operator<<(ostream& out, const Sales_item& item);
    public:
        explicit Sales_item();
        virtual ~Sales_item();
        Sales_item(string isbn, double price);
        Sales_item(const Sales_item& other);
        Sales_item& operator=(const Sales_item& other);

        Sales_item& operator+=(const Sales_item& item);
        bool same_isbn(const Sales_item& other) const;
        inline double avg_price() const;
    private:
        string isbn;
        unsigned units_sold;
        double revenue;
    };
    Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs);

#endif  /* SALES_ITEM_H */
