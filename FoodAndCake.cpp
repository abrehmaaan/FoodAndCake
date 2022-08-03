#include<iostream>
#include<cstring>
using namespace std;
class Food{
    char* name;
public:
    Food(){
        name = NULL;
    }
    Food(const char* name){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    char* getName() const{
        return name;
    }
    void setName(const char* n){
        delete[]name;
        this->name = new char[strlen(n) + 1];
        strcpy(this->name, n);
    }
    Food(const Food& f) {
        name = new char[strlen(f.name) + 1];
        strcpy(name, f.name);
    }
    ~Food() {
        delete[]name;
        name = NULL;
    }
    const Food& operator=(const Food& s) {
        delete[]name;
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        return s;
    }
    void output() const{
        cout<<name<<endl;
    }
};
class Cake:public Food{
    char* topping;
public:
    Cake():Food(){
        topping = NULL;
    }
    Cake(const char* name, const char* topping):Food(name){
        this->topping = new char[strlen(topping) + 1];
        strcpy(this->topping, topping);
    }
    char* getTopping() const{
        return topping;
    }
    void setTopping(const char* n){
        delete[]topping;
        this->topping = new char[strlen(n) + 1];
        strcpy(this->topping, n);
    }
    Cake(const Cake& f):Food(f.getName()) {
        topping = new char[strlen(f.topping) + 1];
        strcpy(topping, f.topping);
    }
    ~Cake() {
        delete[]topping;
        topping = NULL;
    }
    const Cake& operator=(const Cake& s) {
        this->setName(s.getName());
        delete[]topping;
        topping = new char[strlen(s.topping) + 1];
        strcpy(topping, s.topping);
        return s;
    }
    void output() const{
        cout<<getName()<<", "<<topping<<endl;
    }
};
int main() {
    cout << endl;
    Food f1("Bread");
    f1.output();
    cout << "\nf2: Copy Constructor" << endl;
    Food f2 = f1;
    f2.output();
    cout << "\nf3: Assignment Overload" << endl;
    Food f3;
    f3 = f2;
    f3.output();
    cout << "\nFood: Mutator" << endl;
    f1.setName("Pizza");
    f2.setName("Sandwich");
    f1.output();
    f2.output();
    f3.output();
    cout << "\nCake:\n" << endl;
    Cake c1("Ice Cream Cake", "Chocolate Icing");
    c1.output();
    cout << "\ns2: Copy Constructor" << endl;
    Cake c2(c1);
    c2.output();
    cout << "\ns3: Assignment Overload" << endl;
    Cake c3;
    c3 = c2;
    c3.output();
    cout << "\nCake: Mutator" << endl;
    c1.setName("Cheese cake");
    c1.setTopping("Strawberry");
    c2.setName("Potato Cake");
    c2.setTopping("Vanilla");
    c1.output();
    c2.output();
    c3.output();
    cout << endl;
    return 0;
}
