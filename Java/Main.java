import java.io.*;

interface www {
	public int x=213;
	static void lesgo(){
		System.out.println("LESSGOOO");
	}
}



class Parent{
	public Parent(){
		System.out.println("HELLO");
	}
	void speak(){
		System.out.println("Hello");
	}
}

class Main extends Parent implements www
{
	Main(){
		super();
		// int x=10;
	}
	public static void main (String[] args)
	{
		// www Hello;
		System.out.println("hello");
		Main x=new Main();
		x.speak();
	}
}

// Java program to illustrate the concept
// of Autoboxing and Unboxing

// class Main
// {
// 	public static void main (String[] args)
// 	{
// 		// creating an Integer Object
// 		// with value 10.
// 		int prim=100;
		
// 		//Autoboxing up primitive type int into Integer class
// 		Integer i = prim;

// 		// Autounboxing the Object
// 		int i1 = i;

// 		System.out.println("Value of i: " + i);
// 		System.out.println("Value of i1: " + i1);

// 		//Autoboxing of char
// 		Character gfg = 'a';

// 		// Auto-unboxing of Character
// 		char ch = gfg;
// 		System.out.println("Value of ch: " + ch);
// 		System.out.println("Value of gfg: " + gfg);

// 	}
// }
