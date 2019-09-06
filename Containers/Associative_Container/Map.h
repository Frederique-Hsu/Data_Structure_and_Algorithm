#ifndef ASSOCIATIVE_CONTAINER_H
#define ASSOCIATIVE_CONTAINER_H

    #include <string>
    #include <map>

    class Sales_item
    {
    public:
        Sales_item();
    private:
    };

    typedef std::string ISBN;
    typedef std::map<ISBN, Sales_item> Bookstore;

    void initialize_map_objects(void);
    void access_map_objects(void);
    void traverse_map_through_iterator(void);


#endif  /* ASSOCIATIVE_CONTAINER_H */
