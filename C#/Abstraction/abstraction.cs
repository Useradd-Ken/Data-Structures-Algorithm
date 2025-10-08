class program
{
    static void Main()
    {
        // Abstract class cannot be instantiated directly
        // Animal animal = new Animal(); // This will cause a compile-time error

        Dog dog = new Dog();
        dog.MakeSound(); // Output: Woof!
        dog.Eat();       // Output: The dog is eating.
    }
}