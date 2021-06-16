#include "pch.h"
#include "Pizza.h"
#include <iostream>

using namespace std;

/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////משולש פיצה //////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Slice_Pizza::Slice_Pizza() //defualt constractor 
{
    Price = ONE_SLICE_COST;
    Calories = PIZZA_CALORIES;
}

Slice_Pizza::Slice_Pizza(int price)
{
    Set_price(price);
    Calories = PIZZA_CALORIES;
}

void Slice_Pizza::Set_price(int  price)
{
    Price = price;
}
void Slice_Pizza::Set_calories(int  calories)
{
    Calories = calories;
}
int  Slice_Pizza::GetCalories() const
{
    return Calories;
}

int  Slice_Pizza::Getprice() const
{
    return Price;
}

Slice_Pizza::~Slice_Pizza()
{

}

void print_Slice_Pizza(Slice_Pizza a)
{
    double price, calories;
    cout << "   ***** " << endl << "    *** " << endl << "     *   ";;

    calories = a.Calories;
    price = a.Price;
    cout << endl << " price is = " << price << endl << "Calories  " << calories << endl;
}
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////פיצה אישית///////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Personal_Pizza::Personal_Pizza()
{
    Slice_Pizza filler;
    
        Slices = filler;
   
}

Personal_Pizza::Personal_Pizza(int  price)
{
    Slice_Pizza filler(price);
    for (int i = 0; i < 4; i++)
    {
        Slices = filler;
    }
}

void Personal_Pizza::Set_price(int  price)
{
    Price = price;
}

void Personal_Pizza::Set_calories(int  calories)
{
    Slice_Pizza filler;
    filler.Set_calories(calories);

        Slices = filler;
   
}

int  Personal_Pizza::GetCalories() const
{
    return 4 * (Slices.GetCalories());
}

int  Personal_Pizza::Getprice() const
{
    return 3 * (Slices.Getprice());
}

Personal_Pizza::~Personal_Pizza()
{
   
}
Slice_Pizza Personal_Pizza::GetSlice()
{
    return Slices;
}
void print_Personal_Pizza(Personal_Pizza a)
{
    int  price, calories;
    cout << " *** " << endl << "*   *" << endl << "*   *" << endl << " *** ";
    calories = a.Calories;
    price = a.Price;
    cout << endl << " price is = " << price << endl << "Calories  " << calories << endl;
}
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////פיצת השף/////////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Cheff_Pizza::Cheff_Pizza()
{
    Price = (6 * ONE_SLICE_COST);
    Calories = (6 * PIZZA_CALORIES);
}

Cheff_Pizza::Cheff_Pizza(int  price)
{
    Set_price(price);
    Calories = (6 * PIZZA_CALORIES);
}

void Cheff_Pizza::Set_price(int  price)
{
    Price = price;
}

void Cheff_Pizza::Set_calories(int  calories)
{
    Calories = calories;
}

int  Cheff_Pizza::GetCalories() const
{
    return Calories;
}

int  Cheff_Pizza::Getprice() const
{
    return Price;
}

Cheff_Pizza::~Cheff_Pizza()
{

}
void print_Cheff_Pizza(Cheff_Pizza a)
{
    double price, calories;
    cout << "*** " << endl << "* *" << endl << "* *" << endl << "*** ";
    calories = a.Calories;
    price = a.Price;
    cout << endl << " price is = " << price << endl << "Calories  " << calories << endl;
}
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////פיצה משפחתית/////////////////////////////////////////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




Family_Pizza::Family_Pizza()
{

    Slice_Pizza filler;
  
        Slices = filler;
   

}

Family_Pizza::Family_Pizza(int price)
{
    Slice_Pizza filler(price);
    
        Slices= filler;
   
}
void Family_Pizza::Set_calories(int  calories)
{
    Slice_Pizza filler;
    filler.Set_calories(calories);
   
        Slices = filler;
   
}

int  Family_Pizza::GetCalories() const
{
    return 8 * (Slices.GetCalories());
}

int  Family_Pizza::Getprice() const
{
    return 5 * (Slices.Getprice());
}

Slice_Pizza Family_Pizza::GetSlice()
{
    return Slices;
}

Family_Pizza::~Family_Pizza()
{
   // delete[] Slices;
}

void SaveOrder::Serialize(CArchive& archive)
{
    // call base class function first
   // base class is CObject in this case
    CObject::Serialize(archive);

    // now do the stuff for our specific class
    if (archive.IsStoring())
        archive << count_F << count_P << count_S<< count_c;
    else
        archive >> count_F >> count_P >> count_S >> count_c;
}
