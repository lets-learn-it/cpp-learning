#include <iostream>
#include <memory>

class Project;

class Employee {
private:
  std::weak_ptr<Project> p;
public:
  Employee () {
    std::cout << "Creating Employee " << std::endl;
  }
  ~Employee () {
    std::cout << "Destroying Employee " << std::endl;
  }
  void addProject(std::weak_ptr<Project> pro) {
    this->p = pro;
  }
};

class Project {
private:
  std::weak_ptr<Employee> e;
public:
  Project () {
    std::cout << "Creating Project " << std::endl;
  }
  ~Project () {
    std::cout << "Destroying Project " << std::endl;
  }
  void addEmployee(std::weak_ptr<Employee> emp) {
    this->e = emp;
  }
};

int main(int argc, char const *argv[]) {
  std::shared_ptr<Project> p = std::make_shared<Project>();
  std::shared_ptr<Employee> e = std::make_shared<Employee>();

  p->addEmployee(e);
  e->addProject(p);

  /* 
   * Now both employee and project will get destroyed.
   * but both employee and project class should check if ptr is expired
   * using expired() method
   */
  return 0;
}
