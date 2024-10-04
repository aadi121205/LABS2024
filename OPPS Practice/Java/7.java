class A
{
    int a = 10;
    int total = 0;
    void functionA()
    {
        System.out.println("a = " + a);
        System.out.println("total = " + total);
    }
}
class B extends A
{
    int b = 20;
    void functionB()
    {
        total = a + b;
        System.out.println("b = " + b);
        System.out.println("total = " + total);
    }
}
class C extends B
{
    int c = 30;
    void functionC()
    {
        total = a + b + c;
        System.out.println("c = " + c);
        System.out.println("total = " + total);
    }
}
public class Main
{
    public static void main(String[] args)
    {
        C obj = new C();
        obj.functionA();
        obj.functionB();
        obj.functionC();
    }
}