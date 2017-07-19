// Unique-Pointer.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <memory>

class Fish
{
public:
	Fish() { std::cout << "Fish: Constructed" << std::endl; }
	~Fish() { std::cout << "Fish: Destructed" << std::endl; }

	void Swim() const { std::cout << "Fish swims in water" << std::endl; }
};
void MakeFishSwim(const std::unique_ptr<Fish>& inFish)
{
	inFish->Swim();
}

int main()
{
	std::unique_ptr<Fish> smartFish(new Fish);

	smartFish->Swim();
	MakeFishSwim(smartFish); // OK as MakeFishSwim accepts references

	std::unique_ptr<Fish> copySmartFish;
	//copySmartFish = smartFish; // it will give error as operator= is private
    return 0;
}

