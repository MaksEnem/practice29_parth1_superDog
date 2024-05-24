#include <iostream>

class Talent
{
public:
    virtual void setTalent() = 0;    
    virtual void getIsTalent() = 0;
};

class Swimming : virtual public Talent
{
private:
    bool isSwimming = false;
    
public:
    virtual void setTalent() override
    {
        std::string answer;
        std::cout << "If the dog can swimming, then enter \"yes\": ";
        std::cin >> answer;
        if (answer == "yes") isSwimming = true;        
    }

    virtual void getIsTalent() override
    {
        if (isSwimming == true) std::cout << "It can \"Swim\"" << std::endl;        
    }
};

class Dancing : virtual public Talent
{
private:
    bool isDancing = false;

public:
    virtual void setTalent() override
    {
        std::string answer;
        std::cout << "If the dog can dancing, then enter \"yes\": ";
        std::cin >> answer;
        if (answer == "yes") isDancing = true;        
    }

    virtual void getIsTalent() override
    {
        if (isDancing == true) std::cout << "It can \"Dance\"" << std::endl;        
    }
};

class Counting : virtual public Talent
{
private:
    bool isCounting = false;

public:
    virtual void setTalent() override
    {
        std::string answer;
        std::cout << "If the dog can counting, then enter \"yes\": ";
        std::cin >> answer;
        if (answer == "yes") isCounting = true;        
    }

    virtual void getIsTalent() override
    {
        if (isCounting == true) std::cout << "It can \"Count\"" << std::endl;       
    }
};

class Dog
{
private:
    std::string name;
public:
    Dog(std::string inName)
    {
        name = inName;
    }
   
    void addTalents(Talent* talent[])
    {
        for (int i = 0; i < 3; ++i)
        {
            talent[i]->setTalent();
        }
    }

    void show_talents(Talent* talent[])
    {
        std::cout << "This is " << name << " and it has some talents:\n";
        for (int i = 0; i < 3; ++i)
        {
            talent[i]->getIsTalent();
        }
    }
};

int main()
{
    Dog dog1("Steve");   

    Talent* arrTalent[3];
    arrTalent[0] = new Swimming();
    arrTalent[1] = new Dancing();
    arrTalent[2] = new Counting();    

    dog1.addTalents(arrTalent);
    dog1.show_talents(arrTalent);

    return 0;    
}