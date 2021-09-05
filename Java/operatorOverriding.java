class Hello{
	public int x;
	Hello(int x){
		this.x=x;
	}
	// public boolean equals(Object other){
	// 	System.out.println("WELL");
	// 	// return this.x==other.x;
	// 	return true;
	// }
	// public Object afndakj(){
	// 	// return null;
	// }
}

class operatorOverriding{
	public static void main(String[] args) {
		Hello x=new Hello(122);
		Hello y=new Hello(122);
		Hello z=y;
		System.out.println(x.equals(y));
		System.out.println(x.getClass());
		// System.out.println(x==y);
		// System.out.println(y);
	}
}