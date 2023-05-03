#include <iostream>
#include <memory>

class Project;

class Employee {
private:
  std::shared_ptr<Project> p;
public:
  Employee () {
    std::cout << "Creating Employee " << std::endl;
  }
  ~Employee () {
    std::cout << "Destroying Employee " << std::endl;
  }
  void addProject(std::shared_ptr<Project> pro) {
    this->p = pro;
  }
};

class Project {
private:
  std::shared_ptr<Employee> p;
public:
  Project () {
    std::cout << "Creating Project " << std::endl;
  }
  ~Project () {
    std::cout << "Destroying Project " << std::endl;
  }
  void addEmployee(std::shared_ptr<Employee> emp) {
    this->p = emp;
  }
};

int main(int argc, char const *argv[]) {
  std::shared_ptr<Project> p = std::make_shared<Project>();
  std::shared_ptr<Employee> e = std::make_shared<Employee>();

  p->addEmployee(e);
  e->addProject(p);

  /* 
   * At the end none of project/employee gets destroyed 
   * because of circular dependency. Here We need to use weak pointer.
   */
  return 0;
}
