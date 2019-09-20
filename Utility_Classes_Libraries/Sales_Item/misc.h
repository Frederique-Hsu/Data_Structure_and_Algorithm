#ifndef MISC_H
#define MISC_H

    #include <string>

    class Record
    {
        typedef std::size_t size;
        Record();
        Record(size s);
        Record(std::string s);

        size byte_count;
        std::string name;
    public:
        size get_count() const;
        std::string get_name() const;
    };

#endif  /* MISC_H */
