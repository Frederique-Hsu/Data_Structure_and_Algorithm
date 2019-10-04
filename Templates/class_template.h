#ifndef CLASS_TEMPLATE_H
#define CLASS_TEMPLATE_H

    #include <vector>
    using namespace std;

    template<class Type>
    class Queue
    {
    public:
        Queue();
        Queue(const Type& value);
        Type& front();
        const Type& front() const;
        void push(const Type&);
        void pop();
        bool empty() const;
    private:
        vector<Type> vec;
    };

    #include "class_template.cpp"

#endif  /* CLASS_TEMPLATE_H */
