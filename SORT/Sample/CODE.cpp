#include<bits/stdc++.h>

using namespace std;

struct Person {
    std::string name;
    int age;
};

bool compareByName(const Person& a, const Person& b) {
    return a.name < b.name;  // 按名称升序排序
}

bool compareByAge(const Person&a,const Person&b){
    return a.age<b.age;
}

int main() {
    std::vector<Person> people = {{"Alice", 25}, {"Bob", 20}, {"Charlie", 30}};
    sort(people.begin(), people.end(), compareByName);
    for (const auto& person : people) {
        std::cout << person.name << " - " << person.age << std::endl;
    }
    return 0;
}