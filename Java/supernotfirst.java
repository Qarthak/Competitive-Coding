// A simple Java program to demonstrate multiple
// inheritance through default methods.
interface TestInterface1
{
	// default method
	default void show()
	{
		System.out.println("Default TestInterface1");
	}
}

interface TestInterface2
{
	// abstract TestInterface1(int x);
	// Default method
	static void show()
	{
		System.out.println("Default TestInterface2");
	}
}

// Implementation class code
interface supernotfirst extends TestInterface2/* , TestInterface2 */
{
	// Overriding default show method
	// public void show()
	// {
	// 	int x=10;
	// 	// use super keyword to call the show
	// 	// method of TestInterface1 interface
	// 	// TestInterface1.super.show();

	// 	// use super keyword to call the show
	// 	// method of TestInterface2 interface
	// 	// TestInterface2.super.show();
	// }

	public static void main(String args[])
	{
		System.out.println("da");
		// supernotfirst.show();
		// supernotfirst d = new supernotfirst();
		// d.show();
	}
}