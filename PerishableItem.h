#ifndef PERISHABLEITEM_H
#define PERISHABLEITEM_H

class Perishable{
    private:
        int shelfLifeinDay;
        int expirationList[];
    public:
        Perishable();
        int get_shelfLifeinDay();
        void set_shelfLifeinDay(int n);
        void recalculate_expirationList();
        void removeItem(std::string);
        virtual void print();
        ~Perishable();
};


#endif