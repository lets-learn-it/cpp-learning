#include <iostream>
#include <thread>
#include <condition_variable>

using namespace std::literals;

std::mutex mt;
std::condition_variable cv;
int fctn = 1;

void fact(const char* name) {
  std::cout << name << ": Computing factorial" << std::endl;
  for (int i=1;i<5;i++) {
    std::this_thread::sleep_for(1s);
    fctn *= i;
  }
  cv.notify_one();
}

void get_fact(const char* name){
  std::unique_lock<std::mutex> guard(mt);
  std::cout << name << ": Waiting for condition" << std::endl;

  // when fact (thr1) sends notification, this thread should be waiting.
  // if notification is missed, then this thread will wait forever.
  cv.wait(guard);
  std::cout << name << ": fctn = " << fctn << std::endl;
}

int main() {
  std::thread thr1(fact, "thr1"), thr2(get_fact, "thr2");

  thr1.join(); thr2.join();

  return 0;
}

