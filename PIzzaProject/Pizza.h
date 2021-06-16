#include <iostream>
using namespace std;
#define PIZZA_CALORIES 200
#define ONE_SLICE_COST 10
#define PERSONAL_CALORIES 800
#pragma once
class Pizza // abstract class   // המטרה של מחלקה אבסטרקטית היא ליצור 
	//interface משותף לכל המחלקות
{

public: //  מחלקה זאת בשבילך לחסוך בזיכרון

	virtual void  Set_price(int) = 0; // pure virtual function to save  memory

	virtual void  Set_calories(int) = 0;

	virtual int  GetCalories()const = 0;

	virtual int Getprice()const = 0;

protected:
	int Price;
	int  Calories;
};
#pragma once
class Slice_Pizza : public Pizza // משולש פיצה
{
	friend void print_Slice_Pizza(Slice_Pizza);
public:
	Slice_Pizza();//defualt constractor

	Slice_Pizza(int);// another constractor

	virtual void  Set_price(int);  // virtual fuction so I can do Polymorphism right 

	virtual void  Set_calories(int);

	virtual int   GetCalories()const;

	virtual int  Getprice()const;

	virtual ~Slice_Pizza();//defualt distractor

private:

};
#pragma once
class Personal_Pizza :public Slice_Pizza  // פיצה  אישית
{
	friend void print_Personal_Pizza(Personal_Pizza);
public:
	Personal_Pizza();//defualt constractor

	Personal_Pizza(int);// another constractor

	virtual void  Set_price(int);

	virtual void  Set_calories(int);

	virtual int   GetCalories()const;

	virtual int  Getprice()const;

	virtual ~Personal_Pizza();//defualt distractor
	Slice_Pizza GetSlice();
private:
	Slice_Pizza Slices;
};
#pragma once
class Cheff_Pizza :public Pizza // פיצת השף
{
	friend void print_Cheff_Pizza(Cheff_Pizza);
public:
	Cheff_Pizza();//defualt constractor

	Cheff_Pizza(int);// another constractor

	virtual void  Set_price(int);

	virtual void  Set_calories(int);

	virtual int   GetCalories()const;

	virtual int  Getprice()const;

	virtual ~Cheff_Pizza();//defualt distractor

private:

};
#pragma once
class Family_Pizza :public Slice_Pizza // פיצה משפחתית
{
public:
	Family_Pizza();//defualt constractor

	Family_Pizza(int);// another constractor

	void  Set_calories(int);

	int   GetCalories()const;

	int  Getprice()const;

	Slice_Pizza GetSlice();

	

	~Family_Pizza();//defualt distractor
private:
	Slice_Pizza Slices;

};
 
class SaveOrder :public CObject
{
public:
	DECLARE_SERIAL(SaveOrder)
	SaveOrder() {
		count_F=0;
		count_P=0;
		count_S=0;
		count_c=0;
	};
	virtual ~SaveOrder(){ };
	int count_F;
	int count_P;
	int count_S;
	int count_c;

	void Serialize(CArchive& archive);
};