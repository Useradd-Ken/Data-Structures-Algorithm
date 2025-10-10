class Animal
{
    public virtual void MakeSound()
    {
        Console.WriteLine("Some generic animal sound");
    }

    public void Eat()
    {
        Console.WriteLine("The animal is eating.");
    }
}

class program
{
    static void Main()
    {
        Animal myAnimal = new Dog(); // Upcasting
        myAnimal.MakeSound(); // Output: Woof!
        myAnimal.Eat();       // Output: The dog is eating.

        myAnimal = new Cat(); // Upcasting
        myAnimal.MakeSound(); // Output: Meow!
        myAnimal.Eat();       // Output: The cat is eating.
    }
}