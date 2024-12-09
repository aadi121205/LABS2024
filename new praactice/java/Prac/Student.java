public class Student
{
    private String name;
    private int age;
    private String address;
    private String phone;
    private String email;
    private String course;
    private String rollNo;
    private String branch;
    private String college;
    private String university;
    private String semester;
    private String section;
    private String dob;

    public Student(String name, int age, String address, String phone, String email, String course, String rollNo, String branch, String college, String university, String semester, String section, String dob)
    {
        this.name = name;
        this.age = age;
        this.address = address;
        this.phone = phone;
        this.email = email;
        this.course = course;
        this.rollNo = rollNo;
        this.branch = branch;
        this.college = college;
        this.university = university;
        this.semester = semester;
        this.section = section;
        this.dob = dob;
        System.out.println("Student object created");
    }

    public void display()
    {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Address: " + address);
        System.out.println("Phone: " + phone);
        System.out.println("Email: " + email);
        System.out.println("Course: " + course);
        System.out.println("Roll No: " + rollNo);
        System.out.println("Branch: " + branch);
        System.out.println("College: " + college);
        System.out.println("University: " + university);
        System.out.println("Semester: " + semester);
        System.out.println("Section: " + section);
        System.out.println("DOB: " + dob);
    }

    public static void main(String[] args)
    {
        Student s1 = new Student("Rahul", 20, "Delhi", "1234567890", "aasfdasfds@gmail.com", "B.Tech", "123", "CSE", "ABC", "XYZ", "1st", "A", "12-12-1999");
        s1.display();
    }
}