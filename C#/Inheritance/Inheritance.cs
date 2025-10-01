using System;

class Animal
{
    string breed;
    int age;

    public void setBreed(string Breed)
    {
        breed = Breed;
    }
    public string getBreed()
    {
        return breed;
    }
    public void setAge(int Age)
    {
        age = Age;
    }
    public int getAge()
    {
        return age;
    }
    public void Pet()
    {
        Console.WriteLine($"Breed: {breed}, Age: {age}");
    }
}

class Dog : Animal
{
    string name;

    public void setName(string Name)
    {
        name = Name;
    }
    public string getName()
    {
        return name;
    }
    public void Bark()
    {
        Console.WriteLine($"Dog Name: {name}");
    }
}



class main
{
    static void Main()
    {
        Dog dog = new Dog();
        dog.setBreed("Labrador");
        dog.setAge(3);
        dog.setName("Buddy");

        dog.Pet();
        dog.Bark();
    }
}