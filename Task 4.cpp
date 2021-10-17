#include <iostream>
#include <string>

using namespace std;

class Customer
{
    string name, member_type;

    public:

    Customer(string name_, string member_type_ = "none")
        :name(name_), member_type(member_type_)
        {}

    string get_name() { return name; }
    string get_member_type() { return member_type; }
};

class Store
{
    string products[3];
    double prices[3];

    string services[3];
    double prices_s[3];

    public:
    
    Store()
    {
        products[0] = "eggs";
        products[1] = "bread";
        products[2] = "milk";

        prices[0] = 10;
        prices[1] = 3.50;
        prices[2] = 2.50;

        services[0] = "cleaning";
        services[1] = "cooking";
        services[2] = "babysitting";

        prices_s[0] = 50;
        prices_s[1] = 35;
        prices_s[2] = 20;
    }

    double get_product_price(const string& name_)
        {
            int x = -1;
            for(int i = 0; i <= 2; i++)
            {
                if(name_ == products[i])
                {
                    x = i;
                    break;
                }
            }

            if (x == -1)
            {
                return 0;
            }
            else
            {
                return prices[x];
            }
        }

    double get_service_price(const string& name_)
        {
            int x = -1;
            for(int i = 0; i <= 2; i++)
            {
                if(name_ == services[i])
                {
                    x = i;
                    break;
                }
            }

            if (x == -1)
            {return 0;}
            else
            {return prices_s[x];}
        }

        friend class Visit;
};

class DiscountRate
{
    double service_discount_premium;
    double service_discount_gold;
    double service_discount_silver;
    
    double product_discount_premium;
    double product_discount_gold;
    double product_discount_silver;

    public:

    DiscountRate()
        :service_discount_premium(0.2), service_discount_gold(0.15), service_discount_silver(0.1),
         product_discount_premium(0.1), product_discount_gold(0.1), product_discount_silver(0.1)
    {}

    double get_stuff() { return service_discount_premium; }

    double get_service_discount_rate(const string& status_)
    {
        if (status_ == "premium")
        {
            return service_discount_premium;
        }
        else if (status_ == "gold")
        {
            return service_discount_gold;
        }
        else if(status_ == "silver")
        {
            return service_discount_silver;
        }
        else
        {
            return 0;
        }
    }

    double get_product_discount_rate(const string& status_)
    {
        if (status_ == "premium")
        {
            return product_discount_premium;
        }
        else if (status_ == "gold")
        {
            return product_discount_gold;
        }
        else if(status_ == "silver")
        {
            return product_discount_silver;
        }
        else
        {
            return 0;
        }
    }

    friend class Visit;

};

class Visit
{
    Store store;
    DiscountRate discount;

    double service_price;
    double product_price;

    public:

    Visit(Store store_, DiscountRate discount_)
        :store(store_), discount(discount_), service_price(0), product_price(0)
    {}

    void make_visit(Customer customer_, const string& product_to_buy)
    {
        product_price += store.get_product_price(product_to_buy)*(1 - discount.get_product_discount_rate(customer_.get_member_type()));
        service_price += store.get_service_price(product_to_buy)*(1 - discount.get_service_discount_rate(customer_.get_member_type()));  
    }

    double get_service_expense() { return service_price; }
    double get_product_expense() { return product_price; }
    double get_total_expense() { return service_price + product_price; }
};

int main()
{
    Store store;
    DiscountRate discount;

    Customer first("Adam", "premium");
    

    Visit first_one(store, discount);
    first_one.make_visit(first, "eggs");
    first_one.make_visit(first, "babysitting");

    cout << "Products total cost: " << first_one.get_product_expense() << endl;
    cout << "Services total cost: " << first_one.get_service_expense() << endl;
    cout << "Total cost is: " << first_one.get_total_expense() << endl;
}
