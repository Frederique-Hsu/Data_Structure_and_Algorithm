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

    /*============================================================================================*/

    typedef double Money;
    class Account
    {
    public:
        void applyInterest();
        static double rate();
        static void rate(double);   /* sets a new rate */
        Money balance()
        {
            return bal;
        }
    private:
        std::string owner;
        double amount;
        static double interestRate;
        static double initialRate();
        Money bal;
    private:
        static const int period = 30;   /* interest posted every 30 days */
        double daily_tbl[period];       /* OK: because period is constant expression */
    };

    /*============================================================================================*/

    class ConstRef
    {
    public:
        ConstRef(int num);
    private:
        int number;
        const int constNum;
        int& refNum;
    };

    /*============================================================================================*/

    struct NoName
    {
        NoName();
        NoName(const NoName& orig);
        ~NoName();
    private:
        std::string *pstring;
        int i;
        double d;
    };

    typedef struct NoName *PNoName;

#endif  /* MISC_H */
