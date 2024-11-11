#include <iostream>
#include <vector>
#include <fstream>

class Macronutrient
{
    int Proteins;
    int Carbohydrates;
    int Fats;
public:
    Macronutrient(int Proteins_, int Carbohydrates_, int Fats_) : Proteins(Proteins_), Carbohydrates(Carbohydrates_), Fats(Fats_) {}
    Macronutrient(const Macronutrient& other) : Proteins{other.Proteins}, Carbohydrates{other.Carbohydrates}, Fats{other.Fats} {}
    Macronutrient& operator=(const Macronutrient& other)
    {
        Proteins = other.Proteins;
        Carbohydrates = other.Carbohydrates;
        Fats = other.Fats;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& out, const Macronutrient& Macronutrient)
    {
        out << "\n";
        out << Macronutrient.Proteins << "\n";
        out << Macronutrient.Carbohydrates << "\n";
        out << Macronutrient.Fats << "\n";
        return out;
    }
    ~Macronutrient() = default;
};

class Micronutrient
{
    int Vitamins;
    int Minerals;
public:
    Micronutrient(int Vitamins_, int Minerals_) : Vitamins(Vitamins_), Minerals(Minerals_) {}
    friend std::ostream& operator<<(std::ostream& out, const Micronutrient& Micronutrient)
    {
        out << Micronutrient.Vitamins << "\n";
        out << Micronutrient.Minerals << "\n";
        return out;
    }
};

class Food
{
    std::string Name;
    Macronutrient Macronutrients;
    Micronutrient Micronutrients;
public:
    Food();
    Food(const std::string& Name_, const Macronutrient& Macronutrients_, const Micronutrient& Micronutrients_) : Name(Name_), Macronutrients(Macronutrients_), Micronutrients(Micronutrients_) {}
    friend std::ostream& operator<<(std::ostream& out, const Food& Food)
    {
        out << Food.Name;
        out << Food.Macronutrients;
        out << Food.Micronutrients;
        return out;
    }
    void SaveFood()
    {
        std::ofstream fout("/home/marcu/CLionProjects/FoodTracker/Database", std::ios::app);
        if(!fout.is_open())
        {
            std::cerr << "Failed to open file!" << std::endl;
            return;
        }
        fout << Name << Macronutrients << Micronutrients;
        fout.close();
    }
};

class Journal
{
    std::vector<Food> Foods;
    std::vector<int> Grams;
public:
    Journal(const std::vector<Food>& Foods_, const std::vector<int>& Grams_) : Foods(Foods_), Grams(Grams_) {}
    friend std::ostream& operator<<(std::ostream& out, const Journal& Journal)
    {
        out << "Foods: ";
        for (long unsigned int i = 0; i < Journal.Foods.size(); i++)
        {
            out << Journal.Foods[i];
            out << "    Grams: ";
            out << Journal.Grams[i];
            out << "\n";
        }
        return out;
    }
};
void SaveFood()
{
    std::cout << "Name: ";
    std::string Name;
    std::cin >> Name;
    std::cout << "Proteins: ";
    int Proteins;
    std::cin >> Proteins;
    std::cout << "Carbohydrates: ";
    int Carbohydrates;
    std::cin >> Carbohydrates;
    std::cout << "Fats: ";
    int Fats;
    std::cin >> Fats;
    std::cout << "Vitamins: ";
    int Vitamins;
    std::cin >> Vitamins;
    std::cout << "Minerals: ";
    int Minerals;
    std::cin >> Minerals;
    Food f1{Name, {Proteins, Carbohydrates, Fats}, {Vitamins, Minerals}};
    f1.SaveFood();
}

int main()
{
    int i = 99;
    while(i)
    {
        std::cout << "      Menu";
        std::cout << "\n";
        std::cout << "1.Save food\n";
        std::cout << "9.Exit\n";
        std::cin >> i;
        if(i == 1)
        {
            SaveFood();
        }
        if(i == 9)
        {
            i = 0;
        }
    }
    return 0;
}
