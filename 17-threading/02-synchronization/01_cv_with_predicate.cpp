#include <iostream>
#include <thread>
#include <condition_variable>

using namespace std::literals;

std::mutex mt;
std::condition_variable cv;
int count = 0;

void inc(const char* name) {
  for (int i=0;i<20;i++) {
    {
      std::lock_guard<std::mutex> lg(mt);
      count++;
      std::cout << name << ": count = " << count << std::endl;
      if (count == 10) cv.notify_one();
    }
    std::this_thread::sleep_for(0.1s);
  }

}

void wake_me(const char* name) {
  std::cout << name << ": Waitning for count > 10" << std::endl;
  std::unique_lock<std::mutex> ul(mt);
  cv.wait(ul, []() {return count >= 10;});
  std::cout << name << ": count = " << count << std::endl;
  std::cout << name << ": I got lock, thr1 has to wait." << std::endl;
  std::this_thread::sleep_for(0.1s);
}

int main() {
  std::thread thr1(inc, "thr1"), thr2(wake_me, "thr2");

  thr1.join(); thr2.join();

  return 0;
}
