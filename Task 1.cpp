#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
    int n,m;
public:
    Fraction(int n_, int m_)
    {
        assert(m_ != 0);
        n = n_;
        m = m_;
    }

    void set_n(int n_) {n = n_;}
    void set_m(int m_) {m = m_;}

    int get_n()
    {
        return n;
    }
    int get_m()
    {
        return m;
    }

    Fraction addition(Fraction div_)
    {
        if(this->get_m() != div_.get_m())
        {
            int denom = this->get_m()*div_.get_m();
            int nom = this->get_n()*div_.get_m() + this->get_m()*div_.get_n();
            Fraction new_fract(nom,denom);
            return new_fract;
        }
        else
        {
            Fraction new_fract(this->get_n() + div_.get_n(),div_.get_m());
            return new_fract;
        }
    }

    Fraction substraction(Fraction div_)
    {
        if(this->get_m() != div_.get_m())
        {
            int denom = this->get_m()*div_.get_m();
            int nom = this->get_n()*div_.get_m() - this->get_m()*div_.get_n();
            Fraction new_fract(nom,denom);
            return new_fract;
        }
        else
        {
            Fraction new_fract(this->get_n() - div_.get_n(),div_.get_m());
            return new_fract;
        }
    }

    friend Fraction division(Fraction div_1, Fraction div_2);
    friend Fraction multiplication(Fraction div_1, Fraction div_2);

};

Fraction division(Fraction div_1, Fraction div_2)
{
    Fraction new_fract(div_1.get_n()*div_2.get_m(),div_1.get_m()*div_2.get_n());
    return new_fract;
}

Fraction division(Fraction div_1, Fraction div_2)
{
    Fraction new_fract(div_1.get_n()*div_2.get_n(),div_1.get_m()*div_2.get_m());
    return new_fract;
}

int main()
{

    Fraction X(2,4);
    Fraction B(1,4);

    Fraction C = X.addition(B);

    cout << C.get_n() << endl;

    Fraction D = X.substraction(B);
    cout << D.get_n() << " " << D.get_m() << endl;

    Fraction E = division(X,B);

    cout << E.get_n() << " " << E.get_m() << endl;

    return 0;
}
