// This file shows basic functions of reading in a CSV file using C++98
// Please add your name to your code! 

/* Homework Objective: fix this program to match the requirements listed: 
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category 
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.
All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std; 
string AvePricePerBrand(vector<string> Brand, vector<float> Price);
string AvePricePerCategory(vector<string> Brand, vector<float> Price);
int main() {

  // define variables
  string sku, brand, category, year, price; 
  vector<int>vSKU;
  vector<string>vBrand;
  vector<string>vCategory;
  vector<int>vYear;
  vector<float>vPrice;

  ifstream in_stream;
  in_stream.open("data.csv"); //opening the file.

  if (!in_stream.fail()) { //if the file is open

    string line;

    while (getline(in_stream, line)) { //while the end of file is NOT reached
      stringstream in_stream(line);
     // Fields: sku,brand,category,year,price

     getline(in_stream, sku, ',');
     stringstream ssku(sku); 
     int iSKU = 0;
     ssku >> iSKU;
     vSKU.push_back(iSKU);

     getline(in_stream, brand, ',');
     vBrand.push_back(brand);
     getline(in_stream, category, ',');
     vCategory.push_back(category);

     getline(in_stream, year, ','); 
     stringstream syear(year);
     int iYear;
     syear >> iYear;
     vYear.push_back(iYear);

     getline(in_stream, price, '\n'); 
     stringstream sprice(price);
     float fPrice;
     sprice >> fPrice;
     vPrice.push_back(fPrice);
     
    }

    in_stream.close(); //closing the file cout << "Number of entries: " << i-1 << endl;

   } else {
    cout << "Unable to open file"; 
   }
 
  //output values 
  cout << "SKU" << "\t" << "Brand" << "\t" << "Year" << "\t" << "Price" << endl; 

  for (int j = 0; j < vSKU.size(); j++) {
        cout << vSKU[j] << "\t" << vBrand[j] << "\t" << vCategory[j] << "\t\t" << vYear[j] << "\t" << vPrice[j] << endl;
    }
    cout << AvePricePerBrand(vBrand, vPrice);
    cout << AvePricePerCategory(vCategory, vPrice);

    cout << endl;

}

string AvePricePerBrand(vector<string> Brand, vector<float> Price)
{
    string s = "";
    vector<float> AveragePrices;
    vector<string> UniqueBrands;
    vector<int> UniqueBrandsCount;
    
    bool check = false;
    int count = 0;
    float price = 0;

    //seperating unique brands
    for (int i = 0; i < Brand.size(); i++)
    {
        check = false;
        for (int j = 0; j < UniqueBrands.size(); j++)
        {
            if (UniqueBrands[j] == Brand[i])
            {
                check = true;
                break;
            }
        }
        if (check == false)
        {
            UniqueBrands.push_back(Brand[i]);
        }
    }

    //number of occurances of the brand
    for (size_t i = 0; i < UniqueBrands.size(); i++)
    {
        count = 0;
        price = 0;
        for (size_t j = 0; j < Brand.size(); j++)
        {
            if (UniqueBrands[i] == Brand[j])
            {
                price += Price[j];
                count++;
            }
        }
        UniqueBrandsCount.push_back(count);
        AveragePrices.push_back(price);
    }

    //building the string
    s += "Brand Name\tAverage Price\n";
    for (size_t i = 0; i < UniqueBrands.size(); i++)
    {
        stringstream FloatToString;
        s += UniqueBrands[i] + "\t\t";
        FloatToString << (AveragePrices[i] / UniqueBrandsCount[i]);
        s += FloatToString.str();
        s += "\n";
    }
    return s;
}
string AvePricePerCategory(vector<string> Category, vector<float> Price)
{
    string s = "";
    vector<float> AveragePrices;
    vector<string> UniqueCategories;
    vector<int> UniqueCategoryCount;

    bool check = false;
    int count = 0;
    float price = 0;

    //seperating unique brands
    for (int i = 0; i < Category.size(); i++)
    {
        check = false;
        for (int j = 0; j < UniqueCategories.size(); j++)
        {
            if (UniqueCategories[j] == Category[i])
            {
                check = true;
                break;
            }
        }
        if (check == false)
        {
            UniqueCategories.push_back(Category[i]);
        }
    }

    //number of occurances of the brand
    for (size_t i = 0; i < UniqueCategories.size(); i++)
    {
        count = 0;
        price = 0;
        for (size_t j = 0; j < Category.size(); j++)
        {
            if (UniqueCategories[i] == Category[j])
            {
                price += Price[j];
                count++;
            }
        }
        UniqueCategoryCount.push_back(count);
        AveragePrices.push_back(price);
    }

    //building the string
    s += "Category Name\tAverage Price\n";
    for (size_t i = 0; i < UniqueCategories.size(); i++)
    {
        stringstream FloatToString;
        s += UniqueCategories[i] + "\t\t";
        FloatToString << (AveragePrices[i] / UniqueCategoryCount[i]);
        s += FloatToString.str();
        s += "\n";
    }
    return s;
}
