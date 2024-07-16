class A
{
public:
    int pub;

protected:
    int pro;

private:
    int pri;
};
class B : public A
{
    // pub is public here
    // pro is protected here
    // pri is not accessible
};
class C : protected A
{
    // pub is protected here
    // pro is protected here
    // pri is not accessible
};
class D : private A
{
    // pub is private  here
    // pro is private here
    // pro is not accessible
};