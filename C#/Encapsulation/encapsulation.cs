class Encapsulation
{
    private string name;
    private int age;

    public string Name
    {
        get { return name; }
        set { name = value; }
    }

    public int Age
    {
        get { return age; }
        set
        {
            if (value >= 0)
                age = value;
            else
                Console.WriteLine("Age cannot be negative.");
        }
    }
}


class program()
{
    static void Main()
    {
        Encapsulation person = new Encapsulation();
        person.Name = "Alice";
        person.Age = 30;

        Console.WriteLine($"Name: {person.Name}, Age: {person.Age}");

        // Attempting to set a negative age
        person.Age = -5; // This will trigger the validation message
    }
}